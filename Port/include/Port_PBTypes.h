/*============================================================================*/
/* Project      = AUTOSAR Renesas X1x MCAL Components                         */
/* Module       = Port_PBTypes.h                                              */
/*============================================================================*/
/*                                  COPYRIGHT                                 */
/*============================================================================*/
/* Copyright(c) 2012-2017 Renesas Electronics Corporation                     */
/*============================================================================*/
/* Purpose:                                                                   */
/* This file contains the type definitions of Post Build time Parameters      */
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

/*PORT_H_028: EAAR_PN0034_NR_0045, EAAR_PN0034_NR_0060*/
/*******************************************************************************
**                      Revision Control History                              **
*******************************************************************************/
/*
 * V1.0.0:  30-Aug-2012  : Initial Version
 *
 * V1.0.1:  27-Sep-2012  : As per SCR 018, PORT_WRITE_ERROR_CLEAR_VAL is updated
 *
 * V1.0.2:  17-Oct-2012  : As per SCR 027, structures added for Port filter
 *                         functionality.
 *
 * V1.1.0:  16-Jan-2013  : As per SCR 055, following changes are made:
 *                         1. PORT_IOHOLD_MASK and PORT_IOHOLD_CLEAR
 *                         are updated.
 *                         2. Copyright information is updated.
 *
 * V1.2.0:  12-Mar-2013  : As per SCR 091 for mantis #9240, following changes
 *                         are made:
 *                         1. New union type 'Port_Pin_DioOrAltMode' and
 *                            new structure type
 *                            'Port_PinDioAltChangeableDetails' is declared to
 *                            support functionality of new APIs
 *                            'Port_SetToDioMode' and 'Port_SetToAlternateMode'.
 *                         2. Ex-tern for 'Port_GstSetDioAltPinDetails[]' array
 *                            is declared.
 *
 * V1.3.0:  05-Aug-2013  : As per CR 225, as part of merging activity and mantis
 *                         issues #11827, #11215 and #11895, following changes
 *                         are made:
 *                         1. Structure STag_Port_EDCRegs is added to have
 *                            digital Noise filter edge detect control
 *                            functionality.
 *                         2. Header and Environment sections are updated to
 *                            change the device name.
 *                         3. Pre-compile option PORT_DNFAEN_REG_AVAILABLE is
 *                            added to have DNFAnEN register for F1x variant.
 *                         4. Offset's for PODC, PDSC, JPODC, JPDSC, PPROTS,
 *                            PPCMD, JPPROTS, JPPCMD registers and PORT_MAX_MODE
 *                            macro are removed and same will be generated by
 *                            generation tool in Port_Cfg.h file.
 *                         5. Macro PORT_WRITE_ERROR_CLEAR_VAL is removed and
 *                            same will be generated by generation tool as
 *                            32-bit value for F1x and 8-bit value for E1x in
 *                            Port_Cfg.h file.
 *
 * V1.4.0:  04-Sep-2013  : As per CR 236 for mantis issues #12602, Pre-compile
 *                         option 'PORT_PINV_REG_AVAILABLE' is added to have
 *                         Port pin level inversion functionality.
 *
 * V1.4.1:  29-Dec-2013  : As per CR 338, definitions are added for
 *                         PORT_SET_PIN_MODE_API.
 *
 * V1.4.2:  04-Jan-2014  : As per CR 378 for mantis #19208, as part of merging
 *                         activity following changes are made:
 *                         1. Copyright information is updated.
 *                         2. Alternative modes for Port_SetPinMode() API are
 *                            removed.
 *
 * V1.4.3:  06-Mar-2014  : As per CR419, PORT_WORD_ZERO is added.
 *
 * V1.4.4:  25-Jul-2014  : As per CR 563 for mantis #22811, as part of merging
 *                         activity, New structure 'STag_Port_DNFCKSRegs' is
 *                         added for digital filter.
 *
 * V1.4.5:  22-Aug-2014  : As per CR 570, following changes are made:
 *                         1. STag_Port_PinsDirChangeable is
 *                            modified to add new structure element
 *                            'ucPMSRRegIndex' to get PMSR index.
 *                         2. MISRA C Rule Violations are updated as per QAC
 *                            8.1.1.
 * V1.4.6:  28-Jan_2015  : As per mantis #24335,#24187 and #23493 following
 *                         changes are made :
 *                         1. STag_Port_PinModeChangeableGroups is modified
 *                            to add new structure element
 *                            'uint8 ucPIPCRegIndex' to get PIPC index.
 *                         2. Critical Section Macros are updated.
 *                         3. STag_Port_DNFARegs is modified to add new
 *                            structure element 'usDelay' for Digital Filter
 *                         4. STag_Port_PinDioAltChangeableDetails is modified
 *                            to add new structure element
 *                            'uint8 ucPortPIPCIndex' to get PIPC index.
 *                         5. Copyright information is updated.
 * 1.4.7:   12-Feb-2015  : As per merge activity(#26024), the macro
 *                         PORT_LSB_MASK is added
 * V1.4.8:  27-Feb-2016  : Following changes are made:
 *                         1. As per ARDAAAE-1018, a new macro,PORT_MODE_DIO
 *                            is added.
 *                         2. Copyright information is updated.
 *                         3. 'ul' changed to 'UL' to remove Misra warning
 * V1.4.9:  08-Aug-2016 : As Part of V4.01.01 release,Following changes
 *                        are done
 *                        1.As per ARDAAAE-1950,Macro PORT_DEM_ERROR_DETECT has
 *                          been removed
 *                        2.As per ARDAAAE-1949,Macros PORT_SIXTEEN,
 *                          PORT_SET_BYTE, PORT_SET_WORD
 *                          and PORT_SET_LONG_WORD are added.
 *                        3.Macro PORT_DBTOC_VALUE is modified for removing
 *                          MISRA violation 4:4397.
 *                        4.Unwanted Misra violations are removed.
 *                        5.As per ARDAAAE-912,usDNFAEN is changed to ucDNFAENL
 *                          in typedef Port_DNFARegs.
 *                        6.As per ARDAAAE-1908, ASR3.2.2 version information,
 *                          macros PORT_IOHOLD_MASK ,PORT_IOHOLD_CLEAR, the
 *                          structure declaration Port_EDCRegs and the external
 *                          variables related to analog,input,alpha ports are
 *                          removed.Port_GroupType is updated to remove the enum
 *                          values related to Alphabetic,Analog and Input ports
 *                        7.As per ARDAAAE-1936,unit design ID and requirement
 *                          tags are added at applicable places.
 *                        8.PORT_DNF_CLK_SRC_AVAILABLE switch is removed for
 *                          the structure STag_Port_DNFCKSRegs to avoid MISRA
 *                          violation.
 * V1.4.10:  31-Jan-2017 : 1.As per ARDAAAE-2191,updated the format of
 *                           requirement tags
 *                         2.As per ARDAAAE-2276,Macro PORT_DEM_TYPE is removed.
 *                           Added suffix "U" to all the macros.Global arrays
 *                           are made dimensional.Structure name is updated in
 *                           the union Port_Pin_DioOrAltMode to make it unique.
 *                           Macro PORT_LONG_WORD_ZERO is added.Tagname is
 *                           added for the structure inside the union
 *                           Port_Pin_DioOrAltMode and Port_Pin_Direction
 */
