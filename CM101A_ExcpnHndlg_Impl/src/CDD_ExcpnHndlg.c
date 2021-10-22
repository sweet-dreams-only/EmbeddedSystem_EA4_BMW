/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *          File:  CDD_ExcpnHndlg.c
 *        Config:  E:/EA4NewTemplate/CM101A_ExcpnHndlg_Impl/tools/Component.dpa
 *     SW-C Type:  CDD_ExcpnHndlg
 *  Generated at:  Wed Sep 20 08:48:00 2017
 *
 *     Generator:  MICROSAR RTE Generator Version 4.13.0
 *                 RTE Core Version 1.13.0
 *       License:  Unlimited license CBD1400351 for Nxtr Automotive Corporation
 *
 *   Description:  C-Code implementation template for SW-C <CDD_ExcpnHndlg>
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of version logging area >>                DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
* Copyright 2015,2016,2017,2018 Nxtr 
* Nxtr Confidential
*
* Module File Name  : CDD_ExcpnHndlg.c
* Module Description: Implements the RTE functionality of CM101A Exception Handling RH850
* Project           : CBD
* Author            : Kathleen Creager
***********************************************************************************************************************
* Version Control:
* %version:          15 %
* %derived_by:       rzk04c %
*---------------------------------------------------------------------------------------------------------------------
* Date      Rev      Author    Change Description                                                             SCR #
* --------  -------  --------  ----------------------------------------------------------------------------- ---------
* 09/11/15   1       KMC       Initial Version                                                               EA4#1832
* 02/10/16	 2		 AJM       Updated for Clock monitor FENMI handling, 									 EA4#3765
							   Fault processing for Start up test of P Bus and PBG,
							   ChkForStrtUpTest server function inclusion,Soft and Hard Reset Cases
* 04/05/16   3       AJM	   Added NTC handling for DBGRST,INVLDRAMAREA,FACIRSTTRFERR and operating modes  EA4#5099
							   Changed BIST2BITERR to BISTECCERR.
* 04/18/16   4		 AJM 	   Corrected McuDiagc define for NTC 003 bit 0					   				 EA4#5409
* 06/22/16   5		 Selva 	   Added logic to differentiate between Debug Reset 
											and Debug Attached Conditions					   				 EA4#6267
* 08/08/16   6       AJM	   Updates to remove single bit code flash handling and added new NTCs for 		 EA4#6629
							   invalid mem access and errors on interconnect area access
* 08/31/16   7       Selva	   Added logic for MCUDIAGC_CODFLSSNGBITHARDFLT to set NTC 003.0                 EA4#7342
* 02/11/17   8       AJM       Added logic for backup ram rest failure,lock step failure                     EA4#8355
* 04/11/17   9       AJM       Added server runnable to return BRAMDAT1                                      EA4#10795
* 05/18/17   10      Shruthi   Removed CVM startup test diagnostics                                          EA4#11842
* 05/25/17   11      Shruthi   Added MCUDIAGC_CODFLASHEXECENAREGFAILR case to be able to handle
*                              FLS_E_REG_WRITE_VERIFY MCAL failure                                           EA4#12224
* 07/20/17   12      AJM       Quality update to remove ProcEcmRsT function call                             EA4#13344
* 09/20/17   13      AJM       Added functionality to store debug info saved to NVM from BRAMDAT registers   EA4#15032
* 10/17/17   14      AJM       Added case handling for Quick Ignition Reset                                  EA4#16352
* 03/29/18   15      AJM       Added handling for DTS single bit ECC error and CUSTRST handling              EA4#20984,EA4#21920
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
 * Data Types:
 * ===========
 * NtcNr1
 *   uint16 represents integers with a minimum value of 0 and a maximum value of 65535.
 *      The order-relation on uint16 is: x < y if y - x is positive.
 *      uint16 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 1267, +10000.
 *
 * NtcSts1
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 *********************************************************************************************************************/

#include "Rte_CDD_ExcpnHndlg.h" /* PRQA S 0857 */ /* MD_MSR_1.1_857 */


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of include and declaration area >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
#include "CDD_ExcpnHndlg.h"
#include "CDD_ExcpnHndlg_private.h"
#include "sys_regs.h" /* for SYSDEBUGMODE, SYSDEBUGMODEB, SYSRESF*, SYSCVMHVFF, SYSCVMLVFF, SYSPOF* */
#include "ram_regs.h" /* for BRAMDAT0, BRAMDAT1 */
#include "ecm_regs.h" /* for ECMMESSTR0, ECMCESSTR0 */

/* MISRA-C:2004 Rule 1.1 [NXTRDEV 1.1.1]: Inline functions are used for Nxtr Mcu Support library functions to allow for throughput optimization */
/* MISRA-C:2004 Rule 19.1 [NXTRDEV 19.1.1]: AUTOSAR requires deviation from this rule for Memory Mapping include statements */
/* MISRA-C:2004 Rule 16.10 [NXTRDEV 16.10.1]: There is no appropriate action to take on the return value for 
											  Rte_Call_SetNtcSts_Oper(),SetRamBlockStat */
/* MISRA-C:2004 Rule 11.3 [NXTRDEV 11.3.3]: Cast of an integer to a pointer is required for reading from computed addresses */
/* MISRA-C:2004 Rule 11.3 [NXTRDEV 11.3.1]: Cast of a register address to an integer type is required for writing a register address to a register*/

/* NtcStInfo values */

/* NTCNR_0X003 CodFlsHardFlt */
#define CODFLSSNGBITHARDFLT_CNT_U08         (1U)    /* bit 0 - Code Flash Single Bit ECC (Hard fault)*/
#define CODFLSECCDBLBIT_CNT_U08     		(2U)    /* bit 1 - Code Flash ECC Double Bit Detection*/
#define CODFLSADRPAR_CNT_U08        		(4U)    /* bit 2 - Code Flash Address Parity Fault */
#define CODFLASHEXECENAREGFAILR_CNT_U08		(8U)    /* bit 3 - Code Flash Register Write Failure */

/* NTCNR_0X010 MemBistStrtUpFlt */
#define MEMBISTSTRTUPTESTFAILR_CNT_U08     	(1U)    /* bit 0 - MBIST Startup Test Failure */

/* NTCNR_0X013 LclRamHardFlt */
#define LCLRAMECCSNGBITHARDFLT_CNT_U08     	(1U)    /* bit 0 - Local RAM ECC Single Bit (Hard Fault) */
#define LCLRAMECCDBLBIT_CNT_U08 			(2U)	/* bit 1 - Local RAM ECC Double Bit (Hard Fault) */
#define INVLDRAMAREA_CNT_U08 				(4U)	/* bit 2 - Invalid RAM area access (Hard Fault) */

/* NTCNR_0X016 DtsRamDblBitFlt */
#define DTSDBLBIT_CNT_U08					(2U)    /* bit 1 - DTS ECC Double Bit (Hard Fault) */
#define DTSSNGBITFLT_CNT_U08			    (4U)    /* bit 2 - DTS ECC Single Bit Error */

/* NTCNR_0X017 Spi0RamHardFlt */
#define SPI0PRPHLRAMDBLBIT_CNT_U08 			(2U)	/* bit 1 - SPI0 Periheral RAM Double Bit (Hard Fault) */

/* NTCNR_0X018 Spi1RamHardFlt */
#define SPI1PRPHLRAMDBLBIT_CNT_U08 			(2U)	/* bit 1 - SPI1 Periheral RAM Double Bit (Hard Fault) */

/* NTCNR_0X019 Spi2RamHardFlt */
#define SPI2PRPHLRAMDBLBIT_CNT_U08 			(2U)	/* bit 1 - SPI2 Periheral RAM Double Bit (Hard Fault) */

/* NTCNR_0X01A Spi3RamHardFlt */
#define SPI3PRPHLRAMDBLBIT_CNT_U08 			(2U)	/* bit 1 - SPI3 Periheral RAM Double Bit (Hard Fault) */

/* NTCNR_0X021 LoglBistStrtUpFlt */
#define	BISTCODECCFAILR_CNT_U08				(1U)	/* bit 0 - BIST Code ECC Failure */
#define LOGLBISTSTRTUPTESTFAILR_CNT_U08		(4U)    /* bit 2 - LBIST Startup Test Failure */
#define BISTNOTCMPL_CNT_U08					(16U)   /* bit 4 - BIST Not Complete */
#define CPULOCKSTEPSTRTUPTESTFAILR_CNT_U08	(32U)   /* bit 5 - CPU Lock Step Error Forcing Startup Test Failure */
#define DMALOCKSTEPSTRTUPTESTFAILR_CNT_U08	(64U)	/* bit 6 - DMA Lock Step Error Forcing Startup Test Failure */
#define FACIRSTTRFERR_CNT_U08				(128U)	/* bit 7 - FACI Reset Transfer Error  */

/* NTCNR_0X022 RtFlt */ 
#define LOCKSTEPCOMP_CNT_U08 				(1U)	/* bit 0 - CPU Core Mis-compare */
#define SYSVCIE_CNT_U08 					(2U)	/* bit 1 - System VCIE Error */ 
#define RESDOPER_CNT_U08					(4U)    /* bit 2 - Reserved Instruction Exception */
#define ALGNREAD_CNT_U08					(8U)    /* bit 3 - Misalignment Exception - Read */
#define ALGNWR_CNT_U08						(16U)	/* bit 4 - Misalignment Exception - Write */
#define INSTRFETCH_CNT_U08					(32U)	/* bit 5 - Double Bit ECC Error on Instruction Fetch  */
#define INTCNCTRESDAREA_CNT_U08				(64U)	/* bit 6 - Interconnect reserved area access fault  */
#define INVLDMEMACS_CNT_U08					(128U)	/* bit 7 - Invalid memory access fault  */

