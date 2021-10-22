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
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of version logging area >>                DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of version logging area >>                  DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of include and declaration area >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

/*BMW - Start*/
/*------------------------------------------------------------------------------
                      MISRA-Deviations
------------------------------------------------------------------------------*/

/* Violation of MISRA rule 19.6, Reason: #undef is necessary
 * according to memory abstraction */
/* PRQA S 0841 EOF */

/* Violation of MISRA rule 19.15, Reason: File must be included repeatedly
 * according to memory abstraction */
/* PRQA S 0883 EOF */

#if 0

#elif defined (Dlog_START_SEC_CODE)
   #undef     Dlog_START_SEC_CODE
   /*@@@visbch: Mapping to global section in MemMap.h*/
   #define    START_SEC_CODE
#elif defined (Dlog_STOP_SEC_CODE)
   #undef     Dlog_STOP_SEC_CODE
   /*@@@visbch: Mapping to global section in MemMap.h*/
   #define    STOP_SEC_CODE

#elif defined (Dlog_START_SEC_VAR_INIT_8)
   #undef     Dlog_START_SEC_VAR_INIT_8
   /*@@@visbch: Mapping to global section in MemMap.h*/
   #define    START_SEC_VAR_INIT_8BIT
#elif defined (Dlog_STOP_SEC_VAR_INIT_8)
   #undef     Dlog_STOP_SEC_VAR_INIT_8
   /*@@@visbch: Mapping to global section in MemMap.h*/
   #define    STOP_SEC_VAR

#elif defined (Dlog_START_SEC_VAR_INIT_16)
   #undef     Dlog_START_SEC_VAR_INIT_16
   /*@@@visbch: Mapping to global section in MemMap.h*/
   #define    START_SEC_VAR_INIT_16BIT
#elif defined (Dlog_STOP_SEC_VAR_INIT_16)
   #undef     Dlog_STOP_SEC_VAR_INIT_16
   /*@@@visbch: Mapping to global section in MemMap.h*/
   #define    STOP_SEC_VAR

#elif defined (Dlog_START_SEC_VAR_NO_INIT_8)
   #undef     Dlog_START_SEC_VAR_NO_INIT_8
   /*@@@visbch: Mapping to global section in MemMap.h*/
   #define    START_SEC_VAR_NOINIT_8BIT
#elif defined (Dlog_STOP_SEC_VAR_NO_INIT_8)
   #undef     Dlog_STOP_SEC_VAR_NO_INIT_8
   /*@@@visbch: Mapping to global section in MemMap.h*/
   #define    STOP_SEC_VAR

#elif defined (Dlog_START_SEC_VAR_INIT_UNSPECIFIED)
   #undef      Dlog_START_SEC_VAR_INIT_UNSPECIFIED
   /*@@@visbch: Mapping to global section in MemMap.h*/
   #define     START_SEC_VAR_INIT_UNSPECIFIED
#elif defined (Dlog_STOP_SEC_VAR_INIT_UNSPECIFIED)
   #undef      Dlog_STOP_SEC_VAR_INIT_UNSPECIFIED
   /*@@@visbch: Mapping to global section in MemMap.h*/
   #define     STOP_SEC_VAR

#elif defined (Dlog_START_SEC_VAR_NO_INIT_UNSPECIFIED)
   #undef      Dlog_START_SEC_VAR_NO_INIT_UNSPECIFIED
   /*@@@visbch: Mapping to global section in MemMap.h*/
   #define START_SEC_VAR_NOINIT_UNSPECIFIED
#elif defined (Dlog_STOP_SEC_VAR_NO_INIT_UNSPECIFIED)
   #undef      Dlog_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
   /*@@@visbch: Mapping to global section in MemMap.h*/
   #define STOP_SEC_VAR

#elif defined (Dlog_START_SEC_VAR_POWER_ON_CLEARED_UNSPECIFIED)
   #undef      Dlog_START_SEC_VAR_POWER_ON_CLEARED_UNSPECIFIED
   /*@@@visbch: Mapping to global section in MemMap.h*/
   #define START_SEC_VAR_ZERO_INIT_UNSPECIFIED
#elif defined (Dlog_STOP_SEC_VAR_POWER_ON_CLEARED_UNSPECIFIED)
   #undef      Dlog_STOP_SEC_VAR_POWER_ON_CLEARED_UNSPECIFIED
   /*@@@visbch: Mapping to global section in MemMap.h*/
   #define STOP_SEC_VAR

#elif defined (Dlog_START_SEC_VAR_CLEARED_16)
   #undef     Dlog_START_SEC_VAR_CLEARED_16
   /*@@@visbch: Mapping to global section in MemMap.h*/
   #define    START_SEC_VAR_ZERO_INIT_16BIT
#elif defined (Dlog_STOP_SEC_VAR_CLEARED_16)
   #undef     Dlog_STOP_SEC_VAR_CLEARED_16
   /*@@@visbch: Mapping to global section in MemMap.h*/
   #define    STOP_SEC_VAR

