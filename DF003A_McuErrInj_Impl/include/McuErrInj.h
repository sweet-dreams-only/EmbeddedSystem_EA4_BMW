/*****************************************************************************
* Copyright 2016,2017 Nxtr 
* Nxtr Confidential
*
* Module File Name  : McuErrInj.h
* Module Description: Micro Diag Error Injection header file
* Project           : CBD
* Author            : Avinash James
***********************************************************************************************************************
* Version Control:
* %version:          3 %
* %derived_by:       rzk04c %
*----------------------------------------------------------------------------------------------------------------------
* Date      Rev      Author         Change Description                                                           SCR #
* -------   -------  --------  ---------------------------------------------------------------------------     --------
* 12/13/16  1        AJM       Initial version                                                                 EA4#6934
* 03/20/17  2        AJM       Corrected the value for MCUERRINJ_NTC0003BIT01CASE04_CNT_U32                    EA4#6934
* 07/21/17  3        AJM       Added few more test functions and #defines for NTC0x39,0x3A,0x2A                EA4#13348
**********************************************************************************************************************/
#ifndef MCUERRINJ_H
#define MCUERRINJ_H

#include "CDD_ExcpnHndlg.h"
#include "intc_regs.h"
#include "lockstep_regs.h"
#include "adcd_regs.h"
#include "tsg3_regs.h"
#include "tauj_regs.h"
#include "taud_regs.h"
#include "ostm_regs.h"
#include "enca_regs.h"
#include "csih_regs.h"
#include "rsent_regs.h"
#include "psi5_regs.h"
#include "rscan_regs.h"
#include "dma_regs.h"
#include "flxa_regs.h"
#include "ecc_regs.h"
#include "Os.h"
#include "NxtrMcuSuprtLib.h"
#include <float.h>
#include <v800_ghs.h> /* for SYNCM intrinsic */  
#include <string.h>

/* MISRA-C:2004 Rule 8.8 [NXTRDEV 8.8.1]: Deviation allowed for functions required to be declared in two headers to be accessible via the RTE as well as outside of the RTE 
						  Function Names: ClrErrInjReg_Oper,ReadErrInjReg_Oper,UpdErrInjReg_Oper,StrtErrInjCntr_Oper*/

extern FUNC(void, McuErrInj_CODE) ClrErrInjReg_Oper(void);
extern FUNC(void, McuErrInj_CODE) ReadErrInjReg_Oper(P2VAR(uint32, AUTOMATIC, RTE_MCUERRINJ_APPL_VAR) ErrId_Arg);
extern FUNC(void, McuErrInj_CODE) StrtErrInjCntr_Oper(void);
extern FUNC(void, McuErrInj_CODE) UpdErrInjReg_Oper(uint16 NtcNr_Arg, uint8 NtcStInfo_Arg, uint8 ErrInjNr_Arg);
extern FUNC(void, McuErrInj_CODE) McuDiagcTestTrustd(void) ;

#define MCUDIAGCERRINJ                        STD_OFF

#if (MCUDIAGCERRINJ == STD_ON)

#define MCUERRINJ_CPU1PEID_CNT_U32 				((uint32)0x01U)
#define MCUERRINJ_PRPHLTOLCLRAMSPID_CNT_U32		((uint32)0x03U)  /* Peripheral to Local RAM SPID = 3U - Not used*/
#define MCUERRINJ_LCLRAMTOPRPHLSPID_CNT_U32		((uint32)0x02U)  /* Local RAM to Peripheral SPID = 2U - Not used */
#define MCUERRINJ_LCLRAMTOLCLRAMSPID_CNT_U32	((uint32)0x00U)  /* Local RAM to Local RAM SPID = 0U */
#define MCUERRINJ_USRMODENA_CNT_U32				((uint32)0x1U)   /* User Mode Bit : 1: User Mode Access Allowed - Not used*/
#define MCUERRINJ_USRMODDI_CNT_U32				((uint32)0x0U)   /* User Mode Bit : 0: Supervisor Mode access only */

#define MCUERRINJ_SNGBITECCERRADR1_CNT_U32		((uint32)0x0100A000U)
#define MCUERRINJ_SNGBITECCERRADR2_CNT_U32		((uint32)0x0100A010U)
#define MCUERRINJ_DBLBITECCERRADR_CNT_U32		((uint32)0x0100A8B0U)
#define MCUERRINJ_TESTRSTUKWN_CNT_U32		    0xAAAA5555UL