/* NTCNR_0X023 ClkMonrRtFlt 0 & 2 */ 
#define CLKMONR0RTLOWRLIMFLT_CNT_U08 		(4U)	/* bit 2 - Lower limit Clock Monitor 0 Fault */
#define CLKMONR0RTUPPRLIMFLT_CNT_U08 		(8U)	/* bit 3 - Upper limit Clock Monitor 0 Fault */
#define CLKMONR2RTLOWRLIMFLT_CNT_U08 		(64U)	/* bit 6 - Lower limit Clock Monitor 2 Fault */
#define CLKMONR2RTUPPRLIMFLT_CNT_U08 		(128U)	/* bit 7 - Upper limit Clock Monitor 2 Fault */ 

/* NTCNR_0X024 Mode Error */ 
#define OPERMODERRFLSPROGMMODSTRTD_CNT_U08 	(1U)	/* bit 0 - Flash programming mode is started in single-chip mode */
#define OPERMODERRTESTMODSTRTD_CNT_U08 		(2U)	/* bit 1 - Test mode is started in single-chip mode */
#define OPERMODERRSNGCHIPINACTV_CNT_U08 	(4U)	/* bit 2 - Single-chip mode is inactive in single-chip mode */

/* NTCNR_0X027 ClkMonrRtFlt 1 & 3 */ 
#define CLKMONR1RTLOWRLIMFLT_CNT_U08 		(4U)	/* bit 2 - Lower limit Clock Monitor 1 Fault */
#define CLKMONR1RTUPPRLIMFLT_CNT_U08 		(8U)	/* bit 3 - Upper limit Clock Monitor 1 Fault */
#define CLKMONR3RTLOWRLIMFLT_CNT_U08 		(64U)	/* bit 6 - Lower limit Clock Monitor 3 Fault */
#define CLKMONR3RTUPPRLIMFLT_CNT_U08 		(128U)	/* bit 7 - Upper limit Clock Monitor 3 Fault */ 

/* NTCNR_0X025 MemProtnFlt */  
#define	DATAANDINSTRPROTNERR_CNT_U08		(1U)	/* bit 0 -MPU Violation (this covers MDP and MIP Exception) */
#define PRVLGDINSTREXCPN_CNT_U08 			(2U)	/* bit 1 - Privilege Instruction Execution */

/* NTCNR_0X026 EcmMstChkrFlt */ 
#define ECMSTSFLT_CNT_U08			    	(1U)	/* bit 0 - ECM Status Bit Set Prior to ECM Init */
#define EIINTRPTSTRTUPFLT_CNT_U08			(2U)	/* bit 1 - EI Interrupt Start Up Fault */
#define ECMMSTSTRTUPTESTFAILR_CNT_U08		(4U)    /* bit 2 - ECM Startup Master nERROR Output Control Fault */
#define ECMCHKRSTRTUPTESTFAILR_CNT_U08		(8U)    /* bit 3 - ECM Startup Checker nERROR Output Control Fault */
#define ECMPSDOERRINJFLT_CNT_U08			(16U)	/* bit 4 - Pseudo Error Injection Fault */
#define ECMRTMSTCHKRCOMPFLT_CNT_U08			(128U)  /* bit 7 - ECM Runtime Master-Checker Compare Fault */

/* NTCNR_0X028 FpuFlt */ 
#define FPUINVLDOPEREXCPN_CNT_U08 			(2U)	/* bit 1 - FPU Invalid Operation (V Bit) */
#define FPUDIVBYZEROEXCPN_CNT_U08			(4U)    /* bit 2 - FPU Divide by Zero (Z Bit) */
#define FPUOVFEXCPN_CNT_U08					(8U)    /* bit 3 - FPU Overflow (O Bit) */
#define FPUUKWNEXCPN_CNT_U08				(16U)	/* bit 4 - FPU Unknown Error */

/* NTCNR_0X029 UkwnStrtUpDetdFlt */
#define	UKWNRST_CNT_U08						(1U)	/* bit 0 - Unknown Reset Reason */
#define UKWNECMRST_CNT_U08 					(2U)	/* bit 1 - Unknown ECM Reset */
#define BACKUPRAMTSTFAILRINBTLDR_CNT_U08	(8U)	/* bit 3 - Failed Backup RAM0 Read Write Test in bootloader*/
#define UKWNSWRST_CNT_U08					(16U)	/* bit 4 - Unknown Software Reset */
#define BACKUPRAMTSTFAILR_CNT_U08			(32U)	/* bit 5 - Failed Backup RAM Read Write Test */
#define FLSBTLDRPREOSSRTUPEXCPN_CNT_U08		(64U)   /* bit 6 - FBL Pre-OS Startup Exception */
#define STRTUPRSTINFOFAILD_CNT_U08			(128U)	/* bit 7 - Corrupt Start up / Reset Information */

/* NTCNR_0X02A ProgSeqFlt */
#define	PROGFLOW_CNT_U08					(1U)	/* bit 0 - Program Flow */
#define DEADLINEMONR_CNT_U08 				(2U)	/* bit 1 - Deadline Monitor */
#define ALVMONR_CNT_U08						(4U)    /* bit 2 - Alive Monitor */

/* NTCNR_0X02C WdgFlt */
#define	WDGTOUT_CNT_U08						(1U)	/* bit 0 - Watchdog Timeout */

/* NTCNR_0X02D PrphlGuardFlt */
#define PEGRTFLT_CNT_U08 					(2U)	/* bit 1 - PEG RunTime Fault */
#define IPGRTFLT_CNT_U08					(8U)    /* bit 3 - IPG RunTime Fault */
#define PBGSTRTUPTSTAILR_CNT_U08			(16U)	/* bit 4 - PBG (Peripheral Guard) Startup Test Failure */
#define PBGRTFLT_CNT_U08					(32U)	/* bit 5 - PBG Runtime Fault */

/* NTCNR_0X02F Debug Reset */
#define DBGRST_CNT_U08 						(1U)	/* bit 0 - Debug Reset */

/* NTCNR_0X030 OsPrmntGenericFlt */
#define	OSCRITFLT_CNT_U08					(1U)	/* bit 0 - General OS fatal error */ 
#define UKWNEXCPN_CNT_U08 					(2U)	/* bit 1 - Unhandled Exception */  

/* NTCNR_0X031 OsTmpGenericFlt */
#define	OSNONCRITFLT_CNT_U08				(1U)	/* bit 0 - General OS non-fatal (temporary) error */ 

/* NTCNR_0X036 DmaFlt */
#define	DMATRFERR_CNT_U08					(1U)	/* bit 0 - DMA Transfer Error */
#define DMAREGACSPROTCNERR_CNT_U08 			(2U)	/* bit 1 - DMA Register Access Protection Violation */

/* NTCNR_0X037 PrphlBusDataParFlt */
#define	PRPHLBUSDATAPARSTRTUPFLT_CNT_U08	(64U)	/* bit 6 - P-Bus Data Parity Fault Startup Test Failuret */
#define	PRPHLBUSDATAPARPRTFLT_CNT_U08		(128U)	/* bit 7 - P-Bus Data Parity Fault Runtime Fault */

/* NTCNR_0X049 McuVltgMonrFlt */ 
#define	INTCVMOVERVLTGMONR_CNT_U08					(1U)	/* bit 0 - Internal CVM Over Voltage Monitor Fault */
#define	INTCVMUNDERVLTGMONR_CNT_U08					(2U)	/* bit 1 - Internal CVM Under Voltage Monitor Fault */
#define	INTMONRLOVCCFLT_CNT_U08						(16U)	/* bit 4 - Internal Monitor Low Vcc Detected Fault */ 
#define	EXTVLTGMONRFLT_CNT_U08						(128U)	/* bit 7 - External Voltage Monitor Fault */

/* Miscellaneous constants */
#define UPPR16BITMASK_CNT_U32				((uint32)(0xFFFF0000U))
#define LOWR16BITMASK_CNT_U32				((uint32)(0x0000FFFFU))
#define NROFBRAMDATREGS_CNT_U08             ((uint8)4U)
#define SIZEOFBRAMDATREGS_CNT_U08           ((uint8)4U)

/* Typecasting the array pointer/address to the proper array type */
#define  PimRteMcuDiagcData           ( *(Ary1D_u32_4   *) (Rte_Pim_McuDiagcData()) )

#define GlobalShared_START_SEC_VAR_CLEARED_16
#include "MemMap.h"
VAR (uint16, CDD_ExcpnHndlg_VAR) ExcpnHndlgOsErrCod_C; /* ExcpnHndlg component level variable for OS Error Code */
#define GlobalShared_STOP_SEC_VAR_CLEARED_16
#include "MemMap.h"

