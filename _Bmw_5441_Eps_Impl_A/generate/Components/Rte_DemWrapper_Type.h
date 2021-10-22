/**********************************************************************************************************************
 *  COPYRIGHT
 *  -------------------------------------------------------------------------------------------------------------------
 *
 *                This software is copyright protected and proprietary to Vctr Informatik GmbH.
 *                Vctr Informatik GmbH grants to you only those rights as set out in the license conditions.
 *                All other rights remain with Vctr Informatik GmbH.
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *          File:  Rte_DemWrapper_Type.h
 *        Config:  EPS.dpa
 *   ECU-Project:  EPS
 *
 *     Generator:  MICROSAR RTE Generator Version 4.16.0
 *                 RTE Core Version 1.16.0
 *       License:  Unlimited license CBD1700369 for Nxtr Automotive Corporation
 *
 *   Description:  Application types header file for SW-C <DemWrapper>
 *********************************************************************************************************************/

/* double include prevention */
#ifndef _RTE_DEMWRAPPER_TYPE_H
# define _RTE_DEMWRAPPER_TYPE_H

# ifdef __cplusplus
extern "C"
{
# endif /* __cplusplus */

# include "Rte_Type.h"

# ifndef RTE_CORE

/**********************************************************************************************************************
 * Range, Invalidation, Enumeration and Bit Field Definitions
 *********************************************************************************************************************/

#  ifndef DEM_DTC_FORMAT_OBD
#   define DEM_DTC_FORMAT_OBD (0U)
#  endif

#  ifndef DEM_DTC_FORMAT_UDS
#   define DEM_DTC_FORMAT_UDS (1U)
#  endif

#  ifndef DEM_DTC_FORMAT_J1939
#   define DEM_DTC_FORMAT_J1939 (2U)
#  endif

#  ifndef DEM_DTC_FORMAT_OBD
#   define DEM_DTC_FORMAT_OBD (0U)
#  endif

#  ifndef DEM_DTC_FORMAT_UDS
#   define DEM_DTC_FORMAT_UDS (1U)
#  endif

#  ifndef DEM_DTC_FORMAT_J1939
#   define DEM_DTC_FORMAT_J1939 (2U)
#  endif

#  ifndef DEM_DTC_FORMAT_OBD
#   define DEM_DTC_FORMAT_OBD (0U)
#  endif

#  ifndef DEM_DTC_FORMAT_UDS
#   define DEM_DTC_FORMAT_UDS (1U)
#  endif

#  ifndef DEM_DTC_FORMAT_J1939
#   define DEM_DTC_FORMAT_J1939 (2U)
#  endif

#  ifndef DEM_DTC_ORIGIN_PRIMARY_MEMORY
#   define DEM_DTC_ORIGIN_PRIMARY_MEMORY (1U)
#  endif

#  ifndef DEM_DTC_ORIGIN_MIRROR_MEMORY
#   define DEM_DTC_ORIGIN_MIRROR_MEMORY (2U)
#  endif

#  ifndef DEM_DTC_ORIGIN_PERMANENT_MEMORY
#   define DEM_DTC_ORIGIN_PERMANENT_MEMORY (3U)
#  endif

#  ifndef DEM_DTC_ORIGIN_OBD_RELEVANT_MEMORY
#   define DEM_DTC_ORIGIN_OBD_RELEVANT_MEMORY (4U)
#  endif

#  ifndef DEM_DTC_ORIGIN_SECONDARY_MEMORY
#   define DEM_DTC_ORIGIN_SECONDARY_MEMORY (5U)
#  endif

#  ifndef DEM_DTC_ORIGIN_USERDEFINED_MEMORY_10
#   define DEM_DTC_ORIGIN_USERDEFINED_MEMORY_10 (5U)
#  endif

#  ifndef DEM_DTC_ORIGIN_USERDEFINED_MEMORY_11
#   define DEM_DTC_ORIGIN_USERDEFINED_MEMORY_11 (5U)
#  endif

#  ifndef DEM_DTC_ORIGIN_USERDEFINED_MEMORY_12
#   define DEM_DTC_ORIGIN_USERDEFINED_MEMORY_12 (5U)
#  endif

#  ifndef DEM_DTC_ORIGIN_USERDEFINED_MEMORY_13
#   define DEM_DTC_ORIGIN_USERDEFINED_MEMORY_13 (5U)
#  endif

#  ifndef DEM_DTC_ORIGIN_USERDEFINED_MEMORY_14
#   define DEM_DTC_ORIGIN_USERDEFINED_MEMORY_14 (5U)
#  endif

#  ifndef DEM_DTC_ORIGIN_USERDEFINED_MEMORY_15
#   define DEM_DTC_ORIGIN_USERDEFINED_MEMORY_15 (5U)
#  endif

#  ifndef DEM_DTC_ORIGIN_USERDEFINED_MEMORY_16
#   define DEM_DTC_ORIGIN_USERDEFINED_MEMORY_16 (5U)
#  endif

#  ifndef DEM_DTC_ORIGIN_USERDEFINED_MEMORY_17
#   define DEM_DTC_ORIGIN_USERDEFINED_MEMORY_17 (5U)
#  endif

#  ifndef DEM_DTC_ORIGIN_USERDEFINED_MEMORY_18
#   define DEM_DTC_ORIGIN_USERDEFINED_MEMORY_18 (5U)
#  endif

#  ifndef DEM_DTC_ORIGIN_USERDEFINED_MEMORY_19
#   define DEM_DTC_ORIGIN_USERDEFINED_MEMORY_19 (5U)
#  endif

#  ifndef DEM_DTC_ORIGIN_USERDEFINED_MEMORY_1A
#   define DEM_DTC_ORIGIN_USERDEFINED_MEMORY_1A (5U)
#  endif

#  ifndef DEM_DTC_ORIGIN_USERDEFINED_MEMORY_1B
#   define DEM_DTC_ORIGIN_USERDEFINED_MEMORY_1B (5U)
#  endif

#  ifndef DEM_DTC_ORIGIN_USERDEFINED_MEMORY_1C
#   define DEM_DTC_ORIGIN_USERDEFINED_MEMORY_1C (5U)
#  endif

#  ifndef DEM_DTC_ORIGIN_USERDEFINED_MEMORY_1D
#   define DEM_DTC_ORIGIN_USERDEFINED_MEMORY_1D (5U)
#  endif

#  ifndef DEM_DTC_ORIGIN_USERDEFINED_MEMORY_1E
#   define DEM_DTC_ORIGIN_USERDEFINED_MEMORY_1E (5U)
#  endif

#  ifndef DEM_DTC_ORIGIN_USERDEFINED_MEMORY_1F
#   define DEM_DTC_ORIGIN_USERDEFINED_MEMORY_1F (5U)
#  endif

#  ifndef DEM_DTC_ORIGIN_USERDEFINED_MEMORY_20
#   define DEM_DTC_ORIGIN_USERDEFINED_MEMORY_20 (5U)
#  endif

#  ifndef DEM_DTC_ORIGIN_USERDEFINED_MEMORY_21
#   define DEM_DTC_ORIGIN_USERDEFINED_MEMORY_21 (5U)
#  endif

#  ifndef DEM_DTC_ORIGIN_USERDEFINED_MEMORY_22
#   define DEM_DTC_ORIGIN_USERDEFINED_MEMORY_22 (5U)
#  endif

#  ifndef DEM_DTC_ORIGIN_USERDEFINED_MEMORY_23
#   define DEM_DTC_ORIGIN_USERDEFINED_MEMORY_23 (5U)
#  endif

#  ifndef DEM_DTC_ORIGIN_USERDEFINED_MEMORY_24
#   define DEM_DTC_ORIGIN_USERDEFINED_MEMORY_24 (5U)
#  endif

#  ifndef DEM_DTC_ORIGIN_USERDEFINED_MEMORY_25
#   define DEM_DTC_ORIGIN_USERDEFINED_MEMORY_25 (5U)
#  endif

#  ifndef DEM_DTC_ORIGIN_USERDEFINED_MEMORY_26
#   define DEM_DTC_ORIGIN_USERDEFINED_MEMORY_26 (5U)
#  endif

#  ifndef DEM_DTC_ORIGIN_USERDEFINED_MEMORY_27
#   define DEM_DTC_ORIGIN_USERDEFINED_MEMORY_27 (5U)
#  endif

#  ifndef DEM_DTC_ORIGIN_USERDEFINED_MEMORY_28
#   define DEM_DTC_ORIGIN_USERDEFINED_MEMORY_28 (5U)
#  endif

#  ifndef DEM_DTC_ORIGIN_USERDEFINED_MEMORY_29
#   define DEM_DTC_ORIGIN_USERDEFINED_MEMORY_29 (5U)
#  endif

#  ifndef DEM_DTC_ORIGIN_USERDEFINED_MEMORY_2A
#   define DEM_DTC_ORIGIN_USERDEFINED_MEMORY_2A (5U)
#  endif

#  ifndef DEM_DTC_ORIGIN_USERDEFINED_MEMORY_2B
#   define DEM_DTC_ORIGIN_USERDEFINED_MEMORY_2B (5U)
#  endif

#  ifndef DEM_DTC_ORIGIN_USERDEFINED_MEMORY_2C
#   define DEM_DTC_ORIGIN_USERDEFINED_MEMORY_2C (5U)
#  endif

#  ifndef DEM_DTC_ORIGIN_USERDEFINED_MEMORY_2D
#   define DEM_DTC_ORIGIN_USERDEFINED_MEMORY_2D (5U)
#  endif

#  ifndef DEM_DTC_ORIGIN_USERDEFINED_MEMORY_2E
#   define DEM_DTC_ORIGIN_USERDEFINED_MEMORY_2E (5U)
#  endif

#  ifndef DEM_DTC_ORIGIN_USERDEFINED_MEMORY_2F
#   define DEM_DTC_ORIGIN_USERDEFINED_MEMORY_2F (5U)
#  endif

#  ifndef DEM_DTC_ORIGIN_USERDEFINED_MEMORY_30
#   define DEM_DTC_ORIGIN_USERDEFINED_MEMORY_30 (5U)
#  endif

#  ifndef DEM_DTC_ORIGIN_USERDEFINED_MEMORY_31
#   define DEM_DTC_ORIGIN_USERDEFINED_MEMORY_31 (5U)
#  endif

#  ifndef DEM_DTC_ORIGIN_USERDEFINED_MEMORY_32
#   define DEM_DTC_ORIGIN_USERDEFINED_MEMORY_32 (5U)
#  endif

#  ifndef DEM_DTC_ORIGIN_USERDEFINED_MEMORY_33
#   define DEM_DTC_ORIGIN_USERDEFINED_MEMORY_33 (5U)
#  endif

#  ifndef DEM_DTC_ORIGIN_USERDEFINED_MEMORY_34
#   define DEM_DTC_ORIGIN_USERDEFINED_MEMORY_34 (5U)
#  endif

#  ifndef DEM_DTC_ORIGIN_USERDEFINED_MEMORY_35
#   define DEM_DTC_ORIGIN_USERDEFINED_MEMORY_35 (5U)
#  endif

#  ifndef DEM_DTC_ORIGIN_USERDEFINED_MEMORY_36
#   define DEM_DTC_ORIGIN_USERDEFINED_MEMORY_36 (5U)
#  endif

#  ifndef DEM_DTC_ORIGIN_USERDEFINED_MEMORY_37
#   define DEM_DTC_ORIGIN_USERDEFINED_MEMORY_37 (5U)
#  endif

#  ifndef DEM_DTC_ORIGIN_USERDEFINED_MEMORY_38
#   define DEM_DTC_ORIGIN_USERDEFINED_MEMORY_38 (5U)
#  endif

#  ifndef DEM_DTC_ORIGIN_USERDEFINED_MEMORY_39
#   define DEM_DTC_ORIGIN_USERDEFINED_MEMORY_39 (5U)
#  endif

#  ifndef DEM_DTC_ORIGIN_USERDEFINED_MEMORY_3A
#   define DEM_DTC_ORIGIN_USERDEFINED_MEMORY_3A (5U)
#  endif

#  ifndef DEM_DTC_ORIGIN_USERDEFINED_MEMORY_3B
#   define DEM_DTC_ORIGIN_USERDEFINED_MEMORY_3B (5U)
#  endif

#  ifndef DEM_DTC_ORIGIN_USERDEFINED_MEMORY_3C
#   define DEM_DTC_ORIGIN_USERDEFINED_MEMORY_3C (5U)
#  endif

#  ifndef DEM_DTC_ORIGIN_USERDEFINED_MEMORY_3D
#   define DEM_DTC_ORIGIN_USERDEFINED_MEMORY_3D (5U)
#  endif

#  ifndef DEM_DTC_ORIGIN_USERDEFINED_MEMORY_3E
#   define DEM_DTC_ORIGIN_USERDEFINED_MEMORY_3E (5U)
#  endif

#  ifndef DEM_DTC_ORIGIN_USERDEFINED_MEMORY_3F
#   define DEM_DTC_ORIGIN_USERDEFINED_MEMORY_3F (5U)
#  endif

#  ifndef DEM_DTC_ORIGIN_USERDEFINED_MEMORY_40
#   define DEM_DTC_ORIGIN_USERDEFINED_MEMORY_40 (5U)
#  endif

#  ifndef DEM_DTC_ORIGIN_USERDEFINED_MEMORY_41
#   define DEM_DTC_ORIGIN_USERDEFINED_MEMORY_41 (5U)
#  endif

#  ifndef DEM_DTC_ORIGIN_USERDEFINED_MEMORY_42
#   define DEM_DTC_ORIGIN_USERDEFINED_MEMORY_42 (5U)
#  endif

#  ifndef DEM_DTC_ORIGIN_USERDEFINED_MEMORY_43
#   define DEM_DTC_ORIGIN_USERDEFINED_MEMORY_43 (5U)
#  endif

#  ifndef DEM_DTC_ORIGIN_USERDEFINED_MEMORY_44
#   define DEM_DTC_ORIGIN_USERDEFINED_MEMORY_44 (5U)
#  endif

#  ifndef DEM_DTC_ORIGIN_USERDEFINED_MEMORY_45
#   define DEM_DTC_ORIGIN_USERDEFINED_MEMORY_45 (5U)
#  endif

#  ifndef DEM_DTC_ORIGIN_USERDEFINED_MEMORY_46
#   define DEM_DTC_ORIGIN_USERDEFINED_MEMORY_46 (5U)
#  endif

#  ifndef DEM_DTC_ORIGIN_USERDEFINED_MEMORY_47
#   define DEM_DTC_ORIGIN_USERDEFINED_MEMORY_47 (5U)
#  endif

#  ifndef DEM_DTC_ORIGIN_USERDEFINED_MEMORY_48
#   define DEM_DTC_ORIGIN_USERDEFINED_MEMORY_48 (5U)
#  endif

#  ifndef DEM_DTC_ORIGIN_USERDEFINED_MEMORY_49
#   define DEM_DTC_ORIGIN_USERDEFINED_MEMORY_49 (5U)
#  endif

#  ifndef DEM_DTC_ORIGIN_USERDEFINED_MEMORY_4A
#   define DEM_DTC_ORIGIN_USERDEFINED_MEMORY_4A (5U)
#  endif

#  ifndef DEM_DTC_ORIGIN_USERDEFINED_MEMORY_4B
#   define DEM_DTC_ORIGIN_USERDEFINED_MEMORY_4B (5U)
#  endif

#  ifndef DEM_DTC_ORIGIN_USERDEFINED_MEMORY_4C
#   define DEM_DTC_ORIGIN_USERDEFINED_MEMORY_4C (5U)
#  endif

#  ifndef DEM_DTC_ORIGIN_USERDEFINED_MEMORY_4D
#   define DEM_DTC_ORIGIN_USERDEFINED_MEMORY_4D (5U)
#  endif

#  ifndef DEM_DTC_ORIGIN_USERDEFINED_MEMORY_4E
#   define DEM_DTC_ORIGIN_USERDEFINED_MEMORY_4E (5U)
#  endif

#  ifndef DEM_DTC_ORIGIN_USERDEFINED_MEMORY_4F
#   define DEM_DTC_ORIGIN_USERDEFINED_MEMORY_4F (5U)
#  endif

#  ifndef DEM_DTC_ORIGIN_USERDEFINED_MEMORY_50
#   define DEM_DTC_ORIGIN_USERDEFINED_MEMORY_50 (5U)
#  endif

#  ifndef DEM_DTC_ORIGIN_USERDEFINED_MEMORY_51
#   define DEM_DTC_ORIGIN_USERDEFINED_MEMORY_51 (5U)
#  endif

#  ifndef DEM_DTC_ORIGIN_USERDEFINED_MEMORY_52
#   define DEM_DTC_ORIGIN_USERDEFINED_MEMORY_52 (5U)
#  endif

#  ifndef DEM_DTC_ORIGIN_USERDEFINED_MEMORY_53
#   define DEM_DTC_ORIGIN_USERDEFINED_MEMORY_53 (5U)
#  endif

#  ifndef DEM_DTC_ORIGIN_USERDEFINED_MEMORY_54
#   define DEM_DTC_ORIGIN_USERDEFINED_MEMORY_54 (5U)
#  endif

#  ifndef DEM_DTC_ORIGIN_USERDEFINED_MEMORY_55
#   define DEM_DTC_ORIGIN_USERDEFINED_MEMORY_55 (5U)
#  endif

#  ifndef DEM_DTC_ORIGIN_USERDEFINED_MEMORY_56
#   define DEM_DTC_ORIGIN_USERDEFINED_MEMORY_56 (5U)
#  endif

#  ifndef DEM_DTC_ORIGIN_USERDEFINED_MEMORY_57
#   define DEM_DTC_ORIGIN_USERDEFINED_MEMORY_57 (5U)
#  endif

#  ifndef DEM_DTC_ORIGIN_USERDEFINED_MEMORY_58
#   define DEM_DTC_ORIGIN_USERDEFINED_MEMORY_58 (5U)
#  endif

#  ifndef DEM_DTC_ORIGIN_USERDEFINED_MEMORY_59
#   define DEM_DTC_ORIGIN_USERDEFINED_MEMORY_59 (5U)
#  endif

#  ifndef DEM_DTC_ORIGIN_USERDEFINED_MEMORY_5A
#   define DEM_DTC_ORIGIN_USERDEFINED_MEMORY_5A (5U)
#  endif

#  ifndef DEM_DTC_ORIGIN_USERDEFINED_MEMORY_5B
#   define DEM_DTC_ORIGIN_USERDEFINED_MEMORY_5B (5U)
#  endif

#  ifndef DEM_DTC_ORIGIN_USERDEFINED_MEMORY_5C
#   define DEM_DTC_ORIGIN_USERDEFINED_MEMORY_5C (5U)
#  endif

#  ifndef DEM_DTC_ORIGIN_USERDEFINED_MEMORY_5D
#   define DEM_DTC_ORIGIN_USERDEFINED_MEMORY_5D (5U)
#  endif

#  ifndef DEM_DTC_ORIGIN_USERDEFINED_MEMORY_5E
#   define DEM_DTC_ORIGIN_USERDEFINED_MEMORY_5E (5U)
#  endif

#  ifndef DEM_DTC_ORIGIN_USERDEFINED_MEMORY_5F
#   define DEM_DTC_ORIGIN_USERDEFINED_MEMORY_5F (5U)
#  endif

#  ifndef DEM_DTC_ORIGIN_USERDEFINED_MEMORY_60
#   define DEM_DTC_ORIGIN_USERDEFINED_MEMORY_60 (5U)
#  endif

#  ifndef DEM_DTC_ORIGIN_USERDEFINED_MEMORY_61
#   define DEM_DTC_ORIGIN_USERDEFINED_MEMORY_61 (5U)
#  endif

#  ifndef DEM_DTC_ORIGIN_USERDEFINED_MEMORY_62
#   define DEM_DTC_ORIGIN_USERDEFINED_MEMORY_62 (5U)
#  endif

#  ifndef DEM_DTC_ORIGIN_USERDEFINED_MEMORY_63
#   define DEM_DTC_ORIGIN_USERDEFINED_MEMORY_63 (5U)
#  endif

#  ifndef DEM_DTC_ORIGIN_USERDEFINED_MEMORY_64
#   define DEM_DTC_ORIGIN_USERDEFINED_MEMORY_64 (5U)
#  endif

#  ifndef DEM_DTC_ORIGIN_USERDEFINED_MEMORY_65
#   define DEM_DTC_ORIGIN_USERDEFINED_MEMORY_65 (5U)
#  endif

#  ifndef DEM_DTC_ORIGIN_USERDEFINED_MEMORY_66
#   define DEM_DTC_ORIGIN_USERDEFINED_MEMORY_66 (5U)
#  endif

#  ifndef DEM_DTC_ORIGIN_USERDEFINED_MEMORY_67
#   define DEM_DTC_ORIGIN_USERDEFINED_MEMORY_67 (5U)
#  endif

#  ifndef DEM_DTC_ORIGIN_USERDEFINED_MEMORY_68
#   define DEM_DTC_ORIGIN_USERDEFINED_MEMORY_68 (5U)
#  endif

#  ifndef DEM_DTC_ORIGIN_USERDEFINED_MEMORY_69
#   define DEM_DTC_ORIGIN_USERDEFINED_MEMORY_69 (5U)
#  endif

#  ifndef DEM_DTC_ORIGIN_USERDEFINED_MEMORY_6A
#   define DEM_DTC_ORIGIN_USERDEFINED_MEMORY_6A (5U)
#  endif

#  ifndef DEM_DTC_ORIGIN_USERDEFINED_MEMORY_6B
#   define DEM_DTC_ORIGIN_USERDEFINED_MEMORY_6B (5U)
#  endif

#  ifndef DEM_DTC_ORIGIN_USERDEFINED_MEMORY_6C
#   define DEM_DTC_ORIGIN_USERDEFINED_MEMORY_6C (5U)
#  endif

#  ifndef DEM_DTC_ORIGIN_USERDEFINED_MEMORY_6D
#   define DEM_DTC_ORIGIN_USERDEFINED_MEMORY_6D (5U)
#  endif

#  ifndef DEM_DTC_ORIGIN_USERDEFINED_MEMORY_6E
#   define DEM_DTC_ORIGIN_USERDEFINED_MEMORY_6E (5U)
#  endif

#  ifndef DEM_DTC_ORIGIN_USERDEFINED_MEMORY_6F
#   define DEM_DTC_ORIGIN_USERDEFINED_MEMORY_6F (5U)
#  endif

#  ifndef DEM_DTC_ORIGIN_USERDEFINED_MEMORY_70
#   define DEM_DTC_ORIGIN_USERDEFINED_MEMORY_70 (5U)
#  endif

#  ifndef DEM_DTC_ORIGIN_USERDEFINED_MEMORY_71
#   define DEM_DTC_ORIGIN_USERDEFINED_MEMORY_71 (5U)
#  endif

#  ifndef DEM_DTC_ORIGIN_USERDEFINED_MEMORY_72
#   define DEM_DTC_ORIGIN_USERDEFINED_MEMORY_72 (5U)
#  endif

#  ifndef DEM_DTC_ORIGIN_USERDEFINED_MEMORY_73
#   define DEM_DTC_ORIGIN_USERDEFINED_MEMORY_73 (5U)
#  endif

#  ifndef DEM_DTC_ORIGIN_USERDEFINED_MEMORY_74
#   define DEM_DTC_ORIGIN_USERDEFINED_MEMORY_74 (5U)
#  endif

#  ifndef DEM_DTC_ORIGIN_USERDEFINED_MEMORY_75
#   define DEM_DTC_ORIGIN_USERDEFINED_MEMORY_75 (5U)
#  endif

#  ifndef DEM_DTC_ORIGIN_USERDEFINED_MEMORY_76
#   define DEM_DTC_ORIGIN_USERDEFINED_MEMORY_76 (5U)
#  endif

#  ifndef DEM_DTC_ORIGIN_USERDEFINED_MEMORY_77
#   define DEM_DTC_ORIGIN_USERDEFINED_MEMORY_77 (5U)
#  endif

#  ifndef DEM_DTC_ORIGIN_USERDEFINED_MEMORY_78
#   define DEM_DTC_ORIGIN_USERDEFINED_MEMORY_78 (5U)
#  endif

#  ifndef DEM_DTC_ORIGIN_USERDEFINED_MEMORY_79
#   define DEM_DTC_ORIGIN_USERDEFINED_MEMORY_79 (5U)
#  endif

#  ifndef DEM_DTC_ORIGIN_USERDEFINED_MEMORY_7A
#   define DEM_DTC_ORIGIN_USERDEFINED_MEMORY_7A (5U)
#  endif

#  ifndef DEM_DTC_ORIGIN_USERDEFINED_MEMORY_7B
#   define DEM_DTC_ORIGIN_USERDEFINED_MEMORY_7B (5U)
#  endif

#  ifndef DEM_DTC_ORIGIN_USERDEFINED_MEMORY_7C
#   define DEM_DTC_ORIGIN_USERDEFINED_MEMORY_7C (5U)
#  endif

#  ifndef DEM_DTC_ORIGIN_USERDEFINED_MEMORY_7D
#   define DEM_DTC_ORIGIN_USERDEFINED_MEMORY_7D (5U)
#  endif

#  ifndef DEM_DTC_ORIGIN_USERDEFINED_MEMORY_7E
#   define DEM_DTC_ORIGIN_USERDEFINED_MEMORY_7E (5U)
#  endif

#  ifndef DEM_DTC_ORIGIN_USERDEFINED_MEMORY_7F
#   define DEM_DTC_ORIGIN_USERDEFINED_MEMORY_7F (5U)
#  endif

#  ifndef DEM_DTC_ORIGIN_USERDEFINED_MEMORY_80
#   define DEM_DTC_ORIGIN_USERDEFINED_MEMORY_80 (5U)
#  endif

#  ifndef DEM_DTC_ORIGIN_USERDEFINED_MEMORY_81
#   define DEM_DTC_ORIGIN_USERDEFINED_MEMORY_81 (5U)
#  endif

#  ifndef DEM_DTC_ORIGIN_USERDEFINED_MEMORY_82
#   define DEM_DTC_ORIGIN_USERDEFINED_MEMORY_82 (5U)
#  endif

#  ifndef DEM_DTC_ORIGIN_USERDEFINED_MEMORY_83
#   define DEM_DTC_ORIGIN_USERDEFINED_MEMORY_83 (5U)
#  endif

#  ifndef DEM_DTC_ORIGIN_USERDEFINED_MEMORY_84
#   define DEM_DTC_ORIGIN_USERDEFINED_MEMORY_84 (5U)
#  endif

#  ifndef DEM_DTC_ORIGIN_USERDEFINED_MEMORY_85
#   define DEM_DTC_ORIGIN_USERDEFINED_MEMORY_85 (5U)
#  endif

#  ifndef DEM_DTC_ORIGIN_USERDEFINED_MEMORY_86
#   define DEM_DTC_ORIGIN_USERDEFINED_MEMORY_86 (5U)
#  endif

#  ifndef DEM_DTC_ORIGIN_USERDEFINED_MEMORY_87
#   define DEM_DTC_ORIGIN_USERDEFINED_MEMORY_87 (5U)
#  endif

#  ifndef DEM_DTC_ORIGIN_USERDEFINED_MEMORY_88
#   define DEM_DTC_ORIGIN_USERDEFINED_MEMORY_88 (5U)
#  endif

#  ifndef DEM_DTC_ORIGIN_USERDEFINED_MEMORY_89
#   define DEM_DTC_ORIGIN_USERDEFINED_MEMORY_89 (5U)
#  endif

#  ifndef DEM_DTC_ORIGIN_USERDEFINED_MEMORY_8A
#   define DEM_DTC_ORIGIN_USERDEFINED_MEMORY_8A (5U)
#  endif

#  ifndef DEM_DTC_ORIGIN_USERDEFINED_MEMORY_8B
#   define DEM_DTC_ORIGIN_USERDEFINED_MEMORY_8B (5U)
#  endif

#  ifndef DEM_DTC_ORIGIN_USERDEFINED_MEMORY_8C
#   define DEM_DTC_ORIGIN_USERDEFINED_MEMORY_8C (5U)
#  endif

#  ifndef DEM_DTC_ORIGIN_USERDEFINED_MEMORY_8D
#   define DEM_DTC_ORIGIN_USERDEFINED_MEMORY_8D (5U)
#  endif

#  ifndef DEM_DTC_ORIGIN_USERDEFINED_MEMORY_8E
#   define DEM_DTC_ORIGIN_USERDEFINED_MEMORY_8E (5U)
#  endif

#  ifndef DEM_DTC_ORIGIN_USERDEFINED_MEMORY_8F
#   define DEM_DTC_ORIGIN_USERDEFINED_MEMORY_8F (5U)
#  endif

#  ifndef DEM_DTC_ORIGIN_USERDEFINED_MEMORY_90
#   define DEM_DTC_ORIGIN_USERDEFINED_MEMORY_90 (5U)
#  endif

#  ifndef DEM_DTC_ORIGIN_USERDEFINED_MEMORY_91
#   define DEM_DTC_ORIGIN_USERDEFINED_MEMORY_91 (5U)
#  endif

#  ifndef DEM_DTC_ORIGIN_USERDEFINED_MEMORY_92
#   define DEM_DTC_ORIGIN_USERDEFINED_MEMORY_92 (5U)
#  endif

#  ifndef DEM_DTC_ORIGIN_USERDEFINED_MEMORY_93
#   define DEM_DTC_ORIGIN_USERDEFINED_MEMORY_93 (5U)
#  endif

#  ifndef DEM_DTC_ORIGIN_USERDEFINED_MEMORY_94
#   define DEM_DTC_ORIGIN_USERDEFINED_MEMORY_94 (5U)
#  endif

#  ifndef DEM_DTC_ORIGIN_USERDEFINED_MEMORY_95
#   define DEM_DTC_ORIGIN_USERDEFINED_MEMORY_95 (5U)
#  endif

#  ifndef DEM_DTC_ORIGIN_USERDEFINED_MEMORY_96
#   define DEM_DTC_ORIGIN_USERDEFINED_MEMORY_96 (5U)
#  endif

#  ifndef DEM_DTC_ORIGIN_USERDEFINED_MEMORY_97
#   define DEM_DTC_ORIGIN_USERDEFINED_MEMORY_97 (5U)
#  endif

#  ifndef DEM_DTC_ORIGIN_USERDEFINED_MEMORY_98
#   define DEM_DTC_ORIGIN_USERDEFINED_MEMORY_98 (5U)
#  endif

#  ifndef DEM_DTC_ORIGIN_USERDEFINED_MEMORY_99
#   define DEM_DTC_ORIGIN_USERDEFINED_MEMORY_99 (5U)
#  endif

#  ifndef DEM_DTC_ORIGIN_USERDEFINED_MEMORY_9A
#   define DEM_DTC_ORIGIN_USERDEFINED_MEMORY_9A (5U)
#  endif

#  ifndef DEM_DTC_ORIGIN_USERDEFINED_MEMORY_9B
#   define DEM_DTC_ORIGIN_USERDEFINED_MEMORY_9B (5U)
#  endif

#  ifndef DEM_DTC_ORIGIN_USERDEFINED_MEMORY_9C
#   define DEM_DTC_ORIGIN_USERDEFINED_MEMORY_9C (5U)
#  endif

#  ifndef DEM_DTC_ORIGIN_USERDEFINED_MEMORY_9D
#   define DEM_DTC_ORIGIN_USERDEFINED_MEMORY_9D (5U)
#  endif

#  ifndef DEM_DTC_ORIGIN_USERDEFINED_MEMORY_9E
#   define DEM_DTC_ORIGIN_USERDEFINED_MEMORY_9E (5U)
#  endif

#  ifndef DEM_DTC_ORIGIN_USERDEFINED_MEMORY_9F
#   define DEM_DTC_ORIGIN_USERDEFINED_MEMORY_9F (5U)
#  endif

#  ifndef DEM_DTC_ORIGIN_USERDEFINED_MEMORY_A0
#   define DEM_DTC_ORIGIN_USERDEFINED_MEMORY_A0 (5U)
#  endif

#  ifndef DEM_DTC_ORIGIN_USERDEFINED_MEMORY_A1
#   define DEM_DTC_ORIGIN_USERDEFINED_MEMORY_A1 (5U)
#  endif

#  ifndef DEM_DTC_ORIGIN_USERDEFINED_MEMORY_A2
#   define DEM_DTC_ORIGIN_USERDEFINED_MEMORY_A2 (5U)
#  endif

#  ifndef DEM_DTC_ORIGIN_USERDEFINED_MEMORY_A3
#   define DEM_DTC_ORIGIN_USERDEFINED_MEMORY_A3 (5U)
#  endif

#  ifndef DEM_DTC_ORIGIN_USERDEFINED_MEMORY_A4
#   define DEM_DTC_ORIGIN_USERDEFINED_MEMORY_A4 (5U)
#  endif

#  ifndef DEM_DTC_ORIGIN_USERDEFINED_MEMORY_A5
#   define DEM_DTC_ORIGIN_USERDEFINED_MEMORY_A5 (5U)
#  endif

#  ifndef DEM_DTC_ORIGIN_USERDEFINED_MEMORY_A6
#   define DEM_DTC_ORIGIN_USERDEFINED_MEMORY_A6 (5U)
#  endif

#  ifndef DEM_DTC_ORIGIN_USERDEFINED_MEMORY_A7
#   define DEM_DTC_ORIGIN_USERDEFINED_MEMORY_A7 (5U)
#  endif

#  ifndef DEM_DTC_ORIGIN_USERDEFINED_MEMORY_A8
#   define DEM_DTC_ORIGIN_USERDEFINED_MEMORY_A8 (5U)
#  endif

#  ifndef DEM_DTC_ORIGIN_USERDEFINED_MEMORY_A9
#   define DEM_DTC_ORIGIN_USERDEFINED_MEMORY_A9 (5U)
#  endif

#  ifndef DEM_DTC_ORIGIN_USERDEFINED_MEMORY_AA
#   define DEM_DTC_ORIGIN_USERDEFINED_MEMORY_AA (5U)
#  endif

#  ifndef DEM_DTC_ORIGIN_USERDEFINED_MEMORY_AB
#   define DEM_DTC_ORIGIN_USERDEFINED_MEMORY_AB (5U)
#  endif

#  ifndef DEM_DTC_ORIGIN_USERDEFINED_MEMORY_AC
#   define DEM_DTC_ORIGIN_USERDEFINED_MEMORY_AC (5U)
#  endif

#  ifndef DEM_DTC_ORIGIN_USERDEFINED_MEMORY_AD
#   define DEM_DTC_ORIGIN_USERDEFINED_MEMORY_AD (5U)
#  endif

#  ifndef DEM_DTC_ORIGIN_USERDEFINED_MEMORY_AE
#   define DEM_DTC_ORIGIN_USERDEFINED_MEMORY_AE (5U)
#  endif

#  ifndef DEM_DTC_ORIGIN_USERDEFINED_MEMORY_AF
#   define DEM_DTC_ORIGIN_USERDEFINED_MEMORY_AF (5U)
#  endif

#  ifndef DEM_DTC_ORIGIN_USERDEFINED_MEMORY_B0
#   define DEM_DTC_ORIGIN_USERDEFINED_MEMORY_B0 (5U)
#  endif

#  ifndef DEM_DTC_ORIGIN_USERDEFINED_MEMORY_B1
#   define DEM_DTC_ORIGIN_USERDEFINED_MEMORY_B1 (5U)
#  endif

#  ifndef DEM_DTC_ORIGIN_USERDEFINED_MEMORY_B2
#   define DEM_DTC_ORIGIN_USERDEFINED_MEMORY_B2 (5U)
#  endif

#  ifndef DEM_DTC_ORIGIN_USERDEFINED_MEMORY_B3
#   define DEM_DTC_ORIGIN_USERDEFINED_MEMORY_B3 (5U)
#  endif

#  ifndef DEM_DTC_ORIGIN_USERDEFINED_MEMORY_B4
#   define DEM_DTC_ORIGIN_USERDEFINED_MEMORY_B4 (5U)
#  endif

#  ifndef DEM_DTC_ORIGIN_USERDEFINED_MEMORY_B5
#   define DEM_DTC_ORIGIN_USERDEFINED_MEMORY_B5 (5U)
#  endif

#  ifndef DEM_DTC_ORIGIN_USERDEFINED_MEMORY_B6
#   define DEM_DTC_ORIGIN_USERDEFINED_MEMORY_B6 (5U)
#  endif

#  ifndef DEM_DTC_ORIGIN_USERDEFINED_MEMORY_B7
#   define DEM_DTC_ORIGIN_USERDEFINED_MEMORY_B7 (5U)
#  endif

#  ifndef DEM_DTC_ORIGIN_USERDEFINED_MEMORY_B8
#   define DEM_DTC_ORIGIN_USERDEFINED_MEMORY_B8 (5U)
#  endif

#  ifndef DEM_DTC_ORIGIN_USERDEFINED_MEMORY_B9
#   define DEM_DTC_ORIGIN_USERDEFINED_MEMORY_B9 (5U)
#  endif

#  ifndef DEM_DTC_ORIGIN_USERDEFINED_MEMORY_BA
#   define DEM_DTC_ORIGIN_USERDEFINED_MEMORY_BA (5U)
#  endif

#  ifndef DEM_DTC_ORIGIN_USERDEFINED_MEMORY_BB
#   define DEM_DTC_ORIGIN_USERDEFINED_MEMORY_BB (5U)
#  endif

#  ifndef DEM_DTC_ORIGIN_USERDEFINED_MEMORY_BC
#   define DEM_DTC_ORIGIN_USERDEFINED_MEMORY_BC (5U)
#  endif

#  ifndef DEM_DTC_ORIGIN_USERDEFINED_MEMORY_BD
#   define DEM_DTC_ORIGIN_USERDEFINED_MEMORY_BD (5U)
#  endif

#  ifndef DEM_DTC_ORIGIN_USERDEFINED_MEMORY_BE
#   define DEM_DTC_ORIGIN_USERDEFINED_MEMORY_BE (5U)
#  endif

#  ifndef DEM_DTC_ORIGIN_USERDEFINED_MEMORY_BF
#   define DEM_DTC_ORIGIN_USERDEFINED_MEMORY_BF (5U)
#  endif

#  ifndef DEM_DTC_ORIGIN_USERDEFINED_MEMORY_C0
#   define DEM_DTC_ORIGIN_USERDEFINED_MEMORY_C0 (5U)
#  endif

#  ifndef DEM_DTC_ORIGIN_USERDEFINED_MEMORY_C1
#   define DEM_DTC_ORIGIN_USERDEFINED_MEMORY_C1 (5U)
#  endif

#  ifndef DEM_DTC_ORIGIN_USERDEFINED_MEMORY_C2
#   define DEM_DTC_ORIGIN_USERDEFINED_MEMORY_C2 (5U)
#  endif

#  ifndef DEM_DTC_ORIGIN_USERDEFINED_MEMORY_C3
#   define DEM_DTC_ORIGIN_USERDEFINED_MEMORY_C3 (5U)
#  endif

#  ifndef DEM_DTC_ORIGIN_USERDEFINED_MEMORY_C4
#   define DEM_DTC_ORIGIN_USERDEFINED_MEMORY_C4 (5U)
#  endif

#  ifndef DEM_DTC_ORIGIN_USERDEFINED_MEMORY_C5
#   define DEM_DTC_ORIGIN_USERDEFINED_MEMORY_C5 (5U)
#  endif

#  ifndef DEM_DTC_ORIGIN_USERDEFINED_MEMORY_C6
#   define DEM_DTC_ORIGIN_USERDEFINED_MEMORY_C6 (5U)
#  endif

#  ifndef DEM_DTC_ORIGIN_USERDEFINED_MEMORY_C7
#   define DEM_DTC_ORIGIN_USERDEFINED_MEMORY_C7 (5U)
#  endif

#  ifndef DEM_DTC_ORIGIN_USERDEFINED_MEMORY_C8
#   define DEM_DTC_ORIGIN_USERDEFINED_MEMORY_C8 (5U)
#  endif

#  ifndef DEM_DTC_ORIGIN_USERDEFINED_MEMORY_C9
#   define DEM_DTC_ORIGIN_USERDEFINED_MEMORY_C9 (5U)
#  endif

#  ifndef DEM_DTC_ORIGIN_USERDEFINED_MEMORY_CA
#   define DEM_DTC_ORIGIN_USERDEFINED_MEMORY_CA (5U)
#  endif

#  ifndef DEM_DTC_ORIGIN_USERDEFINED_MEMORY_CB
#   define DEM_DTC_ORIGIN_USERDEFINED_MEMORY_CB (5U)
#  endif

#  ifndef DEM_DTC_ORIGIN_USERDEFINED_MEMORY_CC
#   define DEM_DTC_ORIGIN_USERDEFINED_MEMORY_CC (5U)
#  endif

#  ifndef DEM_DTC_ORIGIN_USERDEFINED_MEMORY_CD
#   define DEM_DTC_ORIGIN_USERDEFINED_MEMORY_CD (5U)
#  endif

#  ifndef DEM_DTC_ORIGIN_USERDEFINED_MEMORY_CE
#   define DEM_DTC_ORIGIN_USERDEFINED_MEMORY_CE (5U)
#  endif

#  ifndef DEM_DTC_ORIGIN_USERDEFINED_MEMORY_CF
#   define DEM_DTC_ORIGIN_USERDEFINED_MEMORY_CF (5U)
#  endif

#  ifndef DEM_DTC_ORIGIN_USERDEFINED_MEMORY_D0
#   define DEM_DTC_ORIGIN_USERDEFINED_MEMORY_D0 (5U)
#  endif

#  ifndef DEM_DTC_ORIGIN_USERDEFINED_MEMORY_D1
#   define DEM_DTC_ORIGIN_USERDEFINED_MEMORY_D1 (5U)
#  endif

#  ifndef DEM_DTC_ORIGIN_USERDEFINED_MEMORY_D2
#   define DEM_DTC_ORIGIN_USERDEFINED_MEMORY_D2 (5U)
#  endif

#  ifndef DEM_DTC_ORIGIN_USERDEFINED_MEMORY_D3
#   define DEM_DTC_ORIGIN_USERDEFINED_MEMORY_D3 (5U)
#  endif

#  ifndef DEM_DTC_ORIGIN_USERDEFINED_MEMORY_D4
#   define DEM_DTC_ORIGIN_USERDEFINED_MEMORY_D4 (5U)
#  endif

#  ifndef DEM_DTC_ORIGIN_USERDEFINED_MEMORY_D5
#   define DEM_DTC_ORIGIN_USERDEFINED_MEMORY_D5 (5U)
#  endif

#  ifndef DEM_DTC_ORIGIN_USERDEFINED_MEMORY_D6
#   define DEM_DTC_ORIGIN_USERDEFINED_MEMORY_D6 (5U)
#  endif

#  ifndef DEM_DTC_ORIGIN_USERDEFINED_MEMORY_D7
#   define DEM_DTC_ORIGIN_USERDEFINED_MEMORY_D7 (5U)
#  endif

#  ifndef DEM_DTC_ORIGIN_USERDEFINED_MEMORY_D8
#   define DEM_DTC_ORIGIN_USERDEFINED_MEMORY_D8 (5U)
#  endif

#  ifndef DEM_DTC_ORIGIN_USERDEFINED_MEMORY_D9
#   define DEM_DTC_ORIGIN_USERDEFINED_MEMORY_D9 (5U)
#  endif

#  ifndef DEM_DTC_ORIGIN_USERDEFINED_MEMORY_DA
#   define DEM_DTC_ORIGIN_USERDEFINED_MEMORY_DA (5U)
#  endif

#  ifndef DEM_DTC_ORIGIN_USERDEFINED_MEMORY_DB
#   define DEM_DTC_ORIGIN_USERDEFINED_MEMORY_DB (5U)
#  endif

#  ifndef DEM_DTC_ORIGIN_USERDEFINED_MEMORY_DC
#   define DEM_DTC_ORIGIN_USERDEFINED_MEMORY_DC (5U)
#  endif

#  ifndef DEM_DTC_ORIGIN_USERDEFINED_MEMORY_DD
#   define DEM_DTC_ORIGIN_USERDEFINED_MEMORY_DD (5U)
#  endif

#  ifndef DEM_DTC_ORIGIN_USERDEFINED_MEMORY_DE
#   define DEM_DTC_ORIGIN_USERDEFINED_MEMORY_DE (5U)
#  endif

#  ifndef DEM_DTC_ORIGIN_USERDEFINED_MEMORY_DF
#   define DEM_DTC_ORIGIN_USERDEFINED_MEMORY_DF (5U)
#  endif

#  ifndef DEM_DTC_ORIGIN_USERDEFINED_MEMORY_E0
#   define DEM_DTC_ORIGIN_USERDEFINED_MEMORY_E0 (5U)
#  endif

#  ifndef DEM_DTC_ORIGIN_USERDEFINED_MEMORY_E1
#   define DEM_DTC_ORIGIN_USERDEFINED_MEMORY_E1 (5U)
#  endif

#  ifndef DEM_DTC_ORIGIN_USERDEFINED_MEMORY_E2
#   define DEM_DTC_ORIGIN_USERDEFINED_MEMORY_E2 (5U)
#  endif

#  ifndef DEM_DTC_ORIGIN_USERDEFINED_MEMORY_E3
#   define DEM_DTC_ORIGIN_USERDEFINED_MEMORY_E3 (5U)
#  endif

#  ifndef DEM_DTC_ORIGIN_USERDEFINED_MEMORY_E4
#   define DEM_DTC_ORIGIN_USERDEFINED_MEMORY_E4 (5U)
#  endif

#  ifndef DEM_DTC_ORIGIN_USERDEFINED_MEMORY_E5
#   define DEM_DTC_ORIGIN_USERDEFINED_MEMORY_E5 (5U)
#  endif

#  ifndef DEM_DTC_ORIGIN_USERDEFINED_MEMORY_E6
#   define DEM_DTC_ORIGIN_USERDEFINED_MEMORY_E6 (5U)
#  endif

#  ifndef DEM_DTC_ORIGIN_USERDEFINED_MEMORY_E7
#   define DEM_DTC_ORIGIN_USERDEFINED_MEMORY_E7 (5U)
#  endif

#  ifndef DEM_DTC_ORIGIN_USERDEFINED_MEMORY_E8
#   define DEM_DTC_ORIGIN_USERDEFINED_MEMORY_E8 (5U)
#  endif

#  ifndef DEM_DTC_ORIGIN_USERDEFINED_MEMORY_E9
#   define DEM_DTC_ORIGIN_USERDEFINED_MEMORY_E9 (5U)
#  endif

#  ifndef DEM_DTC_ORIGIN_USERDEFINED_MEMORY_EA
#   define DEM_DTC_ORIGIN_USERDEFINED_MEMORY_EA (5U)
#  endif

#  ifndef DEM_DTC_ORIGIN_USERDEFINED_MEMORY_EB
#   define DEM_DTC_ORIGIN_USERDEFINED_MEMORY_EB (5U)
#  endif

#  ifndef DEM_DTC_ORIGIN_USERDEFINED_MEMORY_EC
#   define DEM_DTC_ORIGIN_USERDEFINED_MEMORY_EC (5U)
#  endif

#  ifndef DEM_DTC_ORIGIN_USERDEFINED_MEMORY_ED
#   define DEM_DTC_ORIGIN_USERDEFINED_MEMORY_ED (5U)
#  endif

#  ifndef DEM_DTC_ORIGIN_USERDEFINED_MEMORY_EE
#   define DEM_DTC_ORIGIN_USERDEFINED_MEMORY_EE (5U)
#  endif

#  ifndef DEM_DTC_ORIGIN_USERDEFINED_MEMORY_EF
#   define DEM_DTC_ORIGIN_USERDEFINED_MEMORY_EF (5U)
#  endif

#  ifndef DEM_DTC_ORIGIN_USERDEFINED_MEMORY_F0
#   define DEM_DTC_ORIGIN_USERDEFINED_MEMORY_F0 (5U)
#  endif

#  ifndef DEM_DTC_ORIGIN_USERDEFINED_MEMORY_F1
#   define DEM_DTC_ORIGIN_USERDEFINED_MEMORY_F1 (5U)
#  endif

#  ifndef DEM_DTC_ORIGIN_USERDEFINED_MEMORY_F2
#   define DEM_DTC_ORIGIN_USERDEFINED_MEMORY_F2 (5U)
#  endif

#  ifndef DEM_DTC_ORIGIN_USERDEFINED_MEMORY_F3
#   define DEM_DTC_ORIGIN_USERDEFINED_MEMORY_F3 (5U)
#  endif

#  ifndef DEM_DTC_ORIGIN_USERDEFINED_MEMORY_F4
#   define DEM_DTC_ORIGIN_USERDEFINED_MEMORY_F4 (5U)
#  endif

#  ifndef DEM_DTC_ORIGIN_USERDEFINED_MEMORY_F5
#   define DEM_DTC_ORIGIN_USERDEFINED_MEMORY_F5 (5U)
#  endif

#  ifndef DEM_DTC_ORIGIN_USERDEFINED_MEMORY_F6
#   define DEM_DTC_ORIGIN_USERDEFINED_MEMORY_F6 (5U)
#  endif

#  ifndef DEM_DTC_ORIGIN_USERDEFINED_MEMORY_F7
#   define DEM_DTC_ORIGIN_USERDEFINED_MEMORY_F7 (5U)
#  endif

#  ifndef DEM_DTC_ORIGIN_USERDEFINED_MEMORY_F8
#   define DEM_DTC_ORIGIN_USERDEFINED_MEMORY_F8 (5U)
#  endif

#  ifndef DEM_DTC_ORIGIN_USERDEFINED_MEMORY_F9
#   define DEM_DTC_ORIGIN_USERDEFINED_MEMORY_F9 (5U)
#  endif

#  ifndef DEM_DTC_ORIGIN_USERDEFINED_MEMORY_FA
#   define DEM_DTC_ORIGIN_USERDEFINED_MEMORY_FA (5U)
#  endif

#  ifndef DEM_DTC_ORIGIN_USERDEFINED_MEMORY_FB
#   define DEM_DTC_ORIGIN_USERDEFINED_MEMORY_FB (5U)
#  endif

#  ifndef DEM_DTC_ORIGIN_USERDEFINED_MEMORY_FC
#   define DEM_DTC_ORIGIN_USERDEFINED_MEMORY_FC (5U)
#  endif

#  ifndef DEM_DTC_ORIGIN_USERDEFINED_MEMORY_FD
#   define DEM_DTC_ORIGIN_USERDEFINED_MEMORY_FD (5U)
#  endif

#  ifndef DEM_DTC_ORIGIN_USERDEFINED_MEMORY_FE
#   define DEM_DTC_ORIGIN_USERDEFINED_MEMORY_FE (5U)
#  endif

#  ifndef DEM_DTC_ORIGIN_USERDEFINED_MEMORY_FF
#   define DEM_DTC_ORIGIN_USERDEFINED_MEMORY_FF (5U)
#  endif

#  ifndef DEM_DTC_ORIGIN_PRIMARY_MEMORY
#   define DEM_DTC_ORIGIN_PRIMARY_MEMORY (1U)
#  endif

#  ifndef DEM_DTC_ORIGIN_MIRROR_MEMORY
#   define DEM_DTC_ORIGIN_MIRROR_MEMORY (2U)
#  endif

#  ifndef DEM_DTC_ORIGIN_PERMANENT_MEMORY
#   define DEM_DTC_ORIGIN_PERMANENT_MEMORY (3U)
#  endif

#  ifndef DEM_DTC_ORIGIN_USERDEFINED_MEMORY_BMWSecondaryErrorMemory
#   define DEM_DTC_ORIGIN_USERDEFINED_MEMORY_BMWSecondaryErrorMemory (4U)
#  endif

# endif /* RTE_CORE */

# ifdef __cplusplus
} /* extern "C" */
# endif /* __cplusplus */

#endif /* _RTE_DEMWRAPPER_TYPE_H */
