/**********************************************************************************************************************
* Copyright 2015,2016,2017,2018 Nxtr 
* Nxtr Confidential
*
* Module File Name  : CDD_GuardCfgAndDiagcNonRte.c 
* Module Description: Non-Rte functions of CM107A Guard Configuration and Diagnostics RH850
* Project           : CBD
* Author            : Kathleen Creager
***********************************************************************************************************************
* Version Control:
* %version:          6 %
* %derived_by:       rzk04c %
*---------------------------------------------------------------------------------------------------------------------
* Date      Rev      Author    Change Description                                                             SCR #
* --------  -------  --------  -----------------------------------------------------------------------------  -------
* 10/19/15   1       KMC       Initial Version                                                                EA4#2030
* 10/22/15   2       KMC       Modify PBG configuration per FDD version 1.1.0                                 EA4#2030
* 03/01/16   3       AJM       Added PBG startup test							                              EA4#2754
* 03/30/16	 4		 AJM	   Added lock protection to PBG registers and syncm useage						  EA4#4976
* 01/12/17	 5		 AJM	   Micro Diag error Injection						                              EA4#8362
* 04/10/18	 6		 AJM	   Made Micro Diag error Injection program independent                            EA4#20999
**********************************************************************************************************************/
#include <v800_ghs.h> /* for SYNCM intrinsic */  
#include "Rte_CDD_GuardCfgAndDiagc.h"
#include "CDD_GuardCfgAndDiagc.h"
#include "CDD_ExcpnHndlg.h"
#include "NxtrMcuSuprtLib.h"
#include "ipg_regs.h"
#include "peg_regs.h"
#include "pbg_regs.h"
#include "port_regs.h"
#include "dnf_regs.h"
#include "adcd_regs.h"
#include "ecm_regs.h"
#include "seg_regs.h"
#include "Os.h"
#include "McuErrInj.h"
#if (MCUDIAGCERRINJ == STD_ON)
#include "sys_regs.h"
#endif

/* MISRA-C:2004 Rule 19.1 [NXTRDEV 19.1.1]: AUTOSAR requires deviation from this rule for Memory Mapping include statements */

/*	bit 31 PROTLOCK enables/disables register lock */
#define PBGPROTNLOCKENA_CNT_U32		0x80000000U /* register is not rewritable */

/* settings common to all PBG protection registers FSGDxxPROTn:
	bits 30:26 reserved, write 0x01	0x04000000U
	bits 24:17 PROTPEID, write 0x02 0x00040000U (enables PEID1 access, disables all other PEIDs)
	bits 16:9 reserved, write 0xFF	0x0001FE00U
	bit 4 PROTDEB, write 1			0x00000010U (enables debugger access)
	bit 3 PROTRDPDEF, write 1  		0x00000008U (enables master passing the filter when PROTRD bit is set)
	bit 2 PROTWRPDEF, write 1  		0x00000004U (enables master passing the filter when PROTWR bit is set)  
	bit 1 PROTRD, write 1  			0x00000002U (enables read access from the master having passed the filter) 
	bit 0 PROTWR, write 1  			0x00000001U (enables write access from the master having passed the filter) */
#define PBGPROTNCMN_CNT_U32			0x0405FE1FU	/* common PBG protection settings */

/* other PBG protection register settings */

/*	bit 25 PROTUM enables/disables user mode access */
#define PBGUSRMODENA_CNT_U32		0x02000000U /* enables user mode access */
#define PBGUSRMODDI_CNT_U32			0x00000000U /* disables user mode access */

/*	bits 8:5 PROTSPID
		bit 8, write 1 to enable SPID3 access
		bit 7, write 1 to enable SPID2 access
		bit 6, write 1 to enable SPID1 access
		bit 5, write 1 to enable SPID0 access */
#define PBGSPID321ENA_CNT_U32		0x000001C0U /* enable SPID3, SPID2, SPID1 */
#define PBGSPID31ENA_CNT_U32		0x00000140U /* enable SPID3, SPID1 */
#define PBGSPID21ENA_CNT_U32		0x000000C0U /* enable SPID2, SPID1 */
#define PBGSPID1ENA_CNT_U32			0x00000040U /* enable SPID1 */

#define PBGSETNOREADWRACS_CNT_U32	0x405FE5CU /* NO Read Write Access to*/

#define NROF8BITREG_CNT_U08			((uint8)0x09)
#define NROF32BITREG_CNT_U08			((uint8)0x02)

#define PBGSTRTUPTESTNOFAILR_CNT_U32	0x0U

#define READERRBIT_CNT_U32  		((uint32)1U<<6U)
#define WRERRBIT_CNT_U32			((uint32)1U<<7U)
#define CFGERRBIT_CNT_U32			((uint32)1U<<8U)
#define PBGERRBIT_CNT_U32			((uint32)1U<<9U)
#define ECMERRBIT_CNT_U32			((uint32)1U<<10U)
#define REGTYPE8BIT_CNT_U32			((uint32)0U<<4U)
#define REGTYPE16BIT_CNT_U32		((uint32)1U<<4U)
#define REGTYPE32BIT_CNT_U32		((uint32)2U<<4U)

#if (MCUDIAGCERRINJ == STD_ON)
#define PBGSETNOREADACS_CNT_U32	0x405FE5DU 		/* NO Read  Access to*/
#define PBGSETNOWRACS_CNT_U32	0x405FE5EU 		/* NO Write Access to*/
#endif

typedef struct 
{
	volatile uint32* PbgProtnRegAdr32BitAcs;
	volatile uint32* PortAcsReg32Bit;
}PbgTest32BitRec1;

typedef struct 
{
	volatile uint32* PbgProtnRegAdr16BitAcs;
	volatile uint16* PortAcsReg16Bit;
}PbgTest16BitRec1;

typedef struct 
{
	volatile uint32* PbgProtnRegAdr8BitAcs;
	volatile uint8* PortAcsReg8Bit;
}PbgTest8BitRec1;
	
static FUNC(void, CDD_GuardCfgAndDiagc_CODE) PegInin(void);
static FUNC(void, CDD_GuardCfgAndDiagc_CODE) PbgInin(void);
static FUNC(void, CDD_GuardCfgAndDiagc_CODE) ConfigureFilterN(volatile P2VAR(uint32,AUTOMATIC,AUTOMATIC)PbgProtReg, uint32 Val,P2VAR(uint32,AUTOMATIC,AUTOMATIC)PbgStrtUpTestFailSts);
static FUNC(void, CDD_GuardCfgAndDiagc_CODE) ChkForECMErr(P2VAR(uint32,AUTOMATIC,AUTOMATIC)PbgStrtUpTestFailSts);
static FUNC(void, CDD_GuardCfgAndDiagc_CODE) ChkForPBGErr(P2VAR(uint32,AUTOMATIC,AUTOMATIC)PbgStrtUpTestFailSts);
static FUNC(void, CDD_GuardCfgAndDiagc_CODE) Vrfy8BitPBGRegAcs(P2VAR(uint32,AUTOMATIC,AUTOMATIC)PbgStrtUpTestFailSts);
static FUNC(void, CDD_GuardCfgAndDiagc_CODE) Vrfy16BitPBGRegAcs(P2VAR(uint32,AUTOMATIC,AUTOMATIC)PbgStrtUpTestFailSts);
static FUNC(void, CDD_GuardCfgAndDiagc_CODE) Vrfy32BitPBGRegAcs(P2VAR(uint32,AUTOMATIC,AUTOMATIC)PbgStrtUpTestFailSts);


#define CDD_GuardCfgAndDiagc_START_SEC_CODE
#include "CDD_GuardCfgAndDiagc_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/******************************************************************************
 * Name:        GuardCfgAndDiagcInit1
 * Description: Guard configuration initialization of PEG, IPG, and PBG
 * Inputs:      None     
 * Outputs:     Configuration registers for PEG, IPG, and PBG  
 * Usage Notes: Non-RTE function so that guard protection can be initialized and enabled before the RTE is started
 ****************************************************************************/
FUNC(void, CDD_GuardCfgAndDiagc_CODE) GuardCfgAndDiagcInit1(void) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{

	PegInin();
	Call_IpgInin(); 
	PbgInin();

}

/******************************************************************************
 * Name:        PegInin
 * Description: Processor Element Guard (PEG) Initialization
 * Inputs:  None         
 * Outputs: PEG configuration registers      
 * Usage Notes: None
 ****************************************************************************/
static FUNC(void, CDD_GuardCfgAndDiagc_CODE) PegInin(void) 
{
	PEGG0MK	= 0x00000000U;					/* Mask value (bits 31:12 of register) = 0 creates a 4Kbyte region */
	PEGG0BA  	= ((uint32)0xFEBFFU << 12)	/* Base value (bits 31:12 of register) = 0xFEBFF; region starts at address 0xFEBFF000 */
				|	((uint32)0x01U << 7)	/* SPID = 3 Access enabled */
				|	((uint32)0x00U << 6)	/* SPID = 2 Access disabled */
				|	((uint32)0x00U << 5)	/* SPID = 1 Access disabled */
				|	((uint32)0x01U << 4)	/* SPID = 0 Access enabled */ 
				|	((uint32)0x01U << 2)	/* Write Access is enabled */
				|	((uint32)0x00U << 1)	/* Read Access is disabled*/
				|	((uint32)0x01U << 0);	/* PE Guard protection area is enabled */
				
	PEGG1MK	= 0x0001F000U;					/* Mask value (bits 31:12 of register) = 0x0001F creates a 128Kbyte region (all of local RAM)*/
	PEGG1BA  	= ((uint32)0xFEBE0U << 12)	/* Base value (bits 31:12 of register) = 0xFEBE0; region starts at address 0xFEBE0000 */
				|	((uint32)0x01U << 7)	/* SPID = 3 Access enabled */  
				|	((uint32)0x01U << 6)	/* SPID = 2 Access enabled */
				|	((uint32)0x00U << 5)	/* SPID = 1 Access disabled */
				|	((uint32)0x01U << 4)	/* SPID = 0 Access enabled */
				|	((uint32)0x00U << 2)	/* Write Access is disabled */
				|	((uint32)0x01U << 1)	/* Read Access is enabled*/
				|	((uint32)0x01U << 0);	/* PE Guard protection area is enabled */

	PEGSP		  = 0x0001U;				/* SPEN : Detection of Accesses by external master having SPID is enabled (PEG Enabled) */
}