/******************************************************************************/
/*PORT_H_029: AR_PN0062_FR_0001, EAAR_PN0034_FR_0052, AR_PN0062_FR_0005*/
/*PORT_H_030: EAAR_PN0034_NR_0001, EAAR_PN0034_NR_0012, EAAR_PN0034_NR_0018*/
/*PORT_H_031: EAAR_PN0034_NR_0056, EAAR_PN0034_NR_0069, EAAR_PN0034_NR_0020*/
/*PORT_H_032: EAAR_PN0034_FR_0021, EAAR_PN0034_NR_0007*/
#ifndef PORT_PBTYPES_H
#define PORT_PBTYPES_H

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/
/* Included for module version information */
#include "Port.h"
/*******************************************************************************
**                      Version Information                                   **
*******************************************************************************/
/* AUTOSAR release version information */
#define PORT_PBTYPES_AR_RELEASE_MAJOR_VERSION  PORT_AR_RELEASE_MAJOR_VERSION
#define PORT_PBTYPES_AR_RELEASE_MINOR_VERSION  PORT_AR_RELEASE_MINOR_VERSION
#define PORT_PBTYPES_AR_RELEASE_REVISION_VERSION \
                                            PORT_AR_RELEASE_REVISION_VERSION

/* File version information */
#define PORT_PBTYPES_SW_MAJOR_VERSION  PORT_SW_MAJOR_VERSION
#define PORT_PBTYPES_SW_MINOR_VERSION  PORT_SW_MINOR_VERSION