extern volatile uint32 McuDiagcTestVar1_G;
extern volatile uint32 McuDiagcTestVar2_G;
extern volatile float32 McuDiagcTestVar3_G;
extern volatile uint32 McuDiagcTestAry_G[8U];
extern volatile VAR(uint32, AUTOMATIC) DmaWrDataVar_G[4U];

/* CM111A */
extern FUNC(void, CDD_VrfyCritReg_CODE) InjVrfyCritRegErr(void);

/* CM101A */
extern FUNC(void, CDD_ExcpnHndlg_CODE) InjMcuVltgMonrErr(void);
extern FUNC(void, CDD_ExcpnHndlg_CODE) InjClkMonrErr(void);
extern FUNC(void, CDD_ExcpnHndlg_CODE) InjOsTmpGenericRtErr (void);
extern FUNC(void, CDD_ExcpnHndlg_CODE) InjOsPrmntGenericRtErr (void);
extern FUNC(void, CDD_ExcpnHndlg_CODE) InjWdgErr (void);
extern FUNC(void, CDD_ExcpnHndlg_CODE) InjFpuErr (void);
extern FUNC(void, CDD_ExcpnHndlg_CODE) InjMemProtnErr (void);
extern FUNC(void, CDD_ExcpnHndlg_CODE) InjModErr (void);
extern FUNC(void, CDD_ExcpnHndlg_CODE) InjMcuRtErr (void);
extern FUNC(void, CDD_ExcpnHndlg_CODE) InjProgSeqErr (void);
extern FUNC(void, CDD_ExcpnHndlg_CODE) InjPbgRtErr (void);

/* CM102A */
extern FUNC(void, CDD_FlsMem_CODE) InjCodFlsEccErr(void);

/* CM103A */
extern FUNC(void, CDD_RamMem_CODE) InjRamErr(void);

/* CM104A */
extern FUNC(void, CDD_EcmOutpAndDiagc_CODE)InjEcmMstChkrRtErr(void);
extern FUNC(void, CDD_EcmOutpAndDiagc_CODE)InjUkwnStrtUpDetdErr(void);

/* CM107A */
extern FUNC(void, CDD_GuardCfgAndDiagc_CODE)InjIpgRtErr(void);
extern FUNC(void, CDD_GuardCfgAndDiagc_CODE)InjRtPegErr(void);

/* CM108A */
extern FUNC(void, CDD_DataAndAdrPar_CODE)InjDataParErr(void);

/* CM200A */
extern FUNC(void, CDD_DmaCfgAndUse_CODE) InjDmaErr(void);
extern FUNC(void, CDD_DmaCfgAndUse_CODE) InjMcuDiagcErr(void);

/* CM340A */
extern FUNC(void, CDD_AdcDiagc_CODE) InjAdcErr(void);

/* AR100A */
extern FUNC(void, NxtrMath_CODE) InjSwFpuErr(void);

/*CM340A - ADC Diagnostic*/
#define MCUERRINJ_NTC0032BIT03ANDBIT01CASE01_CNT_U32 					0x00320A01U
#define MCUERRINJ_NTC0032BIT03ANDBIT02ANDBIT01CASE01_CNT_U32 			0x00320E01U
#define MCUERRINJ_NTC0032BIT03ANDBIT02CASE01_CNT_U32 					0x00320C01U
#define MCUERRINJ_NTC0032BIT03CASE01_CNT_U32 							0x00320801U
#define MCUERRINJ_NTC0032BIT04ANDBIT01CASE01_CNT_U32 					0x00321201U
#define MCUERRINJ_NTC0032BIT04ANDBIT01CASE02_CNT_U32 					0x00321202U
#define MCUERRINJ_NTC0032BIT04ANDBIT02ANDBIT01CASE01_CNT_U32 			0x00321601U
#define MCUERRINJ_NTC0032BIT04ANDBIT02ANDBIT01CASE02_CNT_U32 			0x00321602U
#define MCUERRINJ_NTC0032BIT04ANDBIT02CASE01_CNT_U32 					0x00321401U
#define MCUERRINJ_NTC0032BIT04ANDBIT02CASE02_CNT_U32 					0x00321402U
#define MCUERRINJ_NTC0032BIT04ANDBIT02CASE03_CNT_U32 					0x00321403U
#define MCUERRINJ_NTC0032BIT04ANDBIT03ANDBIT01CASE01_CNT_U32 			0x00321A01U
#define MCUERRINJ_NTC0032BIT04ANDBIT03ANDBIT02ANDBIT01CASE01_CNT_U32 	0x00321E01U
#define MCUERRINJ_NTC0032BIT04ANDBIT03ANDBIT02CASE01_CNT_U32 			0x00321C01U
#define MCUERRINJ_NTC0032BIT05CASE01_CNT_U32 							0x00322001U
#define MCUERRINJ_NTC0032BIT06CASE01_CNT_U32 							0x00324001U
#define MCUERRINJ_NTC0033BIT05CASE01_CNT_U32 							0x00332001U
#define MCUERRINJ_NTC0033BIT06CASE01_CNT_U32 							0x00334001U

