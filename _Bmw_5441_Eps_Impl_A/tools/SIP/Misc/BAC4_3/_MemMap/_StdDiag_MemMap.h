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
#elif defined (StdDiag_START_SEC_CODE)
  #undef StdDiag_START_SEC_CODE
  /*@@@visbch: Mapping to global section in MemMap.h*/
  #define START_SEC_CODE
  #ifdef CHK_StdDiag_SEC_STARTED
    #error "StdDiag section not closed"
  #endif
  #define CHK_StdDiag_SEC_STARTED
  #define CHK_StdDiag_SEC_CODE_STARTED

#elif defined (StdDiag_START_SEC_VAR_INIT_BOOLEAN)
  #undef StdDiag_START_SEC_VAR_INIT_BOOLEAN
  /*@@@visbch: Mapping to global section in MemMap.h*/
  #define START_SEC_VAR_INIT_8BIT
  #ifdef CHK_StdDiag_SEC_STARTED
    #error "StdDiag section not closed"
  #endif
  #define CHK_StdDiag_SEC_STARTED
  #define CHK_StdDiag_SEC_VAR_INIT_BOOLEAN_STARTED

#elif defined (StdDiag_START_SEC_VAR_NO_INIT_BOOLEAN)
  #undef StdDiag_START_SEC_VAR_NO_INIT_BOOLEAN
  /*@@@visbch: Mapping to global section in MemMap.h*/
  #define START_SEC_VAR_NOINIT_8BIT
  #ifdef CHK_StdDiag_SEC_STARTED
    #error "StdDiag section not closed"
  #endif
  #define CHK_StdDiag_SEC_STARTED
  #define CHK_StdDiag_SEC_VAR_NO_INIT_BOOLEAN_STARTED

#elif defined (StdDiag_START_SEC_VAR_NO_INIT_8)
  #undef StdDiag_START_SEC_VAR_NO_INIT_8
  /*@@@visbch: Mapping to global section in MemMap.h*/
  #define START_SEC_VAR_NOINIT_8BIT
  #ifdef CHK_StdDiag_SEC_STARTED
    #error "StdDiag section not closed"
  #endif
  #define CHK_StdDiag_SEC_STARTED
  #define CHK_StdDiag_SEC_VAR_NO_INIT_8_STARTED

#elif defined (StdDiag_START_SEC_VAR_NO_INIT_16)
  #undef StdDiag_START_SEC_VAR_NO_INIT_16
  /*@@@visbch: Mapping to global section in MemMap.h*/
  #define START_SEC_VAR_NOINIT_16BIT
  #ifdef CHK_StdDiag_SEC_STARTED
    #error "StdDiag section not closed"
  #endif
  #define CHK_StdDiag_SEC_STARTED
  #define CHK_StdDiag_SEC_VAR_NO_INIT_16_STARTED

#elif defined (StdDiag_START_SEC_VAR_INIT_UNSPECIFIED)
  #undef StdDiag_START_SEC_VAR_INIT_UNSPECIFIED
  /*@@@visbch: Mapping to global section in MemMap.h*/
  #define START_SEC_VAR_NOINIT_UNSPECIFIED
  #ifdef CHK_StdDiag_SEC_STARTED
    #error "StdDiag section not closed"
  #endif
  #define CHK_StdDiag_SEC_STARTED
  #define CHK_StdDiag_SEC_VAR_INIT_UNSPECIFIED_STARTED

#elif defined (StdDiag_START_SEC_VAR_NO_INIT_UNSPECIFIED)
  #undef StdDiag_START_SEC_VAR_NO_INIT_UNSPECIFIED
  /*@@@visbch: Mapping to global section in MemMap.h*/
  #define START_SEC_VAR_NOINIT_UNSPECIFIED
  #ifdef CHK_StdDiag_SEC_STARTED
    #error "StdDiag section not closed"
  #endif
  #define CHK_StdDiag_SEC_STARTED
  #define CHK_StdDiag_SEC_VAR_NO_INIT_UNSPECIFIED_STARTED

#elif defined (StdDiag_START_SEC_CONST_UNSPECIFIED)
  #undef StdDiag_START_SEC_CONST_UNSPECIFIED
  /*@@@visbch: Mapping to global section in MemMap.h*/
  #define START_SEC_CONST_UNSPECIFIED
  #ifdef CHK_StdDiag_SEC_STARTED
    #error "StdDiag section not closed"
  #endif
  #define CHK_StdDiag_SEC_STARTED
  #define CHK_StdDiag_SEC_CONST_UNSPECIFIED_STARTED

/*-------------------------------------------
   STOP Sections
--------------------------------------------*/
#elif defined (StdDiag_STOP_SEC_CODE)
  #undef StdDiag_STOP_SEC_CODE
  /*@@@visbch: Mapping to global section in MemMap.h*/
  #define STOP_SEC_CODE
  #ifndef CHK_StdDiag_SEC_CODE_STARTED
    #error "StdDiag_SEC_CODE not opened"
  #endif
  #undef CHK_StdDiag_SEC_STARTED
  #undef CHK_StdDiag_SEC_CODE_STARTED

