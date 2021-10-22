/**
*  \file
*
*  \brief       BMW SWC StdDiag
*
*  This file is the configuration source file of the module StdDiag
*  for usage in the BMW AUTOSAR Core.
*
*  \project     BMW Platform Software
*
*  \copyright   BMW AG 2015 - 2017
*
*  \version     5.4.0
*
*  \remarks     The StdDiag module is responsible for BMW specific session
*               handling and handles a number of BMW specific diagnostic requests.
*
*/

/*------------------------------------------------------------------------------
*
*  THIS FILE WAS GENERATED. DO NOT MODIFY!
*
*  GENERATOR       : BMW PAGe 1.1.0
*
*  GENERATION TIME : 2018-07-30 19:57:43.105398
*
------------------------------------------------------------------------------*/

/*------------------------------------------------------------------------------
                      MISRA-Deviations
------------------------------------------------------------------------------*/
/*
   MISRA-C:2004 Rule 19.1: including StdDiag_MemMap.h is necessary throughout
   the file according to memory abstraction. See PRQA 5087.
*/

/*------------------------------------------------------------------------------
                      Include Section
------------------------------------------------------------------------------*/

#include "StdDiag_IDRLAdapter.h"
#include "StdDiag_AdtTypes.h"
#include "StdDiagClassic_Cfg.h"
#include "StdDiagClassic_Version.h"
#include "StdDiag.h"
#include "Rte_StdDiag.h"

/*------------------------------------------------------------------------------
                      Macros
-------------------------------------------------------------------------------*/

/* check version of the module */
#if (!StdDiagClassic_CHECK_VERSION(5,4,0))
   #error "Version of StdDiagClassic_Cfg.c does not match the version of the module!"
#endif

/*------------------------------------------------------------------------------
                      Constants
------------------------------------------------------------------------------*/
/* PRQA S 5087 2 */
#define StdDiag_START_SEC_CONST_UNSPECIFIED
#include "StdDiag_MemMap.h"

/* PRQA S 5087 2 */
#define StdDiag_STOP_SEC_CONST_UNSPECIFIED
#include "StdDiag_MemMap.h"