/*CM103A - RamMem*/
#define MCUERRINJ_NTC0012BIT06CASE01_CNT_U32 					0x00124001U
#define MCUERRINJ_NTC0012BIT06CASE02_CNT_U32 					0x00124002U
#define MCUERRINJ_NTC0012BIT06CASE03_CNT_U32 					0x00124003U
#define MCUERRINJ_NTC0012BIT06CASE04_CNT_U32 					0x00124004U
#define MCUERRINJ_NTC0017BIT01CASE01_CNT_U32 					0x00170201U
#define MCUERRINJ_NTC0018BIT01CASE01_CNT_U32 					0x00180201U
#define MCUERRINJ_NTC0019BIT01CASE01_CNT_U32 					0x00190201U
#define MCUERRINJ_NTC001ABIT01CASE01_CNT_U32 					0x001A0201U
#define MCUERRINJ_NTC0012BIT04CASE01_CNT_U32 					0x00121001U
#define MCUERRINJ_NTC001BBIT01CASE01_CNT_U32 					0x001B0201U
#define MCUERRINJ_NTC0012BIT05CASE01_CNT_U32 					0x00122001U
#define MCUERRINJ_NTC001DBIT01CASE01_CNT_U32 					0x001D0201U
#define MCUERRINJ_NTC0016BIT01CASE01_CNT_U32 					0x00160201U
#define MCUERRINJ_NTC0012BIT03CASE01_CNT_U32 					0x00120801U
#define MCUERRINJ_NTC0012BIT00CASE01_CNT_U32 					0x00120101U
#define MCUERRINJ_NTC0012BIT00CASE02_CNT_U32 					0x00120102U
#define MCUERRINJ_NTC0012BIT00CASE03_CNT_U32 					0x00120103U
#define MCUERRINJ_NTC0012BIT00CASE04_CNT_U32 					0x00120104U
#define MCUERRINJ_NTC0012BIT00CASE05_CNT_U32 					0x00120105U
#define MCUERRINJ_NTC0012BIT00CASE06_CNT_U32 					0x00120106U
#define MCUERRINJ_NTC0012BIT00CASE07_CNT_U32 					0x00120107U
#define MCUERRINJ_NTC0012BIT00CASE08_CNT_U32 					0x00120108U
#define MCUERRINJ_NTC0012BIT00CASE09_CNT_U32 					0x00120109U
#define MCUERRINJ_NTC0012BIT00CASE0A_CNT_U32					0x0012010AU
#define MCUERRINJ_NTC0013BIT01CASE01_CNT_U32					0x00130201U
#define MCUERRINJ_NTC0013BIT01CASE02_CNT_U32					0x00130202U
#define MCUERRINJ_NTC0013BIT00CASE01_CNT_U32					0x00130101U
#define MCUERRINJ_NTC0013BIT00CASE02_CNT_U32					0x00130102U
#define MCUERRINJ_NTC0013BIT02CASE01_CNT_U32					0x00130401U
#define MCUERRINJ_NTC0012BIT02CASE01_CNT_U32					0x00120401U


#define MCUERRINJ_NTC0020BIT00CASE01_CNT_U32					0x00200101U
#define MCUERRINJ_NTC0020BIT01CASE01_CNT_U32					0x00200201U
#define MCUERRINJ_NTC0020BIT00CASE02_CNT_U32					0x00200102U
#define MCUERRINJ_NTC0020BIT01CASE02_CNT_U32					0x00200202U

