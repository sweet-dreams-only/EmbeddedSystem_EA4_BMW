/*----------------------------------------------------------------------------*/
/**
*  \file
*
*  \brief       BMW module Nrv
*
*  This file is a sample for the memory mapping header file of the
*  BMW AUTOSAR Core module "Nrv".
*
*  \project     BMW AUTOSAR Core
*
*  \par         To be changed by user:
*               yes
*
*  \copyright   BMW AG 2012 - 2015
*
*  \version     5.0.3
*
*  \remarks     This file shall contain all memory mapping macros of the
*               module "Nrv".
*
*  \remarks     The content of this file only serves as an example. If this file
*               is platform dependent, this shall be mentioned here.
*
*/
/*----------------------------------------------------------------------------*/

/*------------------------------------------------------------------------------
                      MISRA-Deviations
------------------------------------------------------------------------------*/

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
#elif defined (Nrv_START_SEC_CODE)
  #undef Nrv_START_SEC_CODE
  /*@@@visbch: Mapping to global section in MemMap.h*/
  #define START_SEC_CODE                            /* mapped to default code section */
  #ifdef CHK_Nrv_SEC_STARTED
    #error "Nrv section not closed"
  #endif
  #define CHK_Nrv_SEC_STARTED
  #define CHK_Nrv_SEC_CODE_STARTED

#elif defined (Nrv_START_SEC_VAR_INIT_16)
  #undef Nrv_START_SEC_VAR_INIT_16
  /*@@@visbch: Mapping to global section in MemMap.h*/
  #define START_SEC_VAR_INIT_16BIT                            /* mapped to default code section */
  #ifdef CHK_Nrv_SEC_STARTED
    #error "Nrv section not closed"
  #endif
  #define CHK_Nrv_SEC_STARTED
  #define CHK_Nrv_SEC_VAR_INIT_16_STARTED

#elif defined (Nrv_START_SEC_VAR_INIT_32)
  #undef Nrv_START_SEC_VAR_INIT_32
  /*@@@visbch: Mapping to global section in MemMap.h*/
  #define START_SEC_VAR_INIT_32BIT                            /* mapped to default code section */
  #ifdef CHK_Nrv_SEC_STARTED
    #error "Nrv section not closed"
  #endif
  #define CHK_Nrv_SEC_STARTED
  #define CHK_Nrv_SEC_VAR_INIT_32_STARTED

#elif defined (Nrv_START_SEC_VAR_INIT_UNSPECIFIED)
  #undef Nrv_START_SEC_VAR_INIT_UNSPECIFIED
  /*@@@visbch: Mapping to global section in MemMap.h*/
  #define START_SEC_VAR_INIT_UNSPECIFIED                            /* mapped to default code section */
  #ifdef CHK_Nrv_SEC_STARTED
    #error "Nrv section not closed"
  #endif
  #define CHK_Nrv_SEC_STARTED
  #define CHK_Nrv_SEC_VAR_INIT_UNSPECIFIED_STARTED

#elif defined (Nrv_START_SEC_VAR_NO_INIT_32)
  #undef Nrv_START_SEC_VAR_NO_INIT_32
  /*@@@visbch: Mapping to global section in MemMap.h*/
  #define START_SEC_VAR_NOINIT_32BIT                            /* mapped to default code section */
  #ifdef CHK_Nrv_SEC_STARTED
    #error "Nrv section not closed"
  #endif
  #define CHK_Nrv_SEC_STARTED
  #define CHK_Nrv_SEC_VAR_NO_INIT_32_STARTED

#elif defined (Nrv_START_SEC_VAR_NO_INIT_UNSPECIFIED)
  #undef Nrv_START_SEC_VAR_NO_INIT_UNSPECIFIED
  /*@@@visbch: Mapping to global section in MemMap.h*/
  #define START_SEC_VAR_NOINIT_UNSPECIFIED                            /* mapped to default code section */
  #ifdef CHK_Nrv_SEC_STARTED
    #error "Nrv section not closed"
  #endif
  #define CHK_Nrv_SEC_STARTED
  #define CHK_Nrv_SEC_VAR_NO_INIT_UNSPECIFIED_STARTED

