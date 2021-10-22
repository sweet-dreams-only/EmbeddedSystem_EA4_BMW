/*----------------------------------------------------------------------------*/
/**
*  \file
*
*  \brief       BMW Module Blu
*
*  This file is a sample for the memory mapping header file of the BMW AUTOSAR Core
*  module "BluClassic".
*
*  \project     BMW Platform Software
*
*  \copyright   BMW AG 2017
*
*  \version     5.0.2
*
*  \remarks     This file contains all memory mapping macros of the module "BluClassic".
*
*/


/*------------------------------------------------------------------------------
                      MISRA-Deviations
-------------------------------------------------------------------------------*/

/* MISRA-C:2004 Rule 19.6, Reason: #undef is necessary according to memory abstraction
   PRQA S 0841 EOF

   MISRA-C:2004 Rule 19.15, Reason: File must be included repeatedly according to
   memory abstraction
   PRQA S 0883 EOF */
/*
#error "This file must be integrated and adapted to the memory layout of your project. \
        Please refer to the integration manual."
*/
#if 0
/*-------------------------------------------
   START Sections
--------------------------------------------*/
#elif defined (Blu_START_SEC_CODE)
  #undef Blu_START_SEC_CODE
   /*@@@visbch: Mapping to global section in MemMap.h*/
  #define START_SEC_CODE                            /* mapped to default code section */
  #ifdef CHK_BluClassic_SEC_STARTED
    #error "Blu section not closed"
  #endif
  #define CHK_BluClassic_SEC_STARTED
  #define CHK_BluClassic_SEC_CODE_STARTED

#elif defined (Blu_START_SEC_CODE_NO_OPTIMIZATION)
#undef Blu_START_SEC_CODE_NO_OPTIMIZATION
   /*@@@visbch: Mapping to global section in MemMap.h*/
  #define START_SEC_CODE                            /* mapped to default code section */
  #ifdef CHK_BluClassic_SEC_STARTED
    #error "Blu section not closed"
  #endif
  #define CHK_BluClassic_SEC_STARTED
  #define CHK_BluClassic_SEC_CODE_NO_OPTIMIZATION_STARTED

#elif defined (Blu_START_SEC_CONST_SWEFLASHSTATUSCHECKSUM)
  #undef Blu_START_SEC_CONST_SWEFLASHSTATUSCHECKSUM
   /*@@@visbch: Mapping to global section in MemMap.h*/
  #define START_SEC_CONST_8BIT
//  #pragma ghs section rodata"BLUSWESTATUSCHECKSUM"
  #pragma section BLUSWESTATUSCHECKSUM "BLUSWESTATUSCHECKSUM"
  #if !defined( BLUSWESTATUSCHECKSUM_USE_SECTION )
    #pragma use_section BLUSWESTATUSCHECKSUM BluSweCheckSum
    #define BLUSWESTATUSCHECKSUM_USE_SECTION
  #endif
  #ifdef CHK_BluClassic_SEC_CONST_SWEFLASHSTATUSCHECKSUM
    #error "Blu_SEC_CONST_SWEFLASHSTATUSCHECKSUM already open"
  #endif
  #define CHK_BluClassic_SEC_CONST_SWEFLASHSTATUSCHECKSUM


#elif defined (Blu_START_SEC_CONST_SWEFLASHSTATUSVALIDFLAG)
  #undef Blu_START_SEC_CONST_SWEFLASHSTATUSVALIDFLAG
  /*@@@visbch: Mapping to global section in MemMap.h*/
  #define START_SEC_CONST_16BIT
//  #pragma ghs section rodata="BLUVALIDFLAG"
  #pragma section BLUVALIDFLAG "BLUVALIDFLAG"
  #if !defined( BLUVALIDFLAG_USE_SECTION )
    #pragma use_section BLUVALIDFLAG BluSweValidFlag
    #define BLUVALIDFLAG_USE_SECTION
  #endif
  #ifdef CHK_BluClassic_SEC_CONST_SWEFLASHSTATUSVALIDFLAG
    #error "Blu_SEC_CONST_SWEFLASHSTATUSVALIDFLAG already open"
  #endif
  #define CHK_BluClassic_SEC_CONST_SWEFLASHSTATUSVALIDFLAG

#elif defined (Blu_START_SEC_CONST_SWETABLE)
  #undef Blu_START_SEC_CONST_SWETABLE
  /*@@@visbch: Mapping to global section in MemMap.h*/
  #ifdef CHK_BluClassic_SEC_CONST_SWETABLE
    #error "BluClassic_SEC_CONST_SWETABLE already open"
  #endif
  #define CHK_BluClassic_SEC_CONST_SWETABLE
#pragma option -Xsmall-const=0
#pragma option -Xsmall-data=0
//#pragma section CONST "DefaultSecConst" "DefaultSecConst"
  #define START_SEC_CONST_UNSPECIFIED
//  #pragma ghs section rodata="SWE1DESC"
  #pragma section SWE1DESC "SWE1DESC"
  #if !defined( BLUSWEDESC_USE_SECTION )
    #pragma use_section SWE1DESC BluSweProcessClass
    #define BLUSWEDESC_USE_SECTION
  #endif