#elif defined (Dlog_START_SEC_CONST_16)
   #undef     Dlog_START_SEC_CONST_16
   /*@@@visbch: Mapping to global section in MemMap.h*/
   #define    START_SEC_CONST_16BIT
#elif defined (Dlog_STOP_SEC_CONST_16)
   #undef     Dlog_STOP_SEC_CONST_16
   /*@@@visbch: Mapping to global section in MemMap.h*/
   #define    STOP_SEC_CONST

#elif defined (Dlog_START_SEC_CONST_32)
   #undef     Dlog_START_SEC_CONST_32
   /*@@@visbch: Mapping to global section in MemMap.h*/
   #define    START_SEC_CONST_32BIT
#elif defined (Dlog_STOP_SEC_CONST_32)
   #undef     Dlog_STOP_SEC_CONST_32
   /*@@@visbch: Mapping to global section in MemMap.h*/
   #define    STOP_SEC_CONST

#elif defined (Dlog_START_SEC_CONST_UNSPECIFIED)
   #undef      Dlog_START_SEC_CONST_UNSPECIFIED
   /*@@@visbch: Mapping to global section in MemMap.h*/
   #define START_SEC_CONST_UNSPECIFIED
#elif defined (Dlog_STOP_SEC_CONST_UNSPECIFIED)
   #undef      Dlog_STOP_SEC_CONST_UNSPECIFIED
   /*@@@visbch: Mapping to global section in MemMap.h*/
   #define STOP_SEC_CONST

/* -------------------------------------------------------------------------- */
/*             APPL (Application)                                             */
/* -------------------------------------------------------------------------- */
/* special section for SWE1 description table */
#elif defined (APPL_START_SEC_CONST_SWE1_DESCRIPTION_TABLE)
   #undef      APPL_START_SEC_CONST_SWE1_DESCRIPTION_TABLE
   /*@@@visbch: Mapping to global section in MemMap.h*/
   #define START_SEC_CONST_UNSPECIFIED
//   #pragma ghs section rodata="SWE1DESC"
   #pragma section SWE1DESC "SWE1DESC"
   #if !defined( SWE1DESC_USE_SECTION )
     #pragma use_section SWE1DESC Dlog_Swe1Table
     #define SWE1DESC_USE_SECTION
   #endif
#elif defined (APPL_STOP_SEC_CONST_SWE1_DESCRIPTION_TABLE)
   #undef      APPL_STOP_SEC_CONST_SWE1_DESCRIPTION_TABLE
   /*@@@visbch: Mapping to global section in MemMap.h*/
   #define STOP_SEC_CONST
//   #pragma ghs section rodata=default

/* special section for SWE2 description table */
#elif defined (APPL_START_SEC_CONST_SWE2_DESCRIPTION_TABLE)
   #undef      APPL_START_SEC_CONST_SWE2_DESCRIPTION_TABLE
   /*@@@visbch: Mapping to global section in MemMap.h*/
   #define START_SEC_CONST_UNSPECIFIED
//   #pragma ghs section rodata="SWE2DESC"
   #pragma section SWE2DESC "SWE2DESC"
   #if !defined( SWE2DESC_USE_SECTION )
     #pragma use_section SWE2DESC Dlog_Swe2Table
     #define SWE2DESC_USE_SECTION
   #endif
#elif defined (APPL_STOP_SEC_CONST_SWE2_DESCRIPTION_TABLE)
   #undef      APPL_STOP_SEC_CONST_SWE2_DESCRIPTION_TABLE
   /*@@@visbch: Mapping to global section in MemMap.h*/
   #define STOP_SEC_CONST
//   #pragma ghs section rodata=default

/* special section for SWE3 description table */
#elif defined (APPL_START_SEC_CONST_SWE3_DESCRIPTION_TABLE)
   #undef      APPL_START_SEC_CONST_SWE3_DESCRIPTION_TABLE
   /*@@@visbch: Mapping to global section in MemMap.h*/
   #define START_SEC_CONST_UNSPECIFIED
   #pragma section SWE3DESC "SWE3DESC"
   #if !defined( SWE3DESC_USE_SECTION )
     #pragma use_section SWE3DESC Dlog_Swe3Table
     #define SWE3DESC_USE_SECTION
   #endif
//   #pragma ghs section rodata="SWE3DESC"
#elif defined (APPL_STOP_SEC_CONST_SWE3_DESCRIPTION_TABLE)
   #undef      APPL_STOP_SEC_CONST_SWE3_DESCRIPTION_TABLE
   /*@@@visbch: Mapping to global section in MemMap.h*/
   #define STOP_SEC_CONST
//   #pragma ghs section rodata=default

/* special section for SWE4 description table */
#elif defined (APPL_START_SEC_CONST_SWE4_DESCRIPTION_TABLE)
   #undef      APPL_START_SEC_CONST_SWE4_DESCRIPTION_TABLE
   /*@@@visbch: Mapping to global section in MemMap.h*/
   #define START_SEC_CONST_UNSPECIFIED
