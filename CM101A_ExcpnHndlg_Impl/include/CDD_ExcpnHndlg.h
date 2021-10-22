/**********************************************************************************************************************
* Copyright 2015, 2016, 2017, 2018 Nxtr
* Nxtr Confidential
*
* Module File Name  : CDD_ExcpnHndlg.h 
* Module Description: Declarations of McuDiagc1 data type and global functions of CM101A Exception Handling RH850
* Project           : CBD
* Author            : Kathleen Creager
***********************************************************************************************************************
* Version Control:
* %version:          11 %
* %derived_by:       rzk04c %
*---------------------------------------------------------------------------------------------------------------------
* Date      Rev      Author    Change Description                                                              SCR#
* --------  ------  ---------  ----------------------------------------------------------------------------  ---------
* 09/11/15   1        KMC      Initial Version                                                               EA4#1832
* 01/19/15   2        LWW      Updated for error and protection hook removal                                 EA4#3185
* 02/10/16   3        AJM      Updated for Clock monitor FENMI handling,                                     EA4#3765
*                              Fault processing for Start up test of P Bus and PBG
* 03/22/16   4        AJM      Changed DTS RAM Double BIT ECC fault to SYSERR type from FENMI                EA4#4632
* 04/05/16   5        AJM      Added Mode error handlers, removed SPI Dbl bit Handler,added defines for      EA4#5099
*                              new fault cases
* 08/08/16   6        AJM      Added reset case definitions for INTCNCTRESDAREA and INVLDMEMACS              EA4#6629
* 02/11/17   7        AJM      Added micro diag test reset case and LOCKSTEPECMRST                           EA4#8355 
* 05/25/17   8        Shruthi  Added MCUDIAGC_CODFLASHEXECENAREGFAILR case to be able to handle
*                              FLS_E_REG_WRITE_VERIFY MCAL failure                                           EA4#12224
* 07/20/17   9        AJM      Fixed extern declaration for ChkForStrtUpTest_Oper                            EA4#13344
* 09/20/17   10       AJM      Added QUICKIGNRST reset cause                                                 EA4#15032 
* 03/29/18   11       AJM      Added DTSECCSNGBITERR & CUSTRST reset cause and FeNmiDtsEccSngBitErr          EA4#20984,EA4#21920
                               exception.Corrected value for BACKUPRAMTSTFAILR
**********************************************************************************************************************/
#ifndef CDD_EXCPNHNDLG_H
#define CDD_EXCPNHNDLG_H

/* McuDiagc1 enumeration type */
typedef uint32 McuDiagc1;

/* Used for micro diag error injection testing */
#define         MCUDIAGC_MCUDIAGCTEST            (4294901760U)   /* 0xFFFF0000 */
/* Boot Loader Control Values */
#define         MCUDIAGC_FLSPROGMREQ             (4294836225U)   /* 0xFFFE0001 */
#define         MCUDIAGC_FLSPROGMCMPL            (4294639620U)   /* 0xFFFB0004 */
#define         MCUDIAGC_PWRONRST                (4294443015U)   /* 0xFFF80007 */
#define         MCUDIAGC_ECMRST                  (4294246410U)   /* 0xFFF5000A */
#define         MCUDIAGC_PINRST                  (4294049805U)   /* 0xFFF2000D */
#define         MCUDIAGC_COREVLTGMONRLO          (4293853200U)   /* 0xFFEF0010 */
#define         MCUDIAGC_COREVLTGMONRHI          (4293656595U)   /* 0xFFEC0013 */
#define         MCUDIAGC_PREOSEXCPN              (4293459990U)   /* 0xFFE90016 */
#define         MCUDIAGC_RSTUKWN                 (4293263385U)   /* 0xFFE60019 */
#define         MCUDIAGC_BACKUPRAMTSTFAILR       (4293066780U)   /* 0xFFE3001C */
#define         MCUDIAGC_DBGRST                  (4292870175U)   /* 0xFFE0001F */
#define         MCUDIAGC_LOCKSTEPECMRST          (4292673570U)   /* 0xFFDD0022 */