/******************************************************************************
 * Name:        PbgInin
 * Description: Peripheral Bus Guard (PBG) Initialization
 * Inputs:  None         
 * Outputs: PBG configuration registers      
 * Usage Notes: None
 ****************************************************************************/
static FUNC(void, CDD_GuardCfgAndDiagc_CODE) PbgInin(void) 
{
	#if (MCUDIAGCERRINJ == STD_ON)
	VAR(uint32, AUTOMATIC) ErrId_Cnt_T_u32;
	ReadErrInjReg_Oper(&ErrId_Cnt_T_u32);
	#endif
	
	/* PBG0A Channel 0 - INTC2 */
	PBGFSGD0ADPROT0 = PBGPROTNCMN_CNT_U32	/* common PBG protection settings */
				|	PBGUSRMODDI_CNT_U32	    /* disable user mode access */
				|	PBGSPID1ENA_CNT_U32;	/* enable SPID1 */
	#if (MCUDIAGCERRINJ == STD_OFF)
	/* PBG0A Channel 1 - DMA_DTS */
	PBGFSGD0ADPROT1 = PBGPROTNCMN_CNT_U32	/* common PBG protection settings */
				|	PBGUSRMODENA_CNT_U32	/* enable user mode access */
				|	PBGSPID1ENA_CNT_U32;	/* enable SPID1 */
	#elif (MCUDIAGCERRINJ == STD_ON)
	if(ErrId_Cnt_T_u32 == MCUERRINJ_NTC002DBIT05CASE01_CNT_U32)
	{
		ClrErrInjReg_Oper();
		PBGFSGD0ADPROT1 = PBGSETNOWRACS_CNT_U32	/* No Write access */
					|	PBGUSRMODENA_CNT_U32	/* enable user mode access */
					|	PBGSPID1ENA_CNT_U32;	/* enable SPID1 */
        /* After a Sync instruction write to a register protected by the respective guards*/
        __SYNCM();
        DMASSDTRTSCTL = 0x40000000U;
	}
	else
	{
		PBGFSGD0ADPROT1 = PBGPROTNCMN_CNT_U32	/* common PBG protection settings */
					|	PBGUSRMODENA_CNT_U32	/* enable user mode access */
					|	PBGSPID1ENA_CNT_U32;	/* enable SPID1 */
	}
	#endif

	/* PBG1A Channel 0 - TAPA0 */
	PBGFSGD1ADPROT0 = PBGPROTNCMN_CNT_U32	/* common PBG protection settings */
				|	PBGUSRMODENA_CNT_U32	/* enable user mode access */
				|	PBGSPID1ENA_CNT_U32		/* enable SPID1 */
				|	PBGPROTNLOCKENA_CNT_U32; /* lock the register */
	
	/* PBG1A Channel 1 - TAPA1 */
	PBGFSGD1ADPROT1 = PBGPROTNCMN_CNT_U32	/* common PBG protection settings */
				|	PBGUSRMODENA_CNT_U32	/* enable user mode access */
				|	PBGSPID1ENA_CNT_U32		/* enable SPID1 */
				|	PBGPROTNLOCKENA_CNT_U32; /* lock the register */
	
	/* PBG1A Channel 2 - TAPA2 */
	PBGFSGD1ADPROT2 = PBGPROTNCMN_CNT_U32	/* common PBG protection settings */
				|	PBGUSRMODENA_CNT_U32	/* enable user mode access */
				|	PBGSPID1ENA_CNT_U32		/* enable SPID1 */
				|	PBGPROTNLOCKENA_CNT_U32; /* lock the register */
	
	/* PBG1A Channel 3 - TAPA3 */
	PBGFSGD1ADPROT3 = PBGPROTNCMN_CNT_U32	/* common PBG protection settings */
				|	PBGUSRMODENA_CNT_U32	/* enable user mode access */
				|	PBGSPID1ENA_CNT_U32		/* enable SPID1 */
				|	PBGPROTNLOCKENA_CNT_U32; /* lock the register */
				
	/* PBG1A Channel 4 - PIC2 */
	PBGFSGD1ADPROT4 = PBGPROTNCMN_CNT_U32	/* common PBG protection settings */
				|	PBGUSRMODENA_CNT_U32	/* enable user mode access */
				|	PBGSPID1ENA_CNT_U32		/* enable SPID1 */
				|	PBGPROTNLOCKENA_CNT_U32; /* lock the register */
				
	/* PBG1A Channel 5 - TPBA0 */
	PBGFSGD1ADPROT5 = PBGPROTNCMN_CNT_U32	/* common PBG protection settings */
				|	PBGUSRMODENA_CNT_U32	/* enable user mode access */
				|	PBGSPID1ENA_CNT_U32		/* enable SPID1 */
				|	PBGPROTNLOCKENA_CNT_U32; /* lock the register */
				
	/* PBG1A Channel 6 - TPBA1 */
	PBGFSGD1ADPROT6 = PBGPROTNCMN_CNT_U32	/* common PBG protection settings */
				|	PBGUSRMODENA_CNT_U32	/* enable user mode access */
				|	PBGSPID1ENA_CNT_U32		/* enable SPID1 */
				|	PBGPROTNLOCKENA_CNT_U32; /* lock the register */
				
	/* PBG1A Channel 7 - TSG30 */
	PBGFSGD1ADPROT7 = PBGPROTNCMN_CNT_U32	/* common PBG protection settings */
				|	PBGUSRMODENA_CNT_U32	/* enable user mode access */
				|	PBGSPID1ENA_CNT_U32		/* enable SPID1 */
				|	PBGPROTNLOCKENA_CNT_U32; /* lock the register */
				
	/* PBG1A Channel 8 - TSG31 - Write Operation DMAC03, DMAC04 */ 
	PBGFSGD1ADPROT8 = PBGPROTNCMN_CNT_U32	/* common PBG protection settings */
				|	PBGUSRMODENA_CNT_U32	/* enable user mode access */
				|	PBGSPID21ENA_CNT_U32   	/* enable SPID2 and SPID1 */
				|	PBGPROTNLOCKENA_CNT_U32; /* lock the register */

	#if (MCUDIAGCERRINJ == STD_OFF)
	/* PBG1A Channel 9 - TAUJ0 */
	PBGFSGD1ADPROT9 = PBGPROTNCMN_CNT_U32	/* common PBG protection settings */
				|	PBGUSRMODENA_CNT_U32	/* enable user mode access */
				|	PBGSPID1ENA_CNT_U32		/* enable SPID1 */
				|	PBGPROTNLOCKENA_CNT_U32; /* lock the register */
	#elif (MCUDIAGCERRINJ == STD_ON)
	if (ErrId_Cnt_T_u32 == MCUERRINJ_NTC002DBIT05CASE02_CNT_U32)
	{
		/* Clear BRAMDAT2 Register */
		ClrErrInjReg_Oper();
		/* Disable Write Access for ALL SPIDs */
		PBGFSGD1ADPROT9 = PBGSETNOWRACS_CNT_U32
				|	PBGUSRMODENA_CNT_U32	/* enable user mode access */
				|	PBGSPID1ENA_CNT_U32		/* enable SPID1 */
				|	PBGPROTNLOCKENA_CNT_U32; /* lock the register */
        /* After a Sync instruction write to a register protected by the respective guards*/
        __SYNCM();
        TAUJ0TOE = 0x00U;
	}
	else if (ErrId_Cnt_T_u32 == MCUERRINJ_NTC0022BIT01CASE02_CNT_U32)
	{
		/* Clear BRAMDAT2 Register */
		ClrErrInjReg_Oper();
		/* Disable Read Access for ALL SPIDs */
		PBGFSGD1ADPROT9 = PBGSETNOREADACS_CNT_U32 
				|	PBGUSRMODENA_CNT_U32	/* enable user mode access */
				|	PBGSPID1ENA_CNT_U32		/* enable SPID1 */
				|	PBGPROTNLOCKENA_CNT_U32; /* lock the register */
        /* After a Sync instruction read to a register protected by the respective guards*/
        __SYNCM();
        McuDiagcTestVar1_G = (uint32)TAUJ0CSR0;
	}
	else
	{
		/* Keep Original Setting */
		PBGFSGD1ADPROT9 = PBGPROTNCMN_CNT_U32	/* common PBG protection settings */
				|	PBGUSRMODENA_CNT_U32	/* enable user mode access */
				|	PBGSPID1ENA_CNT_U32		/* enable SPID1 */
				|	PBGPROTNLOCKENA_CNT_U32; /* lock the register */
	}
	#endif
	
	/* PBG1A Channel 10 - TAUJ1 */
	PBGFSGD1ADPROT10 = PBGPROTNCMN_CNT_U32	/* common PBG protection settings */
				|	PBGUSRMODENA_CNT_U32	/* enable user mode access */
				|	PBGSPID1ENA_CNT_U32		/* enable SPID1 */
				|	PBGPROTNLOCKENA_CNT_U32; /* lock the register */
				
	/* PBG1A Channel 11 - TAUJ2 */
	PBGFSGD1ADPROT11 = PBGPROTNCMN_CNT_U32	/* common PBG protection settings */
				|	PBGUSRMODENA_CNT_U32	/* enable user mode access */
				|	PBGSPID1ENA_CNT_U32		/* enable SPID1 */
				|	PBGPROTNLOCKENA_CNT_U32; /* lock the register */
				
	/* PBG1A Channel 12 - TAUD0 */
	PBGFSGD1ADPROT12 = PBGPROTNCMN_CNT_U32	/* common PBG protection settings */
				|	PBGUSRMODENA_CNT_U32	/* enable user mode access */
				|	PBGSPID1ENA_CNT_U32		/* enable SPID1 */
				|	PBGPROTNLOCKENA_CNT_U32; /* lock the register */
				
	/* PBG1A Channel 13 - TAUD1 */
	PBGFSGD1ADPROT13 = PBGPROTNCMN_CNT_U32	/* common PBG protection settings */
				|	PBGUSRMODENA_CNT_U32	/* enable user mode access */
				|	PBGSPID1ENA_CNT_U32		/* enable SPID1 */
				|	PBGPROTNLOCKENA_CNT_U32; /* lock the register */
	
	/* PBG1A Channel 14 - TAUD2 */
	PBGFSGD1ADPROT14 = PBGPROTNCMN_CNT_U32	/* common PBG protection settings */
				|	PBGUSRMODENA_CNT_U32	/* enable user mode access */
				|	PBGSPID1ENA_CNT_U32		/* enable SPID1 */
				|	PBGPROTNLOCKENA_CNT_U32; /* lock the register */
	/* PBG1B Channel 0 - OSTM0 */
	PBGFSGD1BDPROT0 = PBGPROTNCMN_CNT_U32	/* common PBG protection settings */
				|	PBGUSRMODENA_CNT_U32	/* enable user mode access */
				|	PBGSPID1ENA_CNT_U32		/* enable SPID1 */
				|	PBGPROTNLOCKENA_CNT_U32; /* lock the register */

	/* PBG1B Channel 1 - OSTM1 */
	PBGFSGD1BDPROT1 = PBGPROTNCMN_CNT_U32	/* common PBG protection settings */
				|	PBGUSRMODENA_CNT_U32	/* enable user mode access */
				|	PBGSPID1ENA_CNT_U32		/* enable SPID1 */
				|	PBGPROTNLOCKENA_CNT_U32; /* lock the register */

	/* PBG1B Channel 2 - OSTM0_CLKSEL */
	PBGFSGD1BDPROT2 = PBGPROTNCMN_CNT_U32	/* common PBG protection settings */
				|	PBGUSRMODDI_CNT_U32	    /* disable user mode access */
				|	PBGSPID1ENA_CNT_U32		/* enable SPID1 */
				|	PBGPROTNLOCKENA_CNT_U32; /* lock the register */
				
	/* PBG1B Channel 3 - OSTM1_CLKSEL */
	PBGFSGD1BDPROT3 = PBGPROTNCMN_CNT_U32	/* common PBG protection settings */
				|	PBGUSRMODENA_CNT_U32	/* enable user mode access */
				|	PBGSPID1ENA_CNT_U32		/* enable SPID1 */
				|	PBGPROTNLOCKENA_CNT_U32; /* lock the register */
	#if (MCUDIAGCERRINJ == STD_OFF)
	/* PBG1B Channel 4 - ENCA0 */
	PBGFSGD1BDPROT4 = PBGPROTNCMN_CNT_U32	/* common PBG protection settings */
				|	PBGUSRMODENA_CNT_U32	/* enable user mode access */
				|	PBGSPID1ENA_CNT_U32		/* enable SPID1 */
				|	PBGPROTNLOCKENA_CNT_U32; /* lock the register */
    #else
	if (ErrId_Cnt_T_u32 == MCUERRINJ_NTC0022BIT01CASE03_CNT_U32)
	{
		/* Clear BRAMDAT2 Register */
		ClrErrInjReg_Oper();
		/* Disable Read Access for ALL SPIDs */
		PBGFSGD1BDPROT4 = PBGSETNOREADACS_CNT_U32
				|	PBGUSRMODENA_CNT_U32	/* enable user mode access */
				|	PBGSPID1ENA_CNT_U32		/* enable SPID1 */
				|	PBGPROTNLOCKENA_CNT_U32; /* lock the register */
        /* After a Sync instruction read to a register protected by the respective guards*/
        __SYNCM();
        McuDiagcTestVar1_G = (uint32)ENCA0FLG;
	}
	else
	{
		/* Keep Original Setting */
		PBGFSGD1BDPROT4 = PBGPROTNCMN_CNT_U32	/* common PBG protection settings */
				|	PBGUSRMODENA_CNT_U32	/* enable user mode access */
				|	PBGSPID1ENA_CNT_U32		/* enable SPID1 */
				|	PBGPROTNLOCKENA_CNT_U32; /* lock the register */
	}
    #endif

	#if (MCUDIAGCERRINJ == STD_OFF)
	/* PBG1B Channel 5 - ENCA1 */
	PBGFSGD1BDPROT5 = PBGPROTNCMN_CNT_U32	/* common PBG protection settings */
				|	PBGUSRMODENA_CNT_U32	/* enable user mode access */
				|	PBGSPID1ENA_CNT_U32		/* enable SPID1 */
				|	PBGPROTNLOCKENA_CNT_U32; /* lock the register */
	#else
	if (ErrId_Cnt_T_u32 == MCUERRINJ_NTC002DBIT05CASE03_CNT_U32)
	{
		/* Clear BRAMDAT2 Register */
		ClrErrInjReg_Oper();
		/* Disable Write Access for ALL SPIDs */
		PBGFSGD1BDPROT5 = PBGSETNOWRACS_CNT_U32
				|	PBGUSRMODENA_CNT_U32	/* enable user mode access */
				|	PBGSPID1ENA_CNT_U32		/* enable SPID1 */
				|	PBGPROTNLOCKENA_CNT_U32; /* lock the register */
        /* After a Sync instruction write to a register protected by the respective guards*/
        __SYNCM();
        ENCA1FGC = 0x03U;
	}
	else
	{
		/* Keep Original Setting */
		PBGFSGD1BDPROT5 = PBGPROTNCMN_CNT_U32	/* common PBG protection settings */
				|	PBGUSRMODENA_CNT_U32	/* enable user mode access */
				|	PBGSPID1ENA_CNT_U32		/* enable SPID1 */
				|	PBGPROTNLOCKENA_CNT_U32; /* lock the register */
	}
	#endif
    
	/* PBG1B Channel 6 - SENT0 */
	PBGFSGD1BDPROT6 = PBGPROTNCMN_CNT_U32	/* common PBG protection settings */
				|	PBGUSRMODENA_CNT_U32	/* enable user mode access */
				|	PBGSPID1ENA_CNT_U32		/* enable SPID1 */
				|	PBGPROTNLOCKENA_CNT_U32; /* lock the register */
				
	/* PBG1B Channel 7 - SENT1 */
	PBGFSGD1BDPROT7 = PBGPROTNCMN_CNT_U32	/* common PBG protection settings */
				|	PBGUSRMODENA_CNT_U32	/* enable user mode access */
				|	PBGSPID1ENA_CNT_U32		/* enable SPID1 */
				|	PBGPROTNLOCKENA_CNT_U32; /* lock the register */
				
	/* PBG1B Channel 8 - SENT2 */
	PBGFSGD1BDPROT8 = PBGPROTNCMN_CNT_U32	/* common PBG protection settings */
				|	PBGUSRMODENA_CNT_U32	/* enable user mode access */
				|	PBGSPID1ENA_CNT_U32		/* enable SPID1 */
				|	PBGPROTNLOCKENA_CNT_U32; /* lock the register */
				
	/* PBG1B Channel 9 - SENT3 */
	PBGFSGD1BDPROT9 = PBGPROTNCMN_CNT_U32	/* common PBG protection settings */
				|	PBGUSRMODENA_CNT_U32	/* enable user mode access */
				|	PBGSPID1ENA_CNT_U32		/* enable SPID1 */
				|	PBGPROTNLOCKENA_CNT_U32; /* lock the register */
				
	/* PBG1B Channel 10 - SENT4 */
	PBGFSGD1BDPROT10 = PBGPROTNCMN_CNT_U32	/* common PBG protection settings */
				|	PBGUSRMODENA_CNT_U32	/* enable user mode access */
				|	PBGSPID1ENA_CNT_U32		/* enable SPID1 */
				|	PBGPROTNLOCKENA_CNT_U32; /* lock the register */
				
	/* PBG1B Channel 11 - SENT5 */
	PBGFSGD1BDPROT11 = PBGPROTNCMN_CNT_U32	/* common PBG protection settings */
				|	PBGUSRMODENA_CNT_U32	/* enable user mode access */
				|	PBGSPID1ENA_CNT_U32		/* enable SPID1 */
				|	PBGPROTNLOCKENA_CNT_U32; /* lock the register */
				
	/* PBG1B Channel 12 - PSI50 */
	PBGFSGD1BDPROT12 = PBGPROTNCMN_CNT_U32	/* common PBG protection settings */
				|	PBGUSRMODENA_CNT_U32	/* enable user mode access */
				|	PBGSPID1ENA_CNT_U32		/* enable SPID1 */
				|	PBGPROTNLOCKENA_CNT_U32; /* lock the register */
				
	/* PBG1B Channel 13 - PSI51 */
	PBGFSGD1BDPROT13 = PBGPROTNCMN_CNT_U32	/* common PBG protection settings */
				|	PBGUSRMODENA_CNT_U32	/* enable user mode access */
				|	PBGSPID1ENA_CNT_U32		/* enable SPID1 */
				|	PBGPROTNLOCKENA_CNT_U32; /* lock the register */
				
	/* PBG1B Channel 14 - PIC */
	PBGFSGD1BDPROT14 = PBGPROTNCMN_CNT_U32	/* common PBG protection settings */
				|	PBGUSRMODENA_CNT_U32	/* enable user mode access */
				|	PBGSPID1ENA_CNT_U32		/* enable SPID1 */
				|	PBGPROTNLOCKENA_CNT_U32; /* lock the register */
				

	/* PBG2A Channel 0 - CSIG0 - A */
	PBGFSGD2ADPROT0 = PBGPROTNCMN_CNT_U32	/* common PBG protection settings */
				|	PBGUSRMODENA_CNT_U32	/* enable user mode access */
				|	PBGSPID1ENA_CNT_U32		/* enable SPID1 */
				|	PBGPROTNLOCKENA_CNT_U32; /* lock the register */
	
	/* PBG2A Channel 1 - CSIG0 - B */
	PBGFSGD2ADPROT1 = PBGPROTNCMN_CNT_U32	/* common PBG protection settings */
				|	PBGUSRMODENA_CNT_U32	/* enable user mode access */
				|	PBGSPID1ENA_CNT_U32		/* enable SPID1 */
				|	PBGPROTNLOCKENA_CNT_U32; /* lock the register */
				
	/* PBG2A Channel 2 - OSTM3 */
	PBGFSGD2ADPROT2 = PBGPROTNCMN_CNT_U32	/* common PBG protection settings */
				|	PBGUSRMODDI_CNT_U32	    /* disable user mode access */
				|	PBGSPID1ENA_CNT_U32		/* enable SPID1 */
				|	PBGPROTNLOCKENA_CNT_U32; /* lock the register */
				
	/* PBG2A Channel 3 - OSTM4 */
	PBGFSGD2ADPROT3 = PBGPROTNCMN_CNT_U32	/* common PBG protection settings */
				|	PBGUSRMODDI_CNT_U32	    /* disable user mode access */
				|	PBGSPID1ENA_CNT_U32		/* enable SPID1 */
				|	PBGPROTNLOCKENA_CNT_U32; /* lock the register */
				
	/* PBG2A Channel 4 - OSTM5 */
	PBGFSGD2ADPROT4 = PBGPROTNCMN_CNT_U32	/* common PBG protection settings */
				|	PBGUSRMODDI_CNT_U32	    /* disable user mode access */
				|	PBGSPID1ENA_CNT_U32		/* enable SPID1 */
				|	PBGPROTNLOCKENA_CNT_U32; /* lock the register */
				
	/* PBG2A Channel 5 - OSTM6 */
	PBGFSGD2ADPROT5 = PBGPROTNCMN_CNT_U32	/* common PBG protection settings */
				|	PBGUSRMODDI_CNT_U32	    /* disable user mode access */
				|	PBGSPID1ENA_CNT_U32		/* enable SPID1 */
				|	PBGPROTNLOCKENA_CNT_U32; /* lock the register */
				
	/* PBG2A Channel 6 - OSTM7 */
	PBGFSGD2ADPROT6 = PBGPROTNCMN_CNT_U32	/* common PBG protection settings */
				|	PBGUSRMODDI_CNT_U32	    /* disable user mode access */
				|	PBGSPID1ENA_CNT_U32		/* enable SPID1 */
				|	PBGPROTNLOCKENA_CNT_U32; /* lock the register */
				
	/* PBG2A Channel 7 - BIST */
	PBGFSGD2ADPROT7 = PBGPROTNCMN_CNT_U32	/* common PBG protection settings */
				|	PBGUSRMODENA_CNT_U32	/* enable user mode access */
				|	PBGSPID1ENA_CNT_U32		/* enable SPID1 */	
				|	PBGPROTNLOCKENA_CNT_U32; /* lock the register */
				
	/* PBG2A Channel 8 - CSIH0 - A */
	PBGFSGD2ADPROT8 = PBGPROTNCMN_CNT_U32	/* common PBG protection settings */
				|	PBGUSRMODENA_CNT_U32	/* enable user mode access */
				|	PBGSPID1ENA_CNT_U32		/* enable SPID1 */
				|	PBGPROTNLOCKENA_CNT_U32; /* lock the register */
				
	#if (MCUDIAGCERRINJ == STD_OFF)
	/* PBG2A Channel 9 - CSIH0 - B */
	PBGFSGD2ADPROT9 = PBGPROTNCMN_CNT_U32	/* common PBG protection settings */
				|	PBGUSRMODENA_CNT_U32	/* enable user mode access */
				|	PBGSPID1ENA_CNT_U32		/* enable SPID1 */
				|	PBGPROTNLOCKENA_CNT_U32; /* lock the register */
	#elif (MCUDIAGCERRINJ == STD_ON)
	if (ErrId_Cnt_T_u32 == MCUERRINJ_NTC002DBIT05CASE04_CNT_U32)
	{
		/* Clear BRAMDAT2 Register */
		ClrErrInjReg_Oper();
		/* Disable Write Access for ALL SPIDs */
		PBGFSGD2ADPROT9 = PBGSETNOWRACS_CNT_U32
				|	PBGUSRMODENA_CNT_U32	/* enable user mode access */
				|	PBGSPID1ENA_CNT_U32		/* enable SPID1 */
				|	PBGPROTNLOCKENA_CNT_U32; /* lock the register */
        /* After a Sync instruction write to a register protected by the respective guards*/
        __SYNCM();
        CSIH0CFG0 = 0x00000000U;
	}
	else if (ErrId_Cnt_T_u32 == MCUERRINJ_NTC0022BIT01CASE04_CNT_U32)
	{
		/* Clear BRAMDAT2 Register */
		ClrErrInjReg_Oper();
		/* PBG2A Channel 9 - CSIH0 - B */
		PBGFSGD2ADPROT9 = PBGSETNOREADACS_CNT_U32
				|	PBGUSRMODENA_CNT_U32	/* enable user mode access */
				|	PBGSPID1ENA_CNT_U32		/* enable SPID1 */
				|	PBGPROTNLOCKENA_CNT_U32; /* lock the register */
        /* After a Sync instruction read to a register protected by the respective guards*/
        __SYNCM();
        McuDiagcTestVar1_G = CSIH0RX0W;
	}
	else
	{
		/* PBG2A Channel 9 - CSIH0 - B */
		PBGFSGD2ADPROT9 = PBGPROTNCMN_CNT_U32	/* common PBG protection settings */
				|	PBGUSRMODENA_CNT_U32	/* enable user mode access */
				|	PBGSPID1ENA_CNT_U32		/* enable SPID1 */
				|	PBGPROTNLOCKENA_CNT_U32; /* lock the register */
	}
	#endif
				
	/* PBG2A Channel 10 - CSIH1 */ 
	PBGFSGD2ADPROT10 = PBGPROTNCMN_CNT_U32	/* common PBG protection settings */
				|	PBGUSRMODENA_CNT_U32	/* enable user mode access */
				|	PBGSPID1ENA_CNT_U32		/* enable SPID1 */
				|	PBGPROTNLOCKENA_CNT_U32; /* lock the register */
				
	/* PBG2A Channel 11 - CSIH1 - Read Operation DMAC00, Write Operation DMAC14 */
	PBGFSGD2ADPROT11 = PBGPROTNCMN_CNT_U32	/* common PBG protection settings */
				|	PBGUSRMODENA_CNT_U32	/* enable user mode access */
				|	PBGSPID321ENA_CNT_U32  	/* SPID3, SPID2, and SPID1 */
				|	PBGPROTNLOCKENA_CNT_U32; /* lock the register */
				
	/* PBG2A Channel 12 - CSIH2 - A */
	PBGFSGD2ADPROT12 = PBGPROTNCMN_CNT_U32	/* common PBG protection settings */
				|	PBGUSRMODENA_CNT_U32	/* enable user mode access */
				|	PBGSPID1ENA_CNT_U32		/* enable SPID1 */
				|	PBGPROTNLOCKENA_CNT_U32; /* lock the register */
				
	/* PBG2A Channel 13 - CSIH2 - B */
	PBGFSGD2ADPROT13 = PBGPROTNCMN_CNT_U32	/* common PBG protection settings */
				|	PBGUSRMODENA_CNT_U32	/* enable user mode access */
				|	PBGSPID1ENA_CNT_U32		/* enable SPID1 */
				|	PBGPROTNLOCKENA_CNT_U32; /* lock the register */
				
	/* PBG2A Channel 14 - CSIH3 */
	PBGFSGD2ADPROT14 = PBGPROTNCMN_CNT_U32	/* common PBG protection settings */
				|	PBGUSRMODENA_CNT_U32	/* enable user mode access */
				|	PBGSPID1ENA_CNT_U32		/* enable SPID1 */
				|	PBGPROTNLOCKENA_CNT_U32; /* lock the register */
				
	/* PBG2A Channel 15 - CSIH3 - Read Operation DMAC02, Write Operation DMAC12 */
	PBGFSGD2ADPROT15 = PBGPROTNCMN_CNT_U32	/* common PBG protection settings */
				|	PBGUSRMODENA_CNT_U32	/* enable user mode access */
				|	PBGSPID321ENA_CNT_U32  	/* SPID3, SPID2, and SPID1 */
				|	PBGPROTNLOCKENA_CNT_U32; /* lock the register */
				
	/* PBG3A Channel 0 - DNFA */
	PBGFSGD3ADPROT0 = PBGPROTNCMN_CNT_U32	/* common PBG protection settings */
				|	PBGUSRMODDI_CNT_U32	    /* disable user mode access */
				|	PBGSPID1ENA_CNT_U32		/* enable SPID1 */
				|	PBGPROTNLOCKENA_CNT_U32; /* lock the register */
				
	/* PBG3A Channel 1 - JTAG-A */
	PBGFSGD3ADPROT1 = PBGPROTNCMN_CNT_U32	/* common PBG protection settings */
				|	PBGUSRMODDI_CNT_U32	    /* disable user mode access */
				|	PBGSPID1ENA_CNT_U32		/* enable SPID1 */
				|	PBGPROTNLOCKENA_CNT_U32; /* lock the register */
				
	/* PBG3A Channel 2 - JTAG-B */
	PBGFSGD3ADPROT2 = PBGPROTNCMN_CNT_U32	/* common PBG protection settings */
				|	PBGUSRMODDI_CNT_U32	    /* disable user mode access */
				|	PBGSPID1ENA_CNT_U32		/* enable SPID1 */
				|	PBGPROTNLOCKENA_CNT_U32; /* lock the register */
				
	/* PBG3A Channel 3 - Port Group 0 to 5 (Group A) */
	PBGFSGD3ADPROT3 = PBGPROTNCMN_CNT_U32	/* common PBG protection settings */
				|	PBGUSRMODENA_CNT_U32	/* enable user mode access */
				|	PBGSPID1ENA_CNT_U32		/* enable SPID1 */
				|	PBGPROTNLOCKENA_CNT_U32; /* lock the register */
				
	/* PBG3A Channel 4 - Port Group 0 to 5 (Group B) */
	PBGFSGD3ADPROT4 = PBGPROTNCMN_CNT_U32	/* common PBG protection settings */
				|	PBGUSRMODENA_CNT_U32	/* enable user mode access */
				|	PBGSPID1ENA_CNT_U32		/* enable SPID1 */
				|	PBGPROTNLOCKENA_CNT_U32; /* lock the register */
				
	/* PBG3A Channel 5 - FCLA0 */
	PBGFSGD3ADPROT5 = PBGPROTNCMN_CNT_U32	/* common PBG protection settings */
				|	PBGUSRMODDI_CNT_U32	    /* disable user mode access */
				|	PBGSPID1ENA_CNT_U32		/* enable SPID1 */
				|	PBGPROTNLOCKENA_CNT_U32; /* lock the register */
				
	/* PBG3A Channel 6 - FCLA1 */
	PBGFSGD3ADPROT6 = PBGPROTNCMN_CNT_U32	/* common PBG protection settings */
				|	PBGUSRMODDI_CNT_U32	    /* disable user mode access */
				|	PBGSPID1ENA_CNT_U32		/* enable SPID1 */
				|	PBGPROTNLOCKENA_CNT_U32; /* lock the register */
				
	/* PBG3A Channel 7 - FCLA2 */
	PBGFSGD3ADPROT7 = PBGPROTNCMN_CNT_U32	/* common PBG protection settings */
				|	PBGUSRMODDI_CNT_U32	    /* disable user mode access */
				|	PBGSPID1ENA_CNT_U32		/* enable SPID1 */
				|	PBGPROTNLOCKENA_CNT_U32; /* lock the register */
				
	/* PBG3A Channel 8 - FCLA3 */
	PBGFSGD3ADPROT8 = PBGPROTNCMN_CNT_U32	/* common PBG protection settings */
				|	PBGUSRMODDI_CNT_U32	    /* disable user mode access */
				|	PBGSPID1ENA_CNT_U32		/* enable SPID1 */
				|	PBGPROTNLOCKENA_CNT_U32; /* lock the register */
				
	/* PBG3A Channel 9 - FCLA4 */
	PBGFSGD3ADPROT9 = PBGPROTNCMN_CNT_U32	/* common PBG protection settings */
				|	PBGUSRMODDI_CNT_U32	    /* disable user mode access */
				|	PBGSPID1ENA_CNT_U32		/* enable SPID1 */
				|	PBGPROTNLOCKENA_CNT_U32; /* lock the register */

	#if (MCUDIAGCERRINJ == STD_OFF)
	/* PBG3A Channel 10 - ADCD0 - Read Operation DMAC01 */
	PBGFSGD3ADPROT10 = PBGPROTNCMN_CNT_U32	/* common PBG protection settings */
				|	PBGUSRMODENA_CNT_U32	/* enable user mode access */
				|	PBGSPID31ENA_CNT_U32   	/* enable SPID3 and SPID1 */
				|	PBGPROTNLOCKENA_CNT_U32; /* lock the register */
				
	#elif (MCUDIAGCERRINJ == STD_ON)
	if (ErrId_Cnt_T_u32 == MCUERRINJ_NTC002DBIT05CASE05_CNT_U32)
	{
		/* Clear BRAMDAT2 Register */
		ClrErrInjReg_Oper();
		/* Disable Write Access for ALL SPIDs */
		PBGFSGD3ADPROT10 = PBGSETNOWRACS_CNT_U32
				|	PBGUSRMODENA_CNT_U32	/* enable user mode access */
				|	PBGSPID31ENA_CNT_U32   	/* enable SPID3 and SPID1 */
				|	PBGPROTNLOCKENA_CNT_U32; /* lock the register */
        /* After a Sync instruction write to a register protected by the respective guards*/
        __SYNCM();
        ADCD0ADCR1 = 0x00U;
	}
	else if (ErrId_Cnt_T_u32 == MCUERRINJ_NTC0022BIT01CASE05_CNT_U32)
	{
		/* Clear BRAMDAT2 Register */
		ClrErrInjReg_Oper();
		/* Disable Read Access for ALL SPIDs */
		PBGFSGD3ADPROT10 = PBGSETNOREADACS_CNT_U32
				|	PBGUSRMODENA_CNT_U32	/* enable user mode access */
				|	PBGSPID31ENA_CNT_U32   	/* enable SPID3 and SPID1 */
				|	PBGPROTNLOCKENA_CNT_U32; /* lock the register */
        /* After a Sync instruction read to a register protected by the respective guards*/
        __SYNCM();
        McuDiagcTestVar1_G = (uint32)ADCD0ADCR1;
	}
	else
	{
		/* PBG3A Channel 10 - ADCD0 - Read Operation DMAC01 */
		PBGFSGD3ADPROT10 = PBGPROTNCMN_CNT_U32	/* common PBG protection settings */
				|	PBGUSRMODENA_CNT_U32	/* enable user mode access */
				|	PBGSPID31ENA_CNT_U32   	/* enable SPID3 and SPID1 */
				|	PBGPROTNLOCKENA_CNT_U32; /* lock the register */
				
	}
	#endif
	
	/* PBG3A Channel 11 - ADCD1 - Read Operation DMAC16 */
	PBGFSGD3ADPROT11 = PBGPROTNCMN_CNT_U32	/* common PBG protection settings */
				|	PBGUSRMODENA_CNT_U32	/* enable user mode access */
				|	PBGSPID31ENA_CNT_U32   	/* enable SPID3 and SPID1 */
				|	PBGPROTNLOCKENA_CNT_U32; /* lock the register */
				
	#if (MCUDIAGCERRINJ == STD_OFF)
	/* PBG5A Channel 0 - RESET, BSEq0CTL, CLOCK OUTPUT FUNCTION, CVM, LVI, POF, CLMA0 to 3, Digital Noise elimination, flash write and erase protection */
	PBGFSGD5ADPROT0 = PBGPROTNCMN_CNT_U32	/* common PBG protection settings */
				|	PBGUSRMODENA_CNT_U32	/* enable user mode access */
				|	PBGSPID1ENA_CNT_U32		/* enable SPID1 */
				|	PBGPROTNLOCKENA_CNT_U32; /* lock the register */
				
	#elif (MCUDIAGCERRINJ == STD_ON)
	if (ErrId_Cnt_T_u32 == MCUERRINJ_NTC002DBIT05CASE06_CNT_U32)
	{
		/* Clear BRAMDAT2 Register */
		ClrErrInjReg_Oper();
		/* Disable Write Access for ALL SPIDs */
		PBGFSGD5ADPROT0 = PBGSETNOWRACS_CNT_U32
				|	PBGUSRMODENA_CNT_U32	/* enable user mode access */
				|	PBGSPID1ENA_CNT_U32		/* enable SPID1 */
				|	PBGPROTNLOCKENA_CNT_U32; /* lock the register */
        /* After a Sync instruction write to a register protected by the respective guards*/
        __SYNCM();
        SYSDNFCKS100C = 0x00000002U;
    }
	else if (ErrId_Cnt_T_u32 == MCUERRINJ_NTC0022BIT01CASE06_CNT_U32)
	{
		/* Clear BRAMDAT2 Register */
		ClrErrInjReg_Oper();
		/* Disable Read Access for ALL SPIDs */
		PBGFSGD5ADPROT0 = PBGSETNOREADACS_CNT_U32
				|	PBGUSRMODENA_CNT_U32	/* enable user mode access */
				|	PBGSPID1ENA_CNT_U32		/* enable SPID1 */
				|	PBGPROTNLOCKENA_CNT_U32; /* lock the register */
        /* After a Sync instruction read to a register protected by the respective guards*/
        __SYNCM();
        McuDiagcTestVar1_G = SYSDNFCKS100C;
    }
	else
	{
		/* PBG5A Channel 0 - RESET, BSEq0CTL, CLOCK OUTPUT FUNCTION, CVM, LVI, POF, CLMA0 to 3, Digital Noise elimination, flash write and erase protection */
		PBGFSGD5ADPROT0 = PBGPROTNCMN_CNT_U32	/* common PBG protection settings */
				|	PBGUSRMODENA_CNT_U32	/* enable user mode access */
				|	PBGSPID1ENA_CNT_U32		/* enable SPID1 */
				|	PBGPROTNLOCKENA_CNT_U32; /* lock the register */
	}
	#endif
}