//   #pragma ghs section rodata="SWE4DESC"
   #pragma section SWE4DESC "SWE4DESC"
   #if !defined( SWE4DESC_USE_SECTION )
     #pragma use_section SWE4DESC Dlog_Swe4Table
     #define SWE4DESC_USE_SECTION
   #endif
#elif defined (APPL_STOP_SEC_CONST_SWE4_DESCRIPTION_TABLE)
   #undef      APPL_STOP_SEC_CONST_SWE4_DESCRIPTION_TABLE
   /*@@@visbch: Mapping to global section in MemMap.h*/
   #define STOP_SEC_CONST
//   #pragma ghs section rodata=default

/* special section for SWE5 description table */
#elif defined (APPL_START_SEC_CONST_SWE5_DESCRIPTION_TABLE)
   #undef      APPL_START_SEC_CONST_SWE5_DESCRIPTION_TABLE
   /*@@@visbch: Mapping to global section in MemMap.h*/
   #define START_SEC_CONST_UNSPECIFIED
#elif defined (APPL_STOP_SEC_CONST_SWE5_DESCRIPTION_TABLE)
   #undef      APPL_STOP_SEC_CONST_SWE5_DESCRIPTION_TABLE
   /*@@@visbch: Mapping to global section in MemMap.h*/
   #define STOP_SEC_CONST

/* special section for SWE5 description table */
#elif defined (APPL_START_SEC_CONST_SWE6_DESCRIPTION_TABLE)
   #undef      APPL_START_SEC_CONST_SWE6_DESCRIPTION_TABLE
   /*@@@visbch: Mapping to global section in MemMap.h*/
   #define START_SEC_CONST_UNSPECIFIED
#elif defined (APPL_STOP_SEC_CONST_SWE6_DESCRIPTION_TABLE)
   #undef      APPL_STOP_SEC_CONST_SWE6_DESCRIPTION_TABLE
   /*@@@visbch: Mapping to global section in MemMap.h*/
   #define STOP_SEC_CONST

/* special section for SWE5 description table */
#elif defined (APPL_START_SEC_CONST_SWE7_DESCRIPTION_TABLE)
   #undef      APPL_START_SEC_CONST_SWE7_DESCRIPTION_TABLE
   /*@@@visbch: Mapping to global section in MemMap.h*/
   #define START_SEC_CONST_UNSPECIFIED
#elif defined (APPL_STOP_SEC_CONST_SWE7_DESCRIPTION_TABLE)
   #undef      APPL_STOP_SEC_CONST_SWE7_DESCRIPTION_TABLE
   /*@@@visbch: Mapping to global section in MemMap.h*/
   #define STOP_SEC_CONST

/* special section for SWE5 description table */
#elif defined (APPL_START_SEC_CONST_SWE8_DESCRIPTION_TABLE)
   #undef      APPL_START_SEC_CONST_SWE8_DESCRIPTION_TABLE
   /*@@@visbch: Mapping to global section in MemMap.h*/
   #define START_SEC_CONST_UNSPECIFIED
#elif defined (APPL_STOP_SEC_CONST_SWE8_DESCRIPTION_TABLE)
   #undef      APPL_STOP_SEC_CONST_SWE8_DESCRIPTION_TABLE
   /*@@@visbch: Mapping to global section in MemMap.h*/
   #define STOP_SEC_CONST

/* special section for SWE5 description table */
#elif defined (APPL_START_SEC_CONST_SWE9_DESCRIPTION_TABLE)
   #undef      APPL_START_SEC_CONST_SWE9_DESCRIPTION_TABLE
   /*@@@visbch: Mapping to global section in MemMap.h*/
   #define START_SEC_CONST_UNSPECIFIED
#elif defined (APPL_STOP_SEC_CONST_SWE9_DESCRIPTION_TABLE)
   #undef      APPL_STOP_SEC_CONST_SWE9_DESCRIPTION_TABLE
   /*@@@visbch: Mapping to global section in MemMap.h*/
   #define STOP_SEC_CONST

/* special section for SWE1 flash status */
#elif defined (APPL_START_SEC_CONST_SWE1_FLASH_STATUS)
   #undef      APPL_START_SEC_CONST_SWE1_FLASH_STATUS
   /*@@@visbch: Mapping to global section in MemMap.h*/
   #define START_SEC_CONST_UNSPECIFIED
//   #pragma ghs section rodata="SWE1STAT"
   #pragma section SWE1STAT "SWE1STAT"
   #if !defined( SWE1STAT_USE_SECTION )
     #pragma use_section SWE1STAT Dlog_Swe1FlashStatus
     #define SWE1STAT_USE_SECTION
   #endif
#elif defined (APPL_STOP_SEC_CONST_SWE1_FLASH_STATUS)
   #undef      APPL_STOP_SEC_CONST_SWE1_FLASH_STATUS
   /*@@@visbch: Mapping to global section in MemMap.h*/
   #define STOP_SEC_CONST
//  #pragma ghs section rodata=default

/* special section for SWE2 flash status */
#elif defined (APPL_START_SEC_CONST_SWE2_FLASH_STATUS)
   #undef      APPL_START_SEC_CONST_SWE2_FLASH_STATUS
   /*@@@visbch: Mapping to global section in MemMap.h*/
   #define START_SEC_CONST_UNSPECIFIED
