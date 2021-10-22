/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *          File:  DemWrapper.c
 *        Config:  D:/usr/usage/Delivery/CBD17x/CBD1700369/D04/external/Applications/OEM_Extensions/EPS/EPS.dpa
 *     SW-C Type:  DemWrapper
 *  Generated at:  Tue Dec 19 13:12:27 2017
 *
 *     Generator:  MICROSAR RTE Generator Version 4.16.0
 *                 RTE Core Version 1.16.0
 *       License:  Unlimited license CBD1700369 for Nxtr Automotive Corporation
 *
 *   Description:  C-Code implementation template for SW-C <DemWrapper>
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of version logging area >>                DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

/* PRQA S 0777, 0779 EOF */ /* MD_MSR_5.1_777, MD_MSR_5.1_779 */

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
 * Dem_DTCFormatType
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * Dem_DTCFormatType
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * Dem_DTCFormatType
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * Dem_DTCOriginType
 *   uint16 represents integers with a minimum value of 0 and a maximum value of 65535.
 *      The order-relation on uint16 is: x < y if y - x is positive.
 *      uint16 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 1267, +10000.
 *
 * Dem_DTCOriginType
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * Dem_EventIdType
 *   uint16 represents integers with a minimum value of 0 and a maximum value of 65535.
 *      The order-relation on uint16 is: x < y if y - x is positive.
 *      uint16 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 1267, +10000.
 *
 * Dem_EventIdType
 *   uint16 represents integers with a minimum value of 0 and a maximum value of 65535.
 *      The order-relation on uint16 is: x < y if y - x is positive.
 *      uint16 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 1267, +10000.
 *
 *********************************************************************************************************************/

