/**
*  \file
*
*  This file is a sample for the memory mapping header file of the BMW AUTOSAR Core
*  module "Prog".
*
*  \project     BMW Platform Software
*
*  \copyright   BMW AG 2016 - 2017
*
*  \version     5.3.0
*
*  \remarks This file contains all memory mapping macros of the module "Prog".
*
*/

/* Violation of MISRA rule 19.6, Reason: #undef is necessary
 * according to memory abstraction */
/* PRQA S 0841 EOF */

/* Violation of MISRA rule 19.15, Reason: File must be included repeatedly
 * according to memory abstraction */
/* PRQA S 0883 EOF */

/*
#error "This file must be integrated and adapted to the memory layout of your project. \
        Please refer to the integration manual."
*/
#if 0
/*-------------------------------------------
   START Sections
--------------------------------------------*/
#elif defined (Prog_START_SEC_CODE)
  #undef Prog_START_SEC_CODE
  /*@@@visbch: Mapping to global section in MemMap.h*/
  #define START_SEC_CODE                            /* mapped to default code section */
  #ifdef CHK_Prog_SEC_STARTED
    #error "Prog section not closed"
  #endif
  #define CHK_Prog_SEC_STARTED
  #define CHK_Prog_SEC_CODE_STARTED

#elif defined (Prog_START_SEC_CONST_8)
#undef Prog_START_SEC_CONST_8
  /*@@@visbch: Mapping to global section in MemMap.h*/
  #define START_SEC_CONST_8BIT                            /* mapped to default code section */
  #ifdef CHK_Prog_SEC_STARTED
    #error "Prog section not closed"
  #endif
  #define CHK_Prog_SEC_STARTED
  #define CHK_Prog_SEC_CONST_8_STARTED

#elif defined (Prog_START_SEC_CONST_32)
  #undef Prog_START_SEC_CONST_32
  /*@@@visbch: Mapping to global section in MemMap.h*/
  #define START_SEC_CONST_32BIT                            /* mapped to default code section */
  #ifdef CHK_Prog_SEC_STARTED
    #error "Prog section not closed"
  #endif
  #define CHK_Prog_SEC_STARTED
  #define CHK_Prog_SEC_CONST_32_STARTED

#elif defined (Prog_START_SEC_VAR_NO_INIT_8)
#undef Prog_START_SEC_VAR_NO_INIT_8
  /*@@@visbch: Mapping to global section in MemMap.h*/
  #define START_SEC_VAR_NOINIT_8BIT                            /* mapped to default code section */
  #ifdef CHK_Prog_SEC_STARTED
    #error "Prog section not closed"
  #endif
  #define CHK_Prog_SEC_STARTED
  #define CHK_Prog_SEC_VAR_NO_INIT_8_STARTED

#elif defined (Prog_START_SEC_VAR_NO_INIT_32)
  #undef Prog_START_SEC_VAR_NO_INIT_32
  /*@@@visbch: Mapping to global section in MemMap.h*/
  #define START_SEC_VAR_NOINIT_32BIT                            /* mapped to default code section */
  #ifdef CHK_Prog_SEC_STARTED
    #error "Prog section not closed"
  #endif
  #define CHK_Prog_SEC_STARTED
  #define CHK_Prog_SEC_VAR_NO_INIT_32_STARTED

#elif defined (Prog_START_SEC_VAR_POWER_ON_CLEARED_32)
  #undef Prog_START_SEC_VAR_POWER_ON_CLEARED_32
  /*@@@visbch: Mapping to global section in MemMap.h*/
  #define START_SEC_VAR_FAST_ZERO_INIT_32BIT                            /* mapped to default code section */
  #ifdef CHK_Prog_SEC_STARTED
    #error "Prog section not closed"
  #endif
  #define CHK_Prog_SEC_STARTED
  #define CHK_Prog_SEC_VAR_POWER_ON_CLEARED_32_STARTED

#elif defined (Prog_START_SEC_VAR_NO_INIT_UNSPECIFIED)
  #undef Prog_START_SEC_VAR_NO_INIT_UNSPECIFIED
  /*@@@visbch: Mapping to global section in MemMap.h*/
  #define START_SEC_VAR_NOINIT_UNSPECIFIED                            /* mapped to default code section */
  #ifdef CHK_Prog_SEC_STARTED
    #error "Prog section not closed"
  #endif
  #define CHK_Prog_SEC_STARTED
  #define CHK_Prog_SEC_VAR_NO_INIT_UNSPECIFIED_STARTED

#elif defined (Prog_START_SEC_VAR_INIT_UNSPECIFIED)
  #undef Prog_START_SEC_VAR_INIT_UNSPECIFIED
  /*@@@visbch: Mapping to global section in MemMap.h*/
  #define START_SEC_VAR_INIT_UNSPECIFIED                            /* mapped to default code section */
  #ifdef CHK_Prog_SEC_STARTED
    #error "Prog section not closed"
  #endif
  #define CHK_Prog_SEC_STARTED
  #define CHK_Prog_SEC_VAR_INIT_UNSPECIFIED_STARTED

#elif defined (Prog_START_SEC_VAR_SAVED_ZONE_UNSPECIFIED)
  #undef Prog_START_SEC_VAR_SAVED_ZONE_UNSPECIFIED
  /*@@@visbch: Mapping to global section in MemMap.h*/
  #define START_SEC_VAR_NOINIT_UNSPECIFIED                            /* mapped to default code section */
  #ifdef CHK_Prog_SEC_STARTED
    #error "Prog section not closed"
  #endif
  #define CHK_Prog_SEC_STARTED
  #define CHK_Prog_SEC_VAR_SAVED_ZONE_UNSPECIFIED_STARTED

