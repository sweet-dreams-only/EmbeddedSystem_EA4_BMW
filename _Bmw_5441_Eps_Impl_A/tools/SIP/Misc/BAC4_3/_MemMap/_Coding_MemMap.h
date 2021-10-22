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
-------------------------------------------------------------------------------*/

/* PRQA S 0841 EOF
 * Violation of MISRA-C:2004 Rule 19.6:
 * Reason: Suppress violation of using #undef, because this is
 * necessary for using memory abstraction.
 */

/* PRQA S 0883 EOF
 * Violation of MISRA-C:2004 Rule 19.15:
 * Reason: Suppress violation of missing protection against
 * repeated inclusion, because this is necessary for using memory abstraction.
 */


#if 0
/*-------------------------------------------
   START Sections
--------------------------------------------*/

#elif defined (Coding_START_SEC_CODE)
#undef Coding_START_SEC_CODE
/*@@@visbch: Mapping to global section in MemMap.h*/
#define START_SEC_CODE
#ifdef CHK_Coding_SEC_STARTED
#error "Coding_SEC_CODE already open"
#endif
#define CHK_Coding_SEC_STARTED
#define CHK_Coding_SEC_CODE_STARTED

#elif defined (Coding_START_SEC_CONST_16)
#undef Coding_START_SEC_CONST_16
/*@@@visbch: Mapping to global section in MemMap.h*/
#define START_SEC_CONST_16BIT
#ifdef CHK_Coding_SEC_STARTED
#error "Coding_SEC_CONST_16 already open"
#endif
#define CHK_Coding_SEC_STARTED
#define CHK_Coding_START_SEC_CONST_16_STARTED

#elif defined (Coding_START_SEC_CONST_8)
#undef Coding_START_SEC_CONST_8
/*@@@visbch: Mapping to global section in MemMap.h*/
#define START_SEC_CONST_8BIT
#ifdef CHK_Coding_SEC_STARTED
#error "Coding_SEC_CONST_8 already open"
#endif
#define CHK_Coding_SEC_STARTED
#define CHK_Coding_START_SEC_CONST_8_STARTED

#elif defined (Coding_START_SEC_CONST_SAVED_RECOVERY_ZONE_UNSPECIFIED)
#undef Coding_START_SEC_CONST_SAVED_RECOVERY_ZONE_UNSPECIFIED
/*@@@visbch: Mapping to global section in MemMap.h*/
 #define START_SEC_CONST_UNSPECIFIED
#ifdef CHK_Coding_SEC_CONST_SAVED_RECOVERY_ZONE_UNSPECIFIED
#error "Coding_SEC_CONST_SAVED_RECOVERY_ZONE_UNSPECIFIED already open"
#endif
#define CHK_Coding_SEC_STARTED
#define CHK_Coding_SEC_CONST_SAVED_RECOVERY_ZONE_UNSPECIFIED_STARTED

#elif defined (Coding_START_SEC_VAR_CLEARED_32)
#undef Coding_START_SEC_VAR_CLEARED_32
/*@@@visbch: Mapping to global section in MemMap.h*/
#define START_SEC_VAR_ZERO_INIT_32BIT
#ifdef CHK_Coding_SEC_VAR_CLEARED_32
#error "Coding_SEC_VAR_CLEARED_32 already open"
#endif
#define CHK_Coding_SEC_STARTED
#define CHK_Coding_SEC_VAR_CLEARED_32_STARTED

#elif defined (Coding_START_SEC_VAR_INIT_BOOLEAN)
#undef Coding_START_SEC_VAR_INIT_BOOLEAN
/*@@@visbch: Mapping to global section in MemMap.h*/
#define START_SEC_VAR_INIT_8BIT
#ifdef CHK_Coding_SEC_VAR_INIT_BOOLEAN
#error "Coding_SEC_VAR_INIT_BOOLEAN already open"
#endif
#define CHK_Coding_SEC_STARTED
#define CHK_Coding_SEC_VAR_INIT_BOOLEAN_STARTED

#elif defined (Coding_START_SEC_VAR_CLEARED_BOOLEAN)
#undef Coding_START_SEC_VAR_CLEARED_BOOLEAN
/*@@@visbch: Mapping to global section in MemMap.h*/
#define    START_SEC_VAR_ZERO_INIT_8BIT
#ifdef CHK_Coding_SEC_VAR_CLEARED_BOOLEAN
#error "Coding_SEC_VAR_CLEARED_BOOLEAN already open"
#endif
#define CHK_Coding_SEC_STARTED
#define CHK_Coding_SEC_VAR_CLEARED_BOOLEAN_STARTED

