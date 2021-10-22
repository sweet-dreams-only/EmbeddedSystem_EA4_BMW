/**********************************************************************************************************************
* Copyright 2017 Nxtr 
* Nxtr Confidential
*
* Module File Name:   fbl_TmplMonr.c
* Module Description: Driver for handling temporal Monitor Interface
* Project           : BMW
* Author            : Kevin Smith
***********************************************************************************************************************
* Version Control:
* %version:          2 %
* %derived_by:       cz7lt6 %
*----------------------------------------------------------------------------------------------------------------------
* Date      Rev      Author         Change Description                                                           SCR #
* -------   -------  --------  ---------------------------------------------------------------------------     --------
* 09/06/17   1       KJS       Initial Version                                                                 EA4#14822                                                                            
**********************************************************************************************************************/

/**********************************************************************************************************************
    --- IMPORTANT ---
    Date: Sep-6-2017, K. Smith
    
    This file is only part of the project until the bootloader is available. Once the bootloader is available
    this file shall be removed from the project. 
**********************************************************************************************************************/

// #include "fbl_inc.h"
#include "fbl_TmplMonr.h"

/***********************************************************************************************************************
 *  DEFINES
 **********************************************************************************************************************/
/* Restart sequence command for watchdog timer */
#define TMP_DEFAULTSEQ (0x2600 << 1) /* This sequence is needed to put temporal monitor watchdog into default configuration*/
#define TMP_RESTARTSEQ1 0x3DA6
#define TMP_RESTARTSEQ2 0x3C67
#define TMP_RESTARTSEQ3 0x3D9A

/* Flash sequence command for watchdog timer */
#define TMP_FLASHSEQ1 0x3DA6
#define TMP_FLASHSEQ2 0x3C67
#define TMP_FLASHSEQ3 0x3D99


/***********************************************************************************************************************
 *  FBL_TmplMonr_Init
 **********************************************************************************************************************/
/*! \brief        Temporal Monitor Initialization function   
 *  \details      This function is called during bootloader initialization to configure PORT 5 group pins interfaced
 *                with Temporal Monitor IC and SPI module CSIG0        
 
 **********************************************************************************************************************/
void FBL_TmplMonr_Init()
{
/*********************** Port Configuration for CSIG0 SPI Channel *************************** */
  /* PMC configuration for Port mode and Alternate mode */
  PORTPMC5_9 = 0;
  PORTPMC5_0 = 1;
  PORTPMC5_1 = 1;
  PORTPMC5_4 = 1;

  /* PIPC for I/O control by SW or direct peripheral in Alternate mode */
  PORTPIPC5_1 =1;
  PORTPIPC5_4 =1;

  /* PM Configuration for selecting input and output direction */
  PORTPM5_9 = 0;  //CS
  PORTPM5_0=  1;  //SI
  PORTPM5_1=  0;  // SO
  PORTPM5_4=  0;  // SCK

  /*  PFC, PFCE, PFCAE For selecting Alternate functions
   *  PFC, PFCE and PFCAE selected to support 1st alternate function - CSIG0 */
  PORTPFC5_0 = 0;
  PORTPFC5_1 = 0;
  PORTPFC5_4 = 0;

  PORTPFCE5_0 = 0;
  PORTPFCE5_1 = 0;
  PORTPFCE5_4 = 0;

  PORTPFCAE5_0 = 0;
  PORTPFCAE5_1 = 0;
  PORTPFCAE5_4 = 0;

/************************ SPI Configurations **************************************************/
  /* CSIGnCTL0 controls the operation clock and enables or disables transmission/reception */
  CSIG0MBS = 1;
  CSIG0PWR = 1;

  /* CSIG0CTL2 selects the communication clock */
  CSIG0BRS = 0xA; /* Value selected for baud rate equalt to 1Mbps */
  CSIG0PRS = 0x2; /* Prescalar 4 */

  /* CSIG0CFG0 configures the communication protocol – data length, parity, transfer direction, clock
   * phase, and data phase*/
  CSIG0PS = 0;  /* No parity Automatically added */
  CSIG0DLS = 0; /* Data length 16 bits */ 
  CSIG0DIR = 0; /* MSB first */
}

/***********************************************************************************************************************
 *  FBL_TmplMonr_RestartMode
 **********************************************************************************************************************/
/*! \brief       Temporal Monitor Restart Mode function
 *  \details     This function is called during Bootloader initialization to restart the watchdog timer.
 *  \pre         FBL_TmplMonr_Init shall be called before
 **********************************************************************************************************************/
