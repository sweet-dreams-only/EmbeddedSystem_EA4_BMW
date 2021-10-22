/**********************************************************************************************************************
Contract file for CM112A
**********************************************************************************************************************/
#ifndef CDD_EXCPNHNDLG_H
#define CDD_EXCPNHNDLG_H

/* McuDiagc1 enumeration type */
typedef uint32 McuDiagc1;
#define         MCUDIAGC_PWRONRST                (4294443015U)   /* 0xFFF80007 */

extern FUNC(void, CDD_ExcpnHndlg_CODE) GetMcuDiagcIdnData(P2VAR(McuDiagc1, AUTOMATIC, ExcpnHndlg_APPL_VAR) McuDiagcData0_Arg);

#endif