#include "Rte_DemWrapper.h" /* PRQA S 0857 */ /* MD_MSR_1.1_857 */


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of include and declaration area >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/


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
 * Dem_EventIdType: Integer in interval [1...65535]
 * Dem_EventIdType: Integer in interval [1...73]
 * boolean: Boolean (standard type)
 * uint16: Integer in interval [0...65535] (standard type)
 * uint32: Integer in interval [0...4294967295] (standard type)
 * uint8: Integer in interval [0...255] (standard type)
 *
 * Enumeration Types:
 * ==================
 * Dem_DTCFormatType: Enumeration of integer in interval [0...255] with enumerators
 *   DEM_DTC_FORMAT_OBD (0U)
 *   DEM_DTC_FORMAT_UDS (1U)
 *   DEM_DTC_FORMAT_J1939 (2U)
 * Dem_DTCFormatType: Enumeration of integer in interval [0...2] with enumerators
 *   DEM_DTC_FORMAT_OBD (0U)
 *   DEM_DTC_FORMAT_UDS (1U)
 *   DEM_DTC_FORMAT_J1939 (2U)
 * Dem_DTCFormatType: Enumeration of integer in interval [0...2] with enumerators
 *   DEM_DTC_FORMAT_OBD (0U)
 *   DEM_DTC_FORMAT_UDS (1U)
 *   DEM_DTC_FORMAT_J1939 (2U)
 * Dem_DTCOriginType: Enumeration of integer in interval [0...65535] with enumerators
 *   DEM_DTC_ORIGIN_PRIMARY_MEMORY (1U)
 *   DEM_DTC_ORIGIN_MIRROR_MEMORY (2U)
 *   DEM_DTC_ORIGIN_PERMANENT_MEMORY (3U)
 *   DEM_DTC_ORIGIN_OBD_RELEVANT_MEMORY (4U)
 *   DEM_DTC_ORIGIN_SECONDARY_MEMORY (5U)
 *   DEM_DTC_ORIGIN_USERDEFINED_MEMORY_10 (5U)
 *   DEM_DTC_ORIGIN_USERDEFINED_MEMORY_11 (5U)
 *   DEM_DTC_ORIGIN_USERDEFINED_MEMORY_12 (5U)
 *   DEM_DTC_ORIGIN_USERDEFINED_MEMORY_13 (5U)
 *   DEM_DTC_ORIGIN_USERDEFINED_MEMORY_14 (5U)
 *   DEM_DTC_ORIGIN_USERDEFINED_MEMORY_15 (5U)
 *   DEM_DTC_ORIGIN_USERDEFINED_MEMORY_16 (5U)
 *   DEM_DTC_ORIGIN_USERDEFINED_MEMORY_17 (5U)
 *   DEM_DTC_ORIGIN_USERDEFINED_MEMORY_18 (5U)
 *   DEM_DTC_ORIGIN_USERDEFINED_MEMORY_19 (5U)
 *   DEM_DTC_ORIGIN_USERDEFINED_MEMORY_1A (5U)
 *   DEM_DTC_ORIGIN_USERDEFINED_MEMORY_1B (5U)
 *   DEM_DTC_ORIGIN_USERDEFINED_MEMORY_1C (5U)
 *   DEM_DTC_ORIGIN_USERDEFINED_MEMORY_1D (5U)
 *   DEM_DTC_ORIGIN_USERDEFINED_MEMORY_1E (5U)
 *   DEM_DTC_ORIGIN_USERDEFINED_MEMORY_1F (5U)
 *   DEM_DTC_ORIGIN_USERDEFINED_MEMORY_20 (5U)
 *   DEM_DTC_ORIGIN_USERDEFINED_MEMORY_21 (5U)
 *   DEM_DTC_ORIGIN_USERDEFINED_MEMORY_22 (5U)
 *   DEM_DTC_ORIGIN_USERDEFINED_MEMORY_23 (5U)
 *   DEM_DTC_ORIGIN_USERDEFINED_MEMORY_24 (5U)
 *   DEM_DTC_ORIGIN_USERDEFINED_MEMORY_25 (5U)
 *   DEM_DTC_ORIGIN_USERDEFINED_MEMORY_26 (5U)
 *   DEM_DTC_ORIGIN_USERDEFINED_MEMORY_27 (5U)
 *   DEM_DTC_ORIGIN_USERDEFINED_MEMORY_28 (5U)
 *   DEM_DTC_ORIGIN_USERDEFINED_MEMORY_29 (5U)
 *   DEM_DTC_ORIGIN_USERDEFINED_MEMORY_2A (5U)
 *   DEM_DTC_ORIGIN_USERDEFINED_MEMORY_2B (5U)
 *   DEM_DTC_ORIGIN_USERDEFINED_MEMORY_2C (5U)
 *   DEM_DTC_ORIGIN_USERDEFINED_MEMORY_2D (5U)
 *   DEM_DTC_ORIGIN_USERDEFINED_MEMORY_2E (5U)
 *   DEM_DTC_ORIGIN_USERDEFINED_MEMORY_2F (5U)
 *   DEM_DTC_ORIGIN_USERDEFINED_MEMORY_30 (5U)
 *   DEM_DTC_ORIGIN_USERDEFINED_MEMORY_31 (5U)
 *   DEM_DTC_ORIGIN_USERDEFINED_MEMORY_32 (5U)
 *   DEM_DTC_ORIGIN_USERDEFINED_MEMORY_33 (5U)
 *   DEM_DTC_ORIGIN_USERDEFINED_MEMORY_34 (5U)
 *   DEM_DTC_ORIGIN_USERDEFINED_MEMORY_35 (5U)
 *   DEM_DTC_ORIGIN_USERDEFINED_MEMORY_36 (5U)
 *   DEM_DTC_ORIGIN_USERDEFINED_MEMORY_37 (5U)
 *   DEM_DTC_ORIGIN_USERDEFINED_MEMORY_38 (5U)
 *   DEM_DTC_ORIGIN_USERDEFINED_MEMORY_39 (5U)
 *   DEM_DTC_ORIGIN_USERDEFINED_MEMORY_3A (5U)
 *   DEM_DTC_ORIGIN_USERDEFINED_MEMORY_3B (5U)
 *   DEM_DTC_ORIGIN_USERDEFINED_MEMORY_3C (5U)
 *   DEM_DTC_ORIGIN_USERDEFINED_MEMORY_3D (5U)
 *   DEM_DTC_ORIGIN_USERDEFINED_MEMORY_3E (5U)
 *   DEM_DTC_ORIGIN_USERDEFINED_MEMORY_3F (5U)
 *   DEM_DTC_ORIGIN_USERDEFINED_MEMORY_40 (5U)
 *   DEM_DTC_ORIGIN_USERDEFINED_MEMORY_41 (5U)
 *   DEM_DTC_ORIGIN_USERDEFINED_MEMORY_42 (5U)
 *   DEM_DTC_ORIGIN_USERDEFINED_MEMORY_43 (5U)
 *   DEM_DTC_ORIGIN_USERDEFINED_MEMORY_44 (5U)
 *   DEM_DTC_ORIGIN_USERDEFINED_MEMORY_45 (5U)
 *   DEM_DTC_ORIGIN_USERDEFINED_MEMORY_46 (5U)
 *   DEM_DTC_ORIGIN_USERDEFINED_MEMORY_47 (5U)
 *   DEM_DTC_ORIGIN_USERDEFINED_MEMORY_48 (5U)
 *   DEM_DTC_ORIGIN_USERDEFINED_MEMORY_49 (5U)
 *   DEM_DTC_ORIGIN_USERDEFINED_MEMORY_4A (5U)
 *   DEM_DTC_ORIGIN_USERDEFINED_MEMORY_4B (5U)
 *   DEM_DTC_ORIGIN_USERDEFINED_MEMORY_4C (5U)
 *   DEM_DTC_ORIGIN_USERDEFINED_MEMORY_4D (5U)
 *   DEM_DTC_ORIGIN_USERDEFINED_MEMORY_4E (5U)
 *   DEM_DTC_ORIGIN_USERDEFINED_MEMORY_4F (5U)
 *   DEM_DTC_ORIGIN_USERDEFINED_MEMORY_50 (5U)
 *   DEM_DTC_ORIGIN_USERDEFINED_MEMORY_51 (5U)
 *   DEM_DTC_ORIGIN_USERDEFINED_MEMORY_52 (5U)
 *   DEM_DTC_ORIGIN_USERDEFINED_MEMORY_53 (5U)
 *   DEM_DTC_ORIGIN_USERDEFINED_MEMORY_54 (5U)
 *   DEM_DTC_ORIGIN_USERDEFINED_MEMORY_55 (5U)
 *   DEM_DTC_ORIGIN_USERDEFINED_MEMORY_56 (5U)
 *   DEM_DTC_ORIGIN_USERDEFINED_MEMORY_57 (5U)
 *   DEM_DTC_ORIGIN_USERDEFINED_MEMORY_58 (5U)
 *   DEM_DTC_ORIGIN_USERDEFINED_MEMORY_59 (5U)
 *   DEM_DTC_ORIGIN_USERDEFINED_MEMORY_5A (5U)
 *   DEM_DTC_ORIGIN_USERDEFINED_MEMORY_5B (5U)
 *   DEM_DTC_ORIGIN_USERDEFINED_MEMORY_5C (5U)
 *   DEM_DTC_ORIGIN_USERDEFINED_MEMORY_5D (5U)
 *   DEM_DTC_ORIGIN_USERDEFINED_MEMORY_5E (5U)
 *   DEM_DTC_ORIGIN_USERDEFINED_MEMORY_5F (5U)
 *   DEM_DTC_ORIGIN_USERDEFINED_MEMORY_60 (5U)
 *   DEM_DTC_ORIGIN_USERDEFINED_MEMORY_61 (5U)
 *   DEM_DTC_ORIGIN_USERDEFINED_MEMORY_62 (5U)
 *   DEM_DTC_ORIGIN_USERDEFINED_MEMORY_63 (5U)
 *   DEM_DTC_ORIGIN_USERDEFINED_MEMORY_64 (5U)
 *   DEM_DTC_ORIGIN_USERDEFINED_MEMORY_65 (5U)
 *   DEM_DTC_ORIGIN_USERDEFINED_MEMORY_66 (5U)
 *   DEM_DTC_ORIGIN_USERDEFINED_MEMORY_67 (5U)
 *   DEM_DTC_ORIGIN_USERDEFINED_MEMORY_68 (5U)
 *   DEM_DTC_ORIGIN_USERDEFINED_MEMORY_69 (5U)
 *   DEM_DTC_ORIGIN_USERDEFINED_MEMORY_6A (5U)
 *   DEM_DTC_ORIGIN_USERDEFINED_MEMORY_6B (5U)
 *   DEM_DTC_ORIGIN_USERDEFINED_MEMORY_6C (5U)
 *   DEM_DTC_ORIGIN_USERDEFINED_MEMORY_6D (5U)
 *   DEM_DTC_ORIGIN_USERDEFINED_MEMORY_6E (5U)
 *   DEM_DTC_ORIGIN_USERDEFINED_MEMORY_6F (5U)
 *   DEM_DTC_ORIGIN_USERDEFINED_MEMORY_70 (5U)
 *   DEM_DTC_ORIGIN_USERDEFINED_MEMORY_71 (5U)
 *   DEM_DTC_ORIGIN_USERDEFINED_MEMORY_72 (5U)
 *   DEM_DTC_ORIGIN_USERDEFINED_MEMORY_73 (5U)
 *   DEM_DTC_ORIGIN_USERDEFINED_MEMORY_74 (5U)
 *   DEM_DTC_ORIGIN_USERDEFINED_MEMORY_75 (5U)
 *   DEM_DTC_ORIGIN_USERDEFINED_MEMORY_76 (5U)
 *   DEM_DTC_ORIGIN_USERDEFINED_MEMORY_77 (5U)
 *   DEM_DTC_ORIGIN_USERDEFINED_MEMORY_78 (5U)
 *   DEM_DTC_ORIGIN_USERDEFINED_MEMORY_79 (5U)
 *   DEM_DTC_ORIGIN_USERDEFINED_MEMORY_7A (5U)
 *   DEM_DTC_ORIGIN_USERDEFINED_MEMORY_7B (5U)
 *   DEM_DTC_ORIGIN_USERDEFINED_MEMORY_7C (5U)
 *   DEM_DTC_ORIGIN_USERDEFINED_MEMORY_7D (5U)
 *   DEM_DTC_ORIGIN_USERDEFINED_MEMORY_7E (5U)
 *   DEM_DTC_ORIGIN_USERDEFINED_MEMORY_7F (5U)
 *   DEM_DTC_ORIGIN_USERDEFINED_MEMORY_80 (5U)
 *   DEM_DTC_ORIGIN_USERDEFINED_MEMORY_81 (5U)
 *   DEM_DTC_ORIGIN_USERDEFINED_MEMORY_82 (5U)
 *   DEM_DTC_ORIGIN_USERDEFINED_MEMORY_83 (5U)
 *   DEM_DTC_ORIGIN_USERDEFINED_MEMORY_84 (5U)
 *   DEM_DTC_ORIGIN_USERDEFINED_MEMORY_85 (5U)
 *   DEM_DTC_ORIGIN_USERDEFINED_MEMORY_86 (5U)
 *   DEM_DTC_ORIGIN_USERDEFINED_MEMORY_87 (5U)
 *   DEM_DTC_ORIGIN_USERDEFINED_MEMORY_88 (5U)
 *   DEM_DTC_ORIGIN_USERDEFINED_MEMORY_89 (5U)
 *   DEM_DTC_ORIGIN_USERDEFINED_MEMORY_8A (5U)
 *   DEM_DTC_ORIGIN_USERDEFINED_MEMORY_8B (5U)
 *   DEM_DTC_ORIGIN_USERDEFINED_MEMORY_8C (5U)
 *   DEM_DTC_ORIGIN_USERDEFINED_MEMORY_8D (5U)
 *   DEM_DTC_ORIGIN_USERDEFINED_MEMORY_8E (5U)
 *   DEM_DTC_ORIGIN_USERDEFINED_MEMORY_8F (5U)
 *   DEM_DTC_ORIGIN_USERDEFINED_MEMORY_90 (5U)
 *   DEM_DTC_ORIGIN_USERDEFINED_MEMORY_91 (5U)
 *   DEM_DTC_ORIGIN_USERDEFINED_MEMORY_92 (5U)
 *   DEM_DTC_ORIGIN_USERDEFINED_MEMORY_93 (5U)
 *   DEM_DTC_ORIGIN_USERDEFINED_MEMORY_94 (5U)
 *   DEM_DTC_ORIGIN_USERDEFINED_MEMORY_95 (5U)
 *   DEM_DTC_ORIGIN_USERDEFINED_MEMORY_96 (5U)
 *   DEM_DTC_ORIGIN_USERDEFINED_MEMORY_97 (5U)
 *   DEM_DTC_ORIGIN_USERDEFINED_MEMORY_98 (5U)
 *   DEM_DTC_ORIGIN_USERDEFINED_MEMORY_99 (5U)
 *   DEM_DTC_ORIGIN_USERDEFINED_MEMORY_9A (5U)
 *   DEM_DTC_ORIGIN_USERDEFINED_MEMORY_9B (5U)
 *   DEM_DTC_ORIGIN_USERDEFINED_MEMORY_9C (5U)
 *   DEM_DTC_ORIGIN_USERDEFINED_MEMORY_9D (5U)
 *   DEM_DTC_ORIGIN_USERDEFINED_MEMORY_9E (5U)
 *   DEM_DTC_ORIGIN_USERDEFINED_MEMORY_9F (5U)
 *   DEM_DTC_ORIGIN_USERDEFINED_MEMORY_A0 (5U)
 *   DEM_DTC_ORIGIN_USERDEFINED_MEMORY_A1 (5U)
 *   DEM_DTC_ORIGIN_USERDEFINED_MEMORY_A2 (5U)
 *   DEM_DTC_ORIGIN_USERDEFINED_MEMORY_A3 (5U)
 *   DEM_DTC_ORIGIN_USERDEFINED_MEMORY_A4 (5U)
 *   DEM_DTC_ORIGIN_USERDEFINED_MEMORY_A5 (5U)
 *   DEM_DTC_ORIGIN_USERDEFINED_MEMORY_A6 (5U)
 *   DEM_DTC_ORIGIN_USERDEFINED_MEMORY_A7 (5U)
 *   DEM_DTC_ORIGIN_USERDEFINED_MEMORY_A8 (5U)
 *   DEM_DTC_ORIGIN_USERDEFINED_MEMORY_A9 (5U)
 *   DEM_DTC_ORIGIN_USERDEFINED_MEMORY_AA (5U)
 *   DEM_DTC_ORIGIN_USERDEFINED_MEMORY_AB (5U)
 *   DEM_DTC_ORIGIN_USERDEFINED_MEMORY_AC (5U)
 *   DEM_DTC_ORIGIN_USERDEFINED_MEMORY_AD (5U)
 *   DEM_DTC_ORIGIN_USERDEFINED_MEMORY_AE (5U)
 *   DEM_DTC_ORIGIN_USERDEFINED_MEMORY_AF (5U)
 *   DEM_DTC_ORIGIN_USERDEFINED_MEMORY_B0 (5U)
 *   DEM_DTC_ORIGIN_USERDEFINED_MEMORY_B1 (5U)
 *   DEM_DTC_ORIGIN_USERDEFINED_MEMORY_B2 (5U)
 *   DEM_DTC_ORIGIN_USERDEFINED_MEMORY_B3 (5U)
 *   DEM_DTC_ORIGIN_USERDEFINED_MEMORY_B4 (5U)
 *   DEM_DTC_ORIGIN_USERDEFINED_MEMORY_B5 (5U)
 *   DEM_DTC_ORIGIN_USERDEFINED_MEMORY_B6 (5U)
 *   DEM_DTC_ORIGIN_USERDEFINED_MEMORY_B7 (5U)
 *   DEM_DTC_ORIGIN_USERDEFINED_MEMORY_B8 (5U)
 *   DEM_DTC_ORIGIN_USERDEFINED_MEMORY_B9 (5U)
 *   DEM_DTC_ORIGIN_USERDEFINED_MEMORY_BA (5U)
 *   DEM_DTC_ORIGIN_USERDEFINED_MEMORY_BB (5U)
 *   DEM_DTC_ORIGIN_USERDEFINED_MEMORY_BC (5U)
 *   DEM_DTC_ORIGIN_USERDEFINED_MEMORY_BD (5U)
 *   DEM_DTC_ORIGIN_USERDEFINED_MEMORY_BE (5U)
 *   DEM_DTC_ORIGIN_USERDEFINED_MEMORY_BF (5U)
 *   DEM_DTC_ORIGIN_USERDEFINED_MEMORY_C0 (5U)
 *   DEM_DTC_ORIGIN_USERDEFINED_MEMORY_C1 (5U)
 *   DEM_DTC_ORIGIN_USERDEFINED_MEMORY_C2 (5U)
 *   DEM_DTC_ORIGIN_USERDEFINED_MEMORY_C3 (5U)
 *   DEM_DTC_ORIGIN_USERDEFINED_MEMORY_C4 (5U)
 *   DEM_DTC_ORIGIN_USERDEFINED_MEMORY_C5 (5U)
 *   DEM_DTC_ORIGIN_USERDEFINED_MEMORY_C6 (5U)
 *   DEM_DTC_ORIGIN_USERDEFINED_MEMORY_C7 (5U)
 *   DEM_DTC_ORIGIN_USERDEFINED_MEMORY_C8 (5U)
 *   DEM_DTC_ORIGIN_USERDEFINED_MEMORY_C9 (5U)
 *   DEM_DTC_ORIGIN_USERDEFINED_MEMORY_CA (5U)
 *   DEM_DTC_ORIGIN_USERDEFINED_MEMORY_CB (5U)
 *   DEM_DTC_ORIGIN_USERDEFINED_MEMORY_CC (5U)
 *   DEM_DTC_ORIGIN_USERDEFINED_MEMORY_CD (5U)
 *   DEM_DTC_ORIGIN_USERDEFINED_MEMORY_CE (5U)
 *   DEM_DTC_ORIGIN_USERDEFINED_MEMORY_CF (5U)
 *   DEM_DTC_ORIGIN_USERDEFINED_MEMORY_D0 (5U)
 *   DEM_DTC_ORIGIN_USERDEFINED_MEMORY_D1 (5U)
 *   DEM_DTC_ORIGIN_USERDEFINED_MEMORY_D2 (5U)
 *   DEM_DTC_ORIGIN_USERDEFINED_MEMORY_D3 (5U)
 *   DEM_DTC_ORIGIN_USERDEFINED_MEMORY_D4 (5U)
 *   DEM_DTC_ORIGIN_USERDEFINED_MEMORY_D5 (5U)
 *   DEM_DTC_ORIGIN_USERDEFINED_MEMORY_D6 (5U)
 *   DEM_DTC_ORIGIN_USERDEFINED_MEMORY_D7 (5U)
 *   DEM_DTC_ORIGIN_USERDEFINED_MEMORY_D8 (5U)
 *   DEM_DTC_ORIGIN_USERDEFINED_MEMORY_D9 (5U)
 *   DEM_DTC_ORIGIN_USERDEFINED_MEMORY_DA (5U)
 *   DEM_DTC_ORIGIN_USERDEFINED_MEMORY_DB (5U)
 *   DEM_DTC_ORIGIN_USERDEFINED_MEMORY_DC (5U)
 *   DEM_DTC_ORIGIN_USERDEFINED_MEMORY_DD (5U)
 *   DEM_DTC_ORIGIN_USERDEFINED_MEMORY_DE (5U)
 *   DEM_DTC_ORIGIN_USERDEFINED_MEMORY_DF (5U)
 *   DEM_DTC_ORIGIN_USERDEFINED_MEMORY_E0 (5U)
 *   DEM_DTC_ORIGIN_USERDEFINED_MEMORY_E1 (5U)
 *   DEM_DTC_ORIGIN_USERDEFINED_MEMORY_E2 (5U)
 *   DEM_DTC_ORIGIN_USERDEFINED_MEMORY_E3 (5U)
 *   DEM_DTC_ORIGIN_USERDEFINED_MEMORY_E4 (5U)
 *   DEM_DTC_ORIGIN_USERDEFINED_MEMORY_E5 (5U)
 *   DEM_DTC_ORIGIN_USERDEFINED_MEMORY_E6 (5U)
 *   DEM_DTC_ORIGIN_USERDEFINED_MEMORY_E7 (5U)
 *   DEM_DTC_ORIGIN_USERDEFINED_MEMORY_E8 (5U)
 *   DEM_DTC_ORIGIN_USERDEFINED_MEMORY_E9 (5U)
 *   DEM_DTC_ORIGIN_USERDEFINED_MEMORY_EA (5U)
 *   DEM_DTC_ORIGIN_USERDEFINED_MEMORY_EB (5U)
 *   DEM_DTC_ORIGIN_USERDEFINED_MEMORY_EC (5U)
 *   DEM_DTC_ORIGIN_USERDEFINED_MEMORY_ED (5U)
 *   DEM_DTC_ORIGIN_USERDEFINED_MEMORY_EE (5U)
 *   DEM_DTC_ORIGIN_USERDEFINED_MEMORY_EF (5U)
 *   DEM_DTC_ORIGIN_USERDEFINED_MEMORY_F0 (5U)
 *   DEM_DTC_ORIGIN_USERDEFINED_MEMORY_F1 (5U)
 *   DEM_DTC_ORIGIN_USERDEFINED_MEMORY_F2 (5U)
 *   DEM_DTC_ORIGIN_USERDEFINED_MEMORY_F3 (5U)
 *   DEM_DTC_ORIGIN_USERDEFINED_MEMORY_F4 (5U)
 *   DEM_DTC_ORIGIN_USERDEFINED_MEMORY_F5 (5U)
 *   DEM_DTC_ORIGIN_USERDEFINED_MEMORY_F6 (5U)
 *   DEM_DTC_ORIGIN_USERDEFINED_MEMORY_F7 (5U)
 *   DEM_DTC_ORIGIN_USERDEFINED_MEMORY_F8 (5U)
 *   DEM_DTC_ORIGIN_USERDEFINED_MEMORY_F9 (5U)
 *   DEM_DTC_ORIGIN_USERDEFINED_MEMORY_FA (5U)
 *   DEM_DTC_ORIGIN_USERDEFINED_MEMORY_FB (5U)
 *   DEM_DTC_ORIGIN_USERDEFINED_MEMORY_FC (5U)
 *   DEM_DTC_ORIGIN_USERDEFINED_MEMORY_FD (5U)
 *   DEM_DTC_ORIGIN_USERDEFINED_MEMORY_FE (5U)
 *   DEM_DTC_ORIGIN_USERDEFINED_MEMORY_FF (5U)
 * Dem_DTCOriginType: Enumeration of integer in interval [1...4] with enumerators
 *   DEM_DTC_ORIGIN_PRIMARY_MEMORY (1U)
 *   DEM_DTC_ORIGIN_MIRROR_MEMORY (2U)
 *   DEM_DTC_ORIGIN_PERMANENT_MEMORY (3U)
 *   DEM_DTC_ORIGIN_USERDEFINED_MEMORY_BMWSecondaryErrorMemory (4U)
 *
 * Array Types:
 * ============
 * Dem_MaxDataValueType: Array with 18 element(s) of type uint8
 * Dem_MaxDataValueType: Array with 18 element(s) of type uint8
 *
 *********************************************************************************************************************/