/******************************************************************************
 * Name:        IpgInin
 * Description: Internal Peripheral Guard (IPG) Initialization
 * Inputs:  None         
 * Outputs: IPG configuration registers      
 * Usage Notes: To be configured as a trusted function because it needs to run in supervisor mode
 ****************************************************************************/
FUNC(void, CDD_GuardCfgAndDiagc_CODE) IpgInin(void) 
{
	
	IPGPMTUM0 = 	(uint8)((uint8)0x00U << 6)			/* Restrict user mode execute access to Peripheral bus groups 0 to 3 and 5  */
				|	(uint8)((uint8)0x01U << 5)			/* Allow user mode Write access to Peripheral bus groups 0 to 3 and 5 */
				|	(uint8)((uint8)0x01U << 4)			/* Allow user mode Read access to Peripheral bus groups 0 to 3 and 5 */
				|	(uint8)((uint8)0x00U << 2)			/* Restrict user mode execute access to H-bus */
				|	(uint8)((uint8)0x01U << 1)			/* Allow user mode Write access to H-bus */
				|	(uint8)((uint8)0x01U << 0);		/* Allow user mode Read access to H-bus */ 
				
				
	/* PE1 has Interrupt controller & COMPTEST read/write access in supervisor mode */
	IPGPMTUM2 = 	(uint8)((uint8)0x00U << 5)			/* Restrict user mode PE1 write access to COMPTEST */
				|	(uint8)((uint8)0x01U << 4)		/* Allow user mode PE1 read access to COMPTEST */
				|	(uint8)((uint8)0x00U << 1)		/* Restrict user mode PE1 write access to INTC1 */
				|	(uint8)((uint8)0x01U << 0);	/* Allow user mode PE1 read access to INTC1 */
				
		
	/* PE1 has SysErrGen read/write access in supervisor mode */
	IPGPMTUM3 = 	(uint8)((uint8)0x00U << 5)		/* Restrict user mode PE1 write access to SysErrGen */
				|	(uint8)((uint8)0x01U << 4);	/* Allow user mode PE1 read access to SysErrGen */
				
	/* PE1 has IPG and PEG read/write access in supervisor mode */
	IPGPMTUM4 = 	(uint8)((uint8)0x00U << 1)		/* Restrict user mode PE1 write access to IPG and PEG */
				|	(uint8)((uint8)0x01U << 0);	/* Allow user mode PE1 read access to IPG and PEG */
				
	
	/* Enable IPG after above configuration */
	IPGENUM   = 	(uint8)((uint8)0x01U << 1)		/* Enable storing of instruction fetch access violation information */
				|	(uint8)((uint8)0x01U << 0);	/* Enable peripheral device protection */

}	