static FUNC(void, CDD_ExcpnHndlg_CODE) ProcStrtUpOrSwRst(void);
static FUNC(void, CDD_ExcpnHndlg_CODE) ProcPinRst(void);
static INLINE FUNC(boolean, CDD_ExcpnHndlg_CODE)  McuDiagcRstChk(McuDiagc1 RstInfo_Cnt_T_enum);
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
 * Boolean: Boolean
 * boolean: Boolean (standard type)
 * uint16: Integer in interval [0...65535] (standard type)
 * uint32: Integer in interval [0...4294967295] (standard type)
 * uint8: Integer in interval [0...255] (standard type)
 *
 * Enumeration Types:
 * ==================
 * NtcNr1: Enumeration of integer in interval [0...65535] with enumerators
 *   NTCNR_0X001 (1U)
 *   NTCNR_0X002 (2U)
 *   NTCNR_0X003 (3U)
 *   NTCNR_0X004 (4U)
 *   NTCNR_0X005 (5U)
 *   NTCNR_0X006 (6U)
 *   NTCNR_0X007 (7U)
 *   NTCNR_0X008 (8U)
 *   NTCNR_0X009 (9U)
 *   NTCNR_0X00A (10U)
 *   NTCNR_0X00B (11U)
 *   NTCNR_0X00C (12U)
 *   NTCNR_0X00D (13U)
 *   NTCNR_0X00E (14U)
 *   NTCNR_0X00F (15U)
 *   NTCNR_0X010 (16U)
 *   NTCNR_0X011 (17U)
 *   NTCNR_0X012 (18U)
 *   NTCNR_0X013 (19U)
 *   NTCNR_0X014 (20U)
 *   NTCNR_0X015 (21U)
 *   NTCNR_0X016 (22U)
 *   NTCNR_0X017 (23U)
 *   NTCNR_0X018 (24U)
 *   NTCNR_0X019 (25U)
 *   NTCNR_0X01A (26U)
 *   NTCNR_0X01B (27U)
 *   NTCNR_0X01C (28U)
 *   NTCNR_0X01D (29U)
 *   NTCNR_0X01E (30U)
 *   NTCNR_0X01F (31U)
 *   NTCNR_0X020 (32U)
 *   NTCNR_0X021 (33U)
 *   NTCNR_0X022 (34U)
 *   NTCNR_0X023 (35U)
 *   NTCNR_0X024 (36U)
 *   NTCNR_0X025 (37U)
 *   NTCNR_0X026 (38U)
 *   NTCNR_0X027 (39U)
 *   NTCNR_0X028 (40U)
 *   NTCNR_0X029 (41U)
 *   NTCNR_0X02A (42U)
 *   NTCNR_0X02B (43U)
 *   NTCNR_0X02C (44U)
 *   NTCNR_0X02D (45U)
 *   NTCNR_0X02E (46U)
 *   NTCNR_0X02F (47U)
 *   NTCNR_0X030 (48U)
 *   NTCNR_0X031 (49U)
 *   NTCNR_0X032 (50U)
 *   NTCNR_0X033 (51U)
 *   NTCNR_0X034 (52U)
 *   NTCNR_0X035 (53U)
 *   NTCNR_0X036 (54U)
 *   NTCNR_0X037 (55U)
 *   NTCNR_0X038 (56U)
 *   NTCNR_0X039 (57U)
 *   NTCNR_0X03A (58U)
 *   NTCNR_0X03B (59U)
 *   NTCNR_0X03C (60U)
 *   NTCNR_0X03D (61U)
 *   NTCNR_0X03E (62U)
 *   NTCNR_0X03F (63U)
 *   NTCNR_0X040 (64U)
 *   NTCNR_0X041 (65U)
 *   NTCNR_0X042 (66U)
 *   NTCNR_0X043 (67U)
 *   NTCNR_0X044 (68U)
 *   NTCNR_0X045 (69U)
 *   NTCNR_0X046 (70U)
 *   NTCNR_0X047 (71U)
 *   NTCNR_0X048 (72U)
 *   NTCNR_0X049 (73U)
 *   NTCNR_0X04A (74U)
 *   NTCNR_0X04B (75U)
 *   NTCNR_0X04C (76U)
 *   NTCNR_0X04D (77U)
 *   NTCNR_0X04E (78U)
 *   NTCNR_0X04F (79U)
 *   NTCNR_0X050 (80U)
 *   NTCNR_0X051 (81U)
 *   NTCNR_0X052 (82U)
 *   NTCNR_0X053 (83U)
 *   NTCNR_0X054 (84U)
 *   NTCNR_0X055 (85U)
 *   NTCNR_0X056 (86U)
 *   NTCNR_0X057 (87U)
 *   NTCNR_0X058 (88U)
 *   NTCNR_0X059 (89U)
 *   NTCNR_0X05A (90U)
 *   NTCNR_0X05B (91U)
 *   NTCNR_0X05C (92U)
 *   NTCNR_0X05D (93U)
 *   NTCNR_0X05E (94U)
 *   NTCNR_0X05F (95U)
 *   NTCNR_0X060 (96U)
 *   NTCNR_0X061 (97U)
 *   NTCNR_0X062 (98U)
 *   NTCNR_0X063 (99U)
 *   NTCNR_0X064 (100U)
 *   NTCNR_0X065 (101U)
 *   NTCNR_0X066 (102U)
 *   NTCNR_0X067 (103U)
 *   NTCNR_0X068 (104U)
 *   NTCNR_0X069 (105U)
 *   NTCNR_0X06A (106U)
 *   NTCNR_0X06B (107U)
 *   NTCNR_0X06C (108U)
 *   NTCNR_0X06D (109U)
 *   NTCNR_0X06E (110U)
 *   NTCNR_0X06F (111U)
 *   NTCNR_0X070 (112U)
 *   NTCNR_0X071 (113U)
 *   NTCNR_0X072 (114U)
 *   NTCNR_0X073 (115U)
 *   NTCNR_0X074 (116U)
 *   NTCNR_0X075 (117U)
 *   NTCNR_0X076 (118U)
 *   NTCNR_0X077 (119U)
 *   NTCNR_0X078 (120U)
 *   NTCNR_0X079 (121U)
 *   NTCNR_0X07A (122U)
 *   NTCNR_0X07B (123U)
 *   NTCNR_0X07C (124U)
 *   NTCNR_0X07D (125U)
 *   NTCNR_0X07E (126U)
 *   NTCNR_0X07F (127U)
 *   NTCNR_0X080 (128U)
 *   NTCNR_0X081 (129U)
 *   NTCNR_0X082 (130U)
 *   NTCNR_0X083 (131U)
 *   NTCNR_0X084 (132U)
 *   NTCNR_0X085 (133U)
 *   NTCNR_0X086 (134U)
 *   NTCNR_0X087 (135U)
 *   NTCNR_0X088 (136U)
 *   NTCNR_0X089 (137U)
 *   NTCNR_0X08A (138U)
 *   NTCNR_0X08B (139U)
 *   NTCNR_0X08C (140U)
 *   NTCNR_0X08D (141U)
 *   NTCNR_0X08E (142U)
 *   NTCNR_0X08F (143U)
 *   NTCNR_0X090 (144U)
 *   NTCNR_0X091 (145U)
 *   NTCNR_0X092 (146U)
 *   NTCNR_0X093 (147U)
 *   NTCNR_0X094 (148U)
 *   NTCNR_0X095 (149U)
 *   NTCNR_0X096 (150U)
 *   NTCNR_0X097 (151U)
 *   NTCNR_0X098 (152U)
 *   NTCNR_0X099 (153U)
 *   NTCNR_0X09A (154U)
 *   NTCNR_0X09B (155U)
 *   NTCNR_0X09C (156U)
 *   NTCNR_0X09D (157U)
 *   NTCNR_0X09E (158U)
 *   NTCNR_0X09F (159U)
 *   NTCNR_0X0A0 (160U)
 *   NTCNR_0X0A1 (161U)
 *   NTCNR_0X0A2 (162U)
 *   NTCNR_0X0A3 (163U)
 *   NTCNR_0X0A4 (164U)
 *   NTCNR_0X0A5 (165U)
 *   NTCNR_0X0A6 (166U)
 *   NTCNR_0X0A7 (167U)
 *   NTCNR_0X0A8 (168U)
 *   NTCNR_0X0A9 (169U)
 *   NTCNR_0X0AA (170U)
 *   NTCNR_0X0AB (171U)
 *   NTCNR_0X0AC (172U)
 *   NTCNR_0X0AD (173U)
 *   NTCNR_0X0AE (174U)
 *   NTCNR_0X0AF (175U)
 *   NTCNR_0X0B0 (176U)
 *   NTCNR_0X0B1 (177U)
 *   NTCNR_0X0B2 (178U)
 *   NTCNR_0X0B3 (179U)
 *   NTCNR_0X0B4 (180U)
 *   NTCNR_0X0B5 (181U)
 *   NTCNR_0X0B6 (182U)
 *   NTCNR_0X0B7 (183U)
 *   NTCNR_0X0B8 (184U)
 *   NTCNR_0X0B9 (185U)
 *   NTCNR_0X0BA (186U)
 *   NTCNR_0X0BB (187U)
 *   NTCNR_0X0BC (188U)
 *   NTCNR_0X0BD (189U)
 *   NTCNR_0X0BE (190U)
 *   NTCNR_0X0BF (191U)
 *   NTCNR_0X0C0 (192U)
 *   NTCNR_0X0C1 (193U)
 *   NTCNR_0X0C2 (194U)
 *   NTCNR_0X0C3 (195U)
 *   NTCNR_0X0C4 (196U)
 *   NTCNR_0X0C5 (197U)
 *   NTCNR_0X0C6 (198U)
 *   NTCNR_0X0C7 (199U)
 *   NTCNR_0X0C8 (200U)
 *   NTCNR_0X0C9 (201U)
 *   NTCNR_0X0CA (202U)
 *   NTCNR_0X0CB (203U)
 *   NTCNR_0X0CC (204U)
 *   NTCNR_0X0CD (205U)
 *   NTCNR_0X0CE (206U)
 *   NTCNR_0X0CF (207U)
 *   NTCNR_0X0D0 (208U)
 *   NTCNR_0X0D1 (209U)
 *   NTCNR_0X0D2 (210U)
 *   NTCNR_0X0D3 (211U)
 *   NTCNR_0X0D4 (212U)
 *   NTCNR_0X0D5 (213U)
 *   NTCNR_0X0D6 (214U)
 *   NTCNR_0X0D7 (215U)
 *   NTCNR_0X0D8 (216U)
 *   NTCNR_0X0D9 (217U)
 *   NTCNR_0X0DA (218U)
 *   NTCNR_0X0DB (219U)
 *   NTCNR_0X0DC (220U)
 *   NTCNR_0X0DD (221U)
 *   NTCNR_0X0DE (222U)
 *   NTCNR_0X0DF (223U)
 *   NTCNR_0X0E0 (224U)
 *   NTCNR_0X0E1 (225U)
 *   NTCNR_0X0E2 (226U)
 *   NTCNR_0X0E3 (227U)
 *   NTCNR_0X0E4 (228U)
 *   NTCNR_0X0E5 (229U)
 *   NTCNR_0X0E6 (230U)
 *   NTCNR_0X0E7 (231U)
 *   NTCNR_0X0E8 (232U)
 *   NTCNR_0X0E9 (233U)
 *   NTCNR_0X0EA (234U)
 *   NTCNR_0X0EB (235U)
 *   NTCNR_0X0EC (236U)
 *   NTCNR_0X0ED (237U)
 *   NTCNR_0X0EE (238U)
 *   NTCNR_0X0EF (239U)
 *   NTCNR_0X0F0 (240U)
 *   NTCNR_0X0F1 (241U)
 *   NTCNR_0X0F2 (242U)
 *   NTCNR_0X0F3 (243U)
 *   NTCNR_0X0F4 (244U)
 *   NTCNR_0X0F5 (245U)
 *   NTCNR_0X0F6 (246U)
 *   NTCNR_0X0F7 (247U)
 *   NTCNR_0X0F8 (248U)
 *   NTCNR_0X0F9 (249U)
 *   NTCNR_0X0FA (250U)
 *   NTCNR_0X0FB (251U)
 *   NTCNR_0X0FC (252U)
 *   NTCNR_0X0FD (253U)
 *   NTCNR_0X0FE (254U)
 *   NTCNR_0X0FF (255U)
 *   NTCNR_0X100 (256U)
 *   NTCNR_0X101 (257U)
 *   NTCNR_0X102 (258U)
 *   NTCNR_0X103 (259U)
 *   NTCNR_0X104 (260U)
 *   NTCNR_0X105 (261U)
 *   NTCNR_0X106 (262U)
 *   NTCNR_0X107 (263U)
 *   NTCNR_0X108 (264U)
 *   NTCNR_0X109 (265U)
 *   NTCNR_0X10A (266U)
 *   NTCNR_0X10B (267U)
 *   NTCNR_0X10C (268U)
 *   NTCNR_0X10D (269U)
 *   NTCNR_0X10E (270U)
 *   NTCNR_0X10F (271U)
 *   NTCNR_0X110 (272U)
 *   NTCNR_0X111 (273U)
 *   NTCNR_0X112 (274U)
 *   NTCNR_0X113 (275U)
 *   NTCNR_0X114 (276U)
 *   NTCNR_0X115 (277U)
 *   NTCNR_0X116 (278U)
 *   NTCNR_0X117 (279U)
 *   NTCNR_0X118 (280U)
 *   NTCNR_0X119 (281U)
 *   NTCNR_0X11A (282U)
 *   NTCNR_0X11B (283U)
 *   NTCNR_0X11C (284U)
 *   NTCNR_0X11D (285U)
 *   NTCNR_0X11E (286U)
 *   NTCNR_0X11F (287U)
 *   NTCNR_0X120 (288U)
 *   NTCNR_0X121 (289U)
 *   NTCNR_0X122 (290U)
 *   NTCNR_0X123 (291U)
 *   NTCNR_0X124 (292U)
 *   NTCNR_0X125 (293U)
 *   NTCNR_0X126 (294U)
 *   NTCNR_0X127 (295U)
 *   NTCNR_0X128 (296U)
 *   NTCNR_0X129 (297U)
 *   NTCNR_0X12A (298U)
 *   NTCNR_0X12B (299U)
 *   NTCNR_0X12C (300U)
 *   NTCNR_0X12D (301U)
 *   NTCNR_0X12E (302U)
 *   NTCNR_0X12F (303U)
 *   NTCNR_0X130 (304U)
 *   NTCNR_0X131 (305U)
 *   NTCNR_0X132 (306U)
 *   NTCNR_0X133 (307U)
 *   NTCNR_0X134 (308U)
 *   NTCNR_0X135 (309U)
 *   NTCNR_0X136 (310U)
 *   NTCNR_0X137 (311U)
 *   NTCNR_0X138 (312U)
 *   NTCNR_0X139 (313U)
 *   NTCNR_0X13A (314U)
 *   NTCNR_0X13B (315U)
 *   NTCNR_0X13C (316U)
 *   NTCNR_0X13D (317U)
 *   NTCNR_0X13E (318U)
 *   NTCNR_0X13F (319U)
 *   NTCNR_0X140 (320U)
 *   NTCNR_0X141 (321U)
 *   NTCNR_0X142 (322U)
 *   NTCNR_0X143 (323U)
 *   NTCNR_0X144 (324U)
 *   NTCNR_0X145 (325U)
 *   NTCNR_0X146 (326U)
 *   NTCNR_0X147 (327U)
 *   NTCNR_0X148 (328U)
 *   NTCNR_0X149 (329U)
 *   NTCNR_0X14A (330U)
 *   NTCNR_0X14B (331U)
 *   NTCNR_0X14C (332U)
 *   NTCNR_0X14D (333U)
 *   NTCNR_0X14E (334U)
 *   NTCNR_0X14F (335U)
 *   NTCNR_0X150 (336U)
 *   NTCNR_0X151 (337U)
 *   NTCNR_0X152 (338U)
 *   NTCNR_0X153 (339U)
 *   NTCNR_0X154 (340U)
 *   NTCNR_0X155 (341U)
 *   NTCNR_0X156 (342U)
 *   NTCNR_0X157 (343U)
 *   NTCNR_0X158 (344U)
 *   NTCNR_0X159 (345U)
 *   NTCNR_0X15A (346U)
 *   NTCNR_0X15B (347U)
 *   NTCNR_0X15C (348U)
 *   NTCNR_0X15D (349U)
 *   NTCNR_0X15E (350U)
 *   NTCNR_0X15F (351U)
 *   NTCNR_0X160 (352U)
 *   NTCNR_0X161 (353U)
 *   NTCNR_0X162 (354U)
 *   NTCNR_0X163 (355U)
 *   NTCNR_0X164 (356U)
 *   NTCNR_0X165 (357U)
 *   NTCNR_0X166 (358U)
 *   NTCNR_0X167 (359U)
 *   NTCNR_0X168 (360U)
 *   NTCNR_0X169 (361U)
 *   NTCNR_0X16A (362U)
 *   NTCNR_0X16B (363U)
 *   NTCNR_0X16C (364U)
 *   NTCNR_0X16D (365U)
 *   NTCNR_0X16E (366U)
 *   NTCNR_0X16F (367U)
 *   NTCNR_0X170 (368U)
 *   NTCNR_0X171 (369U)
 *   NTCNR_0X172 (370U)
 *   NTCNR_0X173 (371U)
 *   NTCNR_0X174 (372U)
 *   NTCNR_0X175 (373U)
 *   NTCNR_0X176 (374U)
 *   NTCNR_0X177 (375U)
 *   NTCNR_0X178 (376U)
 *   NTCNR_0X179 (377U)
 *   NTCNR_0X17A (378U)
 *   NTCNR_0X17B (379U)
 *   NTCNR_0X17C (380U)
 *   NTCNR_0X17D (381U)
 *   NTCNR_0X17E (382U)
 *   NTCNR_0X17F (383U)
 *   NTCNR_0X180 (384U)
 *   NTCNR_0X181 (385U)
 *   NTCNR_0X182 (386U)
 *   NTCNR_0X183 (387U)
 *   NTCNR_0X184 (388U)
 *   NTCNR_0X185 (389U)
 *   NTCNR_0X186 (390U)
 *   NTCNR_0X187 (391U)
 *   NTCNR_0X188 (392U)
 *   NTCNR_0X189 (393U)
 *   NTCNR_0X18A (394U)
 *   NTCNR_0X18B (395U)
 *   NTCNR_0X18C (396U)
 *   NTCNR_0X18D (397U)
 *   NTCNR_0X18E (398U)
 *   NTCNR_0X18F (399U)
 *   NTCNR_0X190 (400U)
 *   NTCNR_0X191 (401U)
 *   NTCNR_0X192 (402U)
 *   NTCNR_0X193 (403U)
 *   NTCNR_0X194 (404U)
 *   NTCNR_0X195 (405U)
 *   NTCNR_0X196 (406U)
 *   NTCNR_0X197 (407U)
 *   NTCNR_0X198 (408U)
 *   NTCNR_0X199 (409U)
 *   NTCNR_0X19A (410U)
 *   NTCNR_0X19B (411U)
 *   NTCNR_0X19C (412U)
 *   NTCNR_0X19D (413U)
 *   NTCNR_0X19E (414U)
 *   NTCNR_0X19F (415U)
 *   NTCNR_0X1A0 (416U)
 *   NTCNR_0X1A1 (417U)
 *   NTCNR_0X1A2 (418U)
 *   NTCNR_0X1A3 (419U)
 *   NTCNR_0X1A4 (420U)
 *   NTCNR_0X1A5 (421U)
 *   NTCNR_0X1A6 (422U)
 *   NTCNR_0X1A7 (423U)
 *   NTCNR_0X1A8 (424U)
 *   NTCNR_0X1A9 (425U)
 *   NTCNR_0X1AA (426U)
 *   NTCNR_0X1AB (427U)
 *   NTCNR_0X1AC (428U)
 *   NTCNR_0X1AD (429U)
 *   NTCNR_0X1AE (430U)
 *   NTCNR_0X1AF (431U)
 *   NTCNR_0X1B0 (432U)
 *   NTCNR_0X1B1 (433U)
 *   NTCNR_0X1B2 (434U)
 *   NTCNR_0X1B3 (435U)
 *   NTCNR_0X1B4 (436U)
 *   NTCNR_0X1B5 (437U)
 *   NTCNR_0X1B6 (438U)
 *   NTCNR_0X1B7 (439U)
 *   NTCNR_0X1B8 (440U)
 *   NTCNR_0X1B9 (441U)
 *   NTCNR_0X1BA (442U)
 *   NTCNR_0X1BB (443U)
 *   NTCNR_0X1BC (444U)
 *   NTCNR_0X1BD (445U)
 *   NTCNR_0X1BE (446U)
 *   NTCNR_0X1BF (447U)
 *   NTCNR_0X1C0 (448U)
 *   NTCNR_0X1C1 (449U)
 *   NTCNR_0X1C2 (450U)
 *   NTCNR_0X1C3 (451U)
 *   NTCNR_0X1C4 (452U)
 *   NTCNR_0X1C5 (453U)
 *   NTCNR_0X1C6 (454U)
 *   NTCNR_0X1C7 (455U)
 *   NTCNR_0X1C8 (456U)
 *   NTCNR_0X1C9 (457U)
 *   NTCNR_0X1CA (458U)
 *   NTCNR_0X1CB (459U)
 *   NTCNR_0X1CC (460U)
 *   NTCNR_0X1CD (461U)
 *   NTCNR_0X1CE (462U)
 *   NTCNR_0X1CF (463U)
 *   NTCNR_0X1D0 (464U)
 *   NTCNR_0X1D1 (465U)
 *   NTCNR_0X1D2 (466U)
 *   NTCNR_0X1D3 (467U)
 *   NTCNR_0X1D4 (468U)
 *   NTCNR_0X1D5 (469U)
 *   NTCNR_0X1D6 (470U)
 *   NTCNR_0X1D7 (471U)
 *   NTCNR_0X1D8 (472U)
 *   NTCNR_0X1D9 (473U)
 *   NTCNR_0X1DA (474U)
 *   NTCNR_0X1DB (475U)
 *   NTCNR_0X1DC (476U)
 *   NTCNR_0X1DD (477U)
 *   NTCNR_0X1DE (478U)
 *   NTCNR_0X1DF (479U)
 *   NTCNR_0X1E0 (480U)
 *   NTCNR_0X1E1 (481U)
 *   NTCNR_0X1E2 (482U)
 *   NTCNR_0X1E3 (483U)
 *   NTCNR_0X1E4 (484U)
 *   NTCNR_0X1E5 (485U)
 *   NTCNR_0X1E6 (486U)
 *   NTCNR_0X1E7 (487U)
 *   NTCNR_0X1E8 (488U)
 *   NTCNR_0X1E9 (489U)
 *   NTCNR_0X1EA (490U)
 *   NTCNR_0X1EB (491U)
 *   NTCNR_0X1EC (492U)
 *   NTCNR_0X1ED (493U)
 *   NTCNR_0X1EE (494U)
 *   NTCNR_0X1EF (495U)
 *   NTCNR_0X1F0 (496U)
 *   NTCNR_0X1F1 (497U)
 *   NTCNR_0X1F2 (498U)
 *   NTCNR_0X1F3 (499U)
 *   NTCNR_0X1F4 (500U)
 *   NTCNR_0X1F5 (501U)
 *   NTCNR_0X1F6 (502U)
 *   NTCNR_0X1F7 (503U)
 *   NTCNR_0X1F8 (504U)
 *   NTCNR_0X1F9 (505U)
 *   NTCNR_0X1FA (506U)
 *   NTCNR_0X1FB (507U)
 *   NTCNR_0X1FC (508U)
 *   NTCNR_0X1FD (509U)
 *   NTCNR_0X1FE (510U)
 *   NTCNR_0X1FF (511U)
 * NtcSts1: Enumeration of integer in interval [0...255] with enumerators
 *   NTCSTS_PASSD (0U)
 *   NTCSTS_FAILD (1U)
 *   NTCSTS_PREPASSD (2U)
 *   NTCSTS_PREFAILD (3U)
 *
 * Array Types:
 * ============
 * Ary1D_u32_4: Array with 4 element(s) of type uint32
 *
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *
 * APIs which are accessible from all runnable entities of the SW-C
 *
 **********************************************************************************************************************
 * Per-Instance Memory:
 * ====================
 *   uint32 *Rte_Pim_McuDiagcData(void)
 *     Returnvalue: uint32* is of type Ary1D_u32_4
 *
 * Calibration Parameters:
 * =======================
 *   SW-C local Calibration Parameters:
 *   ----------------------------------
 *   uint32 *Rte_CData_McuDiagcDataDft(void)
 *     Returnvalue: uint32* is of type Ary1D_u32_4
 *
 *********************************************************************************************************************/


