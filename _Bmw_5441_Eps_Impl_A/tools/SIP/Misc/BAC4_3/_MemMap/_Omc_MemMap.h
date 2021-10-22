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
/*----------------------------------------------------------------------------*/
/* Misra 2004 Rule 19.6: The compiler directive undef is needed within memory mapping header files */
/* PRQA S 0841 EOF */

/* Misra 2004 Rule 19.15: This header file shall not be protected against multiple inclusions */
/* PRQA S 0883 1 */
#if 0
/*-------------------------------------------
   START Sections
--------------------------------------------*/
#elif defined (Omc_START_SEC_CONST_UNSPECIFIED)
  #undef Omc_START_SEC_CONST_UNSPECIFIED
  /*@@@visbch: Mapping to global section in MemMap.h*/
  #define START_SEC_CONST_UNSPECIFIED
  #ifdef CHK_Omc_SEC_STARTED
    #error "Omc section not closed"
  #endif
  #define CHK_Omc_SEC_STARTED
  #define CHK_Omc_START_SEC_CONST_UNSPECIFIED_STARTED

#elif defined (Omc_START_SEC_VAR_NO_INIT_BOOLEAN)
  #undef Omc_START_SEC_VAR_NO_INIT_BOOLEAN
  /*@@@visbch: Mapping to global section in MemMap.h*/
  #define START_SEC_VAR_NOINIT_8BIT
  #ifdef CHK_Omc_SEC_STARTED
    #error "Omc section not closed"
  #endif
  #define CHK_Omc_SEC_STARTED
  #define CHK_Omc_START_SEC_VAR_NO_INIT_BOOLEAN_STARTED

#elif defined (Omc_START_SEC_CODE)
  #undef Omc_START_SEC_CODE
  /*@@@visbch: Mapping to global section in MemMap.h*/
  #define START_SEC_CODE
  #ifdef CHK_Omc_SEC_STARTED
    #error "Omc section not closed"
  #endif
  #define CHK_Omc_SEC_STARTED
  #define CHK_Omc_SEC_CODE_STARTED

#elif defined (Omc_START_SEC_VAR_SAVED_ZONE_UNSPECIFIED)
   #undef      Omc_START_SEC_VAR_SAVED_ZONE_UNSPECIFIED
   /*@@@visbch: Mapping to global section in MemMap.h*/
   #define START_SEC_VAR_INIT_UNSPECIFIED
   #ifdef CHK_Omc_SEC_STARTED
    #error "Omc section not closed"
   #endif
   #define CHK_Omc_SEC_STARTED
   #define CHK_Omc_START_SEC_VAR_SAVED_ZONE_UNSPECIFIED_STARTED

#elif defined (Omc_START_SEC_CONST_SAVED_RECOVERY_ZONE)
   #undef      Omc_START_SEC_CONST_SAVED_RECOVERY_ZONE
   /*@@@visbch: Mapping to global section in MemMap.h*/
   #define START_SEC_CONST_UNSPECIFIED
   #ifdef CHK_Omc_SEC_STARTED
    #error "Omc section not closed"
   #endif
   #define CHK_Omc_SEC_STARTED
   #define CHK_Omc_SEC_CONST_SAVED_ZONE_STARTED

#elif defined (Omc_START_SEC_VAR_INIT_BOOLEAN)
   #undef      Omc_START_SEC_VAR_INIT_BOOLEAN
   /*@@@visbch: Mapping to global section in MemMap.h*/
   #define START_SEC_VAR_INIT_8BIT
   #ifdef CHK_Omc_SEC_STARTED
    #error "Omc section not closed"
   #endif
   #define CHK_Omc_SEC_STARTED
   #define CHK_Omc_SEC_VAR_INIT_BOOLEAN_STARTED

#elif defined (Omc_START_SEC_VAR_INIT_UNSPECIFIED)
#undef Omc_START_SEC_VAR_INIT_UNSPECIFIED
   /*@@@visbch: Mapping to global section in MemMap.h*/
   #define START_SEC_VAR_INIT_UNSPECIFIED
  #ifdef CHK_Omc_SEC_STARTED
    #error "Omc section not closed"
  #endif
  #define CHK_Omc_SEC_STARTED
  #define CHK_Omc_SEC_VAR_INIT_UNSPECIFIED_STARTED

#elif defined (Omc_START_SEC_VAR_NO_INIT_UNSPECIFIED)
   #undef      Omc_START_SEC_VAR_NO_INIT_UNSPECIFIED
   /*@@@visbch: Mapping to global section in MemMap.h*/
   #define START_SEC_VAR_NOINIT_UNSPECIFIED
   #ifdef CHK_Omc_SEC_STARTED
    #error "Omc section not closed"
   #endif
   #define CHK_Omc_SEC_STARTED
   #define CHK_Omc_SEC_VAR_NO_INIT_UNSPECIFIED_STARTED

/*-------------------------------------------
   STOP Sections
--------------------------------------------*/