//   #pragma ghs section rodata="SWE2STAT"
   #pragma section SWE2STAT "SWE2STAT"
   #if !defined( SWE2STAT_USE_SECTION )
     #pragma use_section SWE2STAT Dlog_Swe2FlashStatus
     #define SWE2STAT_USE_SECTION
   #endif
#elif defined (APPL_STOP_SEC_CONST_SWE2_FLASH_STATUS)
   #undef      APPL_STOP_SEC_CONST_SWE2_FLASH_STATUS
   /*@@@visbch: Mapping to global section in MemMap.h*/
   #define STOP_SEC_CONST
//   #pragma ghs section rodata=default

/* special section for SWE3 flash status */
#elif defined (APPL_START_SEC_CONST_SWE3_FLASH_STATUS)
   #undef      APPL_START_SEC_CONST_SWE3_FLASH_STATUS
   /*@@@visbch: Mapping to global section in MemMap.h*/
   #define START_SEC_CONST_UNSPECIFIED
//   #pragma ghs section rodata="SWE3STAT"
   #pragma section SWE3STAT "SWE3STAT"
   #if !defined( SWE3STAT_USE_SECTION )
     #pragma use_section SWE3STAT Dlog_Swe3FlashStatus
     #define SWE3STAT_USE_SECTION
   #endif
#elif defined (APPL_STOP_SEC_CONST_SWE3_FLASH_STATUS)
   #undef      APPL_STOP_SEC_CONST_SWE3_FLASH_STATUS
   /*@@@visbch: Mapping to global section in MemMap.h*/
   #define STOP_SEC_CONST
//   #pragma ghs section rodata=default

/* special section for SWE4 flash status */
#elif defined (APPL_START_SEC_CONST_SWE4_FLASH_STATUS)
   #undef      APPL_START_SEC_CONST_SWE4_FLASH_STATUS
   /*@@@visbch: Mapping to global section in MemMap.h*/
   #define START_SEC_CONST_UNSPECIFIED
//   #pragma ghs section rodata="SWE4STAT"
   #pragma section SWE4STAT "SWE4STAT"
   #if !defined( SWE4STAT_USE_SECTION )
     #pragma use_section SWE4STAT Dlog_Swe4FlashStatus
     #define SWE4STAT_USE_SECTION
   #endif
#elif defined (APPL_STOP_SEC_CONST_SWE4_FLASH_STATUS)
   #undef      APPL_STOP_SEC_CONST_SWE4_FLASH_STATUS
   /*@@@visbch: Mapping to global section in MemMap.h*/
   #define STOP_SEC_CONST
//   #pragma ghs section rodata=default

/* special section for SWE5 flash status */
#elif defined (APPL_START_SEC_CONST_SWE5_FLASH_STATUS)
   #undef      APPL_START_SEC_CONST_SWE5_FLASH_STATUS
   /*@@@visbch: Mapping to global section in MemMap.h*/
   #define     START_SEC_CONST_UNSPECIFIED
#elif defined (APPL_STOP_SEC_CONST_SWE5_FLASH_STATUS)
   #undef      APPL_STOP_SEC_CONST_SWE5_FLASH_STATUS
   /*@@@visbch: Mapping to global section in MemMap.h*/
   #define STOP_SEC_CONST

/* special section for SWE6 flash status */
#elif defined (APPL_START_SEC_CONST_SWE6_FLASH_STATUS)
   #undef      APPL_START_SEC_CONST_SWE6_FLASH_STATUS
   /*@@@visbch: Mapping to global section in MemMap.h*/
   #define     START_SEC_CONST_UNSPECIFIED
#elif defined (APPL_STOP_SEC_CONST_SWE6_FLASH_STATUS)
   #undef      APPL_STOP_SEC_CONST_SWE6_FLASH_STATUS
   /*@@@visbch: Mapping to global section in MemMap.h*/
   #define STOP_SEC_CONST

/* special section for SWE7 flash status */
#elif defined (APPL_START_SEC_CONST_SWE7_FLASH_STATUS)
   #undef      APPL_START_SEC_CONST_SWE7_FLASH_STATUS
   /*@@@visbch: Mapping to global section in MemMap.h*/
   #define     START_SEC_CONST_UNSPECIFIED
#elif defined (APPL_STOP_SEC_CONST_SWE7_FLASH_STATUS)
   #undef      APPL_STOP_SEC_CONST_SWE7_FLASH_STATUS
   /*@@@visbch: Mapping to global section in MemMap.h*/
   #define STOP_SEC_CONST

/* special section for SWE8 flash status */
#elif defined (APPL_START_SEC_CONST_SWE8_FLASH_STATUS)
   #undef      APPL_START_SEC_CONST_SWE8_FLASH_STATUS
   /*@@@visbch: Mapping to global section in MemMap.h*/
   #define     START_SEC_CONST_UNSPECIFIED
