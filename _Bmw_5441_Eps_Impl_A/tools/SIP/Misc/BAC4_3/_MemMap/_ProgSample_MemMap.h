/**
*  \file
*
*  This file is a sample for the memory mapping header file of the BMW AUTOSAR Core
*  module "ProgSample".
*
*  \project     BMW Platform Software
*
*  \copyright   BMW AG 2016 - 2017
*
*  \version     5.1.1
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
#elif defined (ProgSample_START_SEC_CODE)
  #undef ProgSample_START_SEC_CODE
  /*@@@visbch: Mapping to global section in MemMap.h*/
  #define START_SEC_CODE                            /* mapped to default code section */
  #ifdef CHK_ProgSample_SEC_STARTED
    #error "ProgSample section not closed"
  #endif
  #define CHK_ProgSample_SEC_STARTED
  #define CHK_ProgSample_SEC_CODE_STARTED

#elif defined (ProgSample_STOP_SEC_CODE)
  #undef ProgSample_STOP_SEC_CODE
  /*@@@visbch: Mapping to global section in MemMap.h*/
  #define STOP_SEC_CODE                             /* default code stop section */
  #ifndef CHK_ProgSample_SEC_CODE_STARTED
    #error "ProgSample_SEC_CODE not opened"
  #endif
  #undef CHK_ProgSample_SEC_STARTED
  #undef CHK_ProgSample_SEC_CODE_STARTED

#else
  #error "Error: section does not exist in ProgSample_MemMap.h"
#endif
/*BMW - End*/

/*@@@Vector: Mapping of ProgSample sections to Vector default sections; mapping to OS sections is done within MemMap.h*/
#include "MemMap.h"