/* Start-Up Tests (Pre OS) */
#define         MCUDIAGC_BISTECCERR              (4286513280U)   /* 0xFF7F0080 */
#define         MCUDIAGC_BISTNOTCMPLERR          (4286316675U)   /* 0xFF7C0083 */
#define         MCUDIAGC_LOGLBISTERR             (4286120070U)   /* 0xFF790086 */
#define         MCUDIAGC_MEMBISTERR              (4285923465U)   /* 0xFF760089 */
#define         MCUDIAGC_DMALOCKSTEPERR          (4285726860U)   /* 0xFF73008C */
#define         MCUDIAGC_CPULOCKSTEPERR          (4285530255U)   /* 0xFF70008F */
#define         MCUDIAGC_MSTERROUTPCTRLFLT       (4285333650U)   /* 0xFF6D0092 */
#define         MCUDIAGC_CHKRERROUTPCTRLFLT      (4285137045U)   /* 0xFF6A0095 */
#define         MCUDIAGC_STRTUPCOREVLTGMONROVER  (4284940440U)   /* 0xFF670098 */
#define         MCUDIAGC_STRTUPCOREVLTGMONRUNDER (4284743835U)   /* 0xFF64009B */
#define         MCUDIAGC_ECMSTSSTRTUPFLT         (4284547230U)   /* 0xFF61009E */
#define         MCUDIAGC_EIINTRPTSTRTUPFLT       (4284350625U)   /* 0xFF5E00A1 */
#define         MCUDIAGC_ECMPSDOERRINJFLT        (4284154020U)   /* 0xFF5B00A4 */
#define         MCUDIAGC_PBGSTRTUPTST            (4283957415U)   /* 0xFF5800A7 */
#define         MCUDIAGC_PRPHLBUSDATAPARSTRTUPFLT (4283760810U)  /* 0xFF5500AA */
#define         MCUDIAGC_FACIRSTTRFERR           (4283564205U)   /* 0xFF5200AD */
#define         MCUDIAGC_CODFLASHEXECENAREGFAILR (4283367600U)   /* 0xFF4F00B0 */

/* EI Int Range */
#define         MCUDIAGC_CODFLSSNGBITHARDFLT      (4278124800U)  /* 0xFEFF0100 */  
#define         MCUDIAGC_LCLRAMECCSNGBITHARDFAILR (4277928195U)  /* 0xFEFC0103 */

/* Service Command Range */
#define         MCUDIAGC_SOFTRST                 (4261347840U)   /* 0xFDFF0200 */
#define         MCUDIAGC_HARDRST                 (4261151235U)   /* 0xFDFC0203 */
#define         MCUDIAGC_QUICKIGNRST             (4260954630U)   /* 0xFDF90206 */
#define         MCUDIAGC_CUSTRST                 (4260758025U)   /* 0xFDF60209 */

