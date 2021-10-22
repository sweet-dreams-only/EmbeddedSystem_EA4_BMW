/**********************************************************************************************************************
 *  COPYRIGHT
 *  -------------------------------------------------------------------------------------------------------------------
 *  \verbatim
 *  Copyright (c) 2017 by Vctr Informatik GmbH.                                              All rights reserved.
 *
 *                This software is copyright protected and proprietary to Vctr Informatik GmbH.
 *                Vctr Informatik GmbH grants to you only those rights as set out in the license conditions.
 *                All other rights remain with Vctr Informatik GmbH.
 *  \endverbatim
 *
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/**        \file  Fr_ERay.h
 *        \brief  FlexRay Driver ERAY header file
 *
 *      \details  Public header containing typedefs for use by FlexRay driver according to:
 *                AUTOSAR FlexRay Driver, AUTOSAR Release 4.0
 *
 *********************************************************************************************************************/

 /*********************************************************************************************************************
 *  REVISION HISTORY
 *  -------------------------------------------------------------------------------------------------------------------
 *  Refer to the module's header file.
 *********************************************************************************************************************/

#if (!defined FR_ERAY_H)
# define FR_ERAY_H

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
# include "Platform_Types.h"

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/

/* PRQA S 0857 EOF */ /* MD_MSR_1.1_857 */

/*!
 * \defgroup HSI ERAY Registers
 * \brief 
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 * \{
 */

/** 
 * \defgroup CIF Customer Interface Registers (CIF)
 * \brief The address space from 0x0000 to 0x000F is reserved for customer-specific registers. These registers, if 
 *        implemented, are located in the Customer CPU Interface block. A description can be found in the specific 
 *        Customer CPU Interface specification document.
 * \{
 */
# define FR_CIF_0                                                     0x00000000UL
# define FR_CIF_1                                                     0x00000004UL
# define FR_CIF_2                                                     0x00000008UL
# define FR_CIF_3                                                     0x0000000CUL

#  if (defined FR_CPU_RH850) /* COV_FR_EQUIVALENT_HARDWARE */
/************************************** Register FROC ****************************************************************/
#  define FR_FROC                                                     0x00000004UL /*!< Address of FlexRay Operation Control Register */
#  define FR_FROC_T0IE                                                0x00010000UL /*!< Timer 0 Interrupt Enable Bit */
#  define FR_FROC_OEP                                                 0x00000080UL /*!< Operation Enable Protection Bit */
#  define FR_FROC_OE                                                  0x00000001UL /*!< Operation Enable Bit */
/************************************** Register FROS ****************************************************************/
#  define FR_FROS                                                     0x0000000CUL /*!< Address of FlexRay Operation Status Register */
#  define FR_FROS_T0IS                                                0x00010001UL /*!< Timer 0 Interrupt Status Bit */
#  define FR_FROS_OS                                                  0x00000001UL /*!< Operation Status Bit */
#  endif
/*********************************** Register CIF_2 ******************************************************************/
# define FR_CIF_2_CSLK_FIRST_MASK                                     ((uint32) 0x67000000) /*!< First write Control Setting Lock Key */
# define FR_CIF_2_CSLK_SECOND_MASK                                    ((uint32) 0x98000000) /*!< Second write Control Setting Lock Key */

/**\} */

/** 
 * \defgroup LCK Lock Register (LCK) 
 * \brief The Lock Register is write-only. Reading the register will return 0x00000000.
 * \{
 */
# define FR_LCK                                                       0x0000001CUL
/*********************************** Register LCK ********************************************************************/
# define FR_LCK_CLK_MASK                                              ((uint32) 0x000000FF) /*!< Configuration Lock Key [7:0] */
# define FR_LCK_CLK_SHIFT                                             0
# define FR_LCK_CLK_KEY1                                              ((uint32) 0x000000CE) /*!< Configuration Lock Key of first write */
# define FR_LCK_CLK_KEY2                                              ((uint32) 0x00000031) /*!< Configuration Lock Key of second write */
# define FR_LCK_TMK_MASK                                              ((uint32) 0x000000FF) 
# define FR_LCK_TMK_SHIFT                                             8                     
/**\} */

/**
 * \defgroup IR Interrupt Registers
 * \{
 */

/** 
 * \defgroup EIR Error Interrupt Register (EIR)
 * \brief The flags are set when the CC detects one of the listed error conditions. The flags remain set until the Host 
 *        clears them. A flag is cleared by writing a 1 to the corresponding bit position. Writing a 0 has no effect
 *        on the flag. A hard reset will also clear the register.
 * \{
 */
# define FR_EIR                                                       0x00000020UL
/*********************************** Register EIR ********************************************************************/
# define FR_EIR_PEMC                                                  ((uint32) (0x00000001 << 0) )         /*!< POC Error Mode Changed */
# define FR_EIR_CNA                                                   ((uint32) (0x00000001 << 1) )         /*!< Command Not Accepted */
# define FR_EIR_SFBM                                                  ((uint32) (0x00000001 << 2) )         /*!< Sync Frames Below Minimum */
# define FR_EIR_SFO                                                   ((uint32) (0x00000001 << 3) )         /*!< Sync Frame Overflow */
# define FR_EIR_CCF                                                   ((uint32) (0x00000001 << 4) )         /*!< Clock Correction Failure */
# define FR_EIR_CCL                                                   ((uint32) (0x00000001 << 5) )         /*!< CHI Command Locked */
# define FR_EIR_PERR                                                  ((uint32) (0x00000001 << 6) )         /*!< Parity Error */
# define FR_EIR_RFO_EIR                                               ((uint32) (0x00000001 << 7) )         /*!< Receive FIFO Overrun */
# define FR_EIR_EFA                                                   ((uint32) (0x00000001 << 8) )         /*!< Empty FIFO Access */
# define FR_EIR_IIBA                                                  ((uint32) (0x00000001 << 9) )         /*!< Illegal Input Buffer Access */
# define FR_EIR_IOBA                                                  ((uint32) (0x00000001 << 10))         /*!< Illegal Output Buffer Access */
# define FR_EIR_MHF                                                   ((uint32) (0x00000001 << 11))         /*!< Message Handler Constraints Flag */
# define FR_EIR_EDA                                                   ((uint32) ((uint32)0x00000001 << 16)) /*!< Error Detected on Channel A */
# define FR_EIR_LTVA                                                  ((uint32) ((uint32)0x00000001 << 17)) /*!< Latest Transmit Violation Channel A */
# define FR_EIR_TABA                                                  ((uint32) ((uint32)0x00000001 << 18)) /*!< Transmission Across Boundary Channel A */
# define FR_EIR_EDB                                                   ((uint32) ((uint32)0x00000001 << 24)) /*!< Error Detected on Channel B */
# define FR_EIR_LTVB                                                  ((uint32) ((uint32)0x00000001 << 25)) /*!< Latest Transmit Violation Channel B */
# define FR_EIR_TABB                                                  ((uint32) ((uint32)0x00000001 << 26)) /*!< Transmission Across Boundary Channel B */
/**\} */

/** 
 * \defgroup SIR Status Interrupt Register (SIR)
 * \brief The flags are set when the CC detects one of the listed events. The flags remain set until the Host clears 
 *        them. A flag is cleared by writing a 1 to the corresponding bit position. Writing a 0 has no effect on the
 *        flag. A hard reset will also clear the register.
 * \{
 */
# define FR_SIR                                                       0x00000024UL
/*********************************** Register SIR ********************************************************************/
# define FR_SIR_WST                                                   ((uint32) (0x00000001 << 0) )         /*!< Wakeup Status */
# define FR_SIR_CAS                                                   ((uint32) (0x00000001 << 1) )         /*!< Collision Avoidance Symbol */
# define FR_SIR_CYCS                                                  ((uint32) (0x00000001 << 2) )         /*!< Cycle Start Interrupt */
# define FR_SIR_TXI                                                   ((uint32) (0x00000001 << 3) )         /*!< Transmit Interrupt */
# define FR_SIR_RXI                                                   ((uint32) (0x00000001 << 4) )         /*!< Receive Interrupt */
# define FR_SIR_RFNE                                                  ((uint32) (0x00000001 << 5) )         /*!< Receive FIFO Not Empty */
# define FR_SIR_RFCL                                                  ((uint32) (0x00000001 << 6) )         /*!< Receive FIFO Critical Level */
# define FR_SIR_NMVC                                                  ((uint32) (0x00000001 << 7) )         /*!< Network Management Vector Changed */
# define FR_SIR_TI0                                                   ((uint32) (0x00000001 << 8) )         /*!< Timer Interrupt 0 */
# define FR_SIR_TI1                                                   ((uint32) (0x00000001 << 9) )         /*!< Timer Interrupt 1 */
# define FR_SIR_TIBC                                                  ((uint32) (0x00000001 << 10))         /*!< Transfer Input Buffer Completed */
# define FR_SIR_TOBC                                                  ((uint32) (0x00000001 << 11))         /*!< Transfer Output Buffer Completed */
# define FR_SIR_SWE                                                   ((uint32) (0x00000001 << 12))         /*!< Stop Watch Event */
# define FR_SIR_SUCS                                                  ((uint32) (0x00000001 << 13))         /*!< Startup Completed Successfully */
# define FR_SIR_MBSI                                                  ((uint32) (0x00000001 << 14))         /*!< Message Buffer Status Interrupt */
# define FR_SIR_SDS                                                   ((uint32) (0x00000001 << 15))         /*!< Start of Dynamic Segment */
# define FR_SIR_WUPA                                                  ((uint32) ((uint32)0x00000001 << 16)) /*!< Wakeup Pattern Channel A */
# define FR_SIR_MTSA                                                  ((uint32) ((uint32)0x00000001 << 17)) /*!< MTS Received on Channel A */
# define FR_SIR_WUPB                                                  ((uint32) ((uint32)0x00000001 << 24)) /*!< Wakeup Pattern Channel B */
# define FR_SIR_MTSB                                                  ((uint32) ((uint32)0x00000001 << 25)) /*!< MTS Received on Channel B */
/**\} */

/** 
 * \defgroup EILS Error Interrupt Line Select (EILS)
 * \brief The Error Interrupt Line Select register assigns an interrupt generated by a specific error interrupt flag
 *        from register EIR to one of the two module interrupt lines:
 -           1 = Interrupt assigned to interrupt line eray_int1
 -           0 = Interrupt assigned to interrupt line eray_int0
 * \{
 */
# define FR_EILS                                                      0x00000028UL
/*********************************** Register EILS *******************************************************************/
# define FR_EILS_PEMCL                                                ((uint32) (0x00000001 << 0) )         /*!< POC Error Mode Changed Interrupt Line */
# define FR_EILS_CNAL                                                 ((uint32) (0x00000001 << 1) )         /*!< Command Not Accepted Interrupt Line */
# define FR_EILS_SFBML                                                ((uint32) (0x00000001 << 2) )         /*!< Sync Frames Below Minimum Interrupt Line */
# define FR_EILS_SFOL                                                 ((uint32) (0x00000001 << 3) )         /*!< Sync Frame Overflow Interrupt Line */
# define FR_EILS_CCFL                                                 ((uint32) (0x00000001 << 4) )         /*!< Clock Correction Failure Interrupt Line */
# define FR_EILS_CCLL                                                 ((uint32) (0x00000001 << 5) )         /*!< CHI Command Locked Interrupt Line */
# define FR_EILS_PERRL                                                ((uint32) (0x00000001 << 6) )         /*!< Parity Error Interrupt Line */
# define FR_EILS_RFOL                                                 ((uint32) (0x00000001 << 7) )         /*!< Receive FIFO Overrun Interrupt Line */
# define FR_EILS_EFAL                                                 ((uint32) (0x00000001 << 8) )         /*!< Empty FIFO Access Interrupt Line */
# define FR_EILS_IIBAL                                                ((uint32) (0x00000001 << 9) )         /*!< Illegal Input Buffer Access Interrupt Line */
# define FR_EILS_IOBAL                                                ((uint32) (0x00000001 << 10))         /*!< Illegal Output Buffer Access Interrupt Line */
# define FR_EILS_MHFL                                                 ((uint32) (0x00000001 << 11))         /*!< Message Handler Constraints Flag Interrupt Line */
# define FR_EILS_EDAL                                                 ((uint32) ((uint32)0x00000001 << 16)) /*!< Error Detected on Channel A Interrupt Line */
# define FR_EILS_LTVAL                                                ((uint32) ((uint32)0x00000001 << 17)) /*!< Latest Transmit Violation Channel A Interrupt Line */
# define FR_EILS_TABAL                                                ((uint32) ((uint32)0x00000001 << 18)) /*!< Transmission Across Boundary Channel A Interrupt Line */
# define FR_EILS_EDBL                                                 ((uint32) ((uint32)0x00000001 << 24)) /*!< Error Detected on Channel B Interrupt Line */
# define FR_EILS_LTVBL                                                ((uint32) ((uint32)0x00000001 << 25)) /*!< Latest Transmit Violation Channel B Interrupt Line */
# define FR_EILS_TABBL                                                ((uint32) ((uint32)0x00000001 << 26)) /*!< Transmission Across Boundary Channel B Interrupt Line */
/**\} */

/** 
 * \defgroup SILS Status Interrupt Line Select (SILS)
 * \brief The Status Interrupt Line Select register assign an interrupt generated by a specific status interrupt 
 *        flag from register SIR to one of the two module interrupt lines:
 -           1 = Interrupt assigned to interrupt line eray_int1
 -           0 = Interrupt assigned to interrupt line eray_int0
 * \{
 */
