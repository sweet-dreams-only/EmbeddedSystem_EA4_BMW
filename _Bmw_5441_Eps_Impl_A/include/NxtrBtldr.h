/**********************************************************************************************************************
* Copyright 2017 Nxtr 
* Nxtr Confidential
*
* Module File Name:   NxtrBtldr.h
* Module Description: Nxtr support bootloader function header
* Project           : BMW
* Author            : Kevin Smith
***********************************************************************************************************************
* Version Control:
* %version:          1 %
* %derived_by:       cz7lt6 %
*----------------------------------------------------------------------------------------------------------------------
* Date      Rev      Author         Change Description                                                           SCR #
* -------   -------  --------  ---------------------------------------------------------------------------     --------
* 09/06/17   1       KJS       Initial Version                                                                 EA4#14822                                                                            
* 01/11/18   2       AR        Update for NTC 20 fix                                                           EA4#19308                                                                            
**********************************************************************************************************************/

/**********************************************************************************************************************
    --- IMPORTANT ---
    Date: Sep-6-2017, K. Smith
    
    This file is only part of the project until the bootloader is available. Once the bootloader is available
    this file shall be removed from the project. 
**********************************************************************************************************************/
#ifndef NXTRBTLDR_H
#define NXTRBTLDR_H

/**********************************************************************************************************************
* Include files
 *********************************************************************************************************************/
#include "Std_Types.h"
#include "ram_regs.h"
#include "ecm_regs.h"
#include "sys_regs.h"
#include "clma_regs.h"
#include <v800_ghs.h>

/***********************************************************************************************************************
 *   DEFINES
 **********************************************************************************************************************/

#define FEPCREGID_CNT_U32       ((uint32)(2U))  /* register ID of FEPC */
#define FEPCSELNID_CNT_U32      ((uint32)(0U))  /* selection ID of FEPC */
#define EIPCREGID_CNT_U32       ((uint32)(0U))  /* register ID of EIPC */
#define EIPCSELNID_CNT_U32      ((uint32)(0U))  /* selection ID of EIPC */

/* The following definitions has to be matched with the corresponding definitions in exception handler component */
#define         MCUDIAGC_FLSPROGMREQ             (4294836225U)   /* 0xFFFE0001 */
#define         MCUDIAGC_FLSPROGMCMPL            (4294639620U)   /* 0xFFFB0004 */
#define         MCUDIAGC_PWRONRST                (4294443015U)   /* 0xFFF80007 */
#define         MCUDIAGC_ECMRST                  (4294246410U)   /* 0xFFF5000A */
#define         MCUDIAGC_PINRST                  (4294049805U)   /* 0xFFF2000D */
#define         MCUDIAGC_COREVLTGMONRLO          (4293853200U)   /* 0xFFEF0010 */
#define         MCUDIAGC_COREVLTGMONRHI          (4293656595U)   /* 0xFFEC0013 */
#define         MCUDIAGC_PREOSEXCPN              (4293459990U)   /* 0xFFE90016 */
#define         MCUDIAGC_RSTUKWN                 (4293263385U)   /* 0xFFE60019 */
#define         MCUDIAGC_BACKUPRAMTSTFAILR       (4293132315U)   /* 0xFFE4001B */
#define         MCUDIAGC_DBGRST                  (4292870175U)   /* 0xFFE0001F */
#define         MCUDIAGC_LOCKSTEPECMRST          (4292673570U)   /* 0xFFDD0022 */ 
#define         MCUDIAGC_HARDRST                 (4261151235U) 
/* The following definitions is used by fault injection code */

/* For Micro Diag Special Build define this value to STD_ON */
#define MCUDIAGCERRINJ STD_OFF

#if (MCUDIAGCERRINJ == STD_ON)
#define MCUDIAGC_MCUDIAGCTEST                 (4294901760U)   /* 0xFFFF0000 */
#define MCUERRINJ_NTC0029BIT00CASE01_CNT_U32  0x00290101      /* Unknown Reset Error Injection Value */
#define MCUERRINJ_NTC0029BIT05CASE01_CNT_U32  0x00292001      /* Back Ram 0 Test Failure Error Injection Value */
#define MCUERRINJ_NTC0029BIT07CASE01_CNT_U32  0x00298001      /* Corrupt Startup Error Injection Value */
#endif