#elif defined (APPL_STOP_SEC_CONST_SWE8_FLASH_STATUS)
   #undef      APPL_STOP_SEC_CONST_SWE8_FLASH_STATUS
   /*@@@visbch: Mapping to global section in MemMap.h*/
   #define STOP_SEC_CONST

/* special section for SWE9 flash status */
#elif defined (APPL_START_SEC_CONST_SWE9_FLASH_STATUS)
   #undef      APPL_START_SEC_CONST_SWE9_FLASH_STATUS
   /*@@@visbch: Mapping to global section in MemMap.h*/
   #define     START_SEC_CONST_UNSPECIFIED
#elif defined (APPL_STOP_SEC_CONST_SWE9_FLASH_STATUS)
   #undef      APPL_STOP_SEC_CONST_SWE9_FLASH_STATUS
   /*@@@visbch: Mapping to global section in MemMap.h*/
   #define STOP_SEC_CONST

/* special section for SWE1 signature */
#elif defined (APPL_START_SEC_CONST_SWE1_SIGNATURE)
   #undef      APPL_START_SEC_CONST_SWE1_SIGNATURE
   /*@@@visbch: Mapping to global section in MemMap.h*/
   #define START_SEC_CONST_UNSPECIFIED
//   #pragma ghs section rodata="SWE1SIGNATURE"
   #pragma section SWE1SIGNATURE "SWE1SIGNATURE"
   #if !defined( SWE1SIG_USE_SECTION )
     #pragma use_section SWE1SIGNATURE Dlog_Swe1Signature
     #define SWE1SIG_USE_SECTION
   #endif
#elif defined (APPL_STOP_SEC_CONST_SWE1_SIGNATURE)
   #undef      APPL_STOP_SEC_CONST_SWE1_SIGNATURE
   /*@@@visbch: Mapping to global section in MemMap.h*/
   #define STOP_SEC_CONST
//  #pragma ghs section rodata=default

/* special section for SWE2 signature */
#elif defined (APPL_START_SEC_CONST_SWE2_SIGNATURE)
   #undef      APPL_START_SEC_CONST_SWE2_SIGNATURE
   /*@@@visbch: Mapping to global section in MemMap.h*/
   #define START_SEC_CONST_UNSPECIFIED
//   #pragma ghs section rodata="SWE2SIGNATURE"
   #pragma section SWE2SIGNATURE "SWE2SIGNATURE"
   #if !defined( SWE2SIG_USE_SECTION )
     #pragma use_section SWE2SIGNATURE Dlog_Swe2Signature
     #define SWE2SIG_USE_SECTION
   #endif
#elif defined (APPL_STOP_SEC_CONST_SWE2_SIGNATURE)
   #undef      APPL_STOP_SEC_CONST_SWE2_SIGNATURE
   /*@@@visbch: Mapping to global section in MemMap.h*/
   #define STOP_SEC_CONST
//  #pragma ghs section rodata=default

/* special section for SWE3 signature */
#elif defined (APPL_START_SEC_CONST_SWE3_SIGNATURE)
   #undef      APPL_START_SEC_CONST_SWE3_SIGNATURE
   /*@@@visbch: Mapping to global section in MemMap.h*/
   #define START_SEC_CONST_UNSPECIFIED
//   #pragma ghs section rodata="SWE3SIGNATURE"
   #pragma section SWE3SIGNATURE "SWE3SIGNATURE"
   #if !defined( SWE3SIG_USE_SECTION )
     #pragma use_section SWE3SIGNATURE Dlog_Swe3Signature
     #define SWE3SIG_USE_SECTION
   #endif
#elif defined (APPL_STOP_SEC_CONST_SWE3_SIGNATURE)
   #undef      APPL_STOP_SEC_CONST_SWE3_SIGNATURE
   /*@@@visbch: Mapping to global section in MemMap.h*/
   #define STOP_SEC_CONST
//  #pragma ghs section rodata=default

/* special section for SWE4 signature */
#elif defined (APPL_START_SEC_CONST_SWE4_SIGNATURE)
   #undef      APPL_START_SEC_CONST_SWE4_SIGNATURE
   /*@@@visbch: Mapping to global section in MemMap.h*/
   #define START_SEC_CONST_UNSPECIFIED
//   #pragma ghs section rodata="SWE4SIGNATURE"
   #pragma section SWE4SIGNATURE "SWE4SIGNATURE"
   #if !defined( SWE4SIG_USE_SECTION )
     #pragma use_section SWE4SIGNATURE Dlog_Swe4Signature
     #define SWE4SIG_USE_SECTION
   #endif
#elif defined (APPL_STOP_SEC_CONST_SWE4_SIGNATURE)
   #undef      APPL_STOP_SEC_CONST_SWE4_SIGNATURE
   /*@@@visbch: Mapping to global section in MemMap.h*/
   #define STOP_SEC_CONST
//   #pragma ghs section rodata=default

/* special section for SWE5 signature */
#elif defined (APPL_START_SEC_CONST_SWE5_SIGNATURE)
   #undef      APPL_START_SEC_CONST_SWE5_SIGNATURE
   /*@@@visbch: Mapping to global section in MemMap.h*/
   #define START_SEC_CONST_UNSPECIFIED