#define CDD_ExcpnHndlg_START_SEC_CODE
#include "CDD_ExcpnHndlg_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/**********************************************************************************************************************
 *
 * Runnable Entity Name: ChkForStrtUpTest_Oper
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Oper> of PortPrototype <ChkForStrtUpTest>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   void ChkForStrtUpTest_Oper(boolean *ExecStrtUpTest_Arg)
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: ChkForStrtUpTest_Oper_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, CDD_ExcpnHndlg_CODE) ChkForStrtUpTest_Oper(P2VAR(boolean, AUTOMATIC, RTE_CDD_EXCPNHNDLG_APPL_VAR) ExecStrtUpTest_Arg) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: ChkForStrtUpTest_Oper
 *********************************************************************************************************************/
 	VAR(McuDiagc1, AUTOMATIC) RstInfo_Cnt_T_enum;
	/* copy register values to temporary variables to avoid MISRA rule 12.2 and/or 12.4 warnings */
	RstInfo_Cnt_T_enum = (McuDiagc1)BRAMDAT0;  

	*ExecStrtUpTest_Arg = McuDiagcRstChk(RstInfo_Cnt_T_enum);
	

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: ExcpnHndlgInit2
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed once after the RTE is started
 *
 **********************************************************************************************************************
 *
 * Client/Server Interfaces:
 * =========================
 *   Server Invocation:
 *   ------------------
 *   Std_ReturnType Rte_Call_SetNtcSts_Oper(NtcNr1 NtcNr_Arg, uint8 NtcStInfo_Arg, NtcSts1 NtcSts_Arg, uint16 DebStep_Arg)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_SetNtcSts_PortIf1_E_NOT_OK
 *
 * Service Calls:
 * ==============
 *   Service Invocation:
 *   -------------------
 *   Std_ReturnType Rte_Call_McuDiagcData_SetRamBlockStatus(Boolean RamBlockStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NvMService_AC3_SRBS_Defs_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: ExcpnHndlgInit2_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, CDD_ExcpnHndlg_CODE) ExcpnHndlgInit2(void) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: ExcpnHndlgInit2
 *********************************************************************************************************************/

 /*** This function implements subfunction "Reset Source Determination" of the CM101A Exception Handling RH850 FDD ***/

	VAR(McuDiagc1, AUTOMATIC) RstInfo_Cnt_T_enum;
	VAR(uint32, AUTOMATIC) SysDbgMod_Cnt_T_u32;
	VAR(uint32, AUTOMATIC) SysDbgModB_Cnt_T_u32;
	VAR(uint32, AUTOMATIC) BackUpRam1_Cnt_T_u32;
	VAR(uint32, AUTOMATIC) BackUpRam2_Cnt_T_u32;
	VAR(uint32, AUTOMATIC) BackUpRam3_Cnt_T_u32;
	VAR(uint8, AUTOMATIC) LoopCntr_Cnt_T_u08;
	VAR(uint32, AUTOMATIC) AddrOfBackUpRam_Cnt_T_u32;
    
	/* copy register values to temporary variables to avoid MISRA rule 12.2 and/or 12.4 warnings */
	RstInfo_Cnt_T_enum = (McuDiagc1)BRAMDAT0;  
	SysDbgMod_Cnt_T_u32 = SYSDEBUGMODE;
	SysDbgModB_Cnt_T_u32 = SYSDEBUGMODEB;
	
	/* Pass all NTCs controlled by this component */
	(void)Rte_Call_SetNtcSts_Oper(NTCNR_0X003, 0U, NTCSTS_PASSD, 0U);
	(void)Rte_Call_SetNtcSts_Oper(NTCNR_0X010, 0U, NTCSTS_PASSD, 0U);
	(void)Rte_Call_SetNtcSts_Oper(NTCNR_0X013, 0U, NTCSTS_PASSD, 0U);
	(void)Rte_Call_SetNtcSts_Oper(NTCNR_0X016, 0U, NTCSTS_PASSD, 0U);
	(void)Rte_Call_SetNtcSts_Oper(NTCNR_0X021, 0U, NTCSTS_PASSD, 0U);
	(void)Rte_Call_SetNtcSts_Oper(NTCNR_0X022, 0U, NTCSTS_PASSD, 0U);
	(void)Rte_Call_SetNtcSts_Oper(NTCNR_0X023, 0U, NTCSTS_PASSD, 0U);
	(void)Rte_Call_SetNtcSts_Oper(NTCNR_0X024, 0U, NTCSTS_PASSD, 0U);
	(void)Rte_Call_SetNtcSts_Oper(NTCNR_0X025, 0U, NTCSTS_PASSD, 0U);
	(void)Rte_Call_SetNtcSts_Oper(NTCNR_0X026, 0U, NTCSTS_PASSD, 0U);
	(void)Rte_Call_SetNtcSts_Oper(NTCNR_0X027, 0U, NTCSTS_PASSD, 0U);
	(void)Rte_Call_SetNtcSts_Oper(NTCNR_0X028, 0U, NTCSTS_PASSD, 0U);
	(void)Rte_Call_SetNtcSts_Oper(NTCNR_0X029, 0U, NTCSTS_PASSD, 0U);
	(void)Rte_Call_SetNtcSts_Oper(NTCNR_0X02A, 0U, NTCSTS_PASSD, 0U);
	(void)Rte_Call_SetNtcSts_Oper(NTCNR_0X02C, 0U, NTCSTS_PASSD, 0U);
	(void)Rte_Call_SetNtcSts_Oper(NTCNR_0X02D, 0U, NTCSTS_PASSD, 0U);
	(void)Rte_Call_SetNtcSts_Oper(NTCNR_0X030, 0U, NTCSTS_PASSD, 0U);
	(void)Rte_Call_SetNtcSts_Oper(NTCNR_0X031, 0U, NTCSTS_PASSD, 0U);
	(void)Rte_Call_SetNtcSts_Oper(NTCNR_0X036, 0U, NTCSTS_PASSD, 0U);
	(void)Rte_Call_SetNtcSts_Oper(NTCNR_0X037, 0U, NTCSTS_PASSD, 0U);
	(void)Rte_Call_SetNtcSts_Oper(NTCNR_0X049, 0U, NTCSTS_PASSD, 0U);
	
    if((RstInfo_Cnt_T_enum != MCUDIAGC_FLSPROGMREQ) 
    && (RstInfo_Cnt_T_enum != MCUDIAGC_PWRONRST)
    && (RstInfo_Cnt_T_enum != MCUDIAGC_DBGRST)
    && (RstInfo_Cnt_T_enum != MCUDIAGC_FLSPROGMCMPL)
    && (RstInfo_Cnt_T_enum != MCUDIAGC_HARDRST)
    && (RstInfo_Cnt_T_enum != MCUDIAGC_SOFTRST)
    && (RstInfo_Cnt_T_enum != MCUDIAGC_QUICKIGNRST)
    && (RstInfo_Cnt_T_enum != MCUDIAGC_CUSTRST))
    {
        /*Update  NvM Data */
        LoopCntr_Cnt_T_u08 = NROFBRAMDATREGS_CNT_U08;
        AddrOfBackUpRam_Cnt_T_u32 = (uint32)&BRAMDAT0;
        while(LoopCntr_Cnt_T_u08 > 0U)
        {
            LoopCntr_Cnt_T_u08--;
            PimRteMcuDiagcData[LoopCntr_Cnt_T_u08] = * (uint32*)(AddrOfBackUpRam_Cnt_T_u32 + (uint32)(uint8)(LoopCntr_Cnt_T_u08*SIZEOFBRAMDATREGS_CNT_U08));
        }
        /* Write to NvM */
        (void)Rte_Call_McuDiagcData_SetRamBlockStatus(TRUE);
    }

	/*Check if the Debugger is attached*/
	if ((SysDbgMod_Cnt_T_u32 == 1U) || (SysDbgModB_Cnt_T_u32 == 0U)) 
	{
		(void)Rte_Call_SetNtcSts_Oper(NTCNR_0X02F, 1U, NTCSTS_FAILD, 0U);
	}
	else
	{
		(void)Rte_Call_SetNtcSts_Oper(NTCNR_0X02F, 0U, NTCSTS_PASSD, 0U);
	}
	
	/* Confirm state of reset info in backup RAM is valid - upper 16 bits should be ones complement of lower 16 bits */
	if ((((RstInfo_Cnt_T_enum & UPPR16BITMASK_CNT_U32) >> 16) ^ (RstInfo_Cnt_T_enum & LOWR16BITMASK_CNT_U32)) != LOWR16BITMASK_CNT_U32)
	{
		BackUpRam1_Cnt_T_u32 = BRAMDAT1;
		BackUpRam2_Cnt_T_u32 = BRAMDAT2;
		BackUpRam3_Cnt_T_u32 = BRAMDAT3;
		if((BackUpRam1_Cnt_T_u32 == MCUDIAGC_BACKUPRAMTSTFAILR) || (BackUpRam2_Cnt_T_u32 == MCUDIAGC_BACKUPRAMTSTFAILR) || (BackUpRam3_Cnt_T_u32 == MCUDIAGC_BACKUPRAMTSTFAILR))
		{
			/* Set fault BackUp RAM Test Failure in Bootloader */
			(void)Rte_Call_SetNtcSts_Oper(NTCNR_0X029, BACKUPRAMTSTFAILRINBTLDR_CNT_U08, NTCSTS_FAILD, 0U);
		}
		else
		{
			/* set fault -- BRAMDAT0 is corrupt */
			(void)Rte_Call_SetNtcSts_Oper(NTCNR_0X029, STRTUPRSTINFOFAILD_CNT_U08, NTCSTS_FAILD, 0U);
		}
	}
    else if (RstInfo_Cnt_T_enum == MCUDIAGC_QUICKIGNRST)
    {
		/* No checks needed in Quick Ignition reset */        
    }
    else if (RstInfo_Cnt_T_enum == MCUDIAGC_CUSTRST)
    {
		/* No checks needed in Custom reset */        
    }
	else if (McuDiagcRstChk(RstInfo_Cnt_T_enum) == TRUE)
	{
		/* No checks needed - normal power on start up or flash programming event */
	}
	else if (RstInfo_Cnt_T_enum == MCUDIAGC_DBGRST) 
	{
		/* No checks needed in debug mode */
	}
	else if (RstInfo_Cnt_T_enum == MCUDIAGC_LOCKSTEPECMRST)
	{
		/* Check for lock step fault in either core */
		(void)Rte_Call_SetNtcSts_Oper(NTCNR_0X022, LOCKSTEPCOMP_CNT_U08, NTCSTS_FAILD, 0U); 
	}
	else if(RstInfo_Cnt_T_enum == MCUDIAGC_ECMRST)
	{
        /* Check for any other ECM Reset */
		(void)Rte_Call_SetNtcSts_Oper(NTCNR_0X029, UKWNECMRST_CNT_U08, NTCSTS_FAILD, 0U); 
	}
	else if (RstInfo_Cnt_T_enum == MCUDIAGC_PINRST)
	{
		/* Reset from External Pin (Power Supply) */
		ProcPinRst(); 
	}
	else if (RstInfo_Cnt_T_enum == MCUDIAGC_COREVLTGMONRHI)
	{
		/* Overvoltage internal to uC */
		(void)Rte_Call_SetNtcSts_Oper(NTCNR_0X049, INTCVMOVERVLTGMONR_CNT_U08, NTCSTS_FAILD, 0U);	
	}
	else if (RstInfo_Cnt_T_enum == MCUDIAGC_COREVLTGMONRLO)
	{
		/* Low voltage internal to uC */
		(void)Rte_Call_SetNtcSts_Oper(NTCNR_0X049, INTCVMUNDERVLTGMONR_CNT_U08, NTCSTS_FAILD, 0U);	
	}
	else
	{
		/* process startup non-reset faults and software resets */
		ProcStrtUpOrSwRst();  
	}
		


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: ExcpnHndlgPer1
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered on TimingEvent every 2ms
 *
 **********************************************************************************************************************
 *
 * Client/Server Interfaces:
 * =========================
 *   Server Invocation:
 *   ------------------
 *   Std_ReturnType Rte_Call_SetNtcSts_Oper(NtcNr1 NtcNr_Arg, uint8 NtcStInfo_Arg, NtcSts1 NtcSts_Arg, uint16 DebStep_Arg)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_SetNtcSts_PortIf1_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: ExcpnHndlgPer1_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, CDD_ExcpnHndlg_CODE) ExcpnHndlgPer1(void) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: ExcpnHndlgPer1
 *********************************************************************************************************************/
	if (ExcpnHndlgOsErrCod_C != 0x0000U)
	{
		(void)Rte_Call_SetNtcSts_Oper (NTCNR_0X031, OSNONCRITFLT_CNT_U08, NTCSTS_FAILD, 0U);
	}
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: GetMcuDiagcSpplData_Oper
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Oper> of PortPrototype <GetMcuDiagcSpplData>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   void GetMcuDiagcSpplData_Oper(uint32 *McuDiagcData1_Arg)
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: GetMcuDiagcSpplData_Oper_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, CDD_ExcpnHndlg_CODE) GetMcuDiagcSpplData_Oper(P2VAR(uint32, AUTOMATIC, RTE_CDD_EXCPNHNDLG_APPL_VAR) McuDiagcData1_Arg) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: GetMcuDiagcSpplData_Oper
 *********************************************************************************************************************/

	*McuDiagcData1_Arg = BRAMDAT1;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}