/******************************************************************************
 * Name:        GuardCfgAndDiagcInit3
 * Description: Start Up Initialization test of PBG of Group 3A
 * Inputs:      None     
 * Outputs:     None  
 * Usage Notes: Non-RTE function 
 ****************************************************************************/
FUNC(void, CDD_GuardCfgAndDiagc_CODE) GuardCfgAndDiagcInit3(void) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
	/* This code assumes that the ECM has NOT been configured to generate exceptions or 
	interrupts on PBG error detection.  It is assumed that SYSERR on PBG violation detection then
	is configured so this code briefly disables that but restores it before returning.
	Run this test in Supervisor mode!!!! */

	VAR(uint32,AUTOMATIC) ErrorOutPinMaskSave_Cnt_T_u32 = ECMEMK0;
	VAR(uint16,AUTOMATIC) SaveSegCont_Cnt_T_u16 = SEGCONT;
	VAR(boolean,AUTOMATIC) ExecStrtUpTest_Cnt_T_logl;  
	
	VAR(uint32,AUTOMATIC) PbgStrtUpTestFailSts_Cnt_T_u32 = PBGSTRTUPTESTNOFAILR_CNT_U32;
	#if(MCUDIAGCERRINJ == STD_ON)
	VAR(uint32, AUTOMATIC) McuDiagcData0_Cnt_T_u32;
	GetMcuDiagcIdnData(&McuDiagcData0_Cnt_T_u32);
	#endif
	
	ChkForStrtUpTest_Oper(&ExecStrtUpTest_Cnt_T_logl); 

	if ((( TRUE == ExecStrtUpTest_Cnt_T_logl ) && (0U == (PBGERRSLV3ASTAT & (uint32)1U)) && (0U == (ECMMESSTR0 & ((uint32)1U<<26U))))
		#if(MCUDIAGCERRINJ == STD_ON)
		|| (McuDiagcData0_Cnt_T_u32 == MCUDIAGC_MCUDIAGCTEST)
		#endif
		)
	{
		/* Set BIT26 to prevent (mask off) test induced PBG error from getting to the ERROROUT  pin */
		WrProtdRegEcm_u32 ( ErrorOutPinMaskSave_Cnt_T_u32 | ((uint32)1U << 26U), &ECMEMK0);
		
		SEGVCIE = 0U;  /* turn off syserr response to several VCIE things */
		SEGVPGE = 0U;  /* turn off syserr response to PBG write violation */
		
		/* Ensure the written value has settled */
		__SYNCM();
		
		Vrfy8BitPBGRegAcs(&PbgStrtUpTestFailSts_Cnt_T_u32);
		
		if(PbgStrtUpTestFailSts_Cnt_T_u32 == PBGSTRTUPTESTNOFAILR_CNT_U32)
		{
			Vrfy16BitPBGRegAcs(&PbgStrtUpTestFailSts_Cnt_T_u32);
		}
		if(PbgStrtUpTestFailSts_Cnt_T_u32 == PBGSTRTUPTESTNOFAILR_CNT_U32)
		{
			Vrfy32BitPBGRegAcs(&PbgStrtUpTestFailSts_Cnt_T_u32);
		}
			
		SEGVPGF = 0U;  	/* clear VPGF, this gets set despite VPGE being 0 */
		SEGVCIF = 0U;  /* clear VCIF, this gets set despite VCIE being 0 */
	
		/* Restore entry SEGCONT content */
		SEGCONT = SaveSegCont_Cnt_T_u16;  
		/* Restore the mask to the ERROROUT pin */
		WrProtdRegEcm_u32(ErrorOutPinMaskSave_Cnt_T_u32, &ECMEMK0); 
	}
	/* Comes to the 'else if' case if either of (0U == (PBGERRSLV3ASTAT & (uint32)1U)) or (0U == (ECMMESSTR0 & ((uint32)1U<<26U)) is false */
	else if( TRUE == ExecStrtUpTest_Cnt_T_logl )
	{
	    PbgStrtUpTestFailSts_Cnt_T_u32 = 0xFFFFFFFFU;
	}
	else
	{
		/* Empty Else case */
	}
	
	if(PbgStrtUpTestFailSts_Cnt_T_u32 != PBGSTRTUPTESTNOFAILR_CNT_U32)
	{
		/* Will set error code if the test failed */
		SetMcuDiagcIdnData( MCUDIAGC_PBGSTRTUPTST, PbgStrtUpTestFailSts_Cnt_T_u32); 
	}
}  /* end of the function */

