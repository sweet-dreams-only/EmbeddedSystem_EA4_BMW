/*============================================================================*/
/* Project      = AUTOSAR Renesas X1x MCAL Components                         */
/* Module       = Mcu_Reg.h                                                   */
/*============================================================================*/
/*                                  COPYRIGHT                                 */
/*============================================================================*/
/* Copyright(c) 2013-2016 Renesas Electronics Corporation                     */
/*============================================================================*/
/* Purpose:                                                                   */
/* This file contains register addresses used.                                */
/* AUTOMATICALLY GENERATED FILE - DO NOT EDIT                                 */
/*                                                                            */
/*============================================================================*/
/*                                                                            */
/* Unless otherwise agreed upon in writing between your company and           */
/* Renesas Electronics Corporation the following shall apply!                 */
/*                                                                            */
/* Warranty Disclaimer                                                        */
/*                                                                            */
/* There is no warranty of any kind whatsoever granted by Renesas. Any        */
/* warranty is expressly disclaimed and excluded by Renesas, either expressed */
/* or implied, including but not limited to those for non-infringement of     */
/* intellectual property, merchantability and/or fitness for the particular   */
/* purpose.                                                                   */
/*                                                                            */
/* Renesas shall not have any obligation to maintain, service or provide bug  */
/* fixes for the supplied Product(s) and/or the Application.                  */
/*                                                                            */
/* Each User is solely responsible for determining the appropriateness of     */
/* using the Product(s) and assumes all risks associated with its exercise    */
/* of rights under this Agreement, including, but not limited to the risks    */
/* and costs of program errors, compliance with applicable laws, damage to    */
/* or loss of data, programs or equipment, and unavailability or              */
/* interruption of operations.                                                */
/*                                                                            */
/* Limitation of Liability                                                    */
/*                                                                            */
/* In no event shall Renesas be liable to the User for any incidental,        */
/* consequential, indirect, or punitive damage (including but not limited     */
/* to lost profits) regardless of whether such liability is based on breach   */
/* of contract, tort, strict liability, breach of warranties, failure of      */
/* essential purpose or otherwise and even if advised of the possibility of   */
/* such damages. Renesas shall not be liable for any services or products     */
/* provided by third party vendors, developers or consultants identified or   */
/* referred to the User by Renesas in connection with the Product(s) and/or   */
/* the Application.                                                           */
/*                                                                            */
/*============================================================================*/
/* Environment:                                                               */
/*              Devices:        P1x                                           */
/*============================================================================*/

/*******************************************************************************
**                      Revision Control History                              **
*******************************************************************************/
/*
 * V1.0.0:  26-Aug-2013 : Initial Version
 * V1.1.0:  21-Apr-2014 : Following changes are made:
 *                        1. Copyright information is updated.
 *                        2. Macro MCU_TESTCOMPREG0 and MCU_TESTCOMPREG1 are
 *                           added.
 *                        3. Unwanted macros are removed.
 * V1.1.1:  20-Oct-2014 : As per CR 008 for mantis #19850, MCU_CVMREN is added.
 * V1.1.2:  07-Oct-2015 : 1. As part of ARDAAAE-1481, added register definitions
 *                           for ADC clock selection.
 *                        2. As per fusa requirements EAAR_PN0079_FSR_0099,
 *                           EAAR_PN0079_FSR_0100, and EAAR_PN0079_FSR_0101
 *                           the reister definition MCU_BRAMDAT0 is added.
 * V1.1.3   08-Apr-2016 : Following changes are done as part of P1M
 *                        V4.01.00 release activity.
 *                        1. QAC justification is added for  Msg(4:0857)
 *                        2. Copyright Info is updated.
 */
/******************************************************************************/

/*******************************************************************************
**                   Generation Tool Version                                  **
*******************************************************************************/
/*
 * TOOL VERSION:  1.1.5
 */

/*******************************************************************************
**                          Input File                                        **
*******************************************************************************/
/*
 * INPUT FILE:    C:\Users\tzyksv\AppData\Local\Temp\DaVinci\Cfg-3240631\Generation\Cfg_Gen-1532993252944-0\AutosarFiles_ValGen-1532994905284-0\Mcu_ECUC_3350516407282010857.arxml
 *                C:\Component\FAAR_WE_Synergy\Mcu\generate\R403_MCU_P1x_BSWMDT.arxml
 * GENERATED ON:  30 Jul 2018 - 19:58:53
 */


#ifndef MCU_REG_H
#define MCU_REG_H
/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/