/*PORT_H_033: EAAR_PN0034_NR_0002, EAAR_PN0034_NR_0026, PORT129, PORT207*/
/*******************************************************************************
**                      MISRA C Rule Violations                               **
*******************************************************************************/

/* 1. MISRA C RULE VIOLATION:                                                 */
/*Message        : (4:0750) A union type specifier has been defined.          */
/*Rule           : MISRA-C:2004 Rule 17.4                                     */
/*Justification  : union type specifier is used to achieve better throughput. */
/*Verification   : However, part of the code is verified manually and it is   */
/*                 not having any impact.                                     */
/*Reference      : Look for MISRA Violation: START Msg(4:0750)-1 and          */
/*                 MISRA Violation: END Msg(4:0750)-1                         */
/*                 tags in the code.                                          */

/******************************************************************************/

/* 2. MISRA C RULE VIOLATION:                                                 */
/*Message        : (4:3684) Array declared with unknown size.                 */
/*Rule           : MISRA-C:2004 Rule 17.4                                     */
/*Justification  : Subscripting cannot be applied on the array since size can */
/*                 grow based on configuration done by user i.e. multi        */
/*                 configuration                                              */
/*Verification   : However, part of the code is verified manually and it is   */
/*                 not having any impact.                                     */
/*Reference      : Look for MISRA Violation: START Msg(4:3684)-2 and          */
/*                 MISRA Violation: END Msg(4:3684)-2                         */
/*                 tags in the code.                                          */
/******************************************************************************/
/**                         QAC Warnings                                     **/
/******************************************************************************/
/* 1.  QAC Warning:                                                           */
/* Message       : (2:1314) A struct or union tag has been defined within the */
/*                 definition of another struct or union.                     */
/* Rule          : NA                                                         */
/* Justification : Port_Pin_Direction and Port_Pin_DioOrAltMode are union type*/
/*                 In code, for better efficiency,optimization and            */
/*                 accessibility the registers access is split as 8-bit,      */
/*                 16-bit. Hence the structure defined inside union cannot    */
/*                 be avoided.                                                */
/* Verification  : However, part of the code is verified manually and it is   */
/*                 not having any impact.                                     */
/* Reference     : Look for START Msg(2:1314)-1 and                           */
/*                 END Msg(2:1314)-1 tags in the code.                        */
/******************************************************************************/

/*******************************************************************************
**                      Global Symbols                                        **
*******************************************************************************/
/* General defines */
#define PORT_DBTOC_VALUE  ((((uint32)PORT_VENDOR_ID_VALUE)<< (uint8)22)| \
                           (((uint32)PORT_MODULE_ID_VALUE)<< (uint8)14)| \
                           (((uint32)PORT_SW_MAJOR_VERSION_VALUE) <<(uint8)8)| \
                           (((uint32)PORT_SW_MINOR_VERSION_VALUE) <<(uint8)3))
/* PORT_H_034: PORT_ESDD_UD_103*/
#define PORT_ZERO                      (uint8)0x00U
#define PORT_ONE                       (uint8)0x01U
#define PORT_TEN                       (uint8)0x0AU
#define PORT_SIXTEEN                   (uint8)0x10U

#define PORT_MODE_MASK                 (uint8)0x1FU
#define SET_PIPC_MIN_MODE              (uint8)0x82U
#define PORT_UNINITIALIZED             (boolean)0x00
#define PORT_INITIALIZED               (boolean)0x01
#define PORT_REG_NOTAVAILABLE          (uint8)0xFFU

#define PORT_SET_BYTE                  (uint8)0xFFU
#define PORT_SET_WORD                  (uint16)0xFFFFU
#define PORT_SET_LONG_WORD             (uint32)0xFFFFFFFFUL
#define PORT_LONG_WORD_ONE             (uint32)0x00000001UL