#elif defined (StdDiag_STOP_SEC_VAR_INIT_BOOLEAN)
  #undef StdDiag_STOP_SEC_VAR_INIT_BOOLEAN
  /*@@@visbch: Mapping to global section in MemMap.h*/
  #define STOP_SEC_VAR
  #ifndef CHK_StdDiag_SEC_VAR_INIT_BOOLEAN_STARTED
    #error "StdDiag_SEC_VAR_INIT_BOOLEAN not opened"
  #endif
  #undef CHK_StdDiag_SEC_STARTED
  #undef CHK_StdDiag_SEC_VAR_INIT_BOOLEAN_STARTED

#elif defined (StdDiag_STOP_SEC_VAR_NO_INIT_BOOLEAN)
  #undef StdDiag_STOP_SEC_VAR_NO_INIT_BOOLEAN
  /*@@@visbch: Mapping to global section in MemMap.h*/
  #define STOP_SEC_VAR
  #ifndef CHK_StdDiag_SEC_VAR_NO_INIT_BOOLEAN_STARTED
    #error "StdDiag_SEC_VAR_NO_INIT_BOOLEAN not opened"
  #endif
  #undef CHK_StdDiag_SEC_STARTED
  #undef CHK_StdDiag_SEC_VAR_NO_INIT_BOOLEAN_STARTED

#elif defined (StdDiag_STOP_SEC_VAR_NO_INIT_8)
  #undef StdDiag_STOP_SEC_VAR_NO_INIT_8
  /*@@@visbch: Mapping to global section in MemMap.h*/
  #define STOP_SEC_VAR
  #ifndef CHK_StdDiag_SEC_VAR_NO_INIT_8_STARTED
    #error "StdDiag_SEC_VAR_NO_INIT_8 not opened"
  #endif
  #undef CHK_StdDiag_SEC_STARTED
  #undef CHK_StdDiag_SEC_VAR_NO_INIT_8_STARTED

#elif defined (StdDiag_STOP_SEC_VAR_NO_INIT_16)
  #undef StdDiag_STOP_SEC_VAR_NO_INIT_16
  /*@@@visbch: Mapping to global section in MemMap.h*/
  #define STOP_SEC_VAR
  #ifndef CHK_StdDiag_SEC_VAR_NO_INIT_16_STARTED
    #error "StdDiag_SEC_VAR_NO_INIT_16 not opened"
  #endif
  #undef CHK_StdDiag_SEC_STARTED
  #undef CHK_StdDiag_SEC_VAR_NO_INIT_16_STARTED

#elif defined (StdDiag_STOP_SEC_VAR_INIT_UNSPECIFIED)
  #undef StdDiag_STOP_SEC_VAR_INIT_UNSPECIFIED
  /*@@@visbch: Mapping to global section in MemMap.h*/
  #define STOP_SEC_VAR
  #ifndef CHK_StdDiag_SEC_VAR_INIT_UNSPECIFIED_STARTED
    #error "StdDiag_SEC_VAR_INIT_UNSPECIFIED not opened"
  #endif
  #undef CHK_StdDiag_SEC_STARTED
  #undef CHK_StdDiag_SEC_VAR_INIT_UNSPECIFIED_STARTED

#elif defined (StdDiag_STOP_SEC_VAR_NO_INIT_UNSPECIFIED)
  #undef StdDiag_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
  /*@@@visbch: Mapping to global section in MemMap.h*/
  #define STOP_SEC_VAR
  #ifndef CHK_StdDiag_SEC_VAR_NO_INIT_UNSPECIFIED_STARTED
    #error "StdDiag_SEC_VAR_NO_INIT_UNSPECIFIED not opened"
  #endif
  #undef CHK_StdDiag_SEC_STARTED
  #undef CHK_StdDiag_SEC_VAR_NO_INIT_UNSPECIFIED_STARTED

#elif defined (StdDiag_STOP_SEC_CONST_UNSPECIFIED)
  #undef StdDiag_STOP_SEC_CONST_UNSPECIFIED
  /*@@@visbch: Mapping to global section in MemMap.h*/
  #define STOP_SEC_CONST
  #ifndef CHK_StdDiag_SEC_CONST_UNSPECIFIED_STARTED
    #error "StdDiag_SEC_CONST_UNSPECIFIED not opened"
  #endif
  #undef CHK_StdDiag_SEC_STARTED
  #undef CHK_StdDiag_SEC_CONST_UNSPECIFIED_STARTED

#else
  #error "Error: section does not exist in StdDiag_MemMap.h"
#endif
/*BMW - End*/

/*@@@visbch: Mapping of StdDiag sections to Vector default sections; mapping to OS sections is done within MemMap.h*/
#include "MemMap.h"

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of include and declaration area >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

