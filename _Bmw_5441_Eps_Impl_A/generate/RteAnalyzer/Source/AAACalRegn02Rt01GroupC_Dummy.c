/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *          File:  AAACalRegn02Rt01GroupC_Dummy.c
 *        Config:  EPS.dpa
 *     SW-C Type:  AAACalRegn02Rt01GroupC_Dummy
 *
 *     Generator:  MICROSAR RTE Generator Version 4.16.0
 *                 RTE Core Version 1.16.0
 *       License:  Unlimited license CBD1700369 for Nxtr Automotive Corporation
 *
 *   Description:  C-Code implementation template for SW-C <AAACalRegn02Rt01GroupC_Dummy>
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of version logging area >>                DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

/* PRQA S 0777, 0779 EOF */ /* MD_MSR_5.1_777, MD_MSR_5.1_779 */
/* PRQA S 0857 EOF */ /* MD_MSR_1.1_857 */
/* PRQA S 0614 EOF */ /* MD_Rte_TestCode */

/* PRQA S 3109 EOF */ /* MD_Rte_TestCode */
/* PRQA S 3112 EOF */ /* MD_Rte_TestCode */
/* PRQA S 3197 EOF */ /* MD_Rte_TestCode */
/* PRQA S 3198 EOF */ /* MD_Rte_TestCode */
/* PRQA S 3199 EOF */ /* MD_Rte_TestCode */
/* PRQA S 3201 EOF */ /* MD_Rte_TestCode */
/* PRQA S 3203 EOF */ /* MD_Rte_TestCode */
/* PRQA S 3205 EOF */ /* MD_Rte_TestCode */
/* PRQA S 3206 EOF */ /* MD_Rte_TestCode */
/* PRQA S 3218 EOF */ /* MD_Rte_TestCode */
/* PRQA S 3229 EOF */ /* MD_Rte_TestCode */
/* PRQA S 2002 EOF */ /* MD_Rte_TestCode */
/* PRQA S 3334 EOF */ /* MD_Rte_TestCode */
/* PRQA S 3417 EOF */ /* MD_Rte_TestCode */
/* PRQA S 3426 EOF */ /* MD_Rte_TestCode */
/* PRQA S 3453 EOF */ /* MD_Rte_TestCode */

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
 * s10p5
 *   
 *
 * u10p6
 *   
 *
 * u12p4
 *   
 *
 * u2p14
 *   
 *
 * u4p12
 *   
 *
 * u6p10
 *   
 *
 * u8p8
 *   
 *
 * u9p7
 *   
 *
 *********************************************************************************************************************/

#include "Rte_AAACalRegn02Rt01GroupC_Dummy.h" /* PRQA S 0857 */ /* MD_MSR_1.1_857 */
#include "TSC_AAACalRegn02Rt01GroupC_Dummy.h"


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of include and declaration area >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

