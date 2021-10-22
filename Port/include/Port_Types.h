/*============================================================================*/
/* Project      = AUTOSAR Renesas X1x MCAL Components                         */
/* Module       = Port_Types.h                                                */
/*============================================================================*/
/*                                  COPYRIGHT                                 */
/*============================================================================*/
/* Copyright(c) 2012-2017 Renesas Electronics Corporation                     */
/*============================================================================*/
/* Purpose:                                                                   */
/* Provision of Database declaration.                                         */
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
/*              Devices:        X1x                                           */
/*============================================================================*/

/*PORT_H_064: EAAR_PN0034_NR_0045*/
/*******************************************************************************
**                      Revision Control History                              **
*******************************************************************************/
/*
 * V1.0.0:  30-Aug-2012  : Initial Version
 *
 * V1.0.1:  17-Oct-2012  : As per SCR 027, STag_Port_ConfigType structure is
 *                         updated to add filter registers.
 *
 * V1.1.0:  16-Jan-2013  : As per SCR 055, following changes are made:
 *                         1. STag_Port_ConfigType structure is
 *                         updated.
 *                         2. Copyright information is updated.
 *
 * V1.2.0:  12-Mar-2013  : As per SCR 091 for mantis #9240, new structure
 *                         elements 'pPinDioAltModeDetails' and
 *                         'ucNoOfPinsDioAltModeChangeable' are added in
 *                         STag_Port_ConfigType structure.
 *
 * V1.3.0:  05-Aug-2013  : As per CR 225, as part of merging activity and mantis
 *                         issues #11827, #11215 and #11895, following changes
 *                         are made:
 *                         1. Header and Environment sections are updated to
 *                            change the device name.
 *                         2. Pre-compile option PORT_EDGE_DETECT_CONTROL is
 *                            added to have digital Noise filter edge detect
 *                            control functionality.
 *
 * V1.3.1:  25-Jul-2014  : As per CR 563 for mantis #22811, as part of merging
 *                         activity, new structure elements 'pPortDNFCKSRegs'
 *                         and 'ucNoOfDNFCKSRegs' are added in
 *                         STag_Port_ConfigType structure.
 * V1.3.2:  11-Mar-2016  : Following changes are done
 *                         1.Copyright information is updated.
 *                         2.As per ARDAAAE-1486, in structure
 *                           Port_ConfigType, memory class of pointer variables
 *                           changed from AUTOMATIC to TYPEDEF.
 *                         3.As per ARDAAAE-1545, in structure
 *                           Port_ConfigType, macros PORT_DNFA_REG_CONFIG
 *                           PORT_FCLA_REG_CONFIG and PORT_DNF_CLK_SRC_AVAILABLE
 *                           are removed to remove ERR124001 for multiple config
 *                           sets.
 * V1.3.3:  08-Aug-2016 : As Part of V4.01.01 release,Following changes
 *                         are done
 *                        1. As per ARDAAAE-1908, ASR3.2.2 version information,
 *                           structure members pPortEDCRegs,ucNoOfEDCRegs,
 *                           ucNoOfNumRestoredRegs, ucNoOfAlphaRestoredRegs,
 *                           ucNoOfAnalogRestoredRegs and members related to
 *                           analog,input,alpha ports inside Port_ConfigType
 *                           are removed.
 *                        2. As per ARDAAAE-1936,unit design ID and requirement
 *                           tags are added at applicable places.
 * V1.3.4:  24-Jan-2017 :  As per ARDAAAE-2191,updated the format of requirement
 *                         tags
 *
 */
/******************************************************************************/
/*PORT_H_065: EAAR_PN0034_NR_0001, EAAR_PN0034_NR_0012, EAAR_PN0034_NR_0018*/
/*PORT_H_066: EAAR_PN0034_NR_0056, EAAR_PN0034_NR_0069, EAAR_PN0034_NR_0020*/
/*PORT_H_067: AR_PN0062_FR_0001, AR_PN0062_FR_0005, EAAR_PN0034_NR_0007*/
#ifndef PORT_TYPES_H
#define PORT_TYPES_H

/*******************************************************************************
**                     Include Section                                        **
*******************************************************************************/
/* Included for pre-compile options */
/* PORT_H_068: PORT130, PORT108, EAAR_PN0034_FR_0055, EAAR_PN0034_FR_0001*/
/* PORT_H_069: EAAR_PN0034_FR_0052, EAAR_PN0034_FR_0020, EAAR_PN0034_FR_0021*/
/* PORT_H_070: EAAR_PN0034_NR_0007, PORT129, PORT207*/
#include "Port_Cfg.h"

/*******************************************************************************
**                        Version Information                                 **
*******************************************************************************/
/* AUTOSAR release version information */
#define PORT_TYPES_AR_RELEASE_MAJOR_VERSION    PORT_AR_RELEASE_MAJOR_VERSION
#define PORT_TYPES_AR_RELEASE_MINOR_VERSION    PORT_AR_RELEASE_MINOR_VERSION
#define PORT_TYPES_AR_RELEASE_REVISION_VERSION \
                                     PORT_AR_RELEASE_REVISION_VERSION

/* Module Software version information */
#define PORT_TYPES_SW_MAJOR_VERSION    PORT_SW_MAJOR_VERSION
#define PORT_TYPES_SW_MINOR_VERSION    PORT_SW_MINOR_VERSION

