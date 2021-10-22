/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *          File:  EpsStEstimn.c
 *        Config:  C:/_Synergy_Projects/New_Working/SF066A_EpsStEstimn_Impl/tools/Component.dpa
 *     SW-C Type:  EpsStEstimn
 *  Generated at:  Sat Apr 21 09:56:04 2018
 *
 *     Generator:  MICROSAR RTE Generator Version 4.13.0
 *                 RTE Core Version 1.13.0
 *       License:  Unlimited license CBD1400351 for Nxtr Automotive Corporation
 *
 *   Description:  C-Code implementation template for SW-C <EpsStEstimn>
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of version logging area >>                DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
* Copyright 2018 Nxtr 
* Nxtr Confidential
*
* Module File Name  : EpsStEstimn.c
* Module Description: Implements the SF066A FDD
* Project           : CBD 
* Author            : Shawn Penning
***********************************************************************************************************************
* Version Control:
* %version          : 2%
* %derived_by       : nz3541%
*----------------------------------------------------------------------------------------------------------------------
* Date      Rev      Author         Change Description                                                           SCR #
* -------   -------  --------  ---------------------------------------------------------------------------     ----------
* 04/12/18   1       ML        Initial implementation                                                          EA4#20381  
* 05/04/18   1       SPP       Fix code based on PSR - change coded by Akilan, baselined by SPP                EA4#23204  
**********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of version logging area >>                  DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *
 * AUTOSAR Modelling Object Descriptions
 *
 **********************************************************************************************************************
 *
 * Component Types:
 * ================
 * EpsStEstimn
 *   This component is used to estimate EPS system states from measurements of motor velocity, actual motor torque and handwheel torque.
 *
 *
 * Port Prototypes:
 * ================
 * HwTq
 *   Measured Handwheel Torque
 *
 * MotTqEstimd
 *   Motor Torque Estimated used to calculate State Estimator Input 1
 *
 * MotVelCrf
 *   Motor Velocity CRF used to calculate State Estimator Input 2
 *
 * PinionTqToRackFInstsRat
 *   Pinion Torque To Rack ForceInstantaneous Ratio used to calculate Rack Force Estimated
 *
 * RackFEstimd
 *   Rack Force Estimated is a function of Pinion Torque to Rack Force Instantaneous Ratio
 *
 * SysKineRat
 *   System Kinematic Ratio used to calculate State Estimator Input 2
 *
 * SysTqRat
 *   System Torque Ratio used to calculate State Estimator Input 1
 *
 * TorsBarStEstimd
 *   Output of Torsion Bar State Estimated
 *
 *
 * Runnable Entities:
 * ==================
 * EpsStEstimnInit1
 *   Initialization Runnable
 *
 * EpsStEstimnPer1
 *   Periodic Runnable at 0.002 sec
 *
 *
 * Per-Instance Memory:
 * ====================
 * StEstimrStPrev
 *   PIM used to store previous value of State Estimator State
 *
 *********************************************************************************************************************/

#include "Rte_EpsStEstimn.h" /* PRQA S 0857 */ /* MD_MSR_1.1_857 */


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of include and declaration area >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

#include "NxtrMath.h"
#include "ElecGlbPrm.h"

/******************************************** File Level Rule Deviations *********************************************/
/* MISRA-C:2004 Rule 16.10 [NXTRDEV 16.10.1]: There is no appropriate action to take on the return value for Rte_Read and Rte_Write */
/* MISRA-C:2004 Rule 19.1 [NXTRDEV 19.1.1]: AUTOSAR requires deviation from this rule for Memory Mapping include statements */

