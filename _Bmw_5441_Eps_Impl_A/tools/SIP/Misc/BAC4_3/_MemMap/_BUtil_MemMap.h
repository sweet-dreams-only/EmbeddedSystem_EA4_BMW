/*----------------------------------------------------------------------------*/
/**
*  \file
*
*  This file is a sample for the memory mapping header file of the
*  BMW AUTOSAR Core module "BUtil".
*
*  \project BMW AUTOSAR Core
*
*  \par To be changed by user:
*  yes
*
*  \copyright BMW AG 2012 - 2015
*
*  \remarks This file shall contain all memory mapping macros of the
*           module "BUtil".
*
*  \remarks The content of this file only serves as an example. If this file
*           is platform dependent, this shall be mentioned here.
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


/*@@@Vector: Commented out
#error "This file must be integrated and adapted to the memory layout of your project. \
        Please refer to the integration manual."
*/

#if 0

#elif defined (BUtil_START_SEC_CODE)
  #undef BUtil_START_SEC_CODE
  /*@@@visbch: Mapping to global section in MemMap.h*/
  #define START_SEC_CODE
  #ifdef CHK_BUtil_SEC_STARTED
    #error "BUtil section BUtil_SEC_CODE not closed"
  #endif
  #define CHK_BUtil_SEC_STARTED
  #define CHK_BUtil_SEC_CODE
  
#elif defined (BUtil_START_SEC_VAR_NO_INIT_8)
  #undef BUtil_START_SEC_VAR_NO_INIT_8
  /*@@@visbch: Mapping to global section in MemMap.h*/
  #define START_SEC_VAR_NO_INIT_8
  #ifdef CHK_BUtil_SEC_STARTED
    #error "BUtil section BUtil_START_SEC_VAR_NO_INIT_8 not closed"
  #endif
  #define CHK_BUtil_SEC_STARTED
  #define CHK_BUtil_SEC_VAR_NO_INIT_8

#elif defined (BUtil_START_SEC_VAR_INIT_UNSPECIFIED)
  #undef BUtil_START_SEC_VAR_INIT_UNSPECIFIED
  /*@@@visbch: Mapping to global section in MemMap.h*/
  #define START_SEC_VAR_INIT_UNSPECIFIED
  #ifdef CHK_BUtil_SEC_STARTED
    #error "BUtil section BUtil_START_SEC_VAR_INIT_UNSPECIFIED not closed"
  #endif
  #define CHK_BUtil_SEC_STARTED
  #define CHK_BUtil_SEC_VAR_INIT_UNSPECIFIED

#elif defined (BUtil_STOP_SEC_CODE)
  #undef BUtil_STOP_SEC_CODE
  /*@@@visbch: Mapping to global section in MemMap.h*/
  #define STOP_SEC_CODE
  #ifndef CHK_BUtil_SEC_CODE
    #error "BUtil_SEC_CODE not open"
  #endif
  #undef CHK_BUtil_SEC_STARTED
  #undef CHK_BUtil_SEC_CODE

#elif defined (BUtil_STOP_SEC_VAR_NO_INIT_8)
  #undef BUtil_STOP_SEC_VAR_NO_INIT_8
  /*@@@visbch: Mapping to global section in MemMap.h*/
  #define STOP_SEC_VAR
  #ifndef CHK_BUtil_SEC_VAR_NO_INIT_8
    #error "BUtil_SEC_VAR_NO_INIT_8 not open"
  #endif
  #undef CHK_BUtil_SEC_STARTED
  #undef CHK_BUtil_SEC_VAR_NO_INIT_8

#elif defined (BUtil_STOP_SEC_VAR_INIT_UNSPECIFIED)
  #undef BUtil_STOP_SEC_VAR_INIT_UNSPECIFIED
  /*@@@visbch: Mapping to global section in MemMap.h*/
  #define STOP_SEC_VAR
  #ifndef CHK_BUtil_SEC_VAR_INIT_UNSPECIFIED
    #error "BUtil_SEC_VAR_INIT_UNSPECIFIED not open"
  #endif
  #undef CHK_BUtil_SEC_STARTED
  #undef CHK_BUtil_SEC_VAR_INIT_UNSPECIFIED
#else
  #error "Error: section does not exist in BUtil_MemMap.h"
#endif
#include "MemMap.h"
