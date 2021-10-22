/**********************************************************************************************************************
Stub file for CM107A
**********************************************************************************************************************/

#ifndef CDD_EXCPNHNDLG_H
#define CDD_EXCPNHNDLG_H

/* McuDiagc1 enumeration type */
typedef uint32 McuDiagc1;

/* Used for micro diag error injection testing */
#define         MCUDIAGC_MCUDIAGCTEST            (4294901760U)   /* 0xFFFF0000 */
#define         MCUDIAGC_PBGSTRTUPTST            (4283957415U)   /* 0xFF5800A7 */

extern FUNC(void, CDD_ExcpnHndlg_CODE) SetMcuDiagcIdnData(McuDiagc1 McuDiagcData0_Arg,
                                                    uint32 McuDiagcData1_Arg);
extern FUNC(void, CDD_ExcpnHndlg_CODE) GetMcuDiagcIdnData(P2VAR(McuDiagc1, AUTOMATIC, ExcpnHndlg_APPL_VAR) McuDiagcData0_Arg);
extern FUNC(void, CDD_ExcpnHndlg_CODE) ChkForStrtUpTest_Oper(P2VAR(boolean, AUTOMATIC, RTE_CDD_EXCPNHNDLG_APPL_VAR) ExecStrtUpTest_Arg);

#endif