#elif defined (Blu_START_SEC_CONST_UNSPECIFIED)
  #undef Blu_START_SEC_CONST_UNSPECIFIED
  /*@@@visbch: Mapping to global section in MemMap.h*/
  #define START_SEC_CONST_UNSPECIFIED
  #ifdef CHK_BluClassic_SEC_CONST_UNSPECIFIED
    #error "BluClassic_SEC_CONST_UNSPECIFIED already open"
  #endif
  #define CHK_BluClassic_SEC_CONST_UNSPECIFIED
#pragma option -Xsmall-const=0
#pragma option -Xsmall-data=0
//#pragma section CONST "DefaultSecConst" "DefaultSecConst"


#elif defined (Blu_START_SEC_VAR_FLASHBUFFER)
  #undef Blu_START_SEC_VAR_FLASHBUFFER
  /*@@@visbch: Mapping to global section in MemMap.h*/
  #define START_SEC_VAR_NOINIT_UNSPECIFIED
//  #pragma ghs section bss=".BLUFLASHBUFFER"
  #pragma section DATA ".data" "BLUFLASHDRV" far-absolute
  #ifdef CHK_BluClassic_SEC_VAR_FLASHBUFFER
    #error "BluClassic_SEC_VAR_FLASHBUFFER already open"
  #endif
  #define CHK_BluClassic_SEC_VAR_FLASHBUFFER


#elif defined (Blu_START_SEC_VAR_INIT_32)
#undef Blu_START_SEC_VAR_INIT_32
   /*@@@visbch: Mapping to global section in MemMap.h*/
  #define START_SEC_VAR_INIT_32
  #ifdef CHK_BluClassic_SEC_STARTED
    #error "Blu section not closed"
  #endif
  #define CHK_BluClassic_SEC_STARTED
  #define CHK_BluClassic_SEC_VAR_INIT_32_STARTED


#elif defined (Blu_START_SEC_VAR_NO_INIT_8)
  #undef Blu_START_SEC_VAR_NO_INIT_8
  /*@@@visbch: Mapping to global section in MemMap.h*/
  #define START_SEC_VAR_NOINIT_8BIT
  #ifdef CHK_BluClassic_SEC_VAR_NO_INIT_8
    #error "BluClassic_SEC_VAR_NO_INIT_8 already open"
  #endif
  #define CHK_BluClassic_SEC_VAR_NO_INIT_8


#elif defined (Blu_START_SEC_VAR_NO_INIT_UNSPECIFIED)
  #undef Blu_START_SEC_VAR_NO_INIT_UNSPECIFIED
  /*@@@visbch: Mapping to global section in MemMap.h*/
  #define START_SEC_VAR_NOINIT_UNSPECIFIED
  #ifdef CHK_BluClassic_SEC_VAR_NO_INIT_UNSPECIFIED
    #error "BluClassic_SEC_VAR_NO_INIT_UNSPECIFIED already open"
  #endif
  #define CHK_BluClassic_SEC_VAR_NO_INIT_UNSPECIFIED

/*-------------------------------------------
   STOP Sections
--------------------------------------------*/
#elif defined (Blu_STOP_SEC_CODE)
  #undef Blu_STOP_SEC_CODE
   /*@@@visbch: Mapping to global section in MemMap.h*/
  #define STOP_SEC_CODE                             /* default code stop section */
  #ifndef CHK_BluClassic_SEC_CODE_STARTED
    #error "Blu_SEC_CODE not opened"
  #endif
  #undef CHK_BluClassic_SEC_STARTED
  #undef CHK_BluClassic_SEC_CODE_STARTED

#elif defined (Blu_STOP_SEC_CODE_NO_OPTIMIZATION)
#undef Blu_STOP_SEC_CODE_NO_OPTIMIZATION
   /*@@@visbch: Mapping to global section in MemMap.h*/
  #define STOP_SEC_CODE                             /* default code stop section */
  #ifndef CHK_BluClassic_SEC_CODE_NO_OPTIMIZATION_STARTED
    #error "Blu_SEC_CODE_NO_OPTIMIZATION not opened"
  #endif
  #undef CHK_BluClassic_SEC_STARTED
  #undef CHK_BluClassic_SEC_CODE_NO_OPTIMIZATION_STARTED

#elif defined (Blu_STOP_SEC_CONST_SWEFLASHSTATUSCHECKSUM)
  #undef Blu_STOP_SEC_CONST_SWEFLASHSTATUSCHECKSUM
   /*@@@visbch: Mapping to global section in MemMap.h*/
  #ifndef CHK_BluClassic_SEC_CONST_SWEFLASHSTATUSCHECKSUM
    #error "Blu_SEC_CONST_SWEFLASHSTATUSCHECKSUM not opened"
  #endif
  #undef CHK_BluClassic_SEC_CONST_SWEFLASHSTATUSCHECKSUM
