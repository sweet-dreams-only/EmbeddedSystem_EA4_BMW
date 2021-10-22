/**********************************************************************************************************************
* Copyright 2015, 2016, 2017, 2018 Nxtr
* Nxtr Confidential
*
* Module File Name  : CDD_RamMemNonRte.c
* Module Description: Implements the non-RTE functionality of CM103A RAM Memory
* Project           : CBD
* Author            : Kathleen Creager
***********************************************************************************************************************
* Version Control:
* %version:          9 %
* %derived_by:       nz3893 %
*---------------------------------------------------------------------------------------------------------------------
* Date      Rev      Author    Change Description                                                             SCR #
* --------  -------  --------  -----------------------------------------------------------------------------  -------
* 10/06/15   1       KMC       Initial Version                                                                EA4#1846
* 04/07/16   2       Selva     Updated to V2.1.0 of the FDD design                                            EA4#5097
* 04/17/16   3       Selva     Remove SetMcuDiagData from "SpiDblBitEcc"                                      EA4#5097
* 06/27/16   4       Selva     Created local functions for reducing cyclometric complexity                    EA4#6263
* 08/20/16   5       AJM       Changed SPI double bit handling from Interrupt to Polling                      EA4#6658
* 03/14/17   6       AJM       Micro Diag Error Injection                                                     EA4#6937
* 07/17/17   7       AJM       Added test case 0x130401 and aligned function FuncForLclRamInstrFetchErrInj    EA4#13350
*                              on 32 bit boundary
* 09/22/17   8       AJM       Added ECM error status clear in Ram mode classification check. Corrected       EA4#15081
*                              error id's 0x0012010A and 0x00130202                                           EA4#15447
* 07/11/18   9       BLS       Added CAN peripheral enabling check per FDD v4.6.0                             EA4#21925
*                              Added logic to wait for SPI driver to leave busy state per FDD v4.7.0          EA4#25009
**********************************************************************************************************************/
#include <v800_ghs.h>        /* for SYNCM intrinsic */
#include "Rte_CDD_RamMem.h"
#include "CDD_RamMem.h"
#include "ecc_regs.h"        /* for ECCCPU1ERROVF*, etc. */
#include "Os.h"              /* for SuspendAllInterrupts(), ResumeAllInterrupts() */
#include "NxtrMcuSuprtLib.h" /* for NxtrSwRstFromExcpn() */
#include "CDD_ExcpnHndlg.h"  /* for McuDiagc1 enumeration definitions */
#include "McuErrInj.h"
#include "Spi.h"

/* MISRA-C:2004 Rule 19.1 [NXTRDEV 19.1.1]: AUTOSAR requires deviation from this rule for Memory Mapping include statements */
/* MISRA-C:2004 Rule 11.3 [NXTRDEV 11.3.3]: Cast of an integer to a pointer is required for reading from computed addresses
                                            as needed for microcontroller diagnostics */

#define LCLRAMBASADR_CNT_U32 0xFEB80000U        /* base address of local RAM */
/* On R7F701311, local RAM actually starts at 0xFEBE0000 -- base address is 0xFEB80000 and offset starts at 0x00060000 */

#define VLDADRTESTBITMASK_CNT_U32  0xFFFE0000U  /* mask these bits to check for valid address offset */
#define VLDADRTESTRES_CNT_U32      0x00060000U  /* passing result of valid address offset test */

#define WORDLINEADRMASK_CNT_U32    0xFFFFFF1FU  /* address mask for determining addresses in same word line */

#define BNK0ERRCLRMASK_CNT_U32     0x00000001U  /* bit mask to clear bank 0 errors */
#define BNK1ERRCLRMASK_CNT_U32     0x00000002U  /* bit mask to clear bank 1 errors */
#define BNK2ERRCLRMASK_CNT_U32     0x00000004U  /* bit mask to clear bank 2 errors */
#define BNK3ERRCLRMASK_CNT_U32     0x00000008U  /* bit mask to clear bank 3 errors */

#define BNK0SNGBITERRMASK_CNT_U32  0x00000001U  /* bit mask for bank 0 single bit ECC error flag */
#define BNK1SNGBITERRMASK_CNT_U32  0x00000100U  /* bit mask for bank 1 single bit ECC error flag */
#define BNK2SNGBITERRMASK_CNT_U32  0x00010000U  /* bit mask for bank 2 single bit ECC error flag */
#define BNK3SNGBITERRMASK_CNT_U32  0x01000000U  /* bit mask for bank 3 single bit ECC error flag */

static FUNC(void, CDD_RamMem_CODE) RamFailrModClassnChk(uint32 LclRamFailrAdr_Cnt_T_u32, uint32 ErrClrMask_Cnt_T_u32, uint32 SngBitErrMask_Cnt_T_u32);
static FUNC(void, CDD_RamMem_CODE) RamMemLclRamFailrChk(uint32 LclRamFailrAdr_Cnt_T_u32);

#if(MCUDIAGCERRINJ == STD_ON)
/* Use GreenHills pragma for ensuring proper memory alignment to avoid misalignment read or write errors  */
#pragma alignfunc (4U)
static FUNC(void, CDD_RamMem_CODE) FuncForLclRamInstrFetchErrInj(void);
#endif
#define CDD_RamMem_START_SEC_CODE
#include "CDD_RamMem_MemMap.h"


/**********************************************************************************************************************
 * Name        : RamMemLclRamSngBitEcc
 * Description : Local RAM Single bit ECC exception handler callback for the CM103A RamMem Component
 * Inputs      : None
 * Outputs     : None
 * Usage Notes : Called from Mcu EI interrupt handler MCU_ECM_EIC_ISR
 **********************************************************************************************************************/
FUNC(void, CDD_RamMem_CODE) RamMemLclRamSngBitEcc(void)
{
    SuspendAllInterrupts();

    /* Identify responsible bank Check for Bank 0 */
    if(ECCCPU1ERROVF0 == 1U)
    {
        /* Bank 0 Overflow detected */

        /* Check if the saved address in the valid range */
        *Rte_Pim_LclRamFailrAdr() = (uint32)(ECCCPU1LR1STEADR0_PE1 << 4);
        RamMemLclRamFailrChk(*Rte_Pim_LclRamFailrAdr());

        /* Compute valid RAM address ('or' with base address of local RAM) */
        *Rte_Pim_LclRamFailrAdr() = *Rte_Pim_LclRamFailrAdr() | LCLRAMBASADR_CNT_U32;

        /* Overflow detected with valid address on first error; reset and save the valid address */
        NxtrSwRstFromExcpn(MCUDIAGC_LCLRAMECCSNGBITHARDFAILR, *Rte_Pim_LclRamFailrAdr());
    }

    /* No overflow check for Bank 0 single bit failure */
    else if(ECCCPU1SEDF0 == 1U)
    {
        /* Bank 0 single bit failure flagged */

        /* Check if the saved address in the valid range */
        *Rte_Pim_LclRamFailrAdr() = (uint32)(ECCCPU1LR1STEADR0_PE1 << 4);
        RamMemLclRamFailrChk(*Rte_Pim_LclRamFailrAdr());

        /* Compute valid RAM address ('or' with base address of local RAM) */
        *Rte_Pim_LclRamFailrAdr() = *Rte_Pim_LclRamFailrAdr() | LCLRAMBASADR_CNT_U32;

        /* Clear RAM Bank 0 error info only overflow flag, error status flag, and error address */
        ECCCPU1STCLR0 = 1U;

        /* Check for multibit errors or address errors disguised as single bit */
        RamFailrModClassnChk(*Rte_Pim_LclRamFailrAdr(), BNK0ERRCLRMASK_CNT_U32, BNK0SNGBITERRMASK_CNT_U32);
    }
    else
    {
        /* Do Nothing */
    }

    /* Identify responsible bank Check for Bank 1 */
    if(ECCCPU1ERROVF1 == 1U)
    {
        /* Bank 1 Overflow detected */

        /* Check if the saved address in the valid range */
        *Rte_Pim_LclRamFailrAdr() = (uint32)(ECCCPU1LR1STEADR1_PE1 << 4) | 0x04U;
        RamMemLclRamFailrChk(*Rte_Pim_LclRamFailrAdr());

        /* Compute valid RAM address ('or' with base address of local RAM) */
        *Rte_Pim_LclRamFailrAdr() = *Rte_Pim_LclRamFailrAdr() | LCLRAMBASADR_CNT_U32;

        /* Overflow detected with valid address on first error; reset and save the valid address */
        NxtrSwRstFromExcpn(MCUDIAGC_LCLRAMECCSNGBITHARDFAILR, *Rte_Pim_LclRamFailrAdr());
    }

    /* No overflow check for Bank 1 single bit failure */
    else if(ECCCPU1SEDF1 == 1U)
    {
        /* Bank 1 single bit failure flagged */

        /* Check if the saved address in the valid range */
        *Rte_Pim_LclRamFailrAdr() = (uint32)(ECCCPU1LR1STEADR1_PE1 << 4) | 0x04U;
        RamMemLclRamFailrChk(*Rte_Pim_LclRamFailrAdr());

        /* Compute valid RAM address ('or' with base address of local RAM) */
        *Rte_Pim_LclRamFailrAdr() = *Rte_Pim_LclRamFailrAdr() | LCLRAMBASADR_CNT_U32;

        /* Clear RAM Bank 1 error info only overflow flag, error status flag, and error address */
        ECCCPU1STCLR1 = 1U;

        /* Check for multibit errors or address errors disguised as single bit */
        RamFailrModClassnChk(*Rte_Pim_LclRamFailrAdr(), BNK1ERRCLRMASK_CNT_U32, BNK1SNGBITERRMASK_CNT_U32);
    }
    else
    {
        /* Do Nothing */
    }

    /* Identify responsible bank Check for Bank 2 */
    if(ECCCPU1ERROVF2 == 1U)
    {
        /* Bank 2 Overflow detected */

        /* Check if the saved address in the valid range */
        *Rte_Pim_LclRamFailrAdr() = (uint32)(ECCCPU1LR1STEADR2_PE1 << 4) | 0x08U;
        RamMemLclRamFailrChk(*Rte_Pim_LclRamFailrAdr());

        /* Compute valid RAM address ('or' with base address of local RAM) */
        *Rte_Pim_LclRamFailrAdr() = *Rte_Pim_LclRamFailrAdr() | LCLRAMBASADR_CNT_U32;

        /* Overflow detected with valid address on first error; reset and save the valid address */
        NxtrSwRstFromExcpn(MCUDIAGC_LCLRAMECCSNGBITHARDFAILR, *Rte_Pim_LclRamFailrAdr());
    }

    /* No overflow check for Bank 2 single bit failure */
    else if(ECCCPU1SEDF2 == 1U)
    {
        /* Bank 2 single bit failure flagged */

        /* Check if the saved address in the valid range */
        *Rte_Pim_LclRamFailrAdr() = (uint32)(ECCCPU1LR1STEADR2_PE1 << 4) | 0x08U;
        RamMemLclRamFailrChk(*Rte_Pim_LclRamFailrAdr());

        /* Compute valid RAM address ('or' with base address of local RAM) */
        *Rte_Pim_LclRamFailrAdr() = *Rte_Pim_LclRamFailrAdr() | LCLRAMBASADR_CNT_U32;

        /* Clear RAM Bank 2 error info only overflow flag, error status flag, and error address */
        ECCCPU1STCLR2 = 1U;

        /* Check for multibit errors or address errors disguised as single bit */
        RamFailrModClassnChk(*Rte_Pim_LclRamFailrAdr(), BNK2ERRCLRMASK_CNT_U32, BNK2SNGBITERRMASK_CNT_U32);
    }
    else
    {
        /* Do Nothing */
    }

    /* Identify responsible bank Check for Bank 3 */
    if(ECCCPU1ERROVF3 == 1U)
    {
        /* Bank 3 Overflow detected */

        /* Check if the saved address in the valid range */
        *Rte_Pim_LclRamFailrAdr() = (uint32)(ECCCPU1LR1STEADR3_PE1 << 4) | 0x0CU;
        RamMemLclRamFailrChk(*Rte_Pim_LclRamFailrAdr());

        /* Compute valid RAM address ('or' with base address of local RAM) */
        *Rte_Pim_LclRamFailrAdr() = *Rte_Pim_LclRamFailrAdr() | LCLRAMBASADR_CNT_U32;

        /* Overflow detected with valid address on first error; reset and save the valid address */
        NxtrSwRstFromExcpn(MCUDIAGC_LCLRAMECCSNGBITHARDFAILR, *Rte_Pim_LclRamFailrAdr());
    }

    /* No overflow check for Bank 3 single bit failure */
    else if(ECCCPU1SEDF3 == 1U)
    {
        /* Bank 3 single bit failure flagged */

        /* Check if the saved address in the valid range */
        *Rte_Pim_LclRamFailrAdr() = (uint32)(ECCCPU1LR1STEADR3_PE1 << 4) | 0x0CU;
        RamMemLclRamFailrChk(*Rte_Pim_LclRamFailrAdr());

        /* Compute valid RAM address ('or' with base address of local RAM) */
        *Rte_Pim_LclRamFailrAdr() = *Rte_Pim_LclRamFailrAdr() | LCLRAMBASADR_CNT_U32;

        /* Clear RAM Bank 3 error info only overflow flag, error status flag, and error address */
        ECCCPU1STCLR3 = 1U;

        /* Check for multibit errors or address errors disguised as single bit */
        RamFailrModClassnChk(*Rte_Pim_LclRamFailrAdr(), BNK3ERRCLRMASK_CNT_U32, BNK3SNGBITERRMASK_CNT_U32);
    }
    else
    {
        /* Do Nothing */
    }

    ResumeAllInterrupts();
}


