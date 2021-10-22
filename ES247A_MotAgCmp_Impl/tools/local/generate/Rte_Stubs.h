/******************************************************************************************************************
* Copyright 2016 Nxtr
* Nxtr Confidential
*
* Module File Name:   Rte_Stubs.h
* Module Description: Stubs header for Polyspace analysis.  Generated from TL109A_SwcSuprt.
* Project:            CBD
* Author:             Owen Tosh
******************************************************************************************************************/


#ifndef RTE_STUBS_H
#define RTE_STUBS_H


/*** Extern Statements ***/

/* Inputs */
extern VAR(sint8, AUTOMATIC) MotAgCmp_Ip_AssiMechPolarity;
extern VAR(s15p16, AUTOMATIC) MotAgCmp_Ip_MotAgCumvAlgndMrfRev;
extern VAR(boolean, AUTOMATIC) MotAgCmp_Ip_MotAgCumvInid;

/* Outputs */
extern VAR(s18p13, AUTOMATIC) MotAgCmp_Op_MotAgCumvAlgndCrf;
extern VAR(s18p13, AUTOMATIC) MotAgCmp_Op_MotAgCumvAlgndMrf;
extern VAR(boolean, AUTOMATIC) MotAgCmp_Op_MotAgCumvAlgndVld;

/* Calibrations */
extern CONST(uint8, AUTOMATIC) MotAgCmp_Cal_SysGlbPrmMotPoleCnt;
extern CONST(float32, AUTOMATIC) MotAgCmp_Cal_SysGlbPrmSysKineRat;

/* PIMs */
extern VAR(u0p16, AUTOMATIC) MotAgCmp_Pim_MotAgCmpMotAgBackEmf;
extern VAR(uint8, AUTOMATIC) MotAgCmp_Pim_CmpEnaCntr;
extern VAR(float32, AUTOMATIC) MotAgCmp_Pim_DigMotHwPosn;
extern VAR(s15p16, AUTOMATIC) MotAgCmp_Pim_MotAgCmpMotCtrlMotAgCumvAlgndMrfRevPrev;
extern VAR(s15p16, AUTOMATIC) MotAgCmp_Pim_MotAgCmpMotCtrlMotAgMeclPrev;

/* Arguments and Returns */
extern VAR(boolean, AUTOMATIC) MotAgCmp_Srv_MotAgCmpMotAgBackEmf_SetRamBlockStatus_BlockChanged;
extern VAR(Std_ReturnType, AUTOMATIC) MotAgCmp_Srv_MotAgCmpMotAgBackEmf_SetRamBlockStatus_Return;
extern VAR(u0p16, AUTOMATIC) MotAgCmp_Cli_MotAgCmpBackEmfRead_MotAgBackEmfRead;
extern VAR(u0p16, AUTOMATIC) MotAgCmp_Cli_MotAgCmpBackEmfWr_MotAgCmpBackEmfWrData;


/*** Input Stubs ***/

#ifdef Rte_Read_AssiMechPolarity_Val
# undef Rte_Read_AssiMechPolarity_Val
#endif
#define Rte_Read_AssiMechPolarity_Val(data) (*(data) = MotAgCmp_Ip_AssiMechPolarity)

#ifdef Rte_Read_MotAgCumvAlgndMrfRev_Val
# undef Rte_Read_MotAgCumvAlgndMrfRev_Val
#endif
#define Rte_Read_MotAgCumvAlgndMrfRev_Val(data) (*(data) = MotAgCmp_Ip_MotAgCumvAlgndMrfRev)

#ifdef Rte_Read_MotAgCumvInid_Logl
# undef Rte_Read_MotAgCumvInid_Logl
#endif
#define Rte_Read_MotAgCumvInid_Logl(data) (*(data) = MotAgCmp_Ip_MotAgCumvInid)


/*** Output Stubs ***/

#ifdef Rte_Write_MotAgCumvAlgndCrf_Val
# undef Rte_Write_MotAgCumvAlgndCrf_Val
#endif
#define Rte_Write_MotAgCumvAlgndCrf_Val(data) (MotAgCmp_Op_MotAgCumvAlgndCrf = (data))

#ifdef Rte_Write_MotAgCumvAlgndMrf_Val
# undef Rte_Write_MotAgCumvAlgndMrf_Val
#endif
#define Rte_Write_MotAgCumvAlgndMrf_Val(data) (MotAgCmp_Op_MotAgCumvAlgndMrf = (data))

#ifdef Rte_Write_MotAgCumvAlgndVld_Logl
# undef Rte_Write_MotAgCumvAlgndVld_Logl
#endif
#define Rte_Write_MotAgCumvAlgndVld_Logl(data) (MotAgCmp_Op_MotAgCumvAlgndVld = (data))


/*** Calibration Stubs ***/

#ifdef Rte_Prm_SysGlbPrmMotPoleCnt_Val
# undef Rte_Prm_SysGlbPrmMotPoleCnt_Val
#endif
#define Rte_Prm_SysGlbPrmMotPoleCnt_Val() (MotAgCmp_Cal_SysGlbPrmMotPoleCnt)

#ifdef Rte_Prm_SysGlbPrmSysKineRat_Val
# undef Rte_Prm_SysGlbPrmSysKineRat_Val
#endif
#define Rte_Prm_SysGlbPrmSysKineRat_Val() (MotAgCmp_Cal_SysGlbPrmSysKineRat)


/*** PIM Stubs ***/

#ifdef Rte_Pim_MotAgCmpMotAgBackEmf
# undef Rte_Pim_MotAgCmpMotAgBackEmf
#endif
#define Rte_Pim_MotAgCmpMotAgBackEmf() (&MotAgCmp_Pim_MotAgCmpMotAgBackEmf)

#ifdef Rte_Pim_CmpEnaCntr
# undef Rte_Pim_CmpEnaCntr
#endif
#define Rte_Pim_CmpEnaCntr() (&MotAgCmp_Pim_CmpEnaCntr)

#ifdef Rte_Pim_DigMotHwPosn
# undef Rte_Pim_DigMotHwPosn
#endif
#define Rte_Pim_DigMotHwPosn() (&MotAgCmp_Pim_DigMotHwPosn)

#ifdef Rte_Pim_MotAgCmpMotCtrlMotAgCumvAlgndMrfRevPrev
# undef Rte_Pim_MotAgCmpMotCtrlMotAgCumvAlgndMrfRevPrev
#endif
#define Rte_Pim_MotAgCmpMotCtrlMotAgCumvAlgndMrfRevPrev() (&MotAgCmp_Pim_MotAgCmpMotCtrlMotAgCumvAlgndMrfRevPrev)

#ifdef Rte_Pim_MotAgCmpMotCtrlMotAgMeclPrev
# undef Rte_Pim_MotAgCmpMotCtrlMotAgMeclPrev
#endif
#define Rte_Pim_MotAgCmpMotCtrlMotAgMeclPrev() (&MotAgCmp_Pim_MotAgCmpMotCtrlMotAgMeclPrev)


/*** Client Stub ***/

extern FUNC(void, AUTOMATIC) Rte_Stub(void);


#endif