#define MCUERRINJ_NTC002BBIT01CASE02_CNT_U32					0x002B0202U
#define MCUERRINJ_NTC002BBIT00CASE01_CNT_U32					0x002B0101U
#define MCUERRINJ_NTC002BBIT01CASE01_CNT_U32					0x002B0201U

#define MCUERRINJ_NTC0036BIT00CASE01_CNT_U32					0x00360101U
#define MCUERRINJ_NTC0036BIT00CASE02_CNT_U32					0x00360102U
#define MCUERRINJ_NTC0036BIT01CASE01_CNT_U32					0x00360201U

#define MCUERRINJ_NTC0010BIT00CASE01_CNT_U32					0x00100101U
#define MCUERRINJ_NTC0029BIT04CASE01_CNT_U32					0x00291001U
#define MCUERRINJ_NTC0029BIT06CASE01_CNT_U32					0x00294001U
#define MCUERRINJ_NTC0029BIT06CASE02_CNT_U32					0x00294002U
#define MCUERRINJ_NTC0029BIT06CASE03_CNT_U32					0x00294003U
#define MCUERRINJ_NTC0029BIT06CASE04_CNT_U32					0x00294004U

#define MCUERRINJ_NTC0021BIT00CASE01_CNT_U32					0x00210101U
#define MCUERRINJ_NTC0021BIT00CASE02_CNT_U32					0x00210102U
#define MCUERRINJ_NTC0021BIT02CASE01_CNT_U32					0x00210401U
#define MCUERRINJ_NTC0021BIT02CASE02_CNT_U32					0x00210402U
#define MCUERRINJ_NTC0021BIT04CASE01_CNT_U32					0x00211001U
#define MCUERRINJ_NTC0021BIT05CASE01_CNT_U32					0x00212001U
#define MCUERRINJ_NTC0021BIT06CASE01_CNT_U32					0x00214001U
#define MCUERRINJ_NTC0021BIT07CASE01_CNT_U32					0x00218001U


#define MCUERRINJ_NTC0026BIT00CASE01_CNT_U32					0x00260101U
#define MCUERRINJ_NTC0026BIT00CASE02_CNT_U32					0x00260102U
#define MCUERRINJ_NTC0026BIT01CASE01_CNT_U32					0x00260201U
#define MCUERRINJ_NTC0026BIT02CASE01_CNT_U32					0x00260401U
#define MCUERRINJ_NTC0026BIT03CASE01_CNT_U32					0x00260801U
#define MCUERRINJ_NTC0026BIT04CASE01_CNT_U32					0x00261001U
#define MCUERRINJ_NTC0026BIT04CASE02_CNT_U32					0x00261002U
#define MCUERRINJ_NTC0026BIT07CASE01_CNT_U32					0x00268001U
#define MCUERRINJ_NTC0026BIT07CASE02_CNT_U32					0x00268002U
#define MCUERRINJ_NTC0029BIT01CASE01_CNT_U32					0x00290201U
#define MCUERRINJ_NTC0029BIT00CASE01_CNT_U32					0x00290101U
#define MCUERRINJ_NTC0029BIT03CASE01_CNT_U32					0x00290801U
#define MCUERRINJ_NTC0029BIT05CASE01_CNT_U32					0x00292001U
#define MCUERRINJ_NTC0029BIT07CASE01_CNT_U32					0x00298001U  

#define MCUERRINJ_NTC0037BIT07CASE01_CNT_U32					0x00378001U
#define MCUERRINJ_NTC0037BIT07CASE02_CNT_U32					0x00378002U
#define MCUERRINJ_NTC0037BIT07CASE03_CNT_U32					0x00378003U
#define MCUERRINJ_NTC0037BIT07CASE04_CNT_U32					0x00378004U
#define MCUERRINJ_NTC0037BIT07CASE05_CNT_U32					0x00378005U
#define MCUERRINJ_NTC0037BIT07CASE06_CNT_U32					0x00378006U
#define MCUERRINJ_NTC0037BIT07CASE07_CNT_U32					0x00378007U
#define MCUERRINJ_NTC0037BIT07CASE08_CNT_U32					0x00378008U
#define MCUERRINJ_NTC0037BIT07CASE09_CNT_U32					0x00378009U
#define MCUERRINJ_NTC0037BIT07CASE0A_CNT_U32					0x0037800AU
#define MCUERRINJ_NTC0037BIT07CASE0B_CNT_U32					0x0037800BU
#define MCUERRINJ_NTC0037BIT07CASE0C_CNT_U32					0x0037800CU