# define FR_SILS                                                      0x0000002CUL
/*********************************** Register SILS *******************************************************************/
# define FR_SILS_WSTL                                                 ((uint32) (0x00000001 << 0) )         /*!< Wakeup Status Interrupt Line */
# define FR_SILS_CASL                                                 ((uint32) (0x00000001 << 1) )         /*!< Collision Avoidance Symbol Interrupt Line */
# define FR_SILS_CYCSL                                                ((uint32) (0x00000001 << 2) )         /*!< Cycle Start Interrupt Interrupt Line */
# define FR_SILS_TXIL                                                 ((uint32) (0x00000001 << 3) )         /*!< Transmit Interrupt Interrupt Line */
# define FR_SILS_RXIL                                                 ((uint32) (0x00000001 << 4) )         /*!< Receive Interrupt Interrupt Line */
# define FR_SILS_RFNEL                                                ((uint32) (0x00000001 << 5) )         /*!< Receive FIFO Not Empty Interrupt Line */
# define FR_SILS_RFCCL                                                ((uint32) (0x00000001 << 6) )         /*!< Receive FIFO Critical Level Interrupt Line */
# define FR_SILS_NMVCL                                                ((uint32) (0x00000001 << 7) )         /*!< Network Management Vector Changed Interrupt Line */
# define FR_SILS_TI0L                                                 ((uint32) (0x00000001 << 8) )         /*!< Timer Interrupt 0 Interrupt Line */
# define FR_SILS_TI1L                                                 ((uint32) (0x00000001 << 9) )         /*!< Timer Interrupt 1 Interrupt Line */
# define FR_SILS_TIBCL                                                ((uint32) (0x00000001 << 10))         /*!< Transfer Input Buffer Completed Interrupt Line */
# define FR_SILS_TOBCL                                                ((uint32) (0x00000001 << 11))         /*!< Transfer Output Buffer Completed Interrupt Line */
# define FR_SILS_SWEL                                                 ((uint32) (0x00000001 << 12))         /*!< Stop Watch Event Interrupt Line */
# define FR_SILS_SUCSL                                                ((uint32) (0x00000001 << 13))         /*!< Startup Completed Successfully Interrupt Line */
# define FR_SILS_MBSIL                                                ((uint32) (0x00000001 << 14))         /*!< Message Buffer Status Interrupt Interrupt Line */
# define FR_SILS_SDSL                                                 ((uint32) (0x00000001 << 15))         /*!< Start of Dynamic Segment Interrupt Line */
# define FR_SILS_WUPAL                                                ((uint32) ((uint32)0x00000001 << 16)) /*!< Wakeup Pattern Channel A Interrupt Line */
# define FR_SILS_MTSAL                                                ((uint32) ((uint32)0x00000001 << 17)) /*!< MTS Received on Channel A Interrupt Line */
# define FR_SILS_WUPBL                                                ((uint32) ((uint32)0x00000001 << 24)) /*!< Wakeup Pattern Channel B Interrupt Line */ 
# define FR_SILS_MTSBL                                                ((uint32) ((uint32)0x00000001 << 25)) /*!< MTS Received on Channel B Interrupt Line */
/**\} */

/** 
 * \defgroup EIES Error Interrupt Enable Set / Reset (EIES, EIER)
 * \brief The settings in the Error Interrupt Enable register determine which status changes in the Error Interrupt 
 *        Register will result in an interrupt.
 *        The enable bits are set by writing to address 0x0030 and reset by writing to address 0x0034. Writing a 1 
 *        sets / resets the specific enable bit, writing a 0 has no effect. Reading from both addresses will result 
 *        in the same value.
 -           1 = Interrupt enabled
 -           0 = Interrupt disabled
 * \{
 */
# define FR_EIES                                                      0x00000030UL
# define FR_EIER                                                      0x00000034UL
/*********************************** Register EIES/EIER **************************************************************/
# define FR_EILS_PEMCE                                                ((uint32) (0x00000001 << 0) )         /*!< POC Error Mode Changed Interrupt Enable */
# define FR_EILS_CNAE                                                 ((uint32) (0x00000001 << 1) )         /*!< Command Not Accepted Interrupt Enable */
# define FR_EILS_SFBME                                                ((uint32) (0x00000001 << 2) )         /*!< Sync Frames Below Minimum Interrupt Enable */
# define FR_EILS_SFOE                                                 ((uint32) (0x00000001 << 3) )         /*!< Sync Frame Overflow Interrupt Enable */
# define FR_EILS_CCFE                                                 ((uint32) (0x00000001 << 4) )         /*!< Clock Correction Failure Interrupt Enable */
# define FR_EILS_CCLE                                                 ((uint32) (0x00000001 << 5) )         /*!< CHI Command Locked Interrupt Enable */
# define FR_EILS_PERRE                                                ((uint32) (0x00000001 << 6) )         /*!< Parity Error Interrupt Enable */
# define FR_EILS_RFOE                                                 ((uint32) (0x00000001 << 7) )         /*!< Receive FIFO Overrun Interrupt Enable */
# define FR_EILS_EFAE                                                 ((uint32) (0x00000001 << 8) )         /*!< Empty FIFO Access Interrupt Enable */
# define FR_EILS_IIBAE                                                ((uint32) (0x00000001 << 9) )         /*!< Illegal Input Buffer Access Interrupt Enable */
# define FR_EILS_IOBAE                                                ((uint32) (0x00000001 << 10))         /*!< Illegal Output Buffer Access Interrupt Enable */
# define FR_EILS_MHFE                                                 ((uint32) (0x00000001 << 11))         /*!< Message Handler Constraints Flag Interrupt Enable */
# define FR_EILS_EDAE                                                 ((uint32) ((uint32)0x00000001 << 16)) /*!< Error Detected on Channel A Interrupt Enable */
# define FR_EILS_LTVAE                                                ((uint32) ((uint32)0x00000001 << 17)) /*!< Latest Transmit Violation Channel A Interrupt Enable */
# define FR_EILS_TABAE                                                ((uint32) ((uint32)0x00000001 << 18)) /*!< Transmission Across Boundary Channel A Interrupt Enable */
# define FR_EILS_EDBE                                                 ((uint32) ((uint32)0x00000001 << 24)) /*!< Error Detected on Channel B Interrupt Enable */
# define FR_EILS_LTVBE                                                ((uint32) ((uint32)0x00000001 << 25)) /*!< Latest Transmit Violation Channel B Interrupt Enable */
# define FR_EILS_TABBE                                                ((uint32) ((uint32)0x00000001 << 26)) /*!< Transmission Across Boundary Channel B Interrupt Enable */
/**\} */

/** 
 * \defgroup SIES Status Interrupt Enable Set / Reset (SIES, SIER)
 * \brief The settings in the Status Interrupt Enable register determine which status changes in the Status Interrupt 
 *        Register will result in an interrupt.
 *        The enable bits are set by writing to address 0x0038 and reset by writing to address 0x003C. Writing a 1 
 *        sets / resets the specific enable bit, writing a 0 has no effect. Reading from both addresses will result 
 *        in the same value.
 -           1 = Interrupt enabled
 -           0 = Interrupt disabled
 * \{
 */
# define FR_SIES                                                      0x00000038UL
# define FR_SIER                                                      0x0000003CUL
/*********************************** Register SIES/SIER **************************************************************/
# define FR_SIES_WSTE                                                 ((uint32) (0x00000001 << 0) )         /*!< Wakeup Status Interrupt Enable */
# define FR_SIES_CASE                                                 ((uint32) (0x00000001 << 1) )         /*!< Collision Avoidance Symbol Interrupt Enable */
# define FR_SIES_CYCSE                                                ((uint32) (0x00000001 << 2) )         /*!< Cycle Start Interrupt Interrupt Enable */
# define FR_SIES_TXIE                                                 ((uint32) (0x00000001 << 3) )         /*!< Transmit Interrupt Interrupt Enable */
# define FR_SIES_RXIE                                                 ((uint32) (0x00000001 << 4) )         /*!< Receive Interrupt Interrupt Enable */
# define FR_SIES_RFNEE                                                ((uint32) (0x00000001 << 5) )         /*!< Receive FIFO Not Empty Interrupt Enable */
# define FR_SIES_RFFE                                                 ((uint32) (0x00000001 << 6) )         /*!< Receive FIFO Critical Level Interrupt Enable */
# define FR_SIES_NMVCE                                                ((uint32) (0x00000001 << 7) )         /*!< Network Management Vector Changed Interrupt Enable */
# define FR_SIES_TI0E                                                 ((uint32) (0x00000001 << 8) )         /*!< Timer Interrupt 0 Interrupt Enable */
# define FR_SIES_TI1E                                                 ((uint32) (0x00000001 << 9) )         /*!< Timer Interrupt 1 Interrupt Enable */
# define FR_SIES_TIBCE                                                ((uint32) (0x00000001 << 10))         /*!< Transfer Input Buffer Completed Interrupt Enable */
# define FR_SIES_TOBCE                                                ((uint32) (0x00000001 << 11))         /*!< Transfer Output Buffer Completed Interrupt Enable */
# define FR_SIES_SWEE                                                 ((uint32) (0x00000001 << 12))         /*!< Stop Watch Event Interrupt Enable */
# define FR_SIES_SUCSE                                                ((uint32) (0x00000001 << 13))         /*!< Startup Completed Successfully Interrupt Enable */
# define FR_SIES_MBSIE                                                ((uint32) (0x00000001 << 14))         /*!< Message Buffer Status Interrupt Interrupt Enable */
# define FR_SIES_SDSE                                                 ((uint32) (0x00000001 << 15))         /*!< Start of Dynamic Segment Interrupt Enable */
# define FR_SIES_WUPAE                                                ((uint32) ((uint32)0x00000001 << 16)) /*!< Wakeup Pattern Channel A Interrupt Enable */
# define FR_SIES_MTSAE                                                ((uint32) ((uint32)0x00000001 << 17)) /*!< MTS Received on Channel A Interrupt Enable */
# define FR_SIES_WUPBE                                                ((uint32) ((uint32)0x00000001 << 24)) /*!< Wakeup Pattern Channel B Interrupt Enable */ 
# define FR_SIES_MTSBE                                                ((uint32) ((uint32)0x00000001 << 25)) /*!< MTS Received on Channel B Interrupt Enable */
/**\} */

/** 
 * \defgroup ILE Interrupt Line Enable (ILE)
 * \brief Each of the two interrupt lines to the Host (eray_int0, eray_int1) can be enabled / disabled separately by 
 *        programming bit EINT0 and EINT1.
 -           1 = Interrupt enabled
 -           0 = Interrupt disabled
 * \{
 */
# define FR_ILE                                                       0x00000040UL
/*********************************** Register ILE ********************************************************************/
# define FR_ILE_EINT0_ILE                                             ((uint32) (0x00000001 << 0)) /*!< Enable Interrupt Line 0 eray_int0 */
# define FR_ILE_EINT1_ILE                                             ((uint32) (0x00000001 << 1)) /*!< Enable Interrupt Line 1 eray_int1 */
/**\} */

/** 
 * \defgroup T0C Timer 0 Configuration (T0C)
 * \brief Absolute timer. Specifies in terms of cycle count and macrotick the point in time when the timer 0 interrupt 
 *        occurs. When the timer 0 interrupt is asserted, output signal eray_tint0 is set to 1 for the duration of one 
 *        macrotick and SIR.TI0 is set to 1.
 -        Timer 0 can be activated as long as the POC is either in NORMAL_ACTIVE state or in NORMAL_PASSIVE state. 
 -        Timer 0 is deactivated when leaving NORMAL_ACTIVE state or NORMAL_PASSIVE state except for transitions 
 *        between the two states.
 -        Before reconfiguration of the timer, the timer has to be halted first by writing bit T0RC to 0.
 * \{
 */
# define FR_T0C                                                       0x00000044UL
/*********************************** Register T0C ********************************************************************/
# define FR_T0C_T0RC                                                  ((uint32) (0x00000001 << 0))  /*!< Timer 0 Run Control */
# define FR_T0C_T0MS                                                  ((uint32) (0x00000001 << 1))  /*!< Timer 0 Mode Select */
# define FR_T0C_T0CC_MASK                                             ((uint32) 0x0000007F)         /*!< Timer 0 Cycle Code */
# define FR_T0C_T0CC_SHIFT                                            8                             /*!< Timer 0 Cycle Code position */
# define FR_T0C_T0MO_MASK                                             ((uint32) 0x00003FFF)         /*!< Timer 0 Macrotick Offset */
# define FR_T0C_T0MO_SHIFT                                            16                            /*!< Timer 0 Macrotick Offset position */
/**\} */

/** 
 * \defgroup T1C Timer 1 Configuration (T1C)
 * \brief Relative timer. Specifies in terms of cycle count and macrotick the point in time when the timer 0 interrupt 
 *        occurs. When the timer 0 interrupt is asserted, output signal eray_tint0 is set to 1 for the duration of one 
 *        macrotick and SIR.TI1 is set to 1.
 -        Timer 1 can be activated as long as the POC is either in NORMAL_ACTIVE state or in NORMAL_PASSIVE state. 
 -        Timer 1 is deactivated when leaving NORMAL_ACTIVE state or NORMAL_PASSIVE state except for transitions 
 *        between the two states.
 -        Before reconfiguration of the timer, the timer has to be halted first by writing bit T1RC to 0.
 -        The T1C register is not used by the FlexRay driver.
 * \{
 */
# define FR_T1C                                                       0x00000048UL
/*********************************** Register T1C ********************************************************************/
# define FR_T1C_T1RC                                                  ((uint32) (0x00000001 << 0))  /*!< Timer 1 Run Control */
# define FR_T1C_T1MS                                                  ((uint32) (0x00000001 << 1))  /*!< Timer 1 Mode Select */
# define FR_T1C_T1MO_MASK                                             ((uint32) 0x00003FFF)         /*!< Timer 1 Macrotick Offset */
# define FR_T1C_T1MO_SHIFT                                            16                            /*!< Timer 1 Macrotick Offset position */
/**\} */

/** 
 * \defgroup STPW1 Stop Watch Register 1 (STPW1)
 * \brief The stop watch is activated by a rising or falling edge on pin eray_stpwt, by an interrupt 0,1 event(rising 
 *        edge on pin eray_int0 or eray_int1) or by the Host by writing bit SSWT to 1. With the macrotick counter 
 *        increment following next to the stop watch activation the actual cycle counter and macrotick values are 
 *        captured in register STPW1 while the slot counter values for channel A and B are captured in register STPW2.
 -        The STPW1 register is not used by the FlexRay driver.
 * \{
 */