#pragma option -Xsmall-const=0
#pragma option -Xsmall-data=0
//#pragma section CONST "DefaultSecConst" "DefaultSecConst"
  #define STOP_SEC_CONST                             /* default code stop section */
//  #pragma ghs section rodata=default


#elif defined (Blu_STOP_SEC_CONST_SWEFLASHSTATUSVALIDFLAG)
  #undef Blu_STOP_SEC_CONST_SWEFLASHSTATUSVALIDFLAG
   /*@@@visbch: Mapping to global section in MemMap.h*/
  #ifndef CHK_BluClassic_SEC_CONST_SWEFLASHSTATUSVALIDFLAG
    #error "Blu_SEC_CONST_SWEFLASHSTATUSVALIDFLAG not opened"
  #endif
  #undef CHK_BluClassic_SEC_CONST_SWEFLASHSTATUSVALIDFLAG
#pragma option -Xsmall-const=0
#pragma option -Xsmall-data=0
//#pragma section CONST "DefaultSecConst" "DefaultSecConst"
  #define STOP_SEC_CONST                             /* default code stop section */
//  #pragma ghs section rodata=default


#elif defined (Blu_STOP_SEC_CONST_SWETABLE)
  #undef Blu_STOP_SEC_CONST_SWETABLE
   /*@@@visbch: Mapping to global section in MemMap.h*/
  #ifndef CHK_BluClassic_SEC_CONST_SWETABLE
    #error "Blu_SEC_CONST_SWETABLE not opened"
  #endif
  #undef CHK_BluClassic_SEC_CONST_SWETABLE
#pragma option -Xsmall-const=0
#pragma option -Xsmall-data=0
//#pragma section CONST "DefaultSecConst" "DefaultSecConst"
  #define STOP_SEC_CONST                             /* default code stop section */
//  #pragma ghs section rodata=default


#elif defined (Blu_STOP_SEC_CONST_UNSPECIFIED)
  #undef Blu_STOP_SEC_CONST_UNSPECIFIED
  /*@@@visbch: Mapping to global section in MemMap.h*/
  #ifndef CHK_BluClassic_SEC_CONST_UNSPECIFIED
    #error "Blu_SEC_CONST_UNSPECIFIED not opened"
  #endif
  #undef CHK_BluClassic_SEC_CONST_UNSPECIFIED
#pragma option -Xsmall-const=0
#pragma option -Xsmall-data=0
//#pragma section CONST "DefaultSecConst" "DefaultSecConst"
  #define STOP_SEC_CONST                             /* default code stop section */
//  #pragma ghs section rodata=default


#elif defined (Blu_STOP_SEC_VAR_FLASHBUFFER)
  #undef Blu_STOP_SEC_VAR_FLASHBUFFER
  /*@@@visbch: Mapping to global section in MemMap.h*/
  #define STOP_SEC_VAR                             /* default code stop section */
//  #pragma ghs section rodata=default
  #ifndef CHK_BluClassic_SEC_VAR_FLASHBUFFER
    #error "Blu_SEC_VAR_FLASHBUFFER not opened"
  #endif
  #undef CHK_BluClassic_SEC_VAR_FLASHBUFFER

#elif defined (Blu_STOP_SEC_VAR_INIT_32)
  #undef Blu_STOP_SEC_VAR_INIT_32
   /*@@@visbch: Mapping to global section in MemMap.h*/
  #define STOP_SEC_VAR
  #ifndef CHK_BluClassic_SEC_VAR_INIT_32_STARTED
    #error "Blu_SEC_VAR_INIT_32 not opened"
  #endif
  #undef CHK_BluClassic_SEC_STARTED
  #undef CHK_BluClassic_SEC_VAR_INIT_32_STARTED

#elif defined (Blu_STOP_SEC_VAR_NO_INIT_8)
#undef Blu_STOP_SEC_VAR_NO_INIT_8
  /*@@@visbch: Mapping to global section in MemMap.h*/
  #define STOP_SEC_VAR                             /* default code stop section */
//  #pragma ghs section rodata=default
  #ifndef CHK_BluClassic_SEC_VAR_NO_INIT_8
    #error "Blu_SEC_VAR_NO_INIT_8 not opened"
  #endif
  #undef CHK_BluClassic_SEC_VAR_NO_INIT_8


#elif defined (Blu_STOP_SEC_VAR_NO_INIT_UNSPECIFIED)
  #undef Blu_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
  /*@@@visbch: Mapping to global section in MemMap.h*/
  #define STOP_SEC_VAR                             /* default code stop section */
//  #pragma ghs section rodata=default
  #ifndef CHK_BluClassic_SEC_VAR_NO_INIT_UNSPECIFIED
    #error "Blu_SEC_VAR_NO_INIT_UNSPECIFIED not opened"
  #endif
  #undef CHK_BluClassic_SEC_VAR_NO_INIT_UNSPECIFIED


#else
  #error "Error: section does not exist in Blu_MemMap.h"
#endif
/*BMW - End*/

/*@@@visbch: Mapping of Blu sections to Vector default sections; mapping to OS sections is done within MemMap.h*/
#include "MemMap.h"