/******************************************************************************
 * Name:        ConfigureFilterN
 * Description: Static function to configure, read back and set error code if 
				it doesn't verify
 * Inputs:  	PbgProtReg, Val        
 * Outputs: 	None      
 * Usage Notes: To be called from GuardCfgAndDiagcInit3 function
 ****************************************************************************/
static FUNC(void, CDD_GuardCfgAndDiagc_CODE) ConfigureFilterN(volatile P2VAR(uint32,AUTOMATIC,AUTOMATIC)PbgProtReg, uint32 Val,P2VAR(uint32,AUTOMATIC,AUTOMATIC)PbgStrtUpTestFailSts)
{
	*PbgProtReg = Val;   /* Write to protection register */

	if (Val !=  *PbgProtReg)
	{
		/* Flag Failure*/   
		*PbgStrtUpTestFailSts |= CFGERRBIT_CNT_U32;
	}
      
}

/******************************************************************************
 * Name:        ChkForPBGErr
 * Description: Static function to check PBG access violation error is captured
				if not set diagnostic,clear the error and if the error doesnt 
				clear set diagnostic
 * Inputs:  	None        
 * Outputs: 	None      
 * Usage Notes: To be called from GuardCfgAndDiagcInit3 function
 ****************************************************************************/
static FUNC(void, CDD_GuardCfgAndDiagc_CODE) ChkForPBGErr(P2VAR(uint32,AUTOMATIC,AUTOMATIC)PbgStrtUpTestFailSts)
{
	if (0U == (PBGERRSLV3ASTAT & (uint32)1U))
	{
		/* Flag Failure*/  
		*PbgStrtUpTestFailSts |= PBGERRBIT_CNT_U32;
	}

	/* Clear error and Overflow bits by write to ERRSLV3ACTL*/
	PBGERRSLV3ACTL = 1U;  

	if (0U != (PBGERRSLV3ASTAT & (uint32)1U))
	{
		/* Flag Failure*/  
		*PbgStrtUpTestFailSts |= PBGERRBIT_CNT_U32;
	}
}