/* FE Int Range */
#define         MCUDIAGC_SPIRAMDBLBIT0           (4227793920U)   /* 0xFBFF0400 */
#define         MCUDIAGC_SPIRAMDBLBIT1           (4227597315U)   /* 0xFBFC0403 */
#define         MCUDIAGC_SPIRAMDBLBIT2           (4227400710U)   /* 0xFBF90406 */
#define         MCUDIAGC_SPIRAMDBLBIT3           (4227204105U)   /* 0xFBF60409 */
#define         MCUDIAGC_FENMIWDG                (4227007500U)   /* 0xFBF3040C */
#define         MCUDIAGC_FENMIPROGFLOW           (4226810895U)   /* 0xFBF0040F */
#define         MCUDIAGC_FENMIALVMONR            (4226614290U)   /* 0xFBED0412 */
#define         MCUDIAGC_FEUKWN                  (4226417685U)   /* 0xFBEA0415 */  
#define         MCUDIAGC_FENMIDEADLINEMONR       (4226221080U)   /* 0xFBE70418 */
#define         MCUDIAGC_DTSDBLBIT               (4226024475U)   /* 0xFBE4041B */
#define         MCUDIAGC_PROCRELMGUARD           (4225827870U)   /* 0xFBE1041E */
#define         MCUDIAGC_ECMMSTCHKRERR           (4225631265U)   /* 0xFBDE0421 */
#define         MCUDIAGC_DMATRFERR               (4225434660U)   /* 0xFBDB0424 */
#define         MCUDIAGC_DMAREGACSPROTCNERR      (4225238055U)   /* 0xFBD80427 */
#define         MCUDIAGC_CLKMONR0RTLOWRLIMFLT    (4225041450U)   /* 0xFBD5042A */
#define         MCUDIAGC_CLKMONR0RTUPPRLIMFLT    (4224844845U)   /* 0xFBD2042D */
#define         MCUDIAGC_CLKMONR1RTLOWRLIMFLT    (4224648240U)   /* 0xFBCF0430 */
#define         MCUDIAGC_CLKMONR1RTUPPRLIMFLT    (4224451635U)   /* 0xFBCC0433 */
#define         MCUDIAGC_CLKMONR2RTLOWRLIMFLT    (4224255030U)   /* 0xFBC90436 */
#define         MCUDIAGC_CLKMONR2RTUPPRLIMFLT    (4224058425U)   /* 0xFBC60439 */
#define         MCUDIAGC_CLKMONR3RTLOWRLIMFLT    (4223861820U)   /* 0xFBC3043C */
#define         MCUDIAGC_CLKMONR3RTUPPRLIMFLT    (4223665215U)   /* 0xFBC0043F */
#define         MCUDIAGC_INTCNCTRESDAREA         (4223468610U)   /* 0xFBBD0442 */
#define         MCUDIAGC_INVLDMEMACS             (4223272005U)   /* 0xFBBA0445 */
#define         MCUDIAGC_DTSECCSNGBITERR         (4223075400U)   /* 0xFBB70448 */

/* Exception Range */
#define         MCUDIAGC_ADRPAR                  (4160686080U)   /* 0xF7FF0800 */
#define         MCUDIAGC_ALGNREAD                (4160489475U)   /* 0xF7FC0803 */
#define         MCUDIAGC_ALGNWR                  (4160292870U)   /* 0xF7F90806 */
#define         MCUDIAGC_FPUERRDIVBYZERO         (4160096265U)   /* 0xF7F60809 */
#define         MCUDIAGC_FPUERRINVLDOPER         (4159899660U)   /* 0xF7F3080C */
#define         MCUDIAGC_FPUERROVF               (4159703055U)   /* 0xF7F0080F */
#define         MCUDIAGC_FPUERRUKWN              (4159506450U)   /* 0xF7ED0812 */
#define         MCUDIAGC_CODFLSDBLBIT            (4159309845U)   /* 0xF7EA0815 */
#define         MCUDIAGC_LCLRAMDBLBIT            (4159113240U)   /* 0xF7E70818 */
#define         MCUDIAGC_VCIE                    (4158916635U)   /* 0xF7E4081B */
#define         MCUDIAGC_INSTRFETCH              (4158720030U)   /* 0xF7E1081E */
#define         MCUDIAGC_INTPRPHLGUARD           (4158523425U)   /* 0xF7DE0821 */
#define         MCUDIAGC_PRPHLBUSGUARD           (4158326820U)   /* 0xF7DB0824 */
#define         MCUDIAGC_RESDOPER                (4158130215U)   /* 0xF7D80827 */
#define         MCUDIAGC_UKWNEXCPN               (4157933610U)   /* 0xF7D5082A */
#define         MCUDIAGC_PRMNTOSERR              (4157737005U)   /* 0xF7D2082D */
#define         MCUDIAGC_MPU                     (4157540400U)   /* 0xF7CF0830 */
#define         MCUDIAGC_PRVLGDINSTREXCPN        (4157343795U)   /* 0xF7CC0833 */
#define         MCUDIAGC_PRPHLBUSDATAPAR         (4157147190U)   /* 0xF7C90836 */
#define         MCUDIAGC_INVLDRAMAREA            (4156950585U)   /* 0xF7C60839 */
#define         MCUDIAGC_CODFLSECCSNGBITERR      (4156753980U)   /* 0xF7C3083C */
#define         MCUDIAGC_OPERMODERRFLSPROGMMODSTRTD        (4156557375U)  /* 0xF7C0083F */
#define         MCUDIAGC_OPERMODERRTESTMODSTRTD  (4156360770U)   /* 0xF7BD0842 */
#define         MCUDIAGC_OPERMODERRSNGCHIPINACTV (4156164165U)   /* 0xF7BA0845 */


