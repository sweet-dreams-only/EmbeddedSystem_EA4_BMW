/*============================================================================*/
/* Project      = AUTOSAR Renesas P1x MCAL Components                         */
/* Module       = P1x_translation.h                                           */
/*============================================================================*/
/*                                  COPYRIGHT                                 */
/*============================================================================*/
/* Copyright(c) 2013-2017 Renesas Electronics Corporation                     */
/*============================================================================*/
/* Purpose:                                                                   */
/* This translation file maps device file macros with user defined            */
/* (RENESAS) macros.  Generator uses this translation file inorder to         */
/* avoid hardcoding of base addressess or the usage of device header file     */
/* macros directly.                                                           */
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
/*              Devices:        RH850/P1M:  R7F701304, R7F701305, R7F701310,  */
/*                                          R7F701311, R7F701312, R7F701313,  */
/*                                          R7F701314, R7F701315, R7F701318,  */
/*                                          R7F701319, R7F701320, R7F701321,  */
/*                                          R7F701322, R7F701323              */
/*============================================================================*/

/*******************************************************************************
**                      Revision Control History                              **
*******************************************************************************/
/*
 * V1.0.0:   21-Aug-2013  : Initial version
 *
 * V1.0.1:   21-Jan-2014  : File updated for SPI, FLS clock reference and ADC
 *                          macro
 *
 * V1.0.2:   02-Apr-2014  : File updated for ADC and MCU macros.
 *
 * V1.0.3:   11-Jul-2014  : File updated for PORT macros.
 *
 * V1.0.4:   19-Aug-2014  : File updated for PORT and ICU macros.
 *
 * V1.0.5:   10-Sep-2014  : File updated for MCU and FLSTST macros.
 *
 * V1.0.6:   29-Apr-2015  : File updated for FLS and CAN macros.
 *
 * V1.0.7:   06-Oct-2015  : As part of V4.00.05 release, following changes
 *                          are made -
 *                          1. File updated for ADC macros.
 *                          2. File updated for FLS macros.
 *                          3. As part of ARDAAAE-1481, file updated for MCU
 *                             module to add macros for ADC clock selection
 *                             registers.
 *                          4.As part of ARDAAAE-1533, File is updated for
 *                            adding macros for SPI ECC registers.
 *                          5.As part of ARDAAAE-912,macro RENESAS_DNFA41ENL
 *                            is updated.
 * V1.0.8:   21-Feb-2017  : Following changes are done:
 *                          1.Updated supported devices list in 'Environment'.
 *                          2.Updated copyright information.
 */
/******************************************************************************/
/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/

/*******************************************************************************
**                      Version Information                                   **
*******************************************************************************/

/*******************************************************************************
**                      Global Symbols                                        **
*******************************************************************************/

/*******************************************************************************
**                      Global Data Types                                     **
*******************************************************************************/

/*******************************************************************************
**                 Macros for PORT Driver                                    **
*******************************************************************************/
#define RENESAS_P0           PORTP0
#define RENESAS_PSR0         PORTPSR0
#define RENESAS_PPR0         PORTPPR0
#define RENESAS_PM0          PORTPM0
#define RENESAS_PMC0         PORTPMC0
#define RENESAS_PFC0         PORTPFC0
#define RENESAS_PFCE0        PORTPFCE0
#define RENESAS_PFCAE0       PORTPFCAE0
#define RENESAS_PNOT0        PORTPNOT0
#define RENESAS_PMSR0        PORTPMSR0
#define RENESAS_PMCSR0       PORTPMCSR0
#define RENESAS_PINV0        PORTPINV0
#define RENESAS_PIBC0        PORTPIBC0
#define RENESAS_PBDC0        PORTPBDC0
#define RENESAS_PIPC0        PORTPIPC0
#define RENESAS_PU0          PORTPU0
#define RENESAS_PD0          PORTPD0
#define RENESAS_PODC0        PORTPODC0
#define RENESAS_PODCE0       PORTPODCE0
#define RENESAS_PDSC0        PORTPDSC0
#define RENESAS_PUCC0        PORTPUCC0
#define RENESAS_PISA0        PORTPISA0
#define RENESAS_PPCMD0       PORTPPCMD0

#define RENESAS_P1           PORTP1
#define RENESAS_PSR1         PORTPSR1
#define RENESAS_PPR1         PORTPPR1
#define RENESAS_PM1          PORTPM1
#define RENESAS_PMC1         PORTPMC1
#define RENESAS_PFC1         PORTPFC1
#define RENESAS_PFCE1        PORTPFCE1
#define RENESAS_PFCAE1       PORTPFCAE1
#define RENESAS_PNOT1        PORTPNOT1
#define RENESAS_PMSR1        PORTPMSR1
#define RENESAS_PMCSR1       PORTPMCSR1
#define RENESAS_PINV1        PORTPINV1
#define RENESAS_PIBC1        PORTPIBC1
#define RENESAS_PBDC1        PORTPBDC1
#define RENESAS_PIPC1        PORTPIPC1
#define RENESAS_PU1          PORTPU1
#define RENESAS_PD1          PORTPD1
#define RENESAS_PODC1        PORTPODC1
#define RENESAS_PODCE1       PORTPODCE1
#define RENESAS_PISA1        PORTPISA1
#define RENESAS_PDSC1        PORTPDSC1
#define RENESAS_PUCC1        PORTPUCC1
#define RENESAS_PPCMD1       PORTPPCMD1

#define RENESAS_P2           PORTP2
#define RENESAS_PSR2         PORTPSR2
#define RENESAS_PPR2         PORTPPR2
#define RENESAS_PM2          PORTPM2
#define RENESAS_PMC2         PORTPMC2
#define RENESAS_PFC2         PORTPFC2
#define RENESAS_PFCE2        PORTPFCE2
#define RENESAS_PFCAE2       PORTPFCAE2
#define RENESAS_PNOT2        PORTPNOT2
#define RENESAS_PMSR2        PORTPMSR2
#define RENESAS_PMCSR2       PORTPMCSR2
#define RENESAS_PINV2        PORTPINV2
#define RENESAS_PIBC2        PORTPIBC2
#define RENESAS_PBDC2        PORTPBDC2
#define RENESAS_PIPC2        PORTPIPC2
#define RENESAS_PU2          PORTPU2
#define RENESAS_PD2          PORTPD2
#define RENESAS_PODC2        PORTPODC2
#define RENESAS_PODCE2       PORTPODCE2
#define RENESAS_PISA2        PORTPISA2
#define RENESAS_PDSC2        PORTPDSC2
#define RENESAS_PUCC2        PORTPUCC2
#define RENESAS_PPROTS2      PORTPPROTS2
#define RENESAS_PPCMD2       PPCMD2

#define RENESAS_P3           PORTP3
#define RENESAS_PSR3         PORTPSR3
#define RENESAS_PPR3         PORTPPR3
#define RENESAS_PM3          PORTPM3
#define RENESAS_PMC3         PORTPMC3
#define RENESAS_PFC3         PORTPFC3
#define RENESAS_PFCE3        PORTPFCE3
#define RENESAS_PFCAE3       PORTPFCAE3
#define RENESAS_PNOT3        PORTPNOT3
#define RENESAS_PMSR3        PORTPMSR3
#define RENESAS_PMCSR3       PORTPMCSR3
#define RENESAS_PINV3        PORTPINV3
#define RENESAS_PIBC3        PORTPIBC3
#define RENESAS_PBDC3        PORTPBDC3
#define RENESAS_PIPC3        PORTPIPC3
#define RENESAS_PU3          PORTPU3
#define RENESAS_PD3          PORTPD3
#define RENESAS_PODC3        PORTPODC3
#define RENESAS_PODCE3       PORTPODCE3
#define RENESAS_PISA3        PORTPISA3
#define RENESAS_PDSC3        PORTPDSC3
#define RENESAS_PUCC3        PORTPUCC3
#define RENESAS_PPROTS3      PORTPPROTS3
#define RENESAS_PPCMD3       PPCMD3

#define RENESAS_P4           PORTP4
#define RENESAS_PSR4         PORTPSR4
#define RENESAS_PPR4         PORTPPR4
#define RENESAS_PM4          PORTPM4
#define RENESAS_PMC4         PORTPMC4
#define RENESAS_PFC4         PORTPFC4
#define RENESAS_PFCE4        PORTPFCE4
#define RENESAS_PFCAE4       PORTPFCAE4
#define RENESAS_PNOT4        PORTPNOT4
#define RENESAS_PMSR4        PORTPMSR4
#define RENESAS_PMCSR4       PORTPMCSR4
#define RENESAS_PINV4        PORTPINV4
#define RENESAS_PIBC4        PORTPIBC4
#define RENESAS_PBDC4        PORTPBDC4
#define RENESAS_PIPC4        PORTPIPC4
#define RENESAS_PU4          PORTPU4
#define RENESAS_PD4          PORTPD4
#define RENESAS_PODC4        PORTPODC4
#define RENESAS_PODCE4       PORTPODCE4
#define RENESAS_PISA4        PORTPISA4
#define RENESAS_PDSC4        PORTPDSC4
#define RENESAS_PUCC4        PORTPUCC4
#define RENESAS_PPROTS4      PORTPPROTS4
#define RENESAS_PPCMD4       PPCMD4

#define RENESAS_P5           PORTP5
#define RENESAS_PSR5         PORTPSR5
#define RENESAS_PPR5         PORTPPR5
#define RENESAS_PM5          PORTPM5
#define RENESAS_PMC5         PORTPMC5
#define RENESAS_PFC5         PORTPFC5
#define RENESAS_PFCE5        PORTPFCE5
#define RENESAS_PFCAE5       PORTPFCAE5
#define RENESAS_PNOT5        PORTPNOT5
#define RENESAS_PMSR5        PORTPMSR5
#define RENESAS_PMCSR5       PORTPMCSR5
#define RENESAS_PINV5        PORTPINV5
#define RENESAS_PIBC5        PORTPIBC5
#define RENESAS_PBDC5        PORTPBDC5
#define RENESAS_PIPC5        PORTPIPC5
#define RENESAS_PU5          PORTPU5
#define RENESAS_PD5          PORTPD5
#define RENESAS_PODC5        PORTPODC5
#define RENESAS_PODCE5       PORTPODCE5
#define RENESAS_PDSC5        PORTPDSC5
#define RENESAS_PUCC5        PORTPUCC5
#define RENESAS_PPROTS5      PORTPPROTS5
#define RENESAS_PPCMD5       PORTPPCMD5

#define RENESAS_JP0          PORTJJP0
#define RENESAS_JPSR0        PORTJJPSR0
#define RENESAS_JPPR0        PORTJJPPR0
#define RENESAS_JPM0         PORTJJPM0
#define RENESAS_JPMC0        PORTJJPMC0
#define RENESAS_JPFCE0       PORTJJPFCE0
#define RENESAS_JPNOT0       PORTJJPNOT0
#define RENESAS_JPMSR0       PORTJJPMSR0
#define RENESAS_JPMCSR0      PORTJJPMCSR0
#define RENESAS_JPIBC0       PORTJJPIBC0
#define RENESAS_JPBDC0       PORTJJPBDC0
#define RENESAS_JPU0         PORTJJPU0
#define RENESAS_JPD0         PORTJJPD0
#define RENESAS_JPODC0       PORTJJPODC0
#define RENESAS_JPISA0       PORTJJPISA0
#define RENESAS_JPDSC0       PORTJJPDSC0
#define RENESAS_JPUCC0       PORTJJPUCC0
#define RENESAS_JPPROTS0     PORTJJPPROTS0
#define RENESAS_JPPCMD0      PORTJJPPCMD0

#define RENESAS_DNFA0CTL     DNFA0CTL
#define RENESAS_DNFA0EN      DNFA0EN
#define RENESAS_DNFA0ENL     DNFA0ENL

#define RENESAS_DNFA1CTL     DNFA1CTL
#define RENESAS_DNFA1EN      DNFA1EN
#define RENESAS_DNFA1ENL     DNFA1ENL

#define RENESAS_DNFA10CTL    DNFA10CTL
#define RENESAS_DNFA10EN     DNFA10EN
#define RENESAS_DNFA10ENL    DNFA10ENL

#define RENESAS_DNFA11CTL    DNFA11CTL
#define RENESAS_DNFA11EN     DNFA11EN
#define RENESAS_DNFA11ENL    DNFA11ENL

#define RENESAS_DNFA12CTL    DNFA12CTL
#define RENESAS_DNFA12EN     DNFA12EN
#define RENESAS_DNFA12ENL    DNFA12ENL

#define RENESAS_DNFA13CTL    DNFA13CTL
#define RENESAS_DNFA13EN     DNFA13EN
#define RENESAS_DNFA13ENL    DNFA13ENL

#define RENESAS_DNFA14CTL    DNFA14CTL
#define RENESAS_DNFA14EN     DNFA14EN
#define RENESAS_DNFA14ENL    DNFA14ENL

#define RENESAS_DNFA15CTL    DNFA15CTL
#define RENESAS_DNFA15EN     DNFA15EN
#define RENESAS_DNFA15ENL    DNFA15ENL

#define RENESAS_DNFA16CTL    DNFA16CTL
#define RENESAS_DNFA16EN     DNFA16EN
#define RENESAS_DNFA16ENL    DNFA16ENL

#define RENESAS_DNFA17CTL    DNFA17CTL
#define RENESAS_DNFA17EN     DNFA17EN
#define RENESAS_DNFA17ENL    DNFA17ENL

#define RENESAS_DNFA18CTL    DNFA18CTL
#define RENESAS_DNFA18EN     DNFA18EN
#define RENESAS_DNFA18ENL    DNFA18ENL

#define RENESAS_DNFA19CTL    DNFA19CTL
#define RENESAS_DNFA19EN     DNFA19EN
#define RENESAS_DNFA19ENL    DNFA19ENL

#define RENESAS_DNFA2CTL     DNFA2CTL
#define RENESAS_DNFA2EN      DNFA2EN
#define RENESAS_DNFA2ENL     DNFA2ENL

#define RENESAS_DNFA20CTL    DNFA20CTL
#define RENESAS_DNFA20EN     DNFA20EN
#define RENESAS_DNFA20ENL    DNFA20ENL

#define RENESAS_DNFA21CTL    DNFA21CTL
#define RENESAS_DNFA21EN     DNFA21EN
#define RENESAS_DNFA21ENL    DNFA21ENL

#define RENESAS_DNFA22CTL    DNFA22CTL
#define RENESAS_DNFA22EN     DNFA22EN
#define RENESAS_DNFA22ENL    DNFA22ENL

#define RENESAS_DNFA23CTL    DNFA23CTL
#define RENESAS_DNFA23EN     DNFA23EN
#define RENESAS_DNFA23ENL    DNFA23ENL

#define RENESAS_DNFA24CTL    DNFA24CTL
#define RENESAS_DNFA24EN     DNFA24EN
#define RENESAS_DNFA24ENL    DNFA24ENL

#define RENESAS_DNFA25CTL    DNFA25CTL
#define RENESAS_DNFA25EN     DNFA25EN
#define RENESAS_DNFA25ENL    DNFA25ENL

#define RENESAS_DNFA26CTL    DNFA26CTL
#define RENESAS_DNFA26EN     DNFA26EN
#define RENESAS_DNFA26ENL    DNFA26ENL

#define RENESAS_DNFA27CTL    DNFA27CTL
#define RENESAS_DNFA27EN     DNFA27EN
#define RENESAS_DNFA27ENL    DNFA27ENL

#define RENESAS_DNFA28CTL    DNFA28CTL
#define RENESAS_DNFA28EN     DNFA28EN
#define RENESAS_DNFA28ENL    DNFA28ENL

#define RENESAS_DNFA29CTL    DNFA29CTL
#define RENESAS_DNFA29EN     DNFA29EN
#define RENESAS_DNFA29ENL    DNFA29ENL

#define RENESAS_DNFA3CTL     DNFA3CTL
#define RENESAS_DNFA3EN      DNFA3EN
#define RENESAS_DNFA3ENL     DNFA3ENL

#define RENESAS_DNFA30CTL    DNFA30CTL
#define RENESAS_DNFA30EN     DNFA30EN
#define RENESAS_DNFA30ENL    DNFA30ENL

#define RENESAS_DNFA31CTL    DNFA31CTL
#define RENESAS_DNFA31EN     DNFA31EN
#define RENESAS_DNFA31ENL    DNFA31ENL

#define RENESAS_DNFA32CTL    DNFA32CTL
#define RENESAS_DNFA32EN     DNFA32EN
#define RENESAS_DNFA32ENL    DNFA32ENL

#define RENESAS_DNFA33CTL    DNFA33CTL
#define RENESAS_DNFA33EN     DNFA33EN
#define RENESAS_DNFA33ENL    DNFA33ENL

#define RENESAS_DNFA34CTL    DNFA34CTL
#define RENESAS_DNFA34EN     DNFA34EN
#define RENESAS_DNFA34ENL    DNFA34ENL

#define RENESAS_DNFA35CTL    DNFA35CTL
#define RENESAS_DNFA35EN     DNFA35EN
#define RENESAS_DNFA35ENL    DNFA35ENL

#define RENESAS_DNFA36CTL    DNFA36CTL
#define RENESAS_DNFA36EN     DNFA36EN
#define RENESAS_DNFA36ENL    DNFA36ENL

#define RENESAS_DNFA37CTL    DNFA37CTL
#define RENESAS_DNFA37EN     DNFA37EN
#define RENESAS_DNFA37ENL    DNFA37ENL

#define RENESAS_DNFA38CTL    DNFA38CTL
#define RENESAS_DNFA38EN     DNFA38EN
#define RENESAS_DNFA38ENL    DNFA38ENL

#define RENESAS_DNFA39CTL    DNFA39CTL
#define RENESAS_DNFA39EN     DNFA39EN
#define RENESAS_DNFA39ENL    DNFA39ENL

#define RENESAS_DNFA4CTL     DNFA4CTL
#define RENESAS_DNFA4EN      DNFA4EN
#define RENESAS_DNFA4ENL     DNFA4ENL

#define RENESAS_DNFA40CTL    DNFA40CTL
#define RENESAS_DNFA40EN     DNFA40EN
#define RENESAS_DNFA40ENL    DNFA40ENL

#define RENESAS_DNFA41CTL    DNFA41CTL
#define RENESAS_DNFA41EN     DNFA41EN
#define RENESAS_DNFA41ENL    DNFA41ENL

#define RENESAS_DNFA42CTL    DNFA42CTL
#define RENESAS_DNFA42EN     DNFA42EN
#define RENESAS_DNFA42ENL    DNFA42ENL

#define RENESAS_DNFA43CTL    DNFA43CTL
#define RENESAS_DNFA43EN     DNFA43EN
#define RENESAS_DNFA43ENL    DNFA43ENL

#define RENESAS_DNFA5CTL     DNFA5CTL
#define RENESAS_DNFA5EN      DNFA5EN
#define RENESAS_DNFA5ENL     DNFA5ENL

#define RENESAS_DNFA6CTL     DNFA6CTL
#define RENESAS_DNFA6EN      DNFA6EN
#define RENESAS_DNFA6ENL     DNFA6ENL

#define RENESAS_DNFA7CTL     DNFA7CTL
#define RENESAS_DNFA7EN      DNFA7EN
#define RENESAS_DNFA7ENL     DNFA7ENL

#define RENESAS_DNFA8CTL     DNFA8CTL
#define RENESAS_DNFA8EN      DNFA8EN
#define RENESAS_DNFA8ENL     DNFA8ENL

#define RENESAS_DNFA9CTL     DNFA9CTL
#define RENESAS_DNFA9EN      DNFA9EN
#define RENESAS_DNFA9ENL     DNFA9ENL

#define RENESAS_DNFCKS100C   SYSDNFCKS100C
#define RENESAS_DNFCKS101C   SYSDNFCKS101C
#define RENESAS_DNFCKS106C   SYSDNFCKS106C
#define RENESAS_DNFCKS107C   SYSDNFCKS107C
#define RENESAS_DNFCKS108C   SYSDNFCKS108C
#define RENESAS_DNFCKS109C   SYSDNFCKS109C
#define RENESAS_DNFCKS110C   SYSDNFCKS110C
#define RENESAS_DNFCKS112C   SYSDNFCKS112C
#define RENESAS_DNFCKS113C   SYSDNFCKS113C
#define RENESAS_DNFCKS114C   SYSDNFCKS114C
#define RENESAS_DNFCKS104C   SYSDNFCKS104C
#define RENESAS_DNFCKS105C   SYSDNFCKS105C
#define RENESAS_DNFCKS102C   SYSDNFCKS102C

#define RENESAS_FCLA0CTL0    FCLA0CTL0
#define RENESAS_FCLA0CTL1    FCLA0CTL1
#define RENESAS_FCLA0CTL2    FCLA0CTL2
#define RENESAS_FCLA0CTL3    FCLA0CTL3
#define RENESAS_FCLA0CTL4    FCLA0CTL4
#define RENESAS_FCLA0CTL5    FCLA0CTL5
#define RENESAS_FCLA0CTL6    FCLA0CTL6
#define RENESAS_FCLA0CTL7    FCLA0CTL7

#define RENESAS_FCLA1CTL0    FCLA1CTL0
#define RENESAS_FCLA1CTL1    FCLA1CTL1
#define RENESAS_FCLA1CTL2    FCLA1CTL2
#define RENESAS_FCLA1CTL3    FCLA1CTL3
#define RENESAS_FCLA1CTL4    FCLA1CTL4
#define RENESAS_FCLA1CTL5    FCLA1CTL5
#define RENESAS_FCLA1CTL6    FCLA1CTL6
#define RENESAS_FCLA1CTL7    FCLA1CTL7

#define RENESAS_FCLA2CTL0    FCLA2CTL0
#define RENESAS_FCLA2CTL1    FCLA2CTL1
#define RENESAS_FCLA2CTL2    FCLA2CTL2
#define RENESAS_FCLA2CTL3    FCLA2CTL3
#define RENESAS_FCLA2CTL4    FCLA2CTL4
#define RENESAS_FCLA2CTL5    FCLA2CTL5
#define RENESAS_FCLA2CTL6    FCLA2CTL6
#define RENESAS_FCLA2CTL7    FCLA2CTL7

#define RENESAS_FCLA3CTL0    FCLA3CTL0
#define RENESAS_FCLA3CTL1    FCLA3CTL1
#define RENESAS_FCLA3CTL2    FCLA3CTL2
#define RENESAS_FCLA3CTL3    FCLA3CTL3
#define RENESAS_FCLA3CTL4    FCLA3CTL4
#define RENESAS_FCLA3CTL5    FCLA3CTL5
#define RENESAS_FCLA3CTL6    FCLA3CTL6
#define RENESAS_FCLA3CTL7    FCLA3CTL7

#define RENESAS_FCLA4CTL0    FCLA4CTL0
#define RENESAS_FCLA4CTL1    FCLA4CTL1
#define RENESAS_FCLA4CTL2    FCLA4CTL2
#define RENESAS_FCLA4CTL3    FCLA4CTL3
#define RENESAS_FCLA4CTL4    FCLA4CTL4
#define RENESAS_FCLA4CTL5    FCLA4CTL5
#define RENESAS_FCLA4CTL6    FCLA4CTL6
#define RENESAS_FCLA4CTL7    FCLA4CTL7

/*******************************************************************************
**                 Macros for Watchdog Driver                                 **
*******************************************************************************/
#define RENESAS_WDTA0WDTE        WDTA0WDTE
#define RENESAS_WDTA0EVAC        WDTA0EVAC
#define RENESAS_WDTA0REF         WDTA0REF
#define RENESAS_WDTA0MD          WDTA0MD

#define RENESAS_ICWDTA0_IMR      9

#define RENESAS_ICWDTA0          INTC1EIC9


/*******************************************************************************
**                 Macros for DMA Driver                                      **
*******************************************************************************/
#define RENESAS_DMACT0IC     INTC1EIC16
#define RENESAS_DMACT1IC     INTC1EIC17
#define RENESAS_DMACT2IC     INTC1EIC18
#define RENESAS_DMACT3IC     INTC1EIC19
#define RENESAS_DMACT4IC     INTC1EIC20
#define RENESAS_DMACT5IC     INTC1EIC21
#define RENESAS_DMACT6IC     INTC1EIC22
#define RENESAS_DMACT7IC     INTC1EIC23
#define RENESAS_DMACT8IC     INTC1EIC24
#define RENESAS_DMACT9IC     INTC1EIC25
#define RENESAS_DMACT10IC    INTC1EIC26
#define RENESAS_DMACT11IC    INTC1EIC27
#define RENESAS_DMACT12IC    INTC1EIC28
#define RENESAS_DMACT13IC    INTC1EIC29
#define RENESAS_DMACT14IC    INTC1EIC30
#define RENESAS_DMACT15IC    INTC1EIC31

#define RENESAS_DMACT0IC_IMR     16
#define RENESAS_DMACT1IC_IMR     17
#define RENESAS_DMACT2IC_IMR     18
#define RENESAS_DMACT3IC_IMR     19
#define RENESAS_DMACT4IC_IMR     20
#define RENESAS_DMACT5IC_IMR     21
#define RENESAS_DMACT6IC_IMR     22
#define RENESAS_DMACT7IC_IMR     23
#define RENESAS_DMACT8IC_IMR     24
#define RENESAS_DMACT9IC_IMR     25
#define RENESAS_DMACT10IC_IMR    26
#define RENESAS_DMACT11IC_IMR    27
#define RENESAS_DMACT12IC_IMR    28
#define RENESAS_DMACT13IC_IMR    29
#define RENESAS_DMACT14IC_IMR    30
#define RENESAS_DMACT15IC_IMR    31