/***********************************************************************************************************************
 *  PROTOTYPES
 **********************************************************************************************************************/
void FblEnableCodeFlashECCNtf(void); 
void FblDisableCodeFlashECC(void);
void FblEnableCodeFlashECC(void);
void FblDisableDataFlashECC(void);
void FblEnableLRamECC(void);
void FblEnableICacheRamECCNtf(void);
void FblResetProcessing(void);
void FblNxtrSwRstProgmCmpl(void);
void FblEnableSysErrExceptions(void);
void FblEnablePeripheralRamECC(void);
void FblEiExcpnHndlg(void);
void FblFeExcpnHndlg(void);

inline void FblWrProtdRegSys_u08(uint8 WrVal, volatile uint8 * WrAddr);
inline void FblWrProtdRegSysClmac_u32(uint32 WrVal, volatile uint32 * WrAddr);
inline void FblWrProtdRegEcm_u32(uint32 WrVal, volatile uint32 * WrAddr);

/***********************************************************************************************************************
 *  FUNCTION DEFINITIONS
 **********************************************************************************************************************/
 

/**********************************************************************************************************************
* Name:        FblWrProtdRegSys_u08
* Description: Function to write protected system registers CVMFC,CVMDIAG,CVMDMASK and CVMDEW
* Inputs:      None
* Outputs:     None
* Usage Notes: None
**********************************************************************************************************************/
inline void FblWrProtdRegSys_u08(uint8 WrVal, volatile uint8 * WrAddr)
{
    SYSPROTCMDCVM = 0x000000A5U;
    *WrAddr = WrVal;
    *WrAddr = ~WrVal;
    *WrAddr = WrVal;
    SYSPROTCMDCVM = 0x000000A5U;
    *WrAddr = WrVal;
    *WrAddr = ~WrVal;
    *WrAddr = WrVal;
}

/****************************************************************************************************************************
* Name:        FblWrProtdRegSysClmac_u32
* Description: Function to write protected system registers LVICNT,SWRESA,CKSC0CTL,CKSC1CTL,ADCKSC0CTL,BSEQ0CTL and CLMATEST
* Inputs:      None
* Outputs:     None
* Usage Notes: None
*****************************************************************************************************************************/
inline void FblWrProtdRegSysClmac_u32(uint32 WrVal, volatile uint32 * WrAddr)
{
    SYSPROT1PHCMD = 0x000000A5U;
    *WrAddr = WrVal;
    *WrAddr = ~WrVal;
    *WrAddr = WrVal;
    SYSPROT1PHCMD = 0x000000A5U;
    *WrAddr = WrVal;
    *WrAddr = ~WrVal;
    *WrAddr = WrVal;
}

/****************************************************************************************************************************
* Name:        FblWrProtdRegEcm_u32 
* Description: Function to write protected ECM register ECMMICFG0,ECMMICFG1,ECMNMICFG0,ECMNMICFG1,ECMIRCFG0,ECMIRCFG1,ECMEMK0 
*              ECMEMK1,ECMESSTC0,ECMESSTC1,ECMPE0,ECMPE1,ECMDTMCFG0,ECMDTMCFG1,ECMDTMCFG2 and ECMDTMCFG3
* Inputs:      None
* Outputs:     None
* Usage Notes: None
*****************************************************************************************************************************/
inline void FblWrProtdRegEcm_u32(uint32 WrVal, volatile uint32 * WrAddr)
{
    ECMPCMD1 = 0x000000A5U;
    *WrAddr = WrVal;
    *WrAddr = ~WrVal;
    *WrAddr = WrVal;
    ECMPCMD1 = 0x000000A5U;
    *WrAddr = WrVal;
    *WrAddr = ~WrVal;
    *WrAddr = WrVal;
}

#endif