#define PORT_MSB_MASK                  (uint32)0xFFFF0000UL
#define PORT_LSB_MASK                  (uint32)0x0000FFFFUL

#if (PORT_SET_PIN_MODE_API == STD_ON)
#define PORT_DIO_OUT                   (Port_PinModeType)0x00U
#define PORT_DIO_IN                    (Port_PinModeType)0x01U
#endif

#define PORT_MODE_DIO                  (Port_PinModeType)0x00U

#define PORT_MODE_ADJUST               (Port_PinModeType)0x0EU

#define PORT_TRUE                      (boolean)0x01
#define PORT_FALSE                     (boolean)0x00

#define PORT_INV_NOT_CFG               (uint16)0xFFFFU
#define PORT_WORD_ZERO                 (uint16)0x0000U
#define PORT_LONG_WORD_ZERO            (uint32)0x00000000UL

#define PORT_ENTER_CRITICAL_SECTION(Exclusive_Area) \
                                              SchM_Enter_Port_##Exclusive_Area()
#define PORT_EXIT_CRITICAL_SECTION(Exclusive_Area) \
                                              SchM_Exit_Port_##Exclusive_Area()


/*******************************************************************************
**  Global symbols used for For verifying the Modes
*******************************************************************************/
#define PORT_BIT4_MASK                 (uint8)0x10U  /* For PMC */
#define PORT_BIT3_MASK                 (uint8)0x08U  /* For PFCAE */
#define PORT_BIT2_MASK                 (uint8)0x04U  /* For PFCE */
#define PORT_BIT1_MASK                 (uint8)0x02U  /* For PFC */
#define PORT_BIT0_MASK                 (uint8)0x01U  /* For PM */

/*******************************************************************************
**                      Global Data Types                                     **
*******************************************************************************/
/* Type definition for Port Group types */
/*PORT_H_035: PORT_ESDD_UD_112*/
typedef enum ETag_Port_GroupType
{
  PORT_GROUP_NUMERIC,
  PORT_GROUP_JTAG
} Port_GroupType;

/* MISRA Violation: START Msg(4:0750)-1 */
/*PORT_H_082: PORT_ESDD_UD_134*/
/* Type definition for 32-bit PMSR register */
typedef union UTag_Port_Pin_Direction
{
/* MISRA Violation: END Msg(4:0750)-1 */
  /* Full Word */
  uint32 ulRegContent;
  /* QAC Warning: START Msg(2:1314)-1 */
  struct STag_Tst_Pin_Dir_ByteAccess
  {
  /* QAC Warning: END Msg(2:1314)-1 */
    /* Lower Word */
    uint16 usLSWord;
    /* Higher Word */
    uint16 usMSWord;
  }Tst_Port_Word;
} Port_Pin_Direction;

/* MISRA Violation: START Msg(4:0750)-1 */
/*PORT_H_081: PORT_ESDD_UD_133*/
/* Type definition for 32-bit PMCSR register */
typedef union UTag_Port_Pin_DioOrAltMode
{
/* MISRA Violation: END Msg(4:0750)-1 */
  /* Full Word */
  uint32 ulRegContent;
  /* QAC Warning: START Msg(2:1314)-1 */
  struct STag_Tst_DioOrAlt_ByteAccess
  {
  /* QAC Warning: END Msg(2:1314)-1 */
    /* Lower Word */
    uint16 usLSWord;
    /* Higher Word */
    uint16 usMSWord;
  }Tst_Port_DioOrAlt_Word;
} Port_Pin_DioOrAltMode;

/*******************************************************************************
** Structure declaration of port group registers, except PMSR, PFCE, PFC      **
** and PMCSR.                                                                 **
** This structure will be generated in the following sequence of registers:   **
** PSR, PIS, PISE, PISA, PIBC, PIPC, PU, PD, PBDC, PODC and PDSC.             **
*******************************************************************************/
/*PORT_H_036: PORT_ESDD_UD_075*/
typedef struct STag_Port_Regs
{
  /* Offset value of the register address. This value of any register, when
   * added to the base address, gives the address of that particular register.
   */
  uint16 usRegAddrOffset;
  /* Configured value of the port group registers for initial mode. */
  uint16 usInitModeRegVal;
} Port_Regs;