/* Function prototypes */
extern FUNC(void, CDD_ExcpnHndlg_CODE) SetMcuDiagcIdnData(McuDiagc1 McuDiagcData0_Arg,
                                                    uint32 McuDiagcData1_Arg);
extern FUNC(void, CDD_ExcpnHndlg_CODE) GetMcuDiagcIdnData(P2VAR(McuDiagc1, AUTOMATIC, ExcpnHndlg_APPL_VAR) McuDiagcData0_Arg);
extern FUNC(void, CDD_ExcpnHndlg_CODE) SysErrIrq(void);
extern FUNC(void, CDD_ExcpnHndlg_CODE) FpuErrIrq(void);
extern FUNC(void, CDD_ExcpnHndlg_CODE) AlgnErrIrq(void);
extern FUNC(void, CDD_ExcpnHndlg_CODE) ResdOperIrq(void);
extern FUNC(void, CDD_ExcpnHndlg_CODE) ExcpnHndlgInit1(void);
extern FUNC(void, CDD_ExcpnHndlg_CODE) FeNmiPeg(void);
extern FUNC(void, CDD_ExcpnHndlg_CODE) FeNmiDmaTrf(void);
extern FUNC(void, CDD_ExcpnHndlg_CODE) FeNmiDmaRegAcsProtnErr(void);
extern FUNC(void, CDD_ExcpnHndlg_CODE) FeNmiEcmMstChkrCmp(void);
extern FUNC(void, CDD_ExcpnHndlg_CODE) FeNmiWdg(void);
extern FUNC(void, CDD_ExcpnHndlg_CODE) ProcUkwnExcpnErr(uint32 McuDiagcData1_Arg);
extern FUNC(void, CDD_ExcpnHndlg_CODE) ProcMpuExcpnErr(uint32 McuDiagcData1_Arg);
extern FUNC(void, CDD_ExcpnHndlg_CODE) ProcPrvlgdInstrExcpnErr(uint32 McuDiagcData1_Arg);
extern FUNC(void, CDD_ExcpnHndlg_CODE) ProcPrmntOsErr(uint32 McuDiagcData1_Arg);
extern FUNC(void, CDD_ExcpnHndlg_CODE) ProcNonCritOsErr(uint32 McuDiagcData1_Arg);

extern FUNC(void, CDD_ExcpnHndlg_CODE) FeNmiClkMonr0RtLowrLimFlt(void);
extern FUNC(void, CDD_ExcpnHndlg_CODE) FeNmiClkMonr0RtUpprLimFlt(void);
extern FUNC(void, CDD_ExcpnHndlg_CODE) FeNmiClkMonr1RtLowrLimFlt(void);
extern FUNC(void, CDD_ExcpnHndlg_CODE) FeNmiClkMonr1RtUpprLimFlt(void);
extern FUNC(void, CDD_ExcpnHndlg_CODE) FeNmiClkMonr2RtLowrLimFlt(void);
extern FUNC(void, CDD_ExcpnHndlg_CODE) FeNmiClkMonr2RtUpprLimFlt(void);
extern FUNC(void, CDD_ExcpnHndlg_CODE) FeNmiClkMonr3RtLowrLimFlt(void);
extern FUNC(void, CDD_ExcpnHndlg_CODE) FeNmiClkMonr3RtUpprLimFlt(void);
extern FUNC(void, CDD_ExcpnHndlg_CODE) FeNmiOperModErrSngChipInactv(void);
extern FUNC(void, CDD_ExcpnHndlg_CODE) FeNmiOperModErrFlsProgmModStrtd(void);
extern FUNC(void, CDD_ExcpnHndlg_CODE) FeNmiOperModErrTestModStrtd(void);
extern FUNC(void, CDD_ExcpnHndlg_CODE) FeNmiDtsEccSngBitErr(void);

extern FUNC(void, CDD_ExcpnHndlg_CODE) ChkForStrtUpTest_Oper(P2VAR(boolean, AUTOMATIC, RTE_CDD_EXCPNHNDLG_APPL_VAR) ExecStrtUpTest_Arg); /* PRQA S 0850 */ /* MD_MSR_19.8 */

#endif