#define CDD_ExcpnHndlg_STOP_SEC_CODE
#include "CDD_ExcpnHndlg_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of function definition area >>            DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
#define CDD_ExcpnHndlg_START_SEC_CODE 
#include "CDD_ExcpnHndlg_MemMap.h"

/*****************************************************************************************************************
 * Name        :   ProcStrtUpOrSwRst
 * Description :   Processes a startup non-reset diagnostic failure or a swoftware reset
 * Inputs      :   BRAMDAT0 - global input containing the reset reason/startup failure information
 * Outputs     :   None
 * Usage Notes :   Sets NTCs based on information in BRAMDAT0
 ****************************************************************************************************************/
static FUNC(void, CDD_ExcpnHndlg_CODE) ProcStrtUpOrSwRst(void)
{
	VAR(McuDiagc1, AUTOMATIC) RstInfo_Cnt_T_enum; 
	
	RstInfo_Cnt_T_enum = (McuDiagc1)BRAMDAT0;
	switch (RstInfo_Cnt_T_enum)
	{
		/* cases for pre-OS failures, non-reset */
		case MCUDIAGC_MEMBISTERR:
			(void)Rte_Call_SetNtcSts_Oper(NTCNR_0X010, MEMBISTSTRTUPTESTFAILR_CNT_U08, NTCSTS_FAILD, 0U);
		break;
		
		case MCUDIAGC_BISTECCERR:
			(void)Rte_Call_SetNtcSts_Oper(NTCNR_0X021, BISTCODECCFAILR_CNT_U08, NTCSTS_FAILD, 0U);
		break;
		
		case MCUDIAGC_LOGLBISTERR:
			(void)Rte_Call_SetNtcSts_Oper(NTCNR_0X021, LOGLBISTSTRTUPTESTFAILR_CNT_U08, NTCSTS_FAILD, 0U);
		break;
		
		case MCUDIAGC_BISTNOTCMPLERR:
			(void)Rte_Call_SetNtcSts_Oper(NTCNR_0X021, BISTNOTCMPL_CNT_U08, NTCSTS_FAILD, 0U);
		break;
		
		case MCUDIAGC_CPULOCKSTEPERR:
			(void)Rte_Call_SetNtcSts_Oper(NTCNR_0X021, CPULOCKSTEPSTRTUPTESTFAILR_CNT_U08, NTCSTS_FAILD, 0U);
		break;
		
		case MCUDIAGC_DMALOCKSTEPERR:
			(void)Rte_Call_SetNtcSts_Oper(NTCNR_0X021, DMALOCKSTEPSTRTUPTESTFAILR_CNT_U08, NTCSTS_FAILD, 0U);
		break;
		
		case MCUDIAGC_FACIRSTTRFERR:
			(void)Rte_Call_SetNtcSts_Oper(NTCNR_0X021, FACIRSTTRFERR_CNT_U08, NTCSTS_FAILD, 0U);
		break;
        
		case MCUDIAGC_CODFLASHEXECENAREGFAILR:
			(void)Rte_Call_SetNtcSts_Oper(NTCNR_0X003, CODFLASHEXECENAREGFAILR_CNT_U08, NTCSTS_FAILD, 0U);
		break;		
		
		case MCUDIAGC_ECMSTSSTRTUPFLT:
			(void)Rte_Call_SetNtcSts_Oper(NTCNR_0X026, ECMSTSFLT_CNT_U08, NTCSTS_FAILD, 0U);
		break;
		
		case MCUDIAGC_MSTERROUTPCTRLFLT:
			(void)Rte_Call_SetNtcSts_Oper(NTCNR_0X026, ECMMSTSTRTUPTESTFAILR_CNT_U08, NTCSTS_FAILD, 0U);
		break;
		
		case MCUDIAGC_CHKRERROUTPCTRLFLT:
			(void)Rte_Call_SetNtcSts_Oper(NTCNR_0X026, ECMCHKRSTRTUPTESTFAILR_CNT_U08, NTCSTS_FAILD, 0U);
		break;
		
		case MCUDIAGC_EIINTRPTSTRTUPFLT:
			(void)Rte_Call_SetNtcSts_Oper(NTCNR_0X026, EIINTRPTSTRTUPFLT_CNT_U08, NTCSTS_FAILD, 0U); /* EI Interrupt Start Up Fault */
		break;
		
		case MCUDIAGC_ECMPSDOERRINJFLT:
			(void)Rte_Call_SetNtcSts_Oper(NTCNR_0X026, ECMPSDOERRINJFLT_CNT_U08, NTCSTS_FAILD, 0U); /* Pseudo Error Injection Fault */
		break;
		
		case MCUDIAGC_BACKUPRAMTSTFAILR:
			(void)Rte_Call_SetNtcSts_Oper(NTCNR_0X029, BACKUPRAMTSTFAILR_CNT_U08, NTCSTS_FAILD, 0U);
		break;
		
		case MCUDIAGC_PREOSEXCPN:
			(void)Rte_Call_SetNtcSts_Oper(NTCNR_0X029, FLSBTLDRPREOSSRTUPEXCPN_CNT_U08, NTCSTS_FAILD, 0U);
		break;

		case MCUDIAGC_PBGSTRTUPTST:
			(void)Rte_Call_SetNtcSts_Oper(NTCNR_0X02D, PBGSTRTUPTSTAILR_CNT_U08, NTCSTS_FAILD, 0U); 
		break;
		
		case MCUDIAGC_PRPHLBUSDATAPARSTRTUPFLT:
			(void)Rte_Call_SetNtcSts_Oper(NTCNR_0X037, PRPHLBUSDATAPARSTRTUPFLT_CNT_U08, NTCSTS_FAILD, 0U) ;
		break;
			
		case MCUDIAGC_RSTUKWN:
			(void)Rte_Call_SetNtcSts_Oper(NTCNR_0X029, UKWNRST_CNT_U08, NTCSTS_FAILD, 0U); 
		break;
		
		case MCUDIAGC_CODFLSSNGBITHARDFLT:
			(void)Rte_Call_SetNtcSts_Oper(NTCNR_0X003, CODFLSSNGBITHARDFLT_CNT_U08, NTCSTS_FAILD, 0U);
		break;
		
		case MCUDIAGC_CODFLSDBLBIT:
			(void)Rte_Call_SetNtcSts_Oper(NTCNR_0X003, CODFLSECCDBLBIT_CNT_U08, NTCSTS_FAILD, 0U);
		break;
		
		case MCUDIAGC_ADRPAR:
			(void)Rte_Call_SetNtcSts_Oper(NTCNR_0X003, CODFLSADRPAR_CNT_U08, NTCSTS_FAILD, 0U);
		break;
		
		case MCUDIAGC_PRPHLBUSDATAPAR:
			(void)Rte_Call_SetNtcSts_Oper(NTCNR_0X037, PRPHLBUSDATAPARPRTFLT_CNT_U08, NTCSTS_FAILD, 0U);
		break;
		
		case MCUDIAGC_LCLRAMECCSNGBITHARDFAILR:
			(void)Rte_Call_SetNtcSts_Oper(NTCNR_0X013, LCLRAMECCSNGBITHARDFLT_CNT_U08, NTCSTS_FAILD, 0U); 
		break;
		
		case MCUDIAGC_LCLRAMDBLBIT:
			(void)Rte_Call_SetNtcSts_Oper(NTCNR_0X013, LCLRAMECCDBLBIT_CNT_U08, NTCSTS_FAILD, 0U); 
		break;

		case MCUDIAGC_INVLDRAMAREA:
			(void)Rte_Call_SetNtcSts_Oper(NTCNR_0X013, INVLDRAMAREA_CNT_U08, NTCSTS_FAILD, 0U);
		break;
        
		case MCUDIAGC_DTSECCSNGBITERR:
			(void)Rte_Call_SetNtcSts_Oper(NTCNR_0X016, DTSSNGBITFLT_CNT_U08, NTCSTS_FAILD, 0U); 
		break;

		case MCUDIAGC_DTSDBLBIT:
			(void)Rte_Call_SetNtcSts_Oper(NTCNR_0X016, DTSDBLBIT_CNT_U08, NTCSTS_FAILD, 0U); 
		break;
		
		case MCUDIAGC_SPIRAMDBLBIT0:
			(void)Rte_Call_SetNtcSts_Oper(NTCNR_0X017, SPI0PRPHLRAMDBLBIT_CNT_U08, NTCSTS_FAILD, 0U);
		break;
		
		case MCUDIAGC_SPIRAMDBLBIT1:
			(void)Rte_Call_SetNtcSts_Oper(NTCNR_0X018, SPI1PRPHLRAMDBLBIT_CNT_U08, NTCSTS_FAILD, 0U);
		break;
		
		case MCUDIAGC_SPIRAMDBLBIT2:
			(void)Rte_Call_SetNtcSts_Oper(NTCNR_0X019, SPI2PRPHLRAMDBLBIT_CNT_U08, NTCSTS_FAILD, 0U);
		break;
		
		case MCUDIAGC_SPIRAMDBLBIT3:
			(void)Rte_Call_SetNtcSts_Oper(NTCNR_0X01A, SPI3PRPHLRAMDBLBIT_CNT_U08, NTCSTS_FAILD, 0U);
		break;
		
		case MCUDIAGC_VCIE:
			(void)Rte_Call_SetNtcSts_Oper(NTCNR_0X022, SYSVCIE_CNT_U08, NTCSTS_FAILD, 0U);
		break;
		
		case MCUDIAGC_RESDOPER:
			(void)Rte_Call_SetNtcSts_Oper(NTCNR_0X022, RESDOPER_CNT_U08, NTCSTS_FAILD, 0U);
		break;
		
		case MCUDIAGC_ALGNREAD:
			(void)Rte_Call_SetNtcSts_Oper(NTCNR_0X022, ALGNREAD_CNT_U08, NTCSTS_FAILD, 0U);
		break;
		
		case MCUDIAGC_ALGNWR:
			(void)Rte_Call_SetNtcSts_Oper(NTCNR_0X022, ALGNWR_CNT_U08, NTCSTS_FAILD, 0U);
		break;
		
		case MCUDIAGC_INSTRFETCH:
			(void)Rte_Call_SetNtcSts_Oper(NTCNR_0X022, INSTRFETCH_CNT_U08, NTCSTS_FAILD, 0U);
		break;
		
		case MCUDIAGC_INTCNCTRESDAREA:
			(void)Rte_Call_SetNtcSts_Oper(NTCNR_0X022, INTCNCTRESDAREA_CNT_U08, NTCSTS_FAILD, 0U);
		break;
		
		case MCUDIAGC_INVLDMEMACS:
			(void)Rte_Call_SetNtcSts_Oper(NTCNR_0X022, INVLDMEMACS_CNT_U08, NTCSTS_FAILD, 0U);
		break;
		
		case MCUDIAGC_OPERMODERRFLSPROGMMODSTRTD:
			(void)Rte_Call_SetNtcSts_Oper(NTCNR_0X024, OPERMODERRFLSPROGMMODSTRTD_CNT_U08, NTCSTS_FAILD, 0U);
		break;
		
		case MCUDIAGC_OPERMODERRTESTMODSTRTD: 
			(void)Rte_Call_SetNtcSts_Oper(NTCNR_0X024, OPERMODERRTESTMODSTRTD_CNT_U08, NTCSTS_FAILD, 0U);
		break;
		
		case MCUDIAGC_OPERMODERRSNGCHIPINACTV: 
			(void)Rte_Call_SetNtcSts_Oper(NTCNR_0X024, OPERMODERRSNGCHIPINACTV_CNT_U08, NTCSTS_FAILD, 0U);
		break;
		
		case MCUDIAGC_MPU:
			(void)Rte_Call_SetNtcSts_Oper(NTCNR_0X025, DATAANDINSTRPROTNERR_CNT_U08, NTCSTS_FAILD, 0U);
		break;
		
		case MCUDIAGC_PRVLGDINSTREXCPN:
			(void)Rte_Call_SetNtcSts_Oper(NTCNR_0X025, PRVLGDINSTREXCPN_CNT_U08, NTCSTS_FAILD, 0U);
		break;
		
		case MCUDIAGC_ECMMSTCHKRERR:
			(void)Rte_Call_SetNtcSts_Oper(NTCNR_0X026, ECMRTMSTCHKRCOMPFLT_CNT_U08, NTCSTS_FAILD, 0U);
		break;
		
		case MCUDIAGC_FPUERRINVLDOPER:
			(void)Rte_Call_SetNtcSts_Oper(NTCNR_0X028, FPUINVLDOPEREXCPN_CNT_U08, NTCSTS_FAILD, 0U);
		break;
		
		case MCUDIAGC_FPUERRDIVBYZERO:
			(void)Rte_Call_SetNtcSts_Oper(NTCNR_0X028, FPUDIVBYZEROEXCPN_CNT_U08, NTCSTS_FAILD, 0U);
		break;
		
		case MCUDIAGC_FPUERROVF:
			(void)Rte_Call_SetNtcSts_Oper(NTCNR_0X028, FPUOVFEXCPN_CNT_U08, NTCSTS_FAILD, 0U);
		break;
		
		case MCUDIAGC_FPUERRUKWN:
			(void)Rte_Call_SetNtcSts_Oper(NTCNR_0X028, FPUUKWNEXCPN_CNT_U08, NTCSTS_FAILD, 0U);
		break;
		
		case MCUDIAGC_FENMIPROGFLOW:
			(void)Rte_Call_SetNtcSts_Oper(NTCNR_0X02A, PROGFLOW_CNT_U08, NTCSTS_FAILD, 0U);
		break;
		
		case MCUDIAGC_FENMIDEADLINEMONR:
			(void)Rte_Call_SetNtcSts_Oper(NTCNR_0X02A, DEADLINEMONR_CNT_U08, NTCSTS_FAILD, 0U);
		break;
		
		case MCUDIAGC_FENMIALVMONR:
			(void)Rte_Call_SetNtcSts_Oper(NTCNR_0X02A, ALVMONR_CNT_U08, NTCSTS_FAILD, 0U);
		break;
		
		case MCUDIAGC_FENMIWDG:
			(void)Rte_Call_SetNtcSts_Oper(NTCNR_0X02C, WDGTOUT_CNT_U08, NTCSTS_FAILD, 0U);
		break;
		
		case MCUDIAGC_CLKMONR0RTLOWRLIMFLT:
			(void)Rte_Call_SetNtcSts_Oper(NTCNR_0X023, CLKMONR0RTLOWRLIMFLT_CNT_U08, NTCSTS_FAILD, 0U);
		break;

       	case MCUDIAGC_CLKMONR0RTUPPRLIMFLT:
			(void)Rte_Call_SetNtcSts_Oper(NTCNR_0X023, CLKMONR0RTUPPRLIMFLT_CNT_U08, NTCSTS_FAILD, 0U);
		break;

        case MCUDIAGC_CLKMONR1RTLOWRLIMFLT:
			(void)Rte_Call_SetNtcSts_Oper(NTCNR_0X027, CLKMONR1RTLOWRLIMFLT_CNT_U08, NTCSTS_FAILD, 0U);
		break;

        case MCUDIAGC_CLKMONR1RTUPPRLIMFLT:
			(void)Rte_Call_SetNtcSts_Oper(NTCNR_0X027, CLKMONR1RTUPPRLIMFLT_CNT_U08, NTCSTS_FAILD, 0U);
		break;

        case MCUDIAGC_CLKMONR2RTLOWRLIMFLT:
			(void)Rte_Call_SetNtcSts_Oper(NTCNR_0X023, CLKMONR2RTLOWRLIMFLT_CNT_U08, NTCSTS_FAILD, 0U);
		break;

        case MCUDIAGC_CLKMONR2RTUPPRLIMFLT:
			(void)Rte_Call_SetNtcSts_Oper(NTCNR_0X023, CLKMONR2RTUPPRLIMFLT_CNT_U08, NTCSTS_FAILD, 0U);
		break;

        case MCUDIAGC_CLKMONR3RTLOWRLIMFLT:
			(void)Rte_Call_SetNtcSts_Oper(NTCNR_0X027, CLKMONR3RTLOWRLIMFLT_CNT_U08, NTCSTS_FAILD, 0U);
		break;

        case MCUDIAGC_CLKMONR3RTUPPRLIMFLT:
			(void)Rte_Call_SetNtcSts_Oper(NTCNR_0X027, CLKMONR3RTUPPRLIMFLT_CNT_U08, NTCSTS_FAILD, 0U);
		break;

		case MCUDIAGC_PROCRELMGUARD:
			(void)Rte_Call_SetNtcSts_Oper(NTCNR_0X02D, PEGRTFLT_CNT_U08, NTCSTS_FAILD, 0U);
		break;
		
		case MCUDIAGC_INTPRPHLGUARD:
			(void)Rte_Call_SetNtcSts_Oper(NTCNR_0X02D, IPGRTFLT_CNT_U08, NTCSTS_FAILD, 0U);
		break;
		
		case MCUDIAGC_PRPHLBUSGUARD:
			(void)Rte_Call_SetNtcSts_Oper(NTCNR_0X02D, PBGRTFLT_CNT_U08, NTCSTS_FAILD, 0U);
		break;
		
		case MCUDIAGC_PRMNTOSERR:
			(void)Rte_Call_SetNtcSts_Oper(NTCNR_0X030, OSCRITFLT_CNT_U08, NTCSTS_FAILD, 0U);
		break;
		
		case MCUDIAGC_UKWNEXCPN:
			(void)Rte_Call_SetNtcSts_Oper(NTCNR_0X030, UKWNEXCPN_CNT_U08, NTCSTS_FAILD, 0U);
		break;
		
		case MCUDIAGC_DMATRFERR:
			(void)Rte_Call_SetNtcSts_Oper(NTCNR_0X036, DMATRFERR_CNT_U08, NTCSTS_FAILD, 0U); 
		break;
		
		case MCUDIAGC_DMAREGACSPROTCNERR:
			(void)Rte_Call_SetNtcSts_Oper(NTCNR_0X036, DMAREGACSPROTCNERR_CNT_U08, NTCSTS_FAILD, 0U); 
		break;
				default:
			(void)Rte_Call_SetNtcSts_Oper(NTCNR_0X029, UKWNSWRST_CNT_U08, NTCSTS_FAILD, 0U); 
		break;
	}
}