/*******************************************************************************
** Structure declaration of PFCE, PFC and PMCSR port group registers          **
** This structure will be generated in the following sequence of registers:   **
** PFCE, PFC and PMCSR.                                                       **
*******************************************************************************/
/*PORT_H_037: PORT_ESDD_UD_076*/
typedef struct STag_Port_FuncCtrlRegs
{
  /*
   * Offset value of the register address. This value of any register, when
   * added to the base address, gives the address of that particular register.
   */
  uint16 usRegAddrOffset;
  /* Configured value of the port group registers for initial mode. */
  uint16 usInitModeRegVal;
} Port_FuncCtrlRegs;

/*******************************************************************************
** Structure declaration of PMSR registers for all port groups                **
*******************************************************************************/
/*PORT_H_038: PORT_ESDD_UD_077*/
typedef struct STag_Port_PMSRRegs
{
  /* Bit value of upper 16 bits (31 - 16) is to set 0 if for pin
   * "PortPinDirectionChangeable" is configured as true
   * Bit value of upper 16 bits (31 - 16) is to set 1 if for pin
   * "PortPinDirectionChangeable" configured as false
   * Bit value of lower 16 bits (15 - 0) = Initial value of the corresponding
   * pin
   */
  uint32 ulMaskAndConfigValue;
  /* Offset value of the PMSR register address. This value of any register, when
   * added to the base address, gives the address of that particular register.
   */
  uint16 usRegAddrOffset;
  /* Configured PMSR Register value for initial mode */
  uint16 usInitModeRegVal;
} Port_PMSRRegs;

/*******************************************************************************
** Structure containing information on PINs whose direction can be changed    **
** during run time                                                            **
*******************************************************************************/
#if (PORT_SET_PIN_DIRECTION_API == STD_ON)
/*PORT_H_039: PORT_ESDD_UD_078*/
typedef struct STag_Port_PinsDirChangeable
{
  /* The PIN number whose direction is configured as changeable at run time */
  Port_PinType ddPinId;
  /* Offset value of the PMSR register address. This value of any register, when
   * added to the base address, gives the address of that particular register.
   */
  uint16 usPMSRRegAddrOffset;
  /*
   * Offset value of the PSR register address. This value of any register, when
   * added to the base address, gives the address of that particular register.
   */
  uint16 usPSRRegAddrOffset;
  #if (PORT_PINV_REG_AVAILABLE == STD_ON)
  /* Offset value of the PMSR register address. This value of any register, when
   * added to the base address, gives the address of that particular register.
   */
  uint16 usPINVRegAddrOffset;
  /* Configured level value for PSR register */
  uint16 usPortinversionVal;
  /* Index of the structure array Port_GstNumFuncCtrlRegs[], which provide the
   * information of the PMCSR register of the port group to which this pin
   * belongs.
   */
  uint8 ucPortGroupIndex;
  #endif /* End of PORT_PINV_REG_AVAILABLE == STD_ON */
  /* Mask value to check whether the requested direction and current direction
   * of the PIN are same.
   */
  uint16 usOrMaskVal;
  /* Configured level value for PSR register */
  uint16 usChangeableConfigVal;
  /* Indicates the Port type (Numeric/ Alphabetic/ JTAG/ Analog) */
  uint8 ucPortType;
  /* Index of PMSR register in the structure array of PMSR registers.*/
  uint8 ucPMSRRegIndex;
} Port_PinsDirChangeable;
#endif /* End of PORT_SET_PIN_DIRECTION_API == STD_ON */