#elif defined (Omc_STOP_SEC_CONST_UNSPECIFIED)
  #undef Omc_STOP_SEC_CONST_UNSPECIFIED
  /*@@@visbch: Mapping to global section in MemMap.h*/
  #define STOP_SEC_CONST
  #ifndef CHK_Omc_START_SEC_CONST_UNSPECIFIED_STARTED
    #error "Omc_SEC_CONST_UNSPECIFIED not opened"
  #endif
  #undef CHK_Omc_SEC_STARTED
  #undef CHK_Omc_START_SEC_CONST_UNSPECIFIED_STARTED

#elif defined (Omc_STOP_SEC_VAR_NO_INIT_BOOLEAN)
  #undef Omc_STOP_SEC_VAR_NO_INIT_BOOLEAN
  /*@@@visbch: Mapping to global section in MemMap.h*/
  #define STOP_SEC_VAR
  #ifndef CHK_Omc_START_SEC_VAR_NO_INIT_BOOLEAN_STARTED
    #error "Omc_SEC_VAR_NO_INIT_BOOLEAN not opened"
  #endif
  #undef CHK_Omc_SEC_STARTED
  #undef CHK_Omc_START_SEC_VAR_NO_INIT_BOOLEAN_STARTED

#elif defined (Omc_STOP_SEC_CODE)
  #undef Omc_STOP_SEC_CODE
  /*@@@visbch: Mapping to global section in MemMap.h*/
  #define STOP_SEC_CODE
  #ifndef CHK_Omc_SEC_CODE_STARTED
    #error "Omc_SEC_CODE not opened"
  #endif
  #undef CHK_Omc_SEC_STARTED
  #undef CHK_Omc_SEC_CODE_STARTED

#elif defined (Omc_STOP_SEC_VAR_SAVED_ZONE_UNSPECIFIED)
  #undef Omc_STOP_SEC_VAR_SAVED_ZONE_UNSPECIFIED
  /*@@@visbch: Mapping to global section in MemMap.h*/
  #define STOP_SEC_VAR
  #ifndef CHK_Omc_START_SEC_VAR_SAVED_ZONE_UNSPECIFIED_STARTED
    #error "Omc_SEC_CONST_SAVED_RECOVERY_ZONE_UNSPECIFIED not opened"
  #endif
  #undef CHK_Omc_SEC_STARTED
  #undef CHK_Omc_START_SEC_VAR_SAVED_ZONE_UNSPECIFIED_STARTED

#elif defined (Omc_STOP_SEC_CONST_SAVED_RECOVERY_ZONE)
  #undef Omc_STOP_SEC_CONST_SAVED_RECOVERY_ZONE
  /*@@@visbch: Mapping to global section in MemMap.h*/
  #define STOP_SEC_CONST
  #ifndef CHK_Omc_SEC_CONST_SAVED_ZONE_STARTED
    #error "Omc_SEC_CONST_SAVED_RECOVERY_ZONE not opened"
  #endif
  #undef CHK_Omc_SEC_STARTED
  #undef CHK_Omc_SEC_CONST_SAVED_ZONE_STARTED

#elif defined (Omc_STOP_SEC_VAR_INIT_BOOLEAN)
  #undef Omc_STOP_SEC_VAR_INIT_BOOLEAN
  /*@@@visbch: Mapping to global section in MemMap.h*/
  #define STOP_SEC_VAR
  #ifndef CHK_Omc_SEC_VAR_INIT_BOOLEAN_STARTED
    #error "Omc_SEC_CONST_SAVED_RECOVERY_ZONE not opened"
  #endif
  #undef CHK_Omc_SEC_STARTED
  #undef CHK_Omc_SEC_VAR_INIT_BOOLEAN_STARTED

#elif defined (Omc_STOP_SEC_VAR_INIT_UNSPECIFIED)
  #undef Omc_STOP_SEC_VAR_INIT_UNSPECIFIED
  /*@@@visbch: Mapping to global section in MemMap.h*/
  #define STOP_SEC_VAR
  #ifndef CHK_Omc_SEC_VAR_INIT_UNSPECIFIED_STARTED
    #error "CHK_Omc_SEC_VAR_INIT_UNSPECIFIED_STARTED not opened"
  #endif
  #undef CHK_Omc_SEC_STARTED
  #undef CHK_Omc_SEC_VAR_INIT_UNSPECIFIED_STARTED
  
#elif defined (Omc_STOP_SEC_VAR_NO_INIT_UNSPECIFIED)
  #undef Omc_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
  /*@@@visbch: Mapping to global section in MemMap.h*/
  #define STOP_SEC_VAR
  #ifndef CHK_Omc_SEC_VAR_NO_INIT_UNSPECIFIED_STARTED
    #error "Omc_SEC_VAR_NO_INIT_UNSPECIFIED_ZONE not opened"
  #endif
  #undef CHK_Omc_SEC_STARTED
  #undef CHK_Omc_SEC_VAR_NO_INIT_UNSPECIFIED_STARTED

#else
  #error "Error: section does not exist in Omc_MemMap.h"
#endif
/*BMW - End*/

/*@@@visbch: Mapping of Omc sections to Vector default sections; mapping to OS sections is done within MemMap.h*/
#include "MemMap.h"

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of include and declaration area >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
