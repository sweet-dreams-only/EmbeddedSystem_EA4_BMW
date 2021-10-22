/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *          File:  DemWrapper.c
 *        Config:  EPS.dpa
 *     SW-C Type:  DemWrapper
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
/* PRQA S 0857 EOF */ /* MD_MSR_1.1_857 */
/* PRQA S 0614 EOF */ /* MD_Rte_TestCode */

/* PRQA S 3109 EOF */ /* MD_Rte_TestCode */
/* PRQA S 3112 EOF */ /* MD_Rte_TestCode */
/* PRQA S 3197 EOF */ /* MD_Rte_TestCode */
/* PRQA S 3198 EOF */ /* MD_Rte_TestCode */
/* PRQA S 3199 EOF */ /* MD_Rte_TestCode */
/* PRQA S 3201 EOF */ /* MD_Rte_TestCode */
/* PRQA S 3203 EOF */ /* MD_Rte_TestCode */
/* PRQA S 3205 EOF */ /* MD_Rte_TestCode */
/* PRQA S 3206 EOF */ /* MD_Rte_TestCode */
/* PRQA S 3218 EOF */ /* MD_Rte_TestCode */
/* PRQA S 3229 EOF */ /* MD_Rte_TestCode */
/* PRQA S 2002 EOF */ /* MD_Rte_TestCode */
/* PRQA S 3334 EOF */ /* MD_Rte_TestCode */
/* PRQA S 3417 EOF */ /* MD_Rte_TestCode */
/* PRQA S 3426 EOF */ /* MD_Rte_TestCode */
/* PRQA S 3453 EOF */ /* MD_Rte_TestCode */

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
 *   
 *
 * Dem_DTCFormatType
 *   
 *
 * Dem_DTCFormatType
 *   
 *
 * Dem_DTCOriginType
 *   
 *
 * Dem_DTCOriginType
 *   
 *
 * Dem_EventIdType
 *   
 *
 * Dem_EventIdType
 *   
 *
 *********************************************************************************************************************/

#include "Rte_DemWrapper.h" /* PRQA S 0857 */ /* MD_MSR_1.1_857 */
#include "TSC_DemWrapper.h"


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of include and declaration area >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

#include "string.h"

static void DemWrapper_TestDefines(void);


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
 * Dem_EventIdType: Integer in interval [1...72]
 * Dem_EventIdType: Integer in interval [1...65535]
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
 * Dem_MaxDataValueType: Array with 4 element(s) of type uint8
 * Dem_MaxDataValueType: Array with 4 element(s) of type uint8
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

  Std_ReturnType fct_status;
  boolean fct_error = 0;

  uint32 Call_DemWrapper_EvtInfo_DM_TEST_APPL_GetDTCOfEvent_DTCOfEvent = 0U;

  /*************************************************
  * Direct Function Accesses
  *************************************************/

  fct_status = TSC_DemWrapper_Rte_Call_DemWrapper_EvtInfo_DM_TEST_APPL_GetDTCOfEvent(0U, &Call_DemWrapper_EvtInfo_DM_TEST_APPL_GetDTCOfEvent_DTCOfEvent);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_TIMEOUT:
      fct_error = 1;
      break;
    case RTE_E_DiagnosticInfo_DEM_E_NO_DTC_AVAILABLE:
      fct_error = 1;
      break;
    case RTE_E_DiagnosticInfo_E_NOT_OK:
      fct_error = 1;
      break;
  }

  DemWrapper_TestDefines();

  return RTE_E_OK;

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

  Std_ReturnType fct_status;
  boolean fct_error = 0;

  /*************************************************
  * Direct Function Accesses
  *************************************************/

  fct_status = TSC_DemWrapper_Rte_Call_DemWrapper_ClearDTC_SelectDTC(0U, 0U, 0U);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_TIMEOUT:
      fct_error = 1;
      break;
    case RTE_E_ClearDTC_E_NOT_OK:
      fct_error = 1;
      break;
  }

  return RTE_E_OK;

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

  Std_ReturnType fct_status;
  boolean fct_error = 0;

  uint32 Call_DemWrapper_GeneralDiagnosticInfo_GetDTCOfEvent_DTCOfEvent = 0U;

  /*************************************************
  * Direct Function Accesses
  *************************************************/

  fct_status = TSC_DemWrapper_Rte_Call_DemWrapper_GeneralDiagnosticInfo_GetDTCOfEvent(0U, 0U, &Call_DemWrapper_GeneralDiagnosticInfo_GetDTCOfEvent_DTCOfEvent);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_TIMEOUT:
      fct_error = 1;
      break;
    case RTE_E_GeneralDiagnosticInfo_DEM_E_NO_DTC_AVAILABLE:
      fct_error = 1;
      break;
    case RTE_E_GeneralDiagnosticInfo_E_NOT_OK:
      fct_error = 1;
      break;
  }

  return RTE_E_OK;

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

  Std_ReturnType fct_status;
  boolean fct_error = 0;

  Dem_MaxDataValueType Call_DemWrapper_GeneralDiagnosticInfo_GetEventFreezeFrameDataEx_DestBuffer = {
  0U, 0U, 0U, 0U
};
  uint16 Call_DemWrapper_GeneralDiagnosticInfo_GetEventFreezeFrameDataEx_BufSize = 0U;

  /*************************************************
  * Direct Function Accesses
  *************************************************/

  fct_status = TSC_DemWrapper_Rte_Call_DemWrapper_GeneralDiagnosticInfo_GetEventFreezeFrameDataEx(0U, 0U, 0U, Call_DemWrapper_GeneralDiagnosticInfo_GetEventFreezeFrameDataEx_DestBuffer, &Call_DemWrapper_GeneralDiagnosticInfo_GetEventFreezeFrameDataEx_BufSize);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_TIMEOUT:
      fct_error = 1;
      break;
    case RTE_E_GeneralDiagnosticInfo_DEM_BUFFER_TOO_SMALL:
      fct_error = 1;
      break;
    case RTE_E_GeneralDiagnosticInfo_DEM_NO_SUCH_ELEMENT:
      fct_error = 1;
      break;
    case RTE_E_GeneralDiagnosticInfo_E_NOT_OK:
      fct_error = 1;
      break;
  }

  return RTE_E_OK;

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

  Std_ReturnType fct_status;
  boolean fct_error = 0;

  uint32 Call_DemWrapper_EvtInfo_DM_TEST_COM_GetDTCOfEvent_DTCOfEvent = 0U;

  /*************************************************
  * Direct Function Accesses
  *************************************************/

  fct_status = TSC_DemWrapper_Rte_Call_DemWrapper_EvtInfo_DM_TEST_COM_GetDTCOfEvent(0U, &Call_DemWrapper_EvtInfo_DM_TEST_COM_GetDTCOfEvent_DTCOfEvent);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_TIMEOUT:
      fct_error = 1;
      break;
    case RTE_E_DiagnosticInfo_DEM_E_NO_DTC_AVAILABLE:
      fct_error = 1;
      break;
    case RTE_E_DiagnosticInfo_E_NOT_OK:
      fct_error = 1;
      break;
  }

  return RTE_E_OK;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}


