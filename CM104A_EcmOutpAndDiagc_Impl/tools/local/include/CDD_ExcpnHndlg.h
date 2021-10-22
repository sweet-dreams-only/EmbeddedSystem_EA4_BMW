/* Contract file for CM104A */
#ifndef CDD_EXCPNHNDLG_H
#define CDD_EXCPNHNDLG_H

/* McuDiagc1 enumeration type */
typedef uint32 McuDiagc1;

/* Used for micro diag error injection testing */
#define         MCUDIAGC_MCUDIAGCTEST            (4294901760U)   /* 0xFFFF0000 */
/* Boot Loader Control Values */

/* Start-Up Tests (Pre OS) */

#define         MCUDIAGC_MSTERROUTPCTRLFLT       (4285333650U)   /* 0xFF6D0092 */
#define         MCUDIAGC_CHKRERROUTPCTRLFLT      (4285137045U)   /* 0xFF6A0095 */
#define         MCUDIAGC_ECMSTSSTRTUPFLT         (4284547230U)   /* 0xFF61009E */
#define         MCUDIAGC_EIINTRPTSTRTUPFLT       (4284350625U)   /* 0xFF5E00A1 */
#define         MCUDIAGC_ECMPSDOERRINJFLT        (4284154020U)   /* 0xFF5B00A4 */
#define         MCUDIAGC_FACIRSTTRFERR           (4283564205U)   /* 0xFF5200AD */
#define         MCUDIAGC_ECMRST                  (4294246410U)   /* 0xFFF5000A */

/* Function prototypes */
extern FUNC(void, CDD_ExcpnHndlg_CODE) SetMcuDiagcIdnData(McuDiagc1 McuDiagcData0_Arg,
                uint32 McuDiagcData1_Arg);
extern FUNC(void, CDD_ExcpnHndlg_CODE) GetMcuDiagcIdnData(P2VAR(McuDiagc1, AUTOMATIC, ExcpnHndlg_APPL_VAR) McuDiagcData0_Arg);

extern FUNC(void, CDD_ExcpnHndlg_CODE) ChkForStrtUpTest_Oper(P2VAR(boolean, AUTOMATIC, RTE_CDD_EXCPNHNDLG_APPL_VAR) ExecStrtUpTest_Arg); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#endif
