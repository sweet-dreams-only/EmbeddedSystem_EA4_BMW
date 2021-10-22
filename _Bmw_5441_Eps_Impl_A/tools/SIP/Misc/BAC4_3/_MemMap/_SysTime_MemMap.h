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
/*
   MISRA-C:2004 Rule 19.6: Suppress violation of using #undef, because this is
   necessary for using memory abstraction.
*/
/* PRQA S 0841 EOF */

/*
   MISRA-C:2004 Rule 19.15: Suppress violation of missing protection against
   repeated inclusion, because this is necessary for using memory abstraction.
*/
/* PRQA S 0883 EOF */

#if 0
/*-------------------------------------------
   START Sections
--------------------------------------------*/
#elif defined (SysTime_START_SEC_CODE)
  #undef SysTime_START_SEC_CODE
  /*@@@visbch: Mapping to global section in MemMap.h*/
  #define START_SEC_CODE
  #ifdef CHK_SysTime_SEC_STARTED
    #error "SysTime section not closed"
  #endif
  #define CHK_SysTime_SEC_STARTED
  #define CHK_SysTime_SEC_CODE_STARTED

#elif defined (SysTime_START_SEC_VAR_INIT_32)
  #undef SysTime_START_SEC_VAR_INIT_32
  /*@@@visbch: Mapping to global section in MemMap.h*/
  #define START_SEC_VAR_INIT_32BIT
  #ifdef CHK_SysTime_SEC_STARTED
    #error "SysTime section not closed"
  #endif
  #define CHK_SysTime_SEC_STARTED
  #define CHK_SysTime_SEC_VAR_INIT_32_STARTED

#elif defined (SysTime_START_SEC_VAR_NO_INIT_32)
  #undef SysTime_START_SEC_VAR_NO_INIT_32
  /*@@@visbch: Mapping to global section in MemMap.h*/
  #define START_SEC_VAR_NOINIT_32BIT
  #ifdef CHK_SysTime_SEC_STARTED
    #error "SysTime section not closed"
  #endif
  #define CHK_SysTime_SEC_STARTED
  #define CHK_SysTime_SEC_VAR_NO_INIT_32_STARTED

#elif defined (SysTime_START_SEC_VAR_NO_INIT_UNSPECIFIED)
  #undef SysTime_START_SEC_VAR_NO_INIT_UNSPECIFIED
  /*@@@visbch: Mapping to global section in MemMap.h*/
  #define START_SEC_VAR_NOINIT_UNSPECIFIED
  #ifdef CHK_SysTime_SEC_STARTED
    #error "SysTime section not closed"
  #endif
  #define CHK_SysTime_SEC_STARTED
  #define CHK_SysTime_SEC_VAR_NO_INIT_UNSPECIFIED_STARTED

/*-------------------------------------------
   STOP Sections
--------------------------------------------*/
#elif defined (SysTime_STOP_SEC_CODE)
  #undef SysTime_STOP_SEC_CODE
  /*@@@visbch: Mapping to global section in MemMap.h*/
  #define STOP_SEC_CODE
  #ifndef CHK_SysTime_SEC_CODE_STARTED
    #error "SysTime_SEC_CODE not opened"
  #endif
  #undef CHK_SysTime_SEC_STARTED
  #undef CHK_SysTime_SEC_CODE_STARTED

#elif defined (SysTime_STOP_SEC_VAR_INIT_32)
  #undef SysTime_STOP_SEC_VAR_INIT_32
  /*@@@visbch: Mapping to global section in MemMap.h*/
  #define STOP_SEC_VAR
  #ifndef CHK_SysTime_SEC_VAR_INIT_32_STARTED
    #error "SysTime_SEC_VAR_INIT_32 not opened"
  #endif
  #undef CHK_SysTime_SEC_STARTED
  #undef CHK_SysTime_SEC_VAR_INIT_32_STARTED

#elif defined (SysTime_STOP_SEC_VAR_NO_INIT_32)
  #undef SysTime_STOP_SEC_VAR_NO_INIT_32
  /*@@@visbch: Mapping to global section in MemMap.h*/
  #define STOP_SEC_VAR
  #ifndef CHK_SysTime_SEC_VAR_NO_INIT_32_STARTED
    #error "SysTime_SEC_VAR_NO_INIT_32 not opened"
  #endif
  #undef CHK_SysTime_SEC_STARTED
  #undef CHK_SysTime_SEC_VAR_NO_INIT_32_STARTED

#elif defined (SysTime_STOP_SEC_VAR_NO_INIT_UNSPECIFIED)
  #undef SysTime_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
  /*@@@visbch: Mapping to global section in MemMap.h*/
  #define STOP_SEC_VAR
  #ifndef CHK_SysTime_SEC_VAR_NO_INIT_UNSPECIFIED_STARTED
    #error "SysTime_SEC_VAR_NO_INIT_UNSPECIFIED not opened"
  #endif
  #undef CHK_SysTime_SEC_STARTED
  #undef CHK_SysTime_SEC_VAR_NO_INIT_UNSPECIFIED_STARTED

#else
  #error "Error: section does not exist in SysTime_MemMap.h"
#endif
/*BMW - End*/

/*@@@Vector: Mapping of SysTime sections to Vector default sections; mapping to OS sections is done within MemMap.h*/
#include "MemMap.h"

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of include and declaration area >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