void FBL_TmplMonr_RestartMode()
{
  /* Enable chip select by driving port pin as low */
  PORTP5_9 =0;
  /* Enable transmission */
  CSIG0TXE =1;
  
  /* Load sequence to put Temporal monitor watchdog into default configuration into Tx register */
  CSIG0TX = TMP_DEFAULTSEQ;
  /* Wait till the transmission is finished by checking transmit status flag */
  do
  {
  }while(CSIG0TSF);

  /* Drive the CS line high after the transmission. This is needed since once the transmitted data is
   * received into the shift register of the temporal monitor IC the data is latched into the device register 
   * when the the CS pin is driven high. */
  PORTP5_9 =1;
  
  /* Enable chip select by driving port pin as low */
  PORTP5_9 =0;

  /* Load Restart sequence 1 into Tx register */
  CSIG0TX = TMP_RESTARTSEQ1;
  /* Wait till the transmission is finished by checking transmit status flag */
  do
  {
  }while(CSIG0TSF);
  
  /* Drive the CS line high after the transmission. This is needed since once the transmitted data is
   * received into the shift register of the temporal monitor IC the data is latched into the device register 
   * when the the CS pin is driven high. */
  PORTP5_9 =1;
  
  /* The comments are same for the subsequent steps of restart sequence */
  PORTP5_9 =0;
  
  CSIG0TX = TMP_RESTARTSEQ2;
  do
  {
  }while(CSIG0TSF);
  
  PORTP5_9 =1;
  PORTP5_9 =0;

  CSIG0TX = TMP_RESTARTSEQ3;
  do
  {
  }while(CSIG0TSF);

  /* Disable transmission */
  CSIG0TXE =0;
  /* Disable chip select */
  PORTP5_9 =1; 
}

/***********************************************************************************************************************
 *  FBL_TmplMonr_FlashMode
 **********************************************************************************************************************/
/*! \brief       Temporal Monitor Flash Mode function
 *  \details     This function is called during Bootloader initialization to put watchdog timer into flash mode.
 *  \pre         FBL_TmplMonr_Init shall be called before     
 **********************************************************************************************************************/
void FBL_TmplMonr_FlashMode()
{
  /* Enable chip select by driving port pin as low */
  PORTP5_9 =0;
  /* Enable transmission */
  CSIG0TXE =1;
  
  /* Load Flash sequence 1 into Tx register */
  CSIG0TX = TMP_FLASHSEQ1;
  /* Wait till the transmission is finished by checking transmit status flag */
  do
  {
  }while(CSIG0TSF);

  /* Drive the CS line high after the transmission. This is needed since once the transmitted data is
   * received into the shift register of the temporal monitor IC the data is latched into the device register 
   * when the the CS pin is driven high. */
  PORTP5_9 =1;
  
  /* The comments are same for the subsequent steps of flash sequence */
  PORTP5_9 =0;

  CSIG0TX = TMP_FLASHSEQ2;
  do
  {
  }while(CSIG0TSF);
  
  PORTP5_9 =1;
  PORTP5_9 =0;

  CSIG0TX = TMP_FLASHSEQ3;
  do
  {
  }while(CSIG0TSF);

  /* Disable transmission */
  CSIG0TXE =0;
  /* Disable chip select */
  PORTP5_9 =1;
}

void FBL_SPIInit()
{
    uint16 savedCSIH0MCTL0_Cnt_T_u16;
    uint16 savedCSIH1MCTL0_Cnt_T_u16;
    uint16 savedCSIH2MCTL0_Cnt_T_u16;
    uint16 savedCSIH3MCTL0_Cnt_T_u16;
    uint16 i;
    /* Peripheral SPI RAM is initialized for all type of Resets.*/

    /* CSIH RAM Init */
    /* Save current values of CSIHnMCTL0 */
    savedCSIH0MCTL0_Cnt_T_u16 = CSIH0MCTL0;
    savedCSIH1MCTL0_Cnt_T_u16 = CSIH1MCTL0;
    savedCSIH2MCTL0_Cnt_T_u16 = CSIH2MCTL0;
    savedCSIH3MCTL0_Cnt_T_u16 = CSIH3MCTL0;

    /* set CSIHnMCTL0. CSIHnMMS = 2, memory mode = transmit-only buffer mode */
    CSIH0MCTL0 = 1<<9;
    CSIH1MCTL0 = 1<<9;
    CSIH2MCTL0 = 1<<9;
    CSIH3MCTL0 = 1<<9; 

    for ( i = 0u; i < 128u; i++ )
    {
        /* Write to CSIH memory to initialize */     
        CSIH0TX0W = 0x00000000UL;
        CSIH1TX0W = 0x00000000UL;
        CSIH2TX0W = 0x00000000UL;
        CSIH3TX0W = 0x00000000UL; 
    }

    /* Perform read after ECC initialized to clear ECEMF in ECC Control Regsiter */
    CSIH0TX0W  = CSIH0TX0W;
    CSIH1TX0W  = CSIH1TX0W;
    CSIH2TX0W  = CSIH2TX0W;
    CSIH3TX0W  = CSIH3TX0W;

    /*  tx/rx pointers to default values */
    CSIH0MRWP0 = 0x00000000U;
    CSIH1MRWP0 = 0x00000000U;
    CSIH2MRWP0 = 0x00000000U;
    CSIH3MRWP0 = 0x00000000U;

    /* Restore values of CSIHnMCTL0 */
    CSIH0MCTL0 = savedCSIH0MCTL0_Cnt_T_u16;
    CSIH1MCTL0 = savedCSIH1MCTL0_Cnt_T_u16 ;
    CSIH2MCTL0 = savedCSIH2MCTL0_Cnt_T_u16 ;
    CSIH3MCTL0 = savedCSIH3MCTL0_Cnt_T_u16 ;

}