# define FR_STPW1                                                     0x0000004CUL
/*********************************** Register STPW1 ******************************************************************/
# define FR_STPW1_ESWT                                                ((uint32) (0x00000001 << 0))  /*!< Enable Stop Watch Trigger */
# define FR_STPW1_SWMS                                                ((uint32) (0x00000001 << 1))  /*!< Stop Watch Mode Select */
# define FR_STPW1_EDGE                                                ((uint32) (0x00000001 << 2))  /*!< Stop Watch Trigger Edge Select */
# define FR_STPW1_SSWT                                                ((uint32) (0x00000001 << 3))  /*!< Software Stop Watch Trigger */
# define FR_STPW1_EETP                                                ((uint32) (0x00000001 << 4))  /*!< Enable External Trigger Pin */
# define FR_STPW1_EINT0_STPW1                                         ((uint32) (0x00000001 << 5))  /*!< Enable Interrupt 0 Trigger */
# define FR_STPW1_EINT1_STPW1                                         ((uint32) (0x00000001 << 6))  /*!< Enable Interrupt 1 Trigger */
# define FR_STPW1_SCCV_MASK                                           ((uint32) (0x0000003F)     )  /*!< Stop Watch Captured Cycle Counter Value */
# define FR_STPW1_SCCV_SHIFT                                          8                             /*!< Stop Watch Captured Cycle Counter Value position */
# define FR_STPW1_SMTV0_MASK                                          ((uint32) 0x00003FFF)         /*!< Stop Watch Captured Macrotick Value */
# define FR_STPW1_SMTV0_SHIFT                                         16                            /*!< Stop Watch Captured Macrotick Value position */
/**\} */

/** 
 * \defgroup STPW2 Stop Watch Register 2 (STPW2)
 * \brief The stop watch is activated by a rising or falling edge on pin eray_stpwt, by an interrupt 0,1 event(rising 
 *        edge on pin eray_int0 or eray_int1) or by the Host by writing bit SSWT to 1. With the macrotick counter 
 *        increment following next to the stop watch activation the actual cycle counter and macrotick values are 
 *        captured in register STPW1 while the slot counter values for channel A and B are captured in register STPW2.
 -        The STPW2 register is not used by the FlexRay driver.
 * \{
 */
# define FR_STPW2                                                     0x00000050UL
/*********************************** Register STPW2 ******************************************************************/
/*! STPW2 register bit masks */
# define FR_STPW2_SSCVA_MASK                                          ((uint32) 0x000007FF) /*!< Stop Watch Captured Slot Counter Value Channel A */
# define FR_STPW2_SSCVA_SHIFT                                         0                     /*!< Stop Watch Captured Slot Counter Value Channel A position */
# define FR_STPW2_SSCVB_MASK                                          ((uint32) 0x000007FF) /*!< Stop Watch Captured Slot Counter Value Channel B */
# define FR_STPW2_SSCVB_SHIFT                                         16                    /*!< Stop Watch Captured Slot Counter Value Channel B position */
/**\} */

/**\} */

/**
 * \defgroup CCR CC Control Registers
 * \brief  These registers provided by the CC allow the Host to control the operation of the CC. The FlexRay protocol 
 *         specification requires the Host to write application configuration data in CONFIG state only. 
 -         Please consider that the configuration registers are not locked for writing in DEFAULT_CONFIG state.
 -         The configuration data is reset when DEFAULT_CONFIG state is entered from hard reset. To change POC state 
 *         from DEFAULT_CONFIG to CONFIG state the Host has to apply CHI command CONFIG. 
 -         If the Host wants the CC to leave CONFIG state, the Host has to proceed as described in Lock Register (LCK).
 -         Note that some register bits can be updated in DEFAULT_CONFIG or CONFIG state only!
 * \{
 */

/** 
 * \defgroup SUCC1 SUC Configuration Register 1 (SUCC1)
 * \brief The CC accepts modifications of the register in DEFAULT_CONFIG or CONFIG state only.
 * \{
 */
# define FR_SUCC1                                                     0x00000080UL
/************************************** Register SUCC1 ***************************************************************/
/** 
 * \defgroup SUCC1_CMD SUCC1.CMD
 * \brief The Host may write any CHI command at any time, but certain commands are enabled only in certain POC states. 
 -        If a command is not enabled, it will not be executed, the CHI command vector CMD[3:0] will be reset to 
 *        "0000" = command_not_accepted, and flag EIR.CNA will be set to 1. 
 -        In case the previous CHI command has not yet completed, EIR.CCL is set to 1 together with EIR.CNA; the CHI 
 *        command needs to be repeated. 
 -        Except for HALT state, a POC state change command applied while the CC is already in the requested POC state 
 *        neither causes a state change nor will EIR.CNA be set.
 * \{
 */
# define FR_SUCC1_CMD_MASK                                            ((uint32) 0x0000000F)                 /*!< CHI Command Vector */
# define FR_SUCC1_CMD_SHIFT                                           0                                     /*!< CHI Command Vector position */
# define CCCMD_CNA                                                    ((uint32) 0x00000000)                 /*!< Command Not Accepted */
# define CCCMD_CONFIG                                                 ((uint32) 0x00000001)                 /*!< CONFIG */
# define CCCMD_READY                                                  ((uint32) 0x00000002)                 /*!< READY */
# define CCCMD_WAKEUP                                                 ((uint32) 0x00000003)                 /*!< WAKEUP */
# define CCCMD_RUN                                                    ((uint32) 0x00000004)                 /*!< RUN */
# define CCCMD_ALL_SLOTS                                              ((uint32) 0x00000005)                 /*!< ALL_SLOTS */
# define CCCMD_HALT                                                   ((uint32) 0x00000006)                 /*!< HALT */
# define CCCMD_FREEZE                                                 ((uint32) 0x00000007)                 /*!< FREEZE */
# define CCCMD_SEND_MTS                                               ((uint32) 0x00000008)                 /*!< SEND_MTS */
# define CCCMD_ALLOW_COLDSTART                                        ((uint32) 0x00000009)                 /*!< ALLOW_COLDSTART */
# define CCCMD_RESET_STATUS_INDICATORS                                ((uint32) 0x0000000A)                 /*!< RESET_STATUS_INDICATORS */
# define CCCMD_MONITOR_MODE                                           ((uint32) 0x0000000B)                 /*!< MONITOR_MODE */
# define CCCMD_CLEAR_RAMS                                             ((uint32) 0x0000000C)                 /*!< CLEAR_RAMS */
/**\} */
# define FR_SUCC1_PBSY                                                ((uint32) (0x00000001 << 7))          /*!< POC Busy */
# define FR_SUCC1_TXST                                                ((uint32) (0x00000001 << 8))          /*!< Transmit Startup Frame in Key Slot */
# define FR_SUCC1_TXSY                                                ((uint32) (0x00000001 << 9))          /*!< Transmit Sync Frame in Key Slot */
# define FR_SUCC1_CSA_MASK                                            ((uint32) 0x0000F800)                 /*!< Cold Start Attempts */
# define FR_SUCC1_CSA_SHIFT                                           11                                    /*!< Cold Start Attempts position */
# define FR_SUCC1_PTA_MASK                                            ((uint32) 0x001F0000)                 /*!< Passive to Active */
# define FR_SUCC1_PTA_SHIFT                                           16                                    /*!< Passive to Active position */
# define FR_SUCC1_WUCS                                                ((uint32) ((uint32)0x00000001 << 21)) /*!< WAkeup Channel Select */
# define FR_SUCC1_TSM                                                 ((uint32) ((uint32)0x00000001 << 22)) /*!< Transmission Slot Mode */
# define FR_SUCC1_HCSE                                                ((uint32) ((uint32)0x00000001 << 23)) /*!< Halt due to Clock Sync Error */
# define FR_SUCC1_MTSA                                                ((uint32) ((uint32)0x00000001 << 24)) /*!< Select Channel A for MTS Transmission */
# define FR_SUCC1_MTSB                                                ((uint32) ((uint32)0x00000001 << 25)) /*!< Select Channel B for MTS Transmission */
# define FR_SUCC1_CCHA                                                ((uint32) ((uint32)0x00000001 << 26)) /*!< Connected to Channel A */
# define FR_SUCC1_CCHB                                                ((uint32) ((uint32)0x00000001 << 27)) /*!< Connected to Channel B */
/**\} */

/** 
 * \defgroup SUCC2 SUC Configuration Register 2 (SUCC2)
 * \brief The CC accepts modifications of the register in DEFAULT_CONFIG or CONFIG state only.
 * \{
 */
# define FR_SUCC2                                                     0x00000084UL
/************************************** Register SUCC2 ***************************************************************/
# define FR_SUCC2_LT_MASK                                             ((uint32) 0x001FFFFF)  /*!< Listen Timeout (pdListenTimeout) */
# define FR_SUCC2_LT_SHIFT                                            0                      /*!< Listen Timeout position */
# define FR_SUCC2_LTN_MASK                                            ((uint32) 0x0F000000)  /*!< Listen Timeout Noise (gListenNoise - 1) */
# define FR_SUCC2_LTN_SHIFT                                           24                     /*!< Listen Timeout Noise position */
/**\} */

/** 
 * \defgroup SUCC3 SUC Configuration Register 3 (SUCC3)
 * \brief The CC accepts modifications of the register in DEFAULT_CONFIG or CONFIG state only.
 * \{
 */
# define FR_SUCC3                                                     0x00000088UL
/************************************** Register SUCC3 ***************************************************************/
# define FR_SUCC3_WCP_MASK                                            ((uint32) 0x0000000F) /*!< Maximum Without Clock Correction Passive (gMaxWithoutClockCorrectionPassive) */
# define FR_SUCC3_WCP_SHIFT                                           0 /*!< Maximum Without Clock Correction Passive position */
# define FR_SUCC3_WCF_MASK                                            ((uint32) 0x000000F0) /*!< Maximum Without Clock Correction Fatal (gMaxWithoutClockCorrectionFatal) */
# define FR_SUCC3_WCF_SHIFT                                           4 /*!< Maximum Without Clock Correction Fatal position */
/**\} */

/** 
 * \defgroup NEMC NEM Configuration Register (NEMC)
 * \brief The CC accepts modifications of the register in DEFAULT_CONFIG or CONFIG state only.
 * \{
 */
# define FR_NEMC                                                      0x0000008CUL
/************************************** Register NEMC ****************************************************************/
# define FR_NEMC_NML_MASK                                             ((uint32) 0x0000000F) /*!< Metwork Management Vector Length (gNetworkManagementVectorLength) */
# define FR_NEMC_NML_SHIFT                                            0 /*!< Metwork Management Vector Length position */
/**\} */

/** 
 * \defgroup PRTC1 PRT Configuration Register 1 (PRTC1)
 * \brief The CC accepts modifications of the register in DEFAULT_CONFIG or CONFIG state only.
 * \{
 */
# define FR_PRTC1                                                     0x00000090UL
/************************************** Register PRTC1 ***************************************************************/
# define FR_PRTC1_TSST_MASK                                           ((uint32) 0x0000000F) /*!< Transmission Start Sequence Transmitter (gdTSSTransmitter) */
# define FR_PRTC1_TSST_SHIFT                                          0
# define FR_PRTC1_CASM_MASK                                           ((uint32) 0x000007F0) /*!< Collision Avoidance Symbol Max (gdCASRxLowMax) */
# define FR_PRTC1_CASM_SHIFT                                          4
# define FR_PRTC1_SPP_MASK                                            ((uint32) 0x00003000) /*!< Strobe Point Position */
# define FR_PRTC1_SPP_SHIFT                                           12
# define FR_PRTC1_BRP_MASK                                            ((uint32) 0x0000C000) /*!< Baud Rate Prescaler (gdSampleClockPeriod, pSamplesPerMicrotick) */
# define FR_PRTC1_BRP_SHIFT                                           14
# define FR_PRTC1_RXW_MASK                                            ((uint32) 0x01FF0000) /*!< Wakeup Symbol Receive Window Length (gdWakeupSymbolRxWindow) */
# define FR_PRTC1_RXW_SHIFT                                           16
# define FR_PRTC1_RWP_MASK                                            ((uint32) 0xFC000000) /*!< Repetitions of Tx Wakeup Pattern (pWakeupPattern) */
# define FR_PRTC1_RWP_SHIFT                                           26
/**\} */

/** 
 * \defgroup PRTC2 PRT Configuration Register 2 (PRTC2)
 * \brief The CC accepts modifications of the register in DEFAULT_CONFIG or CONFIG state only.
 * \{
 */
# define FR_PRTC2                                                     0x00000094UL
/************************************** Register PRTC2 ***************************************************************/
# define FR_PRTC2_RXI_MASK                                            ((uint32) 0x0000003F) /*!< Wakeup Symbol Receive Idle (gdWakeupSymbolRxIdle) */
# define FR_PRTC2_RXI_SHIFT                                           0
# define FR_PRTC2_RXL_MASK                                            ((uint32) 0x00003F00) /*!< Wakeup Symbol Receive Low (gdWakeupSymbolRxLow) */
# define FR_PRTC2_RXL_SHIFT                                           8
# define FR_PRTC2_TXI_MASK                                            ((uint32) 0x00FF0000) /*!< Wakeup Symbol Transmit Idle (gdWakeupSymbolTxIdle) */
# define FR_PRTC2_TXI_SHIFT                                           16
# define FR_PRTC2_TXL_MASK                                            ((uint32) 0x3F000000) /*!< Wakeup Symbol Transmit Low (gdWakeupSymbolTxLow) */
# define FR_PRTC2_TXL_SHIFT                                           24
/**\} */

/** 
 * \defgroup MHDC MHD Configuration Register (MHDC)
 * \brief The CC accepts modifications of the register in DEFAULT_CONFIG or CONFIG state only.
 * \{
 */
# define FR_MHDC                                                      0x00000098UL
/************************************** Register MHDC ****************************************************************/
# define FR_MHDC_SFDL_MASK                                            ((uint32) 0x0000007F) /*!< Static Frame Data Length (gPayloadLengthStatic) */
# define FR_MHDC_SFDL_SHIFT                                           0
# define FR_MHDC_SLT_MASK                                             ((uint32) 0x1FFF0000) /*!< Start of Latest Transmit (pLatestTx) */
# define FR_MHDC_SLT_SHIFT                                            16
/**\} */

/** 
 * \defgroup GTUC1 GTU Configuration Register 1 (GTUC1)
 * \brief The CC accepts modifications of the register in DEFAULT_CONFIG or CONFIG state only.
 * \{
 */
# define FR_GTUC1                                                     0x000000A0UL
/************************************** Register GTUC1 ***************************************************************/
# define FR_GTUC1_UT_MASK                                             ((uint32) 0x000FFFFF) /*!< Microtick per Cycle (pMicroPerCycle) */
# define FR_GTUC1_UT_SHIFT                                            0
/**\} */

/** 
 * \defgroup GTUC2 GTU Configuration Register 2 (GTUC2)
 * \brief The CC accepts modifications of the register in DEFAULT_CONFIG or CONFIG state only.
 * \{
 */