/*******************************************************************************
**                 Macros for ADC Driver                                      **
*******************************************************************************/
#define RENESAS_ADC00DMA   55
#define RENESAS_ADC01DMA   56
#define RENESAS_ADC02DMA   57
#define RENESAS_ADC03DMA   58
#define RENESAS_ADC04DMA   59

#define RENESAS_ADC10DMA   60
#define RENESAS_ADC11DMA   61
#define RENESAS_ADC12DMA   62
#define RENESAS_ADC13DMA   63
#define RENESAS_ADC14DMA   64

#define RENESAS_PIC2BADCX0TSEL0  PIC2BADCD0TSEL0
#define RENESAS_PIC2BADCX1TSEL0  PIC2BADCD1TSEL0
#define RENESAS_PIC2BADTEN400    PIC2BADTEN400

#define RENESAS_INTADCX0ERR_IMR  76
#define RENESAS_INTADCX1ERR_IMR  177


#define RENESAS_INTADCX0ERR   INTC2EIC76
#define RENESAS_INTADCX1ERR   INTC2EIC177


#define RENESAS_INTADCX0I0_IMR   77
#define RENESAS_INTADCX0I1_IMR   78
#define RENESAS_INTADCX0I2_IMR   79
#define RENESAS_INTADCX0I3_IMR   80
#define RENESAS_INTADCX0I4_IMR   81

#define RENESAS_INTADCX1I0_IMR    178
#define RENESAS_INTADCX1I1_IMR    179
#define RENESAS_INTADCX1I2_IMR    180
#define RENESAS_INTADCX1I3_IMR    181
#define RENESAS_INTADCX1I4_IMR    182

#define RENESAS_INTADCX0I0   INTC2EIC77
#define RENESAS_INTADCX0I1   INTC2EIC78
#define RENESAS_INTADCX0I2   INTC2EIC79
#define RENESAS_INTADCX0I3   INTC2EIC80
#define RENESAS_INTADCX0I4   INTC2EIC81

#define RENESAS_INTADCX1I0    INTC2EIC178
#define RENESAS_INTADCX1I1    INTC2EIC179
#define RENESAS_INTADCX1I2    INTC2EIC180
#define RENESAS_INTADCX1I3    INTC2EIC181
#define RENESAS_INTADCX1I4    INTC2EIC182

#define RENESAS_TSN0CR    TSN0CR

#define RENESAS_ADCX0ADTIPR3 ADCD0ADTIPR3
#define RENESAS_ADCX1ADTIPR3 ADCD1ADTIPR3
#define RENESAS_ADCX0ADTIPR4 ADCD0ADTIPR4
#define RENESAS_ADCX1ADTIPR4 ADCD1ADTIPR4

#define ADCX0DR00 ADCD0DR00
#define ADCX1DR00 ADCD1DR00

#define RENESAS_ADCX0DR00       ADCD0DR00
#define RENESAS_ADCX0DR02       ADCD0DR02
#define RENESAS_ADCX0DR04       ADCD0DR04
#define RENESAS_ADCX0DR06       ADCD0DR06
#define RENESAS_ADCX0DR08       ADCD0DR08
#define RENESAS_ADCX0DR10       ADCD0DR10
#define RENESAS_ADCX0DR12       ADCD0DR12
#define RENESAS_ADCX0DR14       ADCD0DR14
#define RENESAS_ADCX0DR16       ADCD0DR16
#define RENESAS_ADCX0DR18       ADCD0DR18
#define RENESAS_ADCX0DR20       ADCD0DR20
#define RENESAS_ADCX0DR22       ADCD0DR22

#define RENESAS_ADCX1DR00       ADCD1DR00
#define RENESAS_ADCX1DR02       ADCD1DR02
#define RENESAS_ADCX1DR04       ADCD1DR04
#define RENESAS_ADCX1DR06       ADCD1DR06
#define RENESAS_ADCX1DR08       ADCD1DR08
#define RENESAS_ADCX1DR10       ADCD1DR10
#define RENESAS_ADCX1DR12       ADCD1DR12
#define RENESAS_ADCX1DR14       ADCD1DR14
#define RENESAS_ADCX1DR16       ADCD1DR16
#define RENESAS_ADCX1DR18       ADCD1DR18
#define RENESAS_ADCX1DR20       ADCD1DR20
#define RENESAS_ADCX1DR22       ADCD1DR22

#define RENESAS_ADCX0DIR00       ADCD0DIR00
#define RENESAS_ADCX0DIR01       ADCD0DIR01
#define RENESAS_ADCX0DIR02       ADCD0DIR02
#define RENESAS_ADCX0DIR03       ADCD0DIR03
#define RENESAS_ADCX0DIR04       ADCD0DIR04
#define RENESAS_ADCX0DIR05       ADCD0DIR05
#define RENESAS_ADCX0DIR06       ADCD0DIR06
#define RENESAS_ADCX0DIR07       ADCD0DIR07
#define RENESAS_ADCX0DIR08       ADCD0DIR08
#define RENESAS_ADCX0DIR09       ADCD0DIR09
#define RENESAS_ADCX0DIR10       ADCD0DIR10
#define RENESAS_ADCX0DIR11       ADCD0DIR11
#define RENESAS_ADCX0DIR12       ADCD0DIR12
#define RENESAS_ADCX0DIR13       ADCD0DIR13
#define RENESAS_ADCX0DIR14       ADCD0DIR14
#define RENESAS_ADCX0DIR15       ADCD0DIR15
#define RENESAS_ADCX0DIR16       ADCD0DIR16
#define RENESAS_ADCX0DIR17       ADCD0DIR17
#define RENESAS_ADCX0DIR18       ADCD0DIR18
#define RENESAS_ADCX0DIR19       ADCD0DIR19
#define RENESAS_ADCX0DIR20       ADCD0DIR20
#define RENESAS_ADCX0DIR21       ADCD0DIR21
#define RENESAS_ADCX0DIR22       ADCD0DIR22
#define RENESAS_ADCX0DIR23       ADCD0DIR23

#define RENESAS_ADCX1DIR00       ADCD1DIR00
#define RENESAS_ADCX1DIR01       ADCD1DIR01
#define RENESAS_ADCX1DIR02       ADCD1DIR02
#define RENESAS_ADCX1DIR03       ADCD1DIR03
#define RENESAS_ADCX1DIR04       ADCD1DIR04
#define RENESAS_ADCX1DIR05       ADCD1DIR05
#define RENESAS_ADCX1DIR06       ADCD1DIR06
#define RENESAS_ADCX1DIR07       ADCD1DIR07
#define RENESAS_ADCX1DIR08       ADCD1DIR08
#define RENESAS_ADCX1DIR09       ADCD1DIR09
#define RENESAS_ADCX1DIR10       ADCD1DIR10
#define RENESAS_ADCX1DIR11       ADCD1DIR11
#define RENESAS_ADCX1DIR12       ADCD1DIR12
#define RENESAS_ADCX1DIR13       ADCD1DIR13
#define RENESAS_ADCX1DIR14       ADCD1DIR14
#define RENESAS_ADCX1DIR15       ADCD1DIR15
#define RENESAS_ADCX1DIR16       ADCD1DIR16
#define RENESAS_ADCX1DIR17       ADCD1DIR17
#define RENESAS_ADCX1DIR18       ADCD1DIR18
#define RENESAS_ADCX1DIR19       ADCD1DIR19
#define RENESAS_ADCX1DIR20       ADCD1DIR20
#define RENESAS_ADCX1DIR21       ADCD1DIR21
#define RENESAS_ADCX1DIR22       ADCD1DIR22
#define RENESAS_ADCX1DIR23       ADCD1DIR23

#define RENESAS_ADCX0VCR00       ADCD0VCR00
#define RENESAS_ADCX0VCR01       ADCD0VCR01
#define RENESAS_ADCX0VCR02       ADCD0VCR02
#define RENESAS_ADCX0VCR03       ADCD0VCR03
#define RENESAS_ADCX0VCR04       ADCD0VCR04
#define RENESAS_ADCX0VCR05       ADCD0VCR05
#define RENESAS_ADCX0VCR06       ADCD0VCR06
#define RENESAS_ADCX0VCR07       ADCD0VCR07
#define RENESAS_ADCX0VCR08       ADCD0VCR08
#define RENESAS_ADCX0VCR09       ADCD0VCR09
#define RENESAS_ADCX0VCR10       ADCD0VCR10
#define RENESAS_ADCX0VCR11       ADCD0VCR11
#define RENESAS_ADCX0VCR12       ADCD0VCR12
#define RENESAS_ADCX0VCR13       ADCD0VCR13
#define RENESAS_ADCX0VCR14       ADCD0VCR14
#define RENESAS_ADCX0VCR15       ADCD0VCR15
#define RENESAS_ADCX0VCR16       ADCD0VCR16
#define RENESAS_ADCX0VCR17       ADCD0VCR17
#define RENESAS_ADCX0VCR18       ADCD0VCR18
#define RENESAS_ADCX0VCR19       ADCD0VCR19
#define RENESAS_ADCX0VCR20       ADCD0VCR20
#define RENESAS_ADCX0VCR21       ADCD0VCR21
#define RENESAS_ADCX0VCR22       ADCD0VCR22
#define RENESAS_ADCX0VCR23       ADCD0VCR23

#define RENESAS_ADCX1VCR00       ADCD1VCR00
#define RENESAS_ADCX1VCR01       ADCD1VCR01
#define RENESAS_ADCX1VCR02       ADCD1VCR02
#define RENESAS_ADCX1VCR03       ADCD1VCR03
#define RENESAS_ADCX1VCR04       ADCD1VCR04
#define RENESAS_ADCX1VCR05       ADCD1VCR05
#define RENESAS_ADCX1VCR06       ADCD1VCR06
#define RENESAS_ADCX1VCR07       ADCD1VCR07
#define RENESAS_ADCX1VCR08       ADCD1VCR08
#define RENESAS_ADCX1VCR09       ADCD1VCR09
#define RENESAS_ADCX1VCR10       ADCD1VCR10
#define RENESAS_ADCX1VCR11       ADCD1VCR11
#define RENESAS_ADCX1VCR12       ADCD1VCR12
#define RENESAS_ADCX1VCR13       ADCD1VCR13
#define RENESAS_ADCX1VCR14       ADCD1VCR14
#define RENESAS_ADCX1VCR15       ADCD1VCR15
#define RENESAS_ADCX1VCR16       ADCD1VCR16
#define RENESAS_ADCX1VCR17       ADCD1VCR17
#define RENESAS_ADCX1VCR18       ADCD1VCR18
#define RENESAS_ADCX1VCR19       ADCD1VCR19
#define RENESAS_ADCX1VCR20       ADCD1VCR20
#define RENESAS_ADCX1VCR21       ADCD1VCR21
#define RENESAS_ADCX1VCR22       ADCD1VCR22
#define RENESAS_ADCX1VCR23       ADCD1VCR23

#define RENESAS_DTFR0            DMASSDTFR0
#define RENESAS_DTFR1            DMASSDTFR1
#define RENESAS_DTFR2            DMASSDTFR2
#define RENESAS_DTFR3            DMASSDTFR3
#define RENESAS_DTFR4            DMASSDTFR4
#define RENESAS_DTFR5            DMASSDTFR5
#define RENESAS_DTFR6            DMASSDTFR6
#define RENESAS_DTFR7            DMASSDTFR7
#define RENESAS_DTFR8            DMASSDTFR8
#define RENESAS_DTFR9            DMASSDTFR9
#define RENESAS_DTFR10           DMASSDTFR10
#define RENESAS_DTFR11           DMASSDTFR11
#define RENESAS_DTFR12           DMASSDTFR12
#define RENESAS_DTFR13           DMASSDTFR13
#define RENESAS_DTFR14           DMASSDTFR14
#define RENESAS_DTFR15           DMASSDTFR15

#define RENESAS_ADCDEV00 ADCDEV00
#define RENESAS_ADCDEV04 ADCDEV04
#define RENESAS_ADCDEV08 ADCDEV08
#define RENESAS_ADCDEV12 ADCDEV12
#define RENESAS_ADCDEV01 ADCDEV01
#define RENESAS_ADCDEV05 ADCDEV05
#define RENESAS_ADCDEV09 ADCDEV09
#define RENESAS_ADCDEV13 ADCDEV13

#define RENESAS_DSA0            DMASSDSA0
#define RENESAS_DSA1            DMASSDSA1
#define RENESAS_DSA2            DMASSDSA2
#define RENESAS_DSA3            DMASSDSA3
#define RENESAS_DSA4            DMASSDSA4
#define RENESAS_DSA5            DMASSDSA5
#define RENESAS_DSA6            DMASSDSA6
#define RENESAS_DSA7            DMASSDSA7
#define RENESAS_DSA8            DMASSDSA8
#define RENESAS_DSA9            DMASSDSA9
#define RENESAS_DSA10           DMASSDSA10
#define RENESAS_DSA11           DMASSDSA11
#define RENESAS_DSA12           DMASSDSA12
#define RENESAS_DSA13           DMASSDSA13
#define RENESAS_DSA14           DMASSDSA14
#define RENESAS_DSA15           DMASSDSA15

#define RENESAS_ADOPDIG0        ADCD0ADOPDIG0
#define RENESAS_ADOPDIG1        ADCD1ADOPDIG1

/*******************************************************************************
**                 Macros for MCU Driver                                      **
*******************************************************************************/
#define RENESAS_PROTCMD1                 PROTCMD1
#define RENESAS_PROTCMDCVM               SYSPROTCMDCVM
#define RENESAS_PROTSCVM                 SYSPROTSCVM

#define RENESAS_PPROTS0                  PORTPPROTS0
#define RENESAS_PPROTS1                  PPROTS1

#define RENESAS_SWRESA                   SYSSWRESA


#define RENESAS_CLMATEST                 CLMACCLMATEST
#define RENESAS_CLMATESTS                CLMACCLMATESTS
#define RENESAS_CLMA0CMPH                CLMA0CMPH
#define RENESAS_CLMA0CMPL                CLMA0CMPL
#define RENESAS_CLMA0CTL0                CLMA0CTL0
#define RENESAS_CLMA0PCMD                CLMA0PCMD
#define RENESAS_CLMA0PS                  CLMA0PS
#define RENESAS_CLMA1CMPH                CLMA1CMPH
#define RENESAS_CLMA1CMPL                CLMA1CMPL
#define RENESAS_CLMA1CTL0                CLMA1CTL0
#define RENESAS_CLMA1PCMD                CLMA1PCMD
#define RENESAS_CLMA1PS                  CLMA1PS
#define RENESAS_CLMA2CMPH                CLMA2CMPH
#define RENESAS_CLMA2CMPL                CLMA2CMPL
#define RENESAS_CLMA2CTL0                CLMA2CTL0
#define RENESAS_CLMA2PCMD                CLMA2PCMD
#define RENESAS_CLMA2PS                  CLMA2PS
#define RENESAS_CLMA3CMPH                CLMA3CMPH
#define RENESAS_CLMA3CMPL                CLMA3CMPL
#define RENESAS_CLMA3CTL0                CLMA3CTL0
#define RENESAS_CLMA3PCMD                CLMA3PCMD
#define RENESAS_CLMA3PS                  CLMA3PS
#define RENESAS_LVICNT                   SYSLVICNT
#define RENESAS_RESF                     SYSRESF
#define RENESAS_RESFC                    SYSRESFC
#define RENESAS_POF                      SYSPOF
#define RENESAS_POFC                     SYSPOFC
#define RENESAS_CKSC0STAT                SYSCSC0STAT
#define RENESAS_CKSC1STAT                SYSCSC1STAT
#define RENESAS_CKSC0CTL                 SYSCKSC0CTL
#define RENESAS_CLKD0DIV                 SYSCLKD0DIV
#define RENESAS_CLKD1DIV                 SYSCLKD1DIV
#define RENESAS_CLKD0STAT                SYSCLKD0STAT
#define RENESAS_CLKD1STAT                SYSCLKD1STAT
#define RENESAS_CKSC1CTL                 SYSCKSC1CTL
#define RENESAS_ADCKSC0CTL               SYSADCKSC0CTL
#define RENESAS_ADCKSC0STAT              SYSADCSC0STAT
#define RENESAS_CVMF                     SYSCVMF
#define RENESAS_CVMFC                    SYSCVMFC
#define RENESAS_CVMDE                    SYSCVMDE
#define RENESAS_CVMDEW                   SYSCVMDEW
#define RENESAS_CVMDMASK                 SYSCVMDMASK
#define RENESAS_CVMDIAG                  SYSCVMDIAG
#define RENESAS_CVMMON                   SYSCVMMON
#define RENESAS_CVMREN                   SYSCVMREN

#define RENESAS_PROT1PHCMD               SYSPROT1PHCMD
#define RENESAS_PROT1PS                  SYSPROT1PS

#define RENESAS_ECMMESET                 ECMMESET
#define RENESAS_ECMMECLR                 ECMMECLR
#define RENESAS_ECMMESSTR0               ECMMESSTR0
#define RENESAS_ECMMESSTR1               ECMMESSTR1
#define RENESAS_ECMMPCMD0                ECMMPCMD0

#define RENESAS_ECMCESET                 ECMCESET
#define RENESAS_ECMCECLR                 ECMCECLR
#define RENESAS_ECMCESSTR0               ECMCESSTR0
#define RENESAS_ECMCESSTR1               ECMCESSTR1
#define RENESAS_ECMCPCMD0                ECMCPCMD0

#define RENESAS_ECMEPCFG                 ECMEPCFG
#define RENESAS_ECMMICFG0                ECMMICFG0
#define RENESAS_ECMMICFG1                ECMMICFG1
#define RENESAS_ECMNMICFG0               ECMNMICFG0
#define RENESAS_ECMNMICFG1               ECMNMICFG1
#define RENESAS_ECMIRCFG0                ECMIRCFG0
#define RENESAS_ECMIRCFG1                ECMIRCFG1
#define RENESAS_ECMEMK0                  ECMEMK0
#define RENESAS_ECMEMK1                  ECMEMK1
#define RENESAS_ECMESSTC0                ECMESSTC0
#define RENESAS_ECMESSTC1                ECMESSTC1
#define RENESAS_ECMPCMD1                 ECMPCMD1
#define RENESAS_ECMPS                    ECMPS
#define RENESAS_ECMPE0                   ECMPE0
#define RENESAS_ECMPE1                   ECMPE1
#define RENESAS_ECMEPCTL                 ECMEPCTL
#define RENESAS_ECMDTMCTL                ECMDTMCTL
#define RENESAS_ECMDTMR                  ECMDTMR
#define RENESAS_ECMDTMCMP                ECMDTMCMP
#define RENESAS_ECMDTMCFG0               ECMDTMCFG0
#define RENESAS_ECMDTMCFG1               ECMDTMCFG1
#define RENESAS_ECMDTMCFG2               ECMDTMCFG2
#define RENESAS_ECMDTMCFG3               ECMDTMCFG3
#define RENESAS_EIBD8                    INTC1EIBD8
#define RENESAS_IMR0EIMK8                INTC1IMR0
#define RENESAS_ECMEMK0HH                ECMEMK0HH
#define RENESAS_ECMMICFG0HH              ECMMICFG0HH
#define RENESAS_ECMNMICFG0HH             ECMNMICFG0HH
#define RENESAS_ECMIRCFG0HH              ECMIRCFG0HH

#define RENESAS_TESTCOMPREG0             TESTCOMPREG0
#define RENESAS_TESTCOMPREG1             TESTCOMPREG1

#define RENESAS_ECM_BASE_ADDRESS         ECMEPCFG
#define RENESAS_INTC1EIC8        INTC1EIC8
/*******************************************************************************
**              Common Macros for ICU, GPT and PWM Drivers                    **
*******************************************************************************/

/* Base address of the TAUD0 channel 0 registers structure */
#define RENESAS_TAUD0CDR0       TAUD0CDR0

/* Base address of the TAUD0 channel 1 registers structure */
#define RENESAS_TAUD0CDR1       TAUD0CDR1

/* Base address of the TAUD0 channel 2 registers structure */
#define RENESAS_TAUD0CDR2       TAUD0CDR2

/* Base address of the TAUD0 channel 3 registers structure */
#define RENESAS_TAUD0CDR3       TAUD0CDR3

/* Base address of the TAUD0 channel 4 registers structure */
#define RENESAS_TAUD0CDR4       TAUD0CDR4

/* Base address of the TAUD0 channel 5 registers structure */
#define RENESAS_TAUD0CDR5       TAUD0CDR5

/* Base address of the TAUD0 channel 6 registers structure */
#define RENESAS_TAUD0CDR6       TAUD0CDR6

/* Base address of the TAUD0 channel 7 registers structure */
#define RENESAS_TAUD0CDR7       TAUD0CDR7

/* Base address of the TAUD0 channel 8 registers structure */
#define RENESAS_TAUD0CDR8       TAUD0CDR8

/* Base address of the TAUD0 channel 9 registers structure */
#define RENESAS_TAUD0CDR9       TAUD0CDR9

/* Base address of the TAUD0 channel 10 registers structure */
#define RENESAS_TAUD0CDR10      TAUD0CDR10

/* Base address of the TAUD0 channel 11 registers structure */
#define RENESAS_TAUD0CDR11      TAUD0CDR11

/* Base address of the TAUD0 channel 12 registers structure */
#define RENESAS_TAUD0CDR12      TAUD0CDR12

/* Base address of the TAUD0 channel 13 registers structure */
#define RENESAS_TAUD0CDR13      TAUD0CDR13

/* Base address of the TAUD0 channel 14 registers structure */
#define RENESAS_TAUD0CDR14      TAUD0CDR14

/* Base address of the TAUD0 channel 15 registers structure */
#define RENESAS_TAUD0CDR15      TAUD0CDR15

/* Base address of the TAUD1 channel 0 registers structure */
#define RENESAS_TAUD1CDR0       TAUD1CDR0

/* Base address of the TAUD1 channel 1 registers structure */
#define RENESAS_TAUD1CDR1       TAUD1CDR1

/* Base address of the TAUD1 channel 2 registers structure */
#define RENESAS_TAUD1CDR2       TAUD1CDR2

/* Base address of the TAUD1 channel 3 registers structure */
#define RENESAS_TAUD1CDR3       TAUD1CDR3

/* Base address of the TAUD1 channel 4 registers structure */
#define RENESAS_TAUD1CDR4       TAUD1CDR4

/* Base address of the TAUD1 channel 5 registers structure */
#define RENESAS_TAUD1CDR5       TAUD1CDR5

/* Base address of the TAUD1 channel 6 registers structure */
#define RENESAS_TAUD1CDR6       TAUD1CDR6

/* Base address of the TAUD1 channel 7 registers structure */
#define RENESAS_TAUD1CDR7       TAUD1CDR7

/* Base address of the TAUD1 channel 8 registers structure */
#define RENESAS_TAUD1CDR8       TAUD1CDR8

/* Base address of the TAUD1 channel 9 registers structure */
#define RENESAS_TAUD1CDR9       TAUD1CDR9

/* Base address of the TAUD1 channel 10 registers structure */
#define RENESAS_TAUD1CDR10      TAUD1CDR10

/* Base address of the TAUD1 channel 11 registers structure */
#define RENESAS_TAUD1CDR11      TAUD1CDR11

/* Base address of the TAUD1 channel 12 registers structure */
#define RENESAS_TAUD1CDR12      TAUD1CDR12

/* Base address of the TAUD1 channel 13 registers structure */
#define RENESAS_TAUD1CDR13      TAUD1CDR13

/* Base address of the TAUD1 channel 14 registers structure */
#define RENESAS_TAUD1CDR14      TAUD1CDR14

/* Base address of the TAUD1 channel 15 registers structure */
#define RENESAS_TAUD1CDR15      TAUD1CDR15

/* Base address of the TAUD2 channel 0 registers structure */
#define RENESAS_TAUD2CDR0       TAUD2CDR0

/* Base address of the TAUD2 channel 1 registers structure */
#define RENESAS_TAUD2CDR1       TAUD2CDR1

/* Base address of the TAUD2 channel 2 registers structure */
#define RENESAS_TAUD2CDR2       TAUD2CDR2

/* Base address of the TAUD2 channel 3 registers structure */
#define RENESAS_TAUD2CDR3       TAUD2CDR3

/* Base address of the TAUD2 channel 4 registers structure */
#define RENESAS_TAUD2CDR4       TAUD2CDR4

/* Base address of the TAUD2 channel 5 registers structure */
#define RENESAS_TAUD2CDR5       TAUD2CDR5

/* Base address of the TAUD2 channel 6 registers structure */
#define RENESAS_TAUD2CDR6       TAUD2CDR6

/* Base address of the TAUD2 channel 7 registers structure */
#define RENESAS_TAUD2CDR7       TAUD2CDR7

/* Base address of the TAUD2 channel 8 registers structure */
#define RENESAS_TAUD2CDR8       TAUD2CDR8