/******************************************************************************
 * Name:        ChkForECMErr
 * Description: Static function to check ECM captures the error, sets diagnostic
				message and clears the ECM errors after the check else set 
				diagnostic
 * Inputs:  	None        
 * Outputs: 	None      
 * Usage Notes: To be called from GuardCfgAndDiagcInit3 function
 ****************************************************************************/
static FUNC(void, CDD_GuardCfgAndDiagc_CODE) ChkForECMErr(P2VAR(uint32,AUTOMATIC,AUTOMATIC)PbgStrtUpTestFailSts)
{
	/* Test that the data got to the ECM */
	if (0U == (ECMMESSTR0 & ((uint32)1U<<26U)))
	{
		/* Flag Failure*/ 
		*PbgStrtUpTestFailSts |= ECMERRBIT_CNT_U32;
	}

	/* (clear reg., data field, protection register) */
	WrProtdRegEcm_u32 ((uint32)1U<<26U, &ECMESSTC0); 

	if (0U != (ECMMESSTR0 & ((uint32)1U<<26U) ))
	{
		/* Flag Failure*/ 
		*PbgStrtUpTestFailSts |= ECMERRBIT_CNT_U32;
	}
      
}

/******************************************************************************
 * Name:        Vrfy32BitPBGRegAcs
 * Description: Static function to check 32 bit Read/Write access to PBG 
				peripherals gives exception when protection is provided
 * Inputs:  	None        
 * Outputs: 	None      
 * Usage Notes: To be called from GuardCfgAndDiagcInit3 function
 ****************************************************************************/