#define DemWrapper_START_SEC_CODE
#include "DemWrapper_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/**********************************************************************************************************************
 *
 * Runnable Entity Name: DemWrapper_ApplicationDTCInfoPort_GetDTCOfEvent
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <GetDTCOfEvent> of PortPrototype <DemWrapper_ApplicationDTCInfoPort>
 *
 **********************************************************************************************************************
 *
 * Service Calls:
 * ==============
 *   Service Invocation:
 *   -------------------
 *   Std_ReturnType Rte_Call_DemWrapper_EvtInfo_DM_TEST_APPL_GetDTCOfEvent(Dem_DTCFormatType DTCFormat, uint32 *DTCOfEvent)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticInfo_DEM_E_NO_DTC_AVAILABLE, RTE_E_DiagnosticInfo_E_NOT_OK
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType DemWrapper_ApplicationDTCInfoPort_GetDTCOfEvent(Dem_DTCFormatType DTCFormat, uint32 *DTCOfEvent)
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_Darh_DiagnosticInfo_DEM_E_NO_DTC_AVAILABLE
 *   RTE_E_Darh_DiagnosticInfo_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: DemWrapper_ApplicationDTCInfoPort_GetDTCOfEvent_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, DemWrapper_CODE) DemWrapper_ApplicationDTCInfoPort_GetDTCOfEvent(Dem_DTCFormatType DTCFormat, P2VAR(uint32, AUTOMATIC, RTE_DEMWRAPPER_APPL_VAR) DTCOfEvent) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: DemWrapper_ApplicationDTCInfoPort_GetDTCOfEvent (returns application error)
 *********************************************************************************************************************/

  Std_ReturnType retVal = RTE_E_INVALID;
	
  retVal = Rte_Call_DemWrapper_EvtInfo_DM_TEST_APPL_GetDTCOfEvent( DTCFormat, DTCOfEvent);

  if (retVal == RTE_E_OK)
     return RTE_E_OK;
  else if (retVal == RTE_E_DiagnosticInfo_DEM_E_NO_DTC_AVAILABLE)
     return RTE_E_Darh_DiagnosticInfo_DEM_E_NO_DTC_AVAILABLE;
  else /*if (retVal == RTE_E_DiagnosticInfo_E_NOT_OK)*/
     return RTE_E_Darh_DiagnosticInfo_E_NOT_OK;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: DemWrapper_CddIf_ClearDTC
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <ClearDTC> of PortPrototype <DemWrapper_CddIf>
 *
 **********************************************************************************************************************
 *
 * Service Calls:
 * ==============
 *   Service Invocation:
 *   -------------------
 *   Std_ReturnType Rte_Call_DemWrapper_ClearDTC_SelectDTC(uint32 DTC, Dem_DTCFormatType DTCFormat, Dem_DTCOriginType DTCOrigin)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_ClearDTC_E_NOT_OK, RTE_E_ClearDTC_E_OK
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType DemWrapper_CddIf_ClearDTC(uint32 DTC, Dem_DTCFormatType DTCFormat, Dem_DTCOriginType DTCOrigin)
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_CddIf_DEM_CLEAR_BUSY
 *   RTE_E_CddIf_DEM_CLEAR_FAILED
 *   RTE_E_CddIf_DEM_CLEAR_MEMORY_ERROR
 *   RTE_E_CddIf_DEM_CLEAR_PENDING
 *   RTE_E_CddIf_DEM_CLEAR_WRONG_DTC
 *   RTE_E_CddIf_DEM_CLEAR_WRONG_DTCORIGIN
 *   RTE_E_CddIf_E_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: DemWrapper_CddIf_ClearDTC_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, DemWrapper_CODE) DemWrapper_CddIf_ClearDTC(uint32 DTC, Dem_DTCFormatType DTCFormat, Dem_DTCOriginType DTCOrigin) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: DemWrapper_CddIf_ClearDTC (returns application error)
 *********************************************************************************************************************/
  Std_ReturnType RetVal = RTE_E_CddIf_DEM_CLEAR_FAILED;
  RetVal = Rte_Call_DemWrapper_ClearDTC_SelectDTC( DTC, DTCFormat, DTCOrigin);

  if (RetVal == E_OK)
	  return RTE_E_OK;
  else 
	  return RTE_E_CddIf_DEM_CLEAR_FAILED;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: DemWrapper_Darh_GeneralDiagnosticInfo_GetDTCOfEvent
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <GetDTCOfEvent> of PortPrototype <DemWrapper_Darh_GeneralDiagnosticInfo>
 *
 **********************************************************************************************************************
 *
 * Service Calls:
 * ==============
 *   Service Invocation:
 *   -------------------
 *   Std_ReturnType Rte_Call_DemWrapper_GeneralDiagnosticInfo_GetDTCOfEvent(Dem_EventIdType EventId, Dem_DTCFormatType DTCFormat, uint32 *DTCOfEvent)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_GeneralDiagnosticInfo_DEM_E_NO_DTC_AVAILABLE, RTE_E_GeneralDiagnosticInfo_E_NOT_OK
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType DemWrapper_Darh_GeneralDiagnosticInfo_GetDTCOfEvent(Dem_EventIdType EventId, Dem_DTCFormatType DTCFormat, uint32 *DTCOfEvent)
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_Darh_GeneralDiagnosticInfo_DEM_E_NO_DTC_AVAILABLE
 *   RTE_E_Darh_GeneralDiagnosticInfo_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: DemWrapper_Darh_GeneralDiagnosticInfo_GetDTCOfEvent_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, DemWrapper_CODE) DemWrapper_Darh_GeneralDiagnosticInfo_GetDTCOfEvent(Dem_EventIdType EventId, Dem_DTCFormatType DTCFormat, P2VAR(uint32, AUTOMATIC, RTE_DEMWRAPPER_APPL_VAR) DTCOfEvent) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: DemWrapper_Darh_GeneralDiagnosticInfo_GetDTCOfEvent (returns application error)
 *********************************************************************************************************************/

  Std_ReturnType retVal = RTE_E_INVALID;
  retVal = Rte_Call_DemWrapper_GeneralDiagnosticInfo_GetDTCOfEvent( EventId, DTCFormat, DTCOfEvent);
	
  if (retVal == RTE_E_OK)
     return RTE_E_OK;
  else if (retVal == RTE_E_GeneralDiagnosticInfo_DEM_E_NO_DTC_AVAILABLE)
     return RTE_E_Darh_GeneralDiagnosticInfo_DEM_E_NO_DTC_AVAILABLE;
  else /*if (retVal == RTE_E_GeneralDiagnosticInfo_E_NOT_OK)*/
     return RTE_E_Darh_GeneralDiagnosticInfo_E_NOT_OK;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: DemWrapper_Darh_GeneralDiagnosticInfo_GetEventFreezeFrameData
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <GetEventFreezeFrameData> of PortPrototype <DemWrapper_Darh_GeneralDiagnosticInfo>
 *
 **********************************************************************************************************************
 *
 * Service Calls:
 * ==============
 *   Service Invocation:
 *   -------------------
 *   Std_ReturnType Rte_Call_DemWrapper_GeneralDiagnosticInfo_GetEventFreezeFrameDataEx(Dem_EventIdType EventId, uint8 RecordNumber, uint16 DataId, uint8 *DestBuffer, uint16 *BufSize)
 *     Argument DestBuffer: uint8* is of type Dem_MaxDataValueType
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_GeneralDiagnosticInfo_DEM_BUFFER_TOO_SMALL, RTE_E_GeneralDiagnosticInfo_DEM_NO_SUCH_ELEMENT, RTE_E_GeneralDiagnosticInfo_E_NOT_OK
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType DemWrapper_Darh_GeneralDiagnosticInfo_GetEventFreezeFrameData(Dem_EventIdType EventId, uint8 RecordNumber, boolean ReportTotalRecord, uint16 DataId, uint8 *DestBuffer)
 *     Argument DestBuffer: uint8* is of type Dem_MaxDataValueType
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_Darh_GeneralDiagnosticInfo_DEM_E_NODATAAVAILABLE
 *   RTE_E_Darh_GeneralDiagnosticInfo_DEM_E_WRONG_DIDNUMBER
 *   RTE_E_Darh_GeneralDiagnosticInfo_DEM_E_WRONG_RECORDNUMBER
 *   RTE_E_Darh_GeneralDiagnosticInfo_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: DemWrapper_Darh_GeneralDiagnosticInfo_GetEventFreezeFrameData_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, DemWrapper_CODE) DemWrapper_Darh_GeneralDiagnosticInfo_GetEventFreezeFrameData(Dem_EventIdType EventId, uint8 RecordNumber, boolean ReportTotalRecord, uint16 DataId, P2VAR(uint8, AUTOMATIC, RTE_DEMWRAPPER_APPL_VAR) DestBuffer) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: DemWrapper_Darh_GeneralDiagnosticInfo_GetEventFreezeFrameData (returns application error)
 *********************************************************************************************************************/

