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
#elif defined (Stm_START_SEC_VAR_CLEARED_BOOLEAN)
  #undef Stm_START_SEC_VAR_CLEARED_BOOLEAN
  /*@@@visbch: Mapping to global section in MemMap.h*/
  #define    START_SEC_VAR_ZERO_INIT_8BIT
  #ifdef CHK_Stm_SEC_STARTED
    #error "Stm section not closed"
  #endif
  #define CHK_Stm_SEC_STARTED
  #define CHK_Stm_START_SEC_VAR_CLEARED_BOOLEAN_STARTED

#elif defined (Stm_START_SEC_VAR_CLEARED_16)
  #undef Stm_START_SEC_VAR_CLEARED_16
  /*@@@visbch: Mapping to global section in MemMap.h*/
  #define    START_SEC_VAR_ZERO_INIT_16BIT
  #ifdef CHK_Stm_SEC_STARTED
    #error "Stm section not closed"
  #endif
  #define CHK_Stm_SEC_STARTED
  #define CHK_Stm_START_SEC_VAR_CLEARED_16_STARTED

#elif defined (Stm_START_SEC_CODE)
  #undef Stm_START_SEC_CODE
  /*@@@visbch: Mapping to global section in MemMap.h*/
  #define START_SEC_CODE
  #ifdef CHK_Stm_SEC_STARTED
    #error "Stm section not closed"
  #endif
  #define CHK_Stm_SEC_STARTED
  #define CHK_Stm_SEC_CODE_STARTED

#elif defined (Stm_START_SEC_CONST_UNSPECIFIED)
  #undef Stm_START_SEC_CONST_UNSPECIFIED
  /*@@@visbch: Mapping to global section in MemMap.h*/
  #define START_SEC_CONST_UNSPECIFIED
  #ifdef CHK_Stm_SEC_STARTED
   #error "Stm section not closed"
  #endif
  #define CHK_Stm_SEC_STARTED
  #define CHK_Stm_SEC_CONST_UNSPECIFIED_STARTED

#elif defined (Stm_START_SEC_VAR_INIT_UNSPECIFIED)
  #undef Stm_START_SEC_VAR_INIT_UNSPECIFIED
  /*@@@visbch: Mapping to global section in MemMap.h*/
  #define START_SEC_VAR_INIT_UNSPECIFIED
  #ifdef CHK_Stm_SEC_STARTED
   #error "Stm section not closed"
  #endif
  #define CHK_Stm_SEC_STARTED
  #define CHK_Stm_SEC_VAR_INIT_UNSPECIFIED_STARTED

/*-------------------------------------------
   STOP Sections
--------------------------------------------*/
#elif defined (Stm_STOP_SEC_VAR_CLEARED_BOOLEAN)
  #undef Stm_STOP_SEC_VAR_CLEARED_BOOLEAN
  /*@@@visbch: Mapping to global section in MemMap.h*/
  #define STOP_SEC_VAR
  #ifndef CHK_Stm_SEC_STARTED
    #error "Stm section not closed"
  #endif
  #undef CHK_Stm_SEC_STARTED
  #undef CHK_Stm_STOP_SEC_VAR_CLEARED_BOOLEAN_STARTED

#elif defined (Stm_STOP_SEC_VAR_CLEARED_16)
  #undef Stm_STOP_SEC_VAR_CLEARED_16
  /*@@@visbch: Mapping to global section in MemMap.h*/
  #define STOP_SEC_VAR
  #ifndef CHK_Stm_SEC_STARTED
    #error "Stm section not closed"
  #endif
  #undef CHK_Stm_SEC_STARTED
  #undef CHK_Stm_STOP_SEC_VAR_CLEARED_16_STARTED

#elif defined (Stm_STOP_SEC_CODE)
  #undef Stm_STOP_SEC_CODE
  /*@@@visbch: Mapping to global section in MemMap.h*/
  #define STOP_SEC_CODE
  #ifndef CHK_Stm_SEC_CODE_STARTED
    #error "Stm_SEC_CODE not opened"
  #endif
  #undef CHK_Stm_SEC_STARTED
  #undef CHK_Stm_SEC_CODE_STARTED

#elif defined (Stm_STOP_SEC_CONST_UNSPECIFIED)
  #undef Stm_STOP_SEC_CONST_UNSPECIFIED
  /*@@@visbch: Mapping to global section in MemMap.h*/
  #define STOP_SEC_CONST
  #ifndef CHK_Stm_SEC_CONST_UNSPECIFIED_STARTED
   #error "Stm_SEC_CONST_UNSPECIFIED not opened"
  #endif
  #undef CHK_Stm_SEC_STARTED
  #undef CHK_Stm_SEC_CONST_UNSPECIFIED_STARTED

#elif defined (Stm_STOP_SEC_VAR_INIT_UNSPECIFIED)
  #undef Stm_STOP_SEC_VAR_INIT_UNSPECIFIED
  /*@@@visbch: Mapping to global section in MemMap.h*/
  #define STOP_SEC_VAR
  #ifndef CHK_Stm_SEC_VAR_INIT_UNSPECIFIED_STARTED
   #error "Stm_SEC_VAR_INIT_UNSPECIFIED not opened"
  #endif
  #undef CHK_Stm_SEC_STARTED
  #undef CHK_Stm_SEC_VAR_INIT_UNSPECIFIED_STARTED


#else
  #error "Error: section does not exist in Stm_MemMap.h"
#endif
/*BMW - End*/

/*@@@visbch: Mapping of Stm sections to Vector default sections; mapping to OS sections is done within MemMap.h*/
#include "MemMap.h"

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of include and declaration area >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