/* Base address of the TAUD2 channel 9 registers structure */
#define RENESAS_TAUD2CDR9       TAUD2CDR9

/* Base address of the TAUD2 channel 10 registers structure */
#define RENESAS_TAUD2CDR10      TAUD2CDR10

/* Base address of the TAUD2 channel 11 registers structure */
#define RENESAS_TAUD2CDR11      TAUD2CDR11

/* Base address of the TAUD2 channel 12 registers structure */
#define RENESAS_TAUD2CDR12      TAUD2CDR12

/* Base address of the TAUD2 channel 13 registers structure */
#define RENESAS_TAUD2CDR13      TAUD2CDR13

/* Base address of the TAUD2 channel 14 registers structure */
#define RENESAS_TAUD2CDR14      TAUD2CDR14

/* Base address of the TAUD2 channel 15 registers structure */
#define RENESAS_TAUD2CDR15      TAUD2CDR15
/* Base address of the TAUJ0 channel 0 registers structure */
#define RENESAS_TAUJ0CDR0       TAUJ0CDR0

/* Base address of the TAUJ0 channel 1 registers structure */
#define RENESAS_TAUJ0CDR1       TAUJ0CDR1

/* Base address of the TAUJ0 channel 2 registers structure */
#define RENESAS_TAUJ0CDR2       TAUJ0CDR2

/* Base address of the TAUJ0 channel 3 registers structure */
#define RENESAS_TAUJ0CDR3       TAUJ0CDR3

/* Base address of the TAUJ1 channel 0 registers structure */
#define RENESAS_TAUJ1CDR0       TAUJ1CDR0

/* Base address of the TAUJ1 channel 1 registers structure */
#define RENESAS_TAUJ1CDR1       TAUJ1CDR1

/* Base address of the TAUJ1 channel 2 registers structure */
#define RENESAS_TAUJ1CDR2       TAUJ1CDR2

/* Base address of the TAUJ1 channel 3 registers structure */
#define RENESAS_TAUJ1CDR3       TAUJ1CDR3

/* Base address of the TAUJ2 channel 0 registers structure */
#define RENESAS_TAUJ2CDR0       TAUJ2CDR0

/* Base address of the TAUJ2 channel 1 registers structure */
#define RENESAS_TAUJ2CDR1       TAUJ2CDR1

/* Base address of the TAUJ2 channel 2 registers structure */
#define RENESAS_TAUJ2CDR2       TAUJ2CDR2

/* Base address of the TAUJ2 channel 3 registers structure */
#define RENESAS_TAUJ2CDR3       TAUJ2CDR3

/* Base address of the OSTM0 channel 0 registers structure */
#define RENESAS_OSTM0CMP         OSTM0CMP

/* Base address of the OSTM1 channel 0 registers structure */
#define RENESAS_OSTM1CMP         OSTM1CMP

/* Base address of the OSTM3 channel 0 registers structure */
#define RENESAS_OSTM3CMP         OSTM3CMP

/* Base address of the OSTM4 channel 0 registers structure */
#define RENESAS_OSTM4CMP         OSTM4CMP

/* Base address of the OSTM5 channel 0 registers structure */
#define RENESAS_OSTM5CMP         OSTM5CMP

/* Base address of the OSTM6 channel 0 registers structure */
#define RENESAS_OSTM6CMP         OSTM6CMP

/* Base address of the OSTM7 channel 0 registers structure */
#define RENESAS_OSTM7CMP         OSTM7CMP

/* Base address of the OSTM0 channel 0 registers structure */
#define RENESAS_OSTM0CTL         OSTM0CTL

/* Base address of the OSTM1 channel 0 registers structure */
#define RENESAS_OSTM1CTL         OSTM1CTL

/* Base address of the OSTM3 channel 0 registers structure */
#define RENESAS_OSTM3CTL         OSTM3CTL

/* Base address of the OSTM4 channel 0 registers structure */
#define RENESAS_OSTM4CTL         OSTM4CTL

/* Base address of the OSTM5 channel 0 registers structure */
#define RENESAS_OSTM5CTL         OSTM5CTL

/* Base address of the OSTM6 channel 0 registers structure */
#define RENESAS_OSTM6CTL         OSTM6CTL

/* Base address of the OSTM7 channel 0 registers structure */
#define RENESAS_OSTM7CTL         OSTM7CTL

/* Base address of the OSTM registers structure */
#define RENESAS_OSTM3_FEINT       FEINTF
#define RENESAS_OSTM4_FEINT       FEINTF
#define RENESAS_OSTM5_FEINT       FEINTF
#define RENESAS_OSTM6_FEINT       FEINTF
#define RENESAS_OSTM7_FEINT       FEINTF

#define RENESAS_OSTM3_FEINTC      FEINTFC
#define RENESAS_OSTM4_FEINTC      FEINTFC
#define RENESAS_OSTM5_FEINTC      FEINTFC
#define RENESAS_OSTM6_FEINTC      FEINTFC
#define RENESAS_OSTM7_FEINTC      FEINTFC

/* Base address of the TAUD Unit user control registers structure PWM*/
#define RENESAS_TAUD0TOL        TAUD0TOL
#define RENESAS_TAUD1TOL        TAUD1TOL
#define RENESAS_TAUD2TOL        TAUD2TOL

/* Base address of the TAUJ Unit user control registers structure PWM*/
#define RENESAS_TAUJ0TOL        TAUJ0TOL
#define RENESAS_TAUJ1TOL        TAUJ1TOL
#define RENESAS_TAUJ2TOL        TAUJ2TOL

/* Base address of the TAUD Unit user control registers structure PWM*/
#define RENESAS_TAUD0TE        TAUD0TE
#define RENESAS_TAUD1TE        TAUD1TE
#define RENESAS_TAUD2TE        TAUD2TE

/* Base address of the TAUJ Unit user control registers structure PWM*/
#define RENESAS_TAUJ0TE        TAUJ0TE
#define RENESAS_TAUJ1TE        TAUJ1TE
#define RENESAS_TAUJ2TE        TAUJ2TE

/* Base address of the TAUD Unit user control registers structure PWM*/
#define RENESAS_TAUD0TS        TAUD0TS
#define RENESAS_TAUD1TS        TAUD1TS
#define RENESAS_TAUD2TS        TAUD2TS

/* Base address of the TAUJ Unit user control registers structure PWM*/
#define RENESAS_TAUJ0TS        TAUJ0TS
#define RENESAS_TAUJ1TS        TAUJ1TS
#define RENESAS_TAUJ2TS        TAUJ2TS

/* Base address of the TAUD Unit user control registers structure PWM*/
#define RENESAS_TAUD0TPS        TAUD0TPS
#define RENESAS_TAUD1TPS        TAUD1TPS
#define RENESAS_TAUD2TPS        TAUD2TPS

/* Base address of the TAUJ Unit user control registers structure PWM*/
#define RENESAS_TAUJ0TPS        TAUJ0TPS
#define RENESAS_TAUJ1TPS        TAUJ1TPS
#define RENESAS_TAUJ2TPS        TAUJ2TPS

/* Base address of the TAUD0 registers structure */
#define RENESAS_TAUD0CMOR0      TAUD0CMOR0
#define RENESAS_TAUD0CMOR1      TAUD0CMOR1
#define RENESAS_TAUD0CMOR2      TAUD0CMOR2
#define RENESAS_TAUD0CMOR3      TAUD0CMOR3
#define RENESAS_TAUD0CMOR4      TAUD0CMOR4
#define RENESAS_TAUD0CMOR5      TAUD0CMOR5
#define RENESAS_TAUD0CMOR6      TAUD0CMOR6
#define RENESAS_TAUD0CMOR7      TAUD0CMOR7
#define RENESAS_TAUD0CMOR8      TAUD0CMOR8
#define RENESAS_TAUD0CMOR9      TAUD0CMOR9
#define RENESAS_TAUD0CMOR10     TAUD0CMOR10
#define RENESAS_TAUD0CMOR11     TAUD0CMOR11
#define RENESAS_TAUD0CMOR12     TAUD0CMOR12
#define RENESAS_TAUD0CMOR13     TAUD0CMOR13
#define RENESAS_TAUD0CMOR14     TAUD0CMOR14
#define RENESAS_TAUD0CMOR15     TAUD0CMOR15

/* Base address of the TAUD1 registers structure */
#define RENESAS_TAUD1CMOR0      TAUD1CMOR0
#define RENESAS_TAUD1CMOR1      TAUD1CMOR1
#define RENESAS_TAUD1CMOR2      TAUD1CMOR2
#define RENESAS_TAUD1CMOR3      TAUD1CMOR3
#define RENESAS_TAUD1CMOR4      TAUD1CMOR4
#define RENESAS_TAUD1CMOR5      TAUD1CMOR5
#define RENESAS_TAUD1CMOR6      TAUD1CMOR6
#define RENESAS_TAUD1CMOR7      TAUD1CMOR7
#define RENESAS_TAUD1CMOR8      TAUD1CMOR8
#define RENESAS_TAUD1CMOR9      TAUD1CMOR9
#define RENESAS_TAUD1CMOR10     TAUD1CMOR10
#define RENESAS_TAUD1CMOR11     TAUD1CMOR11
#define RENESAS_TAUD1CMOR12     TAUD1CMOR12
#define RENESAS_TAUD1CMOR13     TAUD1CMOR13
#define RENESAS_TAUD1CMOR14     TAUD1CMOR14
#define RENESAS_TAUD1CMOR15     TAUD1CMOR15

/* Base address of the TAUD2 registers structure */
#define RENESAS_TAUD2CMOR0      TAUD2CMOR0
#define RENESAS_TAUD2CMOR1      TAUD2CMOR1
#define RENESAS_TAUD2CMOR2      TAUD2CMOR2
#define RENESAS_TAUD2CMOR3      TAUD2CMOR3
#define RENESAS_TAUD2CMOR4      TAUD2CMOR4
#define RENESAS_TAUD2CMOR5      TAUD2CMOR5
#define RENESAS_TAUD2CMOR6      TAUD2CMOR6
#define RENESAS_TAUD2CMOR7      TAUD2CMOR7
#define RENESAS_TAUD2CMOR8      TAUD2CMOR8
#define RENESAS_TAUD2CMOR9      TAUD2CMOR9
#define RENESAS_TAUD2CMOR10     TAUD2CMOR10
#define RENESAS_TAUD2CMOR11     TAUD2CMOR11
#define RENESAS_TAUD2CMOR12     TAUD2CMOR12
#define RENESAS_TAUD2CMOR13     TAUD2CMOR13
#define RENESAS_TAUD2CMOR14     TAUD2CMOR14
#define RENESAS_TAUD2CMOR15     TAUD2CMOR15

/* Base address of the TAUJ0 registers structure */
#define RENESAS_TAUJ0CMOR0      TAUJ0CMOR0
#define RENESAS_TAUJ0CMOR1      TAUJ0CMOR1
#define RENESAS_TAUJ0CMOR2      TAUJ0CMOR2
#define RENESAS_TAUJ0CMOR3      TAUJ0CMOR3

/* Base address of the TAUJ1 registers structure */
#define RENESAS_TAUJ1CMOR0      TAUJ1CMOR0
#define RENESAS_TAUJ1CMOR1      TAUJ1CMOR1
#define RENESAS_TAUJ1CMOR2      TAUJ1CMOR2
#define RENESAS_TAUJ1CMOR3      TAUJ1CMOR3

/* Base address of the TAUJ2 registers structure */
#define RENESAS_TAUJ2CMOR0      TAUJ2CMOR0
#define RENESAS_TAUJ2CMOR1      TAUJ2CMOR1
#define RENESAS_TAUJ2CMOR2      TAUJ2CMOR2
#define RENESAS_TAUJ2CMOR3      TAUJ2CMOR3
/* Interrupt select register INTC2 */
#define RENESAS_SELB_INTC2      SELB_INTC2

/* Interrupt control registers for TAUD */
#define RENESAS_ICTAUD0I0       INTC2EIC141
#define RENESAS_ICTAUD0I1       INTC2EIC142
#define RENESAS_ICTAUD0I2       INTC2EIC143
#define RENESAS_ICTAUD0I3       INTC2EIC144
#define RENESAS_ICTAUD0I4       INTC2EIC145
#define RENESAS_ICTAUD0I5       INTC2EIC146
#define RENESAS_ICTAUD0I6       INTC2EIC147
#define RENESAS_ICTAUD0I7       INTC2EIC148
#define RENESAS_ICTAUD0I8       INTC2EIC149
#define RENESAS_ICTAUD0I9       INTC2EIC150
#define RENESAS_ICTAUD0I10      INTC2EIC151
#define RENESAS_ICTAUD0I11      INTC2EIC152
#define RENESAS_ICTAUD0I12      INTC2EIC153
#define RENESAS_ICTAUD0I13      INTC2EIC154
#define RENESAS_ICTAUD0I14      INTC2EIC155
#define RENESAS_ICTAUD0I15      INTC2EIC156

#define RENESAS_ICTAUD1I0       INTC2EIC158
#define RENESAS_ICTAUD1I1       INTC2EIC159
#define RENESAS_ICTAUD1I2       INTC2EIC160
#define RENESAS_ICTAUD1I3       INTC2EIC161
#define RENESAS_ICTAUD1I4       INTC2EIC162
#define RENESAS_ICTAUD1I5       INTC2EIC163
#define RENESAS_ICTAUD1I6       INTC2EIC164
#define RENESAS_ICTAUD1I7       INTC2EIC165
#define RENESAS_ICTAUD1I8       INTC2EIC166
#define RENESAS_ICTAUD1I9       INTC2EIC167
#define RENESAS_ICTAUD1I10      INTC2EIC168
#define RENESAS_ICTAUD1I11      INTC2EIC169
#define RENESAS_ICTAUD1I12      INTC2EIC170
#define RENESAS_ICTAUD1I13      INTC2EIC171
#define RENESAS_ICTAUD1I14      INTC2EIC172
#define RENESAS_ICTAUD1I15      INTC2EIC173

#define RENESAS_ICTAUD2I0       INTC2EIC260
#define RENESAS_ICTAUD2I1       INTC2EIC261
#define RENESAS_ICTAUD2I2       INTC2EIC262
#define RENESAS_ICTAUD2I3       INTC2EIC263
#define RENESAS_ICTAUD2I4       INTC2EIC264
#define RENESAS_ICTAUD2I5       INTC2EIC265
#define RENESAS_ICTAUD2I6       INTC2EIC266
#define RENESAS_ICTAUD2I7       INTC2EIC267
#define RENESAS_ICTAUD2I8       INTC2EIC268
#define RENESAS_ICTAUD2I9       INTC2EIC269
#define RENESAS_ICTAUD2I10      INTC2EIC270
#define RENESAS_ICTAUD2I11      INTC2EIC271
#define RENESAS_ICTAUD2I12      INTC2EIC272
#define RENESAS_ICTAUD2I13      INTC2EIC273
#define RENESAS_ICTAUD2I14      INTC2EIC274
#define RENESAS_ICTAUD2I15      INTC2EIC275

/* Interrupt control registers for TAUJ */
#define RENESAS_ICTAUJ0I0      INTC2EIC133
#define RENESAS_ICTAUJ0I1      INTC2EIC134
#define RENESAS_ICTAUJ0I2      INTC2EIC135
#define RENESAS_ICTAUJ0I3      INTC2EIC136

#define RENESAS_ICTAUJ1I0      INTC2EIC137
#define RENESAS_ICTAUJ1I1      INTC2EIC138
#define RENESAS_ICTAUJ1I2      INTC2EIC139
#define RENESAS_ICTAUJ1I3      INTC2EIC140

#define RENESAS_ICTAUJ2I0      INTC2EIC256
#define RENESAS_ICTAUJ2I1      INTC2EIC257
#define RENESAS_ICTAUJ2I2      INTC2EIC258
#define RENESAS_ICTAUJ2I3      INTC2EIC259


/* Interrupt control registers for OSTM0 */
#define RENESAS_ICOSTM0IIC      INTC2EIC74
#define RENESAS_ICOSTM1IIC      INTC2EIC75

/* Interrupt control registers for TAUD */
#define RENESAS_ICTAUD0I0_IMR       141
#define RENESAS_ICTAUD0I1_IMR       142
#define RENESAS_ICTAUD0I2_IMR       143
#define RENESAS_ICTAUD0I3_IMR       144
#define RENESAS_ICTAUD0I4_IMR       145
#define RENESAS_ICTAUD0I5_IMR       146
#define RENESAS_ICTAUD0I6_IMR       147
#define RENESAS_ICTAUD0I7_IMR       148
#define RENESAS_ICTAUD0I8_IMR       149
#define RENESAS_ICTAUD0I9_IMR       150
#define RENESAS_ICTAUD0I10_IMR      151
#define RENESAS_ICTAUD0I11_IMR      152
#define RENESAS_ICTAUD0I12_IMR      153
#define RENESAS_ICTAUD0I13_IMR      154
#define RENESAS_ICTAUD0I14_IMR      155
#define RENESAS_ICTAUD0I15_IMR      156

#define RENESAS_ICTAUD1I0_IMR       158
#define RENESAS_ICTAUD1I1_IMR       159
#define RENESAS_ICTAUD1I2_IMR       160
#define RENESAS_ICTAUD1I3_IMR       161
#define RENESAS_ICTAUD1I4_IMR       162
#define RENESAS_ICTAUD1I5_IMR       163
#define RENESAS_ICTAUD1I6_IMR       164
#define RENESAS_ICTAUD1I7_IMR       165
#define RENESAS_ICTAUD1I8_IMR       166
#define RENESAS_ICTAUD1I9_IMR       167
#define RENESAS_ICTAUD1I10_IMR      168
#define RENESAS_ICTAUD1I11_IMR      169
#define RENESAS_ICTAUD1I12_IMR      170
#define RENESAS_ICTAUD1I13_IMR      171
#define RENESAS_ICTAUD1I14_IMR      172
#define RENESAS_ICTAUD1I15_IMR      173

#define RENESAS_ICTAUD2I0_IMR       260
#define RENESAS_ICTAUD2I1_IMR       261
#define RENESAS_ICTAUD2I2_IMR       262
#define RENESAS_ICTAUD2I3_IMR       263
#define RENESAS_ICTAUD2I4_IMR       264
#define RENESAS_ICTAUD2I5_IMR       265
#define RENESAS_ICTAUD2I6_IMR       266
#define RENESAS_ICTAUD2I7_IMR       267
#define RENESAS_ICTAUD2I8_IMR       268
#define RENESAS_ICTAUD2I9_IMR       269
#define RENESAS_ICTAUD2I10_IMR      270
#define RENESAS_ICTAUD2I11_IMR      271
#define RENESAS_ICTAUD2I12_IMR      272
#define RENESAS_ICTAUD2I13_IMR      273
#define RENESAS_ICTAUD2I14_IMR      274
#define RENESAS_ICTAUD2I15_IMR      275

/* Interrupt control registers for TAUJ */
#define RENESAS_ICTAUJ0I0_IMR      133
#define RENESAS_ICTAUJ0I1_IMR      134
#define RENESAS_ICTAUJ0I2_IMR      135
#define RENESAS_ICTAUJ0I3_IMR      136

#define RENESAS_ICTAUJ1I0_IMR      137
#define RENESAS_ICTAUJ1I1_IMR      138
#define RENESAS_ICTAUJ1I2_IMR      139
#define RENESAS_ICTAUJ1I3_IMR      140

#define RENESAS_ICTAUJ2I0_IMR      256
#define RENESAS_ICTAUJ2I1_IMR      257
#define RENESAS_ICTAUJ2I2_IMR      258
#define RENESAS_ICTAUJ2I3_IMR      259

/* Interrupt control registers for OSTM */
#define RENESAS_ICOSTM0IIC_IMR   74
#define RENESAS_ICOSTM1IIC_IMR   75

#define RENESAS_TAUD0CNT0       TAUD0CNT0
#define RENESAS_TAUD0CNT1       TAUD0CNT1
#define RENESAS_TAUD0CNT2       TAUD0CNT2
#define RENESAS_TAUD0CNT3       TAUD0CNT3
#define RENESAS_TAUD0CNT4       TAUD0CNT4
#define RENESAS_TAUD0CNT5       TAUD0CNT5
#define RENESAS_TAUD0CNT6       TAUD0CNT6
#define RENESAS_TAUD0CNT7       TAUD0CNT7
#define RENESAS_TAUD0CNT8       TAUD0CNT8
#define RENESAS_TAUD0CNT9       TAUD0CNT9
#define RENESAS_TAUD0CNT10      TAUD0CNT10
#define RENESAS_TAUD0CNT11      TAUD0CNT11
#define RENESAS_TAUD0CNT12      TAUD0CNT12
#define RENESAS_TAUD0CNT13      TAUD0CNT13
#define RENESAS_TAUD0CNT14      TAUD0CNT14
#define RENESAS_TAUD0CNT15      TAUD0CNT15

#define RENESAS_TAUD1CNT0       TAUD1CNT0
#define RENESAS_TAUD1CNT1       TAUD1CNT1
#define RENESAS_TAUD1CNT2       TAUD1CNT2
#define RENESAS_TAUD1CNT3       TAUD1CNT3
#define RENESAS_TAUD1CNT6       TAUD1CNT6
#define RENESAS_TAUD1CNT8       TAUD1CNT8
#define RENESAS_TAUD1CNT10      TAUD1CNT10

#define RENESAS_TAUD2CNT0       TAUD2CNT0
#define RENESAS_TAUD2CNT1       TAUD2CNT1
#define RENESAS_TAUD2CNT2       TAUD2CNT2
#define RENESAS_TAUD2CNT3       TAUD2CNT3
#define RENESAS_TAUD2CNT7       TAUD2CNT7
#define RENESAS_TAUD2CNT11      TAUD2CNT11
#define RENESAS_TAUD2CNT12      TAUD2CNT12
#define RENESAS_TAUD2CNT13      TAUD2CNT13
#define RENESAS_TAUD2CNT14      TAUD2CNT14
#define RENESAS_TAUD2CNT15      TAUD2CNT15

#define RENESAS_TAUJ0CNT0       TAUJ0CNT0
#define RENESAS_TAUJ0CNT1       TAUJ0CNT1
#define RENESAS_TAUJ0CNT2       TAUJ0CNT2
#define RENESAS_TAUJ0CNT3       TAUJ0CNT3

#define RENESAS_TAUJ1CNT0       TAUJ1CNT0
#define RENESAS_TAUJ1CNT1       TAUJ1CNT1
#define RENESAS_TAUJ1CNT2       TAUJ1CNT2
#define RENESAS_TAUJ1CNT3       TAUJ1CNT3

#define RENESAS_TAUJ2CNT0       TAUJ2CNT0
#define RENESAS_TAUJ2CNT1       TAUJ2CNT1
#define RENESAS_TAUJ2CNT2       TAUJ2CNT2
#define RENESAS_TAUJ2CNT3       TAUJ2CNT3

/* Output Enable Register for Timers */
#define RENESAS_OSTM0TOE       OSTM0TOE
#define RENESAS_OSTM1TOE       OSTM1TOE

#define RENESAS_TAUD0TOE0     TAUD0TOE00
#define RENESAS_TAUD0TOE1     TAUD0TOE01
#define RENESAS_TAUD0TOE2     TAUD0TOE02
#define RENESAS_TAUD0TOE3     TAUD0TOE03
#define RENESAS_TAUD0TOE4     TAUD0TOE04
#define RENESAS_TAUD0TOE5     TAUD0TOE05
#define RENESAS_TAUD0TOE6     TAUD0TOE06
#define RENESAS_TAUD0TOE7     TAUD0TOE07
#define RENESAS_TAUD0TOE8     TAUD0TOE08
#define RENESAS_TAUD0TOE9     TAUD0TOE09
#define RENESAS_TAUD0TOE10     TAUD0TOE10
#define RENESAS_TAUD0TOE11     TAUD0TOE11
#define RENESAS_TAUD0TOE12     TAUD0TOE12
#define RENESAS_TAUD0TOE13     TAUD0TOE13
#define RENESAS_TAUD0TOE14     TAUD0TOE14
#define RENESAS_TAUD0TOE15     TAUD0TOE15
#define RENESAS_TAUD1TOE0     TAUD1TOE00
#define RENESAS_TAUD1TOE1     TAUD1TOE01
#define RENESAS_TAUD1TOE2     TAUD1TOE02
#define RENESAS_TAUD1TOE3     TAUD1TOE03
#define RENESAS_TAUD1TOE4     TAUD1TOE04
#define RENESAS_TAUD1TOE5     TAUD1TOE05
#define RENESAS_TAUD1TOE6     TAUD1TOE06
#define RENESAS_TAUD1TOE7     TAUD1TOE07
#define RENESAS_TAUD1TOE8     TAUD1TOE08
#define RENESAS_TAUD1TOE9     TAUD1TOE09
#define RENESAS_TAUD1TOE10     TAUD1TOE10
#define RENESAS_TAUD1TOE11     TAUD1TOE11
#define RENESAS_TAUD1TOE12     TAUD1TOE12
#define RENESAS_TAUD1TOE13     TAUD1TOE13
#define RENESAS_TAUD1TOE14     TAUD1TOE14
#define RENESAS_TAUD1TOE15     TAUD1TOE15
#define RENESAS_TAUD2TOE0     TAUD2TOE00
#define RENESAS_TAUD2TOE1     TAUD2TOE01
#define RENESAS_TAUD2TOE2     TAUD2TOE02
#define RENESAS_TAUD2TOE3     TAUD2TOE03
#define RENESAS_TAUD2TOE4     TAUD2TOE04
#define RENESAS_TAUD2TOE5     TAUD2TOE05
#define RENESAS_TAUD2TOE6     TAUD2TOE06
#define RENESAS_TAUD2TOE7     TAUD2TOE07
#define RENESAS_TAUD2TOE8     TAUD2TOE08
#define RENESAS_TAUD2TOE9     TAUD2TOE09
#define RENESAS_TAUD2TOE10     TAUD2TOE10
#define RENESAS_TAUD2TOE11     TAUD2TOE11
#define RENESAS_TAUD2TOE12     TAUD2TOE12
#define RENESAS_TAUD2TOE13     TAUD2TOE13
#define RENESAS_TAUD2TOE14     TAUD2TOE14
#define RENESAS_TAUD2TOE15     TAUD2TOE15

