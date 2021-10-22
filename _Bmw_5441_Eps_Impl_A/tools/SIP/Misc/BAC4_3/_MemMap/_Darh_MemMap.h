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
#elif defined (Darh_START_SEC_VAR_SAVED_ZONE_UNSPECIFIED)
  #undef Darh_START_SEC_VAR_SAVED_ZONE_UNSPECIFIED
  /*@@@visbch: Mapping to global section in MemMap.h*/
  #define START_SEC_VAR_INIT_UNSPECIFIED
  #ifdef CHK_Darh_SEC_STARTED
    #error "Darh section not closed"
  #endif
  #define CHK_Darh_SEC_STARTED
  #define CHK_Darh_SEC_VAR_SAVED_ZONE_UNSPECIFIED_STARTED

#elif defined (Darh_START_SEC_CODE)
#undef Darh_START_SEC_CODE
  /*@@@visbch: Mapping to global section in MemMap.h*/
  #define START_SEC_CODE
  #ifdef CHK_Darh_SEC_STARTED
    #error "Darh section not closed"
  #endif
  #define CHK_Darh_SEC_STARTED
  #define CHK_Darh_SEC_CODE_STARTED

#elif defined (Darh_START_SEC_CONST_UNSPECIFIED)
  #undef Darh_START_SEC_CONST_UNSPECIFIED
  /*@@@visbch: Mapping to global section in MemMap.h*/
  #define START_SEC_CONST_UNSPECIFIED
  #ifdef CHK_Darh_SEC_STARTED
    #error "Darh section not closed"
  #endif
  #define CHK_Darh_SEC_STARTED
  #define CHK_Darh_SEC_CONST_UNSPECIFIED_STARTED

#elif defined (Darh_START_SEC_VAR_NO_INIT_UNSPECIFIED)
#undef Darh_START_SEC_VAR_NO_INIT_UNSPECIFIED
  /*@@@visbch: Mapping to global section in MemMap.h*/
  #define START_SEC_VAR_NO_INIT_UNSPECIFIED
  #ifdef CHK_Darh_SEC_STARTED
    #error "Darh section not closed"
  #endif
  #define CHK_Darh_SEC_STARTED
  #define CHK_Darh_SEC_VAR_NO_INIT_UNSPECIFIED_STARTED

#elif defined (Darh_START_SEC_VAR_SAVED_ZONE_BOOLEAN)
#undef Darh_START_SEC_VAR_SAVED_ZONE_BOOLEAN
  /*@@@visbch: Mapping to global section in MemMap.h*/
  #define START_SEC_VAR_INIT_8BIT
  #ifdef CHK_Darh_SEC_STARTED
    #error "Darh section not closed"
  #endif
  #define CHK_Darh_SEC_STARTED
  #define CHK_Darh_SEC_VAR_SAVED_ZONE_BOOLEAN_STARTED

#elif defined (Darh_START_SEC_VAR_NO_INIT_16)
#undef Darh_START_SEC_VAR_NO_INIT_16
  /*@@@visbch: Mapping to global section in MemMap.h*/
  #define START_SEC_VAR_NOINIT_16BIT
  #ifdef CHK_Darh_SEC_STARTED
    #error "Darh section not closed"
  #endif
  #define CHK_Darh_SEC_STARTED
  #define CHK_Darh_SEC_VAR_NO_INIT_16_STARTED

/*-------------------------------------------
   STOP Sections
--------------------------------------------*/
#elif defined (Darh_STOP_SEC_VAR_SAVED_ZONE_UNSPECIFIED)
  #undef Darh_STOP_SEC_VAR_SAVED_ZONE_UNSPECIFIED
  /*@@@visbch: Mapping to global section in MemMap.h*/
  #define STOP_SEC_VAR
  #ifndef CHK_Darh_SEC_VAR_SAVED_ZONE_UNSPECIFIED_STARTED
    #error "CHK_Darh_SEC_VAR_SAVED_ZONE_UNSPECIFIED_STARTED not opened"
  #endif
  #undef CHK_Darh_SEC_STARTED
  #undef CHK_Darh_SEC_VAR_SAVED_ZONE_UNSPECIFIED_STARTED

#elif defined (Darh_STOP_SEC_CODE)
#undef Darh_STOP_SEC_CODE
  /*@@@visbch: Mapping to global section in MemMap.h*/
  #define STOP_SEC_CODE
  #ifndef CHK_Darh_SEC_CODE_STARTED
    #error "CHK_Darh_SEC_CODE_STARTED not opened"
  #endif
  #undef CHK_Darh_SEC_STARTED
  #undef CHK_Darh_SEC_CODE_STARTED
  
#elif defined (Darh_STOP_SEC_CONST_UNSPECIFIED)
  #undef Darh_STOP_SEC_CONST_UNSPECIFIED
  /*@@@visbch: Mapping to global section in MemMap.h*/
  #define STOP_SEC_CONST
  #ifndef CHK_Darh_SEC_CONST_UNSPECIFIED_STARTED
    #error "Darh section not opened"
  #endif
  #undef CHK_Darh_SEC_STARTED
  #undef CHK_Darh_SEC_CONST_UNSPECIFIED_STARTED

#elif defined (Darh_STOP_SEC_VAR_NO_INIT_UNSPECIFIED)
#undef Darh_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
  /*@@@visbch: Mapping to global section in MemMap.h*/
  #define STOP_SEC_VAR
  #ifndef CHK_Darh_SEC_VAR_NO_INIT_UNSPECIFIED_STARTED
    #error "Darh section not opened"
  #endif
  #undef CHK_Darh_SEC_STARTED
  #undef CHK_Darh_SEC_VAR_NO_INIT_UNSPECIFIED_STARTED

#elif defined (Darh_STOP_SEC_VAR_SAVED_ZONE_BOOLEAN)
#undef Darh_STOP_SEC_VAR_SAVED_ZONE_BOOLEAN
  /*@@@visbch: Mapping to global section in MemMap.h*/
  #define STOP_SEC_VAR
  #ifndef CHK_Darh_SEC_VAR_SAVED_ZONE_BOOLEAN_STARTED
    #error "Darh section not opened"
  #endif
  #undef CHK_Darh_SEC_STARTED
  #undef CHK_Darh_SEC_VAR_SAVED_ZONE_BOOLEAN_STARTED

#elif defined (Darh_STOP_SEC_VAR_NO_INIT_16)
#undef Darh_STOP_SEC_VAR_NO_INIT_16
  /*@@@visbch: Mapping to global section in MemMap.h*/
  #define STOP_SEC_VAR
  #ifndef CHK_Darh_SEC_VAR_NO_INIT_16_STARTED
    #error "Darh section not opened"
  #endif
  #undef CHK_Darh_SEC_STARTED
  #undef CHK_Darh_SEC_VAR_NO_INIT_16_STARTED

#else
  #error "Error: section does not exist in Darh_MemMap.h"
#endif
/*BMW - End*/

/*@@@visbch: Mapping of Darh sections to Vector default sections; mapping to OS sections is done within MemMap.h*/
#include "MemMap.h"

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of include and declaration area >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