# define FR_GTUC2                                                     0x000000A4UL
/************************************** Register GTUC2 ***************************************************************/
# define FR_GTUC2_MPC_MASK                                            ((uint32) 0x00003FFF) /*!< Macrotick per Cycle (gMacroPerCycle) */
# define FR_GTUC2_MPC_SHIFT                                           0
# define FR_GTUC2_SNM_MASK                                            ((uint32) 0x000F0000) /*!< Sync Node Max (gSyncNodeMax) */
# define FR_GTUC2_SNM_SHIFT                                           16
/**\} */

/** 
 * \defgroup GTUC3 GTU Configuration Register 3 (GTUC3)
 * \brief The CC accepts modifications of the register in DEFAULT_CONFIG or CONFIG state only.
 * \{
 */
# define FR_GTUC3                                                     0x000000A8UL
/************************************** Register GTUC3 ***************************************************************/
# define FR_GTUC3_UIOA_MASK                                           ((uint32) 0x000000FF) /*!< Microtick Initial Offset Channel A (pMicroInitialOffset[A]) */
# define FR_GTUC3_UIOA_SHIFT                                          0
# define FR_GTUC3_UIOB_MASK                                           ((uint32) 0x0000FF00) /*!< Microtick Initial Offset Channel B (pMicroInitialOffset[B]) */
# define FR_GTUC3_UIOB_SHIFT                                          8
# define FR_GTUC3_MIOA_MASK                                           ((uint32) 0x007F0000) /*!< Macrotick Initial Offset Channel A (pMacroInitialOffset[A]) */
# define FR_GTUC3_MIOA_SHIFT                                          16
# define FR_GTUC3_MIOB_MASK                                           ((uint32) 0x7F000000) /*!< Macrotick Initial Offset Channel B (pMacroInitialOffset[B]) */
# define FR_GTUC3_MIOB_SHIFT                                          24
/**\} */

/** 
 * \defgroup GTUC4 GTU Configuration Register 4 (GTUC4)
 * \brief The CC accepts modifications of the register in DEFAULT_CONFIG or CONFIG state only.
 * \{
 */
# define FR_GTUC4                                                     0x000000ACUL
/************************************** Register GTUC4 ***************************************************************/
# define FR_GTUC4_NIT_MASK                                            ((uint32) 0x00003FFF) /*!< Network Idle Time Start (gMacroPerCycle - gdNIT - 1) */
# define FR_GTUC4_NIT_SHIFT                                           0
# define FR_GTUC4_OCS_MASK                                            ((uint32) 0x3FFF0000) /*!< Offset Correction Start (gOffsetCorrectionStart - 1) */
# define FR_GTUC4_OCS_SHIFT                                           16
/**\} */

/** 
 * \defgroup GTUC5 GTU Configuration Register 5 (GTUC5)
 * \brief The CC accepts modifications of the register in DEFAULT_CONFIG or CONFIG state only.
 * \{
 */
# define FR_GTUC5                                                     0x000000B0UL
/************************************** Register GTUC5 ***************************************************************/
# define FR_GTUC5_DCA_MASK                                            ((uint32) 0x000000FF) /*!< Delay Compensation Channel A (pDelayCompensation[A]) */
# define FR_GTUC5_DCA_SHIFT                                           0
# define FR_GTUC5_DCB_MASK                                            ((uint32) 0x0000FF00) /*!< Delay Compensation Channel B (pDelayCompensation[B]) */
# define FR_GTUC5_DCB_SHIFT                                           8
# define FR_GTUC5_CDD_MASK                                            ((uint32) 0x001F0000) /*!< Cluster Drift Damping (pClusterDriftDamping) */
# define FR_GTUC5_CDD_SHIFT                                           16
# define FR_GTUC5_DEC_MASK                                            ((uint32) 0xFF000000) /*!< Decoding Correction (pDecodingCorrection) */
# define FR_GTUC5_DEC_SHIFT                                           24
/**\} */

/** 
 * \defgroup GTUC6 GTU Configuration Register 6 (GTUC6)
 * \brief The CC accepts modifications of the register in DEFAULT_CONFIG or CONFIG state only.
 * \{
 */
# define FR_GTUC6                                                     0x000000B4UL
/************************************** Register GTUC6 ***************************************************************/
# define FR_GTUC6_ASR_MASK                                            ((uint32) 0x000007FF) /*!< Accepted Startup Range (pdAcceptedStartupRange) */
# define FR_GTUC6_ASR_SHIFT                                           0
# define FR_GTUC6_MOD_MASK                                            ((uint32) 0x07FF0000) /*!< Maximum Oscillator Drift (pdMaxDrift) */
# define FR_GTUC6_MOD_SHIFT                                           16
/**\} */

/** 
 * \defgroup GTUC7 GTU Configuration Register 7 (GTUC7)
 * \brief The CC accepts modifications of the register in DEFAULT_CONFIG or CONFIG state only.
 * \{
 */
# define FR_GTUC7                                                     0x000000B8UL
/************************************** Register GTUC7 ***************************************************************/
# define FR_GTUC7_SSL_MASK                                            ((uint32) 0x000003FF) /*!< Static Slot Length (gdStaticSlot) */
# define FR_GTUC7_SSL_SHIFT                                           0
# define FR_GTUC7_NSS_MASK                                            ((uint32) 0x03FF0000) /*!< Number of Static Slots (gNumberOfStaticSlots) */
# define FR_GTUC7_NSS_SHIFT                                           16
/**\} */

/** 
 * \defgroup GTUC8 GTU Configuration Register 8 (GTUC8)
 * \brief The CC accepts modifications of the register in DEFAULT_CONFIG or CONFIG state only.
 * \{
 */
# define FR_GTUC8                                                     0x000000BCUL
/************************************** Register GTUC8 ***************************************************************/
# define FR_GTUC8_MSL_MASK                                            ((uint32) 0x0000003F) /*!< Minislot Length (gdMinislot) */
# define FR_GTUC8_MSL_SHIFT                                           0
# define FR_GTUC8_NMS_MASK                                            ((uint32) 0x1FFF0000) /*!< Number of Minislots (gNumberOfMinislots) */
# define FR_GTUC8_NMS_SHIFT                                           16
/**\} */

/** 
 * \defgroup GTUC9 GTU Configuration Register 9 (GTUC9)
 * \brief The CC accepts modifications of the register in DEFAULT_CONFIG or CONFIG state only.
 * \{
 */
# define FR_GTUC9                                                     0x000000C0UL
/************************************** Register GTUC9 ***************************************************************/
# define FR_GTUC9_APO_MASK                                            ((uint32) 0x0000003F) /*!< Action Point Offset (gdActionPointOffset) */
# define FR_GTUC9_APO_SHIFT                                           0
# define FR_GTUC9_MAPO_MASK                                           ((uint32) 0x00001F00) /*!< Minislot Action Point Offset (gdMinislotActionPointOffset) */
# define FR_GTUC9_MAPO_SHIFT                                          8
# define FR_GTUC9_DSI_MASK                                            ((uint32) 0x00030000) /*!< Dynamic Slot Idle Phase (gdDynamicSlotIdlePhase) */
# define FR_GTUC9_DSI_SHIFT                                           16
/**\} */

/** 
 * \defgroup GTUC10 GTU Configuration Register 10 (GTUC10)
 * \brief The CC accepts modifications of the register in DEFAULT_CONFIG or CONFIG state only.
 * \{
 */
# define FR_GTUC10                                                    0x000000C4UL
/************************************** Register GTUC10 **************************************************************/
/*! GTUC10 register bit masks */
# define FR_GTUC10_MOC_MASK                                           ((uint32) 0x00003FFF) /*!< Maximum Offset Correction (pOffsetCorrectionOut) */
# define FR_GTUC10_MOC_SHIFT                                          0
# define FR_GTUC10_MCR_MASK                                           ((uint32) 0x07FF0000) /*!< Maximum Rate Correction (pRateCorrectionOut) */
# define FR_GTUC10_MCR_SHIFT                                          16
/**\} */

/** 
 * \defgroup GTUC11 GTU Configuration Register 11 (GTUC11)
 * \brief The CC accepts modifications of the register in DEFAULT_CONFIG or CONFIG state only.
 * \{
 */
# define FR_GTUC11                                                    0x000000C8UL
/************************************** Register GTUC11 **************************************************************/
# define FR_GTUC11_EOCC_NONE                                          ((uint32) 0x00000000) /*!< No external offset correction */
# define FR_GTUC11_EOCC_DEC                                           ((uint32) 0x00000002) /*!< Subtracted from calculated offset correction value */
# define FR_GTUC11_EOCC_INC                                           ((uint32) 0x00000003) /*!< Added to calculated offset correction value */
# define FR_GTUC11_EOCC_MASK                                          ((uint32) 0x00000003) /*!< External Offset Correction Control[1:0] (vExternOffsetControl) */
# define FR_GTUC11_EOCC_SHIFT                                         0
# define FR_GTUC11_ERCC_NONE                                          ((uint32) 0x00000000) /*!< No external offset correction */
# define FR_GTUC11_ERCC_DEC                                           ((uint32) 0x00000002) /*!< Subtracted from calculated offset correction value */
# define FR_GTUC11_ERCC_INC                                           ((uint32) 0x00000003) /*!< Added to calculated offset correction value */
# define FR_GTUC11_ERCC_MASK                                          ((uint32) 0x00000003) /*!< External Rate Correction Control[1:0] (vExternRateControl) */
# define FR_GTUC11_ERCC_SHIFT                                         8
# define FR_GTUC11_EOC_MASK                                           ((uint32) 0x00070000) /*!< External Offset Correction (pExternOffsetCorrection) */
# define FR_GTUC11_EOC_SHIFT                                          16
# define FR_GTUC11_ERC_MASK                                           ((uint32) 0x07000000) /*!< External Rate Correction (pExternRateCorrection) */
# define FR_GTUC11_ERC_SHIFT                                          24
/**\} */
/**\} */

/**
 * \defgroup CSR CC Status Registers
 * \brief  During 8/16-bit accesses to status variables coded with more than 8/16-bit, the variable might be updated 
 *         by the CC between two accesses (non-atomic read accesses). The status vector may change faster than the 
 *         Host can poll the status vector, depending on eray_bclk frequency.
 * \{
 */

/** 
 * \defgroup CCSV CC Status Vector (CCSV)
 * \{
 */
# define FR_CCSV                                                      0x00000100UL
/************************************** Register CCSV ****************************************************************/
/** 
 * \defgroup CCSV_POCS CCSV.POCS
 * \brief Indicates:
 -  the actual state of operation of the CC Protocol Operation Control,
 -  the actual state of operation of the POC in the wakeup path,
 -  the actual state of operation of the POC in the startup path.
 * \{
 */
# define FR_CCSV_POCS_MASK                                            ((uint32) 0x0000003F)         /*!< Protocol Operation Control Status */
# define FR_CCSV_POCS_VALUE_MASK                                      ((uint32) 0x0000000F)         /*!< Values of Protocol Operation Control Status */
# define FR_CCSV_POCS_SHIFT                                           (0)
# define CCPOCS_DEFAULT_CONFIG                                        ((uint32) 0x00000000)         /*!< POCState DEFAULT_CONFIG */
# define CCPOCS_READY                                                 ((uint32) 0x00000001)         /*!< POCState READY */
# define CCPOCS_NORMAL_ACTIVE                                         ((uint32) 0x00000002)         /*!< POCState NORMAL_ACTIVE */
# define CCPOCS_NORMAL_PASSIVE                                        ((uint32) 0x00000003)         /*!< POCState NORMAL_PASSIVE */
# define CCPOCS_HALT                                                  ((uint32) 0x00000004)         /*!< POCState HALT */
# define CCPOCS_MONITOR_MODE                                          ((uint32) 0x00000005)         /*!< POCState MONITOR_MODE */
# define CCPOCS_CONFIG                                                ((uint32) 0x0000000F)         /*!< POCState CONFIG */
# define CCPOCS_WAKEUP_GROUP                                          ((uint32) 0x00000010)         /*!< Bit mask of WAKEUP_GROUP */
# define CCPOCS_WAKEUP_STANDBY                                        ((uint32) 0x00000010)         /*!< POCState WAKEUP_STANDBY */
# define CCPOCS_WAKEUP_LISTEN                                         ((uint32) 0x00000011)         /*!< POCState WAKEUP_LISTEN */
# define CCPOCS_WAKEUP_SEND                                           ((uint32) 0x00000012)         /*!< POCState WAKEUP_SEND */
# define CCPOCS_WAKEUP_DETECT                                         ((uint32) 0x00000013)         /*!< POCState WAKEUP_DETECT */
# define CCPOCS_STARTUP_GROUP                                         ((uint32) 0x00000020)         /*!< Bit mask of STARTUP_GROUP */
# define CCPOCS_STARTUP_PREPARE                                       ((uint32) 0x00000020)         /*!< POCState STARTUP_PREPARE */
# define CCPOCS_COLDSTART_LISTEN                                      ((uint32) 0x00000021)         /*!< POCState COLDSTART_LISTEN */
# define CCPOCS_COLDSTART_COLLISION_RESOLUTION                        ((uint32) 0x00000022)         /*!< POCState COLDSTART_COLLISION_RESOLUTION */
# define CCPOCS_COLDSTART_CONSISTENCY_CHECK                           ((uint32) 0x00000023)         /*!< POCState COLDSTART_CONSISTENCY_CHECK */
# define CCPOCS_COLDSTART_GAP                                         ((uint32) 0x00000024)         /*!< POCState COLDSTART_GAP */
# define CCPOCS_COLDSTART_JOIN                                        ((uint32) 0x00000025)         /*!< POCState COLDSTART_JOIN */
# define CCPOCS_INTEGRATION_COLDSTART_CHECK                           ((uint32) 0x00000026)         /*!< POCState INTEGRATION_COLDSTART_CHECK */
# define CCPOCS_INTEGRATION_LISTEN                                    ((uint32) 0x00000027)         /*!< POCState INTEGRATION_LISTEN */
# define CCPOCS_INTEGRATION_CONSISTENCY_CHECK                         ((uint32) 0x00000028)         /*!< POCState INTEGRATION_CONSISTENCY_CHECK */
# define CCPOCS_INITIALIZE_SCHEDULE                                   ((uint32) 0x00000029)         /*!< POCState INITIALIZE_SCHEDULE */
# define CCPOCS_ABORT_STARTUP                                         ((uint32) 0x0000002A)         /*!< POCState ABORT_STARTUP */
# define CCPOCS_GROUP_MASK                                            ((uint32) 0x00000030)         /*!< Bit mask of all POCState groups */
# define CCPOCS_GROUP_SHIFT                                           (4u)
/**\} */
# define FR_CCSV_FSI                                                  ((uint32) (0x00000001 << 6))  /*!< Freeze Status Indicator (vPOC!Freeze) */
# define FR_CCSV_HRQ                                                  ((uint32) (0x00000001 << 7))  /*!< Halt Request (vPOC!CHIHaltRequest) */
/************************************** Register CCSV ****************************************************************/
/** 
 * \defgroup CCSV_SLM CCSV.SLM
 * \brief Indicates the actual slot mode of the POC in states READY, WAKEUP, STARTUP,NORMAL_ACTIVE, and NORMAL_PASSIVE. 
 *        Default is SINGLE. Changes to ALL, depending on SUCC1.TSM. In NORMAL_ACTIVE or NORMAL_PASSIVE state the CHI 
 *        command ALL_SLOTS will change the slot mode from SINGLE over ALL_PENDING to ALL. Set to SINGLE in all other 
 *        states.
 * \{
 */
