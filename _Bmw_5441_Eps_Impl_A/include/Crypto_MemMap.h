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


/* #error "This file must be integrated and adapted to the memory layout of your project. \ */
        /* Please refer to the integration manual." */

#if 0

#elif defined (Crypto_START_SEC_CODE)
   #undef     Crypto_START_SEC_CODE
   #define    DEFAULT_START_SEC_CODE
#elif defined (Crypto_STOP_SEC_CODE)
   #undef     Crypto_STOP_SEC_CODE
   #define    DEFAULT_STOP_SEC_CODE

#elif defined (Crypto_START_SEC_VAR_INIT_8)
   #undef     Crypto_START_SEC_VAR_INIT_8
   #define    DEFAULT_START_SEC_VAR_8BIT
#elif defined (Crypto_STOP_SEC_VAR_INIT_8)
   #undef     Crypto_STOP_SEC_VAR_INIT_8
   #define    DEFAULT_STOP_SEC_VAR_8BIT

#elif defined (Crypto_START_SEC_VAR_INIT_16)
   #undef     Crypto_START_SEC_VAR_INIT_16
   #define    DEFAULT_START_SEC_VAR_16BIT
#elif defined (Crypto_STOP_SEC_VAR_INIT_16)
   #undef     Crypto_STOP_SEC_VAR_INIT_16
   #define    DEFAULT_STOP_SEC_VAR_16BIT

#elif defined (Crypto_START_SEC_VAR_NO_INIT_8)
   #undef     Crypto_START_SEC_VAR_NO_INIT_8
   #define    DEFAULT_START_SEC_VAR_NO_INIT_8BIT
#elif defined (Crypto_STOP_SEC_VAR_NO_INIT_8)
   #undef     Crypto_STOP_SEC_VAR_NO_INIT_8
   #define    DEFAULT_STOP_SEC_VAR_NO_INIT_8BIT

#elif defined (Crypto_START_SEC_VAR_INIT_UNSPECIFIED)
   #undef      Crypto_START_SEC_VAR_INIT_UNSPECIFIED
#elif defined (Crypto_STOP_SEC_VAR_INIT_UNSPECIFIED)
   #undef      Crypto_STOP_SEC_VAR_INIT_UNSPECIFIED
   #define DEFAULT_STOP_SEC_VAR_INIT_UNSPECIFIED

#elif defined (Crypto_START_SEC_VAR_NO_INIT_UNSPECIFIED)
   #undef      Crypto_START_SEC_VAR_NO_INIT_UNSPECIFIED
#elif defined (Crypto_STOP_SEC_VAR_NO_INIT_UNSPECIFIED)
   #undef      Crypto_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
   #define DEFAULT_STOP_SEC_VAR_NO_INIT_UNSPECIFIED

#elif defined (Crypto_START_SEC_VAR_POWER_ON_CLEARED_UNSPECIFIED)
   #undef      Crypto_START_SEC_VAR_POWER_ON_CLEARED_UNSPECIFIED
#elif defined (Crypto_STOP_SEC_VAR_POWER_ON_CLEARED_UNSPECIFIED)
   #undef      Crypto_STOP_SEC_VAR_POWER_ON_CLEARED_UNSPECIFIED
   #define DEFAULT_STOP_SEC_VAR_POWER_ON_CLEARED_UNSPECIFIED

#elif defined (Crypto_START_SEC_VAR_CLEARED_16)
   #undef     Crypto_START_SEC_VAR_CLEARED_16
#elif defined (Crypto_STOP_SEC_VAR_CLEARED_16)
   #undef     Crypto_STOP_SEC_VAR_CLEARED_16
   #define    DEFAULT_STOP_SEC_VAR_CLEARED_16BIT

#elif defined (Crypto_START_SEC_CONST_16)
   #undef     Crypto_START_SEC_CONST_16
   #define    DEFAULT_START_SEC_VAR_16BIT
#elif defined (Crypto_STOP_SEC_CONST_16)
   #undef     Crypto_STOP_SEC_CONST_16
   #define    DEFAULT_STOP_SEC_VAR_16BIT

#elif defined (Crypto_START_SEC_CONST_32)
   #undef     Crypto_START_SEC_CONST_32
   #define    DEFAULT_START_SEC_VAR_32BIT
#elif defined (Crypto_STOP_SEC_CONST_32)
   #undef     Crypto_STOP_SEC_CONST_32
   #define    DEFAULT_STOP_SEC_VAR_32BIT

#elif defined (Crypto_START_SEC_CONST_64)
#undef     Crypto_START_SEC_CONST_64
   #define    DEFAULT_START_SEC_VAR_64BIT
#elif defined (Crypto_STOP_SEC_CONST_64)
#undef     Crypto_STOP_SEC_CONST_64
   #define    DEFAULT_STOP_SEC_VAR_64BIT

#elif defined (Crypto_START_SEC_CONST_UNSPECIFIED)
   #undef      Crypto_START_SEC_CONST_UNSPECIFIED
#elif defined (Crypto_STOP_SEC_CONST_UNSPECIFIED)
   #undef      Crypto_STOP_SEC_CONST_UNSPECIFIED
   #define DEFAULT_STOP_SEC_CONST_UNSPECIFIED

#elif defined (Crypto_START_SEC_CONST_JUMPTABLE)
#undef         Crypto_START_SEC_CONST_JUMPTABLE
#elif defined (Crypto_STOP_SEC_CONST_JUMPTABLE)
#undef         Crypto_STOP_SEC_CONST_JUMPTABLE
   #define    DEFAULT_STOP_SEC_CONST_JUMPTABLE

/* -----------------[End of the section switch]------------------------------ */

#else
  #error "Error: section does not exist in Crypto_MemMap.h"
#endif