/*-------------------------------------------
   STOP Sections
--------------------------------------------*/
#elif defined (Nrv_STOP_SEC_CODE)
  #undef Nrv_STOP_SEC_CODE
  /*@@@visbch: Mapping to global section in MemMap.h*/
  #define STOP_SEC_CODE                             /* default code stop section */
  #ifndef CHK_Nrv_SEC_CODE_STARTED
    #error "Nrv_SEC_CODE not opened"
  #endif
  #undef CHK_Nrv_SEC_STARTED
  #undef CHK_Nrv_SEC_CODE_STARTED

#elif defined (Nrv_STOP_SEC_VAR_INIT_16)
  #undef Nrv_STOP_SEC_VAR_INIT_16
  /*@@@visbch: Mapping to global section in MemMap.h*/
  #define STOP_SEC_VAR                             /* default code stop section */
  #ifndef CHK_Nrv_SEC_VAR_INIT_16_STARTED
    #error "Nrv_SEC_VAR_INIT_16 not opened"
  #endif
  #undef CHK_Nrv_SEC_STARTED
  #undef CHK_Nrv_SEC_VAR_INIT_16_STARTED

#elif defined (Nrv_STOP_SEC_VAR_INIT_32)
  #undef Nrv_STOP_SEC_VAR_INIT_32
  /*@@@visbch: Mapping to global section in MemMap.h*/
  #define STOP_SEC_VAR                             /* default code stop section */
  #ifndef CHK_Nrv_SEC_VAR_INIT_32_STARTED
    #error "Nrv_SEC_VAR_INIT_32 not opened"
  #endif
  #undef CHK_Nrv_SEC_STARTED
  #undef CHK_Nrv_SEC_VAR_INIT_32_STARTED

#elif defined (Nrv_STOP_SEC_VAR_INIT_UNSPECIFIED)
  #undef Nrv_STOP_SEC_VAR_INIT_UNSPECIFIED
  /*@@@visbch: Mapping to global section in MemMap.h*/
  #define STOP_SEC_VAR                             /* default code stop section */
  #ifndef CHK_Nrv_SEC_VAR_INIT_UNSPECIFIED_STARTED
    #error "Nrv_SEC_VAR_INIT_UNSPECIFIED not opened"
  #endif
  #undef CHK_Nrv_SEC_STARTED
  #undef CHK_Nrv_SEC_VAR_NO_INIT_UNSPECIFIED_STARTED

#elif defined (Nrv_STOP_SEC_VAR_NO_INIT_32)
  #undef Nrv_STOP_SEC_VAR_NO_INIT_32
  /*@@@visbch: Mapping to global section in MemMap.h*/
  #define STOP_SEC_VAR                             /* default code stop section */
  #ifndef CHK_Nrv_SEC_VAR_NO_INIT_32_STARTED
    #error "Nrv_SEC_VAR_NO_INIT_32 not opened"
  #endif
  #undef CHK_Nrv_SEC_STARTED
  #undef CHK_Nrv_SEC_VAR_NO_INIT_UNSPECIFIED_STARTED

#elif defined (Nrv_STOP_SEC_VAR_NO_INIT_UNSPECIFIED)
  #undef Nrv_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
  /*@@@visbch: Mapping to global section in MemMap.h*/
  #define STOP_SEC_VAR                             /* default code stop section */
  #ifndef CHK_Nrv_SEC_VAR_NO_INIT_UNSPECIFIED_STARTED
    #error "Nrv_SEC_VAR_NO_INIT_UNSPECIFIED not opened"
  #endif
  #undef CHK_Nrv_SEC_STARTED
  #undef CHK_Nrv_SEC_VAR_NO_INIT_UNSPECIFIED_STARTED

#else
  #error "Error: section does not exist in Nrv_MemMap.h"
#endif
/*BMW - End*/

/*@@@Vector: Mapping of Nrv sections to Vector default sections; mapping to OS sections is done within MemMap.h*/
#include "MemMap.h"