#define RENESAS_TAUJ0TOE0     TAUJ0TOE00
#define RENESAS_TAUJ0TOE1     TAUJ0TOE01
#define RENESAS_TAUJ0TOE2     TAUJ0TOE02
#define RENESAS_TAUJ0TOE3     TAUJ0TOE03
#define RENESAS_TAUJ1TOE0     TAUJ1TOE00
#define RENESAS_TAUJ1TOE1     TAUJ1TOE01
#define RENESAS_TAUJ1TOE2     TAUJ1TOE02
#define RENESAS_TAUJ1TOE3     TAUJ1TOE03
#define RENESAS_TAUJ2TOE0     TAUJ2TOE00
#define RENESAS_TAUJ2TOE1     TAUJ2TOE01
#define RENESAS_TAUJ2TOE2     TAUJ2TOE02
#define RENESAS_TAUJ2TOE3     TAUJ2TOE03


/*******************************************************************************
**                 Macros for ICU Driver                                      **
*******************************************************************************/
#define RENESAS_TAUJ2TT0        TAUJ2TT0
#define RENESAS_TAUJ2TT1        TAUJ2TT1
#define RENESAS_TAUJ2TT2        TAUJ2TT2
#define RENESAS_TAUJ2TT3        TAUJ2TT3


/* Interrupt control registers for External Interrupts */
#define RENESAS_ICP0           INTC2EIC32
#define RENESAS_ICP1           INTC2EIC33
#define RENESAS_ICP2           INTC2EIC34
#define RENESAS_ICP3           INTC2EIC35
#define RENESAS_ICP4           INTC2EIC36
#define RENESAS_ICP5           INTC2EIC128
#define RENESAS_ICP6           INTC2EIC129
#define RENESAS_ICP7           INTC2EIC130
#define RENESAS_ICP8           INTC2EIC131
#define RENESAS_ICP9           INTC2EIC132
#define RENESAS_ICP10          INTC2EIC296
#define RENESAS_ICP11          INTC2EIC297
#define RENESAS_ICP12          INTC2EIC298

#define RENESAS_ICP0_IMR      32
#define RENESAS_ICP1_IMR      33
#define RENESAS_ICP2_IMR      34
#define RENESAS_ICP3_IMR      35
#define RENESAS_ICP4_IMR      36
#define RENESAS_ICP5_IMR      128
#define RENESAS_ICP6_IMR      129
#define RENESAS_ICP7_IMR      130
#define RENESAS_ICP8_IMR      131
#define RENESAS_ICP9_IMR      132
#define RENESAS_ICP10_IMR     296
#define RENESAS_ICP11_IMR     297
#define RENESAS_ICP12_IMR     298

/* External Interrupt edge detection registers */
#define RENESAS_FCLA_INTP0      FCLA1CTL0
#define RENESAS_FCLA_INTP1      FCLA1CTL1
#define RENESAS_FCLA_INTP2      FCLA1CTL2
#define RENESAS_FCLA_INTP3      FCLA1CTL3
#define RENESAS_FCLA_INTP4      FCLA1CTL4
#define RENESAS_FCLA_INTP5      FCLA1CTL5
#define RENESAS_FCLA_INTP6      FCLA1CTL6
#define RENESAS_FCLA_INTP7      FCLA1CTL7
#define RENESAS_FCLA_INTP8      FCLA2CTL0
#define RENESAS_FCLA_INTP9      FCLA2CTL1
#define RENESAS_FCLA_INTP10     FCLA2CTL2
#define RENESAS_FCLA_INTP11     FCLA2CTL3
#define RENESAS_FCLA_INTP12     FCLA2CTL4

/* Previous Input control registers */
#define RENESAS_SELB_TAUD0I     SELB_TAUD0I

/*******************************************************************************
**                 Macros for IMR Register                                    **
*******************************************************************************/
#define RENESAS_IMR0       INTC1IMR0
#define RENESAS_IMR1       INTC2IMR1
#define RENESAS_IMR2       INTC2IMR2
#define RENESAS_IMR3       INTC2IMR3
#define RENESAS_IMR4       INTC2IMR4
#define RENESAS_IMR5       INTC2IMR5
#define RENESAS_IMR6       INTC2IMR6
#define RENESAS_IMR7       INTC2IMR7
#define RENESAS_IMR8       INTC2IMR8
#define RENESAS_IMR9       INTC2IMR9
#define RENESAS_IMR10      INTC2IMR10
#define RENESAS_IMR11      INTC2IMR11

/*******************************************************************************
**                 Macros for SPI Driver                                     **
*******************************************************************************/

/* Base address of the CSIG0  hardware registers structure */
#define RENESAS_CSIG0CTL0        CSIG0CTL0
#define RENESAS_CSIG0BCTL0       CSIG0BCTL0
#define RENESAS_CSIG0CTL1        CSIG0CTL1
#define RENESAS_CSIG0CTL2        CSIG0CTL2
#define RENESAS_CSIG0CFG0        CSIG0CFG0
#define RENESAS_CSIG0TX0W        CSIG0TX0W
#define RENESAS_CSIG0TX0H        CSIG0TX0H
#define RENESAS_CSIG0RX0         CSIG0RX0

/* Base address of the CSIH0 hardware registers structure */
#define RENESAS_CSIH0CTL0        CSIH0CTL0
#define RENESAS_CSIH0CTL1        CSIH0CTL1
#define RENESAS_CSIH0CTL2        CSIH0CTL2
#define RENESAS_CHBA0MCTL1       CSIH0MCTL1
#define RENESAS_CHBA0MCTL2       CSIH0MCTL2
#define RENESAS_CSIH0TX0W        CSIH0TX0W
#define RENESAS_CSIH0TX0H        CSIH0TX0H
#define RENESAS_CSIH0RX0         CSIH0RX0H
#define RENESAS_CHBA0MRWP0       CSIH0MRWP0
#define RENESAS_CHBA0MCTL0       CSIH0MCTL0
#define RENESAS_CHBA0CFG0        CSIH0CFG0
#define RENESAS_CHBA0CFG1        CSIH0CFG1
#define RENESAS_CHBA0CFG2        CSIH0CFG2
#define RENESAS_CHBA0CFG3        CSIH0CFG3
#define RENESAS_CHBA0CFG4        CSIH0CFG4
#define RENESAS_CHBA0CFG5        CSIH0CFG5
#define RENESAS_CHBA0CFG6        CSIH0CFG6
#define RENESAS_CHBA0CFG7        CSIH0CFG7
#define RENESAS_ECCCSIH0CTL      ECCCSIH0CTL


/* Base address of the CSIH1 hardware registers structure */
#define RENESAS_CSIH1CTL0        CSIH1CTL0
#define RENESAS_CSIH1CTL1        CSIH1CTL1
#define RENESAS_CSIH1CTL2        CSIH1CTL2
#define RENESAS_CHBA1MCTL1       CSIH1MCTL1
#define RENESAS_CHBA1MCTL2       CSIH1MCTL2
#define RENESAS_CSIH1TX0W        CSIH1TX0W
#define RENESAS_CSIH1TX0H        CSIH1TX0H
#define RENESAS_CSIH1RX0         CSIH1RX0H
#define RENESAS_CHBA1MRWP0       CSIH1MRWP0
#define RENESAS_CHBA1MCTL0       CSIH1MCTL0
#define RENESAS_CHBA1CFG0        CSIH1CFG0
#define RENESAS_CHBA1CFG1        CSIH1CFG1
#define RENESAS_CHBA1CFG2        CSIH1CFG2
#define RENESAS_CHBA1CFG3        CSIH1CFG3
#define RENESAS_CHBA1CFG4        CSIH1CFG4
#define RENESAS_CHBA1CFG5        CSIH1CFG5
#define RENESAS_CHBA1CFG6        CSIH1CFG6
#define RENESAS_CHBA1CFG7        CSIH1CFG7
#define RENESAS_ECCCSIH1CTL      ECCCSIH1CTL

/* Base address of the CSIH2 hardware registers structure */
#define RENESAS_CSIH2CTL0        CSIH2CTL0
#define RENESAS_CSIH2CTL1        CSIH2CTL1
#define RENESAS_CSIH2CTL2        CSIH2CTL2
#define RENESAS_CHBA2MCTL0       CSIH2MCTL0
#define RENESAS_CHBA2MCTL1       CSIH2MCTL1
#define RENESAS_CSIH2TX0W        CSIH2TX0W
#define RENESAS_CSIH2TX0H        CSIH2TX0H
#define RENESAS_CSIH2RX0         CSIH2RX0H
#define RENESAS_CHBA2MRWP0       CSIH2MRWP0
#define RENESAS_CHBA2CFG0        CSIH2CFG0
#define RENESAS_CHBA2CFG1        CSIH2CFG1
#define RENESAS_CHBA2CFG2        CSIH2CFG2
#define RENESAS_CHBA2CFG3        CSIH2CFG3
#define RENESAS_CHBA2CFG4        CSIH2CFG4
#define RENESAS_CHBA2CFG5        CSIH2CFG5
#define RENESAS_CHBA2CFG6        CSIH2CFG6
#define RENESAS_CHBA2CFG7        CSIH2CFG7
#define RENESAS_ECCCSIH2CTL      ECCCSIH2CTL

/* Base address of the CSIH3 hardware registers structure */
#define RENESAS_CSIH3CTL0        CSIH3CTL0
#define RENESAS_CSIH3CTL1        CSIH3CTL1
#define RENESAS_CSIH3CTL2        CSIH3CTL2
#define RENESAS_CHBA3MCTL0       CSIH3MCTL0
#define RENESAS_CHBA3MCTL1       CSIH3MCTL1
#define RENESAS_CSIH3TX0W        CSIH3TX0W
#define RENESAS_CSIH3TX0H        CSIH3TX0H
#define RENESAS_CSIH3RX0         CSIH3RX0H
#define RENESAS_CHBA3MRWP0       CSIH3MRWP0
#define RENESAS_CHBA3CFG0        CSIH3CFG0
#define RENESAS_CHBA3CFG1        CSIH3CFG1
#define RENESAS_CHBA3CFG2        CSIH3CFG2
#define RENESAS_CHBA3CFG3        CSIH3CFG3
#define RENESAS_CHBA3CFG4        CSIH3CFG4
#define RENESAS_CHBA3CFG5        CSIH3CFG5
#define RENESAS_CHBA3CFG6        CSIH3CFG6
#define RENESAS_CHBA3CFG7        CSIH3CFG7
#define RENESAS_ECCCSIH3CTL      ECCCSIH3CTL

/*CSIH0/CSIH1 DMA trigger controls register on CSL0 active*/

#define RENESAS_SELCSIHDMA       CSIHSELCSIHDMA

/* Interrupt control registers for CSIG0 */
#define RENESAS_ICCSIG0IRE          INTC2EIC174
#define RENESAS_ICCSIG0IR           INTC2EIC176
#define RENESAS_ICCSIG0IC           INTC2EIC175

/* Interrupt control registers for CSIH0 */
#define RENESAS_CSIH0TIRE           INTC2EIC82
#define RENESAS_CSIH0TIR            INTC2EIC83
#define RENESAS_CSIH0TIC            INTC2EIC84
#define RENESAS_CSIH0TIJC           INTC2EIC89

/* Interrupt control registers for CSIH1 */
#define RENESAS_CSIH1TIRE           INTC2EIC90
#define RENESAS_CSIH1TIR            INTC2EIC91
#define RENESAS_CSIH1TIC            INTC2EIC92
#define RENESAS_CSIH1TIJC           INTC2EIC97

/* Interrupt control registers for CSIH2 */
#define RENESAS_CSIH2TIRE           INTC2EIC98
#define RENESAS_CSIH2TIR            INTC2EIC99
#define RENESAS_CSIH2TIC            INTC2EIC100
#define RENESAS_CSIH2TIJC           INTC2EIC101

/* Interrupt control registers for CSIH3 */
#define RENESAS_CSIH3TIRE           INTC2EIC102
#define RENESAS_CSIH3TIR            INTC2EIC103
#define RENESAS_CSIH3TIC            INTC2EIC104
#define RENESAS_CSIH3TIJC           INTC2EIC105

/* Interrupt control registers for CSIH0 */
#define RENESAS_CSIH0TIRE_IMR       82
#define RENESAS_CSIH0TIR_IMR        83
#define RENESAS_CSIH0TIC_IMR        84
#define RENESAS_CSIH0TIJC_IMR       89

/* Interrupt control registers for CSIH1 */
#define RENESAS_CSIH1TIRE_IMR       90
#define RENESAS_CSIH1TIR_IMR        91
#define RENESAS_CSIH1TIC_IMR        92
#define RENESAS_CSIH1TIJC_IMR       97

/* Interrupt control registers for CSIH2 */
#define RENESAS_CSIH2TIRE_IMR       98
#define RENESAS_CSIH2TIR_IMR        99
#define RENESAS_CSIH2TIC_IMR        100
#define RENESAS_CSIH2TIJC_IMR       101

/* Interrupt control registers for CSIH3 */
#define RENESAS_CSIH3TIRE_IMR       102
#define RENESAS_CSIH3TIR_IMR        103
#define RENESAS_CSIH3TIC_IMR        104
#define RENESAS_CSIH3TIJC_IMR       105

/* Interrupt control registers for CSIG0 */
#define RENESAS_ICCSIG0IRE_IMR      174
#define RENESAS_ICCSIG0IC_IMR       176
#define RENESAS_ICCSIG0IR_IMR       175

/* MCU reference*/

#define RENESAS_MCUREF              McuPeripheralClock

/*****************************************************************************
**                         Macros for CAN Driver                            **
******************************************************************************/
/*GLOBAL REGISTER MACROS*/
#define RENESAS_RCAN0GCFG           RSCAN0GCFG
#define RENESAS_RCAN0GCTR           RSCAN0GCTR
#define RENESAS_RCAN0GSTS           RSCAN0GSTS
#define RENESAS_RCAN0RMNB           RSCAN0RMNB
#define RENESAS_RCAN0GAFLECTR       RSCAN0GAFLECTR
#define RENESAS_RCAN0GAFLCFG0       RSCAN0GAFLCFG0
#define RENESAS_RCAN0GAFLCFG1       RSCAN0GAFLCFG1
#define RENESAS_RCAN0TMIEC0         RSCAN0TMIEC0
#define RENESAS_RCAN0RMND0          RSCAN0RMND0

/*CHANNEL CONFIGURATION REGISTER MACROS*/
#define RENESAS_RCAN0C0CFG      RSCAN0C0CFG
#define RENESAS_RCAN0C1CFG      RSCAN0C1CFG
#define RENESAS_RCAN0C2CFG      RSCAN0C2CFG
#define RENESAS_RCAN0C3CFG      RSCAN0C3CFG
#define RENESAS_RCAN0C4CFG      RSCAN0C4CFG
#define RENESAS_RCAN0C5CFG      RSCAN0C5CFG

/*CHANNEL CONTROL REGISTER MACROS*/
#define RENESAS_RCAN0C0CTR      RSCAN0C0CTR
#define RENESAS_RCAN0C1CTR      RSCAN0C1CTR
#define RENESAS_RCAN0C2CTR      RSCAN0C2CTR
#define RENESAS_RCAN0C3CTR      RSCAN0C3CTR
#define RENESAS_RCAN0C4CTR      RSCAN0C4CTR
#define RENESAS_RCAN0C5CTR      RSCAN0C5CTR

/*CHANNEL STATUS REGISTER MACROS*/
#define RENESAS_RCAN0C0STS      RSCAN0C0STS
#define RENESAS_RCAN0C1STS      RSCAN0C1STS
#define RENESAS_RCAN0C2STS      RSCAN0C2STS
#define RENESAS_RCAN0C3STS      RSCAN0C3STS
#define RENESAS_RCAN0C4STS      RSCAN0C4STS
#define RENESAS_RCAN0C5STS      RSCAN0C5STS

/*THL REGISTER MACROS*/
#define RENESAS_RCAN0THLCC0      RSCAN0THLCC0
#define RENESAS_RCAN0THLCC1      RSCAN0THLCC1
#define RENESAS_RCAN0THLCC2      RSCAN0THLCC2
#define RENESAS_RCAN0THLCC3      RSCAN0THLCC3
#define RENESAS_RCAN0THLCC4      RSCAN0THLCC4
#define RENESAS_RCAN0THLCC5      RSCAN0THLCC5

#define RENESAS_RCAN0THLACC0      RSCAN0THLACC0
#define RENESAS_RCAN0THLACC1      RSCAN0THLACC1
#define RENESAS_RCAN0THLACC2      RSCAN0THLACC2
#define RENESAS_RCAN0THLACC3      RSCAN0THLACC3
#define RENESAS_RCAN0THLACC4      RSCAN0THLACC4
#define RENESAS_RCAN0THLACC5      RSCAN0THLACC5

#define RENESAS_RCAN0THLSTS0    RSCAN0THLSTS0
#define RENESAS_RCAN0THLSTS1    RSCAN0THLSTS1
#define RENESAS_RCAN0THLSTS2    RSCAN0THLSTS2
#define RENESAS_RCAN0THLSTS3    RSCAN0THLSTS3
#define RENESAS_RCAN0THLSTS4    RSCAN0THLSTS4
#define RENESAS_RCAN0THLSTS5    RSCAN0THLSTS5

#define RENESAS_RCAN0THLPCTR0   RSCAN0THLPCTR0
#define RENESAS_RCAN0THLPCTR1   RSCAN0THLPCTR1
#define RENESAS_RCAN0THLPCTR2   RSCAN0THLPCTR2
#define RENESAS_RCAN0THLPCTR3   RSCAN0THLPCTR3
#define RENESAS_RCAN0THLPCTR4   RSCAN0THLPCTR4
#define RENESAS_RCAN0THLPCTR5   RSCAN0THLPCTR5

/*******************************************************************************
**                 Macros for CAN MCUCLOCK Software Implementation            **
*******************************************************************************/
#define RENESAS_CANMCUPPLCLOCK    McuPeripheralClock
#define RENESAS_CANMCUPCLKCLOCK   McuPeripheralClock
#define RENESAS_CANMCUMAINCLOCK   McuMainOsciFrequency
#define RENESAS_PFCLAWAKEUPINTMASK SUPPORTED
/*RX BUFFERS MACROS*/
#define RENESAS_RCAN0RMID0      RSCAN0RMID0
#define RENESAS_RCAN0RMID1      RSCAN0RMID1
#define RENESAS_RCAN0RMID2      RSCAN0RMID2
#define RENESAS_RCAN0RMID3      RSCAN0RMID3
#define RENESAS_RCAN0RMID4      RSCAN0RMID4
#define RENESAS_RCAN0RMID5      RSCAN0RMID5
#define RENESAS_RCAN0RMID6      RSCAN0RMID6
#define RENESAS_RCAN0RMID7      RSCAN0RMID7
#define RENESAS_RCAN0RMID8      RSCAN0RMID8
#define RENESAS_RCAN0RMID9      RSCAN0RMID9
#define RENESAS_RCAN0RMID10     RSCAN0RMID10
#define RENESAS_RCAN0RMID11     RSCAN0RMID11
#define RENESAS_RCAN0RMID12     RSCAN0RMID12
#define RENESAS_RCAN0RMID13     RSCAN0RMID13
#define RENESAS_RCAN0RMID14     RSCAN0RMID14
#define RENESAS_RCAN0RMID15     RSCAN0RMID15
#define RENESAS_RCAN0RMID16     RSCAN0RMID16
#define RENESAS_RCAN0RMID17     RSCAN0RMID17
#define RENESAS_RCAN0RMID18     RSCAN0RMID18
#define RENESAS_RCAN0RMID19     RSCAN0RMID19
#define RENESAS_RCAN0RMID20     RSCAN0RMID20
#define RENESAS_RCAN0RMID21     RSCAN0RMID21
#define RENESAS_RCAN0RMID22     RSCAN0RMID22
#define RENESAS_RCAN0RMID23     RSCAN0RMID23
#define RENESAS_RCAN0RMID24     RSCAN0RMID24
#define RENESAS_RCAN0RMID25     RSCAN0RMID25
#define RENESAS_RCAN0RMID26     RSCAN0RMID26
#define RENESAS_RCAN0RMID27     RSCAN0RMID27
#define RENESAS_RCAN0RMID28     RSCAN0RMID28
#define RENESAS_RCAN0RMID29     RSCAN0RMID29
#define RENESAS_RCAN0RMID30     RSCAN0RMID30
#define RENESAS_RCAN0RMID31     RSCAN0RMID31
#define RENESAS_RCAN0RMID32     RSCAN0RMID32
#define RENESAS_RCAN0RMID33     RSCAN0RMID33
#define RENESAS_RCAN0RMID34     RSCAN0RMID34
#define RENESAS_RCAN0RMID35     RSCAN0RMID35
#define RENESAS_RCAN0RMID36     RSCAN0RMID36
#define RENESAS_RCAN0RMID37     RSCAN0RMID37
#define RENESAS_RCAN0RMID38     RSCAN0RMID38
#define RENESAS_RCAN0RMID39     RSCAN0RMID39
#define RENESAS_RCAN0RMID40     RSCAN0RMID40
#define RENESAS_RCAN0RMID41     RSCAN0RMID41
#define RENESAS_RCAN0RMID42     RSCAN0RMID42
#define RENESAS_RCAN0RMID43     RSCAN0RMID43
#define RENESAS_RCAN0RMID44     RSCAN0RMID44
#define RENESAS_RCAN0RMID45     RSCAN0RMID45
#define RENESAS_RCAN0RMID46     RSCAN0RMID46
#define RENESAS_RCAN0RMID47     RSCAN0RMID47
#define RENESAS_RCAN0RMID48     RSCAN0RMID48
#define RENESAS_RCAN0RMID49     RSCAN0RMID49
#define RENESAS_RCAN0RMID50     RSCAN0RMID50
#define RENESAS_RCAN0RMID51     RSCAN0RMID51
#define RENESAS_RCAN0RMID52     RSCAN0RMID52
#define RENESAS_RCAN0RMID53     RSCAN0RMID53
#define RENESAS_RCAN0RMID54     RSCAN0RMID54
#define RENESAS_RCAN0RMID55     RSCAN0RMID55
#define RENESAS_RCAN0RMID56     RSCAN0RMID56
#define RENESAS_RCAN0RMID57     RSCAN0RMID57
#define RENESAS_RCAN0RMID58     RSCAN0RMID58
#define RENESAS_RCAN0RMID59     RSCAN0RMID59
#define RENESAS_RCAN0RMID60     RSCAN0RMID60
#define RENESAS_RCAN0RMID61     RSCAN0RMID61
#define RENESAS_RCAN0RMID62     RSCAN0RMID62
#define RENESAS_RCAN0RMID63     RSCAN0RMID63
#define RENESAS_RCAN0RMID64     RSCAN0RMID64
#define RENESAS_RCAN0RMID65     RSCAN0RMID65
#define RENESAS_RCAN0RMID66     RSCAN0RMID66
#define RENESAS_RCAN0RMID67     RSCAN0RMID67
#define RENESAS_RCAN0RMID68     RSCAN0RMID68
#define RENESAS_RCAN0RMID69     RSCAN0RMID69
#define RENESAS_RCAN0RMID70     RSCAN0RMID70
#define RENESAS_RCAN0RMID71     RSCAN0RMID71
#define RENESAS_RCAN0RMID72     RSCAN0RMID72
#define RENESAS_RCAN0RMID73     RSCAN0RMID73
#define RENESAS_RCAN0RMID74     RSCAN0RMID74
#define RENESAS_RCAN0RMID75     RSCAN0RMID75
#define RENESAS_RCAN0RMID76     RSCAN0RMID76
#define RENESAS_RCAN0RMID77     RSCAN0RMID77
#define RENESAS_RCAN0RMID78     RSCAN0RMID78
#define RENESAS_RCAN0RMID79     RSCAN0RMID79
#define RENESAS_RCAN0RMID80     RSCAN0RMID80
#define RENESAS_RCAN0RMID81     RSCAN0RMID81
#define RENESAS_RCAN0RMID82     RSCAN0RMID82
#define RENESAS_RCAN0RMID83     RSCAN0RMID83
#define RENESAS_RCAN0RMID84     RSCAN0RMID84
#define RENESAS_RCAN0RMID85     RSCAN0RMID85
#define RENESAS_RCAN0RMID86     RSCAN0RMID86
#define RENESAS_RCAN0RMID87     RSCAN0RMID87
#define RENESAS_RCAN0RMID88     RSCAN0RMID88
#define RENESAS_RCAN0RMID89     RSCAN0RMID89
#define RENESAS_RCAN0RMID90     RSCAN0RMID90
#define RENESAS_RCAN0RMID91     RSCAN0RMID91
#define RENESAS_RCAN0RMID92     RSCAN0RMID92
#define RENESAS_RCAN0RMID93     RSCAN0RMID93
#define RENESAS_RCAN0RMID94     RSCAN0RMID94
#define RENESAS_RCAN0RMID95     RSCAN0RMID95