//  Std_ReturnType retVal = RTE_E_INVALID;
  uint16 BufSize;
  
  BufSize = (sizeof(Dem_MaxDataValueType));
//  RetVal = Rte_Call_DemWrapper_GeneralDiagnosticInfo_GetEventFreezeFrameDataEx(Dem_EventIdType EventId, uint8 RecordNumber, uint16 DataId, uint8 *DestBuffer, uint16 *BufSize)
  
//  if (RetVal == RTE_E_Darh_GeneralDiagnosticInfo_DEM_BUFFER_TOO_SMALL)
//  return 
//  return RTE_E_OK;
  return Rte_Call_DemWrapper_GeneralDiagnosticInfo_GetEventFreezeFrameDataEx(EventId, RecordNumber, DataId, DestBuffer, &BufSize);

  /*The requested event data is not currently stored (but the request was valid) OR The requested record number is not supported by the event OR The requested DID is not
   supported by the freeze frame*/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: DemWrapper_Init
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed once after the RTE is started
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: DemWrapper_Init_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, DemWrapper_CODE) DemWrapper_Init(void) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: DemWrapper_Init
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: DemWrapper_NetworkDTCInfoPort_GetDTCOfEvent
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <GetDTCOfEvent> of PortPrototype <DemWrapper_NetworkDTCInfoPort>
 *
 **********************************************************************************************************************
 *
 * Service Calls:
 * ==============
 *   Service Invocation:
 *   -------------------
 *   Std_ReturnType Rte_Call_DemWrapper_EvtInfo_DM_TEST_COM_GetDTCOfEvent(Dem_DTCFormatType DTCFormat, uint32 *DTCOfEvent)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticInfo_DEM_E_NO_DTC_AVAILABLE, RTE_E_DiagnosticInfo_E_NOT_OK
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType DemWrapper_NetworkDTCInfoPort_GetDTCOfEvent(Dem_DTCFormatType DTCFormat, uint32 *DTCOfEvent)
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_Darh_DiagnosticInfo_DEM_E_NO_DTC_AVAILABLE
 *   RTE_E_Darh_DiagnosticInfo_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: DemWrapper_NetworkDTCInfoPort_GetDTCOfEvent_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, DemWrapper_CODE) DemWrapper_NetworkDTCInfoPort_GetDTCOfEvent(Dem_DTCFormatType DTCFormat, P2VAR(uint32, AUTOMATIC, RTE_DEMWRAPPER_APPL_VAR) DTCOfEvent) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: DemWrapper_NetworkDTCInfoPort_GetDTCOfEvent (returns application error)
 *********************************************************************************************************************/
  Std_ReturnType retVal = RTE_E_INVALID;
	
  retVal = Rte_Call_DemWrapper_EvtInfo_DM_TEST_COM_GetDTCOfEvent( DTCFormat, DTCOfEvent);

  if (retVal == RTE_E_OK)
     return RTE_E_OK;
  else if (retVal == RTE_E_DiagnosticInfo_DEM_E_NO_DTC_AVAILABLE)
     return RTE_E_Darh_DiagnosticInfo_DEM_E_NO_DTC_AVAILABLE;
  else /*if (retVal == RTE_E_DiagnosticInfo_E_NOT_OK)*/
     return RTE_E_Darh_DiagnosticInfo_E_NOT_OK;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}


#define DemWrapper_STOP_SEC_CODE
#include "DemWrapper_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of function definition area >>            DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of function definition area >>              DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of removed code area >>                   DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of removed code area >>                     DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