/*******************************************************************************
**                      Version Information                                   **
*******************************************************************************/

/*******************************************************************************
**                       Common Published Information                         **
*******************************************************************************/

/*******************************************************************************
**                      MISRA C Rule Violations                               **
*******************************************************************************/

/******************************************************************************/

/* 1. MISRA C RULE VIOLATION:                                                 */
/* Message       : Msg(4:0857) Number of macro definitions exceeds 1024 -     */
/*                 program does not conform strictly to ISO:C90.              */
/* Rule          : MISRA-C:2004 Rule                                          */
/* Justification : Number of macro definitions depends on configuration and   */
/*                 added as per functionality implementation                  */
/* Verification  : However, part of the code is verified manually and it is   */
/*                 not having any impact.                                     */
/* Reference     : Look for START Msg(4:0857)-1 and                           */
/*                 END Msg(4:0857)-1 tags in the code.                        */

/******************************************************************************/

/*******************************************************************************
**                      Global Symbols                                        **
*******************************************************************************/
/* MISRA Violation: START Msg(4:0857)-1 */
/* Reset source determination register */
#define MCU_RESF                            (*((volatile uint32  *)0xFFF82800UL))

/* Reset source clear register */
#define MCU_RESFC                           (*((volatile uint32  *)0xFFF82808UL))

/* Power-on clear flag register */
#define MCU_POF                             (*((volatile uint32  *)0xFFF8AC10UL))

/* Power-on clear flag clear register */
#define MCU_POFC                            (*((volatile uint32  *)0xFFF8AC14UL))

/* Software Reset Request Register */
#define MCU_SWRESA                          (*((volatile uint32  *)0xFFF8AC18UL))

/* Clock divider 0 register */
#define MCU_CLKD0DIV                        (*((volatile uint32  *)0xFFF89180UL))

/* Clock 0 selection status register */
#define MCU_CKSC0STAT                       (*((volatile uint32  *)0xFFF89084UL))

/* Clock 0 division status register */
#define MCU_CLKD0STAT                       (*((volatile uint32  *)0xFFF89184UL))

/* Clock 1 selection control register */
#define MCU_CKSC1CTL                        (*((volatile uint32  *)0xFFF890C0UL))

/* Clock 1 selection status register */
#define MCU_CKSC1STAT                       (*((volatile uint32  *)0xFFF890C4UL))

/* Clock 1 division register */
#define MCU_CLKD1DIV                        (*((volatile uint32  *)0xFFF89188UL))

/* Clock 1 division status register */
#define MCU_CLKD1STAT                       (*((volatile uint32  *)0xFFF8918CUL))

/* Protect 1 command register */
#define MCU_PROT1PHCMD                      (*((volatile uint32  *)0xFFF8B000UL))

/* Protect 1 status register */
#define MCU_PROT1PS                         (*((volatile uint32  *)0xFFF8B004UL))

/* ECM master error source status register 0 */
#define MCU_ECMMESSTR0                      (*((volatile uint32  *)0xFFD60008UL))

/* ECM master error source status register 1 */
#define MCU_ECMMESSTR1                      (*((volatile uint32  *)0xFFD6000CUL))

/* ECM master protection command register */
#define MCU_ECMMPCMD0                       (*((volatile uint32  *)0xFFD60010UL))

/* ECM checker protection command register */
#define MCU_ECMCPCMD0                       (*((volatile uint32  *)0xFFD61010UL))

/* ECM checker error source status register 0 */
#define MCU_ECMCESSTR0                      (*((volatile uint32  *)0xFFD61008UL))

/* ECM checker error source status register 1 */
#define MCU_ECMCESSTR1                      (*((volatile uint32  *)0xFFD6100CUL))

/* ECM maskable interrupt configuration register 0 */
#define MCU_ECMMICFG0                       (*((volatile uint32  *)0xFFD62004UL))

/* ECM maskable interrupt configuration register 1 */
#define MCU_ECMMICFG1                       (*((volatile uint32  *)0xFFD62008UL))

/* ECM non-maskable interrupt configuration register 0 */
#define MCU_ECMNMICFG0                      (*((volatile uint32  *)0xFFD6200CUL))

/* ECM non-maskable interrupt configuration register 1 */
#define MCU_ECMNMICFG1                      (*((volatile uint32  *)0xFFD62010UL))

/* ECM internal reset configuration register 0 */
#define MCU_ECMIRCFG0                       (*((volatile uint32  *)0xFFD62014UL))