#define RENESAS_RCAN0RMPTR0      RSCAN0RMPTR0
#define RENESAS_RCAN0RMPTR1      RSCAN0RMPTR1
#define RENESAS_RCAN0RMPTR2      RSCAN0RMPTR2
#define RENESAS_RCAN0RMPTR3      RSCAN0RMPTR3
#define RENESAS_RCAN0RMPTR4      RSCAN0RMPTR4
#define RENESAS_RCAN0RMPTR5      RSCAN0RMPTR5
#define RENESAS_RCAN0RMPTR6      RSCAN0RMPTR6
#define RENESAS_RCAN0RMPTR7      RSCAN0RMPTR7
#define RENESAS_RCAN0RMPTR8      RSCAN0RMPTR8
#define RENESAS_RCAN0RMPTR9      RSCAN0RMPTR9
#define RENESAS_RCAN0RMPTR10     RSCAN0RMPTR10
#define RENESAS_RCAN0RMPTR11     RSCAN0RMPTR11
#define RENESAS_RCAN0RMPTR12     RSCAN0RMPTR12
#define RENESAS_RCAN0RMPTR13     RSCAN0RMPTR13
#define RENESAS_RCAN0RMPTR14     RSCAN0RMPTR14
#define RENESAS_RCAN0RMPTR15     RSCAN0RMPTR15
#define RENESAS_RCAN0RMPTR16     RSCAN0RMPTR16
#define RENESAS_RCAN0RMPTR17     RSCAN0RMPTR17
#define RENESAS_RCAN0RMPTR18     RSCAN0RMPTR18
#define RENESAS_RCAN0RMPTR19     RSCAN0RMPTR19
#define RENESAS_RCAN0RMPTR20     RSCAN0RMPTR20
#define RENESAS_RCAN0RMPTR21     RSCAN0RMPTR21
#define RENESAS_RCAN0RMPTR22     RSCAN0RMPTR22
#define RENESAS_RCAN0RMPTR23     RSCAN0RMPTR23
#define RENESAS_RCAN0RMPTR24     RSCAN0RMPTR24
#define RENESAS_RCAN0RMPTR25     RSCAN0RMPTR25
#define RENESAS_RCAN0RMPTR26     RSCAN0RMPTR26
#define RENESAS_RCAN0RMPTR27     RSCAN0RMPTR27
#define RENESAS_RCAN0RMPTR28     RSCAN0RMPTR28
#define RENESAS_RCAN0RMPTR29     RSCAN0RMPTR29
#define RENESAS_RCAN0RMPTR30     RSCAN0RMPTR30
#define RENESAS_RCAN0RMPTR31     RSCAN0RMPTR31
#define RENESAS_RCAN0RMPTR32     RSCAN0RMPTR32
#define RENESAS_RCAN0RMPTR33     RSCAN0RMPTR33
#define RENESAS_RCAN0RMPTR34     RSCAN0RMPTR34
#define RENESAS_RCAN0RMPTR35     RSCAN0RMPTR35
#define RENESAS_RCAN0RMPTR36     RSCAN0RMPTR36
#define RENESAS_RCAN0RMPTR37     RSCAN0RMPTR37
#define RENESAS_RCAN0RMPTR38     RSCAN0RMPTR38
#define RENESAS_RCAN0RMPTR39     RSCAN0RMPTR39
#define RENESAS_RCAN0RMPTR40     RSCAN0RMPTR40
#define RENESAS_RCAN0RMPTR41     RSCAN0RMPTR41
#define RENESAS_RCAN0RMPTR42     RSCAN0RMPTR42
#define RENESAS_RCAN0RMPTR43     RSCAN0RMPTR43
#define RENESAS_RCAN0RMPTR44     RSCAN0RMPTR44
#define RENESAS_RCAN0RMPTR45     RSCAN0RMPTR45
#define RENESAS_RCAN0RMPTR46     RSCAN0RMPTR46
#define RENESAS_RCAN0RMPTR47     RSCAN0RMPTR47
#define RENESAS_RCAN0RMPTR48     RSCAN0RMPTR48
#define RENESAS_RCAN0RMPTR49     RSCAN0RMPTR49
#define RENESAS_RCAN0RMPTR50     RSCAN0RMPTR50
#define RENESAS_RCAN0RMPTR51     RSCAN0RMPTR51
#define RENESAS_RCAN0RMPTR52     RSCAN0RMPTR52
#define RENESAS_RCAN0RMPTR53     RSCAN0RMPTR53
#define RENESAS_RCAN0RMPTR54     RSCAN0RMPTR54
#define RENESAS_RCAN0RMPTR55     RSCAN0RMPTR55
#define RENESAS_RCAN0RMPTR56     RSCAN0RMPTR56
#define RENESAS_RCAN0RMPTR57     RSCAN0RMPTR57
#define RENESAS_RCAN0RMPTR58     RSCAN0RMPTR58
#define RENESAS_RCAN0RMPTR59     RSCAN0RMPTR59
#define RENESAS_RCAN0RMPTR60     RSCAN0RMPTR60
#define RENESAS_RCAN0RMPTR61     RSCAN0RMPTR61
#define RENESAS_RCAN0RMPTR62     RSCAN0RMPTR62
#define RENESAS_RCAN0RMPTR63     RSCAN0RMPTR63
#define RENESAS_RCAN0RMPTR64     RSCAN0RMPTR64
#define RENESAS_RCAN0RMPTR65     RSCAN0RMPTR65
#define RENESAS_RCAN0RMPTR66     RSCAN0RMPTR66
#define RENESAS_RCAN0RMPTR67     RSCAN0RMPTR67
#define RENESAS_RCAN0RMPTR68     RSCAN0RMPTR68
#define RENESAS_RCAN0RMPTR69     RSCAN0RMPTR69
#define RENESAS_RCAN0RMPTR70     RSCAN0RMPTR70
#define RENESAS_RCAN0RMPTR71     RSCAN0RMPTR71
#define RENESAS_RCAN0RMPTR72     RSCAN0RMPTR72
#define RENESAS_RCAN0RMPTR73     RSCAN0RMPTR73
#define RENESAS_RCAN0RMPTR74     RSCAN0RMPTR74
#define RENESAS_RCAN0RMPTR75     RSCAN0RMPTR75
#define RENESAS_RCAN0RMPTR76     RSCAN0RMPTR76
#define RENESAS_RCAN0RMPTR77     RSCAN0RMPTR77
#define RENESAS_RCAN0RMPTR78     RSCAN0RMPTR78
#define RENESAS_RCAN0RMPTR79     RSCAN0RMPTR79
#define RENESAS_RCAN0RMPTR80     RSCAN0RMPTR80
#define RENESAS_RCAN0RMPTR81     RSCAN0RMPTR81
#define RENESAS_RCAN0RMPTR82     RSCAN0RMPTR82
#define RENESAS_RCAN0RMPTR83     RSCAN0RMPTR83
#define RENESAS_RCAN0RMPTR84     RSCAN0RMPTR84
#define RENESAS_RCAN0RMPTR85     RSCAN0RMPTR85
#define RENESAS_RCAN0RMPTR86     RSCAN0RMPTR86
#define RENESAS_RCAN0RMPTR87     RSCAN0RMPTR87
#define RENESAS_RCAN0RMPTR88     RSCAN0RMPTR88
#define RENESAS_RCAN0RMPTR89     RSCAN0RMPTR89
#define RENESAS_RCAN0RMPTR90     RSCAN0RMPTR90
#define RENESAS_RCAN0RMPTR91     RSCAN0RMPTR91
#define RENESAS_RCAN0RMPTR92     RSCAN0RMPTR92
#define RENESAS_RCAN0RMPTR93     RSCAN0RMPTR93
#define RENESAS_RCAN0RMPTR94     RSCAN0RMPTR94
#define RENESAS_RCAN0RMPTR95     RSCAN0RMPTR95

#define RENESAS_RCAN0RMDF00      RSCAN0RMDF00
#define RENESAS_RCAN0RMDF01      RSCAN0RMDF01
#define RENESAS_RCAN0RMDF02      RSCAN0RMDF02
#define RENESAS_RCAN0RMDF03      RSCAN0RMDF03
#define RENESAS_RCAN0RMDF04      RSCAN0RMDF04
#define RENESAS_RCAN0RMDF05      RSCAN0RMDF05
#define RENESAS_RCAN0RMDF06      RSCAN0RMDF06
#define RENESAS_RCAN0RMDF07      RSCAN0RMDF07
#define RENESAS_RCAN0RMDF08      RSCAN0RMDF08
#define RENESAS_RCAN0RMDF09      RSCAN0RMDF09
#define RENESAS_RCAN0RMDF010     RSCAN0RMDF010
#define RENESAS_RCAN0RMDF011     RSCAN0RMDF011
#define RENESAS_RCAN0RMDF012     RSCAN0RMDF012
#define RENESAS_RCAN0RMDF013     RSCAN0RMDF013
#define RENESAS_RCAN0RMDF014     RSCAN0RMDF014
#define RENESAS_RCAN0RMDF015     RSCAN0RMDF015
#define RENESAS_RCAN0RMDF016     RSCAN0RMDF016
#define RENESAS_RCAN0RMDF017     RSCAN0RMDF017
#define RENESAS_RCAN0RMDF018     RSCAN0RMDF018
#define RENESAS_RCAN0RMDF019     RSCAN0RMDF019
#define RENESAS_RCAN0RMDF020     RSCAN0RMDF020
#define RENESAS_RCAN0RMDF021     RSCAN0RMDF021
#define RENESAS_RCAN0RMDF022     RSCAN0RMDF022
#define RENESAS_RCAN0RMDF023     RSCAN0RMDF023
#define RENESAS_RCAN0RMDF024     RSCAN0RMDF024
#define RENESAS_RCAN0RMDF025     RSCAN0RMDF025
#define RENESAS_RCAN0RMDF026     RSCAN0RMDF026
#define RENESAS_RCAN0RMDF027     RSCAN0RMDF027
#define RENESAS_RCAN0RMDF028     RSCAN0RMDF028
#define RENESAS_RCAN0RMDF029     RSCAN0RMDF029
#define RENESAS_RCAN0RMDF030     RSCAN0RMDF030
#define RENESAS_RCAN0RMDF031     RSCAN0RMDF031
#define RENESAS_RCAN0RMDF032     RSCAN0RMDF032
#define RENESAS_RCAN0RMDF033     RSCAN0RMDF033
#define RENESAS_RCAN0RMDF034     RSCAN0RMDF034
#define RENESAS_RCAN0RMDF035     RSCAN0RMDF035
#define RENESAS_RCAN0RMDF036     RSCAN0RMDF036
#define RENESAS_RCAN0RMDF037     RSCAN0RMDF037
#define RENESAS_RCAN0RMDF038     RSCAN0RMDF038
#define RENESAS_RCAN0RMDF039     RSCAN0RMDF039
#define RENESAS_RCAN0RMDF040     RSCAN0RMDF040
#define RENESAS_RCAN0RMDF041     RSCAN0RMDF041
#define RENESAS_RCAN0RMDF042     RSCAN0RMDF042
#define RENESAS_RCAN0RMDF043     RSCAN0RMDF043
#define RENESAS_RCAN0RMDF044     RSCAN0RMDF044
#define RENESAS_RCAN0RMDF045     RSCAN0RMDF045
#define RENESAS_RCAN0RMDF046     RSCAN0RMDF046
#define RENESAS_RCAN0RMDF047     RSCAN0RMDF047
#define RENESAS_RCAN0RMDF048     RSCAN0RMDF048
#define RENESAS_RCAN0RMDF049     RSCAN0RMDF049
#define RENESAS_RCAN0RMDF050     RSCAN0RMDF050
#define RENESAS_RCAN0RMDF051     RSCAN0RMDF051
#define RENESAS_RCAN0RMDF052     RSCAN0RMDF052
#define RENESAS_RCAN0RMDF053     RSCAN0RMDF053
#define RENESAS_RCAN0RMDF054     RSCAN0RMDF054
#define RENESAS_RCAN0RMDF055     RSCAN0RMDF055
#define RENESAS_RCAN0RMDF056     RSCAN0RMDF056
#define RENESAS_RCAN0RMDF057     RSCAN0RMDF057
#define RENESAS_RCAN0RMDF058     RSCAN0RMDF058
#define RENESAS_RCAN0RMDF059     RSCAN0RMDF059
#define RENESAS_RCAN0RMDF060     RSCAN0RMDF060
#define RENESAS_RCAN0RMDF061     RSCAN0RMDF061
#define RENESAS_RCAN0RMDF062     RSCAN0RMDF062
#define RENESAS_RCAN0RMDF063     RSCAN0RMDF063
#define RENESAS_RCAN0RMDF064     RSCAN0RMDF064
#define RENESAS_RCAN0RMDF065     RSCAN0RMDF065
#define RENESAS_RCAN0RMDF066     RSCAN0RMDF066
#define RENESAS_RCAN0RMDF067     RSCAN0RMDF067
#define RENESAS_RCAN0RMDF068     RSCAN0RMDF068
#define RENESAS_RCAN0RMDF069     RSCAN0RMDF069
#define RENESAS_RCAN0RMDF070     RSCAN0RMDF070
#define RENESAS_RCAN0RMDF071     RSCAN0RMDF071
#define RENESAS_RCAN0RMDF072     RSCAN0RMDF072
#define RENESAS_RCAN0RMDF073     RSCAN0RMDF073
#define RENESAS_RCAN0RMDF074     RSCAN0RMDF074
#define RENESAS_RCAN0RMDF075     RSCAN0RMDF075
#define RENESAS_RCAN0RMDF076     RSCAN0RMDF076
#define RENESAS_RCAN0RMDF077     RSCAN0RMDF077
#define RENESAS_RCAN0RMDF078     RSCAN0RMDF078
#define RENESAS_RCAN0RMDF079     RSCAN0RMDF079
#define RENESAS_RCAN0RMDF080     RSCAN0RMDF080
#define RENESAS_RCAN0RMDF081     RSCAN0RMDF081
#define RENESAS_RCAN0RMDF082     RSCAN0RMDF082
#define RENESAS_RCAN0RMDF083     RSCAN0RMDF083
#define RENESAS_RCAN0RMDF084     RSCAN0RMDF084
#define RENESAS_RCAN0RMDF085     RSCAN0RMDF085
#define RENESAS_RCAN0RMDF086     RSCAN0RMDF086
#define RENESAS_RCAN0RMDF087     RSCAN0RMDF087
#define RENESAS_RCAN0RMDF088     RSCAN0RMDF088
#define RENESAS_RCAN0RMDF089     RSCAN0RMDF089
#define RENESAS_RCAN0RMDF090     RSCAN0RMDF090
#define RENESAS_RCAN0RMDF091     RSCAN0RMDF091
#define RENESAS_RCAN0RMDF092     RSCAN0RMDF092
#define RENESAS_RCAN0RMDF093     RSCAN0RMDF093
#define RENESAS_RCAN0RMDF094     RSCAN0RMDF094
#define RENESAS_RCAN0RMDF095     RSCAN0RMDF095

/*RX FIFO MACROS*/
#define RENESAS_RCAN0RFCC0      RSCAN0RFCC0
#define RENESAS_RCAN0RFCC1      RSCAN0RFCC1
#define RENESAS_RCAN0RFCC2      RSCAN0RFCC2
#define RENESAS_RCAN0RFCC3      RSCAN0RFCC3
#define RENESAS_RCAN0RFCC4      RSCAN0RFCC4
#define RENESAS_RCAN0RFCC5      RSCAN0RFCC5
#define RENESAS_RCAN0RFCC6      RSCAN0RFCC6
#define RENESAS_RCAN0RFCC7      RSCAN0RFCC7

#define RENESAS_RCAN0RFSTS0      RSCAN0RFSTS0
#define RENESAS_RCAN0RFSTS1      RSCAN0RFSTS1
#define RENESAS_RCAN0RFSTS2      RSCAN0RFSTS2
#define RENESAS_RCAN0RFSTS3      RSCAN0RFSTS3
#define RENESAS_RCAN0RFSTS4      RSCAN0RFSTS4
#define RENESAS_RCAN0RFSTS5      RSCAN0RFSTS5
#define RENESAS_RCAN0RFSTS6      RSCAN0RFSTS6
#define RENESAS_RCAN0RFSTS7      RSCAN0RFSTS7

#define RENESAS_RCAN0RFPCTR0      RSCAN0RFPCTR0
#define RENESAS_RCAN0RFPCTR1      RSCAN0RFPCTR1
#define RENESAS_RCAN0RFPCTR2      RSCAN0RFPCTR2
#define RENESAS_RCAN0RFPCTR3      RSCAN0RFPCTR3
#define RENESAS_RCAN0RFPCTR4      RSCAN0RFPCTR4
#define RENESAS_RCAN0RFPCTR5      RSCAN0RFPCTR5
#define RENESAS_RCAN0RFPCTR6      RSCAN0RFPCTR6
#define RENESAS_RCAN0RFPCTR7      RSCAN0RFPCTR7

#define RENESAS_RCAN0RFID0      RSCAN0RFID0
#define RENESAS_RCAN0RFID1      RSCAN0RFID1
#define RENESAS_RCAN0RFID2      RSCAN0RFID2
#define RENESAS_RCAN0RFID3      RSCAN0RFID3
#define RENESAS_RCAN0RFID4      RSCAN0RFID4
#define RENESAS_RCAN0RFID5      RSCAN0RFID5
#define RENESAS_RCAN0RFID6      RSCAN0RFID6
#define RENESAS_RCAN0RFID7      RSCAN0RFID7

#define RENESAS_RCAN0RFPTR0      RSCAN0RFPTR0
#define RENESAS_RCAN0RFPTR1      RSCAN0RFPTR1
#define RENESAS_RCAN0RFPTR2      RSCAN0RFPTR2
#define RENESAS_RCAN0RFPTR3      RSCAN0RFPTR3
#define RENESAS_RCAN0RFPTR4      RSCAN0RFPTR4
#define RENESAS_RCAN0RFPTR5      RSCAN0RFPTR5
#define RENESAS_RCAN0RFPTR6      RSCAN0RFPTR6
#define RENESAS_RCAN0RFPTR7      RSCAN0RFPTR7

#define RENESAS_RCAN0RFDF00      RSCAN0RFDF00
#define RENESAS_RCAN0RFDF01      RSCAN0RFDF01
#define RENESAS_RCAN0RFDF02      RSCAN0RFDF02
#define RENESAS_RCAN0RFDF03      RSCAN0RFDF03
#define RENESAS_RCAN0RFDF04      RSCAN0RFDF04
#define RENESAS_RCAN0RFDF05      RSCAN0RFDF05
#define RENESAS_RCAN0RFDF06      RSCAN0RFDF06
#define RENESAS_RCAN0RFDF07      RSCAN0RFDF07

#define RENESAS_RCAN0RFDF10      RSCAN0RFDF10
#define RENESAS_RCAN0RFDF11      RSCAN0RFDF11
#define RENESAS_RCAN0RFDF12      RSCAN0RFDF12
#define RENESAS_RCAN0RFDF13      RSCAN0RFDF13
#define RENESAS_RCAN0RFDF14      RSCAN0RFDF14
#define RENESAS_RCAN0RFDF15      RSCAN0RFDF15
#define RENESAS_RCAN0RFDF16      RSCAN0RFDF16
#define RENESAS_RCAN0RFDF17      RSCAN0RFDF17

/*COM FIFO MACROS*/
#define RENESAS_RCAN0CFCC0      RSCAN0CFCC0
#define RENESAS_RCAN0CFCC1      RSCAN0CFCC1
#define RENESAS_RCAN0CFCC2      RSCAN0CFCC2
#define RENESAS_RCAN0CFCC3      RSCAN0CFCC3
#define RENESAS_RCAN0CFCC4      RSCAN0CFCC4
#define RENESAS_RCAN0CFCC5      RSCAN0CFCC5
#define RENESAS_RCAN0CFCC6      RSCAN0CFCC6
#define RENESAS_RCAN0CFCC7      RSCAN0CFCC7
#define RENESAS_RCAN0CFCC8      RSCAN0CFCC8
#define RENESAS_RCAN0CFCC9      RSCAN0CFCC9
#define RENESAS_RCAN0CFCC10     RSCAN0CFCC10
#define RENESAS_RCAN0CFCC11     RSCAN0CFCC11
#define RENESAS_RCAN0CFCC12     RSCAN0CFCC12
#define RENESAS_RCAN0CFCC13     RSCAN0CFCC13
#define RENESAS_RCAN0CFCC14     RSCAN0CFCC14
#define RENESAS_RCAN0CFCC15     RSCAN0CFCC15
#define RENESAS_RCAN0CFCC16     RSCAN0CFCC16
#define RENESAS_RCAN0CFCC17     RSCAN0CFCC17


#define RENESAS_RCAN0CFID0      RSCAN0CFID0
#define RENESAS_RCAN0CFID1      RSCAN0CFID1
#define RENESAS_RCAN0CFID2      RSCAN0CFID2
#define RENESAS_RCAN0CFID3      RSCAN0CFID3
#define RENESAS_RCAN0CFID4      RSCAN0CFID4
#define RENESAS_RCAN0CFID5      RSCAN0CFID5
#define RENESAS_RCAN0CFID6      RSCAN0CFID6
#define RENESAS_RCAN0CFID7      RSCAN0CFID7
#define RENESAS_RCAN0CFID8      RSCAN0CFID8
#define RENESAS_RCAN0CFID9      RSCAN0CFID9
#define RENESAS_RCAN0CFID10     RSCAN0CFID10
#define RENESAS_RCAN0CFID11     RSCAN0CFID11
#define RENESAS_RCAN0CFID12     RSCAN0CFID12
#define RENESAS_RCAN0CFID13     RSCAN0CFID13
#define RENESAS_RCAN0CFID14     RSCAN0CFID14
#define RENESAS_RCAN0CFID15     RSCAN0CFID15
#define RENESAS_RCAN0CFID16     RSCAN0CFID16
#define RENESAS_RCAN0CFID17     RSCAN0CFID17

#define RENESAS_RCAN0CFPTR0      RSCAN0CFPTR0
#define RENESAS_RCAN0CFPTR1      RSCAN0CFPTR1
#define RENESAS_RCAN0CFPTR2      RSCAN0CFPTR2
#define RENESAS_RCAN0CFPTR3      RSCAN0CFPTR3
#define RENESAS_RCAN0CFPTR4      RSCAN0CFPTR4
#define RENESAS_RCAN0CFPTR5      RSCAN0CFPTR5
#define RENESAS_RCAN0CFPTR6      RSCAN0CFPTR6
#define RENESAS_RCAN0CFPTR7      RSCAN0CFPTR7
#define RENESAS_RCAN0CFPTR8      RSCAN0CFPTR8
#define RENESAS_RCAN0CFPTR9      RSCAN0CFPTR9
#define RENESAS_RCAN0CFPTR10     RSCAN0CFPTR10
#define RENESAS_RCAN0CFPTR11     RSCAN0CFPTR11
#define RENESAS_RCAN0CFPTR12     RSCAN0CFPTR12
#define RENESAS_RCAN0CFPTR13     RSCAN0CFPTR13
#define RENESAS_RCAN0CFPTR14     RSCAN0CFPTR14
#define RENESAS_RCAN0CFPTR15     RSCAN0CFPTR15
#define RENESAS_RCAN0CFPTR16     RSCAN0CFPTR16
#define RENESAS_RCAN0CFPTR17     RSCAN0CFPTR17

#define RENESAS_RCAN0CFSTS0      RSCAN0CFSTS0
#define RENESAS_RCAN0CFSTS1      RSCAN0CFSTS1
#define RENESAS_RCAN0CFSTS2      RSCAN0CFSTS2
#define RENESAS_RCAN0CFSTS3      RSCAN0CFSTS3
#define RENESAS_RCAN0CFSTS4      RSCAN0CFSTS4
#define RENESAS_RCAN0CFSTS5      RSCAN0CFSTS5
#define RENESAS_RCAN0CFSTS6      RSCAN0CFSTS6
#define RENESAS_RCAN0CFSTS7      RSCAN0CFSTS7
#define RENESAS_RCAN0CFSTS8      RSCAN0CFSTS8
#define RENESAS_RCAN0CFSTS9      RSCAN0CFSTS9
#define RENESAS_RCAN0CFSTS10     RSCAN0CFSTS10
#define RENESAS_RCAN0CFSTS11     RSCAN0CFSTS11
#define RENESAS_RCAN0CFSTS12     RSCAN0CFSTS12
#define RENESAS_RCAN0CFSTS13     RSCAN0CFSTS13
#define RENESAS_RCAN0CFSTS14     RSCAN0CFSTS14
#define RENESAS_RCAN0CFSTS15     RSCAN0CFSTS15
#define RENESAS_RCAN0CFSTS16     RSCAN0CFSTS16
#define RENESAS_RCAN0CFSTS17     RSCAN0CFSTS17


