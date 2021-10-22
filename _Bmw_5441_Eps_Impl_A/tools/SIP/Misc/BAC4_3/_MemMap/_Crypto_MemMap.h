/*----------------------------------------------------------------------------*/
/**
*  \file
*
*  This file is a sample for the memory mapping header file of the
*  BMW AUTOSAR Core module "Crypto".
*
*  \project BMW AUTOSAR Core
*
*  \par To be changed by user:
*  yes
*
*  \copyright BMW AG 2012 - 2016
*
*  \remarks This file shall contain all memory mapping macros of the
*           module "Crypto".
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


#ifndef I_KNOW_THAT_THIS_CODE_IS_NOT_FOR_PRODUCTION
#error "the program must not be used in connection with series production"
#endif

#if 0

#elif defined (Crypto_START_SEC_CODE)
  #undef Crypto_START_SEC_CODE
  #define START_SEC_CODE                            /* mapped to default code section */
  #ifdef CHK_Crypto_SEC_CODE
    #error "Crypto_SEC_CODE already open"
  #endif
  #define CHK_Crypto_SEC_CODE


#elif defined (Crypto_START_SEC_CONST_JUMPTABLE)
  #undef Crypto_START_SEC_CONST_JUMPTABLE
  /*@@@visbch: Mapping to global section in MemMap.h*/
  #define START_SEC_CONST_8BIT
  #pragma section CCRYPJUMPT "CCRYPJUMPT"
  #if !defined( CCRYPJUMPT_USE_SECTION )
    #pragma use_section CCRYPJUMPT CryptoJumptable
    #define CCRYPJUMPT_USE_SECTION
  #endif
  #ifdef CHK_Crypto_SEC_CONST_JUMPTABLE
    #error "Crypto_SEC_CONST_JUMPTABLE already open"
  #endif
  #define CHK_Crypto_SEC_CONST_JUMPTABLE
#pragma option -Xsmall-const=0
#pragma option -Xsmall-data=0
//#pragma section CONST "DefaultSecConst" "DefaultSecConst"

#elif defined (Crypto_START_SEC_CONST_64)
#undef     Crypto_START_SEC_CONST_64
  /*@@@visbch: Mapping to global section in MemMap.h*/
  #define START_SEC_CONST_64BIT
  #ifdef CHK_Crypto_SEC_CONST_64
    #error "Crypto_SEC_CONST_64 already open"
  #endif
  #define CHK_Crypto_SEC_CONST_64
#pragma option -Xsmall-const=0
#pragma option -Xsmall-data=0
//#pragma section CONST "DefaultSecConst" "DefaultSecConst"


#elif defined (Crypto_START_SEC_CONST_UNSPECIFIED)
  #undef Crypto_START_SEC_CONST_UNSPECIFIED
  /*@@@visbch: Mapping to global section in MemMap.h*/
  #define START_SEC_CONST_UNSPECIFIED
  #ifdef CHK_Crypto_SEC_CONST_UNSPECIFIED
    #error "Crypto_SEC_CONST_UNSPECIFIED already open"
  #endif
  #define CHK_Crypto_SEC_CONST_UNSPECIFIED
#pragma option -Xsmall-const=0
#pragma option -Xsmall-data=0
//#pragma section CONST "DefaultSecConst" "DefaultSecConst"


#elif defined (Crypto_STOP_SEC_CODE)
  #undef Crypto_STOP_SEC_CODE
  /*@@@visbch: Mapping to global section in MemMap.h*/
  #define STOP_SEC_CODE                             /* default code stop section */
  #ifndef CHK_Crypto_SEC_CODE
    #error "Crypto_SEC_CODE not open"
  #endif
  #undef CHK_Crypto_SEC_CODE


#elif defined (Crypto_STOP_SEC_CONST_JUMPTABLE)
  #undef Crypto_STOP_SEC_CONST_JUMPTABLE
  /*@@@visbch: Mapping to global section in MemMap.h*/
  #define STOP_SEC_CONST                             /* default code stop section */
  #ifndef CHK_Crypto_SEC_CONST_JUMPTABLE
    #error "Crypto_SEC_CONST_JUMPTABLE not open"
  #endif
  #undef CHK_Crypto_SEC_CONST_JUMPTABLE
#pragma option -Xsmall-const=0
#pragma option -Xsmall-data=0
//#pragma section CONST "DefaultSecConst" "DefaultSecConst"

#elif defined (Crypto_STOP_SEC_CONST_64)
  #undef Crypto_STOP_SEC_CONST_64
  /*@@@visbch: Mapping to global section in MemMap.h*/
  #define STOP_SEC_CONST                             /* default code stop section */
  #ifndef CHK_Crypto_SEC_CONST_64
    #error "Crypto_SEC_CONST_64 not open"
  #endif
  #undef CHK_Crypto_SEC_CONST_64
#pragma option -Xsmall-const=0
#pragma option -Xsmall-data=0
//#pragma section CONST "DefaultSecConst" "DefaultSecConst"


#elif defined (Crypto_STOP_SEC_CONST_UNSPECIFIED)
  #undef Crypto_STOP_SEC_CONST_UNSPECIFIED
  /*@@@visbch: Mapping to global section in MemMap.h*/
  #define STOP_SEC_CONST                             /* default code stop section */
  #ifndef CHK_Crypto_SEC_CONST_UNSPECIFIED
    #error "Crypto_SEC_CONST_UNSPECIFIED not open"
  #endif
  #undef CHK_Crypto_SEC_CONST_UNSPECIFIED
#pragma option -Xsmall-const=0
#pragma option -Xsmall-data=0
//#pragma section CONST "DefaultSecConst" "DefaultSecConst"


#else
  #error "error section does not exist in this Crypto_MemMap.h"
#endif
/*BMW - End*/

/*@@@Vector: Mapping of Prog sections to Vector default sections; mapping to OS sections is done within MemMap.h*/
#include "MemMap.h"