# define FR_CCSV_SLM_MASK                                             ((uint32) 0x00000300)         /*!< Slot Mode */
# define FR_CCSV_SLM_SHIFT                                            8
# define FR_CCSV_SLM_SINGLE                                           ((uint32) 0x00000000)         /*!< SINGLE */
# define FR_CCSV_SLM_ALL_PENDING                                      ((uint32) 0x00000002)         /*!< ALL_PENDING */
# define FR_CCSV_SLM_ALL                                              ((uint32) 0x00000003)         /*!< ALL */
/**\} */
# define FR_CCSV_CSNI                                                 ((uint32) (0x00000001 << 12)) /*!< Coldstart Noise Indicator (vPOC!ColdstartNoise) */
# define FR_CCSV_CSAI                                                 ((uint32) (0x00000001 << 13)) /*!< Coldstart Abort Indicator */
# define FR_CCSV_CSI                                                  ((uint32) (0x00000001 << 14)) /*!< Cold Start Inhibit (vColdStartInhibit) */
# define FR_CCSV_WSV_MASK                                             ((uint32) 0x00070000)         /*!< Wakeup Status (vPOC!WakeupStatus) */
# define FR_CCSV_WSV_SHIFT                                            16
# define FR_CCSV_RCA_MASK                                             ((uint32) 0x00F80000)         /*!< Remaining Coldstart Attempts (vRemainingColdstartAttempts) */
# define FR_CCSV_RCA_SHIFT                                            19
# define FR_CCSV_PSL_MASK                                             ((uint32) 0x3F000000)         /*!< POC Status Log */
# define FR_CCSV_PSL_SHIFT                                            24
/**\} */

/** 
 * \defgroup CCEV CC Error Vector (CCEV)
 * \{
 */
# define FR_CCEV                                                      0x00000104UL
/************************************** Register CCEV ****************************************************************/
# define FR_CCEV_CCFC_MASK                                            ((uint32) 0x0000000F) /*!< Clock Correction Failed Counter (vClockCorrectionFailed) */
# define FR_CCEV_CCFC_SHIFT                                           0
/** 
 * \defgroup CCEV_ERRM CCEV.ERRM
 * \brief Indicates the actual error mode of the POC.
 * \{
 */
# define FR_CCEV_ERRM_MASK                                            ((uint32) 0x000000C0) /*!< Error Mode (vPOC!ErrorMode) */
# define FR_CCEV_ERRM_SHIFT                                           6
# define FR_CCEV_ERRM_ACTIVE                                          ((uint32) 0x00000000) /*!< ACTIVE (green) */
# define FR_CCEV_ERRM_PASSIVE                                         ((uint32) 0x00000001) /*!< PASSIVE (yellow) */
# define FR_CCEV_ERRM_COMM_HALT                                       ((uint32) 0x00000002) /*!< COMM_HALT (red) */
/**\} */
# define FR_CCEV_PTAC_MASK                                            ((uint32) 0x00001F00) /*!< Passive to Active Count (vAllowPassiveToActive) */
# define FR_CCEV_PTAC_SHIFT                                           8
/**\} */

/** 
 * \defgroup SCV Slot Counter Value (SCV)
 * \brief The register is reset when the CC leaves CONFIG state or enters STARTUP state.
 -        The SCV register is not used by the FlexRay driver.
 * \{
 */
# define FR_SCV                                                       0x00000110UL
/************************************** Register SCV *****************************************************************/
# define FR_SCV_SCCA_MASK                                             ((uint32) 0x000007FF) /*!< Slot Counter Channel A (vSlotCounter[A]) */
# define FR_SCV_SCCA_SHIFT                                            0
# define FR_SCV_SCCB_MASK                                             ((uint32) 0x07FF0000) /*!< Slot Counter Channel B (vSlotCounter[B]) */
# define FR_SCV_SCCB_SHIFT                                            16
/**\} */

/** 
 * \defgroup MTCCV Macrotick and Cycle Counter Value (MTCCV)
 * \brief The register is reset when the CC leaves CONFIG state or enters STARTUP state.
 * \{
 */
# define FR_MTCCV                                                     0x00000114UL
/************************************** Register MTCCV ***************************************************************/
# define FR_MTCCV_MTV_MASK                                            ((uint32) 0x00003FFF) /*!< Macrotick Value (vMacrotick) */
# define FR_MTCCV_MTV_SHIFT                                           0
# define FR_MTCCV_CCV_MASK                                            ((uint32) 0x003F0000) /*!< Cycle Counter Value (vCycleCounter) */
# define FR_MTCCV_CCV_SHIFT                                           16
/**\} */

/** 
 * \defgroup RCV Rate Correction Value (RCV)
 * \brief The register is reset when the CC leaves CONFIG state or enters STARTUP state.
 * \{
 */
# define FR_RCV                                                       0x00000118UL
/************************************** Register RCV *****************************************************************/
# define FR_RCV_MASK                                                  ((uint32) 0x00000FFF) /*!< Rate Correction Value (vRateCorrection) */
# define FR_RCV_SHIFT                                                 0
/**\} */

/** 
 * \defgroup OCV Offset Correction Value (OCV)
 * \brief The register is reset when the CC leaves CONFIG state or enters STARTUP state.
 * \{
 */
# define FR_OCV                                                       0x0000011CUL
/************************************** Register OCV *****************************************************************/
# define CCREGVAL_OCV_MASK                                            ((uint32) 0x0007FFFF) /*!< Offset Correction Value (vOffsetCorrection) */
# define CCREGVAL_OCV_SHIFT                                           0
/**\} */

/** 
 * \defgroup SFS Sync Frame Status (SFS)
 * \brief The register is reset when the CC leaves CONFIG state or enters STARTUP state.
 * \{
 */
# define FR_SFS                                                       0x00000120UL
/************************************** Register SFS *****************************************************************/
# define FR_SFS_VSAE_MASK                                             ((uint32) 0x0000000F)         /*!< Valid Sync Frames Channel A, even communication cycle */
# define FR_SFS_VSAE_SHIFT                                            0
# define FR_SFS_VSAO_MASK                                             ((uint32) 0x000000F0)         /*!< Valid Sync Frames Channel A, odd communication cycle */
# define FR_SFS_VSAO_SHIFT                                            4
# define FR_SFS_VSBE_MASK                                             ((uint32) 0x00000F00)         /*!< Valid Sync Frames Channel B, even communication cycle */
# define FR_SFS_VSBE_SHIFT                                            8
# define FR_SFS_VSBO_MASK                                             ((uint32) 0x0000F000)         /*!< Valid Sync Frames Channel B, odd communication cycle */
# define FR_SFS_VSBO_SHIFT                                            12
# define FR_SFS_MOCS                                                  ((uint32) (0x00000001 << 16)) /*!< Missing Offset Correction Signal */
# define FR_SFS_OCLR                                                  ((uint32) (0x00000001 << 17)) /*!< Offset Correction Limit Reached */
# define FR_SFS_MRCS                                                  ((uint32) (0x00000001 << 18)) /*!< Missing Rate Correction Signal */
# define FR_SFS_RCLR                                                  ((uint32) (0x00000001 << 19)) /*!< Rate Correction Limit Reached */
/**\} */

/** 
 * \defgroup SWNIT Symbol Window and NIT Status (SWNIT)
 * \brief Symbol window related status information. Updated by the CC at the end of the symbol window for each channel.
 -        During startup the status data is not updated. 
 -        The register is reset when the CC leaves CONFIG state or enters STARTUP state.
 * \{
 */
# define FR_SWNIT                                                     0x00000124UL
/************************************** Register SWNIT ***************************************************************/
# define FR_SWNIT_SESA                                                ((uint32) (0x00000001 << 0) ) /*!< Syntax Error in Symbol Windows Channel A (vSS!SyntaxErrorA) */
# define FR_SWNIT_SBSA                                                ((uint32) (0x00000001 << 1) ) /*!< Slot Boundary Violation in Symbol Windows Channel A (vSS!BViolationA) */
# define FR_SWNIT_TCSA                                                ((uint32) (0x00000001 << 2) ) /*!< Transmission Conflict in Symbol Windows Channel A (vSS!TxConflictA) */
# define FR_SWNIT_SESB                                                ((uint32) (0x00000001 << 3) ) /*!< Syntax Error in Symbol Windows Channel B (vSS!SyntaxErrorB) */
# define FR_SWNIT_SBSB                                                ((uint32) (0x00000001 << 4) ) /*!< Slot Boundary Violation in Symbol Windows Channel B (vSS!BViolationB) */
# define FR_SWNIT_TCSB                                                ((uint32) (0x00000001 << 5) ) /*!< Transmission Conflict in Symbol Windows Channel B (vSS!TxConflictB) */
# define FR_SWNIT_MTSA_SFS                                            ((uint32) (0x00000001 << 6) ) /*!< MTS Received on Channel A (vSS!ValidMTSA) */
# define FR_SWNIT_MTSB_SFS                                            ((uint32) (0x00000001 << 7) ) /*!< MTS Received on Channel B (vSS!ValidMTSB) */
# define FR_SWNIT_SENA                                                ((uint32) (0x00000001 << 8) ) /*!< Syntax Error during NIT Channel A (vSS!SyntaxErrorA) */
# define FR_SWNIT_SBNA                                                ((uint32) (0x00000001 << 9) ) /*!< Slot Boundary Violation during NIT Channel A (vSS!BViolationA) */
# define FR_SWNIT_SENB                                                ((uint32) (0x00000001 << 10)) /*!< Syntax Error during NIT Channel B (vSS!SyntaxErrorB) */
# define FR_SWNIT_SBNB                                                ((uint32) (0x00000001 << 11)) /*!< Slot Boundary Violation during NIT Channel B (vSS!BViolationB) */
# define FR_SWNIT_WIN_A_SHIFT                                         ((uint8) 0x00)
# define FR_SWNIT_WIN_B_SHIFT                                         ((uint8) 0x03)
# define FR_SWNIT_MTSA_SFS_SHIFT                                      ((uint8) 0x06)
# define FR_SWNIT_MTSB_SFS_SHIFT                                      ((uint8) 0x07)
# define FR_SWNIT_SENA_SHIFT                                          ((uint8) 0x08)
# define FR_SWNIT_SENB_SHIFT                                          ((uint8) 0x0A)
/**\} */

/** 
 * \defgroup ACS Aggregated Channel Status (ACS)
 * \brief The aggregated channel status provides the Host with an accrued status of channel activity for all communication
 *        slots regardless of whether they are assigned for transmission or subscribed for reception. The aggregated 
 *        channel status also includes status data from the symbol window and the network idle time. 
 -        The status data is updated (set) after each slot and aggregated until it is reset by the Host.
 -        During startup the status data is not updated. 
 -        A flag is cleared by writing a 1 to the corresponding bit position. Writing a 0 has no effect on the flag. 
 -        The register is reset when the CC leaves CONFIG state or enters STARTUP state.
 * \{
 */
# define FR_ACS                                                       0x00000128UL
/************************************** Register ACS *****************************************************************/
# define FR_ACS_VFRA                                                  ((uint32) (0x00000001 << 0) ) /*!< Valid Frame Received on Channel A (vSS!ValidFrameA) */
# define FR_ACS_SEDA                                                  ((uint32) (0x00000001 << 1) ) /*!< Syntax Error Detected on Channel A (vSS!SyntaxErrorA) */
# define FR_ACS_CEDA                                                  ((uint32) (0x00000001 << 2) ) /*!< Content Error Detected on Channel A (vSS!ContentErrorA) */
# define FR_ACS_CIA                                                   ((uint32) (0x00000001 << 3) ) /*!< Communication Indicator Channel A */
# define FR_ACS_SBVA                                                  ((uint32) (0x00000001 << 4) ) /*!< Slot Boundary Violation on Channel A (vSS!BViolationA) */
# define FR_ACS_VFRB                                                  ((uint32) (0x00000001 << 8) ) /*!< Valid Frame Received on Channel B (vSS!ValidFrameB) */
# define FR_ACS_SEDB                                                  ((uint32) (0x00000001 << 9) ) /*!< Syntax Error Detected on Channel B (vSS!SyntaxErrorB) */
# define FR_ACS_CEDB                                                  ((uint32) (0x00000001 << 10)) /*!< Content Error Detected on Channel B (vSS!ContentErrorB) */
# define FR_ACS_CIB                                                   ((uint32) (0x00000001 << 11)) /*!< Communication Indicator Channel B */
# define FR_ACS_SBVB                                                  ((uint32) (0x00000001 << 12)) /*!< Slot Boundary Violation on Channel B (vSS!BViolationB) */
# define FR_FR_ACS_VFRA_SHIFT                                         ((uint8) 0x00)
# define FR_FR_ACS_VFRB_SHIFT                                         ((uint8) 0x08)
# define FR_FR_ACS_MASK                                               ((uint32) 0x0000FFFF )        /*!< Aggregated Channel Status */
/**\} */

/** 
 * \defgroup ESIDn Even Sync ID [1...15] (ESIDn)
 * \brief Registers ESID1 to ESID15 hold the frame IDs of the sync frames received in even communication cycles used 
 *        for clock synchronisation up to the limit of gSyncNodeMax. The values are sorted in ascending order, with 
 *        register ESID1 holding the lowest received sync frame ID. 
 -        If the node itself transmits a sync frame in an  even communication cycle, register ESID1 holds the respective 
 *        sync frame ID as configured in message buffer 0 and flags RXEA, RXEB are set. 
 -        The value is updated during the NIT of each even communication cycle. 
 -        The register is reset when the CC leaves CONFIG state or enters STARTUP state.
 * \{
 */