#define RENESAS_RCAN0CFDF00      RSCAN0CFDF00
#define RENESAS_RCAN0CFDF01      RSCAN0CFDF01
#define RENESAS_RCAN0CFDF02      RSCAN0CFDF02
#define RENESAS_RCAN0CFDF03      RSCAN0CFDF03
#define RENESAS_RCAN0CFDF04      RSCAN0CFDF04
#define RENESAS_RCAN0CFDF05      RSCAN0CFDF05
#define RENESAS_RCAN0CFDF06      RSCAN0CFDF06
#define RENESAS_RCAN0CFDF07      RSCAN0CFDF07
#define RENESAS_RCAN0CFDF08      RSCAN0CFDF08
#define RENESAS_RCAN0CFDF09      RSCAN0CFDF09
#define RENESAS_RCAN0CFDF010     RSCAN0CFDF010
#define RENESAS_RCAN0CFDF011     RSCAN0CFDF011
#define RENESAS_RCAN0CFDF012     RSCAN0CFDF012
#define RENESAS_RCAN0CFDF013     RSCAN0CFDF013
#define RENESAS_RCAN0CFDF014     RSCAN0CFDF014
#define RENESAS_RCAN0CFDF015     RSCAN0CFDF015
#define RENESAS_RCAN0CFDF016     RSCAN0CFDF016
#define RENESAS_RCAN0CFDF017     RSCAN0CFDF017

#define RENESAS_RCAN0CFDF10      RSCAN0CFDF10
#define RENESAS_RCAN0CFDF11      RSCAN0CFDF11
#define RENESAS_RCAN0CFDF12      RSCAN0CFDF12
#define RENESAS_RCAN0CFDF13      RSCAN0CFDF13
#define RENESAS_RCAN0CFDF14      RSCAN0CFDF14
#define RENESAS_RCAN0CFDF15      RSCAN0CFDF15
#define RENESAS_RCAN0CFDF16      RSCAN0CFDF16
#define RENESAS_RCAN0CFDF17      RSCAN0CFDF17
#define RENESAS_RCAN0CFDF18      RSCAN0CFDF18
#define RENESAS_RCAN0CFDF19      RSCAN0CFDF19
#define RENESAS_RCAN0CFDF110     RSCAN0CFDF110
#define RENESAS_RCAN0CFDF111     RSCAN0CFDF111
#define RENESAS_RCAN0CFDF112     RSCAN0CFDF112
#define RENESAS_RCAN0CFDF113     RSCAN0CFDF113
#define RENESAS_RCAN0CFDF114     RSCAN0CFDF114
#define RENESAS_RCAN0CFDF115     RSCAN0CFDF115
#define RENESAS_RCAN0CFDF116     RSCAN0CFDF116
#define RENESAS_RCAN0CFDF117     RSCAN0CFDF117

#define RENESAS_RCAN0CFPCTR0      RSCAN0CFPCTR0
#define RENESAS_RCAN0CFPCTR1      RSCAN0CFPCTR1
#define RENESAS_RCAN0CFPCTR2      RSCAN0CFPCTR2
#define RENESAS_RCAN0CFPCTR3      RSCAN0CFPCTR3
#define RENESAS_RCAN0CFPCTR4      RSCAN0CFPCTR4
#define RENESAS_RCAN0CFPCTR5      RSCAN0CFPCTR5
#define RENESAS_RCAN0CFPCTR6      RSCAN0CFPCTR6
#define RENESAS_RCAN0CFPCTR7      RSCAN0CFPCTR7
#define RENESAS_RCAN0CFPCTR8      RSCAN0CFPCTR8
#define RENESAS_RCAN0CFPCTR9      RSCAN0CFPCTR9
#define RENESAS_RCAN0CFPCTR10     RSCAN0CFPCTR10
#define RENESAS_RCAN0CFPCTR11     RSCAN0CFPCTR11
#define RENESAS_RCAN0CFPCTR12     RSCAN0CFPCTR12
#define RENESAS_RCAN0CFPCTR13     RSCAN0CFPCTR13
#define RENESAS_RCAN0CFPCTR14     RSCAN0CFPCTR14
#define RENESAS_RCAN0CFPCTR15     RSCAN0CFPCTR15
#define RENESAS_RCAN0CFPCTR16     RSCAN0CFPCTR16
#define RENESAS_RCAN0CFPCTR17     RSCAN0CFPCTR17

/*TX BUFFERS MACROS*/
#define RENESAS_RCAN0TMID0      RSCAN0TMID0
#define RENESAS_RCAN0TMID1      RSCAN0TMID1
#define RENESAS_RCAN0TMID2      RSCAN0TMID2
#define RENESAS_RCAN0TMID3      RSCAN0TMID3
#define RENESAS_RCAN0TMID4      RSCAN0TMID4
#define RENESAS_RCAN0TMID5      RSCAN0TMID5
#define RENESAS_RCAN0TMID6      RSCAN0TMID6
#define RENESAS_RCAN0TMID7      RSCAN0TMID7
#define RENESAS_RCAN0TMID8      RSCAN0TMID8
#define RENESAS_RCAN0TMID9      RSCAN0TMID9
#define RENESAS_RCAN0TMID10     RSCAN0TMID10
#define RENESAS_RCAN0TMID11     RSCAN0TMID11
#define RENESAS_RCAN0TMID12     RSCAN0TMID12
#define RENESAS_RCAN0TMID13     RSCAN0TMID13
#define RENESAS_RCAN0TMID14     RSCAN0TMID14
#define RENESAS_RCAN0TMID15     RSCAN0TMID15
#define RENESAS_RCAN0TMID16     RSCAN0TMID16
#define RENESAS_RCAN0TMID17     RSCAN0TMID17
#define RENESAS_RCAN0TMID18     RSCAN0TMID18
#define RENESAS_RCAN0TMID19     RSCAN0TMID19
#define RENESAS_RCAN0TMID20     RSCAN0TMID20
#define RENESAS_RCAN0TMID21     RSCAN0TMID21
#define RENESAS_RCAN0TMID22     RSCAN0TMID22
#define RENESAS_RCAN0TMID23     RSCAN0TMID23
#define RENESAS_RCAN0TMID24     RSCAN0TMID24
#define RENESAS_RCAN0TMID25     RSCAN0TMID25
#define RENESAS_RCAN0TMID26     RSCAN0TMID26
#define RENESAS_RCAN0TMID27     RSCAN0TMID27
#define RENESAS_RCAN0TMID28     RSCAN0TMID28
#define RENESAS_RCAN0TMID29     RSCAN0TMID29
#define RENESAS_RCAN0TMID30     RSCAN0TMID30
#define RENESAS_RCAN0TMID31     RSCAN0TMID31
#define RENESAS_RCAN0TMID32     RSCAN0TMID32
#define RENESAS_RCAN0TMID33     RSCAN0TMID33
#define RENESAS_RCAN0TMID34     RSCAN0TMID34
#define RENESAS_RCAN0TMID35     RSCAN0TMID35
#define RENESAS_RCAN0TMID36     RSCAN0TMID36
#define RENESAS_RCAN0TMID37     RSCAN0TMID37
#define RENESAS_RCAN0TMID38     RSCAN0TMID38
#define RENESAS_RCAN0TMID39     RSCAN0TMID39
#define RENESAS_RCAN0TMID40     RSCAN0TMID40
#define RENESAS_RCAN0TMID41     RSCAN0TMID41
#define RENESAS_RCAN0TMID42     RSCAN0TMID42
#define RENESAS_RCAN0TMID43     RSCAN0TMID43
#define RENESAS_RCAN0TMID44     RSCAN0TMID44
#define RENESAS_RCAN0TMID45     RSCAN0TMID45
#define RENESAS_RCAN0TMID46     RSCAN0TMID46
#define RENESAS_RCAN0TMID47     RSCAN0TMID47
#define RENESAS_RCAN0TMID48     RSCAN0TMID48
#define RENESAS_RCAN0TMID49     RSCAN0TMID49
#define RENESAS_RCAN0TMID50     RSCAN0TMID50
#define RENESAS_RCAN0TMID51     RSCAN0TMID51
#define RENESAS_RCAN0TMID52     RSCAN0TMID52
#define RENESAS_RCAN0TMID53     RSCAN0TMID53
#define RENESAS_RCAN0TMID54     RSCAN0TMID54
#define RENESAS_RCAN0TMID55     RSCAN0TMID55
#define RENESAS_RCAN0TMID56     RSCAN0TMID56
#define RENESAS_RCAN0TMID57     RSCAN0TMID57
#define RENESAS_RCAN0TMID58     RSCAN0TMID58
#define RENESAS_RCAN0TMID59     RSCAN0TMID59
#define RENESAS_RCAN0TMID60     RSCAN0TMID60
#define RENESAS_RCAN0TMID61     RSCAN0TMID61
#define RENESAS_RCAN0TMID62     RSCAN0TMID62
#define RENESAS_RCAN0TMID63     RSCAN0TMID63
#define RENESAS_RCAN0TMID64     RSCAN0TMID64
#define RENESAS_RCAN0TMID65     RSCAN0TMID65
#define RENESAS_RCAN0TMID66     RSCAN0TMID66
#define RENESAS_RCAN0TMID67     RSCAN0TMID67
#define RENESAS_RCAN0TMID68     RSCAN0TMID68
#define RENESAS_RCAN0TMID69     RSCAN0TMID69
#define RENESAS_RCAN0TMID70     RSCAN0TMID70
#define RENESAS_RCAN0TMID71     RSCAN0TMID71
#define RENESAS_RCAN0TMID72     RSCAN0TMID72
#define RENESAS_RCAN0TMID73     RSCAN0TMID73
#define RENESAS_RCAN0TMID74     RSCAN0TMID74
#define RENESAS_RCAN0TMID75     RSCAN0TMID75
#define RENESAS_RCAN0TMID76     RSCAN0TMID76
#define RENESAS_RCAN0TMID77     RSCAN0TMID77
#define RENESAS_RCAN0TMID78     RSCAN0TMID78
#define RENESAS_RCAN0TMID79     RSCAN0TMID79
#define RENESAS_RCAN0TMID80     RSCAN0TMID80
#define RENESAS_RCAN0TMID81     RSCAN0TMID81
#define RENESAS_RCAN0TMID82     RSCAN0TMID82
#define RENESAS_RCAN0TMID83     RSCAN0TMID83
#define RENESAS_RCAN0TMID84     RSCAN0TMID84
#define RENESAS_RCAN0TMID85     RSCAN0TMID85
#define RENESAS_RCAN0TMID86     RSCAN0TMID86
#define RENESAS_RCAN0TMID87     RSCAN0TMID87
#define RENESAS_RCAN0TMID88     RSCAN0TMID88
#define RENESAS_RCAN0TMID89     RSCAN0TMID89
#define RENESAS_RCAN0TMID90     RSCAN0TMID90
#define RENESAS_RCAN0TMID91     RSCAN0TMID91
#define RENESAS_RCAN0TMID92     RSCAN0TMID92
#define RENESAS_RCAN0TMID93     RSCAN0TMID93
#define RENESAS_RCAN0TMID94     RSCAN0TMID94
#define RENESAS_RCAN0TMID95     RSCAN0TMID95

#define RENESAS_RCAN0TMPTR0      RSCAN0TMPTR0
#define RENESAS_RCAN0TMPTR1      RSCAN0TMPTR1
#define RENESAS_RCAN0TMPTR2      RSCAN0TMPTR2
#define RENESAS_RCAN0TMPTR3      RSCAN0TMPTR3
#define RENESAS_RCAN0TMPTR4      RSCAN0TMPTR4
#define RENESAS_RCAN0TMPTR5      RSCAN0TMPTR5
#define RENESAS_RCAN0TMPTR6      RSCAN0TMPTR6
#define RENESAS_RCAN0TMPTR7      RSCAN0TMPTR7
#define RENESAS_RCAN0TMPTR8      RSCAN0TMPTR8
#define RENESAS_RCAN0TMPTR9      RSCAN0TMPTR9
#define RENESAS_RCAN0TMPTR10     RSCAN0TMPTR10
#define RENESAS_RCAN0TMPTR11     RSCAN0TMPTR11
#define RENESAS_RCAN0TMPTR12     RSCAN0TMPTR12
#define RENESAS_RCAN0TMPTR13     RSCAN0TMPTR13
#define RENESAS_RCAN0TMPTR14     RSCAN0TMPTR14
#define RENESAS_RCAN0TMPTR15     RSCAN0TMPTR15
#define RENESAS_RCAN0TMPTR16     RSCAN0TMPTR16
#define RENESAS_RCAN0TMPTR17     RSCAN0TMPTR17
#define RENESAS_RCAN0TMPTR18     RSCAN0TMPTR18
#define RENESAS_RCAN0TMPTR19     RSCAN0TMPTR19
#define RENESAS_RCAN0TMPTR20     RSCAN0TMPTR20
#define RENESAS_RCAN0TMPTR21     RSCAN0TMPTR21
#define RENESAS_RCAN0TMPTR22     RSCAN0TMPTR22
#define RENESAS_RCAN0TMPTR23     RSCAN0TMPTR23
#define RENESAS_RCAN0TMPTR24     RSCAN0TMPTR24
#define RENESAS_RCAN0TMPTR25     RSCAN0TMPTR25
#define RENESAS_RCAN0TMPTR26     RSCAN0TMPTR26
#define RENESAS_RCAN0TMPTR27     RSCAN0TMPTR27
#define RENESAS_RCAN0TMPTR28     RSCAN0TMPTR28
#define RENESAS_RCAN0TMPTR29     RSCAN0TMPTR29
#define RENESAS_RCAN0TMPTR30     RSCAN0TMPTR30
#define RENESAS_RCAN0TMPTR31     RSCAN0TMPTR31
#define RENESAS_RCAN0TMPTR32     RSCAN0TMPTR32
#define RENESAS_RCAN0TMPTR33     RSCAN0TMPTR33
#define RENESAS_RCAN0TMPTR34     RSCAN0TMPTR34
#define RENESAS_RCAN0TMPTR35     RSCAN0TMPTR35
#define RENESAS_RCAN0TMPTR36     RSCAN0TMPTR36
#define RENESAS_RCAN0TMPTR37     RSCAN0TMPTR37
#define RENESAS_RCAN0TMPTR38     RSCAN0TMPTR38
#define RENESAS_RCAN0TMPTR39     RSCAN0TMPTR39
#define RENESAS_RCAN0TMPTR40     RSCAN0TMPTR40
#define RENESAS_RCAN0TMPTR41     RSCAN0TMPTR41
#define RENESAS_RCAN0TMPTR42     RSCAN0TMPTR42
#define RENESAS_RCAN0TMPTR43     RSCAN0TMPTR43
#define RENESAS_RCAN0TMPTR44     RSCAN0TMPTR44
#define RENESAS_RCAN0TMPTR45     RSCAN0TMPTR45
#define RENESAS_RCAN0TMPTR46     RSCAN0TMPTR46
#define RENESAS_RCAN0TMPTR47     RSCAN0TMPTR47
#define RENESAS_RCAN0TMPTR48     RSCAN0TMPTR48
#define RENESAS_RCAN0TMPTR49     RSCAN0TMPTR49
#define RENESAS_RCAN0TMPTR50     RSCAN0TMPTR50
#define RENESAS_RCAN0TMPTR51     RSCAN0TMPTR51
#define RENESAS_RCAN0TMPTR52     RSCAN0TMPTR52
#define RENESAS_RCAN0TMPTR53     RSCAN0TMPTR53
#define RENESAS_RCAN0TMPTR54     RSCAN0TMPTR54
#define RENESAS_RCAN0TMPTR55     RSCAN0TMPTR55
#define RENESAS_RCAN0TMPTR56     RSCAN0TMPTR56
#define RENESAS_RCAN0TMPTR57     RSCAN0TMPTR57
#define RENESAS_RCAN0TMPTR58     RSCAN0TMPTR58
#define RENESAS_RCAN0TMPTR59     RSCAN0TMPTR59
#define RENESAS_RCAN0TMPTR60     RSCAN0TMPTR60
#define RENESAS_RCAN0TMPTR61     RSCAN0TMPTR61
#define RENESAS_RCAN0TMPTR62     RSCAN0TMPTR62
#define RENESAS_RCAN0TMPTR63     RSCAN0TMPTR63
#define RENESAS_RCAN0TMPTR64     RSCAN0TMPTR64
#define RENESAS_RCAN0TMPTR65     RSCAN0TMPTR65
#define RENESAS_RCAN0TMPTR66     RSCAN0TMPTR66
#define RENESAS_RCAN0TMPTR67     RSCAN0TMPTR67
#define RENESAS_RCAN0TMPTR68     RSCAN0TMPTR68
#define RENESAS_RCAN0TMPTR69     RSCAN0TMPTR69
#define RENESAS_RCAN0TMPTR70     RSCAN0TMPTR70
#define RENESAS_RCAN0TMPTR71     RSCAN0TMPTR71
#define RENESAS_RCAN0TMPTR72     RSCAN0TMPTR72
#define RENESAS_RCAN0TMPTR73     RSCAN0TMPTR73
#define RENESAS_RCAN0TMPTR74     RSCAN0TMPTR74
#define RENESAS_RCAN0TMPTR75     RSCAN0TMPTR75
#define RENESAS_RCAN0TMPTR76     RSCAN0TMPTR76
#define RENESAS_RCAN0TMPTR77     RSCAN0TMPTR77
#define RENESAS_RCAN0TMPTR78     RSCAN0TMPTR78
#define RENESAS_RCAN0TMPTR79     RSCAN0TMPTR79
#define RENESAS_RCAN0TMPTR80     RSCAN0TMPTR80
#define RENESAS_RCAN0TMPTR81     RSCAN0TMPTR81
#define RENESAS_RCAN0TMPTR82     RSCAN0TMPTR82
#define RENESAS_RCAN0TMPTR83     RSCAN0TMPTR83
#define RENESAS_RCAN0TMPTR84     RSCAN0TMPTR84
#define RENESAS_RCAN0TMPTR85     RSCAN0TMPTR85
#define RENESAS_RCAN0TMPTR86     RSCAN0TMPTR86
#define RENESAS_RCAN0TMPTR87     RSCAN0TMPTR87
#define RENESAS_RCAN0TMPTR88     RSCAN0TMPTR88
#define RENESAS_RCAN0TMPTR89     RSCAN0TMPTR89
#define RENESAS_RCAN0TMPTR90     RSCAN0TMPTR90
#define RENESAS_RCAN0TMPTR91     RSCAN0TMPTR91
#define RENESAS_RCAN0TMPTR92     RSCAN0TMPTR92
#define RENESAS_RCAN0TMPTR93     RSCAN0TMPTR93
#define RENESAS_RCAN0TMPTR94     RSCAN0TMPTR94
#define RENESAS_RCAN0TMPTR95     RSCAN0TMPTR95



#define RENESAS_RCAN0TMDF00      RSCAN0TMDF00
#define RENESAS_RCAN0TMDF01      RSCAN0TMDF01
#define RENESAS_RCAN0TMDF02      RSCAN0TMDF02
#define RENESAS_RCAN0TMDF03      RSCAN0TMDF03
#define RENESAS_RCAN0TMDF04      RSCAN0TMDF04
#define RENESAS_RCAN0TMDF05      RSCAN0TMDF05
#define RENESAS_RCAN0TMDF06      RSCAN0TMDF06
#define RENESAS_RCAN0TMDF07      RSCAN0TMDF07
#define RENESAS_RCAN0TMDF08      RSCAN0TMDF08
#define RENESAS_RCAN0TMDF09      RSCAN0TMDF09
#define RENESAS_RCAN0TMDF010     RSCAN0TMDF010
#define RENESAS_RCAN0TMDF011     RSCAN0TMDF011
#define RENESAS_RCAN0TMDF012     RSCAN0TMDF012
#define RENESAS_RCAN0TMDF013     RSCAN0TMDF013
#define RENESAS_RCAN0TMDF014     RSCAN0TMDF014
#define RENESAS_RCAN0TMDF015     RSCAN0TMDF015
#define RENESAS_RCAN0TMDF016     RSCAN0TMDF016
#define RENESAS_RCAN0TMDF017     RSCAN0TMDF017
#define RENESAS_RCAN0TMDF018     RSCAN0TMDF018
#define RENESAS_RCAN0TMDF019     RSCAN0TMDF019
#define RENESAS_RCAN0TMDF020     RSCAN0TMDF020
#define RENESAS_RCAN0TMDF021     RSCAN0TMDF021
#define RENESAS_RCAN0TMDF022     RSCAN0TMDF022
#define RENESAS_RCAN0TMDF023     RSCAN0TMDF023
#define RENESAS_RCAN0TMDF024     RSCAN0TMDF024
#define RENESAS_RCAN0TMDF025     RSCAN0TMDF025
#define RENESAS_RCAN0TMDF026     RSCAN0TMDF026
#define RENESAS_RCAN0TMDF027     RSCAN0TMDF027
#define RENESAS_RCAN0TMDF028     RSCAN0TMDF028
#define RENESAS_RCAN0TMDF029     RSCAN0TMDF029
#define RENESAS_RCAN0TMDF030     RSCAN0TMDF030
#define RENESAS_RCAN0TMDF031     RSCAN0TMDF031
#define RENESAS_RCAN0TMDF032     RSCAN0TMDF032
#define RENESAS_RCAN0TMDF033     RSCAN0TMDF033
#define RENESAS_RCAN0TMDF034     RSCAN0TMDF034
#define RENESAS_RCAN0TMDF035     RSCAN0TMDF035
#define RENESAS_RCAN0TMDF036     RSCAN0TMDF036
#define RENESAS_RCAN0TMDF037     RSCAN0TMDF037
#define RENESAS_RCAN0TMDF038     RSCAN0TMDF038
#define RENESAS_RCAN0TMDF039     RSCAN0TMDF039
#define RENESAS_RCAN0TMDF040     RSCAN0TMDF040
#define RENESAS_RCAN0TMDF041     RSCAN0TMDF041
#define RENESAS_RCAN0TMDF042     RSCAN0TMDF042
#define RENESAS_RCAN0TMDF043     RSCAN0TMDF043
#define RENESAS_RCAN0TMDF044     RSCAN0TMDF044
#define RENESAS_RCAN0TMDF045     RSCAN0TMDF045
#define RENESAS_RCAN0TMDF046     RSCAN0TMDF046
#define RENESAS_RCAN0TMDF047     RSCAN0TMDF047
#define RENESAS_RCAN0TMDF048     RSCAN0TMDF048
#define RENESAS_RCAN0TMDF049     RSCAN0TMDF049
#define RENESAS_RCAN0TMDF050     RSCAN0TMDF050
#define RENESAS_RCAN0TMDF051     RSCAN0TMDF051
#define RENESAS_RCAN0TMDF052     RSCAN0TMDF052
#define RENESAS_RCAN0TMDF053     RSCAN0TMDF053
#define RENESAS_RCAN0TMDF054     RSCAN0TMDF054
#define RENESAS_RCAN0TMDF055     RSCAN0TMDF055
#define RENESAS_RCAN0TMDF056     RSCAN0TMDF056
#define RENESAS_RCAN0TMDF057     RSCAN0TMDF057
#define RENESAS_RCAN0TMDF058     RSCAN0TMDF058
#define RENESAS_RCAN0TMDF059     RSCAN0TMDF059
#define RENESAS_RCAN0TMDF060     RSCAN0TMDF060
#define RENESAS_RCAN0TMDF061     RSCAN0TMDF061
#define RENESAS_RCAN0TMDF062     RSCAN0TMDF062
#define RENESAS_RCAN0TMDF063     RSCAN0TMDF063
#define RENESAS_RCAN0TMDF064     RSCAN0TMDF064
#define RENESAS_RCAN0TMDF065     RSCAN0TMDF065
#define RENESAS_RCAN0TMDF066     RSCAN0TMDF066
#define RENESAS_RCAN0TMDF067     RSCAN0TMDF067
#define RENESAS_RCAN0TMDF068     RSCAN0TMDF068
#define RENESAS_RCAN0TMDF069     RSCAN0TMDF069
#define RENESAS_RCAN0TMDF070     RSCAN0TMDF070
#define RENESAS_RCAN0TMDF071     RSCAN0TMDF071
#define RENESAS_RCAN0TMDF072     RSCAN0TMDF072
#define RENESAS_RCAN0TMDF073     RSCAN0TMDF073
#define RENESAS_RCAN0TMDF074     RSCAN0TMDF074
#define RENESAS_RCAN0TMDF075     RSCAN0TMDF075
#define RENESAS_RCAN0TMDF076     RSCAN0TMDF076
#define RENESAS_RCAN0TMDF077     RSCAN0TMDF077
#define RENESAS_RCAN0TMDF078     RSCAN0TMDF078
#define RENESAS_RCAN0TMDF079     RSCAN0TMDF079
#define RENESAS_RCAN0TMDF080     RSCAN0TMDF080
#define RENESAS_RCAN0TMDF081     RSCAN0TMDF081
#define RENESAS_RCAN0TMDF082     RSCAN0TMDF082
#define RENESAS_RCAN0TMDF083     RSCAN0TMDF083
#define RENESAS_RCAN0TMDF084     RSCAN0TMDF084
#define RENESAS_RCAN0TMDF085     RSCAN0TMDF085
#define RENESAS_RCAN0TMDF086     RSCAN0TMDF086
#define RENESAS_RCAN0TMDF087     RSCAN0TMDF087
#define RENESAS_RCAN0TMDF088     RSCAN0TMDF088
#define RENESAS_RCAN0TMDF089     RSCAN0TMDF089
#define RENESAS_RCAN0TMDF090     RSCAN0TMDF090
#define RENESAS_RCAN0TMDF091     RSCAN0TMDF091
#define RENESAS_RCAN0TMDF092     RSCAN0TMDF092
#define RENESAS_RCAN0TMDF093     RSCAN0TMDF093
#define RENESAS_RCAN0TMDF094     RSCAN0TMDF094
#define RENESAS_RCAN0TMDF095     RSCAN0TMDF095