#define MCUERRINJ_NTC0037BIT06CASE01_CNT_U32					0x00374001U
#define MCUERRINJ_NTC0037BIT06CASE02_CNT_U32					0x00374002U
#define MCUERRINJ_NTC0037BIT06CASE03_CNT_U32					0x00374003U
#define MCUERRINJ_NTC0037BIT06CASE04_CNT_U32					0x00374004U
#define MCUERRINJ_NTC0037BIT06CASE05_CNT_U32					0x00374005U
#define MCUERRINJ_NTC0037BIT06CASE06_CNT_U32					0x00374006U


#define MCUERRINJ_NTC0022BIT01CASE01_CNT_U32					0x00220201U
#define MCUERRINJ_NTC0022BIT01CASE02_CNT_U32					0x00220202U
#define MCUERRINJ_NTC0022BIT01CASE03_CNT_U32					0x00220203U
#define MCUERRINJ_NTC0022BIT01CASE04_CNT_U32					0x00220204U
#define MCUERRINJ_NTC0022BIT01CASE05_CNT_U32					0x00220205U
#define MCUERRINJ_NTC0022BIT01CASE06_CNT_U32					0x00220206U

#define MCUERRINJ_NTC002DBIT04CASE01_CNT_U32					0x002D1001U
#define MCUERRINJ_NTC002DBIT04CASE02_CNT_U32					0x002D1002U
#define MCUERRINJ_NTC0022BIT05CASE02_CNT_U32					0x002D2002U
#define MCUERRINJ_NTC0022BIT05CASE03_CNT_U32					0x002D2003U
#define MCUERRINJ_NTC0022BIT05CASE04_CNT_U32					0x002D2004U
#define MCUERRINJ_NTC0022BIT05CASE05_CNT_U32					0x002D2005U
#define MCUERRINJ_NTC0022BIT05CASE06_CNT_U32					0x002D2006U

#define MCUERRINJ_NTC002DBIT01CASE01_CNT_U32					0x002D0201U
#define MCUERRINJ_NTC002DBIT01CASE02_CNT_U32					0x002D0202U
#define MCUERRINJ_NTC002DBIT05CASE01_CNT_U32					0x002D2001U

#define MCUERRINJ_NTC0022BIT00CASE01_CNT_U32					0x00220101U
#define MCUERRINJ_NTC0022BIT00CASE02_CNT_U32					0x00220102U
#define MCUERRINJ_NTC0022BIT02CASE01_CNT_U32					0x00220401U
#define MCUERRINJ_NTC0022BIT03CASE01_CNT_U32					0x00220801U
#define MCUERRINJ_NTC0022BIT04CASE01_CNT_U32					0x00221001U
#define MCUERRINJ_NTC0022BIT05CASE01_CNT_U32					0x00222001U
#define MCUERRINJ_NTC0022BIT06CASE01_CNT_U32					0x00224001U
#define MCUERRINJ_NTC0022BIT06CASE02_CNT_U32					0x00224002U
#define MCUERRINJ_NTC0022BIT06CASE03_CNT_U32					0x00224003U
#define MCUERRINJ_NTC0022BIT06CASE04_CNT_U32					0x00224004U
#define MCUERRINJ_NTC0022BIT07CASE01_CNT_U32					0x00228001U


#define MCUERRINJ_NTC002DBIT05CASE02_CNT_U32					0x002D2002U
#define MCUERRINJ_NTC002DBIT05CASE03_CNT_U32					0x002D2003U
#define MCUERRINJ_NTC002DBIT05CASE04_CNT_U32					0x002D2004U
#define MCUERRINJ_NTC002DBIT05CASE05_CNT_U32					0x002D2005U
#define MCUERRINJ_NTC002DBIT05CASE06_CNT_U32					0x002D2006U

