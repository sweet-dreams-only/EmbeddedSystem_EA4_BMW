/**********************************************************************************************************************
Contract file for CM102A
**********************************************************************************************************************/
#ifndef CDD_EXCPNHNDLG_H
#define CDD_EXCPNHNDLG_H

/* McuDiagc1 enumeration type */
typedef uint32 McuDiagc1;

/* Used for micro diag error injection testing */
#define         MCUDIAGC_MCUDIAGCTEST            (4294901760U)   /* 0xFFFF0000 */


/* EI Int Range */
#define         MCUDIAGC_CODFLSSNGBITHARDFLT      (4278124800U)   /* 0xFEFF0100 */  

extern FUNC(void, CDD_ExcpnHndlg_CODE) ChkForStrtUpTest_Oper(P2VAR(boolean, AUTOMATIC, RTE_CDD_EXCPNHNDLG_APPL_VAR) ExecStrtUpTest_Arg); /* PRQA S 0850 */ /* MD_MSR_19.8 */

#endif