/**********************************************************************************************************************
 * Name        : RamFailrModClassnChk
 * Description : For the CM103A RamMem Component
 * Inputs      : None
 * Outputs     : None
 * Usage Notes : Called from RamMemLclRamSngBitEcc
 **********************************************************************************************************************/
static FUNC(void, CDD_RamMem_CODE) RamFailrModClassnChk(uint32 LclRamFailrAdr_Cnt_T_u32, uint32 ErrClrMask_Cnt_T_u32, uint32 SngBitErrMask_Cnt_T_u32)
{
    VAR(uint32, AUTOMATIC) WordLineAdr_Cnt_T_u32;
    VAR(uint8 , AUTOMATIC) WordLineAdrIdx_Cnt_T_u08;

    WordLineAdr_Cnt_T_u32 = LclRamFailrAdr_Cnt_T_u32 & WORDLINEADRMASK_CNT_U32;

    *Rte_Pim_LclRamEccSngBitSoftFailr() = TRUE;
    for(WordLineAdrIdx_Cnt_T_u08 = 0U; (WordLineAdrIdx_Cnt_T_u08 < 8U); WordLineAdrIdx_Cnt_T_u08++)
    {
        *Rte_Pim_LclRamWordLineRead() = *(uint32 *)WordLineAdr_Cnt_T_u32;
        WordLineAdr_Cnt_T_u32 = WordLineAdr_Cnt_T_u32 + 0x00000020U;

    }
    __SYNCM(); /* Wait until read from the RAM word line is complete */

    /* Clears the following in Bank Specific RAM Status Register
        1) Overflow flag
        2) Error status flag
        3) Error address */

    ECCCPU1LRSTCLR_PE1 = ErrClrMask_Cnt_T_u32;
    /* Clear the ECM Status Register corresponding to the local RAM 1 Bit ECC Error */
    WrProtdRegEcm_u32 (0x00000004U, &ECMESSTC1);
}

/**********************************************************************************************************************
 * Name        : RamMemLclRamFailrChk
 * Description : For the CM103A RamMem Component
 * Inputs      : None
 * Outputs     : None
 * Usage Notes : Called from RamMemLclRamFailrChk
 **********************************************************************************************************************/
static FUNC(void, CDD_RamMem_CODE) RamMemLclRamFailrChk( uint32 LclRamFailrAdr_Cnt_T_u32 )
{
    if((LclRamFailrAdr_Cnt_T_u32 & VLDADRTESTBITMASK_CNT_U32) != VLDADRTESTRES_CNT_U32)
    {
        /* Invalid Address Found; reset and save the invalid address */
        NxtrSwRstFromExcpn(MCUDIAGC_LCLRAMECCSNGBITHARDFAILR, LclRamFailrAdr_Cnt_T_u32);
    }

}

#if(MCUDIAGCERRINJ == STD_ON)
/**********************************************************************************************************************
 * Name        : FuncForLclRamInstrFetchErrInj
 * Description : For the error injection in SPI
 * Inputs      : None
 * Outputs     : None
 * Usage Notes : Called from InjRamMemErr
 **********************************************************************************************************************/
static FUNC(void, CDD_RamMem_CODE) FuncForLclRamInstrFetchErrInj(void)
{
    asm( "nop" );
    asm( "nop" );
    asm( "nop" );
    asm( "nop" );
    asm( "nop" );
    asm( "nop" );
    asm( "nop" );
    asm( "nop" );
    asm( "nop" );
    asm( "nop" );
    asm( "nop" );
    asm( "nop" );
    asm( "nop" );
    asm( "nop" );
    asm( "nop" );
    asm( "nop" );
}

/**********************************************************************************************************************
 * Name        : InjRamErr
 * Description : For the error injection in SPI, CAN, FlexRay, Local RAM, DTS
 * Inputs      : None
 * Outputs     : None
 * Usage Notes : Called from McuErrInj
 **********************************************************************************************************************/
