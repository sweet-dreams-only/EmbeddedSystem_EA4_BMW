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

#elif defined (CodingSample_START_SEC_CODE)
#undef CodingSample_START_SEC_CODE
/*@@@visbch: Mapping to global section in MemMap.h*/
#define START_SEC_CODE
#ifdef CHK_CodingSample_SEC_STARTED
#error "CodingSample section not closed"
#endif
#define CHK_CodingSample_SEC_STARTED
#define CHK_CodingSample_SEC_CODE_STARTED

#elif defined (CodingSample_START_SEC_VAR_INIT_UNSPECIFIED)
#undef CodingSample_START_SEC_VAR_INIT_UNSPECIFIED
/*@@@visbch: Mapping to global section in MemMap.h*/
#define START_SEC_VAR_INIT_UNSPECIFIED
#ifdef CHK_CodingSample_SEC_STARTED
#error "CodingSample section not closed"
#endif
#define CHK_CodingSample_SEC_STARTED
#define CHK_CodingSample_SEC_VAR_INIT_UNSPECIFIED_STARTED

#elif defined (CodingSample_START_SEC_VAR_NO_INIT_8)
#undef CodingSample_START_SEC_VAR_NO_INIT_8
/*@@@visbch: Mapping to global section in MemMap.h*/
#define START_SEC_VAR_NOINIT_8BIT
#ifdef CHK_CodingSample_SEC_STARTED
#error "CodingSample section not closed"
#endif
#define CHK_CodingSample_SEC_STARTED
#define CHK_CodingSample_SEC_VAR_NO_INIT_8_STARTED

/*-------------------------------------------
 STOP Sections
--------------------------------------------*/

#elif defined (CodingSample_STOP_SEC_CODE)
#undef CodingSample_STOP_SEC_CODE
/*@@@visbch: Mapping to global section in MemMap.h*/
#define STOP_SEC_CODE
#ifndef CHK_CodingSample_SEC_CODE_STARTED
#error "CodingSample_SEC_CODE not opened"
#endif
#undef CHK_CodingSample_SEC_STARTED
#undef CHK_CodingSample_SEC_CODE_STARTED

#elif defined (CodingSample_STOP_SEC_VAR_INIT_UNSPECIFIED)
#undef CodingSample_STOP_SEC_VAR_INIT_UNSPECIFIED
/*@@@visbch: Mapping to global section in MemMap.h*/
#define STOP_SEC_VAR
#ifndef CHK_CodingSample_SEC_VAR_INIT_UNSPECIFIED_STARTED
#error "CodingSample_SEC_VAR_INIT_UNSPECIFIED not opened"
#endif
#undef CHK_CodingSample_SEC_STARTED
#undef CHK_CodingSample_SEC_VAR_INIT_UNSPECIFIED_STARTED

#elif defined (CodingSample_STOP_SEC_VAR_NO_INIT_8)
#undef CodingSample_STOP_SEC_VAR_NO_INIT_8
/*@@@visbch: Mapping to global section in MemMap.h*/
#define STOP_SEC_VAR
#ifndef CHK_CodingSample_SEC_VAR_NO_INIT_8_STARTED
#error "CodingSample_SEC_VAR_NO_INIT_8 not opened"
#endif
#undef CHK_CodingSample_SEC_STARTED
#undef CHK_CodingSample_SEC_VAR_NO_INIT_8_STARTED

#else
#error "Error: section does not exist in CodingSample_MemMap.h"
#endif
/*BMW - End*/

/*@@@visbch: Mapping of CodingSample sections to Vector default sections; mapping to OS sections is done within MemMap.h*/
#include "MemMap.h"

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of include and declaration area >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