/********************************************* Embedded Local Constants **********************************************/ 
#define EPSST1ESTIMDMAX_HWRADPERSEC_F32         ( 1350.0F)
#define EPSST1ESTIMDMIN_HWRADPERSEC_F32         (-1350.0F)
#define EPSST3ESTIMDMAX_HWNWTMTRPERSEC_F32      ( 5000.0F)
#define EPSST3ESTIMDMIN_HWNWTMTRPERSEC_F32      (-5000.0F)
#define EPSST4ESTIMDMAX_HWNWTMTR_F32            ( 100.0F)
#define EPSST4ESTIMDMIN_HWNWTMTR_F32            (-100.0F)
#define EPSST5ESTIMDMAX_HWNWTMTR_F32            ( 300.0F)
#define EPSST5ESTIMDMIN_HWNWTMTR_F32            (-300.0F)
#define RACKFESTIMDMAX_RACKNWT_F32              ( 25000.0F)
#define RACKFESTIMDMIN_RACKNWT_F32              (-25000.0F)
#define SYSKINERATHILIM_MOTDEGPERHWDEG_F32      ( 50.0F)
#define SYSKINERATLOLIM_MOTDEGPERHWDEG_F32      ( 10.0F)


#define PrmEpsStEstimnMtrxA                         (*(const Ary2D_f32_5_5 *)Rte_Prm_EpsStEstimnMtrxA_Ary2D())
#define PrmEpsStEstimnMtrxB                         (*(const Ary2D_f32_5_3 *)Rte_Prm_EpsStEstimnMtrxB_Ary2D())
#define PrmEpsStEstimnMtrxC                         (*(const Ary2D_f32_5_5 *)Rte_Prm_EpsStEstimnMtrxC_Ary2D())
#define PrmEpsStEstimnMtrxD                         (*(const Ary2D_f32_5_3 *)Rte_Prm_EpsStEstimnMtrxD_Ary2D())

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
 * float32: Real in interval [-FLT_MAX...FLT_MAX] with single precision (standard type)
 *
 * Array Types:
 * ============
 * Ary1D_f32_3: Array with 3 element(s) of type float32
 * Ary1D_f32_5: Array with 5 element(s) of type float32
 * Ary2D_f32_5_3: Array with 5 element(s) of type Ary1D_f32_3
 * Ary2D_f32_5_5: Array with 5 element(s) of type Ary1D_f32_5
 *
 * Record Types:
 * =============
 * TorsBarStEstimdRec1: Record with elements
 *   MotVelEstimd of type float32
 *   TorsBarTqEstimd of type float32
 *   TorsBarRotatmEstimd of type float32
 *   DrvrTqEstimd of type float32
 *   RackTqEstimd of type float32
 *
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *
 * APIs which are accessible from all runnable entities of the SW-C
 *
 **********************************************************************************************************************
 * Per-Instance Memory:
 * ====================
 *   float32 *Rte_Pim_StEstimrStPrev(void)
 *     Returnvalue: float32* is of type Ary1D_f32_5
 *
 * Calibration Parameters:
 * =======================
 *   Calibration Component Calibration Parameters:
 *   ---------------------------------------------
 *   float32 *Rte_Prm_EpsStEstimnMtrxA_Ary2D(void)
 *     Returnvalue: float32* is of type Ary2D_f32_5_5
 *   float32 *Rte_Prm_EpsStEstimnMtrxB_Ary2D(void)
 *     Returnvalue: float32* is of type Ary2D_f32_5_3
 *   float32 *Rte_Prm_EpsStEstimnMtrxC_Ary2D(void)
 *     Returnvalue: float32* is of type Ary2D_f32_5_5
 *   float32 *Rte_Prm_EpsStEstimnMtrxD_Ary2D(void)
 *     Returnvalue: float32* is of type Ary2D_f32_5_3
 *
 *********************************************************************************************************************/