# define FR_ESIDn                                                     0x00000130UL
# define FR_ESID1                                                     0x00000130UL
# define FR_ESID2                                                     0x00000134UL
# define FR_ESID3                                                     0x00000138UL
# define FR_ESID4                                                     0x0000013CUL
# define FR_ESID5                                                     0x00000140UL
# define FR_ESID6                                                     0x00000144UL
# define FR_ESID7                                                     0x00000148UL
# define FR_ESID8                                                     0x0000014CUL
# define FR_ESID9                                                     0x00000150UL
# define FR_ESID10                                                    0x00000154UL
# define FR_ESID11                                                    0x00000158UL
# define FR_ESID12                                                    0x0000015CUL
# define FR_ESID13                                                    0x00000160UL
# define FR_ESID14                                                    0x00000164UL
# define FR_ESID15                                                    0x00000168UL
/************************************** Register ESIDn ***************************************************************/
# define FR_ESIDn_EID_MASK                                            ((uint32) 0x000003FF)         /*!< Even Sync ID (vsSyncIDListA,B even) */
# define FR_ESIDn_EID_SHIFT                                           0
# define FR_ESIDn_RXEA                                                ((uint32) (0x00000001 << 14)) /*!< Received / Configured Even Sync ID on Channel A */
# define FR_ESIDn_RXEB                                                ((uint32) (0x00000001 << 15)) /*!< Received / Configured Even Sync ID on Channel B */
# define FR_ESIDn_NUMBER                                              ((uint8) 15)                  /*!< Maximum number of ESID registers */
/**\} */

/** 
 * \defgroup OSIDn Odd Sync ID [1...15] (OSIDn)
 * \brief Registers OSID1 to OSID15 hold the frame IDs of the sync frames received in odd and even communication cycles
 *        used for clock synchronisation up to the limit of gSyncNodeMax. The values are sorted in ascending order, with
 *        register OSID1 holding the lowest received sync frame ID. 
 -        If the node itself transmits a sync frame in an odd  communication cycle, register OSID1 holds the respective
 *        sync frame ID as configured in message buffer 0 and flags RXOA, RXOB are set.
 -        The value is updated during the NIT of each odd communication cycle. 
 -        The register is reset when the CC leaves CONFIG state or enters STARTUP state.
 * \{
 */
# define FR_OSIDn                                                     0x00000170UL
# define FR_OSID1                                                     0x00000170UL
# define FR_OSID2                                                     0x00010174UL
# define FR_OSID3                                                     0x00020178UL
# define FR_OSID4                                                     0x0003017CUL
# define FR_OSID5                                                     0x00040180UL
# define FR_OSID6                                                     0x00050184UL
# define FR_OSID7                                                     0x00060188UL
# define FR_OSID8                                                     0x0007018CUL
# define FR_OSID9                                                     0x00080190UL
# define FR_OSID10                                                    0x00090194UL
# define FR_OSID11                                                    0x00100198UL
# define FR_OSID12                                                    0x0011019CUL
# define FR_OSID13                                                    0x001201A0UL
# define FR_OSID14                                                    0x001301A4UL
# define FR_OSID15                                                    0x000001A8UL
/************************************** Register OSIDn ***************************************************************/
# define FR_OSIDn_OID_MASK                                            ((uint32) 0x000003FF)         /*!< Odd Sync ID (vsSyncIDListA,B odd) */
# define FR_OSIDn_OID_SHIFT                                           0                                                                                     
# define FR_OSIDn_RXOA                                                ((uint32) (0x00000001 << 14)) /*!< Received / Configured Odd Sync ID on Channel A */
# define FR_OSIDn_RXOB                                                ((uint32) (0x00000001 << 15)) /*!< Received / Configured Odd Sync ID on Channel B */
/**\} */

/** 
 * \defgroup NMVn Network Management Vector [1...3] (NMVn)
 * \brief The three network management registers hold the accrued NM vector (configurable 0 to 12 bytes). The accrued 
 *        NM vector is generated by the CC by bit-wise ORing each NM vector received (valid static frames with PPI = 1)
 *        on each channel .
 -        The CC updates the NM vector at the end of each communication cycle as long as the CC is either in NORMAL_ACTIVE
 *        or NORMAL_PASSIVE state. The NM vector is reset when the CC leaves CONFIG state or enters STARTUP state.
 -        NMVn-bytes exceeding the configured NM vector length are not valid.
 * \{
 */
# define FR_NMVn                                                      0x000001B0UL
# define FR_NMV1                                                      0x000001B0UL
# define FR_NMV2                                                      0x000001B4UL
# define FR_NMV3                                                      0x000001B8UL
/************************************** Register NMVn ****************************************************************/
# define FR_NMVn_NM_MASK                                              ((uint32) 0xFFFFFFFF) /*!< Network Management Vector */
# define FR_NMVn_NM_SHIFT                                             0
/**\} */
/**\} */

/** 
 * \defgroup MBCR Message Buffer Control Registers
 * \{
 */

/** 
 * \defgroup MRC Message RAM Configuration (MRC)
 * \brief The Message RAM Configuration register defines the number of message buffers assigned to the static segment, 
 *        dynamic segment, and FIFO. 
 -        The register can be written during DEFAULT_CONFIG or CONFIG state only.
 * \{
 */
# define FR_MRC                                                       0x00000300UL
/************************************** Register MRC *****************************************************************/
# define FR_MRC_FDB_MASK                                              ((uint32) 0x000000FF)                 /*!< First Dynamic Buffer */
# define FR_MRC_FDB_SHIFT                                             0
# define FR_MRC_FFB_MASK                                              ((uint32) 0x0000FF00)                 /*!< First Buffer of FIFO */
# define FR_MRC_FFB_SHIFT                                             0
# define FR_MRC_LCB_MASK                                              ((uint32) 0x00FF0000)                 /*!< Last Configured Buffer */
# define FR_MRC_LCB_SHIFT                                             0
# define FR_MRC_SEC_MASK                                              ((uint32) 0x03000000)                 /*!< Secure Buffers */
# define FR_MRC_SEC_SHIFT                                             0
# define FR_MRC_SPLM                                                  ((uint32) ((uint32)0x00000001 << 26)) /*!< Sync Frame Payload Multiplex */
/**\} */

/** 
 * \defgroup FRF FIFO Rejection Filter (FRF)
 * \brief The FIFO Rejection Filter defines a user specified sequence of bits to which channel, frame ID, and cycle 
 *        count of the incoming frames are compared. Together with the FIFO Rejection Filter Mask this register 
 *        determines whether a message is rejected by the FIFO. 
 -        The FRF register can be written during DEFAULT_CONFIG or CONFIG state only.
 -        The FRF register is not used by the FlexRay driver.
 * \{
 */
# define FR_FRF                                                       0x00000304UL
/************************************** Register FRF *****************************************************************/
# define FR_FRF_CH_MASK                                               ((uint32) 0x00000003)
# define FR_FRF_CH_SHIFT                                              0
# define FR_FRF_FID_MASK_FRF                                          ((uint32) 0x00001FFC)
# define FR_FRF_FID_SHIFT_FRF                                         2
# define FR_FRF_CYF_MASK                                              ((uint32) 0x007F0000)
# define FR_FRF_CYF_SHIFT                                             16
# define FR_FRF_RSS                                                   ((uint32) ((uint32)0x00000001 << 23))
# define FR_FRF_RNF                                                   ((uint32) ((uint32)0x00000001 << 24))
/**\} */

/** 
 * \defgroup FRFM FIFO Rejection Filter Mask (FRFM)
 * \brief The FIFO Rejection Filter Mask specifies which of the corresponding frame ID filter bits are relevant for 
 *        rejection filtering. If a bit is set, it indicates that the corresponding bit in the FRF register will not
 *        be considered for rejection filtering. 
 -        The FRFM register can be written during DEFAULT_CONFIG or CONFIG state only.
 -        The FRFM register is not used by the FlexRay driver.
 * \{
 */
# define FR_FRFM                                                      0x00000308UL
/************************************** Register FRFM ****************************************************************/
# define FR_FRFM_MFID_MASK                                            ((uint32) 0x00001FFC)
# define FR_FRFM_MFID_SHIFT                                           2
/**\} */

/** 
 * \defgroup FCL FIFO Critical Level (FCL)
 * \brief The CC accepts modifications of the register in DEFAULT_CONFIG or CONFIG state only.
 -        The FCL register is not used by the FlexRay driver.
 * \{
 */
# define FR_FCL                                                       0x0000030CUL
/************************************** Register FCL *****************************************************************/
# define FR_FCL_CL_MASK                                               ((uint32) 0x000000FF)
# define FR_FCL_CL_SHIFT                                              0
/**\} */
/**\} */

/** 
 * \defgroup MBSR Message Buffer Status Registers
 * \{
 */

/** 
 * \defgroup MHDS Message Handler Status (MHDS)
 * \brief A flag is cleared by writing a 1 to the corresponding bit position. Writing a 0 has no effect on the flag. 
 -        The register will also be cleared by hard reset or by CHI command CLEAR_RAMS.
 * \{
 */
# define FR_MHDS                                                      0x00000310UL 
/************************************** Register MHDS ****************************************************************/
# define FR_MHDS_PIBF                                                 ((uint32) (0x00000001 << 0)) /*!< Parity Error Input Buffer RAM 1,2 */
# define FR_MHDS_POBF                                                 ((uint32) (0x00000001 << 1)) /*!< Parity Error Output Buffer RAM 1,2 */
# define FR_MHDS_PMR                                                  ((uint32) (0x00000001 << 2)) /*!< Parity Error Message RAM */
# define FR_MHDS_PTBF1                                                ((uint32) (0x00000001 << 3)) /*!< Parity Error Transient Buffer RAM A */
# define FR_MHDS_PTBF2                                                ((uint32) (0x00000001 << 4)) /*!< Parity Error Transient Buffer RAM B */
# define FR_MHDS_FMBD                                                 ((uint32) (0x00000001 << 5)) /*!< Faulty Message Buffer Detected */
# define FR_MHDS_MFMB                                                 ((uint32) (0x00000001 << 6)) /*!< Multiple Faulty Message Buffers detected */
# define FR_MHDS_CRAM                                                 ((uint32) (0x00000001 << 7)) /*!< Clear all internal RAM's */
# define FR_MHDS_FMB_MASK                                             ((uint32) 0x00007F00)        /*!< Faulty Message Buffers */
# define FR_MHDS_FMB_SHIFT                                            8
# define FR_MHDS_MBT_MASK                                             ((uint32) 0x007F0000)        /*!< Message Buffers Tranmsitted */
# define FR_MHDS_MBT_SHIFT                                            16
# define FR_MHDS_MBU_MASK                                             ((uint32) 0x7F000000)        /*!< Message Buffer Updated */
# define FR_MHDS_MBU_SHIFT                                            24
/**\} */

/** 
 * \defgroup LDTS Last Dynamic Transmit Slot (LDTS)
 * \brief The register is reset when the CC leaves CONFIG state, enters STARTUP state, or by CHI command CLEAR_RAMS.
 -        The LDTS register is not used by the FlexRay driver.
 * \{
 */
# define FR_LDTS                                                      0x00000314UL
/************************************** Register LDTS ****************************************************************/
# define FR_LDTS_LDTA_MASK                                            ((uint32) 0x000007FF) /*!< Last Dynamic Transmission Channel A */
# define FR_LDTS_LDTA_SHIFT                                           0
# define FR_LDTS_LDTB_MASK                                            ((uint32) 0x07FF0000) /*!< Last Dynamic Transmission Channel B */
# define FR_LDTS_LDTB_SHIFT                                           16
/**\} */

/** 
 * \defgroup FSR FIFO Status Register (FSR)
 * \brief The register is reset when the CC leaves CONFIG state, enters STARTUP state, or by CHI command CLEAR_RAMS.
 -        The FSR register is not used by the FlexRay driver.
 * \{
 */
# define FR_FSR                                                       0x00000318UL
/************************************** Register FSR *****************************************************************/
# define FR_FSR_RFNE_FSR                                              ((uint32) (0x00000001 << 0)) /*!<  */
# define FR_FSR_RFCL_FSR                                              ((uint32) (0x00000001 << 1))
# define FR_FSR_RFO_FSR                                               ((uint32) (0x00000001 << 2))
# define FR_FSR_RFFL_MASK                                             ((uint32) 0x0000FF00)
# define FR_FSR_RFFL_SHIFT                                            8
/**\} */

/** 
 * \defgroup MHDF Message Handler Constraints Flags (MHDF)
 * \brief Some constraints exist for the Message Handler regarding eray_bclk frequency, Message RAM configuration, and 
 *        FlexRay bus traffic (see Addendum to E-Ray FlexRay IP-Module Specification). To simplify software development, 
 *        constraints violations are reported by setting flags in the MHDF.
 -        The MHDF register is not used by the FlexRay driver.
 * \{
 */
# define FR_MHDF                                                      0x0000031CUL 
/************************************** Register MHDF ****************************************************************/
# define FR_MHDF_SNUA                                                 ((uint32) (0x00000001 << 0))
# define FR_MHDF_SNUB                                                 ((uint32) (0x00000001 << 1))
# define FR_MHDF_FNFA                                                 ((uint32) (0x00000001 << 2))
# define FR_MHDF_FNFB                                                 ((uint32) (0x00000001 << 3))
# define FR_MHDF_WAHP                                                 ((uint32) (0x00000001 << 8))
/**\} */

/** 
 * \defgroup TXRQn Transmission Request 1/2/3/4 (TXRQn)
 * \brief The four registers reflect the state of the TXR flags of all configured message buffers. The flags are 
 *        evaluated for transmit buffers only. 
 -        If the number of configured message buffers is less than 128, the remaining TXR flags have no meaning.
 * \{
 */
# define FR_TXRQn                                                     0x00000320UL
/************************************** Register TXRQn ***************************************************************/
# define FR_TXRQn_TXR_MASK                                            ((uint32) 0xFFFFFFFF)
# define FR_TXRQn_TXR_SHIFT                                           0
/**\} */