/*****************************************************************************************************************
 * Name        :   ProcPinRst
 * Description :   Processes a reset initiated by the external reset pin
 * Inputs      :   None
 * Outputs     :   None
 * Usage Notes :   Sets NTC to indicate pin reset
 ****************************************************************************************************************/
static FUNC(void, CDD_ExcpnHndlg_CODE) ProcPinRst(void)
{
	(void)Rte_Call_SetNtcSts_Oper(NTCNR_0X049, EXTVLTGMONRFLT_CNT_U08, NTCSTS_FAILD, 0U); 
}


/*****************************************************************************************************************
 * Name        :   McuDiagcRstChk
 * Description :   Checks and returns boolean based on Mcu Diagnostic Reset
 * Inputs      :   RstInfo_Cnt_T_enum
 * Outputs     :   McuDiagcRstChk_Cnt_T_lgc
 * Usage Notes :   None
 ****************************************************************************************************************/
static INLINE FUNC(boolean, CDD_ExcpnHndlg_CODE)  McuDiagcRstChk(McuDiagc1 RstInfo_Cnt_T_enum)
{
	
	VAR(boolean, AUTOMATIC) McuDiagcRstChk_Cnt_T_lgc;
	
	if((RstInfo_Cnt_T_enum == MCUDIAGC_PWRONRST) || (RstInfo_Cnt_T_enum == MCUDIAGC_FLSPROGMCMPL)  || (RstInfo_Cnt_T_enum == MCUDIAGC_HARDRST)
			|| (RstInfo_Cnt_T_enum == MCUDIAGC_SOFTRST))
	{
		McuDiagcRstChk_Cnt_T_lgc = TRUE;
	}
	else
	{
		McuDiagcRstChk_Cnt_T_lgc = FALSE;
	}
	return(McuDiagcRstChk_Cnt_T_lgc) ;
}

#define CDD_ExcpnHndlg_STOP_SEC_CODE
#include "CDD_ExcpnHndlg_MemMap.h"

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of function definition area >>              DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of removed code area >>                   DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of removed code area >>                     DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