/* ECM internal reset configuration register 1 */
#define MCU_ECMIRCFG1                       (*((volatile uint32  *)0xFFD62018UL))

/* ECM error mask register 0 */
#define MCU_ECMEMK0                         (*((volatile uint32  *)0xFFD6201CUL))

/* ECM error mask register 1 */
#define MCU_ECMEMK1                         (*((volatile uint32  *)0xFFD62020UL))

/* ECM master status address 0 */
#define MCU_ECMESSTC0                       (*((volatile uint32  *)0xFFD62024UL))

/* ECM master status address 1 */
#define MCU_ECMESSTC1                       (*((volatile uint32  *)0xFFD62028UL))

/* ECM protection command register */
#define MCU_ECMPCMD1                        (*((volatile uint32  *)0xFFD6202CUL))

/* ECM pseudo error trigger register 0 */
#define MCU_ECMPE0                          (*((volatile uint32  *)0xFFD62034UL))

/* ECM pseudo error trigger register 1 */
#define MCU_ECMPE1                          (*((volatile uint32  *)0xFFD62038UL))

/* ECM delay timer configuration register 0 */
#define MCU_ECMDTMCFG0                      (*((volatile uint32  *)0xFFD62048UL))

/* ECM delay timer configuration register 1 */
#define MCU_ECMDTMCFG1                      (*((volatile uint32  *)0xFFD6204CUL))

/* ECM delay timer configuration register 2 */
#define MCU_ECMDTMCFG2                      (*((volatile uint32  *)0xFFD62050UL))

/* ECM delay timer configuration register 3 */
#define MCU_ECMDTMCFG3                      (*((volatile uint32  *)0xFFD62054UL))

/* CVM protection register */
#define MCU_PROTCMDCVM                      (*((volatile uint32  *)0xFFF83010UL))

/* CVM protection command status register */
#define MCU_PROTSCVM                        (*((volatile uint32  *)0xFFF83014UL))

/* LVI control register */
#define MCU_LVICNT                          (*((volatile uint32  *)0xFFF82C00UL))

/* Clock 0 selection control register */
#define MCU_CKSC0CTL                        (*((volatile uint32  *)0xFFF89080UL))

/* CLMA self-test register */
#define MCU_CLMATEST                        (*((volatile uint32  *)0xFFF88204UL))

/* CLMA self-test status register */
#define MCU_CLMATESTS                       (*((volatile uint32  *)0xFFF88208UL))

/* EI level interrupt bind register */
#define MCU_EIBD8                           (*((volatile uint32  *)0xFFFEEB20UL))

/* Comparator test register 0 */
#define MCU_TESTCOMPREG0                    (*((volatile uint32  *)0xFFFEED00UL))

/* Comparator test register 1 */
#define MCU_TESTCOMPREG1                    (*((volatile uint32  *)0xFFFEED04UL))

/* CVM reset enable Control Register */
#define MCU_CVMREN                          (*((volatile uint32  *)0xFFF82840UL))

/* ADC clock control register */
#define MCU_ADCKSC0CTL                      (*((volatile uint32  *)0xFFF89200UL))

/* ADC clock status register */
#define MCU_ADCKSC0STAT                     (*((volatile uint32  *)0xFFF89204UL))

/* Backup register 0 */
#define MCU_BRAMDAT0                        (*((volatile uint32  *)0xFFC0A000UL))


/* CLMA0 compare register L */
#define MCU_CLMA0CMPL                       (*((volatile uint16  *)0xFFF88408UL))

/* CLMA0 compare register H */
#define MCU_CLMA0CMPH                       (*((volatile uint16  *)0xFFF8840CUL))

/* CLMA1 compare register L */
#define MCU_CLMA1CMPL                       (*((volatile uint16  *)0xFFF88428UL))

/* CLMA1 compare register H */
#define MCU_CLMA1CMPH                       (*((volatile uint16  *)0xFFF8842CUL))

/* CLMA2 compare register L */
#define MCU_CLMA2CMPL                       (*((volatile uint16  *)0xFFF88448UL))

/* CLMA2 compare register H */
#define MCU_CLMA2CMPH                       (*((volatile uint16  *)0xFFF8844CUL))

/* CLMA3 compare register L */
#define MCU_CLMA3CMPL                       (*((volatile uint16  *)0xFFF88468UL))

/* CLMA3 compare register H */
#define MCU_CLMA3CMPH                       (*((volatile uint16  *)0xFFF8846CUL))

/* ECM delay timer register */
#define MCU_ECMDTMR                         (*((volatile uint16  *)0xFFD62040UL))