/** 
 * \defgroup NDATn New Data 1/2/3/4 (NDATn)
 * \brief The four registers reflect the state of the ND flags of all configured message buffers. ND flags belonging 
 *        to transmit buffers have no meaning. 
 -        If the number of configured message buffers is less than 128, the remaining ND flags have no meaning. 
 -        The registers are reset when the CC leaves CONFIG state or enters STARTUP state.
 * \{
 */
# define FR_NDATn                                                     0x00000330UL
/************************************** Register NDATn ***************************************************************/
# define FR_NDATn_ND_MASK                                             ((uint32) 0xFFFFFFFF)
# define FR_NDATn_ND_SHIFT                                            0
/**\} */

/** 
 * \defgroup MBSCn Message Buffer Status Changed 1/2/3/4 (MBSCn)
 * \brief The four registers reflect the state of the MBC flags of all configured message buffers. 
 -        If the number of configured message buffers is less than 128, the remaining MBC flags have no meaning. 
 -        The registers are reset when the CC leaves CONFIG state or enters STARTUP state.
 -        The FR_MBSCn registers are not used by the FlexRay driver.
 * \{
 */
# define FR_MBSCn                                                     0x00000340UL
/************************************** Register MBSCn ***************************************************************/
# define FR_MBSCn_MBC_MASK                                            ((uint32) 0xFFFFFFFF)
# define FR_MBSCn_MBC_SHIFT                                           0
/**\} */
/**\} */

/** 
 * \defgroup IDR Identification Registers
 * \{
 */

/** 
 * \defgroup CREL Core Release Register (CREL)
 * \brief The CREL register is not used by the FlexRay driver.
 * \{
 */
# define FR_CREL                                                      0x000003F0UL
/************************************** Register CREL ****************************************************************/
# define FR_CREL_DAY_MASK                                             ((uint32) 0x000000FF)
# define FR_CREL_DAY_SHIFT                                            0
# define FR_CREL_MON_MASK                                             ((uint32) 0x0000FF00)
# define FR_CREL_MON_SHIFT                                            8
# define FR_CREL_YEAR_MASK                                            ((uint32) 0x000F0000)
# define FR_CREL_YEAR_SHIFT                                           16
# define FR_CREL_STEP_MASK                                            ((uint32) 0x0FF00000)
# define FR_CREL_STEP_SHIFT                                           20
# define FR_CREL_REL_MASK                                             ((uint32) 0xF0000000)
# define FR_CREL_REL_SHIFT                                            28
/**\} */

/** 
 * \defgroup ENDN Endian Register (ENDN)
 * \brief The ENDN register is not used by the FlexRay driver.
 * \{
 */
# define FR_ENDN                                                      0x000003F4UL
/************************************** Register ENDN ****************************************************************/
# define FR_ENDN_ETV_MASK                                             ((uint32) 0xFFFFFFFF)
# define FR_ENDN_ETV_SHIFT                                            0
/**\} */
/**\} */

/** 
 * \defgroup IB Input Buffer
 * \brief Double buffer structure consisting of Input Buffer Host and Input Buffer Shadow. While the Host can write to 
 *        Input Buffer Host, the transfer to the Message RAM is done from Input Buffer Shadow. The Input Buffer holds 
 *        the header and data sections to be transferred to the selected message buffer in the Message RAM. It is used 
 *        to configure the message buffers in the Message RAM and to update the data sections of transmit buffers.
 -        When updating the header section of a message buffer in the Message RAM from the Input Buffer, the Message 
 *        Buffer Status (MBS) is automatically reset to zero.
 -        The header sections of message buffers belonging to the receive FIFO can only be (re)configured when the CC 
 *        is in DEFAULT_CONFIG or CONFIG state. For those message buffers only the payload length configured and the 
 *        data pointer need to be configured via WRHS2.PLC[6:0] and WRHS3.DP[10:0]. All information required for acceptance 
 *        filtering is taken from the FIFO rejection filter and the FIFO rejection filter mask.
 * \{
 */

/** 
 * \defgroup WRDSn Write Data Section [1...64] (WRDSn)
 * \brief Holds the data words to be transferred to the data section of the addressed message buffer. The data words are 
 *        written to the Message RAM in transmission order from DW1(byte0, byte1) to DW_PL (PL = number of data words as 
 *        defined by the payload length configured WRHS2.PLC[6:0]).
 * \{
 */
# define FR_WRDSn                                                     0x00000400UL
/************************************** Register WRDSn ***************************************************************/
# define FR_WRDSn_MD_MASK                                             ((uint32) 0xFFFFFFFF)
# define FR_WRDSn_MD_SHIFT                                            0

# define FR_WRHS1                                                     0x00000500UL
/************************************** Register WRHS1 ***************************************************************/
# define FR_WRHS1_FID_MASK                                            ((uint32) 0x000007FF)                 /*!< Frame ID */
# define FR_WRHS1_FID_SHIFT                                           0
# define FR_WRHS1_CYC_MASK                                            ((uint32) 0x007F0000)                 /*!< Cycle Code */
# define FR_WRHS1_CYC_SHIFT                                           16
# define FR_WRHS1_CHA                                                 ((uint32) ((uint32)0x00000001 << 24)) /*!< Channel Filter Control Channel A */
# define FR_WRHS1_CHA_SHIFT                                           24
# define FR_WRHS1_CHB                                                 ((uint32) ((uint32)0x00000001 << 25)) /*!< Channel Filter Control Channel B */
# define FR_WRHS1_CFG                                                 ((uint32) ((uint32)0x00000001 << 26)) /*!< Message Buffer Direction Configuration Bit */
# define FR_WRHS1_PPIT                                                ((uint32) ((uint32)0x00000001 << 27)) /*!< Payload Preamble Indicator Transmit */
# define FR_WRHS1_TXM                                                 ((uint32) ((uint32)0x00000001 << 28)) /*!< Transmission Mode */
# define FR_WRHS1_MBI                                                 ((uint32) ((uint32)0x00000001 << 29)) /*!< Message Buffer Interrupt */

# define FR_WRHS2                                                     0x00000504UL
/************************************** Register WRHS2 ***************************************************************/
# define FR_WRHS2_CRC_MASK                                            ((uint32) 0x000007FF) /*!< Header CRC (vRF!Header!HeaderCRC) */
# define FR_WRHS2_CRC_SHIFT                                           0
# define FR_WRHS2_PLC_MASK                                            ((uint32) 0x007F0000) /*!< Payload Length Configured */
# define FR_WRHS2_PLC_SHIFT                                           ((uint8) 16)
# define FR_WRHS2_PLC_BYTE_SHIFT                                      ((uint8) 15)          /*!< Shift PLC to bytevalue. Precondition: WRHS2.bit15 to be 0 */

# define FR_WRHS3                                                     0x00000508UL
/************************************** Register WRHS3 ***************************************************************/
# define FR_WRHS3_DP_MASK                                             ((uint32) 0x000007FF)
# define FR_WRHS3_DP_SHIFT                                            0
/**\} */

/** 
 * \defgroup IBCM Input Buffer Command Mask (IBCM)
 * \brief Configures how the message buffer in the Message RAM selected by register IBCR is updated. When IBF Host and 
 *        IBF Shadow are swapped, also mask bits LHSH, LDSH, and STXRH are swapped with bits LHSS, LDSS, and STXRS to 
 *        keep them attached to the respective Input Buffer transfer.
 * \{
 */
# define FR_IBCM                                                      0x00000510UL
/************************************** Register IBCM ****************************************************************/
# define FR_IBCM_LHSH                                                 ((uint32) (0x00000001 << 0) )         /*!< Load Header Section Host */
# define FR_IBCM_LDSH                                                 ((uint32) (0x00000001 << 1) )         /*!< Load Data Section Host */
# define FR_IBCM_STXRH                                                ((uint32) (0x00000001 << 2) )         /*!< Set Transmission Request Host */
# define FR_IBCM_LHSS                                                 ((uint32) ((uint32)0x00000001 << 16)) /*!< Load Header Section Shadow */
# define FR_IBCM_LDSS                                                 ((uint32) ((uint32)0x00000001 << 17)) /*!< Load Data Section Shadow */
# define FR_IBCM_STXRS                                                ((uint32) ((uint32)0x00000001 << 18)) /*!< Set Transmission Request Shadow */
/**\} */

/** 
 * \defgroup IBCR Input Buffer Command Request (IBCR)
 * \brief When the Host writes the number of the target message buffer in the Message RAM to IBRH[6:0], IBF Host and 
 *        IBF Shadow are swapped. In addition the message buffer numbers stored under IBRH[6:0] and IBRS[6:0] are 
 *        also swapped.
 -        With this write operation the IBSYS is set to 1. The Message Handler then starts to transfer the contents 
 *        of IBF Shadow to the message buffer in the Message RAM selected by IBRS[6:0]. 
 -        While the Message Handler transfers the data from IBF Shadow to the target message buffer in the Message RAM,
 *        the Host may write the next message into the IBF Host. After the transfer between IBF Shadow and the 
 *        Message RAM has completed, IBSYS is set back to 0 and the next transfer to the Message RAM may be started 
 *        by the Host by writing the respective target message buffer number to IBRH[6:0].
 -        If a write access to IBRH[6:0] occurs while IBSYS is 1, IBSYH is set to 1. After completion of the ongoing
 *        data transfer from IBF Shadow to the Message RAM, IBF Host and IBF Shadow are swapped, IBSYH is reset to 0. 
 *        IBSYS remains set to 1, and the next transfer to the Message RAM is started. In addition the message buffer
 *        numbers stored under IBRH[6:0] and IBRS[6:0] are also swapped.
 -        Any write access to an Input Buffer register while both IBSYS and IBSYH are set will cause the error flag 
 *        EIR.IIBA to be set. In this case the Input Buffer will not be changed.
 * \{
 */
# define FR_IBCR                                                      0x00000514UL
/************************************** Register IBCR ****************************************************************/
# define FR_IBCR_IBRH_MASK                                            ((uint32) 0x0000007F)                 /*!< Input Buffer Request Host */
# define FR_IBCR_IBRH_SHIFT                                           0
# define FR_IBCR_IBSYH                                                ((uint32) (0x00000001 << 15))         /*!< Input Buffer Busy Host */
# define FR_IBCR_IBRS_MASK                                            ((uint32) 0x007F0000)                 /*!< Input Buffer Request Shadow */
# define FR_IBCR_IBRS_SHIFT                                           16
# define FR_IBCR_IBSYS                                                ((uint32) ((uint32)0x00000001 << 31)) /*!< Input Buffer Busy Shadow */
/**\} */
/**\} */

/** 
 * \defgroup OB Output Buffer
 * \brief Double buffer structure consisting of Output Buffer Host and Output Buffer Shadow. Used to read out message 
 *        buffers from the Message RAM. While the Host can read from Output Buffer Host, the Message Handler transfers
 *        the selected message buffer from Message RAM to Output Buffer Shadow.
 * \{
 */

/** 
 * \defgroup RDDSn Read Data Section [1...64] (RDDSn)
 * \brief Holds the data words read from the data section of the addressed message buffer. The data words are read from 
 *        the Message RAM in reception order from DW1 (byte0, byte1) to DW_PL (PL = number of data words as defined by 
 *        the payload length configured RDHS2.PLC[6:0]).
 * \{
 */
# define FR_RDDSn                                                     0x00000600UL
/************************************** Register RDDSn ***************************************************************/
# define FR_RDDSn_MD_MASK                                             ((uint32) 0xFFFFFFFF)
# define FR_RDDSn_MD_SHIFT                                            0
/**\} */

/** 
 * \defgroup RDHS1 Read Header Section 1 (RDHS1)
 * \brief Values as configured by the Host via WRHS1.
 * \{
 */
# define FR_RDHS1                                                     0x00000700UL
/************************************** Register RDHS1 ***************************************************************/
# define FR_RDHS1_FID_MASK                                            ((uint32) 0x000007FF)                 /*!< Frame ID */
# define FR_RDHS1_FID_SHIFT                                           0                                                                                        
# define FR_RDHS1_CYC_MASK                                            ((uint32) 0x007F0000)                 /*!< Cycle Code */
# define FR_RDHS1_CYC_SHIFT                                           16                                                                                       
# define FR_RDHS1_CHA                                                 ((uint32) ((uint32)0x00000001 << 24)) /*!< Channel Filter Control Channel A */
# define FR_RDHS1_CHB                                                 ((uint32) ((uint32)0x00000001 << 25)) /*!< Channel Filter Control Channel B */
# define FR_RDHS1_CFG                                                 ((uint32) ((uint32)0x00000001 << 26)) /*!< Message Buffer Direction Configuration Bit */
# define FR_RDHS1_PPIT                                                ((uint32) ((uint32)0x00000001 << 27)) /*!< Payload Preamble Indicator Transmit */
# define FR_RDHS1_TXM                                                 ((uint32) ((uint32)0x00000001 << 28)) /*!< Transmission Mode */
# define FR_RDHS1_MBI                                                 ((uint32) ((uint32)0x00000001 << 29)) /*!< Message Buffer Interrupt */
/**\} */

/** 
 * \defgroup RDHS2 Read Header Section 2 (RDHS2)
 * \brief Values as configured by the Host via WRHS2.
 * \{
 */
# define FR_RDHS2                                                     0x00000704UL
/************************************** Register RDHS2 ***************************************************************/
# define FR_RDHS2_CRC_MASK                                            ((uint32) 0x000007FF) /*!< Header CRC (vRF!Header!HeaderCRC) */
# define FR_RDHS2_CRC_SHIFT                                           0                                                                                       
# define FR_RDHS2_PLC_MASK                                            ((uint32) 0x007F0000) /*!< Payload Length Configured */
# define FR_RDHS2_PLC_SHIFT                                           16                                                                                      
# define FR_RDHS2_PLR_MASK                                            ((uint32) 0x7F000000) /*!< Payload Length Received */
# define FR_RDHS2_PLR_SHIFT                                           24
/**\} */

/** 
 * \defgroup RDHS3 Read Header Section 3 (RDHS3)
 * \brief Values as configured by the Host via WRHS3.
 * \{
 */