#elif defined (Coding_START_SEC_VAR_CLEARED_UNSPECIFIED)
#undef Coding_START_SEC_VAR_CLEARED_UNSPECIFIED
/*@@@visbch: Mapping to global section in MemMap.h*/
#define    START_SEC_VAR_ZERO_INIT_UNSPECIFIED
#ifdef CHK_Coding_SEC_VAR_CLEARED_UNSPECIFIED
#error "Coding_SEC_VAR_CLEARED_UNSPECIFIED already open"
#endif
#define CHK_Coding_SEC_STARTED
#define CHK_Coding_SEC_VAR_CLEARED_UNSPECIFIED_STARTED

#elif defined (Coding_START_SEC_VAR_INIT_8)
#undef Coding_START_SEC_VAR_INIT_8
/*@@@visbch: Mapping to global section in MemMap.h*/
#define START_SEC_VAR_INIT_8BIT
#ifdef CHK_Coding_SEC_VAR_INIT_8
#error "Coding_SEC_VAR_INIT_8 already open"
#endif
#define CHK_Coding_SEC_STARTED
#define CHK_Coding_SEC_VAR_INIT_8_STARTED

#elif defined (Coding_START_SEC_VAR_INIT_UNSPECIFIED)
#undef Coding_START_SEC_VAR_INIT_UNSPECIFIED
/*@@@visbch: Mapping to global section in MemMap.h*/
#define START_SEC_VAR_INIT_UNSPECIFIED
#ifdef CHK_Coding_SEC_VAR_INIT_UNSPECIFIED
#error "Coding_SEC_VAR_INIT_UNSPECIFIED already open"
#endif
#define CHK_Coding_SEC_STARTED
#define CHK_Coding_SEC_VAR_INIT_UNSPECIFIED_STARTED

#elif defined (Coding_START_SEC_VAR_SAVED_ZONE_UNSPECIFIED)
#undef Coding_START_SEC_VAR_SAVED_ZONE_UNSPECIFIED
/*@@@visbch: Mapping to global section in MemMap.h*/
#define START_SEC_VAR_INIT_UNSPECIFIED
#ifdef CHK_Coding_SEC_VAR_SAVED_ZONE_UNSPECIFIED
#error "Coding_SEC_VAR_SAVED_ZONE_UNSPECIFIED already open"
#endif
#define CHK_Coding_SEC_STARTED
#define CHK_Coding_SEC_VAR_SAVED_ZONE_UNSPECIFIED_STARTED

/*-------------------------------------------
 STOP Sections
--------------------------------------------*/

#elif defined (Coding_STOP_SEC_CODE)
#undef Coding_STOP_SEC_CODE
/*@@@visbch: Mapping to global section in MemMap.h*/
#define STOP_SEC_CODE
#ifndef CHK_Coding_SEC_CODE_STARTED
#error "Coding_SEC_CODE not opened"
#endif
#undef CHK_Coding_SEC_STARTED
#undef CHK_Coding_SEC_CODE_STARTED

#elif defined (Coding_STOP_SEC_CONST_16)
#undef Coding_STOP_SEC_CONST_16
/*@@@visbch: Mapping to global section in MemMap.h*/
#define STOP_SEC_CONST
#ifndef CHK_Coding_START_SEC_CONST_16_STARTED
#error "Coding__SEC_CONST_16 not opened"
#endif
#undef CHK_Coding_SEC_STARTED
#undef CHK_Coding_START_SEC_CONST_16_STARTED

#elif defined (Coding_STOP_SEC_CONST_8)
#undef Coding_STOP_SEC_CONST_8
/*@@@visbch: Mapping to global section in MemMap.h*/
#define STOP_SEC_CONST
#ifndef CHK_Coding_START_SEC_CONST_8_STARTED
#error "Coding_SEC_CONST_8 not opened"
#endif
#undef CHK_Coding_SEC_STARTED
#undef CHK_Coding_START_SEC_CONST_8_STARTED

#elif defined (Coding_STOP_SEC_CONST_SAVED_RECOVERY_ZONE_UNSPECIFIED)
#undef Coding_STOP_SEC_CONST_SAVED_RECOVERY_ZONE_UNSPECIFIED
/*@@@visbch: Mapping to global section in MemMap.h*/
#define STOP_SEC_CONST
#ifndef CHK_Coding_SEC_CONST_SAVED_RECOVERY_ZONE_UNSPECIFIED_STARTED
#error "Coding_SEC_CONST_SAVED_RECOVERY_ZONE_UNSPECIFIED not open"
#endif
#undef CHK_Coding_SEC_STARTED
#undef CHK_Coding_SEC_CONST_SAVED_RECOVERY_ZONE_UNSPECIFIED_STARTED