#define EpsStEstimn_START_SEC_CODE
#include "EpsStEstimn_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/**********************************************************************************************************************
 *
 * Runnable Entity Name: EpsStEstimnInit1
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed once after the RTE is started
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: EpsStEstimnInit1_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, EpsStEstimn_CODE) EpsStEstimnInit1(void) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: EpsStEstimnInit1
 *********************************************************************************************************************/

 /* Do Nothing */

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: EpsStEstimnPer1
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered on TimingEvent every 2ms
 *
 **********************************************************************************************************************
 *
 * Input Interfaces:
 * =================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Read_HwTq_Val(float32 *data)
 *   Std_ReturnType Rte_Read_MotTqEstimd_Val(float32 *data)
 *   Std_ReturnType Rte_Read_MotVelCrf_Val(float32 *data)
 *   Std_ReturnType Rte_Read_PinionTqToRackFInstsRat_Val(float32 *data)
 *   Std_ReturnType Rte_Read_SysKineRat_Val(float32 *data)
 *   Std_ReturnType Rte_Read_SysTqRat_Val(float32 *data)
 *
 * Output Interfaces:
 * ==================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Write_RackFEstimd_Val(float32 data)
 *   Std_ReturnType Rte_Write_TorsBarStEstimd_Rec(const TorsBarStEstimdRec1 *data)
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: EpsStEstimnPer1_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, EpsStEstimn_CODE) EpsStEstimnPer1(void) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: EpsStEstimnPer1
 *********************************************************************************************************************/

    VAR(float32, AUTOMATIC) HwTq_HwNwtMtr_T_f32;
    VAR(float32, AUTOMATIC) MotTqEstimd_MotNwtMtr_T_f32;
    VAR(float32, AUOTMATIC) MotVelCrf_MotRadPerSec_T_f32;
    VAR(float32, AUTOMATIC) PinionTqToRackFInstsRat_RackNwtPerHwNwtMtr_T_f32;
    VAR(float32, AUTOMATIC) SysKineRat_MotDegPerHwDeg_T_f32;
    VAR(float32, AUTOMATIC) SysTqRat_HwNwtMtrPerMotNwtMtr_T_f32;
    VAR(float32, AUTOMATIC) SysKineRatLimd_MotDegPerHwDeg_T_f32;
    
    VAR(float32, AUTOMATIC) RackFEstimd_RackNwt_T_f32;
    VAR(TorsBarStEstimdRec1, AUTOMATIC) TorsBarStEstimd_Uls_T_rec;
    /* Variable is listed as Uls because each array element has a different unit. */
    /*** [0] is HwNwtMtr 
         [1] is HwDeg
         [2] is HwNwtMtr ***/
    VAR(float32, AUTOMATIC) StEstimrInp_Uls_T_f32[3];
    VAR(uint8, AUTOMATIC)   RowIdx_Cnt_T_u08;
    VAR(uint8, AUTOMATIC)   ColIdx_Cnt_T_u08;
    VAR(float32, AUTOMATIC) StEstimrMtrxD_Uls_T_f32[5]={0.0F,0.0F,0.0F,0.0F,0.0F};
    VAR(float32, AUTOMATIC) StEstimrMtrxB_Uls_T_f32[5]={0.0F,0.0F,0.0F,0.0F,0.0F};
    VAR(float32, AUTOMATIC) StEstimrMtrxA_Uls_T_f32[5]={0.0F,0.0F,0.0F,0.0F,0.0F};
    VAR(float32, AUTOMATIC) StEstimrMtrxAB_Uls_T_f32[5]={0.0F,0.0F,0.0F,0.0F,0.0F};
    VAR(float32, AUTOMATIC) StEstimrMtrxABC_Uls_T_f32[5]={0.0F,0.0F,0.0F,0.0F,0.0F};
    VAR(float32, AUTOMATIC) StEstimrMtrxABCD_Uls_T_f32[5]={0.0F,0.0F,0.0F,0.0F,0.0F};
    
    (void)Rte_Read_HwTq_Val(&HwTq_HwNwtMtr_T_f32);
    (void)Rte_Read_MotTqEstimd_Val(&MotTqEstimd_MotNwtMtr_T_f32);
    (void)Rte_Read_MotVelCrf_Val(&MotVelCrf_MotRadPerSec_T_f32);
    (void)Rte_Read_PinionTqToRackFInstsRat_Val(&PinionTqToRackFInstsRat_RackNwtPerHwNwtMtr_T_f32);
    (void)Rte_Read_SysKineRat_Val(&SysKineRat_MotDegPerHwDeg_T_f32);
    (void)Rte_Read_SysTqRat_Val(&SysTqRat_HwNwtMtrPerMotNwtMtr_T_f32);
	
	SysKineRatLimd_MotDegPerHwDeg_T_f32 = Lim_f32(SysKineRat_MotDegPerHwDeg_T_f32,SYSKINERATLOLIM_MOTDEGPERHWDEG_F32, SYSKINERATHILIM_MOTDEGPERHWDEG_F32);
 
    /*** InpProcessing ***/
    StEstimrInp_Uls_T_f32[0] = MotTqEstimd_MotNwtMtr_T_f32 * SysTqRat_HwNwtMtrPerMotNwtMtr_T_f32;
    StEstimrInp_Uls_T_f32[1] = (MotVelCrf_MotRadPerSec_T_f32 / SysKineRatLimd_MotDegPerHwDeg_T_f32);
    StEstimrInp_Uls_T_f32[2] = HwTq_HwNwtMtr_T_f32;
    
    /*** StEstimn ***/
    for(RowIdx_Cnt_T_u08 = 0U; RowIdx_Cnt_T_u08 < TblSize_m(PrmEpsStEstimnMtrxB); RowIdx_Cnt_T_u08++)
    {
        for(ColIdx_Cnt_T_u08 = 0U; ColIdx_Cnt_T_u08 < TblSize_m(PrmEpsStEstimnMtrxB[0]); ColIdx_Cnt_T_u08++)
        {
            StEstimrMtrxB_Uls_T_f32[RowIdx_Cnt_T_u08] += (PrmEpsStEstimnMtrxB[RowIdx_Cnt_T_u08][ColIdx_Cnt_T_u08]) * 
                                                          StEstimrInp_Uls_T_f32[ColIdx_Cnt_T_u08];
        }
    }
    
    for(RowIdx_Cnt_T_u08 = 0U; RowIdx_Cnt_T_u08 < TblSize_m(PrmEpsStEstimnMtrxA); RowIdx_Cnt_T_u08++)
    {
        for(ColIdx_Cnt_T_u08 = 0U; ColIdx_Cnt_T_u08 < TblSize_m(PrmEpsStEstimnMtrxA[0]); ColIdx_Cnt_T_u08++)
        {
            StEstimrMtrxA_Uls_T_f32[RowIdx_Cnt_T_u08] += (PrmEpsStEstimnMtrxA[RowIdx_Cnt_T_u08][ColIdx_Cnt_T_u08]) *
                                                          Rte_Pim_StEstimrStPrev()[ColIdx_Cnt_T_u08];
        }
    }
    
    for(RowIdx_Cnt_T_u08 = 0U; RowIdx_Cnt_T_u08 < 5U; RowIdx_Cnt_T_u08++)
    {
        StEstimrMtrxAB_Uls_T_f32[RowIdx_Cnt_T_u08] = StEstimrMtrxA_Uls_T_f32[RowIdx_Cnt_T_u08] + StEstimrMtrxB_Uls_T_f32[RowIdx_Cnt_T_u08];
        Rte_Pim_StEstimrStPrev()[RowIdx_Cnt_T_u08] = StEstimrMtrxAB_Uls_T_f32[RowIdx_Cnt_T_u08];
    }
    
    for(RowIdx_Cnt_T_u08 = 0U; RowIdx_Cnt_T_u08 < TblSize_m(PrmEpsStEstimnMtrxC); RowIdx_Cnt_T_u08++)
    {
        for(ColIdx_Cnt_T_u08 = 0U; ColIdx_Cnt_T_u08 < TblSize_m(PrmEpsStEstimnMtrxC[0]); ColIdx_Cnt_T_u08++)
        {
            StEstimrMtrxABC_Uls_T_f32[RowIdx_Cnt_T_u08] += ((PrmEpsStEstimnMtrxC[RowIdx_Cnt_T_u08][ColIdx_Cnt_T_u08]) * 
                                                           StEstimrMtrxAB_Uls_T_f32[ColIdx_Cnt_T_u08]);
        }
    }
    
    for(RowIdx_Cnt_T_u08 = 0U; RowIdx_Cnt_T_u08 < TblSize_m(PrmEpsStEstimnMtrxD); RowIdx_Cnt_T_u08++)
    {
        for(ColIdx_Cnt_T_u08 = 0U; ColIdx_Cnt_T_u08 < TblSize_m(PrmEpsStEstimnMtrxD[0]); ColIdx_Cnt_T_u08++)
        {
            StEstimrMtrxD_Uls_T_f32[RowIdx_Cnt_T_u08] += ((PrmEpsStEstimnMtrxD[RowIdx_Cnt_T_u08][ColIdx_Cnt_T_u08]) *
                                                         StEstimrInp_Uls_T_f32[ColIdx_Cnt_T_u08]);
        }
    }
    
    for(RowIdx_Cnt_T_u08 = 0U; RowIdx_Cnt_T_u08 < 5U; RowIdx_Cnt_T_u08++)
    {
        StEstimrMtrxABCD_Uls_T_f32[RowIdx_Cnt_T_u08] = StEstimrMtrxABC_Uls_T_f32[RowIdx_Cnt_T_u08] + StEstimrMtrxD_Uls_T_f32[RowIdx_Cnt_T_u08];
    }
    
    /*** OutpProcessing ***/
    TorsBarStEstimd_Uls_T_rec.MotVelEstimd = Lim_f32(StEstimrMtrxABCD_Uls_T_f32[0], EPSST1ESTIMDMIN_HWRADPERSEC_F32, EPSST1ESTIMDMAX_HWRADPERSEC_F32);
    TorsBarStEstimd_Uls_T_rec.TorsBarTqEstimd = Lim_f32(StEstimrMtrxABCD_Uls_T_f32[1], ELECGLBPRM_HWTQMINLIM_HWNWTMTR_F32, ELECGLBPRM_HWTQMAXLIM_HWNWTMTR_F32);
    TorsBarStEstimd_Uls_T_rec.TorsBarRotatmEstimd = Lim_f32(StEstimrMtrxABCD_Uls_T_f32[2], EPSST3ESTIMDMIN_HWNWTMTRPERSEC_F32, EPSST3ESTIMDMAX_HWNWTMTRPERSEC_F32);
    TorsBarStEstimd_Uls_T_rec.DrvrTqEstimd = Lim_f32(StEstimrMtrxABCD_Uls_T_f32[3], EPSST4ESTIMDMIN_HWNWTMTR_F32, EPSST4ESTIMDMAX_HWNWTMTR_F32);
    TorsBarStEstimd_Uls_T_rec.RackTqEstimd = Lim_f32(StEstimrMtrxABCD_Uls_T_f32[4], EPSST5ESTIMDMIN_HWNWTMTR_F32, EPSST5ESTIMDMAX_HWNWTMTR_F32);
    
    RackFEstimd_RackNwt_T_f32 = Lim_f32(TorsBarStEstimd_Uls_T_rec.RackTqEstimd * PinionTqToRackFInstsRat_RackNwtPerHwNwtMtr_T_f32,
                                        RACKFESTIMDMIN_RACKNWT_F32, 
                                        RACKFESTIMDMAX_RACKNWT_F32);
                                        
    (void)Rte_Write_RackFEstimd_Val(RackFEstimd_RackNwt_T_f32);
    (void)Rte_Write_TorsBarStEstimd_Rec(&TorsBarStEstimd_Uls_T_rec);
    
 
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}


#define EpsStEstimn_STOP_SEC_CODE
#include "EpsStEstimn_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


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