#define MCUERRINJ_NTC0002BIT00CASE01_CNT_U32					(0x00020101U)
#define MCUERRINJ_NTC0002BIT00CASE02_CNT_U32					(0x00020102U)
#define MCUERRINJ_NTC0003BIT00CASE01_CNT_U32					(0x00030101U)
#define MCUERRINJ_NTC0003BIT00CASE02_CNT_U32					(0x00030102U)
#define MCUERRINJ_NTC0003BIT01CASE01_CNT_U32					(0x00030201U)
#define MCUERRINJ_NTC0003BIT01CASE04_CNT_U32					(0x00030204U)
#define MCUERRINJ_NTC0003BIT01CASE03_CNT_U32					(0x00030203U)
#define MCUERRINJ_NTC0003BIT02CASE01_CNT_U32					(0x00030401U)

#define MCUERRINJ_NTC0028BIT01CASE01_CNT_U32					0x00280201U
#define MCUERRINJ_NTC0028BIT01CASE02_CNT_U32					0x00280202U
#define MCUERRINJ_NTC0028BIT01CASE03_CNT_U32					0x00280203U
#define MCUERRINJ_NTC0028BIT02CASE01_CNT_U32					0x00280401U
#define MCUERRINJ_NTC0028BIT03CASE01_CNT_U32					0x00280801U
#define MCUERRINJ_NTC0028BIT04CASE01_CNT_U32					0x00281001U

#define MCUERRINJ_NTC0025BIT01CASE01_CNT_U32					0x00250201U
#define MCUERRINJ_NTC0025BIT00CASE01_CNT_U32					0x00250101U

#define MCUERRINJ_NTC002DBIT03CASE01_CNT_U32					0x002D0801U
#define MCUERRINJ_NTC002DBIT03CASE02_CNT_U32					0x002D0802U
#define MCUERRINJ_NTC002DBIT03CASE03_CNT_U32					0x002D0803U
#define MCUERRINJ_NTC002DBIT03CASE04_CNT_U32					0x002D0804U
#define MCUERRINJ_NTC002DBIT03CASE05_CNT_U32					0x002D0805U
#define MCUERRINJ_NTC002DBIT03CASE06_CNT_U32					0x002D0806U

#define MCUERRINJ_NTC0023BIT02CASE01_CNT_U32					0x00230401U
#define MCUERRINJ_NTC0023BIT03CASE01_CNT_U32					0x00230801U
#define MCUERRINJ_NTC0023BIT06CASE01_CNT_U32					0x00234001U
#define MCUERRINJ_NTC0023BIT07CASE01_CNT_U32					0x00238001U


#define MCUERRINJ_NTC0027BIT02CASE01_CNT_U32					0x00270401U
#define MCUERRINJ_NTC0027BIT03CASE01_CNT_U32					0x00270801U
#define MCUERRINJ_NTC0027BIT06CASE01_CNT_U32					0x00274001U
#define MCUERRINJ_NTC0027BIT07CASE01_CNT_U32					0x00278001U

#define MCUERRINJ_NTC0024BIT00CASE01_CNT_U32					0x00240101U
#define MCUERRINJ_NTC0024BIT01CASE01_CNT_U32					0x00240201U
#define MCUERRINJ_NTC0024BIT02CASE01_CNT_U32					0x00240401U

#define MCUERRINJ_NTC002CBIT00CASE01_CNT_U32					0x002C0101U
#define MCUERRINJ_NTC0030BIT00CASE01_CNT_U32					0x00300101U
#define MCUERRINJ_NTC0030BIT01CASE01_CNT_U32					0x00300201U

#define MCUERRINJ_NTC0031BIT00CASE01_CNT_U32					0x00310101U
#define MCUERRINJ_NTC0049BIT00CASE01_CNT_U32					0x00490101U
#define MCUERRINJ_NTC0049BIT01CASE01_CNT_U32					0x00490201U

#define MCUERRINJ_NTC002ABIT00CASE01_CNT_U32					0x002A0101U
#define MCUERRINJ_NTC002ABIT02CASE01_CNT_U32					0x002A0401U

#define MCUERRINJ_NTC0039BIT00CASE01_CNT_U32					0x00390101U
#define MCUERRINJ_NTC0039BIT00CASE02_CNT_U32					0x00390102U
#define MCUERRINJ_NTC0039BIT00CASE03_CNT_U32					0x00390103U
#define MCUERRINJ_NTC0039BIT00CASE04_CNT_U32					0x00390104U

#define MCUERRINJ_NTC003ABIT22CASE01_CNT_U32					0x003A2201U

#endif
#endif