#elif defined (Coding_STOP_SEC_VAR_CLEARED_32)
#undef Coding_STOP_SEC_VAR_CLEARED_32
/*@@@visbch: Mapping to global section in MemMap.h*/
#define STOP_SEC_VAR
#ifndef CHK_Coding_SEC_VAR_CLEARED_32_STARTED
#error "Coding_SEC_VAR_CLEARED_32 not open"
#endif
#undef CHK_Coding_SEC_STARTED
#undef CHK_Coding_SEC_VAR_CLEARED_32_STARTED

#elif defined (Coding_STOP_SEC_VAR_INIT_BOOLEAN)
#undef Coding_STOP_SEC_VAR_INIT_BOOLEAN
/*@@@visbch: Mapping to global section in MemMap.h*/
#define STOP_SEC_VAR
#ifndef CHK_Coding_SEC_VAR_INIT_BOOLEAN_STARTED
#error "Coding_SEC_VAR_INIT_BOOLEAN not open"
#endif
#undef CHK_Coding_SEC_STARTED
#undef CHK_Coding_SEC_VAR_INIT_BOOLEAN_STARTED

#elif defined (Coding_STOP_SEC_VAR_CLEARED_BOOLEAN)
#undef Coding_STOP_SEC_VAR_CLEARED_BOOLEAN
/*@@@visbch: Mapping to global section in MemMap.h*/
#define STOP_SEC_VAR
#ifndef CHK_Coding_SEC_VAR_CLEARED_BOOLEAN_STARTED
#error "Coding_SEC_VAR_CLEARED_BOOLEAN not open"
#endif
#undef CHK_Coding_SEC_STARTED
#undef CHK_Coding_SEC_VAR_CLEARED_BOOLEAN_STARTED

#elif defined (Coding_STOP_SEC_VAR_CLEARED_UNSPECIFIED)
#undef Coding_STOP_SEC_VAR_CLEARED_UNSPECIFIED
/*@@@visbch: Mapping to global section in MemMap.h*/
#define STOP_SEC_VAR
#ifndef CHK_Coding_SEC_VAR_CLEARED_UNSPECIFIED_STARTED
#error "Coding_SEC_VAR_CLEARED_UNSPECIFIED not open"
#endif
#undef CHK_Coding_SEC_STARTED
#undef CHK_Coding_SEC_VAR_CLEARED_UNSPECIFIED_STARTED

#elif defined (Coding_STOP_SEC_VAR_INIT_8)
#undef Coding_STOP_SEC_VAR_INIT_8
/*@@@visbch: Mapping to global section in MemMap.h*/
#define STOP_SEC_VAR
#ifndef CHK_Coding_SEC_VAR_INIT_8_STARTED
#error "Coding_SEC_VAR_INIT_8 not open"
#endif
#undef CHK_Coding_SEC_STARTED
#undef CHK_Coding_SEC_VAR_INIT_8_STARTED

#elif defined (Coding_STOP_SEC_VAR_INIT_UNSPECIFIED)
#undef Coding_STOP_SEC_VAR_INIT_UNSPECIFIED
/*@@@visbch: Mapping to global section in MemMap.h*/
#define STOP_SEC_VAR
#ifndef CHK_Coding_SEC_VAR_INIT_UNSPECIFIED_STARTED
#error "Coding_SEC_VAR_INIT_UNSPECIFIED not open"
#endif
#undef CHK_Coding_SEC_STARTED
#undef CHK_Coding_SEC_VAR_INIT_UNSPECIFIED_STARTED

#elif defined (Coding_STOP_SEC_VAR_SAVED_ZONE_UNSPECIFIED)
#undef Coding_STOP_SEC_VAR_SAVED_ZONE_UNSPECIFIED
/*@@@visbch: Mapping to global section in MemMap.h*/
#define STOP_SEC_VAR
#ifndef CHK_Coding_SEC_VAR_SAVED_ZONE_UNSPECIFIED_STARTED
#error "Coding_SEC_VAR_SAVED_ZONE_UNSPECIFIED not open"
#endif
#undef CHK_Coding_SEC_STARTED
#undef CHK_Coding_SEC_VAR_SAVED_ZONE_UNSPECIFIED_STARTED

#else
#error "Error: section does not exist in Coding_MemMap.h"
#endif
/*BMW - End*/

/*@@@visbch: Mapping of Coding sections to Vector default sections; mapping to OS sections is done within MemMap.h*/
#include "MemMap.h"

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of include and declaration area >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