/*******************************************************************************
**                      GLOBAL DATA TYPES                                     **
*******************************************************************************/
/* Structure for Port Init Configuration */
/* PORT_H_071: PORT073, PORT072 */
/* Overall Module Configuration Data Structure */

/* PORT_H_072: PORT_ESDD_UD_074*/
typedef struct STag_Port_ConfigType
{
  /* Database start value - 0x0EDF0400 */
  uint32 ulStartOfDbToc;

  #if (PORT_NUM_PORT_GROUPS_AVAILABLE == STD_ON)
  /* Pointer to structure of Numeric Port Group registers in sequence: PSR,
   * PIS, PISE, PISA, PIBC, PIPC, PU, PD, PBDC, PODC and PDSC.
   */
  P2CONST(struct STag_Port_Regs, TYPEDEF, PORT_CONFIG_CONST) pPortNumRegs;

  /* Pointer to structure of Numeric Function Control Port Group registers
   * in sequence: PFCE, PFC, PFCAE and PMCSR
   */
  P2CONST(struct STag_Port_FuncCtrlRegs, TYPEDEF, PORT_CONFIG_CONST)
                                                       pPortNumFuncCtrlRegs;

  /* Pointer to structure of Numeric PMSR Port Group registers */
  P2CONST(struct STag_Port_PMSRRegs, TYPEDEF, PORT_CONFIG_CONST)
                                                       pPortNumPMSRRegs;
  #endif

  #if (PORT_JTAG_PORT_GROUPS_AVAILABLE == STD_ON)
  /* Pointer to structure of JTAG Port Group registers in sequence:
   * PSR, PIS, PISE, PISA, PIBC, PIPC, PU, PD, PBDC, PODC and PDSC.
   */
  P2CONST(struct STag_Port_Regs, TYPEDEF, PORT_CONFIG_CONST) pPortJRegs;

  /* Pointer to structure of JTAG Function Control Port Group registers in
   * sequence: PFCE, PFC, PFCAE and PMCSR
   */
  P2CONST(struct STag_Port_FuncCtrlRegs, TYPEDEF, PORT_CONFIG_CONST)
                                                       pPortJFuncCtrlRegs;

  /* Pointer to structure of JTAG PMSR Port Group registers */
  P2CONST(struct STag_Port_PMSRRegs, TYPEDEF, PORT_CONFIG_CONST)
                                                       pPortJPMSRRegs;
  #endif

  #if (PORT_SET_PIN_DIRECTION_API == STD_ON)
  /* Pointer to structure containing details about the pins whose direction
   * can be changed during run time
   */
  P2CONST(struct STag_Port_PinsDirChangeable, TYPEDEF, PORT_CONFIG_CONST)
                                                       pPinDirChangeable;
  #endif

  #if (PORT_SET_PIN_MODE_API == STD_ON)
  /* Pointer to structure containing details about the port pin mode */
  P2CONST(struct STag_Port_PinModeChangeableGroups, TYPEDEF,
                              PORT_CONFIG_CONST) pPinModeChangeableGroups;
  /* Pointer to structure containing details about the port pin mode */
  P2CONST(struct STag_Port_PinModeChangeableDetails, TYPEDEF,
                              PORT_CONFIG_CONST) pPinModeChangeableDetails;
  #endif

  #if (PORT_SET_TO_DIO_ALT_MODE_API == STD_ON)
  /* Pointer to structure containing details about the port dio or alternate
   * pin mode
   */
  P2CONST(struct STag_Port_PinDioAltChangeableDetails, TYPEDEF,
                              PORT_CONFIG_CONST) pPinDioAltModeDetails;
  #endif

  /* Pointer to array of structure containing details about DNFA registers */
  P2CONST(struct STag_Port_DNFARegs, TYPEDEF, PORT_CONFIG_CONST)
                                                 pPortDNFARegs;

  /* Pointer to array of structure containing details about FCLA registers */
  P2CONST(struct STag_Port_FCLARegs, TYPEDEF, PORT_CONFIG_CONST)
                                                 pPortFCLARegs;

  /* Pointer to array of structure containing details about DNFCKS registers */
  P2CONST(struct STag_Port_DNFCKSRegs, TYPEDEF, PORT_CONFIG_DATA)
                                                            pPortDNFCKSRegs;

  #if (PORT_SET_PIN_DIRECTION_API == STD_ON)
  /* The Total number of Pins configured for Direction Change at run time. */
  uint8 ucNoOfPinsDirChangeable;
  #endif

  #if (PORT_SET_PIN_MODE_API == STD_ON)
  /* The Total number of Pins configured for Mode Change at run time. */
  uint8 ucNoOfPinsModeChangeable;
  #endif

  #if (PORT_SET_TO_DIO_ALT_MODE_API == STD_ON)
  /*
   * The Total number of Pins configured for Dio or Alternate Mode
   * changeable at run time.
   */
  uint8 ucNoOfPinsDioAltModeChangeable;
  #endif

  /* The total number of DNFA noise elimination registers configured */
  uint8 ucNoOfDNFARegs;

  /* The total number of FCLA noise elimination registers configured */
  uint8 ucNoOfFCLARegs;

  /* The total number of DNFCKS noise elimination registers configured */
  uint8 ucNoOfDNFCKSRegs;
} Port_ConfigType;

#endif /* PORT_TYPES_H */

/*******************************************************************************
**                          End Of File                                       **
*******************************************************************************/