#define RENESAS_RCAN0TMC0      RSCAN0TMC0
#define RENESAS_RCAN0TMC1      RSCAN0TMC1
#define RENESAS_RCAN0TMC2      RSCAN0TMC2
#define RENESAS_RCAN0TMC3      RSCAN0TMC3
#define RENESAS_RCAN0TMC4      RSCAN0TMC4
#define RENESAS_RCAN0TMC5      RSCAN0TMC5
#define RENESAS_RCAN0TMC6      RSCAN0TMC6
#define RENESAS_RCAN0TMC7      RSCAN0TMC7
#define RENESAS_RCAN0TMC8      RSCAN0TMC8
#define RENESAS_RCAN0TMC9      RSCAN0TMC9
#define RENESAS_RCAN0TMC10     RSCAN0TMC10
#define RENESAS_RCAN0TMC11     RSCAN0TMC11
#define RENESAS_RCAN0TMC12     RSCAN0TMC12
#define RENESAS_RCAN0TMC13     RSCAN0TMC13
#define RENESAS_RCAN0TMC14     RSCAN0TMC14
#define RENESAS_RCAN0TMC15     RSCAN0TMC15
#define RENESAS_RCAN0TMC16     RSCAN0TMC16
#define RENESAS_RCAN0TMC17     RSCAN0TMC17
#define RENESAS_RCAN0TMC18     RSCAN0TMC18
#define RENESAS_RCAN0TMC19     RSCAN0TMC19
#define RENESAS_RCAN0TMC20     RSCAN0TMC20
#define RENESAS_RCAN0TMC21     RSCAN0TMC21
#define RENESAS_RCAN0TMC22     RSCAN0TMC22
#define RENESAS_RCAN0TMC23     RSCAN0TMC23
#define RENESAS_RCAN0TMC24     RSCAN0TMC24
#define RENESAS_RCAN0TMC25     RSCAN0TMC25
#define RENESAS_RCAN0TMC26     RSCAN0TMC26
#define RENESAS_RCAN0TMC27     RSCAN0TMC27
#define RENESAS_RCAN0TMC28     RSCAN0TMC28
#define RENESAS_RCAN0TMC29     RSCAN0TMC29
#define RENESAS_RCAN0TMC30     RSCAN0TMC30
#define RENESAS_RCAN0TMC31     RSCAN0TMC31
#define RENESAS_RCAN0TMC32     RSCAN0TMC32
#define RENESAS_RCAN0TMC33     RSCAN0TMC33
#define RENESAS_RCAN0TMC34     RSCAN0TMC34
#define RENESAS_RCAN0TMC35     RSCAN0TMC35
#define RENESAS_RCAN0TMC36     RSCAN0TMC36
#define RENESAS_RCAN0TMC37     RSCAN0TMC37
#define RENESAS_RCAN0TMC38     RSCAN0TMC38
#define RENESAS_RCAN0TMC39     RSCAN0TMC39
#define RENESAS_RCAN0TMC40     RSCAN0TMC40
#define RENESAS_RCAN0TMC41     RSCAN0TMC41
#define RENESAS_RCAN0TMC42     RSCAN0TMC42
#define RENESAS_RCAN0TMC43     RSCAN0TMC43
#define RENESAS_RCAN0TMC44     RSCAN0TMC44
#define RENESAS_RCAN0TMC45     RSCAN0TMC45
#define RENESAS_RCAN0TMC46     RSCAN0TMC46
#define RENESAS_RCAN0TMC47     RSCAN0TMC47
#define RENESAS_RCAN0TMC48     RSCAN0TMC48
#define RENESAS_RCAN0TMC49     RSCAN0TMC49
#define RENESAS_RCAN0TMC50     RSCAN0TMC50
#define RENESAS_RCAN0TMC51     RSCAN0TMC51
#define RENESAS_RCAN0TMC52     RSCAN0TMC52
#define RENESAS_RCAN0TMC53     RSCAN0TMC53
#define RENESAS_RCAN0TMC54     RSCAN0TMC54
#define RENESAS_RCAN0TMC55     RSCAN0TMC55
#define RENESAS_RCAN0TMC56     RSCAN0TMC56
#define RENESAS_RCAN0TMC57     RSCAN0TMC57
#define RENESAS_RCAN0TMC58     RSCAN0TMC58
#define RENESAS_RCAN0TMC59     RSCAN0TMC59
#define RENESAS_RCAN0TMC60     RSCAN0TMC60
#define RENESAS_RCAN0TMC61     RSCAN0TMC61
#define RENESAS_RCAN0TMC62     RSCAN0TMC62
#define RENESAS_RCAN0TMC63     RSCAN0TMC63
#define RENESAS_RCAN0TMC64     RSCAN0TMC64
#define RENESAS_RCAN0TMC65     RSCAN0TMC65
#define RENESAS_RCAN0TMC66     RSCAN0TMC66
#define RENESAS_RCAN0TMC67     RSCAN0TMC67
#define RENESAS_RCAN0TMC68     RSCAN0TMC68
#define RENESAS_RCAN0TMC69     RSCAN0TMC69
#define RENESAS_RCAN0TMC70     RSCAN0TMC70
#define RENESAS_RCAN0TMC71     RSCAN0TMC71
#define RENESAS_RCAN0TMC72     RSCAN0TMC72
#define RENESAS_RCAN0TMC73     RSCAN0TMC73
#define RENESAS_RCAN0TMC74     RSCAN0TMC74
#define RENESAS_RCAN0TMC75     RSCAN0TMC75
#define RENESAS_RCAN0TMC76     RSCAN0TMC76
#define RENESAS_RCAN0TMC77     RSCAN0TMC77
#define RENESAS_RCAN0TMC78     RSCAN0TMC78
#define RENESAS_RCAN0TMC79     RSCAN0TMC79
#define RENESAS_RCAN0TMC80     RSCAN0TMC80
#define RENESAS_RCAN0TMC81     RSCAN0TMC81
#define RENESAS_RCAN0TMC82     RSCAN0TMC82
#define RENESAS_RCAN0TMC83     RSCAN0TMC83
#define RENESAS_RCAN0TMC84     RSCAN0TMC84
#define RENESAS_RCAN0TMC85     RSCAN0TMC85
#define RENESAS_RCAN0TMC86     RSCAN0TMC86
#define RENESAS_RCAN0TMC87     RSCAN0TMC87
#define RENESAS_RCAN0TMC88     RSCAN0TMC88
#define RENESAS_RCAN0TMC89     RSCAN0TMC89
#define RENESAS_RCAN0TMC90     RSCAN0TMC90
#define RENESAS_RCAN0TMC91     RSCAN0TMC91
#define RENESAS_RCAN0TMC92     RSCAN0TMC92
#define RENESAS_RCAN0TMC93     RSCAN0TMC93
#define RENESAS_RCAN0TMC94     RSCAN0TMC94
#define RENESAS_RCAN0TMC95     RSCAN0TMC95

#define RENESAS_RCAN0TMSTS0      RSCAN0TMSTS0
#define RENESAS_RCAN0TMSTS1      RSCAN0TMSTS1
#define RENESAS_RCAN0TMSTS2      RSCAN0TMSTS2
#define RENESAS_RCAN0TMSTS3      RSCAN0TMSTS3
#define RENESAS_RCAN0TMSTS4      RSCAN0TMSTS4
#define RENESAS_RCAN0TMSTS5      RSCAN0TMSTS5
#define RENESAS_RCAN0TMSTS6      RSCAN0TMSTS6
#define RENESAS_RCAN0TMSTS7      RSCAN0TMSTS7
#define RENESAS_RCAN0TMSTS8      RSCAN0TMSTS8
#define RENESAS_RCAN0TMSTS9      RSCAN0TMSTS9
#define RENESAS_RCAN0TMSTS10     RSCAN0TMSTS10
#define RENESAS_RCAN0TMSTS11     RSCAN0TMSTS11
#define RENESAS_RCAN0TMSTS12     RSCAN0TMSTS12
#define RENESAS_RCAN0TMSTS13     RSCAN0TMSTS13
#define RENESAS_RCAN0TMSTS14     RSCAN0TMSTS14
#define RENESAS_RCAN0TMSTS15     RSCAN0TMSTS15
#define RENESAS_RCAN0TMSTS16     RSCAN0TMSTS16
#define RENESAS_RCAN0TMSTS17     RSCAN0TMSTS17
#define RENESAS_RCAN0TMSTS18     RSCAN0TMSTS18
#define RENESAS_RCAN0TMSTS19     RSCAN0TMSTS19
#define RENESAS_RCAN0TMSTS20     RSCAN0TMSTS20
#define RENESAS_RCAN0TMSTS21     RSCAN0TMSTS21
#define RENESAS_RCAN0TMSTS22     RSCAN0TMSTS22
#define RENESAS_RCAN0TMSTS23     RSCAN0TMSTS23
#define RENESAS_RCAN0TMSTS24     RSCAN0TMSTS24
#define RENESAS_RCAN0TMSTS25     RSCAN0TMSTS25
#define RENESAS_RCAN0TMSTS26     RSCAN0TMSTS26
#define RENESAS_RCAN0TMSTS27     RSCAN0TMSTS27
#define RENESAS_RCAN0TMSTS28     RSCAN0TMSTS28
#define RENESAS_RCAN0TMSTS29     RSCAN0TMSTS29
#define RENESAS_RCAN0TMSTS30     RSCAN0TMSTS30
#define RENESAS_RCAN0TMSTS31     RSCAN0TMSTS31
#define RENESAS_RCAN0TMSTS32     RSCAN0TMSTS32
#define RENESAS_RCAN0TMSTS33     RSCAN0TMSTS33
#define RENESAS_RCAN0TMSTS34     RSCAN0TMSTS34
#define RENESAS_RCAN0TMSTS35     RSCAN0TMSTS35
#define RENESAS_RCAN0TMSTS36     RSCAN0TMSTS36
#define RENESAS_RCAN0TMSTS37     RSCAN0TMSTS37
#define RENESAS_RCAN0TMSTS38     RSCAN0TMSTS38
#define RENESAS_RCAN0TMSTS39     RSCAN0TMSTS39
#define RENESAS_RCAN0TMSTS40     RSCAN0TMSTS40
#define RENESAS_RCAN0TMSTS41     RSCAN0TMSTS41
#define RENESAS_RCAN0TMSTS42     RSCAN0TMSTS42
#define RENESAS_RCAN0TMSTS43     RSCAN0TMSTS43
#define RENESAS_RCAN0TMSTS44     RSCAN0TMSTS44
#define RENESAS_RCAN0TMSTS45     RSCAN0TMSTS45
#define RENESAS_RCAN0TMSTS46     RSCAN0TMSTS46
#define RENESAS_RCAN0TMSTS47     RSCAN0TMSTS47
#define RENESAS_RCAN0TMSTS48     RSCAN0TMSTS48
#define RENESAS_RCAN0TMSTS49     RSCAN0TMSTS49
#define RENESAS_RCAN0TMSTS50     RSCAN0TMSTS50
#define RENESAS_RCAN0TMSTS51     RSCAN0TMSTS51
#define RENESAS_RCAN0TMSTS52     RSCAN0TMSTS52
#define RENESAS_RCAN0TMSTS53     RSCAN0TMSTS53
#define RENESAS_RCAN0TMSTS54     RSCAN0TMSTS54
#define RENESAS_RCAN0TMSTS55     RSCAN0TMSTS55
#define RENESAS_RCAN0TMSTS56     RSCAN0TMSTS56
#define RENESAS_RCAN0TMSTS57     RSCAN0TMSTS57
#define RENESAS_RCAN0TMSTS58     RSCAN0TMSTS58
#define RENESAS_RCAN0TMSTS59     RSCAN0TMSTS59
#define RENESAS_RCAN0TMSTS60     RSCAN0TMSTS60
#define RENESAS_RCAN0TMSTS61     RSCAN0TMSTS61
#define RENESAS_RCAN0TMSTS62     RSCAN0TMSTS62
#define RENESAS_RCAN0TMSTS63     RSCAN0TMSTS63
#define RENESAS_RCAN0TMSTS64     RSCAN0TMSTS64
#define RENESAS_RCAN0TMSTS65     RSCAN0TMSTS65
#define RENESAS_RCAN0TMSTS66     RSCAN0TMSTS66
#define RENESAS_RCAN0TMSTS67     RSCAN0TMSTS67
#define RENESAS_RCAN0TMSTS68     RSCAN0TMSTS68
#define RENESAS_RCAN0TMSTS69     RSCAN0TMSTS69
#define RENESAS_RCAN0TMSTS70     RSCAN0TMSTS70
#define RENESAS_RCAN0TMSTS71     RSCAN0TMSTS71
#define RENESAS_RCAN0TMSTS72     RSCAN0TMSTS72
#define RENESAS_RCAN0TMSTS73     RSCAN0TMSTS73
#define RENESAS_RCAN0TMSTS74     RSCAN0TMSTS74
#define RENESAS_RCAN0TMSTS75     RSCAN0TMSTS75
#define RENESAS_RCAN0TMSTS76     RSCAN0TMSTS76
#define RENESAS_RCAN0TMSTS77     RSCAN0TMSTS77
#define RENESAS_RCAN0TMSTS78     RSCAN0TMSTS78
#define RENESAS_RCAN0TMSTS79     RSCAN0TMSTS79
#define RENESAS_RCAN0TMSTS80     RSCAN0TMSTS80
#define RENESAS_RCAN0TMSTS81     RSCAN0TMSTS81
#define RENESAS_RCAN0TMSTS82     RSCAN0TMSTS82
#define RENESAS_RCAN0TMSTS83     RSCAN0TMSTS83
#define RENESAS_RCAN0TMSTS84     RSCAN0TMSTS84
#define RENESAS_RCAN0TMSTS85     RSCAN0TMSTS85
#define RENESAS_RCAN0TMSTS86     RSCAN0TMSTS86
#define RENESAS_RCAN0TMSTS87     RSCAN0TMSTS87
#define RENESAS_RCAN0TMSTS88     RSCAN0TMSTS88
#define RENESAS_RCAN0TMSTS89     RSCAN0TMSTS89
#define RENESAS_RCAN0TMSTS90     RSCAN0TMSTS90
#define RENESAS_RCAN0TMSTS91     RSCAN0TMSTS91
#define RENESAS_RCAN0TMSTS92     RSCAN0TMSTS92
#define RENESAS_RCAN0TMSTS93     RSCAN0TMSTS93
#define RENESAS_RCAN0TMSTS94     RSCAN0TMSTS94
#define RENESAS_RCAN0TMSTS95     RSCAN0TMSTS95

/*ACCEPTANCE FILTER LIST MACROS*/
#define RENESAS_RCAN0GAFLID0      RSCAN0GAFLID0
#define RENESAS_RCAN0GAFLID1      RSCAN0GAFLID1
#define RENESAS_RCAN0GAFLID2      RSCAN0GAFLID2
#define RENESAS_RCAN0GAFLID3      RSCAN0GAFLID3
#define RENESAS_RCAN0GAFLID4      RSCAN0GAFLID4
#define RENESAS_RCAN0GAFLID5      RSCAN0GAFLID5
#define RENESAS_RCAN0GAFLID6      RSCAN0GAFLID6
#define RENESAS_RCAN0GAFLID7      RSCAN0GAFLID7
#define RENESAS_RCAN0GAFLID8      RSCAN0GAFLID8
#define RENESAS_RCAN0GAFLID9      RSCAN0GAFLID9
#define RENESAS_RCAN0GAFLID10     RSCAN0GAFLID10
#define RENESAS_RCAN0GAFLID11     RSCAN0GAFLID11
#define RENESAS_RCAN0GAFLID12     RSCAN0GAFLID12
#define RENESAS_RCAN0GAFLID13     RSCAN0GAFLID13
#define RENESAS_RCAN0GAFLID14     RSCAN0GAFLID14
#define RENESAS_RCAN0GAFLID15     RSCAN0GAFLID15

#define RENESAS_RCAN0GAFLM0      RSCAN0GAFLM0
#define RENESAS_RCAN0GAFLM1      RSCAN0GAFLM1
#define RENESAS_RCAN0GAFLM2      RSCAN0GAFLM2
#define RENESAS_RCAN0GAFLM3      RSCAN0GAFLM3
#define RENESAS_RCAN0GAFLM4      RSCAN0GAFLM4
#define RENESAS_RCAN0GAFLM5      RSCAN0GAFLM5
#define RENESAS_RCAN0GAFLM6      RSCAN0GAFLM6
#define RENESAS_RCAN0GAFLM7      RSCAN0GAFLM7
#define RENESAS_RCAN0GAFLM8      RSCAN0GAFLM8
#define RENESAS_RCAN0GAFLM9      RSCAN0GAFLM9
#define RENESAS_RCAN0GAFLM10     RSCAN0GAFLM10
#define RENESAS_RCAN0GAFLM11     RSCAN0GAFLM11
#define RENESAS_RCAN0GAFLM12     RSCAN0GAFLM12
#define RENESAS_RCAN0GAFLM13     RSCAN0GAFLM13
#define RENESAS_RCAN0GAFLM14     RSCAN0GAFLM14
#define RENESAS_RCAN0GAFLM15     RSCAN0GAFLM15

#define RENESAS_RCAN0GAFLP00      RSCAN0GAFLP00
#define RENESAS_RCAN0GAFLP01      RSCAN0GAFLP01
#define RENESAS_RCAN0GAFLP02      RSCAN0GAFLP02
#define RENESAS_RCAN0GAFLP03      RSCAN0GAFLP03
#define RENESAS_RCAN0GAFLP04      RSCAN0GAFLP04
#define RENESAS_RCAN0GAFLP05      RSCAN0GAFLP05
#define RENESAS_RCAN0GAFLP06      RSCAN0GAFLP06
#define RENESAS_RCAN0GAFLP07      RSCAN0GAFLP07
#define RENESAS_RCAN0GAFLP08      RSCAN0GAFLP08
#define RENESAS_RCAN0GAFLP09      RSCAN0GAFLP09
#define RENESAS_RCAN0GAFLP010     RSCAN0GAFLP010
#define RENESAS_RCAN0GAFLP011     RSCAN0GAFLP011
#define RENESAS_RCAN0GAFLP012     RSCAN0GAFLP012
#define RENESAS_RCAN0GAFLP013     RSCAN0GAFLP013
#define RENESAS_RCAN0GAFLP014     RSCAN0GAFLP014
#define RENESAS_RCAN0GAFLP015     RSCAN0GAFLP015

#define RENESAS_RCAN0GAFLP10      RSCAN0GAFLP10
#define RENESAS_RCAN0GAFLP11      RSCAN0GAFLP11
#define RENESAS_RCAN0GAFLP12      RSCAN0GAFLP12
#define RENESAS_RCAN0GAFLP13      RSCAN0GAFLP13
#define RENESAS_RCAN0GAFLP14      RSCAN0GAFLP14
#define RENESAS_RCAN0GAFLP15      RSCAN0GAFLP15
#define RENESAS_RCAN0GAFLP16      RSCAN0GAFLP16
#define RENESAS_RCAN0GAFLP17      RSCAN0GAFLP17
#define RENESAS_RCAN0GAFLP18      RSCAN0GAFLP18
#define RENESAS_RCAN0GAFLP19      RSCAN0GAFLP19
#define RENESAS_RCAN0GAFLP110     RSCAN0GAFLP110
#define RENESAS_RCAN0GAFLP111     RSCAN0GAFLP111
#define RENESAS_RCAN0GAFLP112     RSCAN0GAFLP112
#define RENESAS_RCAN0GAFLP113     RSCAN0GAFLP113
#define RENESAS_RCAN0GAFLP114     RSCAN0GAFLP114
#define RENESAS_RCAN0GAFLP115     RSCAN0GAFLP115

#define RENESAS_ICRCAN00ERR        INTC2EIC183
#define RENESAS_ICRCAN01ERR        INTC2EIC186
#define RENESAS_ICRCAN02ERR        EIC191


#define RENESAS_ICRCANGRECC       INTC2EIC189

/* Global Error interrupt register */
#define RENESAS_ICRCANGERR_IMR     189

/* Global Receive interrupt register */
#define RENESAS_ICRCANGRECC_IMR    190

/* Macros for interrupt mask registers added */
#define RENESAS_ICRCAN00ERR_IMR 183
#define RENESAS_ICRCAN01ERR_IMR 186
#define RENESAS_ICRCAN02ERR_IMR 191

#define RENESAS_ICRCAN00REC_IMR 184
#define RENESAS_ICRCAN01REC_IMR 187
#define RENESAS_ICRCAN02REC_IMR 192

#define RENESAS_ICRCAN00TRX_IMR 185
#define RENESAS_ICRCAN01TRX_IMR 188
#define RENESAS_ICRCAN02TRX_IMR 193

#define RENESAS_ICRCAN00WUP_IMR 128
#define RENESAS_ICRCAN01WUP_IMR 129
#define RENESAS_ICRCAN02WUP_IMR 296


#define RENESAS_RSCAN00_WAKEUP    INTC2EIC128
#define RENESAS_RSCAN01_WAKEUP    INTC2EIC129
#define RENESAS_RSCAN02_WAKEUP    INTC2EIC296


#define IMRCAN0ERR 183
#define IMRCAN1ERR 186

#define IMRCAN0REC 184
#define IMRCAN1REC 187

#define IMRCAN0TRX 185
#define IMRCAN1TRX 188

#define IMRCAN0WUP 29
#define IMRCAN1WUP 30

#define pIMRCANGRECC 189

#define RENESAS_IMRCANGRECC    189

#define RENESAS_RSCAN0GTSTCFG     RSCAN0GTSTCFG
#define RENESAS_RSCAN0GLOCKK      RSCAN0GLOCKK
#define RENESAS_RSCAN0GTSTCTR     RSCAN0GTSTCTR
#define RENESAS_RSCAN0RPGACC0     RSCAN0RPGACC0

#define RENESAS_RCAN0C0ERFL       RSCAN0C0ERFL
#define RENESAS_RCAN0C1ERFL       RSCAN0C1ERFL
/* Macro's for Digital filter */
#define   RENESAS_RSCAN00_DNFAEN   DNFA2EN
#define   RENESAS_RSCAN01_DNFAEN   DNFA2EN
#define   RENESAS_RSCAN02_DNFAEN   DNFA2EN
#define   RENESAS_RSCAN00_DNFAENMASK   0x0001
#define   RENESAS_RSCAN01_DNFAENMASK   0x0002
#define   RENESAS_RSCAN02_DNFAENMASK   0x0004
#define   RENESAS_RSCAN_DNFAENMASK     SUPPORTED

/*******************************************************************************
**                        Macros for CAN QUEUE Implementation                 **
*******************************************************************************/
#define RENESAS_RCAN0TXQCC0     RSCAN0TXQCC0
#define RENESAS_RCAN0TXQCC1     RSCAN0TXQCC1
#define RENESAS_RCAN0TXQCC2     RSCAN0TXQCC2
#define RENESAS_RCAN0TXQCC3     RSCAN0TXQCC3
#define RENESAS_RCAN0TXQCC4     RSCAN0TXQCC4
#define RENESAS_RCAN0TXQCC5     RSCAN0TXQCC5

#define RENESAS_RCAN0TXQSTS0    RSCAN0TXQSTS0
#define RENESAS_RCAN0TXQSTS1    RSCAN0TXQSTS1
#define RENESAS_RCAN0TXQSTS2    RSCAN0TXQSTS2
#define RENESAS_RCAN0TXQSTS3    RSCAN0TXQSTS3
#define RENESAS_RCAN0TXQSTS4    RSCAN0TXQSTS4
#define RENESAS_RCAN0TXQSTS5    RSCAN0TXQSTS5

#define RENESAS_RCAN0TXQPCTR0   RSCAN0TXQPCTR0
#define RENESAS_RCAN0TXQPCTR1   RSCAN0TXQPCTR1
#define RENESAS_RCAN0TXQPCTR2   RSCAN0TXQPCTR2
#define RENESAS_RCAN0TXQPCTR3   RSCAN0TXQPCTR3
#define RENESAS_RCAN0TXQPCTR4   RSCAN0TXQPCTR4
#define RENESAS_RCAN0TXQPCTR5   RSCAN0TXQPCTR5