/*******************************************************************************
** Structure contains information about the port groups, containing the PINs  **
** whose mode can be changed during run time.                                 **
*******************************************************************************/
#if (PORT_SET_PIN_MODE_API == STD_ON)
/*PORT_H_040: PORT_ESDD_UD_079*/
typedef struct STag_Port_PinModeChangeableGroups
{

  /* Index of the PSR register in the structure array, where all port group
   * registers, except PMSR, are generated.
   */
  uint8 ucPSRRegIndex;
  /* Index of the PFCE register in the structure array, where all port group
   * registers, except PMSR, are generated.
   */
  uint8 ucPFCERegIndex;
  /* Index of the PFC register in the structure array, where all port group
   * registers, except PMSR, are generated.
   */
  uint8 ucPFCRegIndex;
  /* Index of the PFCAE register in the structure array, where all port group
   * registers, except PMSR, are generated.
   */
  uint8 ucPFCAERegIndex;
  /* Index of the PMCSR register in the structure array, where all port group
   * registers, except PMSR, are generated.
   */
  uint8 ucPMCSRRegIndex;
  /* Index of PMSR register in the structure array of PMSR registers.*/
  uint8 ucPMSRRegIndex;
  /* Index of the PIPC register in the structure array, where all port group
   * registers, except PMSR, are generated.
   */
  uint8 ucPIPCRegIndex;
} Port_PinModeChangeableGroups;
#endif /* End of PORT_SET_PIN_MODE_API == STD_ON */

/*******************************************************************************
** Structure contains details of PINs whose mode can be changed during run    **
** time.                                                                      **
*******************************************************************************/
#if (PORT_SET_PIN_MODE_API == STD_ON)
/*PORT_H_041: PORT_ESDD_UD_080*/
typedef struct STag_Port_PinModeChangeableDetails
{
  /* The PIN number whose mode is configured as changeable at run time. */
  Port_PinType ddPinId;
  /* Or mask value of the port pin */
  uint16 usOrMask;
  /* Index of the structure array which provide the information of port groups,
   * containing the PINs whose mode can be changed during run time
   */
  uint8 ucSetModeIndex;
  /* Indicates the Port type (Numeric/ Alphabetic/ JTAG/ Analog/ Input)  */
  uint8 ucPortType;
} Port_PinModeChangeableDetails;
#endif /* End of PORT_SET_PIN_MODE_API == STD_ON */

/*******************************************************************************
** Structure contains details of PINs whose mode can be changed to DIO or     **
** alternate mode during runtime.                                             **
*******************************************************************************/
#if (PORT_SET_TO_DIO_ALT_MODE_API == STD_ON)
/*PORT_H_042: PORT_ESDD_UD_072*/
typedef struct STag_Port_PinDioAltChangeableDetails
{
  /* The PIN number whose mode is configured as changeable at run time. */
  Port_PinType ddPinId;
  /* Or mask value of the port pin */
  uint16 usOrMask;
  /* Index of the structure array Port_GstNumFuncCtrlRegs[], which provide the
   * information of the PMCSR register of the port group to which this pin
   * belongs.
   */
  uint8 ucPortGroupIndex;
  /* Indicates the Port type (Numeric/ Alphabetic/ JTAG/ Analog/ Input)  */
  uint8 ucPortType;
  /* Index of the PIPC register in the structure array */
  uint8 ucPortPIPCIndex;
} Port_PinDioAltChangeableDetails;
#endif /* End of PORT_SET_PIN_MODE_API == STD_ON */

/*******************************************************************************
** Structure contains the declaration for DNFA registers                      **
** This structure will be generated in the following sequence of registers:   **
** DNFAnCTL, DNFAnEN.                                                         **
*******************************************************************************/
/*PORT_H_043: PORT_ESDD_UD_070*/
typedef struct STag_Port_DNFARegs
{
  /* Offset value of the DNFACTL register address. This value of any register,
   * if added to the base address, gives the address of that particular register
   */
  uint16 usDNFARegAddrOffset;
  #if (PORT_DNFAEN_REG_AVAILABLE == STD_ON)
  /* Configured value for DNFA noise elimination enable register */
  uint8 ucDNFAENL;
  #endif /* End of PORT_DNFAEN_REG_AVAILABLE == STD_ON */
  /* Configured value for DNFA noise elimination control register */
  uint8 ucDNFACTL;

  uint16 usDELAY;
} Port_DNFARegs;

/*******************************************************************************
** Structure contains the declaration for FCLA registers                      **
** This structure will be generated in the following sequence of registers:   **
** FCLAnCTL.                                                                  **
*******************************************************************************/
/*PORT_H_044: PORT_ESDD_UD_071*/
typedef struct STag_Port_FCLARegs
{
  /* Offset value of the FLCACTL register address. This value of any register,
   * if added to the base address, gives the address of that particular register
   */
  uint16 usFCLARegAddrOffset;
  /* Configured value for FCLA noise elimination control register */
  uint8 ucFCLACTL;
} Port_FCLARegs;