#include "string.h"


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
 * s10p5: Integer in interval [-32768...32767]
 * sint16: Integer in interval [-32768...32767] (standard type)
 * u10p6: Integer in interval [0...65535]
 * u12p4: Integer in interval [0...65535]
 * u2p14: Integer in interval [0...65535]
 * u4p12: Integer in interval [0...65535]
 * u6p10: Integer in interval [0...65535]
 * u8p8: Integer in interval [0...65535]
 * u9p7: Integer in interval [0...65535]
 * uint16: Integer in interval [0...65535] (standard type)
 *
 * Array Types:
 * ============
 * Ary1D_s10p5_8: Array with 8 element(s) of type s10p5
 * Ary1D_u10p6_12: Array with 12 element(s) of type u10p6
 * Ary1D_u10p6_9: Array with 9 element(s) of type u10p6
 * Ary1D_u12p4_12: Array with 12 element(s) of type u12p4
 * Ary1D_u12p4_7: Array with 7 element(s) of type u12p4
 * Ary1D_u12p4_9: Array with 9 element(s) of type u12p4
 * Ary1D_u2p14_10: Array with 10 element(s) of type u2p14
 * Ary1D_u2p14_5: Array with 5 element(s) of type u2p14
 * Ary1D_u2p14_8: Array with 8 element(s) of type u2p14
 * Ary1D_u2p14_9: Array with 9 element(s) of type u2p14
 * Ary1D_u4p12_8: Array with 8 element(s) of type u4p12
 * Ary1D_u6p10_9: Array with 9 element(s) of type u6p10
 * Ary1D_u8p8_10: Array with 10 element(s) of type u8p8
 * Ary1D_u8p8_8: Array with 8 element(s) of type u8p8
 * Ary1D_u9p7_5: Array with 5 element(s) of type u9p7
 * Ary1D_u9p7_8: Array with 8 element(s) of type u9p7
 * Ary2D_u10p6_8_12: Array with 8 element(s) of type Ary1D_u10p6_12
 * Ary2D_u10p6_8_9: Array with 8 element(s) of type Ary1D_u10p6_9
 * Ary2D_u12p4_8_12: Array with 8 element(s) of type Ary1D_u12p4_12
 * Ary2D_u2p14_5_10: Array with 5 element(s) of type Ary1D_u2p14_10
 * Ary2D_u2p14_5_8: Array with 5 element(s) of type Ary1D_u2p14_8
 * Ary2D_u2p14_7_8: Array with 7 element(s) of type Ary1D_u2p14_8
 * Ary2D_u6p10_8_9: Array with 8 element(s) of type Ary1D_u6p10_9
 * Ary2D_u8p8_5_10: Array with 5 element(s) of type Ary1D_u8p8_10
 * Ary2D_u8p8_5_8: Array with 5 element(s) of type Ary1D_u8p8_8
 *
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *
 * APIs which are accessible from all runnable entities of the SW-C
 *
 **********************************************************************************************************************
 * Calibration Parameters:
 * =======================
 *   Calibration Component Calibration Parameters:
 *   ---------------------------------------------
 *   boolean Rte_Prm_CtrldVelRtnVelErrScaEna_Logl(Rte_Instance self)
 *   u10p6 *Rte_Prm_CtrldVelRtnDampgX_Ary2D(Rte_Instance self)
 *     Returnvalue: u10p6* is of type Ary2D_u10p6_8_9
 *   u6p10 *Rte_Prm_CtrldVelRtnDampgY_Ary2D(Rte_Instance self)
 *     Returnvalue: u6p10* is of type Ary2D_u6p10_8_9
 *   u8p8 *Rte_Prm_CtrldVelRtnDesVelScaX_Ary2D(Rte_Instance self)
 *     Returnvalue: u8p8* is of type Ary2D_u8p8_5_8
 *   u2p14 *Rte_Prm_CtrldVelRtnDesVelScaY_Ary2D(Rte_Instance self)
 *     Returnvalue: u2p14* is of type Ary2D_u2p14_5_8
 *   u12p4 *Rte_Prm_CtrldVelRtnDesVelX_Ary2D(Rte_Instance self)
 *     Returnvalue: u12p4* is of type Ary2D_u12p4_8_12
 *   u10p6 *Rte_Prm_CtrldVelRtnDesVelY_Ary2D(Rte_Instance self)
 *     Returnvalue: u10p6* is of type Ary2D_u10p6_8_12
 *   u12p4 *Rte_Prm_CtrldVelRtnHwPosnScaX_Ary1D(Rte_Instance self)
 *     Returnvalue: u12p4* is of type Ary1D_u12p4_9
 *   u2p14 *Rte_Prm_CtrldVelRtnHwPosnScaY_Ary1D(Rte_Instance self)
 *     Returnvalue: u2p14* is of type Ary1D_u2p14_9
 *   u8p8 *Rte_Prm_CtrldVelRtnHwTqSca1X_Ary2D(Rte_Instance self)
 *     Returnvalue: u8p8* is of type Ary2D_u8p8_5_10
 *   u2p14 *Rte_Prm_CtrldVelRtnHwTqSca1Y_Ary2D(Rte_Instance self)
 *     Returnvalue: u2p14* is of type Ary2D_u2p14_5_10
 *   u8p8 *Rte_Prm_CtrldVelRtnHwTqSca2X_Ary2D(Rte_Instance self)
 *     Returnvalue: u8p8* is of type Ary2D_u8p8_5_10
 *   u2p14 *Rte_Prm_CtrldVelRtnHwTqSca2Y_Ary2D(Rte_Instance self)
 *     Returnvalue: u2p14* is of type Ary2D_u2p14_5_10
 *   u8p8 *Rte_Prm_CtrldVelRtnIntglGain_Ary1D(Rte_Instance self)
 *     Returnvalue: u8p8* is of type Ary1D_u8p8_8
 *   u8p8 *Rte_Prm_CtrldVelRtnPinionTqScaX_Ary2D(Rte_Instance self)
 *     Returnvalue: u8p8* is of type Ary2D_u8p8_5_8
 *   u2p14 *Rte_Prm_CtrldVelRtnPinionTqScaY_Ary2D(Rte_Instance self)
 *     Returnvalue: u2p14* is of type Ary2D_u2p14_5_8
 *   u4p12 *Rte_Prm_CtrldVelRtnPropGain_Ary1D(Rte_Instance self)
 *     Returnvalue: u4p12* is of type Ary1D_u4p12_8
 *   u8p8 *Rte_Prm_CtrldVelRtnTqGrdtScaX_Ary2D(Rte_Instance self)
 *     Returnvalue: u8p8* is of type Ary2D_u8p8_5_8
 *   u2p14 *Rte_Prm_CtrldVelRtnTqGrdtScaY_Ary2D(Rte_Instance self)
 *     Returnvalue: u2p14* is of type Ary2D_u2p14_5_8
 *   u9p7 *Rte_Prm_CtrldVelRtnVehSpdScaBilnrSeln_Ary1D(Rte_Instance self)
 *     Returnvalue: u9p7* is of type Ary1D_u9p7_5
 *   u12p4 *Rte_Prm_CtrldVelRtnVelErrScaBilnrSeln_Ary1D(Rte_Instance self)
 *     Returnvalue: u12p4* is of type Ary1D_u12p4_7
 *   s10p5 *Rte_Prm_CtrldVelRtnVelErrScaX_Ary1D(Rte_Instance self)
 *     Returnvalue: s10p5* is of type Ary1D_s10p5_8
 *   u2p14 *Rte_Prm_CtrldVelRtnVelErrScaY_Ary2D(Rte_Instance self)
 *     Returnvalue: u2p14* is of type Ary2D_u2p14_7_8
 *   u2p14 *Rte_Prm_CtrldVelRtnVelErrVehSpdScaY_Ary1D(Rte_Instance self)
 *     Returnvalue: u2p14* is of type Ary1D_u2p14_5
 *   u9p7 *Rte_Prm_CtrldVelRtnVelSpdTbl_Ary1D(Rte_Instance self)
 *     Returnvalue: u9p7* is of type Ary1D_u9p7_8
 *
 *********************************************************************************************************************/