/* EXTERNAL INTERRUPT EDGE DETECTION REGISTERS */
#define RENESAS_RSCAN00_FCLA        FCLA1CTL5
#define RENESAS_RSCAN01_FCLA        FCLA1CTL6
#define RENESAS_RSCAN02_FCLA        FCLA2CTL2

#define RENESAS_RSCAN03_FCLA        FCLA0CTL3
#define RENESAS_RSCAN04_FCLA        FCLA0CTL4
#define RENESAS_RSCAN05_FCLA        FCLA0CTL5
#define RENESAS_RSCAN06_FCLA        FCLA0CTL6
#define RENESAS_FCLA0CTL0_ADC0      FCLA0CTL0_ADC0
#define RENESAS_FCLA0CTL0_ADC1      FCLA0CTL0_ADC1
#define RENESAS_FCLA0CTL1_ADC0      FCLA0CTL1_ADC0
#define RENESAS_FCLA0CTL1_ADC1      FCLA0CTL1_ADC1
#define RENESAS_FCLA0CTL2_ADC0      FCLA0CTL2_ADC0
#define RENESAS_FCLA0CTL2_ADC1      FCLA0CTL2_ADC1

#define RENESAS_DNFAADCTL0CTL       DNFAADCTL0CTL
#define RENESAS_DNFAADCTL0EN        DNFAADCTL0EN
#define RENESAS_DNFAADCTL0ENL       DNFAADCTL0ENL
#define RENESAS_DNFAADCTL1CTL       DNFAADCTL1CTL
#define RENESAS_DNFAADCTL1EN        DNFAADCTL1EN
#define RENESAS_DNFAADCTL1ENL       DNFAADCTL1ENL
#define RENESAS_DNFATAUD0ICTL       DNFATAUD0ICTL
#define RENESAS_DNFATAUD0IEN        DNFATAUD0IEN
#define RENESAS_DNFATAUD0IENH       DNFATAUD0IENH
#define RENESAS_DNFATAUD0IENL       DNFATAUD0IENL
#define RENESAS_DNFATAUB0ICTL       DNFATAUB0ICTL
#define RENESAS_DNFATAUB0IEN        DNFATAUB0IEN
#define RENESAS_DNFATAUB0IENH       DNFATAUB0IENH
#define RENESAS_DNFATAUB0IENL       DNFATAUB0IENL
#define RENESAS_DNFATAUB1ICTL       DNFATAUB1ICTL
#define RENESAS_DNFATAUB1IEN        DNFATAUB1IEN
#define RENESAS_DNFATAUB1IENH       DNFATAUB1IENH
#define RENESAS_DNFATAUB1IENL       DNFATAUB1IENL
#define RENESAS_DNFAENCA0ICTL       DNFAENCA0ICTL
#define RENESAS_DNFAENCA0IEN        DNFAENCA0IEN
#define RENESAS_DNFAENCA0IENL       DNFAENCA0IENL
/*******************************************************************************
**                        Macros for GPT Driver                               **
*******************************************************************************/



/*******************************************************************************
**                 Macros for FLS Software Component                          **
*******************************************************************************/
#define RENESAS_FLMDCNT         FLMDCNT
#define RENESAS_FLMDPCMD        FLMDPCMD
#define RENESAS_FHVE3           FLASHFHVE3
#define RENESAS_FHVE15          FLASHFHVE15
#define RENESAS_SELFID0         FLASHSELFID0
#define RENESAS_SELFID1         FLASHSELFID1
#define RENESAS_SELFID2         FLASHSELFID2
#define RENESAS_SELFID3         FLASHSELFID3
#define RENESAS_FACI            FACIFPMON
#define RENESAS_ECC             ECCEEPDFECCCTL
#define RENESAS_FRTEINT         FACIFRTEINT
#define RENESAS_ICFLENDNM_ADDR  INTC2EIC379
#define RENESAS_FCUFAREA        FACIFCUFAREA
/* Interrupt control registers for FL (sequencer) */

#define RENESAS_ICFLENDNM_IMR       379

/* MCU reference*/
#define RENESAS_FLS_MCUREF_PARAM   McuCpuMainSysClk

#define RENESAS_FLS_DEVICE      P1x

/*******************************************************************************
**                 Macros for FLSTST Software Component                      **
*******************************************************************************/
#define RENESAS_DCRA0CIN         DCRA0CIN
#define RENESAS_DCRA1CIN         DCRA1CIN
#define RENESAS_DCRA2CIN         DCRA2CIN
#define RENESAS_DCRA3CIN         DCRA3CIN

#define RENESAS_DCRA0CTL         DCRA0CTL
#define RENESAS_DCRA1CTL         DCRA1CTL
#define RENESAS_DCRA2CTL         DCRA2CTL
#define RENESAS_DCRA3CTL         DCRA3CTL

#define RENESAS_DCRA0COUT        DCRA0COUT
#define RENESAS_DCRA1COUT        DCRA1COUT
#define RENESAS_DCRA2COUT        DCRA2COUT
#define RENESAS_DCRA3COUT        DCRA3COUT

#define RENESAS_CF1STEADR0_PE1    ECCFLICF1STEADR0_PE1
#define RENESAS_CFECCCTL_PE1L     ECCFLICFECCCTL_PE1L
#define RENESAS_CFSTCLR_PE1LL     ECCFLICFSTCLR_PE1LL
#define RENESAS_CFERRINT_PE1LL    ECCFLICFERRINT_PE1LL
#define RENESAS_CF1STERSTR_PE1LL  ECCFLICF1STERSTR_PE1LL
#define RENESAS_CFAPCTLL          ECCFLICFAPCTLL

#define RENESAS_FLSTST_DEVICE     P1x
/*******************************************************************************
**                 Macros for RAMTST Software Component                      **
*******************************************************************************/
#define RENESAS_LRECC_CNTL        ECCCPU1LRECCCTL_PE1
#define RENESAS_LRERRINT_CNTL     ECCCPU1LRERRINT_PE1


/*******************************************************************************

/*******************************************************************************
**                     Macros for Flexray Drivers                             **
*******************************************************************************/
#define RENESAS_FLXA0FROC        FLXA0FROC
#define RENESAS_FLXA0FROS        FLXA0FROS
#define RENESAS_FLXA0FRLCK        FLXA0FRLCK
#define RENESAS_FLXA0FREIR        FLXA0FREIR
#define RENESAS_FLXA0FRSIR        FLXA0FRSIR
#define RENESAS_FLXA0FREILS        FLXA0FREILS
#define RENESAS_FLXA0FRSILS        FLXA0FRSILS
#define RENESAS_FLXA0FREIES        FLXA0FREIES
#define RENESAS_FLXA0FREIER        FLXA0FREIER
#define RENESAS_FLXA0FRSIES        FLXA0FRSIES
#define RENESAS_FLXA0FRSIER        FLXA0FRSIER
#define RENESAS_FLXA0FRILE        FLXA0FRILE
#define RENESAS_FLXA0FRT0C        FLXA0FRT0C
#define RENESAS_FLXA0FRT1C        FLXA0FRT1C
#define RENESAS_FLXA0FRSTPW1        FLXA0FRSTPW1
#define RENESAS_FLXA0FRSTPW2        FLXA0FRSTPW2
#define RENESAS_FLXA0FRSUCC1        FLXA0FRSUCC1
#define RENESAS_FLXA0FRSUCC2        FLXA0FRSUCC2
#define RENESAS_FLXA0FRSUCC3        FLXA0FRSUCC3
#define RENESAS_FLXA0FRNEMC        FLXA0FRNEMC
#define RENESAS_FLXA0FRPRTC1        FLXA0FRPRTC1
#define RENESAS_FLXA0FRPRTC2        FLXA0FRPRTC2
#define RENESAS_FLXA0FRMHDC        FLXA0FRMHDC
#define RENESAS_FLXA0FRGTUC1        FLXA0FRGTUC1
#define RENESAS_FLXA0FRGTUC2        FLXA0FRGTUC2
#define RENESAS_FLXA0FRGTUC3        FLXA0FRGTUC3
#define RENESAS_FLXA0FRGTUC4        FLXA0FRGTUC4
#define RENESAS_FLXA0FRGTUC5        FLXA0FRGTUC5
#define RENESAS_FLXA0FRGTUC6        FLXA0FRGTUC6
#define RENESAS_FLXA0FRGTUC7        FLXA0FRGTUC7
#define RENESAS_FLXA0FRGTUC8        FLXA0FRGTUC8
#define RENESAS_FLXA0FRGTUC9        FLXA0FRGTUC9
#define RENESAS_FLXA0FRGTUC10        FLXA0FRGTUC10
#define RENESAS_FLXA0FRGTUC11        FLXA0FRGTUC11
#define RENESAS_FLXA0FRCCSV        FLXA0FRCCSV
#define RENESAS_FLXA0FRCCEV        FLXA0FRCCEV
#define RENESAS_FLXA0FRSCV        FLXA0FRSCV
#define RENESAS_FLXA0FRMTCCV        FLXA0FRMTCCV
#define RENESAS_FLXA0FRRCV        FLXA0FRRCV
#define RENESAS_FLXA0FROCV        FLXA0FROCV
#define RENESAS_FLXA0FRSFS        FLXA0FRSFS
#define RENESAS_FLXA0FRSWNIT        FLXA0FRSWNIT
#define RENESAS_FLXA0FRACS        FLXA0FRACS
#define RENESAS_FLXA0FRESID0        FLXA0FRESID0
#define RENESAS_FLXA0FRESID1        FLXA0FRESID1
#define RENESAS_FLXA0FRESID2        FLXA0FRESID2
#define RENESAS_FLXA0FRESID3        FLXA0FRESID3
#define RENESAS_FLXA0FRESID4        FLXA0FRESID4
#define RENESAS_FLXA0FRESID5        FLXA0FRESID5
#define RENESAS_FLXA0FRESID6        FLXA0FRESID6
#define RENESAS_FLXA0FRESID7        FLXA0FRESID7
#define RENESAS_FLXA0FRESID8        FLXA0FRESID8
#define RENESAS_FLXA0FRESID9        FLXA0FRESID9
#define RENESAS_FLXA0FRESID10        FLXA0FRESID10
#define RENESAS_FLXA0FRESID11        FLXA0FRESID11
#define RENESAS_FLXA0FRESID12        FLXA0FRESID12
#define RENESAS_FLXA0FRESID13        FLXA0FRESID13
#define RENESAS_FLXA0FRESID14        FLXA0FRESID14
#define RENESAS_FLXA0FRESID15        FLXA0FRESID15
#define RENESAS_FLXA0FROSID0        FLXA0FROSID0
#define RENESAS_FLXA0FROSID1        FLXA0FROSID1
#define RENESAS_FLXA0FROSID2        FLXA0FROSID2
#define RENESAS_FLXA0FROSID3        FLXA0FROSID3
#define RENESAS_FLXA0FROSID4        FLXA0FROSID4
#define RENESAS_FLXA0FROSID5        FLXA0FROSID5
#define RENESAS_FLXA0FROSID6        FLXA0FROSID6
#define RENESAS_FLXA0FROSID7        FLXA0FROSID7
#define RENESAS_FLXA0FROSID8        FLXA0FROSID8
#define RENESAS_FLXA0FROSID9        FLXA0FROSID9
#define RENESAS_FLXA0FROSID10        FLXA0FROSID10
#define RENESAS_FLXA0FROSID11        FLXA0FROSID11
#define RENESAS_FLXA0FROSID12        FLXA0FROSID12
#define RENESAS_FLXA0FROSID13        FLXA0FROSID13
#define RENESAS_FLXA0FROSID14        FLXA0FROSID14
#define RENESAS_FLXA0FROSID15        FLXA0FROSID15
#define RENESAS_FLXA0FRNMV1        FLXA0FRNMV1
#define RENESAS_FLXA0FRNMV2        FLXA0FRNMV2
#define RENESAS_FLXA0FRNMV3        FLXA0FRNMV3
#define RENESAS_FLXA0FRMRC        FLXA0FRMRC
#define RENESAS_FLXA0FRFRF        FLXA0FRFRF
#define RENESAS_FLXA0FRFRFM        FLXA0FRFRFM
#define RENESAS_FLXA0FRFCL        FLXA0FRFCL
#define RENESAS_FLXA0FRMHDS        FLXA0FRMHDS
#define RENESAS_FLXA0FRLDTS        FLXA0FRLDTS
#define RENESAS_FLXA0FRFSR        FLXA0FRFSR
#define RENESAS_FLXA0FRMHDF        FLXA0FRMHDF
#define RENESAS_FLXA0FRTXRQ1        FLXA0FRTXRQ1
#define RENESAS_FLXA0FRTXRQ2        FLXA0FRTXRQ2
#define RENESAS_FLXA0FRTXRQ3        FLXA0FRTXRQ3
#define RENESAS_FLXA0FRTXRQ4        FLXA0FRTXRQ4
#define RENESAS_FLXA0FRNDAT1        FLXA0FRNDAT1
#define RENESAS_FLXA0FRNDAT2        FLXA0FRNDAT2
#define RENESAS_FLXA0FRNDAT3        FLXA0FRNDAT3
#define RENESAS_FLXA0FRNDAT4        FLXA0FRNDAT4
#define RENESAS_FLXA0FRMBSC1        FLXA0FRMBSC1
#define RENESAS_FLXA0FRMBSC2        FLXA0FRMBSC2
#define RENESAS_FLXA0FRMBSC3        FLXA0FRMBSC3
#define RENESAS_FLXA0FRMBSC4        FLXA0FRMBSC4
#define RENESAS_FLXA0FRWRDS1        FLXA0FRWRDS1
#define RENESAS_FLXA0FRWRDS2        FLXA0FRWRDS2
#define RENESAS_FLXA0FRWRDS3        FLXA0FRWRDS3
#define RENESAS_FLXA0FRWRDS4        FLXA0FRWRDS4
#define RENESAS_FLXA0FRWRDS5        FLXA0FRWRDS5
#define RENESAS_FLXA0FRWRDS6        FLXA0FRWRDS6
#define RENESAS_FLXA0FRWRDS7        FLXA0FRWRDS7
#define RENESAS_FLXA0FRWRDS8        FLXA0FRWRDS8
#define RENESAS_FLXA0FRWRDS9        FLXA0FRWRDS9
#define RENESAS_FLXA0FRWRDS10        FLXA0FRWRDS10
#define RENESAS_FLXA0FRWRDS11        FLXA0FRWRDS11
#define RENESAS_FLXA0FRWRDS12        FLXA0FRWRDS12
#define RENESAS_FLXA0FRWRDS13        FLXA0FRWRDS13
#define RENESAS_FLXA0FRWRDS14        FLXA0FRWRDS14
#define RENESAS_FLXA0FRWRDS15        FLXA0FRWRDS15
#define RENESAS_FLXA0FRWRDS16        FLXA0FRWRDS16
#define RENESAS_FLXA0FRWRDS17        FLXA0FRWRDS17
#define RENESAS_FLXA0FRWRDS18        FLXA0FRWRDS18
#define RENESAS_FLXA0FRWRDS19        FLXA0FRWRDS19
#define RENESAS_FLXA0FRWRDS20        FLXA0FRWRDS20
#define RENESAS_FLXA0FRWRDS21        FLXA0FRWRDS21
#define RENESAS_FLXA0FRWRDS22        FLXA0FRWRDS22
#define RENESAS_FLXA0FRWRDS23        FLXA0FRWRDS23
#define RENESAS_FLXA0FRWRDS24        FLXA0FRWRDS24
#define RENESAS_FLXA0FRWRDS25        FLXA0FRWRDS25
#define RENESAS_FLXA0FRWRDS26        FLXA0FRWRDS26
#define RENESAS_FLXA0FRWRDS27        FLXA0FRWRDS27
#define RENESAS_FLXA0FRWRDS28        FLXA0FRWRDS28
#define RENESAS_FLXA0FRWRDS29        FLXA0FRWRDS29
#define RENESAS_FLXA0FRWRDS30        FLXA0FRWRDS30
#define RENESAS_FLXA0FRWRDS31        FLXA0FRWRDS31
#define RENESAS_FLXA0FRWRDS32        FLXA0FRWRDS32
#define RENESAS_FLXA0FRWRDS33        FLXA0FRWRDS33
#define RENESAS_FLXA0FRWRDS34        FLXA0FRWRDS34
#define RENESAS_FLXA0FRWRDS35        FLXA0FRWRDS35
#define RENESAS_FLXA0FRWRDS36        FLXA0FRWRDS36
#define RENESAS_FLXA0FRWRDS37        FLXA0FRWRDS37
#define RENESAS_FLXA0FRWRDS38        FLXA0FRWRDS38
#define RENESAS_FLXA0FRWRDS39        FLXA0FRWRDS39
#define RENESAS_FLXA0FRWRDS40        FLXA0FRWRDS40
#define RENESAS_FLXA0FRWRDS41        FLXA0FRWRDS41
#define RENESAS_FLXA0FRWRDS42        FLXA0FRWRDS42
#define RENESAS_FLXA0FRWRDS43        FLXA0FRWRDS43
#define RENESAS_FLXA0FRWRDS44        FLXA0FRWRDS44
#define RENESAS_FLXA0FRWRDS45        FLXA0FRWRDS45
#define RENESAS_FLXA0FRWRDS46        FLXA0FRWRDS46
#define RENESAS_FLXA0FRWRDS47        FLXA0FRWRDS47
#define RENESAS_FLXA0FRWRDS48        FLXA0FRWRDS48
#define RENESAS_FLXA0FRWRDS49        FLXA0FRWRDS49
#define RENESAS_FLXA0FRWRDS50        FLXA0FRWRDS50
#define RENESAS_FLXA0FRWRDS51        FLXA0FRWRDS51
#define RENESAS_FLXA0FRWRDS52        FLXA0FRWRDS52
#define RENESAS_FLXA0FRWRDS53        FLXA0FRWRDS53
#define RENESAS_FLXA0FRWRDS54        FLXA0FRWRDS54
#define RENESAS_FLXA0FRWRDS55        FLXA0FRWRDS55
#define RENESAS_FLXA0FRWRDS56        FLXA0FRWRDS56
#define RENESAS_FLXA0FRWRDS57        FLXA0FRWRDS57
#define RENESAS_FLXA0FRWRDS58        FLXA0FRWRDS58
#define RENESAS_FLXA0FRWRDS59        FLXA0FRWRDS59
#define RENESAS_FLXA0FRWRDS60        FLXA0FRWRDS60
#define RENESAS_FLXA0FRWRDS61        FLXA0FRWRDS61
#define RENESAS_FLXA0FRWRDS62        FLXA0FRWRDS62
#define RENESAS_FLXA0FRWRDS63        FLXA0FRWRDS63
#define RENESAS_FLXA0FRWRDS64        FLXA0FRWRDS64
#define RENESAS_FLXA0FRWRHS0        FLXA0FRWRHS0
#define RENESAS_FLXA0FRWRHS1        FLXA0FRWRHS1
#define RENESAS_FLXA0FRWRHS2        FLXA0FRWRHS2
#define RENESAS_FLXA0FRIBCM        FLXA0FRIBCM
#define RENESAS_FLXA0FRIBCR        FLXA0FRIBCR
#define RENESAS_FLXA0FRRDDS1        FLXA0FRRDDS1
#define RENESAS_FLXA0FRRDDS2        FLXA0FRRDDS2
#define RENESAS_FLXA0FRRDDS3        FLXA0FRRDDS3
#define RENESAS_FLXA0FRRDDS4        FLXA0FRRDDS4
#define RENESAS_FLXA0FRRDDS5        FLXA0FRRDDS5
#define RENESAS_FLXA0FRRDDS6        FLXA0FRRDDS6
#define RENESAS_FLXA0FRRDDS7        FLXA0FRRDDS7
#define RENESAS_FLXA0FRRDDS8        FLXA0FRRDDS8
#define RENESAS_FLXA0FRRDDS9        FLXA0FRRDDS9
#define RENESAS_FLXA0FRRDDS10        FLXA0FRRDDS10
#define RENESAS_FLXA0FRRDDS11        FLXA0FRRDDS11
#define RENESAS_FLXA0FRRDDS12        FLXA0FRRDDS12
#define RENESAS_FLXA0FRRDDS13        FLXA0FRRDDS13
#define RENESAS_FLXA0FRRDDS14        FLXA0FRRDDS14
#define RENESAS_FLXA0FRRDDS15        FLXA0FRRDDS15
#define RENESAS_FLXA0FRRDDS16        FLXA0FRRDDS16
#define RENESAS_FLXA0FRRDDS17        FLXA0FRRDDS17
#define RENESAS_FLXA0FRRDDS18        FLXA0FRRDDS18
#define RENESAS_FLXA0FRRDDS19        FLXA0FRRDDS19
#define RENESAS_FLXA0FRRDDS20        FLXA0FRRDDS20
#define RENESAS_FLXA0FRRDDS21        FLXA0FRRDDS21
#define RENESAS_FLXA0FRRDDS22        FLXA0FRRDDS22
#define RENESAS_FLXA0FRRDDS23        FLXA0FRRDDS23
#define RENESAS_FLXA0FRRDDS24        FLXA0FRRDDS24
#define RENESAS_FLXA0FRRDDS25        FLXA0FRRDDS25
#define RENESAS_FLXA0FRRDDS26        FLXA0FRRDDS26
#define RENESAS_FLXA0FRRDDS27        FLXA0FRRDDS27
#define RENESAS_FLXA0FRRDDS28        FLXA0FRRDDS28
#define RENESAS_FLXA0FRRDDS29        FLXA0FRRDDS29
#define RENESAS_FLXA0FRRDDS30        FLXA0FRRDDS30
#define RENESAS_FLXA0FRRDDS31        FLXA0FRRDDS31
#define RENESAS_FLXA0FRRDDS32        FLXA0FRRDDS32
#define RENESAS_FLXA0FRRDDS33        FLXA0FRRDDS33
#define RENESAS_FLXA0FRRDDS34        FLXA0FRRDDS34
#define RENESAS_FLXA0FRRDDS35        FLXA0FRRDDS35
#define RENESAS_FLXA0FRRDDS36        FLXA0FRRDDS36
#define RENESAS_FLXA0FRRDDS37        FLXA0FRRDDS37
#define RENESAS_FLXA0FRRDDS38        FLXA0FRRDDS38
#define RENESAS_FLXA0FRRDDS39        FLXA0FRRDDS39
#define RENESAS_FLXA0FRRDDS40        FLXA0FRRDDS40
#define RENESAS_FLXA0FRRDDS41        FLXA0FRRDDS41
#define RENESAS_FLXA0FRRDDS42        FLXA0FRRDDS42
#define RENESAS_FLXA0FRRDDS43        FLXA0FRRDDS43
#define RENESAS_FLXA0FRRDDS44        FLXA0FRRDDS44
#define RENESAS_FLXA0FRRDDS45        FLXA0FRRDDS45
#define RENESAS_FLXA0FRRDDS46        FLXA0FRRDDS46
#define RENESAS_FLXA0FRRDDS47        FLXA0FRRDDS47
#define RENESAS_FLXA0FRRDDS48        FLXA0FRRDDS48
#define RENESAS_FLXA0FRRDDS49        FLXA0FRRDDS49
#define RENESAS_FLXA0FRRDDS50        FLXA0FRRDDS50
#define RENESAS_FLXA0FRRDDS51        FLXA0FRRDDS51
#define RENESAS_FLXA0FRRDDS52        FLXA0FRRDDS52
#define RENESAS_FLXA0FRRDDS53        FLXA0FRRDDS53
#define RENESAS_FLXA0FRRDDS54        FLXA0FRRDDS54
#define RENESAS_FLXA0FRRDDS55        FLXA0FRRDDS55
#define RENESAS_FLXA0FRRDDS56        FLXA0FRRDDS56
#define RENESAS_FLXA0FRRDDS57        FLXA0FRRDDS57
#define RENESAS_FLXA0FRRDDS58        FLXA0FRRDDS58
#define RENESAS_FLXA0FRRDDS59        FLXA0FRRDDS59
#define RENESAS_FLXA0FRRDDS60        FLXA0FRRDDS60
#define RENESAS_FLXA0FRRDDS61        FLXA0FRRDDS61
#define RENESAS_FLXA0FRRDDS62        FLXA0FRRDDS62
#define RENESAS_FLXA0FRRDDS63        FLXA0FRRDDS63
#define RENESAS_FLXA0FRRDDS64        FLXA0FRRDDS64
#define RENESAS_FLXA0FRRDHS0        FLXA0FRRDHS0
#define RENESAS_FLXA0FRRDHS1        FLXA0FRRDHS1
#define RENESAS_FLXA0FRRDHS2        FLXA0FRRDHS2
#define RENESAS_FLXA0FRMBS        FLXA0FRMBS
#define RENESAS_FLXA0FROBCM        FLXA0FROBCM
#define RENESAS_FLXA0FROBCR        FLXA0FROBCR

/*******************************************************************************
**                 Macros for BACKUP RAM                                      **
*******************************************************************************/
#define RENESAS_BRAMDAT0    BRAMDAT0
#define RENESAS_BRAMDAT1    BRAMDAT1
#define RENESAS_BRAMDAT2    BRAMDAT2
#define RENESAS_BRAMDAT3    BRAMDAT3

/*******************************************************************************

/*******************************************************************************
**                      Function Prototypes                                   **
*******************************************************************************/

/*******************************************************************************
**                          End Of File                                       **
*******************************************************************************/