static FUNC(void, CDD_GuardCfgAndDiagc_CODE) Vrfy32BitPBGRegAcs(P2VAR(uint32,AUTOMATIC,AUTOMATIC)PbgStrtUpTestFailSts)
{
	CONST(PbgTest32BitRec1,AUTOMATIC) PbgTest32BitRecAry[NROF32BITREG_CNT_U08] =
	{
		{&PBGFSGD3ADPROT2,&PORTJJPCR0_0},		/* 32 bit address (for the second value)   */
		{&PBGFSGD3ADPROT4,&PORTPCR0_0}			/* 32 bit address (for the second value)   */
	};

	volatile P2VAR( uint32, AUTOMATIC,AUTOMATIC) PbgRegAddrPtr_Cnt_T_u32;   		/* get first guard reg addr */
	volatile P2VAR( uint32, AUTOMATIC,AUTOMATIC) TestPrphlAddrPtr_Cnt_T_u32;  	/* Peripheral test address */
	volatile VAR( uint32,AUTOMATIC) ReadVal32_Cnt_T_u32;
	VAR(uint32,AUTOMATIC) SavePbgProtectionReg_Cnt_T_u32;
	VAR(uint8,AUTOMATIC) LoopCntr_Cnt_T_u08 = 0U;
	
	do
	{
		/* Get next Register address */	
		PbgRegAddrPtr_Cnt_T_u32 = PbgTest32BitRecAry[LoopCntr_Cnt_T_u08].PbgProtnRegAdr32BitAcs;  
		/* Get next  peripheral address */
		TestPrphlAddrPtr_Cnt_T_u32 =  PbgTest32BitRecAry[LoopCntr_Cnt_T_u08].PortAcsReg32Bit; 

		/* Save filter value */
		SavePbgProtectionReg_Cnt_T_u32 = *PbgRegAddrPtr_Cnt_T_u32;   

		/* Configure to NO ACCESS PERMISSION 0x405FE5C  no user mode, need 
		to pass filter but no read nor write access is given*/
		ConfigureFilterN( PbgRegAddrPtr_Cnt_T_u32, PBGSETNOREADWRACS_CNT_U32,PbgStrtUpTestFailSts);    

		/* Show that READING from the resource is protected 
		16 bit read from the resource,should generate error */	
		ReadVal32_Cnt_T_u32  =  *TestPrphlAddrPtr_Cnt_T_u32;  
		
		ChkForPBGErr(PbgStrtUpTestFailSts);

		ChkForECMErr(PbgStrtUpTestFailSts);

		if(*PbgStrtUpTestFailSts != PBGSTRTUPTESTNOFAILR_CNT_U32)
		{
			/* Read Test Failed */
			*PbgStrtUpTestFailSts |= READERRBIT_CNT_U32;
		}
		else
		{
			/* 32 bit write to the resource, should generate error	*/			
			*TestPrphlAddrPtr_Cnt_T_u32  = ReadVal32_Cnt_T_u32  ;  

			ChkForPBGErr(PbgStrtUpTestFailSts);

			ChkForECMErr(PbgStrtUpTestFailSts);
			
			if(*PbgStrtUpTestFailSts != PBGSTRTUPTESTNOFAILR_CNT_U32)
			{
				/* Write Test Failed */
				*PbgStrtUpTestFailSts |= WRERRBIT_CNT_U32;
			}
		
		}
		/* Restore PBG register value */
		ConfigureFilterN( PbgRegAddrPtr_Cnt_T_u32, SavePbgProtectionReg_Cnt_T_u32,PbgStrtUpTestFailSts); 	
		
		LoopCntr_Cnt_T_u08++;
	}while((LoopCntr_Cnt_T_u08 < NROF32BITREG_CNT_U08) && (*PbgStrtUpTestFailSts == PBGSTRTUPTESTNOFAILR_CNT_U32));
	
	if(*PbgStrtUpTestFailSts != PBGSTRTUPTESTNOFAILR_CNT_U32)
	{
		/* Register Type */
		*PbgStrtUpTestFailSts |= REGTYPE32BIT_CNT_U32;
		/* Index */
		*PbgStrtUpTestFailSts |= ((uint32)LoopCntr_Cnt_T_u08-1U);
		
	}
      
}

/******************************************************************************
 * Name:        Vrfy16BitPBGRegAcs
 * Description: Static function to check 16 bit Read/Write access to PBG 
				peripherals gives exception when protection is provided
 * Inputs:  	None        
 * Outputs: 	None      
 * Usage Notes: To be called from GuardCfgAndDiagcInit3 function
 ****************************************************************************/
static FUNC(void, CDD_GuardCfgAndDiagc_CODE) Vrfy16BitPBGRegAcs(P2VAR(uint32,AUTOMATIC,AUTOMATIC)PbgStrtUpTestFailSts)
{
	CONST(PbgTest16BitRec1,AUTOMATIC) PbgTest16BitRec = {&PBGFSGD3ADPROT3,&PORTPMC0};
	volatile P2VAR( uint32, AUTOMATIC,AUTOMATIC) PbgRegAddrPtr_Cnt_T_u32;   		/* get first guard reg addr */
	volatile P2VAR( uint16, AUTOMATIC,AUTOMATIC) TestPrphlAddrPtr_Cnt_T_u16;  	/* Peripheral test address */
	volatile VAR( uint16,AUTOMATIC) ReadVal16_Cnt_T_u16;
	VAR(uint32,AUTOMATIC) SavePbgProtectionReg_Cnt_T_u32;
	#if(MCUDIAGCERRINJ == STD_ON)
	VAR(uint32, AUTOMATIC) ErrId_Cnt_T_u32;
	ReadErrInjReg_Oper(&ErrId_Cnt_T_u32);
	#endif
	
	/* Get next Register address */	
	PbgRegAddrPtr_Cnt_T_u32 = PbgTest16BitRec.PbgProtnRegAdr16BitAcs;  
	/* Get next  peripheral address */
	TestPrphlAddrPtr_Cnt_T_u16 =  PbgTest16BitRec.PortAcsReg16Bit; 

	/* Save filter value */
	SavePbgProtectionReg_Cnt_T_u32 = *PbgRegAddrPtr_Cnt_T_u32;   

	/* Configure to NO ACCESS PERMISSION 0x405FE5C  no user mode, need 
	to pass filter but no read nor write access is given*/
	ConfigureFilterN( PbgRegAddrPtr_Cnt_T_u32, PBGSETNOREADWRACS_CNT_U32,PbgStrtUpTestFailSts);    

	#if (MCUDIAGCERRINJ == STD_ON)
	if (ErrId_Cnt_T_u32 == MCUERRINJ_NTC002DBIT04CASE02_CNT_U32)
	{
		/* Clear BRAMDAT2 Register */
		ClrErrInjReg_Oper();
		/* Enable Write access for Error Injection */
		ConfigureFilterN( PbgRegAddrPtr_Cnt_T_u32, PBGSETNOREADACS_CNT_U32, PbgStrtUpTestFailSts);
	}
	else if (ErrId_Cnt_T_u32 == MCUERRINJ_NTC002DBIT04CASE01_CNT_U32)
	{
		/* Clear BRAMDAT2 Register */
		ClrErrInjReg_Oper();
		/* Enable Read access for Error Injection */
		ConfigureFilterN( PbgRegAddrPtr_Cnt_T_u32, PBGSETNOWRACS_CNT_U32, PbgStrtUpTestFailSts);
	}
	else
	{
		/* Do nothing */
	}
	#endif
	
	/* Show that READING from the resource is protected 
	16 bit read from the resource,should generate error */	
	ReadVal16_Cnt_T_u16  =  *TestPrphlAddrPtr_Cnt_T_u16;  
	
	ChkForPBGErr(PbgStrtUpTestFailSts);

	ChkForECMErr(PbgStrtUpTestFailSts);
	
	if(*PbgStrtUpTestFailSts != PBGSTRTUPTESTNOFAILR_CNT_U32)
	{
		/* Read Test Failed */
		*PbgStrtUpTestFailSts |= READERRBIT_CNT_U32;
	}
	else
	{
		/* 16 bit write to the resource, should generate error	*/	
		*TestPrphlAddrPtr_Cnt_T_u16  = ReadVal16_Cnt_T_u16  ;  

		ChkForPBGErr(PbgStrtUpTestFailSts);

		ChkForECMErr(PbgStrtUpTestFailSts);
		
		if(*PbgStrtUpTestFailSts != PBGSTRTUPTESTNOFAILR_CNT_U32)
		{
			/* Write Test Failed */
			*PbgStrtUpTestFailSts |= WRERRBIT_CNT_U32;
		}
	
	}		
	
	/* Restore PBG register value */
	ConfigureFilterN( PbgRegAddrPtr_Cnt_T_u32, SavePbgProtectionReg_Cnt_T_u32,PbgStrtUpTestFailSts); 
	
	if(*PbgStrtUpTestFailSts != PBGSTRTUPTESTNOFAILR_CNT_U32)
	{
		/* Register Type */
		*PbgStrtUpTestFailSts |= REGTYPE16BIT_CNT_U32;
		/* Index */		
		*PbgStrtUpTestFailSts |= ((uint32)(0U)<<0U);
	}
      
}

/******************************************************************************
 * Name:        Vrfy8BitPBGRegAcs
 * Description: Static function to check 8 bit Read/Write access to PBG 
				peripherals gives exception when protection is provided
 * Inputs:  	None        
 * Outputs: 	None      
 * Usage Notes: To be called from GuardCfgAndDiagcInit3 function
 ****************************************************************************/