#define AAACalRegn02Rt01GroupC_Dummy_START_SEC_CODE
#include "AAACalRegn02Rt01GroupC_Dummy_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/**********************************************************************************************************************
 *
 * Runnable Entity Name: CalRegn02Rt01GroupCDummyInit1
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed once after the RTE is started
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: CalRegn02Rt01GroupCDummyInit1_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, AAACalRegn02Rt01GroupC_Dummy_CODE) CalRegn02Rt01GroupCDummyInit1(Rte_Instance self) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: CalRegn02Rt01GroupCDummyInit1
 *********************************************************************************************************************/

  boolean CtrldVelRtnVelErrScaEna_Logl_data;
  Ary2D_u10p6_8_9 CtrldVelRtnDampgX_Ary2D_data;
  Ary2D_u6p10_8_9 CtrldVelRtnDampgY_Ary2D_data;
  Ary2D_u8p8_5_8 CtrldVelRtnDesVelScaX_Ary2D_data;
  Ary2D_u2p14_5_8 CtrldVelRtnDesVelScaY_Ary2D_data;
  Ary2D_u12p4_8_12 CtrldVelRtnDesVelX_Ary2D_data;
  Ary2D_u10p6_8_12 CtrldVelRtnDesVelY_Ary2D_data;
  Ary1D_u12p4_9 CtrldVelRtnHwPosnScaX_Ary1D_data;
  Ary1D_u2p14_9 CtrldVelRtnHwPosnScaY_Ary1D_data;
  Ary2D_u8p8_5_10 CtrldVelRtnHwTqSca1X_Ary2D_data;
  Ary2D_u2p14_5_10 CtrldVelRtnHwTqSca1Y_Ary2D_data;
  Ary2D_u8p8_5_10 CtrldVelRtnHwTqSca2X_Ary2D_data;
  Ary2D_u2p14_5_10 CtrldVelRtnHwTqSca2Y_Ary2D_data;
  Ary1D_u8p8_8 CtrldVelRtnIntglGain_Ary1D_data;
  Ary2D_u8p8_5_8 CtrldVelRtnPinionTqScaX_Ary2D_data;
  Ary2D_u2p14_5_8 CtrldVelRtnPinionTqScaY_Ary2D_data;
  Ary1D_u4p12_8 CtrldVelRtnPropGain_Ary1D_data;
  Ary2D_u8p8_5_8 CtrldVelRtnTqGrdtScaX_Ary2D_data;
  Ary2D_u2p14_5_8 CtrldVelRtnTqGrdtScaY_Ary2D_data;
  Ary1D_u9p7_5 CtrldVelRtnVehSpdScaBilnrSeln_Ary1D_data;
  Ary1D_u12p4_7 CtrldVelRtnVelErrScaBilnrSeln_Ary1D_data;
  Ary1D_s10p5_8 CtrldVelRtnVelErrScaX_Ary1D_data;
  Ary2D_u2p14_7_8 CtrldVelRtnVelErrScaY_Ary2D_data;
  Ary1D_u2p14_5 CtrldVelRtnVelErrVehSpdScaY_Ary1D_data;
  Ary1D_u9p7_8 CtrldVelRtnVelSpdTbl_Ary1D_data;

  /*************************************************
  * Direct Function Accesses
  *************************************************/

  CtrldVelRtnVelErrScaEna_Logl_data = TSC_AAACalRegn02Rt01GroupC_Dummy_Rte_Prm_CtrldVelRtnVelErrScaEna_Logl(self);
  (void)memcpy(CtrldVelRtnDampgX_Ary2D_data, TSC_AAACalRegn02Rt01GroupC_Dummy_Rte_Prm_CtrldVelRtnDampgX_Ary2D(self), sizeof(Ary2D_u10p6_8_9));
  (void)memcpy(CtrldVelRtnDampgY_Ary2D_data, TSC_AAACalRegn02Rt01GroupC_Dummy_Rte_Prm_CtrldVelRtnDampgY_Ary2D(self), sizeof(Ary2D_u6p10_8_9));
  (void)memcpy(CtrldVelRtnDesVelScaX_Ary2D_data, TSC_AAACalRegn02Rt01GroupC_Dummy_Rte_Prm_CtrldVelRtnDesVelScaX_Ary2D(self), sizeof(Ary2D_u8p8_5_8));
  (void)memcpy(CtrldVelRtnDesVelScaY_Ary2D_data, TSC_AAACalRegn02Rt01GroupC_Dummy_Rte_Prm_CtrldVelRtnDesVelScaY_Ary2D(self), sizeof(Ary2D_u2p14_5_8));
  (void)memcpy(CtrldVelRtnDesVelX_Ary2D_data, TSC_AAACalRegn02Rt01GroupC_Dummy_Rte_Prm_CtrldVelRtnDesVelX_Ary2D(self), sizeof(Ary2D_u12p4_8_12));
  (void)memcpy(CtrldVelRtnDesVelY_Ary2D_data, TSC_AAACalRegn02Rt01GroupC_Dummy_Rte_Prm_CtrldVelRtnDesVelY_Ary2D(self), sizeof(Ary2D_u10p6_8_12));
  (void)memcpy(CtrldVelRtnHwPosnScaX_Ary1D_data, TSC_AAACalRegn02Rt01GroupC_Dummy_Rte_Prm_CtrldVelRtnHwPosnScaX_Ary1D(self), sizeof(Ary1D_u12p4_9));
  (void)memcpy(CtrldVelRtnHwPosnScaY_Ary1D_data, TSC_AAACalRegn02Rt01GroupC_Dummy_Rte_Prm_CtrldVelRtnHwPosnScaY_Ary1D(self), sizeof(Ary1D_u2p14_9));
  (void)memcpy(CtrldVelRtnHwTqSca1X_Ary2D_data, TSC_AAACalRegn02Rt01GroupC_Dummy_Rte_Prm_CtrldVelRtnHwTqSca1X_Ary2D(self), sizeof(Ary2D_u8p8_5_10));
  (void)memcpy(CtrldVelRtnHwTqSca1Y_Ary2D_data, TSC_AAACalRegn02Rt01GroupC_Dummy_Rte_Prm_CtrldVelRtnHwTqSca1Y_Ary2D(self), sizeof(Ary2D_u2p14_5_10));
  (void)memcpy(CtrldVelRtnHwTqSca2X_Ary2D_data, TSC_AAACalRegn02Rt01GroupC_Dummy_Rte_Prm_CtrldVelRtnHwTqSca2X_Ary2D(self), sizeof(Ary2D_u8p8_5_10));
  (void)memcpy(CtrldVelRtnHwTqSca2Y_Ary2D_data, TSC_AAACalRegn02Rt01GroupC_Dummy_Rte_Prm_CtrldVelRtnHwTqSca2Y_Ary2D(self), sizeof(Ary2D_u2p14_5_10));
  (void)memcpy(CtrldVelRtnIntglGain_Ary1D_data, TSC_AAACalRegn02Rt01GroupC_Dummy_Rte_Prm_CtrldVelRtnIntglGain_Ary1D(self), sizeof(Ary1D_u8p8_8));
  (void)memcpy(CtrldVelRtnPinionTqScaX_Ary2D_data, TSC_AAACalRegn02Rt01GroupC_Dummy_Rte_Prm_CtrldVelRtnPinionTqScaX_Ary2D(self), sizeof(Ary2D_u8p8_5_8));
  (void)memcpy(CtrldVelRtnPinionTqScaY_Ary2D_data, TSC_AAACalRegn02Rt01GroupC_Dummy_Rte_Prm_CtrldVelRtnPinionTqScaY_Ary2D(self), sizeof(Ary2D_u2p14_5_8));
  (void)memcpy(CtrldVelRtnPropGain_Ary1D_data, TSC_AAACalRegn02Rt01GroupC_Dummy_Rte_Prm_CtrldVelRtnPropGain_Ary1D(self), sizeof(Ary1D_u4p12_8));
  (void)memcpy(CtrldVelRtnTqGrdtScaX_Ary2D_data, TSC_AAACalRegn02Rt01GroupC_Dummy_Rte_Prm_CtrldVelRtnTqGrdtScaX_Ary2D(self), sizeof(Ary2D_u8p8_5_8));
  (void)memcpy(CtrldVelRtnTqGrdtScaY_Ary2D_data, TSC_AAACalRegn02Rt01GroupC_Dummy_Rte_Prm_CtrldVelRtnTqGrdtScaY_Ary2D(self), sizeof(Ary2D_u2p14_5_8));
  (void)memcpy(CtrldVelRtnVehSpdScaBilnrSeln_Ary1D_data, TSC_AAACalRegn02Rt01GroupC_Dummy_Rte_Prm_CtrldVelRtnVehSpdScaBilnrSeln_Ary1D(self), sizeof(Ary1D_u9p7_5));
  (void)memcpy(CtrldVelRtnVelErrScaBilnrSeln_Ary1D_data, TSC_AAACalRegn02Rt01GroupC_Dummy_Rte_Prm_CtrldVelRtnVelErrScaBilnrSeln_Ary1D(self), sizeof(Ary1D_u12p4_7));
  (void)memcpy(CtrldVelRtnVelErrScaX_Ary1D_data, TSC_AAACalRegn02Rt01GroupC_Dummy_Rte_Prm_CtrldVelRtnVelErrScaX_Ary1D(self), sizeof(Ary1D_s10p5_8));
  (void)memcpy(CtrldVelRtnVelErrScaY_Ary2D_data, TSC_AAACalRegn02Rt01GroupC_Dummy_Rte_Prm_CtrldVelRtnVelErrScaY_Ary2D(self), sizeof(Ary2D_u2p14_7_8));
  (void)memcpy(CtrldVelRtnVelErrVehSpdScaY_Ary1D_data, TSC_AAACalRegn02Rt01GroupC_Dummy_Rte_Prm_CtrldVelRtnVelErrVehSpdScaY_Ary1D(self), sizeof(Ary1D_u2p14_5));
  (void)memcpy(CtrldVelRtnVelSpdTbl_Ary1D_data, TSC_AAACalRegn02Rt01GroupC_Dummy_Rte_Prm_CtrldVelRtnVelSpdTbl_Ary1D(self), sizeof(Ary1D_u9p7_8));


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}


#define AAACalRegn02Rt01GroupC_Dummy_STOP_SEC_CODE
#include "AAACalRegn02Rt01GroupC_Dummy_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of function definition area >>            DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of function definition area >>              DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of removed code area >>                   DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of removed code area >>                     DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

/**********************************************************************************************************************
 MISRA 2004 violations and justifications
 *********************************************************************************************************************/

/* module specific MISRA deviations:
   MD_Rte_TestCode:
     Reason:     This justification is used within the generated test code by the Rte Analyzer.
     Risk:       No functional risk.
     Prevention: Not required.

*/