FUNC(void, CDD_RamMem_CODE) InjRamErr(void)
{
    VAR(uint32, AUTOMATIC) ErrId_Cnt_T_u32;

    /* Create an array of 4 of length 32 bits. Each of the elements will be placed in different RAM
       Banks. Based on their address, choose the index to inject the 1/2 Bit ECC faults. */
    static volatile VAR(uint32, AUTOMATIC) McuDiagcTestAry_F[4U]= {0U, 0U, 0U, 0U};

    static volatile P2VAR(uint32, AUTOMATIC, AUTOMATIC) RamBnkAddr_F = &McuDiagcTestAry_F[0];
    VAR(uint32, AUTOMATIC) RamBnk_Cnt_T_u32 = ((uint32)RamBnkAddr_F & 0x0000000FU);
    VAR(uint8, AUTOMATIC) Indx_Cnt_T_u08;
    static volatile VAR(uint32, AUTOMATIC) TempVar_F;
    VAR(uint8, AUTOMATIC) SpiBusyFlg_Cnt_T_u08 = E_NOT_OK;

    ReadErrInjReg_Oper(&ErrId_Cnt_T_u32);

    /* CSIH0 Single Bit Error */
    if(ErrId_Cnt_T_u32 == MCUERRINJ_NTC0012BIT06CASE01_CNT_U32)
    {
        /* Check whether SPI is busy */
        SpiBusyFlg_Cnt_T_u08 = Spi_DeInit();

        if(SpiBusyFlg_Cnt_T_u08 == E_OK)
        {
            /* Clear BRAMDAT2 Register */
            ClrErrInjReg_Oper();

            SuspendAllInterrupts();

            /* Turn on operation clock */
            CSIH0CTL0 = 0x80U;
            __SYNCM();

            /* Turn on Test mode */
            ECCCSIH0TMC = 0x8080U;
            __SYNCM();

            /* Set the read write pointer to 0 */
            CSIH0MRWP0 = 0x00000000U;
            __SYNCM();

            /* Write transmission data */
            CSIH0TX0W = 0xAA55U;
            __SYNCM();

            /* Reset the read write pointer to 0 because pointer gets updated after writing to CSIH0TX0W */
            CSIH0MRWP0 = 0x00000000U;
            __SYNCM();

            /* Read from SPI peripheral register */
            McuDiagcTestVar1_G = CSIH0TX0W;
            __SYNCM();

            /* Read the ECC for the corresponding data */
            McuDiagcTestVar2_G = ECCCSIH0HORD;
            __SYNCM();
            CSIH0MRWP0 = 0x00000000U;
            __SYNCM();

            /* Changing the ECC LSB to induce a 1 Bit ECC */
            McuDiagcTestVar1_G ^= 0x0001U;
            ECCCSIH0ERDB = (uint8)McuDiagcTestVar2_G;
            __SYNCM();

            /* Enable using the ERDB as the ECC input to the decoder */
            ECCCSIH0TMC = 0x8088U;
            __SYNCM();

            /* Write the 1 bit ECC error value to the transmission register */
            CSIH0TX0W = McuDiagcTestVar1_G;
            __SYNCM();

            /* Turn off test mode */
            ECCCSIH0TMC = 0x8000U;
            __SYNCM();

            /* Reset Pointer */
            CSIH0MRWP0 = 0x00000000U;
            __SYNCM();

            /* Read from the error injected transmission register */
            McuDiagcTestVar1_G = CSIH0TX0W;

            /* Reinitialize SPI drivers */
            Spi_Init(SpiDriver);

            ResumeAllInterrupts();
        }
    }

    /* Error Injection Point 2 */
    else if(ErrId_Cnt_T_u32 == MCUERRINJ_NTC0012BIT06CASE02_CNT_U32)
    {
        /* Check whether SPI is busy */
        SpiBusyFlg_Cnt_T_u08 = Spi_DeInit();

        if(SpiBusyFlg_Cnt_T_u08 == E_OK)
        {
            /* Clear BRAMDAT2 Register */
            ClrErrInjReg_Oper();

            SuspendAllInterrupts();

            /* Turn on operation clock */
            CSIH1CTL0 = 0x80U;
            __SYNCM();

            /* Turn on Test mode */
            ECCCSIH1TMC = 0x8080U;
            __SYNCM();
            CSIH1MRWP0 = 0x00000000U;
            __SYNCM();
            CSIH1TX0W = 0xAA55U;
            __SYNCM();
            CSIH1MRWP0 = 0x00000000U;
            __SYNCM();
            McuDiagcTestVar1_G = CSIH1TX0W;
            __SYNCM();
            McuDiagcTestVar2_G = ECCCSIH1HORD;
            __SYNCM();
            CSIH1MRWP0 = 0x00000000U;
            __SYNCM();
            McuDiagcTestVar1_G ^= 0x0001U;
            ECCCSIH1ERDB = (uint8)McuDiagcTestVar2_G;
            __SYNCM();
            ECCCSIH1TMC = 0x8088U;
            __SYNCM();
            CSIH1TX0W = McuDiagcTestVar1_G;
            __SYNCM();
            ECCCSIH1TMC = 0x8000U;
            __SYNCM();
            CSIH1MRWP0 = 0x00000000U;
            __SYNCM();

            McuDiagcTestVar1_G = CSIH1TX0W;

            /* Reinitialize SPI drivers */
            Spi_Init(SpiDriver);

            ResumeAllInterrupts();
        }
    }

    /* Error Injection Point 3 */
    else if(ErrId_Cnt_T_u32 == MCUERRINJ_NTC0012BIT06CASE03_CNT_U32)
    {
        /* Check whether SPI is busy */
        SpiBusyFlg_Cnt_T_u08 = Spi_DeInit();

        if(SpiBusyFlg_Cnt_T_u08 == E_OK)
        {
            /* Clear BRAMDAT2 Register */
            ClrErrInjReg_Oper();

            SuspendAllInterrupts();

            /* Turn on operation clock */
            CSIH2CTL0 = 0x80U;
            __SYNCM();

            /* Turn on Test mode */
            ECCCSIH2TMC = 0x8080U;
            __SYNCM();
            CSIH2MRWP0 = 0x00000000U;
            __SYNCM();
            CSIH2TX0W = 0xAA55U;
            __SYNCM();
            CSIH2MRWP0 = 0x00000000U;
            __SYNCM();
            McuDiagcTestVar1_G = CSIH2TX0W;
            __SYNCM();
            McuDiagcTestVar2_G = ECCCSIH2HORD;
            __SYNCM();
            CSIH2MRWP0 = 0x00000000U;
            __SYNCM();
            McuDiagcTestVar1_G ^= 0x0001U;
            ECCCSIH2ERDB = (uint8)McuDiagcTestVar2_G;
            __SYNCM();
            ECCCSIH2TMC = 0x8088U;
            __SYNCM();
            CSIH2TX0W = McuDiagcTestVar1_G;
            __SYNCM();
            ECCCSIH2TMC = 0x8000U;
            __SYNCM();
            CSIH2MRWP0 = 0x00000000U;
            __SYNCM();

            McuDiagcTestVar1_G = CSIH2TX0W;

            /* Reinitialize SPI drivers */
            Spi_Init(SpiDriver);

            ResumeAllInterrupts();
        }
    }

    /* Error Injection Point 4 */
    else if(ErrId_Cnt_T_u32 == MCUERRINJ_NTC0012BIT06CASE04_CNT_U32)
    {
        /* Check whether SPI is busy */
        SpiBusyFlg_Cnt_T_u08 = Spi_DeInit();

        if(SpiBusyFlg_Cnt_T_u08 == E_OK)
        {
            /* Clear BRAMDAT2 Register */
            ClrErrInjReg_Oper();

            SuspendAllInterrupts();

            /* Turn on operation clock */
            CSIH3CTL0 = 0x80U;
            __SYNCM();

            /* Turn on Test mode */
            ECCCSIH3TMC = 0x8080U;
            __SYNCM();
            CSIH3MRWP0 = 0x00000000U;
            __SYNCM();
            CSIH3TX0W = 0xAA55U;
            __SYNCM();
            CSIH3MRWP0 = 0x00000000U;
            __SYNCM();
            McuDiagcTestVar1_G = CSIH3TX0W;
            __SYNCM();
            McuDiagcTestVar2_G = ECCCSIH3HORD;
            __SYNCM();
            CSIH3MRWP0 = 0x00000000U;
            __SYNCM();
            McuDiagcTestVar1_G ^= 0x0001U;
            ECCCSIH3ERDB = (uint8)McuDiagcTestVar2_G;
            __SYNCM();
            ECCCSIH3TMC = 0x8088U;
            __SYNCM();
            CSIH3TX0W = McuDiagcTestVar1_G;
            __SYNCM();
            ECCCSIH3TMC = 0x8000U;
            __SYNCM();
            CSIH3MRWP0 = 0x00000000U;
            __SYNCM();

            McuDiagcTestVar1_G = CSIH3TX0W;

            /* Reinitialize SPI drivers */
            Spi_Init(SpiDriver);

            ResumeAllInterrupts();
        }
    }

    /* Error Injection Point 5 */
    else if(ErrId_Cnt_T_u32 == MCUERRINJ_NTC0017BIT01CASE01_CNT_U32)
    {
        /* Check whether SPI is busy */
        SpiBusyFlg_Cnt_T_u08 = Spi_DeInit();

        if(SpiBusyFlg_Cnt_T_u08 == E_OK)
        {
            /* Clear BRAMDAT2 Register */
            ClrErrInjReg_Oper();

            SuspendAllInterrupts();

            /* Turn on operation clock */
            CSIH0CTL0 = 0x80U;
            __SYNCM();
            ECCCSIH0TMC = 0x8080U;
            __SYNCM();
            CSIH0MRWP0 = 0x00000000U;
            __SYNCM();
            CSIH0TX0W = 0xAA55U;
            __SYNCM();
            CSIH0MRWP0 = 0x00000000U;
            __SYNCM();
            McuDiagcTestVar1_G = CSIH0TX0W;
            __SYNCM();
            McuDiagcTestVar2_G = ECCCSIH0HORD;
            __SYNCM();
            CSIH0MRWP0 = 0x00000000U;
            __SYNCM();
            McuDiagcTestVar1_G ^= 0x0003U;
            ECCCSIH0ERDB = (uint8)McuDiagcTestVar2_G;
            __SYNCM();
            ECCCSIH0TMC = 0x8088U;
            __SYNCM();
            CSIH0TX0W = McuDiagcTestVar1_G;
            __SYNCM();
            ECCCSIH0TMC = 0x8000U;
            __SYNCM();
            CSIH0MRWP0 = 0x00000000U;
            __SYNCM();

            McuDiagcTestVar1_G = CSIH0TX0W;

            /* Reinitialize SPI drivers */
            Spi_Init(SpiDriver);

            ResumeAllInterrupts();
        }
    }

    /* Error Injection Point 6 */
    else if(ErrId_Cnt_T_u32 == MCUERRINJ_NTC0018BIT01CASE01_CNT_U32)
    {
        /* Check whether SPI is busy */
        SpiBusyFlg_Cnt_T_u08 = Spi_DeInit();

        if(SpiBusyFlg_Cnt_T_u08 == E_OK)
        {
            /* Clear BRAMDAT2 Register */
            ClrErrInjReg_Oper();

            SuspendAllInterrupts();

            /* Turn on operation clock */
            CSIH1CTL0 = 0x80U;
            __SYNCM();
            ECCCSIH1TMC = 0x8080U;
            __SYNCM();
            CSIH1MRWP0 = 0x00000000U;
            __SYNCM();
            CSIH1TX0W = 0xAA55U;
            __SYNCM();
            CSIH1MRWP0 = 0x00000000U;
            __SYNCM();
            McuDiagcTestVar1_G = CSIH1TX0W;
            __SYNCM();
            McuDiagcTestVar2_G = ECCCSIH1HORD;
            __SYNCM();
            CSIH1MRWP0 = 0x00000000U;
            __SYNCM();
            McuDiagcTestVar1_G ^= 0x0003U;
            ECCCSIH1ERDB = (uint8)McuDiagcTestVar2_G;
            __SYNCM();
            ECCCSIH1TMC = 0x8088U;
            __SYNCM();
            CSIH1TX0W = McuDiagcTestVar1_G;
            __SYNCM();
            ECCCSIH1TMC = 0x8000U;
            __SYNCM();
            CSIH1MRWP0 = 0x00000000U;
            __SYNCM();

            McuDiagcTestVar1_G = CSIH1TX0W;

            /* Reinitialize SPI drivers */
            Spi_Init(SpiDriver);

            ResumeAllInterrupts();
        }
    }

    /* Error Injection Point 7 */
    else if(ErrId_Cnt_T_u32 == MCUERRINJ_NTC0019BIT01CASE01_CNT_U32)
    {
        /* Check whether SPI is busy */
        SpiBusyFlg_Cnt_T_u08 = Spi_DeInit();

        if(SpiBusyFlg_Cnt_T_u08 == E_OK)
        {
            /* Clear BRAMDAT2 Register */
            ClrErrInjReg_Oper();

            SuspendAllInterrupts();

            /* Turn on operation clock */
            CSIH2CTL0 = 0x80U;
            __SYNCM();
            ECCCSIH2TMC = 0x8080U;
            __SYNCM();
            CSIH2MRWP0 = 0x00000000U;
            __SYNCM();
            CSIH2TX0W = 0xAA55U;
            __SYNCM();
            CSIH2MRWP0 = 0x00000000U;
            __SYNCM();
            McuDiagcTestVar1_G = CSIH2TX0W;
            __SYNCM();
            McuDiagcTestVar2_G = ECCCSIH2HORD;
            __SYNCM();
            CSIH2MRWP0 = 0x00000000U;
            __SYNCM();
            McuDiagcTestVar1_G ^= 0x0003U;
            ECCCSIH2ERDB = (uint8)McuDiagcTestVar2_G;
            __SYNCM();
            ECCCSIH2TMC = 0x8088U;
            __SYNCM();
            CSIH2TX0W = McuDiagcTestVar1_G;
            __SYNCM();
            ECCCSIH2TMC = 0x8000U;
            __SYNCM();
            CSIH2MRWP0 = 0x00000000U;
            __SYNCM();

            McuDiagcTestVar1_G = CSIH2TX0W;

            /* Reinitialize SPI drivers */
            Spi_Init(SpiDriver);

            ResumeAllInterrupts();
        }
    }

    /* Error Injection Point 8 */
    else if(ErrId_Cnt_T_u32 == MCUERRINJ_NTC001ABIT01CASE01_CNT_U32)
    {
        /* Check whether SPI is busy */
        SpiBusyFlg_Cnt_T_u08 = Spi_DeInit();

        if(SpiBusyFlg_Cnt_T_u08 == E_OK)
        {
            /* Clear BRAMDAT2 Register */
            ClrErrInjReg_Oper();

            SuspendAllInterrupts();

            /* Turn on operation clock */
            CSIH3CTL0 = 0x80U;
            __SYNCM();
            ECCCSIH3TMC = 0x8080U;
            __SYNCM();
            CSIH3MRWP0 = 0x00000000U;
            __SYNCM();
            CSIH3TX0W = 0xAA55U;
            __SYNCM();
            CSIH3MRWP0 = 0x00000000U;
            __SYNCM();
            McuDiagcTestVar1_G = CSIH3TX0W;
            __SYNCM();
            McuDiagcTestVar2_G = ECCCSIH3HORD;
            __SYNCM();
            CSIH3MRWP0 = 0x00000000U;
            __SYNCM();
            McuDiagcTestVar1_G ^= 0x0003U;
            ECCCSIH3ERDB = (uint8)McuDiagcTestVar2_G;
            __SYNCM();
            ECCCSIH3TMC = 0x8088U;
            __SYNCM();
            CSIH3TX0W = McuDiagcTestVar1_G;
            __SYNCM();
            ECCCSIH3TMC = 0x8000U;
            __SYNCM();
            CSIH3MRWP0 = 0x00000000U;
            __SYNCM();

            McuDiagcTestVar1_G = CSIH3TX0W;

            /* Reinitialize SPI drivers */
            Spi_Init(SpiDriver);

            ResumeAllInterrupts();
        }
    }

    /* Error Injection Point 9 */
    else if(ErrId_Cnt_T_u32 == MCUERRINJ_NTC0012BIT04CASE01_CNT_U32)
    {
        /* Clear BRAMDAT2 Register */
        ClrErrInjReg_Oper();

        SuspendAllInterrupts();

        /* Wait while CAN RAM initialization is ongoing  */
        while((RSCAN0GSTS & 0x00000008U) != 0)
        {
            /* Do Nothing */
        }

        /* Check if CAN Channel is enabled */
        if(RSCAN0GSLPSTS != 0)
        {
            /* RSCAN was not enabled; switch to global reset mode
               to enable clocks before going to global test mode;
               switch to global mode -- bits 2:0 of RSCAN0GCTR = 0b001 */
            RSCAN0GCTR = (RSCAN0GCTR & (~(uint32)0x07U)) | (uint32)0x01U;
        }
        else
        {
            /* RSCAN is already in operate mode by the time this test is run
               so no need to enable */
        }

        /* Switch to global test mode -- bits 2:0 of RSCAN0GCTR = 0b010 */
        RSCAN0GCTR = (RSCAN0GCTR & (~(uint32)0x07U)) | (uint32)0x02U;

        /* Wait for global test mode in status register */
        while((RSCAN0GSTS & (uint32)0x02U) == 0U)
        {
            /* Do Nothing */
        }

        /* Enable the RAM test mode */
        /* Write protection release sequence to RSCAN0GLOCKK */
        RSCAN0GLOCKK = (uint32)0x7575U;
        RSCAN0GLOCKK = (uint32)0x8A8AU;

        /* Set RTME bit in RSCAN0GTSTCTR */
        RSCAN0GTSTCTR = (uint32)0x04U;
        __SYNCM();

        /* Waiting to make sure test mode write has completed same as while((RSCAN0GTSTCTR) == 0)  */
        while((RSCAN0GTSTCTR & 0x4UL) == 0U)
        {
        }

        /* Enable Test Mode, Generate RAM Read Cycle,  */
        /* TMC.ECREOS to 1 : TRC.ERDB[6:0] is output to the ECC redundant bit output */
        /* "The TRC.ERDB[6:0] value is input to the ECC redundant bit area to the decoder circuit." */
        ECCRCAN0TMC = (uint16)0x8088U;
        __SYNCM();
        McuDiagcTestVar1_G = (uint32)0x00000000U;

        /* TempEcc = 0x00; test ECC value is zero */
        McuDiagcTestVar2_G = ECCRCAN0TRC;
        McuDiagcTestVar2_G &= 0xFFFFFF00U;
        McuDiagcTestVar2_G |= 0x40U;
        ECCRCAN0TRC = McuDiagcTestVar2_G;
        __SYNCM();

        /* Test pattern data word  */
        RSCAN0RPGACC40 = McuDiagcTestVar1_G;

        /* Disable test mode */
        ECCRCAN0TMC = (uint16)0x8000U;
        __SYNCM();

        McuDiagcTestVar1_G = RSCAN0RPGACC40;

        /* Switch to global operating mode -- bits 2:0 of RSCAN0GCTR = 0b000 */
        RSCAN0GCTR = RSCAN0GCTR & (~(uint32)0x07U);
        ResumeAllInterrupts();
    }

    /* Error Injection Point 10 */
    else if(ErrId_Cnt_T_u32 == MCUERRINJ_NTC001BBIT01CASE01_CNT_U32)
    {
        /* Clear BRAMDAT2 Register */
        ClrErrInjReg_Oper();

        SuspendAllInterrupts();

        /* Wait while CAN RAM initialization is ongoing  */
        while((RSCAN0GSTS & 0x00000008U) != 0)
        {
            /* Do Nothing */
        }

        /* Check if CAN Channel is enabled */
        if(RSCAN0GSLPSTS != 0)
        {
            /* RSCAN was not enabled; switch to global reset mode
               to enable clocks before going to global test mode;
               switch to global mode -- bits 2:0 of RSCAN0GCTR = 0b001 */
            RSCAN0GCTR = (RSCAN0GCTR & (~(uint32)0x07U)) | (uint32)0x01U;
        }
        else
        {
            /* RSCAN is already in operate mode by the time this test is run
               so no need to enable */
        }

        /* Switch to global test mode -- bits 2:0 of RSCAN0GCTR = 0b010 */
        RSCAN0GCTR = (RSCAN0GCTR & (~ (uint32)0x07U)) | (uint32)0x02U;

        /* Wait for global test mode in status register */
        while((RSCAN0GSTS & (uint32)0x02U) == 0U)
        {
            /* Do Nothing */
        }

        /* Enable the RAM test mode */
        /* Write protection release sequence to RSCAN0GLOCKK */
        RSCAN0GLOCKK = (uint32)0x7575U;
        RSCAN0GLOCKK = (uint32)0x8A8AU;

        /* Set RTME bit in RSCAN0GTSTCTR */
        RSCAN0GTSTCTR = (uint32)0x04U;
        __SYNCM();

        /* Waiting to make sure test mode write has completed same as while((RSCAN0GTSTCTR) == 0) */
        while((RSCAN0GTSTCTR & 0x4UL) == 0U)
        {
            /* Do Nothing */
        }

        /* Enable Test Mode, Generate RAM Read Cycle */
        /* TMC.ECREOS to 1: TRC.ERDB[6:0] is output to the ECC redundant bit output */
        /* The TRC.ERDB [6:0] value is input to the ECC redundant bit area to the decoder circuit." */
        ECCRCAN0TMC = (uint16)0x8088U;
        __SYNCM();
        McuDiagcTestVar1_G = (uint32)0x00000003U;

        /* TempEcc = 0x00; test ECC value is zero */
        McuDiagcTestVar2_G = ECCRCAN0TRC;
        McuDiagcTestVar2_G &= 0xFFFFFF00U;

        /* McuDiagcTestVar2_G |= TempEcc; commented out OR with zero */
        ECCRCAN0TRC = McuDiagcTestVar2_G;
        __SYNCM();

        /* Test pattern data word */
        RSCAN0RPGACC40 = McuDiagcTestVar1_G;

        /* Disable test mode */
        ECCRCAN0TMC = (uint16)0x8000U;
        __SYNCM();

        McuDiagcTestVar1_G = RSCAN0RPGACC40;

        /* Switch to global operating mode -- bits 2:0 of RSCAN0GCTR = 0b000 */
        RSCAN0GCTR = RSCAN0GCTR & (~(uint32)0x07U);
        ResumeAllInterrupts();
    }

    /* FR Message RAM 1 Bit ECC Error Injection */
    else if(ErrId_Cnt_T_u32 == MCUERRINJ_NTC0012BIT05CASE01_CNT_U32)
    {
        /* Clear BRAMDAT2 Register */
        ClrErrInjReg_Oper();

        /* FROC.OEP = 0, OE is unprotected */
        FLXA0OEP = 0U;

        /* Need to enable FLX sample clock operation enabled */
        FLXA0OE = 1U;

        /* wait for enable operation to complete */
        while(FLXA0OS == 0U)
        {
        }

        /* POC Busy Flag
           0 POC not busy, FLXAnFRSUCC1.CMD writeable
           1 POC is busy, bit FLXAnFRSUCC1.CMD locked */
        while(FLXA0PBSY == 1U)
        {
        }

        /**********************************************************/
        /* Transfer data by host from input buffer to msg RAM     */
        /**********************************************************/

        /* IBSYS = 1, Transfer between IBF Shadow and Message RAM in progress */
        while(FLXA0IBSYS == 1U)
        {
        }

        ECCFLX0TMC = 0x8088u;
        __SYNCM();

        ECCFLX0ERDB = 0x40U;

        /* Write data section 1 to 64 regs FLXA0FRWRDS1 to FLXA0FRWRDS64
           Data words to be transferred to the data section of the specified message buffer. */
        FLXA0FRWRDS1 = 0x00000000U;
        FLXA0FRWRDS2 = 0x00000000U;
        FLXA0FRWRDS3 = 0x00000000U;
        FLXA0FRWRDS4 = 0x00000000U;

        /* FRIBCM reg */
        FLXA0STXRH = 0U;
        FLXA0LDSH  = 1U; /* load data section only */

        /* Demand data transfer to target message buffer */
        FLXA0IBRH = 0U;

        /* Request while transfer between IBF Shadow and Message RAM in progress */
        while(FLXA0IBSYS == 1U)
        {
        }

        ECCFLX0TMC = 0x8000u;
        __SYNCM();


        /***************************************************************************************/
        /* Transfer data by host from msg RAM to output buffer                                 */
        /* Read from msg RAM that contains incorrect ECC bits will cause 1 bit ECC error error */
        /***************************************************************************************/

        /* Transfer data by host from input buffer to msg RAM */
        while(FLXA0OBSYS == 1U)
        {
        }

        /* Data section selected for transfer from Message RAM to Output Buffer */
        FLXA0RDSS = 1U;

        /* Output Buffer Request Shadow Bit */
        FLXA0OBRS = 0U;

        /* Transfer to OBF Shadow requested */
        FLXA0REQ = 1U;

        while(FLXA0OBSYS == 1U)
        {
        }

        /* Swap OBF Shadow and OBF Host */
        FLXA0VIEW = 1U;
    }

    /* FR Message RAM 2 Bit ECC Error Injection */
    else if(ErrId_Cnt_T_u32 == MCUERRINJ_NTC001DBIT01CASE01_CNT_U32)
    {
        /* Clear BRAMDAT2 Register */
        ClrErrInjReg_Oper();

        /* FROC.OEP = 0, OE is unprotected */
        FLXA0OEP = 0U;

        /* Need to enable FLX sample clock operation enabled */
        FLXA0OE = 1U;

        /* Wait for enable operation to complete */
        while(FLXA0OS == 0U)
        {
        }

        /* POC Busy Flag
           0 POC not busy, FLXAnFRSUCC1.CMD writeable
           1 POC is busy, bit FLXAnFRSUCC1.CMD locked */
        while(FLXA0PBSY == 1U)
        {
        }

        /**********************************************************/
        /* Transfer data by host from input buffer to msg RAM     */
        /**********************************************************/

        /* IBSYS = 1, Transfer between IBF Shadow and Message RAM in progress */
        while(FLXA0IBSYS == 1U)
        {
        }

        /* Enable Test Mode
           Set ECC Redundant Bit Output Data To Substitution Buffer */
        ECCFLX0TMC = 0x8088u;
        __SYNCM();

        ECCFLX0ERDB = 0x00U;
        /* Write Substitution Buffer data section
           1 to 64 regs FLXA0FRWRDS1 to FLXA0FRWRDS64
           Data words to be transferred to the data section of the specified message buffer. */
        FLXA0FRWRDS1 = 0x00000003U;
        FLXA0FRWRDS2 = 0x00000003U;
        FLXA0FRWRDS3 = 0x00000003U;
        FLXA0FRWRDS4 = 0x00000003U;

        /* FRIBCM reg */
        FLXA0STXRH = 0U;

        /* Load data section only */
        FLXA0LDSH = 1U;

        /* Demand data transfer to target message buffer */
        FLXA0IBRH = 0U;

        /* Request while transfer between IBF Shadow and Message RAM in progress */
        while(FLXA0IBSYS == 1U)
        {
        }

        /* Disable Test Mode */
        ECCFLX0TMC = 0x8000u;
        __SYNCM();

        /**************************************************************************************/
        /* Transfer data by host from msg RAM to output buffer                                */
        /* Read from msg RAM that contains incorrect ECC bits will cause 1 bit ECC error error*/
        /**************************************************************************************/

        /* Transfer data by host from input buffer to msg RAM */
        while(FLXA0OBSYS == 1U)
        {
            /* Transfer between Message RAM and OBF Shadow in progress */
        }

        /* Data section selected for transfer from Message RAM to Output Buffer */
        FLXA0RDSS = 1U;

        /* Output Buffer Request Shadow Bit */
        FLXA0OBRS = 0U;

        /* Transfer to OBF Shadow requested */
        FLXA0REQ = 1U;

        while(FLXA0OBSYS == 1U)
        {
            /* Transfer between Message RAM and OBF Shadow in progress */
        }

        /* Swap OBF Shadow and OBF Host */
        FLXA0VIEW = 1U;
    }

    /* DTS Double Bit ECC Fault Injection */
    else if(ErrId_Cnt_T_u32 == MCUERRINJ_NTC0016BIT01CASE01_CNT_U32)
    {
        /* Clear BRAMDAT2 Register */
        ClrErrInjReg_Oper();
        SuspendAllInterrupts();

        /* DTRTSCTL.ECCTST = 1, test mode enabled */
        /* DTRTSCTL.DATSEL = 1, ECC bit value specified by DTRTWDAT reg */
        DMASSDTRTSCTL = 0x40000003U;
        __SYNCM();

        /* Write ECC bits values to DTRTWDAT */
        DMASSDTRTWDAT = 0x00000003U;

        /* Write test pattern data in any location in DTSRAM */
        DMASSDTSA000 = 0X00000003U;
        __SYNCM();

        /* DTRTSCTL.ECCTST = 0, test mode disabled */
        DMASSDTRTSCTL = 0x40000000U;
        __SYNCM();
        ResumeAllInterrupts();

        /* Read from same DTSRAM address that test pattern was written to */
        /* This read operation should cause ECC error */
        McuDiagcTestVar1_G = DMASSDTSA000;
    }

    /* DTS Single Bit ECC Fault Injection */
    else if(ErrId_Cnt_T_u32 == MCUERRINJ_NTC0012BIT03CASE01_CNT_U32)
    {
        /* Clear BRAMDAT2 Register */
        ClrErrInjReg_Oper();
        SuspendAllInterrupts();

        /* DTRTSCTL.ECCTST = 1, test mode enabled */
        /* DTRTSCTL.DATSEL = 1, ECC bit value specified by DTRTWDAT reg */
        DMASSDTRTSCTL = 0x40000003U;
        __SYNCM();

        /* Write ECC bits values to DTRTWDAT*/
        DMASSDTRTWDAT = 0x00000001U;

        /* Write test pattern data in any location in DTSRAM*/
        DMASSDTSA000 = 0X00000003U;
        __SYNCM();

        /* DTRTSCTL.ECCTST = 0, test mode disabled */
        DMASSDTRTSCTL = 0x40000000U;
        __SYNCM();
        ResumeAllInterrupts();

        /* Read from same DTSRAM address that test pattern was written to*/
        /* This read operation should cause ECC error */
        McuDiagcTestVar1_G = DMASSDTSA000;
    }
    else if(ErrId_Cnt_T_u32 == MCUERRINJ_NTC0012BIT00CASE01_CNT_U32)
    {
        /* Clear BRAMDAT2 Register */
        ClrErrInjReg_Oper();

        SuspendAllInterrupts();

        switch(RamBnk_Cnt_T_u32)
        {
            case 0x0U:
                Indx_Cnt_T_u08 = 0U;
            break;

            case 0x4U:
                Indx_Cnt_T_u08 = 3U;
            break;

            case 0x8U:
                Indx_Cnt_T_u08 = 2U;
            break;

            case 0xCU:
                Indx_Cnt_T_u08 = 1U;
            break;

            default:
                Indx_Cnt_T_u08 = 0U;
            break;
        }

        /* Set (PROT[1:0]) = (0, 1) when writing to LRTSTCTL. DATSEL = 1, ECCTST = 1 */
        ECCCPU1LRTSTCTL_PE1 = 0x00004003U;
        __SYNCM();

        /* Inject 1 Bit Faulty Data in ECC */
        McuDiagcTestAry_F[Indx_Cnt_T_u08] = 0x43U;
        __SYNCM();

        /* Set (PROT[1:0]) = (0, 1) when writing to LRTSTCTL. DATSEL = 0, ECCTST = 1 */
        ECCCPU1LRTSTCTL_PE1 = 0x00004002U;
        __SYNCM();
        McuDiagcTestAry_F[Indx_Cnt_T_u08] = 0x00000000U;
        __SYNCM();

        /* Set (PROT[1:0]) = (0, 1) when writing to LRTSTCTL. DATSEL = 0, ECCTST = 0 */
        ECCCPU1LRTSTCTL_PE1 = 0x00004000U;
        __SYNCM();

        McuDiagcTestVar1_G = McuDiagcTestAry_F[Indx_Cnt_T_u08];
        __SYNCM();

        /* Enable all the EI Interrupts */
        ResumeAllInterrupts();
    }

    /* Bank1 Error from CPU Read */
    else if(ErrId_Cnt_T_u32 == MCUERRINJ_NTC0012BIT00CASE02_CNT_U32)
    {
        /* Clear BRAMDAT2 Register */
        ClrErrInjReg_Oper();

        SuspendAllInterrupts();

        switch(RamBnk_Cnt_T_u32)
        {
            case 0x0U:
                Indx_Cnt_T_u08 = 1U;
            break;

            case 0x4U:
                Indx_Cnt_T_u08 = 0U;
            break;

            case 0x8U:
                Indx_Cnt_T_u08 = 3U;
            break;

            case 0xCU:
                Indx_Cnt_T_u08 = 2U;
            break;

            default:
                Indx_Cnt_T_u08 = 0U;
            break;
        }

        /* Set (PROT[1:0]) = (0, 1) when writing to LRTSTCTL. DATSEL = 1, ECCTST = 1 */
        ECCCPU1LRTSTCTL_PE1 = 0x00004003U;
        __SYNCM();

        /* Inject 1 Bit Faulty Data in ECC */
        McuDiagcTestAry_F[Indx_Cnt_T_u08] = 0x43U;
        __SYNCM();

        /* Set (PROT[1:0]) = (0, 1) when writing to LRTSTCTL. DATSEL = 0, ECCTST = 1 */
        ECCCPU1LRTSTCTL_PE1 = 0x00004002U;
        __SYNCM();
        McuDiagcTestAry_F[Indx_Cnt_T_u08] = 0x00000000U;
        __SYNCM();

        /* Set (PROT[1:0]) = (0, 1) when writing to LRTSTCTL. DATSEL = 0, ECCTST = 0 */
        ECCCPU1LRTSTCTL_PE1 = 0x00004000U;
        __SYNCM();

        McuDiagcTestVar1_G = McuDiagcTestAry_F[Indx_Cnt_T_u08];
        __SYNCM();

        /* Enable all the EI Interrupts */
        ResumeAllInterrupts();
    }

    /* Bank2 Error from CPU Read */
    else if(ErrId_Cnt_T_u32 == MCUERRINJ_NTC0012BIT00CASE03_CNT_U32)
    {
        /* Clear BRAMDAT2 Register */
        ClrErrInjReg_Oper();

        SuspendAllInterrupts();
        switch(RamBnk_Cnt_T_u32)
        {
            case 0x0U:
                Indx_Cnt_T_u08 = 2U;
            break;

            case 0x4U:
                Indx_Cnt_T_u08 = 1U;
            break;

            case 0x8U:
                Indx_Cnt_T_u08 = 0U;
            break;

            case 0xCU:
                Indx_Cnt_T_u08 = 3U;
            break;

            default:
                Indx_Cnt_T_u08 = 0U;
            break;
        }

        /* Set (PROT[1:0]) = (0, 1) when writing to LRTSTCTL. DATSEL = 1, ECCTST = 1 */
        ECCCPU1LRTSTCTL_PE1 = 0x00004003U;
        __SYNCM();

        /* Inject 1 Bit Faulty Data in ECC */
        McuDiagcTestAry_F[Indx_Cnt_T_u08] = 0x43U;
        __SYNCM();

        /* Set (PROT[1:0]) = (0, 1) when writing to LRTSTCTL. DATSEL = 0, ECCTST = 1 */
        ECCCPU1LRTSTCTL_PE1 = 0x00004002U;
        __SYNCM();
        McuDiagcTestAry_F[Indx_Cnt_T_u08] = 0x00000000U;
        __SYNCM();

        /* Set (PROT[1:0]) = (0, 1) when writing to LRTSTCTL. DATSEL = 0, ECCTST = 0 */
        ECCCPU1LRTSTCTL_PE1 = 0x00004000U;
        __SYNCM();

        McuDiagcTestVar1_G = McuDiagcTestAry_F[Indx_Cnt_T_u08];
        __SYNCM();

        /* Enable all the EI Interrupts */
        ResumeAllInterrupts();
    }

    /* Bank3 Error from CPU Read */
    else if(ErrId_Cnt_T_u32 == MCUERRINJ_NTC0012BIT00CASE04_CNT_U32)
    {
        /* Clear BRAMDAT2 Register */
        ClrErrInjReg_Oper();

        SuspendAllInterrupts();
        switch(RamBnk_Cnt_T_u32)
        {
            case 0x0U:
                Indx_Cnt_T_u08 = 3U;
            break;

            case 0x4U:
                Indx_Cnt_T_u08 = 2U;
            break;

            case 0x8U:
                Indx_Cnt_T_u08 = 1U;
            break;

            case 0xCU:
                Indx_Cnt_T_u08 = 0U;
            break;

            default:
                Indx_Cnt_T_u08 = 0U;
            break;
        }

        /* Set (PROT[1:0]) = (0, 1) when writing to LRTSTCTL. DATSEL = 1, ECCTST = 1 */
        ECCCPU1LRTSTCTL_PE1 = 0x00004003U;
        __SYNCM();

        /* Inject 1 Bit Faulty Data in ECC */
        McuDiagcTestAry_F[Indx_Cnt_T_u08] = 0x43U;
        __SYNCM();

        /* Set (PROT[1:0]) = (0, 1) when writing to LRTSTCTL. DATSEL = 0, ECCTST = 1 */
        ECCCPU1LRTSTCTL_PE1 = 0x00004002U;
        __SYNCM();
        McuDiagcTestAry_F[Indx_Cnt_T_u08] = 0x00000000U;
        __SYNCM();

        /* Set (PROT[1:0]) = (0, 1) when writing to LRTSTCTL. DATSEL = 0, ECCTST = 0 */
        ECCCPU1LRTSTCTL_PE1 = 0x00004000U;
        __SYNCM();

        McuDiagcTestVar1_G = McuDiagcTestAry_F[Indx_Cnt_T_u08];
        __SYNCM();

        /* Enable all the EI Interrupts */
        ResumeAllInterrupts();
    }

    /* Bank 0 Error from DMA Read */
    else if(ErrId_Cnt_T_u32 == MCUERRINJ_NTC0012BIT00CASE05_CNT_U32)
    {
        /* Clear BRAMDAT2 Register */
        ClrErrInjReg_Oper();

        SuspendAllInterrupts();
        switch(RamBnk_Cnt_T_u32)
        {
            case 0x0U:
                Indx_Cnt_T_u08 = 0U;
            break;

            case 0x4U:
                Indx_Cnt_T_u08 = 3U;
            break;

            case 0x8U:
                Indx_Cnt_T_u08 = 2U;
            break;

            case 0xCU:
                Indx_Cnt_T_u08 = 1U;
            break;

            default:
                Indx_Cnt_T_u08 = 0U;
            break;
        }

        /* Set (PROT[1:0]) = (0, 1) when writing to LRTSTCTL. DATSEL = 1, ECCTST = 1 */
        ECCCPU1LRTSTCTL_PE1 = 0x00004003U;
        __SYNCM();

        /* Inject 1 Bit Faulty Data in ECC */
        McuDiagcTestAry_F[Indx_Cnt_T_u08] = 0x43U;
        __SYNCM();

        /* Set (PROT[1:0]) = (0, 1) when writing to LRTSTCTL. DATSEL = 0, ECCTST = 1 */
        ECCCPU1LRTSTCTL_PE1 = 0x00004002U;
        __SYNCM();
        McuDiagcTestAry_F[Indx_Cnt_T_u08] = 0x00000000U;
        __SYNCM();

        /* Set (PROT[1:0]) = (0, 1) when writing to LRTSTCTL. DATSEL = 0, ECCTST = 0 */
        ECCCPU1LRTSTCTL_PE1 = 0x00004000U;
        __SYNCM();

        McuDiagcTestVar1_G = McuDiagcTestAry_F[Indx_Cnt_T_u08];
        __SYNCM();

        /* Set up DMA Channel 10 to do a DMA transfer from CF to LRAM as follows */
        DMASSDCEN8  =  0x00000000U;
        DMASSDM10CM = ((uint32)MCUERRINJ_CPU1PEID_CNT_U32           << 4)
                    | ((uint32)MCUERRINJ_LCLRAMTOLCLRAMSPID_CNT_U32 << 2)
                    | ((uint32)MCUERRINJ_USRMODDI_CNT_U32           << 1);
        DMASSDSA8   = (uint32)(&(McuDiagcTestAry_F[Indx_Cnt_T_u08])); /* Local RAM ECC Error Address */
        DMASSDDA8   = (uint32)(&(DmaWrDataVar_G)); /* Local RAM Address */
        DMASSDTC8   = ((uint32)0x00U << 16)
                    | ((uint32)0x01U <<  0);
        DMASSDTCT8  = ((uint32)0x00U << 27)
                    | ((uint32)0x00U << 26)
                    | ((uint32)0x00U << 18)
                    | ((uint32)0x00U << 16)
                    | ((uint32)0x00U << 15)
                    | ((uint32)0x00U << 14)
                    | ((uint32)0x01U << 13)
                    | ((uint32)0x00U << 11)
                    | ((uint32)0x00U <<  9)
                    | ((uint32)0x00U <<  7)
                    | ((uint32)0x00U <<  5)
                    | ((uint32)0x02U <<  2)
                    | ((uint32)0x01U <<  0);

        DMASSDTFR8  = ((uint32)   0U <<  1)
                    | ((uint32)   0U <<  0);

        /* Enabling DMA channel should trigger the DMA transfer */
        DMASSDCEN8  = 0x00000001U;
        DMASSDCSTS8 = 0x00000001U;

        __SYNCM();

        /* Enable all the EI Interrupts */
        ResumeAllInterrupts();
    }

    /* Bank 1 Error from DMA Read */
    else if(ErrId_Cnt_T_u32 == MCUERRINJ_NTC0012BIT00CASE06_CNT_U32)
    {
        /* Clear BRAMDAT2 Register */
        ClrErrInjReg_Oper();

        SuspendAllInterrupts();
        switch(RamBnk_Cnt_T_u32)
        {
            case 0x0U:
                Indx_Cnt_T_u08 = 1U;
            break;

            case 0x4U:
                Indx_Cnt_T_u08 = 0U;
            break;

            case 0x8U:
                Indx_Cnt_T_u08 = 3U;
            break;

            case 0xCU:
                Indx_Cnt_T_u08 = 2U;
            break;

            default:
                Indx_Cnt_T_u08 = 0U;
            break;
        }
        /* Set (PROT[1:0]) = (0, 1) when writing to LRTSTCTL. DATSEL = 1, ECCTST = 1 */
        ECCCPU1LRTSTCTL_PE1 = 0x00004003U;
        __SYNCM();

        /* Inject 1 Bit Faulty Data in ECC */
        McuDiagcTestAry_F[Indx_Cnt_T_u08] = 0x43U;
        __SYNCM();

        /* Set (PROT[1:0]) = (0, 1) when writing to LRTSTCTL. DATSEL = 0, ECCTST = 1 */
        ECCCPU1LRTSTCTL_PE1 = 0x00004002U;
        __SYNCM();
        McuDiagcTestAry_F[Indx_Cnt_T_u08] = 0x00000000U;
        __SYNCM();

        /* Set (PROT[1:0]) = (0, 1) when writing to LRTSTCTL. DATSEL = 0, ECCTST = 0 */
        ECCCPU1LRTSTCTL_PE1 = 0x00004000U;
        __SYNCM();

        McuDiagcTestVar1_G = McuDiagcTestAry_F[Indx_Cnt_T_u08];
        __SYNCM();

        /* Set up DMA Channel 10 to do a DMA transfer from CF to LRAM as follows */
        DMASSDCEN8  = 0x00000000U;
        DMASSDM10CM = ((uint32)MCUERRINJ_CPU1PEID_CNT_U32           << 4)
                    | ((uint32)MCUERRINJ_LCLRAMTOLCLRAMSPID_CNT_U32 << 2)
                    | ((uint32)MCUERRINJ_USRMODDI_CNT_U32           << 1);
        DMASSDSA8   = (uint32)(&(McuDiagcTestAry_F[Indx_Cnt_T_u08])); /* Local RAM ECC Error Address */
        DMASSDDA8   = (uint32)(&(DmaWrDataVar_G)); /* Local RAM Address */
        DMASSDTC8   = ((uint32)0x00U << 16)
                    | ((uint32)0x01U << 0);
        DMASSDTCT8  = ((uint32)0x00U << 27)
                    | ((uint32)0x00U << 26)
                    | ((uint32)0x00U << 18)
                    | ((uint32)0x00U << 16)
                    | ((uint32)0x00U << 15)
                    | ((uint32)0x00U << 14)
                    | ((uint32)0x01U << 13)
                    | ((uint32)0x00U << 11)
                    | ((uint32)0x00U <<  9)
                    | ((uint32)0x00U <<  7)
                    | ((uint32)0x00U <<  5)
                    | ((uint32)0x02U <<  2)
                    | ((uint32)0x01U <<  0);

        DMASSDTFR8  = ((uint32)   0U <<  1)
                    | ((uint32)   0U <<  0);

        /* Enabling DMA channel should trigger the DMA transfer */
        DMASSDCEN8  = 0x00000001U;
        DMASSDCSTS8 = 0x00000001U;

        __SYNCM();

        /* Enable all the EI Interrupts */
        ResumeAllInterrupts();
    }

    /* Bank 2 Error from DMA Read */
    else if(ErrId_Cnt_T_u32 == MCUERRINJ_NTC0012BIT00CASE07_CNT_U32)
    {
        /* Clear BRAMDAT2 Register */
        ClrErrInjReg_Oper();

        SuspendAllInterrupts();

        switch(RamBnk_Cnt_T_u32)
        {
            case 0x0U:
                Indx_Cnt_T_u08 = 2U;
            break;

            case 0x4U:
                Indx_Cnt_T_u08 = 1U;
            break;

            case 0x8U:
                Indx_Cnt_T_u08 = 0U;
            break;

            case 0xCU:
                Indx_Cnt_T_u08 = 3U;
            break;

            default:
                Indx_Cnt_T_u08 = 0U;
            break;
        }
        /* Set (PROT[1:0]) = (0, 1) when writing to LRTSTCTL. DATSEL = 1, ECCTST = 1 */
        ECCCPU1LRTSTCTL_PE1 = 0x00004003U;
        __SYNCM();

        /* Inject 1 Bit Faulty Data in ECC */
        McuDiagcTestAry_F[Indx_Cnt_T_u08] = 0x43U;
        __SYNCM();

        /* Set (PROT[1:0]) = (0, 1) when writing to LRTSTCTL. DATSEL = 0, ECCTST = 1 */
        ECCCPU1LRTSTCTL_PE1 = 0x00004002U;
        __SYNCM();
        McuDiagcTestAry_F[Indx_Cnt_T_u08] = 0x00000000U;
        __SYNCM();

        /* Set (PROT[1:0]) = (0, 1) when writing to LRTSTCTL. DATSEL = 0, ECCTST = 0 */
        ECCCPU1LRTSTCTL_PE1 = 0x00004000U;
        __SYNCM();

        McuDiagcTestVar1_G = McuDiagcTestAry_F[Indx_Cnt_T_u08];
        __SYNCM();

        /* Set up DMA Channel 10 to do a DMA transfer from CF to LRAM as follows */
        DMASSDCEN8  = 0x00000000U;
        DMASSDM10CM = ((uint32)MCUERRINJ_CPU1PEID_CNT_U32           << 4)
                    | ((uint32)MCUERRINJ_LCLRAMTOLCLRAMSPID_CNT_U32 << 2)
                    | ((uint32)MCUERRINJ_USRMODDI_CNT_U32           << 1);
        DMASSDSA8   = (uint32)(&(McuDiagcTestAry_F[Indx_Cnt_T_u08])); /* Local RAM ECC Error Address */
        DMASSDDA8   = (uint32)(&(DmaWrDataVar_G)); /* Local RAM Address */
        DMASSDTC8   = ((uint32)0x00U << 16)
                    | ((uint32)0x01U <<  0);
        DMASSDTCT8 =  ((uint32)0x00U << 27)
                    | ((uint32)0x00U << 26)
                    | ((uint32)0x00U << 18)
                    | ((uint32)0x00U << 16)
                    | ((uint32)0x00U << 15)
                    | ((uint32)0x00U << 14)
                    | ((uint32)0x01U << 13)
                    | ((uint32)0x00U << 11)
                    | ((uint32)0x00U <<  9)
                    | ((uint32)0x00U <<  7)
                    | ((uint32)0x00U <<  5)
                    | ((uint32)0x02U <<  2)
                    | ((uint32)0x01U <<  0);

        DMASSDTFR8  = ((uint32)   0U <<  1)
                    | ((uint32)   0U <<  0);

        /* Enabling DMA channel should trigger the DMA transfer */
        DMASSDCEN8  = 0x00000001U;
        DMASSDCSTS8 = 0x00000001U;

        __SYNCM();

        /* Enable all the EI Interrupts */
        ResumeAllInterrupts();
    }

    /* Bank 3 Error from DMA Read */
    else if(ErrId_Cnt_T_u32 == MCUERRINJ_NTC0012BIT00CASE08_CNT_U32)
    {
        /* Clear BRAMDAT2 Register */
        ClrErrInjReg_Oper();

        SuspendAllInterrupts();
        switch(RamBnk_Cnt_T_u32)
        {
            case 0x0U:
                Indx_Cnt_T_u08 = 3U;
            break;

            case 0x4U:
                Indx_Cnt_T_u08 = 2U;
            break;

            case 0x8U:
                Indx_Cnt_T_u08 = 1U;
            break;

            case 0xCU:
                Indx_Cnt_T_u08 = 0U;
            break;

            default:
                Indx_Cnt_T_u08 = 0U;
            break;
        }

        /* Set (PROT[1:0]) = (0, 1) when writing to LRTSTCTL. DATSEL = 1, ECCTST = 1 */
        ECCCPU1LRTSTCTL_PE1 = 0x00004003U;
        __SYNCM();

        /* Inject 1 Bit Faulty Data in ECC */
        McuDiagcTestAry_F[Indx_Cnt_T_u08] = 0x43U;
        __SYNCM();

        /* Set (PROT[1:0]) = (0, 1) when writing to LRTSTCTL. DATSEL = 0, ECCTST = 1 */
        ECCCPU1LRTSTCTL_PE1 = 0x00004002U;
        __SYNCM();
        McuDiagcTestAry_F[Indx_Cnt_T_u08] = 0x00000000U;
        __SYNCM();

        /* Set (PROT[1:0]) = (0, 1) when writing to LRTSTCTL. DATSEL = 0, ECCTST = 0 */
        ECCCPU1LRTSTCTL_PE1 = 0x00004000U;
        __SYNCM();

        McuDiagcTestVar1_G = McuDiagcTestAry_F[Indx_Cnt_T_u08];
        __SYNCM();

        /* Set up DMA Channel 10 to do a DMA transfer from CF to LRAM as follows */
        DMASSDCEN8  = 0x00000000U;
        DMASSDM10CM = ((uint32)MCUERRINJ_CPU1PEID_CNT_U32           << 4)
                    | ((uint32)MCUERRINJ_LCLRAMTOLCLRAMSPID_CNT_U32 << 2)
                    | ((uint32)MCUERRINJ_USRMODDI_CNT_U32           << 1);
        DMASSDSA8   = (uint32)(&(McuDiagcTestAry_F[Indx_Cnt_T_u08])); /* Local RAM ECC Error Address */
        DMASSDDA8   = (uint32)(&(DmaWrDataVar_G)); /* Local RAM Address */
        DMASSDTC8   = ((uint32)0x00U << 16)
                    | ((uint32)0x01U <<  0);
        DMASSDTCT8 =  ((uint32)0x00U << 27)
                    | ((uint32)0x00U << 26)
                    | ((uint32)0x00U << 18)
                    | ((uint32)0x00U << 16)
                    | ((uint32)0x00U << 15)
                    | ((uint32)0x00U << 14)
                    | ((uint32)0x01U << 13)
                    | ((uint32)0x00U << 11)
                    | ((uint32)0x00U <<  9)
                    | ((uint32)0x00U <<  7)
                    | ((uint32)0x00U <<  5)
                    | ((uint32)0x02U <<  2)
                    | ((uint32)0x01U <<  0);

        DMASSDTFR8  = ((uint32)   0U <<  1)
                    | ((uint32)   0U <<  0);

        /* Enabling DMA channel should trigger the DMA transfer */
        DMASSDCEN8  = 0x00000001U;
        DMASSDCSTS8 = 0x00000001U;

        __SYNCM();

        /* Enable all the EI Interrupts */
        ResumeAllInterrupts();
    }

    /* Special Conditions:
       PEG guard has to enable access for FR (SPID = 3) to access Local RAM
       LRAM Error from FR Read */
    else if(ErrId_Cnt_T_u32 == MCUERRINJ_NTC0012BIT00CASE09_CNT_U32)
    {
        /* Clear BRAMDAT2 Register */
        ClrErrInjReg_Oper();
        SuspendAllInterrupts();

        /* FlexRay module enable per section 18.3.1.1 of the UM */

        /* FROC.OEP = 0, OE is unprotected */
        FLXA0OEP = 0U;
        asm( "syncm" );

        /* FROC.OE = 1, Operation Enabled */
        FLXA0OE = 1u;
        asm( "syncm" );

        while(FLXA0OS == 0U)
        {
        /* FLXAnFROS.OS
           0 operation disabled, reset state
           1 operation enabled */
        ;
        }

        /* FROC.OEP = 1, OE is protected : Write access to the OE bit is disabled */
        FLXA0OEP = 1U;

        /* FLXAnFRSUCC1.PBSY = 1
           POC is busy, bit FLXAnFRSUCC1.CMD locked */
        while(FLXA0PBSY == 1U)
        {
        ;
        }

        /* Set (PROT[1:0]) = (0, 1) when writing to LRTSTCTL. DATSEL = 1, ECCTST = 1 */
        ECCCPU1LRTSTCTL_PE1 = 0x00004003U;
        __SYNCM();

        /* Inject 1 Bit Faulty Data in ECC */
        McuDiagcTestAry_G[0] = 0x43U;
        __SYNCM();

        /* Set (PROT[1:0]) = (0, 1) when writing to LRTSTCTL. DATSEL = 0, ECCTST = 1 */
        ECCCPU1LRTSTCTL_PE1 = 0x00004002U;
        __SYNCM();
        McuDiagcTestAry_G[0] = 0x00000000U;
        __SYNCM();

        /* Set (PROT[1:0]) = (0, 1) when writing to LRTSTCTL. DATSEL = 0, ECCTST = 0 */
        ECCCPU1LRTSTCTL_PE1 = 0x00004000U;
        __SYNCM();

        /* Input transfer is used to set up a message buffer or to update data for transmission.
           FLXAnFRIBA FlexRay Input Pointer Table Base Address Register */
        FLXA0FRIBA = (uint32)(&McuDiagcTestAry_G);

        /* Configure size of input pointer table */
        FLXA0ITM = 2U;

        /* IBSYS = 1, Transfer between IBF Shadow and Message RAM in progress */
        while(FLXA0IBSYS == 1U)
        {
        ;
        }

        /* This initializes the put and get index pointers
           Input Transfer Enable Bit */
        FLXA0ITE = 1U;
        asm( "syncm" );

        /* To commit this table entry to the input handler, the application has to write the target message buffer
           number to the input queue control register */
        FLXA0IMBNR = 0U;

        /* Transfer function of user requested input transfers */
        FLXA0UIDX = 1U;
        asm( "syncm" );

        /* FLXAnFRITS.UIRP should be set to one at this point
           changes from 1 to 0 when completed */

        while(FLXA0UIRP == 1U)
        {
        ;
        }
        __SYNCM();

        /* Enable all the EI Interrupts */
        ResumeAllInterrupts();
    }

    /* LRAM 1 Bit Error from Instruction fetch */
    else if(ErrId_Cnt_T_u32 == MCUERRINJ_NTC0012BIT00CASE0A_CNT_U32)
    {
        (void)memcpy((void*)&McuDiagcTestAry_G, (void*)&FuncForLclRamInstrFetchErrInj, sizeof(McuDiagcTestAry_G));

        /* Clear BRAMDAT2 Register */
        ClrErrInjReg_Oper();
        SuspendAllInterrupts();

        /* set ECCTST = 1 ECC Test Mode Enable */
        TempVar_F = ECCCPU1LRTSTCTL_PE1;
        TempVar_F |= 0x00004002U;
        ECCCPU1LRTSTCTL_PE1 = TempVar_F;
        asm( "syncm" );

        /* ECC RAM Select Test Area RAM */
        TempVar_F = ECCCPU1LRTSTCTL_PE1;
        TempVar_F |= 0x00004000U;

        /* DATSEL = 0 */
        TempVar_F &= ~0x01UL;
        ECCCPU1LRTSTCTL_PE1 = TempVar_F;
        asm( "syncm" );

        McuDiagcTestAry_G[0] = 0x00000000U;
        asm( "syncm" );

        /* Write ECC bits associated with test pattern just written to RAM */
        /* ECC RAM Select Test Area ECC*/
        TempVar_F = ECCCPU1LRTSTCTL_PE1;
        TempVar_F |= 0x00004000U;

        /* DATSEL = 1 */
        TempVar_F |= 0x01UL;
        ECCCPU1LRTSTCTL_PE1 = TempVar_F;
        asm( "syncm" );

        McuDiagcTestAry_G[0] = 0x43U;
        asm( "syncm" );

        /* ECC RAM TestMode Disable set ECCTST = 0 */
        TempVar_F = ECCCPU1LRTSTCTL_PE1;
        TempVar_F &= ~0x02UL;
        TempVar_F |= 0x00004000U;
        ECCCPU1LRTSTCTL_PE1 = TempVar_F;
        asm( "syncm" );

        /* Execution of function from RAM will now cause ECC 1 bit Local RAM error */
        ((void (*)(void))&McuDiagcTestAry_G)();

        /* Enable all the EI Interrupts */
        ResumeAllInterrupts();
    }

    /* LRAM 2 Bit Error from Instruction fetch */
    else if(ErrId_Cnt_T_u32 == MCUERRINJ_NTC0013BIT01CASE02_CNT_U32)
    {
        (void)memcpy((void*)&McuDiagcTestAry_G, (void*)&FuncForLclRamInstrFetchErrInj, sizeof(McuDiagcTestAry_G));

        /* Clear BRAMDAT2 Register */
        ClrErrInjReg_Oper();
        SuspendAllInterrupts();

        /* set ECCTST = 1 Test Mode Enable */
        TempVar_F = ECCCPU1LRTSTCTL_PE1;
        TempVar_F |= 0x00004002UL;
        ECCCPU1LRTSTCTL_PE1 = TempVar_F;
        asm( "syncm" );

        /* Select Test Area   RAM */
        TempVar_F = ECCCPU1LRTSTCTL_PE1;
        TempVar_F |= 0x00004000UL;

        /* DATSEL = 0 */
        TempVar_F &= ~0x01UL;
        ECCCPU1LRTSTCTL_PE1 = TempVar_F;
        asm( "syncm" );

        McuDiagcTestAry_G[0] = 0x00000003U;
        asm( "syncm" );

        /* Write ECC bits associated with test pattern just written to RAM
           Select Test Area ECC */
        TempVar_F = ECCCPU1LRTSTCTL_PE1;
        TempVar_F |= 0x00004000UL;

        /* DATSEL = 1 */
        TempVar_F |= 0x01UL;
        ECCCPU1LRTSTCTL_PE1 = TempVar_F;
        asm( "syncm" );

        McuDiagcTestAry_G[0] = 0x03U;
        asm( "syncm" );

        /* Set ECCTST = 0
           Test Mode Disable */
        TempVar_F = ECCCPU1LRTSTCTL_PE1;
        TempVar_F &= ~0x02UL;
        TempVar_F |= 0x00004000UL;
        ECCCPU1LRTSTCTL_PE1 = TempVar_F;
        asm( "syncm" );

        /* Execution of function from RAM will now cause ECC 2 bit Local RAM error */
        ((void (*)(void))&McuDiagcTestAry_G)();

        /* Enable all the EI Interrupts */
        ResumeAllInterrupts();
    }

    /* Local RAM Single Hard Fault */
    else if(ErrId_Cnt_T_u32 == MCUERRINJ_NTC0013BIT00CASE01_CNT_U32)
    {
        /* Clear BRAMDAT2 Register */
        ClrErrInjReg_Oper();

        SuspendAllInterrupts();
        /* Set (PROT[1:0]) = (0, 1) when writing to LRTSTCTL. DATSEL = 1, ECCTST = 1 */
        ECCCPU1LRTSTCTL_PE1 = 0x00004003U;
        __SYNCM();

        /* Inject 1 Bit Faulty Data in ECC */
        McuDiagcTestAry_G[0] = 0x43U;
        __SYNCM();

        /* Set (PROT[1:0]) = (0, 1) when writing to LRTSTCTL. DATSEL = 0, ECCTST = 1 */
        ECCCPU1LRTSTCTL_PE1 = 0x00004002U;
        __SYNCM();
        McuDiagcTestAry_G[0] = 0x00000000U;
        __SYNCM();

        /* Set (PROT[1:0]) = (0, 1) when writing to LRTSTCTL. DATSEL = 0, ECCTST = 0 */
        ECCCPU1LRTSTCTL_PE1 = 0x00004000U;
        __SYNCM();
        McuDiagcTestVar1_G = McuDiagcTestAry_G[0];
        __SYNCM();

        /* Cause another 1 bit RAM Error which should set the overflow bit; Set (PROT[1:0]) = (0, 1) when writing to LRTSTCTL. DATSEL = 1, ECCTST = 1 */
        ECCCPU1LRTSTCTL_PE1 = 0x00004003U;
        __SYNCM();

        /* Inject 1 Bit Faulty Data in ECC */
        McuDiagcTestAry_G[4] = 0x43U;
        __SYNCM();

        /* Set (PROT[1:0]) = (0, 1) when writing to LRTSTCTL. DATSEL = 0, ECCTST = 1 */
        ECCCPU1LRTSTCTL_PE1 = 0x00004002U;
        __SYNCM();
        McuDiagcTestAry_G[4] = 0x00000000U;
        __SYNCM();

        /* Set (PROT[1:0]) = (0, 1) when writing to LRTSTCTL. DATSEL = 0, ECCTST = 0 */
        ECCCPU1LRTSTCTL_PE1 = 0x00004000U;
        __SYNCM();

        McuDiagcTestVar1_G = McuDiagcTestAry_G[4];
        __SYNCM();

        /* Enable all the EI Interrupts */
        ResumeAllInterrupts();
    }
    else if(ErrId_Cnt_T_u32 == MCUERRINJ_NTC0013BIT00CASE02_CNT_U32)
    {
        /* Clear BRAMDAT2 Register */
        ClrErrInjReg_Oper();

        SuspendAllInterrupts();

        /* Set (PROT[1:0]) = (0, 1) when writing to LRTSTCTL. DATSEL = 1, ECCTST = 1 */
        ECCCPU1LRTSTCTL_PE1 = 0x00004003U;
        __SYNCM();

        /* Inject 1 Bit Faulty Data in ECC */
        McuDiagcTestAry_G[0] = 0x43U;
        __SYNCM();

        /* Set (PROT[1:0]) = (0, 1) when writing to LRTSTCTL. DATSEL = 0, ECCTST = 1 */
        ECCCPU1LRTSTCTL_PE1 = 0x00004002U;
        __SYNCM();
        McuDiagcTestAry_G[0] = 0x00000000U;
        __SYNCM();

        /* Set (PROT[1:0]) = (0, 1) when writing to LRTSTCTL. DATSEL = 0, ECCTST = 0 */
        ECCCPU1LRTSTCTL_PE1 = 0x00004000U;
        __SYNCM();

        /* Set up DMA Channel 10 to do a DMA transfer from CF to LRAM as follows */
        DMASSDCEN8  = 0x00000000U;
        DMASSDM10CM = ((uint32)MCUERRINJ_CPU1PEID_CNT_U32           << 4)
                    | ((uint32)MCUERRINJ_LCLRAMTOLCLRAMSPID_CNT_U32 << 2)
                    | ((uint32)MCUERRINJ_USRMODDI_CNT_U32           << 1);
        DMASSDSA8   = (uint32)(&(McuDiagcTestAry_G)); /* Local RAM ECC Error Address */
        DMASSDDA8   = (uint32)(&(DmaWrDataVar_G)); /* Local RAM Address */
        DMASSDTC8   = ((uint32)0x00U << 16)
                    | ((uint32)0x01U <<  0);
        DMASSDTCT8  = ((uint32)0x00U << 27)
                    | ((uint32)0x00U << 26)
                    | ((uint32)0x00U << 18)
                    | ((uint32)0x00U << 16)
                    | ((uint32)0x00U << 15)
                    | ((uint32)0x00U << 14)
                    | ((uint32)0x01U << 13)
                    | ((uint32)0x00U << 11)
                    | ((uint32)0x00U <<  9)
                    | ((uint32)0x00U <<  7)
                    | ((uint32)0x00U <<  5)
                    | ((uint32)0x02U <<  2)
                    | ((uint32)0x01U <<  0);

        DMASSDTFR8  = ((uint32)   0U <<  1)
                    | ((uint32)   0U <<  0);

        /* enabling DMA channel should trigger the DMA transfer */
        DMASSDCEN8 = 0x00000001U;
        DMASSDCSTS8 = 0x00000001U;

        __SYNCM();

        /* Cause another 1 bit RAM Error which should set the overflow bit; Set (PROT[1:0]) = (0, 1) when writing to LRTSTCTL. DATSEL = 1, ECCTST = 1 */
        ECCCPU1LRTSTCTL_PE1 = 0x00004003U;
        __SYNCM();

        /* Inject 1 Bit Faulty Data in ECC */
        McuDiagcTestAry_G[4] = 0x43U;
        __SYNCM();

        /* Set (PROT[1:0]) = (0, 1) when writing to LRTSTCTL. DATSEL = 0, ECCTST = 1 */
        ECCCPU1LRTSTCTL_PE1 = 0x00004002U;
        __SYNCM();
        McuDiagcTestAry_G[4] = 0x00000000U;
        __SYNCM();

        /* Set (PROT[1:0]) = (0, 1) when writing to LRTSTCTL. DATSEL = 0, ECCTST = 0 */
        ECCCPU1LRTSTCTL_PE1 = 0x00004000U;
        __SYNCM();

        /* Set up DMA Channel 10 to do a DMA transfer from CF to LRAM as follows */
        DMASSDCEN8  = 0x00000000U;
        DMASSDM10CM = ((uint32)MCUERRINJ_CPU1PEID_CNT_U32           << 4)
                    | ((uint32)MCUERRINJ_LCLRAMTOLCLRAMSPID_CNT_U32 << 2)
                    | ((uint32)MCUERRINJ_USRMODDI_CNT_U32           << 1);
        DMASSDSA8   = (uint32)(&(McuDiagcTestAry_G[4])); /* Local RAM ECC Error Address */
        DMASSDDA8   = (uint32)(&(DmaWrDataVar_G)); /* Local RAM Address */
        DMASSDTC8   = ((uint32)0x00U << 16)
                    | ((uint32)0x01U <<  0);
        DMASSDTCT8  = ((uint32)0x00U << 27)
                    | ((uint32)0x00U << 26)
                    | ((uint32)0x00U << 18)
                    | ((uint32)0x00U << 16)
                    | ((uint32)0x00U << 15)
                    | ((uint32)0x00U << 14)
                    | ((uint32)0x01U << 13)
                    | ((uint32)0x00U << 11)
                    | ((uint32)0x00U <<  9)
                    | ((uint32)0x00U <<  7)
                    | ((uint32)0x00U <<  5)
                    | ((uint32)0x02U <<  2)
                    | ((uint32)0x01U <<  0);

        DMASSDTFR8  = ((uint32)   0U <<  1)
                    | ((uint32)   0U <<  0);

        /* enabling DMA channel should trigger the DMA transfer */
        DMASSDCEN8 = 0x00000001U;
        DMASSDCSTS8 = 0x00000001U;

        /* Enable all the EI Interrupts */
        ResumeAllInterrupts();
    }
    /* Local RAM Double bit ECC Error */
    else if(ErrId_Cnt_T_u32 == MCUERRINJ_NTC0013BIT01CASE01_CNT_U32)
    {
        /* Clear BRAMDAT2 Register */
        ClrErrInjReg_Oper();

        SuspendAllInterrupts();

        /* Set (PROT[1:0]) = (0, 1) when writing to LRTSTCTL. DATSEL = 1, ECCTST = 1 */
        ECCCPU1LRTSTCTL_PE1 = 0x00004003U;
        __SYNCM();

        /* Inject 2 Bit Faulty Data in ECC */
        McuDiagcTestAry_G[0] = 0x03U;
        __SYNCM();

        /* Set (PROT[1:0]) = (0, 1) when writing to LRTSTCTL. DATSEL = 0, ECCTST = 1 */
        ECCCPU1LRTSTCTL_PE1 = 0x00004002U;
        __SYNCM();
        McuDiagcTestAry_G[0] = 0x00000003U;
        __SYNCM();

        /* Set (PROT[1:0]) = (0, 1) when writing to LRTSTCTL. DATSEL = 0, ECCTST = 0 */
        ECCCPU1LRTSTCTL_PE1 = 0x00004000U;
        __SYNCM();

        McuDiagcTestVar1_G = McuDiagcTestAry_G[0];
        __SYNCM();

        /* Enable all the EI Interrupts */
        ResumeAllInterrupts();
    }

    else if(ErrId_Cnt_T_u32 == MCUERRINJ_NTC0012BIT02CASE01_CNT_U32)
    {
        /* Clear BRAMDAT2 Register */
        ClrErrInjReg_Oper();

        SuspendAllInterrupts();

        /* Clear Cache: ICCTRL.ICHCLR = 1 */
        McuDiagcTestVar1_G = __STSR (24, 4); /* read ICCTRL */
        __LDSR (24, 4, (McuDiagcTestVar1_G | 0x00000100U));  /* ICCTRL = ICCTRL | 0x00000100U (set bit 8) */

        /* Wait until Cache is cleared: ICCTRL.ICHCLR = 0  (bit 8 of ICCTRL) */
        McuDiagcTestVar1_G = __STSR (24, 4); /* read ICCTRL */
        while((McuDiagcTestVar1_G & 0x00000100U) == 0x00000100U)
        {
            McuDiagcTestVar1_G = (uint32)__STSR (24, 4); /* read ICCTRL */
        }

        /* Set IDSTCLR_PE1.STCLR0 = 1, IDSTCLR_PE1.STCLR1 = 1  to clear error info in both Banks */
        ECCIC1IDSTCLR_PE1 = 0x00000003U;

        /* Write cache tag value in ICTAGL; */
        /* Write DATAL in ICDATL or Write DATAH in ICDATH */
        __LDSR(16, 4, 0x00000000U); /* ICTAGL = 0x0000 0000 */
        __LDSR(18, 4, 0x00000003U); /* ICDATL = 0x0000 0003 */
        __LDSR(19, 4, 0x00000000U); /* ICDATH = 0x0000 0000 */

        McuDiagcTestVar1_G = (uint32)__STSR (17, 4); /* Read ICTAGH */

        /* ICTAGH.PD = 0; ICTAGH.PT = 0; */
        McuDiagcTestVar1_G &= 0xAFFFFFFFU;

        /* ICTAGH.WD = 1; ICTAGH.WT = 1; */
        McuDiagcTestVar1_G |= 0xA0000000U;

        __LDSR (17, 4, McuDiagcTestVar1_G); /* Write ICTAGH */
        __SYNCM();

        /* Execute CIST using a system register to store DATAL or DATAH and the related info */
        asm( "cache 96, [r0]" ); /* CACHE 1100000, [reg1] */
        __SYNCM();

        /* Execute CILD from the same index to load the previous stored value to a system register */
        asm( "cache 97, [r0]" ); /* CACHE 1100001, [reg1] */
        __SYNCM();

        McuDiagcTestVar1_G = __STSR (17, 4); /* Read ICTAGH */

        /* ICTAGH.PD = 1; */
        McuDiagcTestVar1_G |= 0x40000000U;

        /* clear bits 23:16 */
        McuDiagcTestVar1_G &= 0xFF00FFFFU;

        /* Modify two bits of DATAECC, set ECC bits to value of 3 */
        McuDiagcTestVar1_G |= 0x00030000U;

        __LDSR (17, 4, McuDiagcTestVar1_G); /* Write ICTAGH */
        __SYNCM();

        /* Execute CIST using a system register to store DATAL or DATAH and the related info */
        asm( "cache 96, [r0]" ); /* CACHE 1100000, [reg1] */
        __SYNCM();

        /* Execute CILD from the same index to load the previous stored value to a system register */
        asm( "cache 97, [r0]" ); /* CACHE 1100001, [reg1] */
        __SYNCM();

        ResumeAllInterrupts();
    }
    else if(ErrId_Cnt_T_u32 == MCUERRINJ_NTC0013BIT02CASE01_CNT_U32)
    {
        /* Clear BRAMDAT2 Register */
        ClrErrInjReg_Oper();

        McuDiagcTestVar1_G = *(uint32 *)(0xFEA00000U);
    }
    else
    {
        /* Do Nothing */
    }
}

#endif

#define CDD_RamMem_STOP_SEC_CODE
#include "CDD_RamMem_MemMap.h"