#elif defined (APPL_STOP_SEC_CONST_SWE5_SIGNATURE)
   #undef      APPL_STOP_SEC_CONST_SWE5_SIGNATURE
   /*@@@visbch: Mapping to global section in MemMap.h*/
   #define     STOP_SEC_CONST

/* special section for SWE6 signature */
#elif defined (APPL_START_SEC_CONST_SWE6_SIGNATURE)
   #undef      APPL_START_SEC_CONST_SWE6_SIGNATURE
   /*@@@visbch: Mapping to global section in MemMap.h*/
   #define START_SEC_CONST_UNSPECIFIED
#elif defined (APPL_STOP_SEC_CONST_SWE6_SIGNATURE)
   #undef      APPL_STOP_SEC_CONST_SWE6_SIGNATURE
   /*@@@visbch: Mapping to global section in MemMap.h*/
   #define STOP_SEC_CONST

/* special section for SWE7 signature */
#elif defined (APPL_START_SEC_CONST_SWE7_SIGNATURE)
   #undef      APPL_START_SEC_CONST_SWE7_SIGNATURE
   /*@@@visbch: Mapping to global section in MemMap.h*/
   #define START_SEC_CONST_UNSPECIFIED
#elif defined (APPL_STOP_SEC_CONST_SWE7_SIGNATURE)
   #undef      APPL_STOP_SEC_CONST_SWE7_SIGNATURE
   /*@@@visbch: Mapping to global section in MemMap.h*/
   #define STOP_SEC_CONST

/* special section for SWE8 signature */
#elif defined (APPL_START_SEC_CONST_SWE8_SIGNATURE)
   #undef      APPL_START_SEC_CONST_SWE8_SIGNATURE
   /*@@@visbch: Mapping to global section in MemMap.h*/
   #define START_SEC_CONST_UNSPECIFIED
#elif defined (APPL_STOP_SEC_CONST_SWE8_SIGNATURE)
   #undef      APPL_STOP_SEC_CONST_SWE8_SIGNATURE
   /*@@@visbch: Mapping to global section in MemMap.h*/
   #define STOP_SEC_CONST

/* special section for SWE9 signature */
#elif defined (APPL_START_SEC_CONST_SWE9_SIGNATURE)
   #undef      APPL_START_SEC_CONST_SWE9_SIGNATURE
   /*@@@visbch: Mapping to global section in MemMap.h*/
   #define START_SEC_CONST_UNSPECIFIED
#elif defined (APPL_STOP_SEC_CONST_SWE9_SIGNATURE)
   #undef      APPL_STOP_SEC_CONST_SWE9_SIGNATURE
   /*@@@visbch: Mapping to global section in MemMap.h*/
   #define STOP_SEC_CONST

/* -------------------------------------------------------------------------- */
/*             BL (Bootloader)                                                */
/* -------------------------------------------------------------------------- */
#elif defined (Dlog_START_SEC_CONST_SHARED_SWE_DATA)
   #undef      Dlog_START_SEC_CONST_SHARED_SWE_DATA
   /*@@@visbch: Mapping to global section in MemMap.h*/
  #define START_SEC_CONST_8BIT
//  #pragma ghs section rodata="SHAREDSWEDATA"
  #pragma section SHAREDSWEDATA "SHAREDSWEDATA"
  #if !defined( SHAREDSWEDATA_USE_SECTION )
    #pragma use_section SHAREDSWEDATA Dlog_CommonLogisticBtld
    #define SHAREDSWEDATA_USE_SECTION
  #endif
#elif defined (Dlog_STOP_SEC_CONST_SHARED_SWE_DATA)
   #undef      Dlog_STOP_SEC_CONST_SHARED_SWE_DATA
   /*@@@visbch: Mapping to global section in MemMap.h*/
   #define STOP_SEC_CONST
//  #pragma ghs section rodata=default

#elif defined (Dlog_START_SEC_CONST_SHARED_MEMSEGTBL_DATA)
   #undef      Dlog_START_SEC_CONST_SHARED_MEMSEGTBL_DATA
   /*@@@visbch: Mapping to global section in MemMap.h*/
   #define START_SEC_CONST_UNSPECIFIED
#elif defined (Dlog_STOP_SEC_CONST_SHARED_MEMSEGTBL_DATA)
   #undef      Dlog_STOP_SEC_CONST_SHARED_MEMSEGTBL_DATA
   /*@@@visbch: Mapping to global section in MemMap.h*/
   #define STOP_SEC_CONST


/* special section for boot SWE description table */
#elif defined (BL_START_SEC_CONST_BOOTSWE_DESCRIPTION_TABLE)
   #undef      BL_START_SEC_CONST_BOOTSWE_DESCRIPTION_TABLE
   /*@@@visbch: Mapping to global section in MemMap.h*/
  #define START_SEC_CONST_8BIT
  #pragma section BOOTSWEDESC "BOOTSWEDESC"
  #if !defined( BOOTSWEDESC_USE_SECTION )
    #pragma use_section BOOTSWEDESC Dlog_SweBootTable
    #define BOOTSWEDESC_USE_SECTION
  #endif