# define FR_RDHS3                                                     0x00000708UL
/************************************** Register RDHS3 ***************************************************************/
# define FR_RDHS3_DP_MASK                                             ((uint32) 0x000007FF)                 /*!< Data Pointer */
# define FR_RDHS3_DP_SHIFT                                            0
# define FR_RDHS3_RCC_MASK                                            ((uint32) 0x003F0000)                 /*!< Receive Cycle Count (vRF!Header!CycleCount) */
# define FR_RDHS3_RCC_SHIFT                                           16
# define FR_RDHS3_RCI                                                 ((uint32) ((uint32)0x00000001 << 24)) /*!< Received on Channel Indicator (vSS!Channel) */
# define FR_RDHS3_SFI                                                 ((uint32) ((uint32)0x00000001 << 25)) /*!< Startup Frame Indicator (vRF!Header!SuFIndicator) */
# define FR_RDHS3_SYN                                                 ((uint32) ((uint32)0x00000001 << 26)) /*!< Sync Frame Indicator (vRF!Header!SyFIndicator) */
# define FR_RDHS3_NFI                                                 ((uint32) ((uint32)0x00000001 << 27)) /*!< Null Frame Indicator (vRF!Header!NFIndicator) */
# define FR_RDHS3_PPI                                                 ((uint32) ((uint32)0x00000001 << 28)) /*!< Payload Preamble Indicator (vRF!Header!PPIndicator) */
# define FR_RDHS3_RES                                                 ((uint32) ((uint32)0x00000001 << 29)) /*!< Reserved Bit (vRF!Header!Reserved) */
/**\} */

/** 
 * \defgroup MBS Message Buffer Status (MBS)
 * \brief The message buffer status is updated by the CC with respect to the assigned channel(s) latest at the end of 
 *        the slot following the slot assigned to the message buffer. The flags are updated only when the CC is in 
 *        NORMAL_ACTIVE or NORMAL_PASSIVE state. If only one channel (A or B) is assigned to a message buffer, the 
 *        channel-specific status flags of the other channel are written to zero. If both channels are assigned to 
 *        a message buffer, the channel-specific status flags of both channels are updated. 
 -        The message buffer status is updated only when the slot counter reached the configured frame ID and when the 
 *        cycle counter filter matched. When the Host updates a message buffer via Input Buffer, all MBS flags are 
 *        reset to zero independent of which IBCM bits are set or not. 
 -        Whenever the Message Handler changes one of the flags VFRA, VFRB, SEOA, SEOB, CEOA, CEOB, SVOA, SVOB, TCIA, 
 *        TCIB, ESA, ESB, MLST, FTA, FTB the respective message buffer's MBC flag in registers MBSC1/2/3/4 is set.
 * \{
 */
# define FR_MBS                                                       0x0000070CUL
/************************************** Register MBS *****************************************************************/
# define FR_MBS_VFRA                                                  ((uint32) (0x00000001 << 0) )         /*!< Valid Frame Received on Channel A (vSS!ValidFrameA) */
# define FR_MBS_VFRB                                                  ((uint32) (0x00000001 << 1) )         /*!< Valid Frame Received on Channel B (vSS!ValidFrameB) */
# define FR_MBS_SEOA                                                  ((uint32) (0x00000001 << 2) )         /*!< Syntax Error Observed on Channel A (vSS!SyntaxErrorA) */
# define FR_MBS_SEOB                                                  ((uint32) (0x00000001 << 3) )         /*!< Syntax Error Observed on Channel B (vSS!SyntaxErrorB) */
# define FR_MBS_CEOA                                                  ((uint32) (0x00000001 << 4) )         /*!< Content Error Observed on Channel A (vSS!ContentErrorA) */
# define FR_MBS_CEOB                                                  ((uint32) (0x00000001 << 5) )         /*!< Content Error Observed on Channel B (vSS!ContentErrorB) */
# define FR_MBS_SVOA                                                  ((uint32) (0x00000001 << 6) )         /*!< Slot Boundary Violation Observed on Channel A (vSS!BViolationA) */
# define FR_MBS_SVOB                                                  ((uint32) (0x00000001 << 7) )         /*!< Slot Boundary Violation Observed on Channel B (vSS!BViolationB) */
# define FR_MBS_TCIA                                                  ((uint32) (0x00000001 << 8) )         /*!< Transmission Conflict Indication Channel A (vSS!TxConflictA) */
# define FR_MBS_TCIA_SHIFT                                            8
# define FR_MBS_TCIB                                                  ((uint32) (0x00000001 << 9) )         /*!< Transmission Conflict Indication Channel B (vSS!TxConflictB) */
# define FR_MBS_TCIB_SHIFT                                            9
# define FR_MBS_ESA                                                   ((uint32) (0x00000001 << 10))         /*!< Empty Slot Channel A */
# define FR_MBS_ESB                                                   ((uint32) (0x00000001 << 11))         /*!< Empty Slot Channel B */
# define FR_MBS_MLST                                                  ((uint32) (0x00000001 << 12))         /*!< Message Lost */
# define FR_MBS_FTA                                                   ((uint32) (0x00000001 << 14))         /*!< Frame Tranmsitted on Channel A */
# define FR_MBS_FTB                                                   ((uint32) (0x00000001 << 15))         /*!< Frame Tranmsitted on Channel B */
# define FR_MBS_CCS_MASK                                              ((uint32) 0x003F0000)                 /*!< Cycle Count Status */
# define FR_MBS_CCS_SHIFT                                             16
# define FR_MBS_RCIS                                                  ((uint32)( (uint32)0x00000001 << 24)) /*!< Received on Channel Indicator Status (vSS!Channel) */
# define FR_MBS_SFIS                                                  ((uint32)( (uint32)0x00000001 << 25)) /*!< Startup Frame Indicator Status (vRF!Header!SuFIndicator) */
# define FR_MBS_SYNS                                                  ((uint32)( (uint32)0x00000001 << 26)) /*!< Sync Frame Indicator Status (vRF!Header!SyFIndicator) */
# define FR_MBS_NFIS                                                  ((uint32)( (uint32)0x00000001 << 27)) /*!< Null Frame Indicator Status (vRF!Header!NFIndicator) */
# define FR_MBS_PPIS                                                  ((uint32)( (uint32)0x00000001 << 28)) /*!< Payload Preamble Indicator Status (vRF!Header!PPIndicator) */
# define FR_MBS_RESS                                                  ((uint32)( (uint32)0x00000001 << 29)) /*!< Reserved Bit Status (vRF!Header!Reserved) */
/**\} */

/** 
 * \defgroup OBCM Output Buffer Command Mask (OBCM)
 * \brief Configures how the Output Buffer is updated from the message buffer in the Message RAM selected by OBCR.OBRS[6:0].
 *        Mask bits RDSS and RHSS are copied to the register internal storage when a Message RAM transfer is requested 
 *        by OBCR.REQ. When OBF Host and OBF Shadow are swapped, mask bits RDSH and RHSH are swapped with the register 
 *        internal storage to keep them attached to the respective Output Buffer transfer. 
 *
 * \{
 */
# define FR_OBCM                                                      0x00000710UL
/************************************** Register OBCM ****************************************************************/
# define FR_OBCM_RHSS                                                 ((uint32) (0x00000001 << 0) )         /*!< Read Header Section Shadow */
# define FR_OBCM_RDSS                                                 ((uint32) (0x00000001 << 1) )         /*!< Read Data Section Shadow */
# define FR_OBCM_RHSH                                                 ((uint32) ((uint32)0x00000001 << 16)) /*!< Read Header Section Host */
# define FR_OBCM_RDSH                                                 ((uint32) ((uint32)0x00000001 << 17)) /*!< Read Data Section Host */
/**\} */

/** 
 * \defgroup OBCR Output Buffer Command Request (OBCR)
 * \brief After setting bit REQ to 1 while OBSYS is 0, OBSYS is automatically set to 1, OBRS[6:0] is copied to 
 *        the register internal storage, mask bits OBCM.RDSS and OBCM.RHSS are copied to register OBCM internal storage,
 *        and the transfer of the message buffer selected by OBRS[6:0] from the Message RAM to OBF Shadow is started. 
 *        When the transfer between the Message RAM and OBF Shadow has completed, this is signalled by setting OBSYS back
 *        to 0.
 -        By setting bit VIEW to 1 while OBSYS is 0, OBF Host and OBF Shadow are swapped. Additionally mask bits OBCM.RDSH
 *        and OBCM.RHSH are swapped with the register OBCM internal storage to keep them attached to the respective Output
 *        Buffer transfer. OBRH[6:0] signals the number of the message buffer currently accessible by the Host.
 -        If bits REQ and VIEW are set to 1 with the same write access while OBSYS is 0, OBSYS is automatically set to 1 
 *        and OBF Shadow and OBF Host are swapped. Additionally mask bits OBCM.RDSH and OBCM.RHSH are swapped with the 
 *        registers internal storage to keep them attached to the respective Output Buffer transfer. Afterwards OBRS[6:0] 
 *        is copied to the register internal storage, and the transfer of the selected message buffer from the Message RAM 
 *        to OBF Shadow is started. While the transfer is ongoing the Host can read the message buffer transferred by the 
 *        previous transfer from OBF Host. When the current transfer between Message RAM and OBF Shadow has completed, this 
 *        is signalled by setting OBSYS back to 0.
 -        Any write access to OBCR[15:8] while OBSYS is set will cause the error flag EIR.IOBA to be set. In this case the 
 *        Output Buffer will not be changed.
 * \{
 */
# define FR_OBCR                                                      0x00000714UL
/************************************** Register OBCR ****************************************************************/
# define FR_OBCR_OBRS_MASK                                            ((uint32) 0x0000007F)         /*!< Output Buffer Request Shadow */
# define FR_OBCR_OBRS_SHIFT                                           0
# define FR_OBCR_VIEW                                                 ((uint32) (0x00000001 << 8) ) /*!< View Shadow Buffer */
# define FR_OBCR_REQ                                                  ((uint32) (0x00000001 << 9) ) /*!< Request Message RAM Transfer */
# define FR_OBCR_OBSYS                                                ((uint32) (0x00000001 << 15)) /*!< Output Buffer Busy Shadow */
# define FR_OBCR_OBRH_MASK                                            ((uint32) 0x007F0000)         /*!< Output Buffer Request Host */
# define FR_OBCR_OBRH_SHIFT                                           0
/**\} */
/**\} */

/************************************** Output Buffer ****************************************************************/
/* These defines are only used by the FR81, SH2 and TMS570 FlexRay driver */
# define CCBUF_RDDS1                                                  (uint32)0x0600
# define CCBUF_RDDS2                                                  (uint32)0x0604
# define CCBUF_RDDS3                                                  (uint32)0x0608
# define CCBUF_RDDS4                                                  (uint32)0x060C
# define CCBUF_RDDS5                                                  (uint32)0x0610
# define CCBUF_RDDS6                                                  (uint32)0x0614
# define CCBUF_RDDS7                                                  (uint32)0x0618
# define CCBUF_RDDS8                                                  (uint32)0x061C
# define CCBUF_RDDS9                                                  (uint32)0x0620
# define CCBUF_RDDS10                                                 (uint32)0x0624
# define CCBUF_RDDS11                                                 (uint32)0x0628
# define CCBUF_RDDS12                                                 (uint32)0x062C
# define CCBUF_RDDS13                                                 (uint32)0x0630
# define CCBUF_RDDS14                                                 (uint32)0x0634
# define CCBUF_RDDS15                                                 (uint32)0x0638
# define CCBUF_RDDS16                                                 (uint32)0x063C
# define CCBUF_WRDS1                                                  (uint32)0x0400
# define CCBUF_WRDS2                                                  (uint32)0x0404
# define CCBUF_WRDS3                                                  (uint32)0x0408
# define CCBUF_WRDS4                                                  (uint32)0x040C
# define CCBUF_WRDS5                                                  (uint32)0x0410
# define CCBUF_WRDS6                                                  (uint32)0x0414
# define CCBUF_WRDS7                                                  (uint32)0x0418
# define CCBUF_WRDS8                                                  (uint32)0x041C
# define CCBUF_WRDS9                                                  (uint32)0x0420
# define CCBUF_WRDS10                                                 (uint32)0x0424
# define CCBUF_WRDS11                                                 (uint32)0x0428
# define CCBUF_WRDS12                                                 (uint32)0x042C
# define CCBUF_WRDS13                                                 (uint32)0x0430
# define CCBUF_WRDS14                                                 (uint32)0x0434
# define CCBUF_WRDS15                                                 (uint32)0x0438
# define CCBUF_WRDS16                                                 (uint32)0x043C
/************************************** end register defines *********************************************************/

/**\} */

/*** ERay limits ***/
# define CC_MAX_NUM_HW_BUFFERS                                        ((uint8)(128))
# define CC_MAX_NUM_PAYLOAD_BYTES                                     ((uint8)(254))
# define CC_MAX_NUM_PAYLOAD_16BIT_WORDS                               ((uint8)(16))
# define CC_MAX_NUM_TIMERS                                            2

/*** ErrorFlag defines ***/
# define CC_ERROR_ERRM_ACTIVE                                         ((uint32) 0x00000000 )
# define CC_ERROR_ERRM_PASSIVE                                        ((uint32) 0x00000001 << 1)
# define CC_ERROR_ERRM_COMMHALT                                       ((uint32) 0x00000001 << 2)
# define CC_ERROR_ERRM_RESERVED                                       ((uint32) 0x00000001 << 3)
# define CC_ERROR_COLDSTART                                           ((uint32) 0x00000001 << 4)
# define CC_ERROR_CLOCKCORRECTION                                     ((uint32) 0x00000001 << 5)
# define CC_ERROR_SYNCFRAME                                           ((uint32) 0x00000001 << 6)
# define CC_ERROR_SYNTAX_A                                            ((uint32) 0x00000001 << 7)
# define CC_ERROR_SYNTAX_B                                            ((uint32) 0x00000001 << 8)
# define CC_ERROR_CHANNEL_A                                           ((uint32) 0x00000001 << 9)
# define CC_ERROR_CHANNEL_B                                           ((uint32) 0x00000001 << 10)
# define CC_ERROR_LATESTTX_A                                          ((uint32) 0x00000001 << 11)
# define CC_ERROR_LATESTTX_B                                          ((uint32) 0x00000001 << 12)
# define CC_ERROR_SW_A                                                ((uint32) 0x00000001 << 14)
# define CC_ERROR_SW_B                                                ((uint32) 0x00000001 << 15)
# define CC_ERROR_NIT_A                                               ((uint32) 0x00000001 << 16)
# define CC_ERROR_NIT_B                                               ((uint32) 0x00000001 << 17)

/***** end of header file ********************************************************************************************/
#endif /* FR_ERAY_H */