/* ECM delay timer compare register */
#define MCU_ECMDTMCMP                       (*((volatile uint16  *)0xFFD62044UL))

/* ECM interrupt mask control register */
#define MCU_IMR0EIMK8                       (*((volatile uint16  *)0xFFFEEAF0UL))

/* Maskable interrupt enable register for ECM */
#define MCU_INTC1EIC8                       (*((volatile uint16  *)0xFFFEEA10UL))


/* CVM factor register */
#define MCU_CVMF                            (*((volatile uint8  *)0xFFF82820UL))

/* CVM detection enable register */
#define MCU_CVMDE                           (*((volatile uint8  *)0xFFF82824UL))

/* CVM detection output mask register */
#define MCU_CVMDMASK                        (*((volatile uint8  *)0xFFF8282CUL))

/* CVM monitor Register */
#define MCU_CVMMON                          (*((volatile uint8  *)0xFFF82834UL))

/* CLMA0 protect command register */
#define MCU_CLMA0PCMD                       (*((volatile uint8  *)0xFFF88410UL))

/* CLMA0 protect status register */
#define MCU_CLMA0PS                         (*((volatile uint8  *)0xFFF88414UL))

/* CLMA1 protect command register */
#define MCU_CLMA1PCMD                       (*((volatile uint8  *)0xFFF88430UL))

/* CLMA1 protect status register */
#define MCU_CLMA1PS                         (*((volatile uint8  *)0xFFF88434UL))

/* CLMA2 protect command register */
#define MCU_CLMA2PCMD                       (*((volatile uint8  *)0xFFF88450UL))

/* CLMA2 protect status register */
#define MCU_CLMA2PS                         (*((volatile uint8  *)0xFFF88454UL))

/* CLMA3 protect command register */
#define MCU_CLMA3PCMD                       (*((volatile uint8  *)0xFFF88470UL))

/* CLMA3 protect status register */
#define MCU_CLMA3PS                         (*((volatile uint8  *)0xFFF88474UL))

/* ECM master error clear address */
#define MCU_ECMMECLR                        (*((volatile uint8  *)0xFFD60004UL))

/* ECM checker error clear trigger register */
#define MCU_ECMCECLR                        (*((volatile uint8  *)0xFFD61004UL))

/* ECM master error set trigger register */
#define MCU_ECMMESET                        (*((volatile uint8  *)0xFFD60000UL))

/* ECM checker error set trigger register */
#define MCU_ECMCESET                        (*((volatile uint8  *)0xFFD61000UL))

/* ECM error pulse configuration register */
#define MCU_ECMEPCFG                        (*((volatile uint8  *)0xFFD62000UL))

/* ECM protection status register */
#define MCU_ECMPS                           (*((volatile uint8  *)0xFFD62030UL))

/* ECM delay timer control register */
#define MCU_ECMDTMCTL                       (*((volatile uint8  *)0xFFD6203CUL))

/* ECM error pulse control register */
#define MCU_ECMEPCTL                        (*((volatile uint8  *)0xFFD63000UL))

/* Mcu clock monitor 0 control reg address */
#define MCU_CLMA0CTL0                       (*((volatile uint8  *)0xFFF88400UL))

/* Mcu clock monitor 1 control reg address */
#define MCU_CLMA1CTL0                       (*((volatile uint8  *)0xFFF88420UL))

/* Mcu clock monitor 2 control reg address */
#define MCU_CLMA2CTL0                       (*((volatile uint8  *)0xFFF88440UL))

/* Mcu clock monitor 3 control reg address */
#define MCU_CLMA3CTL0                       (*((volatile uint8  *)0xFFF88460UL))

/* CVM factor clear register */
#define MCU_CVMFC                           (*((volatile uint8  *)0xFFF82838UL))

/* CVM detection enable setting register */
#define MCU_CVMDEW                          (*((volatile uint8  *)0xFFF8283CUL))

/* CVM Diagnostic Function Control Register */
#define MCU_CVMDIAG                         (*((volatile uint8  *)0xFFF82830UL))


/* ECM Base address */
#define MCU_ECM_BASE_ADDRESS                ((uint32)0xFFD62000UL)


/* END Msg(4:0857)-1 */
/*******************************************************************************
**                      Global Data Types                                     **
*******************************************************************************/

/*******************************************************************************
**                      Function Prototypes                                   **
*******************************************************************************/

#endif /* MCU_REG_H */

/*******************************************************************************
**                      End of File                                           **
*******************************************************************************/