#elif defined (BL_STOP_SEC_CONST_BOOTSWE_DESCRIPTION_TABLE)
   #undef      BL_STOP_SEC_CONST_BOOTSWE_DESCRIPTION_TABLE
   /*@@@visbch: Mapping to global section in MemMap.h*/
   #define STOP_SEC_CONST

/* special section for boot SWE data */
#elif defined (Dlog_START_SEC_CONST_BOOT_SWE_DATA)
   #undef      Dlog_START_SEC_CONST_BOOT_SWE_DATA
   /*@@@visbch: Mapping to global section in MemMap.h*/
   #define START_SEC_CONST_UNSPECIFIED
#elif defined (Dlog_STOP_SEC_CONST_BOOT_SWE_DATA)
   #undef      Dlog_STOP_SEC_CONST_BOOT_SWE_DATA
   /*@@@visbch: Mapping to global section in MemMap.h*/
   #define STOP_SEC_CONST

/* special section for boot SWE flash status */
#elif defined (BL_START_SEC_CONST_BOOTSWE_FLASH_STATUS)
   #undef      BL_START_SEC_CONST_BOOTSWE_FLASH_STATUS
   /*@@@visbch: Mapping to global section in MemMap.h*/
     #define START_SEC_CONST_8BIT
  #pragma section BOOTSWESTAT "BOOTSWESTAT"
  #if !defined( BOOTSWESTAT_USE_SECTION )
    #pragma use_section BOOTSWESTAT Dlog_BootFlashStatus
    #define BOOTSWESTAT_USE_SECTION
  #endif
#elif defined (BL_STOP_SEC_CONST_BOOTSWE_FLASH_STATUS)
   #undef      BL_STOP_SEC_CONST_BOOTSWE_FLASH_STATUS
   /*@@@visbch: Mapping to global section in MemMap.h*/
   #define STOP_SEC_CONST

/* special section for boot SWE signature */
#elif defined (BL_START_SEC_CONST_BOOTSWE_SIGNATURE)
   #undef      BL_START_SEC_CONST_BOOTSWE_SIGNATURE
   /*@@@visbch: Mapping to global section in MemMap.h*/
  #define START_SEC_CONST_8BIT
  #pragma section BOOTSWESIGNATURE "BOOTSWESIGNATURE"
  #if !defined( BOOTSWESIGNATURE_USE_SECTION )
    #pragma use_section BOOTSWESIGNATURE Dlog_BootSignature
    #define BOOTSWESIGNATURE_USE_SECTION
  #endif
#elif defined (BL_STOP_SEC_CONST_BOOTSWE_SIGNATURE)
   #undef      BL_STOP_SEC_CONST_BOOTSWE_SIGNATURE
   /*@@@visbch: Mapping to global section in MemMap.h*/
   #define STOP_SEC_CONST

/* -------------------------------------------------------------------------- */
/*             BM (BootManager)                                               */
/* -------------------------------------------------------------------------- */

/* special section for hardware description table */
#elif defined (Dlog_START_SEC_CONST_BM_HW_DESCRIPTION_TABLE)
   #undef      Dlog_START_SEC_CONST_BM_HW_DESCRIPTION_TABLE
   /*@@@visbch: Mapping to global section in MemMap.h*/
  #define START_SEC_CONST_8BIT
  #pragma section HWEDESC "HWEDESC"
  #if !defined( HWDESC_USE_SECTION )
    #pragma use_section HWEDESC Dlog_HwDescData
    #define HWDESC_USE_SECTION
  #endif
#elif defined (Dlog_STOP_SEC_CONST_BM_HW_DESCRIPTION_TABLE)
   #undef      Dlog_STOP_SEC_CONST_BM_HW_DESCRIPTION_TABLE
   /*@@@visbch: Mapping to global section in MemMap.h*/
   #define STOP_SEC_CONST

/* special section for const data that is shared between bootmanager, application and bootloader */
#elif defined (Dlog_START_SEC_CONST_SHARED_BM_DATA)
   #undef      Dlog_START_SEC_CONST_SHARED_BM_DATA
   /*@@@visbch: Mapping to global section in MemMap.h*/
   #define START_SEC_CONST_8BIT
#elif defined (Dlog_STOP_SEC_CONST_SHARED_BM_DATA)
   #undef      Dlog_STOP_SEC_CONST_SHARED_BM_DATA
   /*@@@visbch: Mapping to global section in MemMap.h*/
   #define STOP_SEC_CONST

/* special section for swe status that is shared between bootmanager and bootloader */
#elif defined (Dlog_START_SEC_VAR_SHARED_SWESTATUS)
   #undef      Dlog_START_SEC_VAR_SHARED_SWESTATUS
   /*@@@visbch: Mapping to global section in MemMap.h*/
   #define START_SEC_VAR_NOINIT_UNSPECIFIED
   #pragma section SDATA ".sdata" "DLOG_SWESTATUS" far-absolute