#define DemWrapper_STOP_SEC_CODE
#include "DemWrapper_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of function definition area >>            DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

static void DemWrapper_TestDefines(void)
{
  /* Enumeration Data Types */

  Dem_DTCFormatType Test_Dem_DTCFormatType_V_1 = DEM_DTC_FORMAT_OBD;
  Dem_DTCFormatType Test_Dem_DTCFormatType_V_2 = DEM_DTC_FORMAT_UDS;
  Dem_DTCFormatType Test_Dem_DTCFormatType_V_3 = DEM_DTC_FORMAT_J1939;

  Dem_DTCOriginType Test_Dem_DTCOriginType_V_1 = DEM_DTC_ORIGIN_PRIMARY_MEMORY;
  Dem_DTCOriginType Test_Dem_DTCOriginType_V_2 = DEM_DTC_ORIGIN_MIRROR_MEMORY;
  Dem_DTCOriginType Test_Dem_DTCOriginType_V_3 = DEM_DTC_ORIGIN_PERMANENT_MEMORY;
  Dem_DTCOriginType Test_Dem_DTCOriginType_V_4 = DEM_DTC_ORIGIN_OBD_RELEVANT_MEMORY;
  Dem_DTCOriginType Test_Dem_DTCOriginType_V_5 = DEM_DTC_ORIGIN_SECONDARY_MEMORY;
  Dem_DTCOriginType Test_Dem_DTCOriginType_V_6 = DEM_DTC_ORIGIN_USERDEFINED_MEMORY_10;
  Dem_DTCOriginType Test_Dem_DTCOriginType_V_7 = DEM_DTC_ORIGIN_USERDEFINED_MEMORY_11;
  Dem_DTCOriginType Test_Dem_DTCOriginType_V_8 = DEM_DTC_ORIGIN_USERDEFINED_MEMORY_12;
  Dem_DTCOriginType Test_Dem_DTCOriginType_V_9 = DEM_DTC_ORIGIN_USERDEFINED_MEMORY_13;
  Dem_DTCOriginType Test_Dem_DTCOriginType_V_10 = DEM_DTC_ORIGIN_USERDEFINED_MEMORY_14;
  Dem_DTCOriginType Test_Dem_DTCOriginType_V_11 = DEM_DTC_ORIGIN_USERDEFINED_MEMORY_15;
  Dem_DTCOriginType Test_Dem_DTCOriginType_V_12 = DEM_DTC_ORIGIN_USERDEFINED_MEMORY_16;
  Dem_DTCOriginType Test_Dem_DTCOriginType_V_13 = DEM_DTC_ORIGIN_USERDEFINED_MEMORY_17;
  Dem_DTCOriginType Test_Dem_DTCOriginType_V_14 = DEM_DTC_ORIGIN_USERDEFINED_MEMORY_18;
  Dem_DTCOriginType Test_Dem_DTCOriginType_V_15 = DEM_DTC_ORIGIN_USERDEFINED_MEMORY_19;
  Dem_DTCOriginType Test_Dem_DTCOriginType_V_16 = DEM_DTC_ORIGIN_USERDEFINED_MEMORY_1A;
  Dem_DTCOriginType Test_Dem_DTCOriginType_V_17 = DEM_DTC_ORIGIN_USERDEFINED_MEMORY_1B;
  Dem_DTCOriginType Test_Dem_DTCOriginType_V_18 = DEM_DTC_ORIGIN_USERDEFINED_MEMORY_1C;
  Dem_DTCOriginType Test_Dem_DTCOriginType_V_19 = DEM_DTC_ORIGIN_USERDEFINED_MEMORY_1D;
  Dem_DTCOriginType Test_Dem_DTCOriginType_V_20 = DEM_DTC_ORIGIN_USERDEFINED_MEMORY_1E;
  Dem_DTCOriginType Test_Dem_DTCOriginType_V_21 = DEM_DTC_ORIGIN_USERDEFINED_MEMORY_1F;
  Dem_DTCOriginType Test_Dem_DTCOriginType_V_22 = DEM_DTC_ORIGIN_USERDEFINED_MEMORY_20;
  Dem_DTCOriginType Test_Dem_DTCOriginType_V_23 = DEM_DTC_ORIGIN_USERDEFINED_MEMORY_21;
  Dem_DTCOriginType Test_Dem_DTCOriginType_V_24 = DEM_DTC_ORIGIN_USERDEFINED_MEMORY_22;
  Dem_DTCOriginType Test_Dem_DTCOriginType_V_25 = DEM_DTC_ORIGIN_USERDEFINED_MEMORY_23;
  Dem_DTCOriginType Test_Dem_DTCOriginType_V_26 = DEM_DTC_ORIGIN_USERDEFINED_MEMORY_24;
  Dem_DTCOriginType Test_Dem_DTCOriginType_V_27 = DEM_DTC_ORIGIN_USERDEFINED_MEMORY_25;
  Dem_DTCOriginType Test_Dem_DTCOriginType_V_28 = DEM_DTC_ORIGIN_USERDEFINED_MEMORY_26;
  Dem_DTCOriginType Test_Dem_DTCOriginType_V_29 = DEM_DTC_ORIGIN_USERDEFINED_MEMORY_27;
  Dem_DTCOriginType Test_Dem_DTCOriginType_V_30 = DEM_DTC_ORIGIN_USERDEFINED_MEMORY_28;
  Dem_DTCOriginType Test_Dem_DTCOriginType_V_31 = DEM_DTC_ORIGIN_USERDEFINED_MEMORY_29;
  Dem_DTCOriginType Test_Dem_DTCOriginType_V_32 = DEM_DTC_ORIGIN_USERDEFINED_MEMORY_2A;
  Dem_DTCOriginType Test_Dem_DTCOriginType_V_33 = DEM_DTC_ORIGIN_USERDEFINED_MEMORY_2B;
  Dem_DTCOriginType Test_Dem_DTCOriginType_V_34 = DEM_DTC_ORIGIN_USERDEFINED_MEMORY_2C;
  Dem_DTCOriginType Test_Dem_DTCOriginType_V_35 = DEM_DTC_ORIGIN_USERDEFINED_MEMORY_2D;
  Dem_DTCOriginType Test_Dem_DTCOriginType_V_36 = DEM_DTC_ORIGIN_USERDEFINED_MEMORY_2E;
  Dem_DTCOriginType Test_Dem_DTCOriginType_V_37 = DEM_DTC_ORIGIN_USERDEFINED_MEMORY_2F;
  Dem_DTCOriginType Test_Dem_DTCOriginType_V_38 = DEM_DTC_ORIGIN_USERDEFINED_MEMORY_30;
  Dem_DTCOriginType Test_Dem_DTCOriginType_V_39 = DEM_DTC_ORIGIN_USERDEFINED_MEMORY_31;
  Dem_DTCOriginType Test_Dem_DTCOriginType_V_40 = DEM_DTC_ORIGIN_USERDEFINED_MEMORY_32;
  Dem_DTCOriginType Test_Dem_DTCOriginType_V_41 = DEM_DTC_ORIGIN_USERDEFINED_MEMORY_33;
  Dem_DTCOriginType Test_Dem_DTCOriginType_V_42 = DEM_DTC_ORIGIN_USERDEFINED_MEMORY_34;
  Dem_DTCOriginType Test_Dem_DTCOriginType_V_43 = DEM_DTC_ORIGIN_USERDEFINED_MEMORY_35;
  Dem_DTCOriginType Test_Dem_DTCOriginType_V_44 = DEM_DTC_ORIGIN_USERDEFINED_MEMORY_36;
  Dem_DTCOriginType Test_Dem_DTCOriginType_V_45 = DEM_DTC_ORIGIN_USERDEFINED_MEMORY_37;
  Dem_DTCOriginType Test_Dem_DTCOriginType_V_46 = DEM_DTC_ORIGIN_USERDEFINED_MEMORY_38;
  Dem_DTCOriginType Test_Dem_DTCOriginType_V_47 = DEM_DTC_ORIGIN_USERDEFINED_MEMORY_39;
  Dem_DTCOriginType Test_Dem_DTCOriginType_V_48 = DEM_DTC_ORIGIN_USERDEFINED_MEMORY_3A;
  Dem_DTCOriginType Test_Dem_DTCOriginType_V_49 = DEM_DTC_ORIGIN_USERDEFINED_MEMORY_3B;
  Dem_DTCOriginType Test_Dem_DTCOriginType_V_50 = DEM_DTC_ORIGIN_USERDEFINED_MEMORY_3C;
  Dem_DTCOriginType Test_Dem_DTCOriginType_V_51 = DEM_DTC_ORIGIN_USERDEFINED_MEMORY_3D;
  Dem_DTCOriginType Test_Dem_DTCOriginType_V_52 = DEM_DTC_ORIGIN_USERDEFINED_MEMORY_3E;
  Dem_DTCOriginType Test_Dem_DTCOriginType_V_53 = DEM_DTC_ORIGIN_USERDEFINED_MEMORY_3F;
  Dem_DTCOriginType Test_Dem_DTCOriginType_V_54 = DEM_DTC_ORIGIN_USERDEFINED_MEMORY_40;
  Dem_DTCOriginType Test_Dem_DTCOriginType_V_55 = DEM_DTC_ORIGIN_USERDEFINED_MEMORY_41;
  Dem_DTCOriginType Test_Dem_DTCOriginType_V_56 = DEM_DTC_ORIGIN_USERDEFINED_MEMORY_42;
  Dem_DTCOriginType Test_Dem_DTCOriginType_V_57 = DEM_DTC_ORIGIN_USERDEFINED_MEMORY_43;
  Dem_DTCOriginType Test_Dem_DTCOriginType_V_58 = DEM_DTC_ORIGIN_USERDEFINED_MEMORY_44;
  Dem_DTCOriginType Test_Dem_DTCOriginType_V_59 = DEM_DTC_ORIGIN_USERDEFINED_MEMORY_45;
  Dem_DTCOriginType Test_Dem_DTCOriginType_V_60 = DEM_DTC_ORIGIN_USERDEFINED_MEMORY_46;
  Dem_DTCOriginType Test_Dem_DTCOriginType_V_61 = DEM_DTC_ORIGIN_USERDEFINED_MEMORY_47;
  Dem_DTCOriginType Test_Dem_DTCOriginType_V_62 = DEM_DTC_ORIGIN_USERDEFINED_MEMORY_48;
  Dem_DTCOriginType Test_Dem_DTCOriginType_V_63 = DEM_DTC_ORIGIN_USERDEFINED_MEMORY_49;
  Dem_DTCOriginType Test_Dem_DTCOriginType_V_64 = DEM_DTC_ORIGIN_USERDEFINED_MEMORY_4A;
  Dem_DTCOriginType Test_Dem_DTCOriginType_V_65 = DEM_DTC_ORIGIN_USERDEFINED_MEMORY_4B;
  Dem_DTCOriginType Test_Dem_DTCOriginType_V_66 = DEM_DTC_ORIGIN_USERDEFINED_MEMORY_4C;
  Dem_DTCOriginType Test_Dem_DTCOriginType_V_67 = DEM_DTC_ORIGIN_USERDEFINED_MEMORY_4D;
  Dem_DTCOriginType Test_Dem_DTCOriginType_V_68 = DEM_DTC_ORIGIN_USERDEFINED_MEMORY_4E;
  Dem_DTCOriginType Test_Dem_DTCOriginType_V_69 = DEM_DTC_ORIGIN_USERDEFINED_MEMORY_4F;
  Dem_DTCOriginType Test_Dem_DTCOriginType_V_70 = DEM_DTC_ORIGIN_USERDEFINED_MEMORY_50;
  Dem_DTCOriginType Test_Dem_DTCOriginType_V_71 = DEM_DTC_ORIGIN_USERDEFINED_MEMORY_51;
  Dem_DTCOriginType Test_Dem_DTCOriginType_V_72 = DEM_DTC_ORIGIN_USERDEFINED_MEMORY_52;
  Dem_DTCOriginType Test_Dem_DTCOriginType_V_73 = DEM_DTC_ORIGIN_USERDEFINED_MEMORY_53;
  Dem_DTCOriginType Test_Dem_DTCOriginType_V_74 = DEM_DTC_ORIGIN_USERDEFINED_MEMORY_54;
  Dem_DTCOriginType Test_Dem_DTCOriginType_V_75 = DEM_DTC_ORIGIN_USERDEFINED_MEMORY_55;
  Dem_DTCOriginType Test_Dem_DTCOriginType_V_76 = DEM_DTC_ORIGIN_USERDEFINED_MEMORY_56;
  Dem_DTCOriginType Test_Dem_DTCOriginType_V_77 = DEM_DTC_ORIGIN_USERDEFINED_MEMORY_57;
  Dem_DTCOriginType Test_Dem_DTCOriginType_V_78 = DEM_DTC_ORIGIN_USERDEFINED_MEMORY_58;
  Dem_DTCOriginType Test_Dem_DTCOriginType_V_79 = DEM_DTC_ORIGIN_USERDEFINED_MEMORY_59;
  Dem_DTCOriginType Test_Dem_DTCOriginType_V_80 = DEM_DTC_ORIGIN_USERDEFINED_MEMORY_5A;
  Dem_DTCOriginType Test_Dem_DTCOriginType_V_81 = DEM_DTC_ORIGIN_USERDEFINED_MEMORY_5B;
  Dem_DTCOriginType Test_Dem_DTCOriginType_V_82 = DEM_DTC_ORIGIN_USERDEFINED_MEMORY_5C;
  Dem_DTCOriginType Test_Dem_DTCOriginType_V_83 = DEM_DTC_ORIGIN_USERDEFINED_MEMORY_5D;
  Dem_DTCOriginType Test_Dem_DTCOriginType_V_84 = DEM_DTC_ORIGIN_USERDEFINED_MEMORY_5E;
  Dem_DTCOriginType Test_Dem_DTCOriginType_V_85 = DEM_DTC_ORIGIN_USERDEFINED_MEMORY_5F;
  Dem_DTCOriginType Test_Dem_DTCOriginType_V_86 = DEM_DTC_ORIGIN_USERDEFINED_MEMORY_60;
  Dem_DTCOriginType Test_Dem_DTCOriginType_V_87 = DEM_DTC_ORIGIN_USERDEFINED_MEMORY_61;
  Dem_DTCOriginType Test_Dem_DTCOriginType_V_88 = DEM_DTC_ORIGIN_USERDEFINED_MEMORY_62;
  Dem_DTCOriginType Test_Dem_DTCOriginType_V_89 = DEM_DTC_ORIGIN_USERDEFINED_MEMORY_63;
  Dem_DTCOriginType Test_Dem_DTCOriginType_V_90 = DEM_DTC_ORIGIN_USERDEFINED_MEMORY_64;
  Dem_DTCOriginType Test_Dem_DTCOriginType_V_91 = DEM_DTC_ORIGIN_USERDEFINED_MEMORY_65;
  Dem_DTCOriginType Test_Dem_DTCOriginType_V_92 = DEM_DTC_ORIGIN_USERDEFINED_MEMORY_66;
  Dem_DTCOriginType Test_Dem_DTCOriginType_V_93 = DEM_DTC_ORIGIN_USERDEFINED_MEMORY_67;
  Dem_DTCOriginType Test_Dem_DTCOriginType_V_94 = DEM_DTC_ORIGIN_USERDEFINED_MEMORY_68;
  Dem_DTCOriginType Test_Dem_DTCOriginType_V_95 = DEM_DTC_ORIGIN_USERDEFINED_MEMORY_69;
  Dem_DTCOriginType Test_Dem_DTCOriginType_V_96 = DEM_DTC_ORIGIN_USERDEFINED_MEMORY_6A;
  Dem_DTCOriginType Test_Dem_DTCOriginType_V_97 = DEM_DTC_ORIGIN_USERDEFINED_MEMORY_6B;
  Dem_DTCOriginType Test_Dem_DTCOriginType_V_98 = DEM_DTC_ORIGIN_USERDEFINED_MEMORY_6C;
  Dem_DTCOriginType Test_Dem_DTCOriginType_V_99 = DEM_DTC_ORIGIN_USERDEFINED_MEMORY_6D;
  Dem_DTCOriginType Test_Dem_DTCOriginType_V_100 = DEM_DTC_ORIGIN_USERDEFINED_MEMORY_6E;
  Dem_DTCOriginType Test_Dem_DTCOriginType_V_101 = DEM_DTC_ORIGIN_USERDEFINED_MEMORY_6F;
  Dem_DTCOriginType Test_Dem_DTCOriginType_V_102 = DEM_DTC_ORIGIN_USERDEFINED_MEMORY_70;
  Dem_DTCOriginType Test_Dem_DTCOriginType_V_103 = DEM_DTC_ORIGIN_USERDEFINED_MEMORY_71;
  Dem_DTCOriginType Test_Dem_DTCOriginType_V_104 = DEM_DTC_ORIGIN_USERDEFINED_MEMORY_72;
  Dem_DTCOriginType Test_Dem_DTCOriginType_V_105 = DEM_DTC_ORIGIN_USERDEFINED_MEMORY_73;
  Dem_DTCOriginType Test_Dem_DTCOriginType_V_106 = DEM_DTC_ORIGIN_USERDEFINED_MEMORY_74;
  Dem_DTCOriginType Test_Dem_DTCOriginType_V_107 = DEM_DTC_ORIGIN_USERDEFINED_MEMORY_75;
  Dem_DTCOriginType Test_Dem_DTCOriginType_V_108 = DEM_DTC_ORIGIN_USERDEFINED_MEMORY_76;
  Dem_DTCOriginType Test_Dem_DTCOriginType_V_109 = DEM_DTC_ORIGIN_USERDEFINED_MEMORY_77;
  Dem_DTCOriginType Test_Dem_DTCOriginType_V_110 = DEM_DTC_ORIGIN_USERDEFINED_MEMORY_78;
  Dem_DTCOriginType Test_Dem_DTCOriginType_V_111 = DEM_DTC_ORIGIN_USERDEFINED_MEMORY_79;
  Dem_DTCOriginType Test_Dem_DTCOriginType_V_112 = DEM_DTC_ORIGIN_USERDEFINED_MEMORY_7A;
  Dem_DTCOriginType Test_Dem_DTCOriginType_V_113 = DEM_DTC_ORIGIN_USERDEFINED_MEMORY_7B;
  Dem_DTCOriginType Test_Dem_DTCOriginType_V_114 = DEM_DTC_ORIGIN_USERDEFINED_MEMORY_7C;
  Dem_DTCOriginType Test_Dem_DTCOriginType_V_115 = DEM_DTC_ORIGIN_USERDEFINED_MEMORY_7D;
  Dem_DTCOriginType Test_Dem_DTCOriginType_V_116 = DEM_DTC_ORIGIN_USERDEFINED_MEMORY_7E;
  Dem_DTCOriginType Test_Dem_DTCOriginType_V_117 = DEM_DTC_ORIGIN_USERDEFINED_MEMORY_7F;
  Dem_DTCOriginType Test_Dem_DTCOriginType_V_118 = DEM_DTC_ORIGIN_USERDEFINED_MEMORY_80;
  Dem_DTCOriginType Test_Dem_DTCOriginType_V_119 = DEM_DTC_ORIGIN_USERDEFINED_MEMORY_81;
  Dem_DTCOriginType Test_Dem_DTCOriginType_V_120 = DEM_DTC_ORIGIN_USERDEFINED_MEMORY_82;
  Dem_DTCOriginType Test_Dem_DTCOriginType_V_121 = DEM_DTC_ORIGIN_USERDEFINED_MEMORY_83;
  Dem_DTCOriginType Test_Dem_DTCOriginType_V_122 = DEM_DTC_ORIGIN_USERDEFINED_MEMORY_84;
  Dem_DTCOriginType Test_Dem_DTCOriginType_V_123 = DEM_DTC_ORIGIN_USERDEFINED_MEMORY_85;
  Dem_DTCOriginType Test_Dem_DTCOriginType_V_124 = DEM_DTC_ORIGIN_USERDEFINED_MEMORY_86;
  Dem_DTCOriginType Test_Dem_DTCOriginType_V_125 = DEM_DTC_ORIGIN_USERDEFINED_MEMORY_87;
  Dem_DTCOriginType Test_Dem_DTCOriginType_V_126 = DEM_DTC_ORIGIN_USERDEFINED_MEMORY_88;
  Dem_DTCOriginType Test_Dem_DTCOriginType_V_127 = DEM_DTC_ORIGIN_USERDEFINED_MEMORY_89;
  Dem_DTCOriginType Test_Dem_DTCOriginType_V_128 = DEM_DTC_ORIGIN_USERDEFINED_MEMORY_8A;
  Dem_DTCOriginType Test_Dem_DTCOriginType_V_129 = DEM_DTC_ORIGIN_USERDEFINED_MEMORY_8B;
  Dem_DTCOriginType Test_Dem_DTCOriginType_V_130 = DEM_DTC_ORIGIN_USERDEFINED_MEMORY_8C;
  Dem_DTCOriginType Test_Dem_DTCOriginType_V_131 = DEM_DTC_ORIGIN_USERDEFINED_MEMORY_8D;
  Dem_DTCOriginType Test_Dem_DTCOriginType_V_132 = DEM_DTC_ORIGIN_USERDEFINED_MEMORY_8E;
  Dem_DTCOriginType Test_Dem_DTCOriginType_V_133 = DEM_DTC_ORIGIN_USERDEFINED_MEMORY_8F;
  Dem_DTCOriginType Test_Dem_DTCOriginType_V_134 = DEM_DTC_ORIGIN_USERDEFINED_MEMORY_90;
  Dem_DTCOriginType Test_Dem_DTCOriginType_V_135 = DEM_DTC_ORIGIN_USERDEFINED_MEMORY_91;
  Dem_DTCOriginType Test_Dem_DTCOriginType_V_136 = DEM_DTC_ORIGIN_USERDEFINED_MEMORY_92;
  Dem_DTCOriginType Test_Dem_DTCOriginType_V_137 = DEM_DTC_ORIGIN_USERDEFINED_MEMORY_93;
  Dem_DTCOriginType Test_Dem_DTCOriginType_V_138 = DEM_DTC_ORIGIN_USERDEFINED_MEMORY_94;
  Dem_DTCOriginType Test_Dem_DTCOriginType_V_139 = DEM_DTC_ORIGIN_USERDEFINED_MEMORY_95;
  Dem_DTCOriginType Test_Dem_DTCOriginType_V_140 = DEM_DTC_ORIGIN_USERDEFINED_MEMORY_96;
  Dem_DTCOriginType Test_Dem_DTCOriginType_V_141 = DEM_DTC_ORIGIN_USERDEFINED_MEMORY_97;
  Dem_DTCOriginType Test_Dem_DTCOriginType_V_142 = DEM_DTC_ORIGIN_USERDEFINED_MEMORY_98;
  Dem_DTCOriginType Test_Dem_DTCOriginType_V_143 = DEM_DTC_ORIGIN_USERDEFINED_MEMORY_99;
  Dem_DTCOriginType Test_Dem_DTCOriginType_V_144 = DEM_DTC_ORIGIN_USERDEFINED_MEMORY_9A;
  Dem_DTCOriginType Test_Dem_DTCOriginType_V_145 = DEM_DTC_ORIGIN_USERDEFINED_MEMORY_9B;
  Dem_DTCOriginType Test_Dem_DTCOriginType_V_146 = DEM_DTC_ORIGIN_USERDEFINED_MEMORY_9C;
  Dem_DTCOriginType Test_Dem_DTCOriginType_V_147 = DEM_DTC_ORIGIN_USERDEFINED_MEMORY_9D;
  Dem_DTCOriginType Test_Dem_DTCOriginType_V_148 = DEM_DTC_ORIGIN_USERDEFINED_MEMORY_9E;
  Dem_DTCOriginType Test_Dem_DTCOriginType_V_149 = DEM_DTC_ORIGIN_USERDEFINED_MEMORY_9F;
  Dem_DTCOriginType Test_Dem_DTCOriginType_V_150 = DEM_DTC_ORIGIN_USERDEFINED_MEMORY_A0;
  Dem_DTCOriginType Test_Dem_DTCOriginType_V_151 = DEM_DTC_ORIGIN_USERDEFINED_MEMORY_A1;
  Dem_DTCOriginType Test_Dem_DTCOriginType_V_152 = DEM_DTC_ORIGIN_USERDEFINED_MEMORY_A2;
  Dem_DTCOriginType Test_Dem_DTCOriginType_V_153 = DEM_DTC_ORIGIN_USERDEFINED_MEMORY_A3;
  Dem_DTCOriginType Test_Dem_DTCOriginType_V_154 = DEM_DTC_ORIGIN_USERDEFINED_MEMORY_A4;
  Dem_DTCOriginType Test_Dem_DTCOriginType_V_155 = DEM_DTC_ORIGIN_USERDEFINED_MEMORY_A5;
  Dem_DTCOriginType Test_Dem_DTCOriginType_V_156 = DEM_DTC_ORIGIN_USERDEFINED_MEMORY_A6;
  Dem_DTCOriginType Test_Dem_DTCOriginType_V_157 = DEM_DTC_ORIGIN_USERDEFINED_MEMORY_A7;
  Dem_DTCOriginType Test_Dem_DTCOriginType_V_158 = DEM_DTC_ORIGIN_USERDEFINED_MEMORY_A8;
  Dem_DTCOriginType Test_Dem_DTCOriginType_V_159 = DEM_DTC_ORIGIN_USERDEFINED_MEMORY_A9;
  Dem_DTCOriginType Test_Dem_DTCOriginType_V_160 = DEM_DTC_ORIGIN_USERDEFINED_MEMORY_AA;
  Dem_DTCOriginType Test_Dem_DTCOriginType_V_161 = DEM_DTC_ORIGIN_USERDEFINED_MEMORY_AB;
  Dem_DTCOriginType Test_Dem_DTCOriginType_V_162 = DEM_DTC_ORIGIN_USERDEFINED_MEMORY_AC;
  Dem_DTCOriginType Test_Dem_DTCOriginType_V_163 = DEM_DTC_ORIGIN_USERDEFINED_MEMORY_AD;
  Dem_DTCOriginType Test_Dem_DTCOriginType_V_164 = DEM_DTC_ORIGIN_USERDEFINED_MEMORY_AE;
  Dem_DTCOriginType Test_Dem_DTCOriginType_V_165 = DEM_DTC_ORIGIN_USERDEFINED_MEMORY_AF;
  Dem_DTCOriginType Test_Dem_DTCOriginType_V_166 = DEM_DTC_ORIGIN_USERDEFINED_MEMORY_B0;
  Dem_DTCOriginType Test_Dem_DTCOriginType_V_167 = DEM_DTC_ORIGIN_USERDEFINED_MEMORY_B1;
  Dem_DTCOriginType Test_Dem_DTCOriginType_V_168 = DEM_DTC_ORIGIN_USERDEFINED_MEMORY_B2;
  Dem_DTCOriginType Test_Dem_DTCOriginType_V_169 = DEM_DTC_ORIGIN_USERDEFINED_MEMORY_B3;
  Dem_DTCOriginType Test_Dem_DTCOriginType_V_170 = DEM_DTC_ORIGIN_USERDEFINED_MEMORY_B4;
  Dem_DTCOriginType Test_Dem_DTCOriginType_V_171 = DEM_DTC_ORIGIN_USERDEFINED_MEMORY_B5;
  Dem_DTCOriginType Test_Dem_DTCOriginType_V_172 = DEM_DTC_ORIGIN_USERDEFINED_MEMORY_B6;
  Dem_DTCOriginType Test_Dem_DTCOriginType_V_173 = DEM_DTC_ORIGIN_USERDEFINED_MEMORY_B7;
  Dem_DTCOriginType Test_Dem_DTCOriginType_V_174 = DEM_DTC_ORIGIN_USERDEFINED_MEMORY_B8;
  Dem_DTCOriginType Test_Dem_DTCOriginType_V_175 = DEM_DTC_ORIGIN_USERDEFINED_MEMORY_B9;
  Dem_DTCOriginType Test_Dem_DTCOriginType_V_176 = DEM_DTC_ORIGIN_USERDEFINED_MEMORY_BA;
  Dem_DTCOriginType Test_Dem_DTCOriginType_V_177 = DEM_DTC_ORIGIN_USERDEFINED_MEMORY_BB;
  Dem_DTCOriginType Test_Dem_DTCOriginType_V_178 = DEM_DTC_ORIGIN_USERDEFINED_MEMORY_BC;
  Dem_DTCOriginType Test_Dem_DTCOriginType_V_179 = DEM_DTC_ORIGIN_USERDEFINED_MEMORY_BD;
  Dem_DTCOriginType Test_Dem_DTCOriginType_V_180 = DEM_DTC_ORIGIN_USERDEFINED_MEMORY_BE;
  Dem_DTCOriginType Test_Dem_DTCOriginType_V_181 = DEM_DTC_ORIGIN_USERDEFINED_MEMORY_BF;
  Dem_DTCOriginType Test_Dem_DTCOriginType_V_182 = DEM_DTC_ORIGIN_USERDEFINED_MEMORY_C0;
  Dem_DTCOriginType Test_Dem_DTCOriginType_V_183 = DEM_DTC_ORIGIN_USERDEFINED_MEMORY_C1;
  Dem_DTCOriginType Test_Dem_DTCOriginType_V_184 = DEM_DTC_ORIGIN_USERDEFINED_MEMORY_C2;
  Dem_DTCOriginType Test_Dem_DTCOriginType_V_185 = DEM_DTC_ORIGIN_USERDEFINED_MEMORY_C3;
  Dem_DTCOriginType Test_Dem_DTCOriginType_V_186 = DEM_DTC_ORIGIN_USERDEFINED_MEMORY_C4;
  Dem_DTCOriginType Test_Dem_DTCOriginType_V_187 = DEM_DTC_ORIGIN_USERDEFINED_MEMORY_C5;
  Dem_DTCOriginType Test_Dem_DTCOriginType_V_188 = DEM_DTC_ORIGIN_USERDEFINED_MEMORY_C6;
  Dem_DTCOriginType Test_Dem_DTCOriginType_V_189 = DEM_DTC_ORIGIN_USERDEFINED_MEMORY_C7;
  Dem_DTCOriginType Test_Dem_DTCOriginType_V_190 = DEM_DTC_ORIGIN_USERDEFINED_MEMORY_C8;
  Dem_DTCOriginType Test_Dem_DTCOriginType_V_191 = DEM_DTC_ORIGIN_USERDEFINED_MEMORY_C9;
  Dem_DTCOriginType Test_Dem_DTCOriginType_V_192 = DEM_DTC_ORIGIN_USERDEFINED_MEMORY_CA;
  Dem_DTCOriginType Test_Dem_DTCOriginType_V_193 = DEM_DTC_ORIGIN_USERDEFINED_MEMORY_CB;
  Dem_DTCOriginType Test_Dem_DTCOriginType_V_194 = DEM_DTC_ORIGIN_USERDEFINED_MEMORY_CC;
  Dem_DTCOriginType Test_Dem_DTCOriginType_V_195 = DEM_DTC_ORIGIN_USERDEFINED_MEMORY_CD;
  Dem_DTCOriginType Test_Dem_DTCOriginType_V_196 = DEM_DTC_ORIGIN_USERDEFINED_MEMORY_CE;
  Dem_DTCOriginType Test_Dem_DTCOriginType_V_197 = DEM_DTC_ORIGIN_USERDEFINED_MEMORY_CF;
  Dem_DTCOriginType Test_Dem_DTCOriginType_V_198 = DEM_DTC_ORIGIN_USERDEFINED_MEMORY_D0;
  Dem_DTCOriginType Test_Dem_DTCOriginType_V_199 = DEM_DTC_ORIGIN_USERDEFINED_MEMORY_D1;
  Dem_DTCOriginType Test_Dem_DTCOriginType_V_200 = DEM_DTC_ORIGIN_USERDEFINED_MEMORY_D2;
  Dem_DTCOriginType Test_Dem_DTCOriginType_V_201 = DEM_DTC_ORIGIN_USERDEFINED_MEMORY_D3;
  Dem_DTCOriginType Test_Dem_DTCOriginType_V_202 = DEM_DTC_ORIGIN_USERDEFINED_MEMORY_D4;
  Dem_DTCOriginType Test_Dem_DTCOriginType_V_203 = DEM_DTC_ORIGIN_USERDEFINED_MEMORY_D5;
  Dem_DTCOriginType Test_Dem_DTCOriginType_V_204 = DEM_DTC_ORIGIN_USERDEFINED_MEMORY_D6;
  Dem_DTCOriginType Test_Dem_DTCOriginType_V_205 = DEM_DTC_ORIGIN_USERDEFINED_MEMORY_D7;
  Dem_DTCOriginType Test_Dem_DTCOriginType_V_206 = DEM_DTC_ORIGIN_USERDEFINED_MEMORY_D8;
  Dem_DTCOriginType Test_Dem_DTCOriginType_V_207 = DEM_DTC_ORIGIN_USERDEFINED_MEMORY_D9;
  Dem_DTCOriginType Test_Dem_DTCOriginType_V_208 = DEM_DTC_ORIGIN_USERDEFINED_MEMORY_DA;
  Dem_DTCOriginType Test_Dem_DTCOriginType_V_209 = DEM_DTC_ORIGIN_USERDEFINED_MEMORY_DB;
  Dem_DTCOriginType Test_Dem_DTCOriginType_V_210 = DEM_DTC_ORIGIN_USERDEFINED_MEMORY_DC;
  Dem_DTCOriginType Test_Dem_DTCOriginType_V_211 = DEM_DTC_ORIGIN_USERDEFINED_MEMORY_DD;
  Dem_DTCOriginType Test_Dem_DTCOriginType_V_212 = DEM_DTC_ORIGIN_USERDEFINED_MEMORY_DE;
  Dem_DTCOriginType Test_Dem_DTCOriginType_V_213 = DEM_DTC_ORIGIN_USERDEFINED_MEMORY_DF;
  Dem_DTCOriginType Test_Dem_DTCOriginType_V_214 = DEM_DTC_ORIGIN_USERDEFINED_MEMORY_E0;
  Dem_DTCOriginType Test_Dem_DTCOriginType_V_215 = DEM_DTC_ORIGIN_USERDEFINED_MEMORY_E1;
  Dem_DTCOriginType Test_Dem_DTCOriginType_V_216 = DEM_DTC_ORIGIN_USERDEFINED_MEMORY_E2;
  Dem_DTCOriginType Test_Dem_DTCOriginType_V_217 = DEM_DTC_ORIGIN_USERDEFINED_MEMORY_E3;
  Dem_DTCOriginType Test_Dem_DTCOriginType_V_218 = DEM_DTC_ORIGIN_USERDEFINED_MEMORY_E4;
  Dem_DTCOriginType Test_Dem_DTCOriginType_V_219 = DEM_DTC_ORIGIN_USERDEFINED_MEMORY_E5;
  Dem_DTCOriginType Test_Dem_DTCOriginType_V_220 = DEM_DTC_ORIGIN_USERDEFINED_MEMORY_E6;
  Dem_DTCOriginType Test_Dem_DTCOriginType_V_221 = DEM_DTC_ORIGIN_USERDEFINED_MEMORY_E7;
  Dem_DTCOriginType Test_Dem_DTCOriginType_V_222 = DEM_DTC_ORIGIN_USERDEFINED_MEMORY_E8;
  Dem_DTCOriginType Test_Dem_DTCOriginType_V_223 = DEM_DTC_ORIGIN_USERDEFINED_MEMORY_E9;
  Dem_DTCOriginType Test_Dem_DTCOriginType_V_224 = DEM_DTC_ORIGIN_USERDEFINED_MEMORY_EA;
  Dem_DTCOriginType Test_Dem_DTCOriginType_V_225 = DEM_DTC_ORIGIN_USERDEFINED_MEMORY_EB;
  Dem_DTCOriginType Test_Dem_DTCOriginType_V_226 = DEM_DTC_ORIGIN_USERDEFINED_MEMORY_EC;
  Dem_DTCOriginType Test_Dem_DTCOriginType_V_227 = DEM_DTC_ORIGIN_USERDEFINED_MEMORY_ED;
  Dem_DTCOriginType Test_Dem_DTCOriginType_V_228 = DEM_DTC_ORIGIN_USERDEFINED_MEMORY_EE;
  Dem_DTCOriginType Test_Dem_DTCOriginType_V_229 = DEM_DTC_ORIGIN_USERDEFINED_MEMORY_EF;
  Dem_DTCOriginType Test_Dem_DTCOriginType_V_230 = DEM_DTC_ORIGIN_USERDEFINED_MEMORY_F0;
  Dem_DTCOriginType Test_Dem_DTCOriginType_V_231 = DEM_DTC_ORIGIN_USERDEFINED_MEMORY_F1;
  Dem_DTCOriginType Test_Dem_DTCOriginType_V_232 = DEM_DTC_ORIGIN_USERDEFINED_MEMORY_F2;
  Dem_DTCOriginType Test_Dem_DTCOriginType_V_233 = DEM_DTC_ORIGIN_USERDEFINED_MEMORY_F3;
  Dem_DTCOriginType Test_Dem_DTCOriginType_V_234 = DEM_DTC_ORIGIN_USERDEFINED_MEMORY_F4;
  Dem_DTCOriginType Test_Dem_DTCOriginType_V_235 = DEM_DTC_ORIGIN_USERDEFINED_MEMORY_F5;
  Dem_DTCOriginType Test_Dem_DTCOriginType_V_236 = DEM_DTC_ORIGIN_USERDEFINED_MEMORY_F6;
  Dem_DTCOriginType Test_Dem_DTCOriginType_V_237 = DEM_DTC_ORIGIN_USERDEFINED_MEMORY_F7;
  Dem_DTCOriginType Test_Dem_DTCOriginType_V_238 = DEM_DTC_ORIGIN_USERDEFINED_MEMORY_F8;
  Dem_DTCOriginType Test_Dem_DTCOriginType_V_239 = DEM_DTC_ORIGIN_USERDEFINED_MEMORY_F9;
  Dem_DTCOriginType Test_Dem_DTCOriginType_V_240 = DEM_DTC_ORIGIN_USERDEFINED_MEMORY_FA;
  Dem_DTCOriginType Test_Dem_DTCOriginType_V_241 = DEM_DTC_ORIGIN_USERDEFINED_MEMORY_FB;
  Dem_DTCOriginType Test_Dem_DTCOriginType_V_242 = DEM_DTC_ORIGIN_USERDEFINED_MEMORY_FC;
  Dem_DTCOriginType Test_Dem_DTCOriginType_V_243 = DEM_DTC_ORIGIN_USERDEFINED_MEMORY_FD;
  Dem_DTCOriginType Test_Dem_DTCOriginType_V_244 = DEM_DTC_ORIGIN_USERDEFINED_MEMORY_FE;
  Dem_DTCOriginType Test_Dem_DTCOriginType_V_245 = DEM_DTC_ORIGIN_USERDEFINED_MEMORY_FF;
}

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of function definition area >>              DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of removed code area >>                   DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of removed code area >>                     DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

/**********************************************************************************************************************
 MISRA 2004 violations and justifications
 *********************************************************************************************************************/

/* module specific MISRA deviations:
   MD_Rte_TestCode:
     Reason:     This justification is used within the generated test code by the Rte Analyzer.
     Risk:       No functional risk.
     Prevention: Not required.

*/