/*******************************************************************************
** Structure contains the declaration for DNFCKS register                     **
** This structure will be generated in the following sequence                 **
*******************************************************************************/
/*PORT_H_045: PORT_ESDD_UD_089*/
typedef struct STag_Port_DNFCKSRegs
{
  /* Configured value for DNFA noise elimination control register */
  uint32 ulDNFCKS;
  /* Offset value of the DNFCKS register address. This value of any register,
   * if added to the base address, gives the address of that particular register
   */
  uint16 usDNFCKSRegAddrOffset;
} Port_DNFCKSRegs;


/*******************************************************************************
**                       Extern declarations for Global Data                  **
*******************************************************************************/
#define PORT_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "MemMap.h"

/*PORT_H_046: PORT_ESDD_UD_108*/
#if (PORT_NUM_PORT_GROUPS_AVAILABLE == STD_ON)
/*PORT_H_084: PORT_ESDD_UD_136*/
extern CONST(Port_Regs, PORT_CONST) Port_GstNumRegs[PORT_NUM_REGS_ARRAY_SIZE];
/*PORT_H_085: PORT_ESDD_UD_137*/
extern CONST(Port_FuncCtrlRegs, PORT_CONST)
                       Port_GstNumFuncCtrlRegs[PORT_NUM_FUNC_REGS_ARRAY_SIZE];
/*PORT_H_086: PORT_ESDD_UD_138*/
extern CONST(Port_PMSRRegs, PORT_CONST)
                           Port_GstNumPMSRRegs[PORT_NUM_PMSR_REGS_ARRAY_SIZE];
#endif

#if (PORT_JTAG_PORT_GROUPS_AVAILABLE == STD_ON)
/*PORT_H_087: PORT_ESDD_UD_139*/
extern CONST(Port_Regs, PORT_CONST)
                                  Port_GstJTAGRegs[PORT_JTAG_REGS_ARRAY_SIZE];
/*PORT_H_088: PORT_ESDD_UD_140*/
extern CONST(Port_FuncCtrlRegs, PORT_CONST)
                     Port_GstJTAGFuncCtrlRegs[PORT_JTAG_FUNC_REGS_ARRAY_SIZE];
/*PORT_H_089: PORT_ESDD_UD_141*/
extern CONST(Port_PMSRRegs, PORT_CONST)
                         Port_GstJTAGPMSRRegs[PORT_JTAG_PMSR_REGS_ARRAY_SIZE];
#endif

/* MISRA Violation: START Msg(4:3684)-2 */
#if (PORT_SET_PIN_DIRECTION_API == STD_ON)
extern CONST(Port_PinsDirChangeable, PORT_CONST)
                                               Port_GstPinDirChangeableList[];
#endif

#if (PORT_SET_TO_DIO_ALT_MODE_API == STD_ON)
extern CONST(Port_PinDioAltChangeableDetails, PORT_CONST)
                                                Port_GstSetDioAltPinDetails[];
#endif

#if (PORT_SET_PIN_MODE_API == STD_ON)
extern CONST(Port_PinModeChangeableGroups, PORT_CONST)
                                                  Port_GstSetModeGroupsList[];
extern CONST (Port_PinModeChangeableDetails, PORT_CONST)
                                              Port_GstSetModePinDetailsList[];
#endif

extern CONST(Port_DNFARegs, PORT_CONST)
                                  Port_GstDNFARegs[];
extern CONST(Port_FCLARegs, PORT_CONST)
                                  Port_GstFCLARegs[];
/* MISRA Violation: END Msg(4:3684)-2 */

#if (PORT_DNF_CLK_SRC_AVAILABLE == STD_ON)
/*PORT_H_090: PORT_ESDD_UD_142*/
extern CONST(Port_DNFCKSRegs, PORT_CONST)
                              Port_GstDNFCKSRegs[PORT_DNFCKS_REGS_ARRAY_SIZE];
#endif


#define PORT_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "MemMap.h"



#endif /* PORT_PBTYPES_H  */


/*******************************************************************************
**                      End of File                                           **
*******************************************************************************/