/*-------------------------------------------
   STOP Sections
--------------------------------------------*/
#elif defined (Prog_STOP_SEC_CODE)
  #undef Prog_STOP_SEC_CODE
  /*@@@visbch: Mapping to global section in MemMap.h*/
  #define STOP_SEC_CODE                             /* default code stop section */
  #ifndef CHK_Prog_SEC_CODE_STARTED
    #error "Prog_SEC_CODE not opened"
  #endif
  #undef CHK_Prog_SEC_STARTED
  #undef CHK_Prog_SEC_CODE_STARTED

#elif defined (Prog_STOP_SEC_CONST_8)
#undef Prog_STOP_SEC_CONST_8
  /*@@@visbch: Mapping to global section in MemMap.h*/
  #define STOP_SEC_CONST                             /* default code stop section */
  #ifndef CHK_Prog_SEC_CONST_8_STARTED
    #error "Prog_SEC_CONST_32 not opened"
  #endif
  #undef CHK_Prog_SEC_STARTED
  #undef CHK_Prog_SEC_CONST_8_STARTED

#elif defined (Prog_STOP_SEC_CONST_32)
  #undef Prog_STOP_SEC_CONST_32
  /*@@@visbch: Mapping to global section in MemMap.h*/
  #define STOP_SEC_CONST                             /* default code stop section */
  #ifndef CHK_Prog_SEC_CONST_32_STARTED
    #error "Prog_SEC_CONST_32 not opened"
  #endif
  #undef CHK_Prog_SEC_STARTED
  #undef CHK_Prog_SEC_CONST_32_STARTED

#elif defined (Prog_STOP_SEC_VAR_NO_INIT_8)
#undef Prog_STOP_SEC_VAR_NO_INIT_8
  /*@@@visbch: Mapping to global section in MemMap.h*/
  #define STOP_SEC_VAR                             /* default code stop section */
  #ifndef CHK_Prog_SEC_VAR_NO_INIT_8_STARTED
    #error "Prog_SEC_VAR_NO_INIT_8 not opened"
  #endif
  #undef CHK_Prog_SEC_STARTED
  #undef CHK_Prog_SEC_VAR_NO_INIT_8_STARTED

#elif defined (Prog_STOP_SEC_VAR_NO_INIT_32)
  #undef Prog_STOP_SEC_VAR_NO_INIT_32
  /*@@@visbch: Mapping to global section in MemMap.h*/
  #define STOP_SEC_VAR                             /* default code stop section */
  #ifndef CHK_Prog_SEC_VAR_NO_INIT_32_STARTED
    #error "Prog_SEC_VAR_NO_INIT_32 not opened"
  #endif
  #undef CHK_Prog_SEC_STARTED
  #undef CHK_Prog_SEC_VAR_NO_INIT_32_STARTED

#elif defined (Prog_STOP_SEC_VAR_POWER_ON_CLEARED_32)
  #undef Prog_STOP_SEC_VAR_POWER_ON_CLEARED_32
  /*@@@visbch: Mapping to global section in MemMap.h*/
  #define STOP_SEC_VAR                             /* default code stop section */
  #ifndef CHK_Prog_SEC_VAR_POWER_ON_CLEARED_32_STARTED
    #error "Prog_SEC_VAR_POWER_ON_CLEARED_32 not opened"
  #endif
  #undef CHK_Prog_SEC_STARTED
  #undef CHK_Prog_SEC_VAR_POWER_ON_CLEARED_32_STARTED

#elif defined (Prog_STOP_SEC_VAR_NO_INIT_UNSPECIFIED)
  #undef Prog_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
  /*@@@visbch: Mapping to global section in MemMap.h*/
  #define STOP_SEC_VAR                             /* default code stop section */
  #ifndef CHK_Prog_SEC_VAR_NO_INIT_UNSPECIFIED_STARTED
    #error "Prog_SEC_VAR_NO_INIT_UNSPECIFIED not opened"
  #endif
  #undef CHK_Prog_SEC_STARTED
  #undef CHK_Prog_SEC_VAR_NO_INIT_UNSPECIFIED_STARTED

#elif defined (Prog_STOP_SEC_VAR_INIT_UNSPECIFIED)
  #undef Prog_STOP_SEC_VAR_INIT_UNSPECIFIED
  /*@@@visbch: Mapping to global section in MemMap.h*/
  #define STOP_SEC_VAR                             /* default code stop section */
  #ifndef CHK_Prog_SEC_VAR_INIT_UNSPECIFIED_STARTED
    #error "Prog_SEC_VAR_INIT_UNSPECIFIED not opened"
  #endif
  #undef CHK_Prog_SEC_STARTED
  #undef CHK_Prog_SEC_VAR_INIT_UNSPECIFIED_STARTED

#elif defined (Prog_STOP_SEC_VAR_SAVED_ZONE_UNSPECIFIED)
  #undef Prog_STOP_SEC_VAR_SAVED_ZONE_UNSPECIFIED
  /*@@@visbch: Mapping to global section in MemMap.h*/
  #define STOP_SEC_VAR                             /* default code stop section */
  #ifndef CHK_Prog_SEC_VAR_SAVED_ZONE_UNSPECIFIED_STARTED
    #error "Prog_SEC_VAR_SAVED_ZONE_UNSPECIFIED not opened"
  #endif
  #undef CHK_Prog_SEC_STARTED
  #undef CHK_Prog_SEC_VAR_SAVED_ZONE_UNSPECIFIED_STARTED

#else
  #error "Error: section does not exist in Prog_MemMap.h"
#endif
/*BMW - End*/

/*@@@Vector: Mapping of Prog sections to Vector default sections; mapping to OS sections is done within MemMap.h*/
#include "MemMap.h"