//   #pragma section DLOG_SWESTATUS "DLOG_SWESTATUS"
//   #if !defined( SWESTATUS_USE_SECTION )
//     #pragma use_section DLOG_SWESTATUS Dlog_SweStatus
//     #define SWESTATUS_USE_SECTION
//   #endif
#elif defined (Dlog_STOP_SEC_VAR_SHARED_SWESTATUS)
   #undef      Dlog_STOP_SEC_VAR_SHARED_SWESTATUS
   /*@@@visbch: Mapping to global section in MemMap.h*/
   #define STOP_SEC_VAR
//  #pragma section
   #pragma section SDATA

   
/* special section for swe status that is shared between bootmanager and bootloader */
#elif defined (Dlog_START_SEC_VAR_SHARED_SWEINFOS)
   #undef      Dlog_START_SEC_VAR_SHARED_SWEINFOS
   /*@@@visbch: Mapping to global section in MemMap.h*/
   #define START_SEC_VAR_INIT_UNSPECIFIED
   #pragma section DATA ".data" "DLOG_SWEINFOS" far-absolute
//   #pragma section SWEINFOS "SWEINFOS"
//   #if !defined( SWEINFOS_USE_SECTION )
//     #pragma use_section SWEINFOS Dlog_SweInfos
//     #define SWEINFOS_USE_SECTION
//   #endif
#elif defined (Dlog_STOP_SEC_VAR_SHARED_SWEINFOS)
   #undef      Dlog_STOP_SEC_VAR_SHARED_SWEINFOS
   /*@@@visbch: Mapping to global section in MemMap.h*/
   #define STOP_SEC_VAR
   #pragma section DATA
   
/* special section for swe status that is shared between bootmanager and bootloader */
#elif defined (Dlog_START_SEC_VAR_SHARED_DATA)
   #undef      Dlog_START_SEC_VAR_SHARED_DATA
   /*@@@visbch: Mapping to global section in MemMap.h*/
   #define START_SEC_VAR_INIT_UNSPECIFIED
   #pragma section DATA ".data" "DLOG_SWEDATA" far-absolute
//   #pragma section SWEDLOGDATA "SWEDLOGDATA"
//   #if !defined( SWEDLOGDATA_USE_SECTION )
//     #pragma use_section SWEDLOGDATA Dlog_Data
//     #define SWEDLOGDATA_USE_SECTION
//   #endif
#elif defined (Dlog_STOP_SEC_VAR_SHARED_DATA)
   #undef      Dlog_STOP_SEC_VAR_SHARED_DATA
   /*@@@visbch: Mapping to global section in MemMap.h*/
   #define STOP_SEC_VAR
   #pragma section DATA
   
/* special section for boot status that is shared between bootmanager, application and bootloader */
#elif defined (Dlog_START_SEC_VAR_NOINIT_SHARED_BOOT_STATUS)
   #undef      Dlog_START_SEC_VAR_NOINIT_SHARED_BOOT_STATUS
   /*@@@visbch: Mapping to global section in MemMap.h*/
   #define START_SEC_VAR_NOINIT_8BIT
   #pragma section DATA ".data" "DLOGBOOTSTATUSNOINIT" far-absolute
//   #pragma section DLOGBOOTSTATUSNOINIT "DLOGBOOTSTATUSNOINIT"
//   #if !defined( DLOGBOOTSTATUSNOINIT_USE_SECTION )
//     #pragma use_section DLOGBOOTSTATUSNOINIT Dlog_BootStatus
//     #define DLOGBOOTSTATUSNOINIT_USE_SECTION
//   #endif
#elif defined (Dlog_STOP_SEC_VAR_NOINIT_SHARED_BOOT_STATUS)
   #undef      Dlog_STOP_SEC_VAR_NOINIT_SHARED_BOOT_STATUS
   /*@@@visbch: Mapping to global section in MemMap.h*/
   #define STOP_SEC_VAR
   #pragma section DATA
   

/* -------------------------------------------------------------------------- */
/*             Data Logistic (Application and Bootloader)                     */
/* -------------------------------------------------------------------------- */
/* special section for SVK history memory, progstatus */
#elif defined (Dlog_START_SEC_VAR_SAVED_ZONE_UNSPECIFIED)
   #undef      Dlog_START_SEC_VAR_SAVED_ZONE_UNSPECIFIED
   /*@@@visbch: Mapping to global section in MemMap.h*/
   #define START_SEC_VAR_NOINIT_UNSPECIFIED
#elif defined (Dlog_STOP_SEC_VAR_SAVED_ZONE_UNSPECIFIED)
   #undef      Dlog_STOP_SEC_VAR_SAVED_ZONE_UNSPECIFIED
   /*@@@visbch: Mapping to global section in MemMap.h*/
   #define STOP_SEC_VAR

/* -----------------[End of the section switch]------------------------------ */

#else
  #error "Error: section does not exist in Dlog_MemMap.h"
#endif
/*BMW - End*/

/*@@@visbch: Mapping of Dlog sections to Vector default sections; mapping to OS sections is done within MemMap.h*/
#include "MemMap.h"

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of include and declaration area >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