static FUNC(void, CDD_GuardCfgAndDiagc_CODE) Vrfy8BitPBGRegAcs(P2VAR(uint32,AUTOMATIC,AUTOMATIC)PbgStrtUpTestFailSts)
{
	CONST(PbgTest8BitRec1,AUTOMATIC) PbgTest8BitRecAry[NROF8BITREG_CNT_U08] =
	{
		{&PBGFSGD3ADPROT0,&DNFA0CTL},		/* 8 bit address (for the second value)   */
		{&PBGFSGD3ADPROT1,&PORTJJPIBC0},	/* 8 bit address (for the second value)   */
		{&PBGFSGD3ADPROT5,&FCLA0CTL0},		/* 8 bit address (for the second value)   */
		{&PBGFSGD3ADPROT6,&FCLA1CTL0},		/* 8 bit address (for the second value)   */
		{&PBGFSGD3ADPROT7,&FCLA2CTL0},		/* 8 bit address (for the second value)   */
		{&PBGFSGD3ADPROT8,&FCLA3CTL0},		/* 8 bit address (for the second value)   */
		{&PBGFSGD3ADPROT9,&FCLA4CTL0},		/* 8 bit address (for the second value)   */
		{&PBGFSGD3ADPROT10,&ADCD0THACR},	/* 8 bit address (for the second value)   */
		{&PBGFSGD3ADPROT11,&ADCD1THACR}		/* 8 bit address (for the second value)   */	
	};

	volatile P2VAR( uint32, AUTOMATIC,AUTOMATIC) PbgRegAddrPtr_Cnt_T_u32;   		/* get first guard reg addr */
	volatile P2VAR( uint8, AUTOMATIC,AUTOMATIC) TestPrphlAddrPtr_Cnt_T_u08;  	/* Peripheral test address */
	volatile VAR( uint8,AUTOMATIC) ReadVal8_Cnt_T_u08;
	VAR(uint32,AUTOMATIC) SavePbgProtectionReg_Cnt_T_u32;
	VAR(uint8,AUTOMATIC) LoopCntr_Cnt_T_u08 = 0U;

	do
	{
		/* Get next Register address */	
		PbgRegAddrPtr_Cnt_T_u32 = PbgTest8BitRecAry[LoopCntr_Cnt_T_u08].PbgProtnRegAdr8BitAcs;  
		/* Get next  peripheral address */
		TestPrphlAddrPtr_Cnt_T_u08 =  PbgTest8BitRecAry[LoopCntr_Cnt_T_u08].PortAcsReg8Bit; 

		/* Save filter value */
		SavePbgProtectionReg_Cnt_T_u32 = *PbgRegAddrPtr_Cnt_T_u32;   

		/* Configure to NO ACCESS PERMISSION 0x405FE5C  no user mode, need 
		to pass filter but no read nor write access is given*/
		ConfigureFilterN( PbgRegAddrPtr_Cnt_T_u32, PBGSETNOREADWRACS_CNT_U32,PbgStrtUpTestFailSts);    

		/* Show that READING from the resource is protected 
		16 bit read from the resource,should generate error */	
		ReadVal8_Cnt_T_u08  =  *TestPrphlAddrPtr_Cnt_T_u08;  
		
		ChkForPBGErr(PbgStrtUpTestFailSts);

		ChkForECMErr(PbgStrtUpTestFailSts);
		
		if(*PbgStrtUpTestFailSts != PBGSTRTUPTESTNOFAILR_CNT_U32)
		{
			/* Read Test Failed */
			*PbgStrtUpTestFailSts |= READERRBIT_CNT_U32;
		}
		else
		{
			/* 8 bit write to the resource, should generate error	*/
			*TestPrphlAddrPtr_Cnt_T_u08  = ReadVal8_Cnt_T_u08  ;  

			ChkForPBGErr(PbgStrtUpTestFailSts);

			ChkForECMErr(PbgStrtUpTestFailSts);
			
			if(*PbgStrtUpTestFailSts != PBGSTRTUPTESTNOFAILR_CNT_U32)
			{
				/* Write Test Failed */
				*PbgStrtUpTestFailSts |= WRERRBIT_CNT_U32;
			}
		
		}			
					
		/* Restore PBG register value */
		ConfigureFilterN( PbgRegAddrPtr_Cnt_T_u32, SavePbgProtectionReg_Cnt_T_u32,PbgStrtUpTestFailSts); 
		
		LoopCntr_Cnt_T_u08++;
	}while((LoopCntr_Cnt_T_u08 < NROF8BITREG_CNT_U08) && (*PbgStrtUpTestFailSts == PBGSTRTUPTESTNOFAILR_CNT_U32));
	
	if(*PbgStrtUpTestFailSts != PBGSTRTUPTESTNOFAILR_CNT_U32)
	{
		/* Register Type */
		*PbgStrtUpTestFailSts |= REGTYPE8BIT_CNT_U32; 
		/* Index */	
		*PbgStrtUpTestFailSts |= ((uint32)LoopCntr_Cnt_T_u08-1U);
	}
      
      
}

#if (MCUDIAGCERRINJ == STD_ON)
/******************************************************************************
 * Name:        InjRtPegErr
 * Description: Inject Run time PEG access errors
 * Inputs:  	None        
 * Outputs: 	None      
 * Usage Notes: To be called from DF003 Micro Diag Error Injection
 ****************************************************************************/
FUNC(void, CDD_GuardCfgAndDiagc_CODE)InjRtPegErr(void)
{
	VAR(uint32, AUTOMATIC) ErrId_Cnt_T_u32;
	VAR(uint32, AUTOMATIC)TempVar_Cnt_u32;
	/* FaultError Injection Point 1 */
	ReadErrInjReg_Oper(&ErrId_Cnt_T_u32);

	/* PEG Violation: Disable SPID 3 access to Area 1 of LRAM */
	if (ErrId_Cnt_T_u32 == MCUERRINJ_NTC002DBIT01CASE01_CNT_U32)
	{
		/* Clear BRAMDAT2 Register */
		ClrErrInjReg_Oper();
		/* Disable SPID 3 from read access of the entire LRAM */
		PEGG1BA = 0xFEBE0053U;

		FLXA0OEP = 0U;
		__SYNCM();

		FLXA0OE = 1U;
		__SYNCM();

		while ( FLXA0OS == 0U)
		{
		}

		/* FROC.OEP = 1, OE is protected : Write access to the OE bit is disabled */
		FLXA0OEP = 1U;

		while ( FLXA0PBSY == 1U)
		{
		}
		
		/* FLXAnFRIBA - FlexRay Input Pointer Table Base Address Register  */ 
		FLXA0FRIBA = (uint32)&McuDiagcTestAry_G[0];

		/* Configure size of input pointer table */
		FLXA0ITM = 2U;

		/* IBSYS = 1, Transfer between IBF Shadow and Message RAM in progress */
		while ( FLXA0IBSYS == 1U)
		{
		}

		/* Input Transfer Enable Bit.This initialise the put and get index pointers */
		FLXA0ITE = 1U;
		__SYNCM();
	   
		/* To commit this table entry to the input handler, the application has to write the target message buffer
		number to the input queue control register */
		FLXA0IMBNR = 0U;

		FLXA0UIDX = 1U;
		__SYNCM();
	 
		while ( FLXA0UIRP == 1U)
		{
		}
	}
	else if(ErrId_Cnt_T_u32 == MCUERRINJ_NTC002DBIT01CASE02_CNT_U32)
	{
		ClrErrInjReg_Oper();
		TempVar_Cnt_u32 = DMASSDM02CM; /* a channel that write access to local RAM */
		TempVar_Cnt_u32 = TempVar_Cnt_u32 & (~((uint32)0x0000000CU));  /* clear the SPID bits (bits 3:2) */
		TempVar_Cnt_u32 = TempVar_Cnt_u32 | ((uint32)0x00000004U); /* use SPID 1 */
		DMASSDM02CM = TempVar_Cnt_u32;
	}
	else
	{
		/* Do nothing */
	}
}

/******************************************************************************
 * Name:        InjIpgRtErr 
 * Description: Inject Run time IPG access errors
 * Inputs:  	None        
 * Outputs: 	None      
 * Usage Notes: To be called from DF003 Micro Diag Error Injection
 ****************************************************************************/
FUNC(void, CDD_GuardCfgAndDiagc_CODE)InjIpgRtErr(void)
{
	VAR(uint32, AUTOMATIC) ErrId_Cnt_T_u32;
	ReadErrInjReg_Oper(&ErrId_Cnt_T_u32);

	if (ErrId_Cnt_T_u32 == MCUERRINJ_NTC002DBIT03CASE01_CNT_U32)
	{
		/* Clear BRAMDAT2 Register */
		ClrErrInjReg_Oper();
		/* Write to Test Compare Registers to Inject Error */
		TESTCOMPREG0 = 0xFFFFFFFFU;
	}
	else if (ErrId_Cnt_T_u32 == MCUERRINJ_NTC002DBIT03CASE02_CNT_U32)
	{
		/* Clear BRAMDAT2 Register */
		ClrErrInjReg_Oper();
		/* Write to Test Compare Registers to Inject Error */
		TESTCOMPREG1 = 0xFFFFFFFFU;
	}
	else if (ErrId_Cnt_T_u32 == MCUERRINJ_NTC002DBIT03CASE03_CNT_U32)
	{
		/* Clear BRAMDAT2 Register */
		ClrErrInjReg_Oper();
		/* Write to EIC8.EIPn-0n its initial configuration-Interrupt control registers */
		INTC1EIC8 = 0x8000U;
	}
	else if (ErrId_Cnt_T_u32 == MCUERRINJ_NTC002DBIT03CASE04_CNT_U32)
	{
		/* Clear BRAMDAT2 Register */
		ClrErrInjReg_Oper();
		/* Write to SEGCONT its initial configuration */
		SEGCONT = 0x0370U;
	}
	else if (ErrId_Cnt_T_u32 == MCUERRINJ_NTC002DBIT03CASE05_CNT_U32)
	{
		/* Clear BRAMDAT2 Register */
		ClrErrInjReg_Oper();
		/* Write to PEGG0BA its initial configuration */
		PEGG0BA  	= ((uint32)0xFEBFFU << 12)	/* Base value (bits 31:12 of register) = 0xFEBFF; region starts at address 0xFEBFF000 */
					|	((uint32)0x01U << 7)	/* SPID = 3 Access enabled */
					|	((uint32)0x00U << 6)	/* SPID = 2 Access disabled */
					|	((uint32)0x00U << 5)	/* SPID = 1 Access disabled */
					|	((uint32)0x01U << 4)	/* SPID = 0 Access enabled */ 
					|	((uint32)0x01U << 2)	/* Write Access is enabled */
					|	((uint32)0x00U << 1)	/* Read Access is disabled*/
					|	((uint32)0x01U << 0);	/* PE Guard protection area is enabled */
	}
	else if (ErrId_Cnt_T_u32 == MCUERRINJ_NTC002DBIT03CASE06_CNT_U32)
	{
		/* Clear BRAMDAT2 Register */
		ClrErrInjReg_Oper();
		/* IPG Control Register */
		IPGPMTUM0 = 0x33U;
	}
	else
	{
		/* Do nothing */
	}
}
#endif

#define CDD_GuardCfgAndDiagc_STOP_SEC_CODE
#include "CDD_GuardCfgAndDiagc_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
