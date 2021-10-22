/**
 * \file
 *
 * \brief       Coding - This file is the configuration implementation file for
 *              the Coding module.
 *
 * \project     BMW Platform Software
 *
 * \copyright   BMW AG 2016 - 2017
 *
 * \version     5.2.1
 *
 */

/*------------------------------------------------------------------------------
*
*  THIS FILE WAS GENERATED. DO NOT MODIFY!
*
*  GENERATOR       : BMW PAGe 1.1.0
*
*  GENERATION TIME : 2018-07-30 19:57:39.743062
*
------------------------------------------------------------------------------*/

/*------------------------------------------------------------------------------
                      MISRA-Deviations
------------------------------------------------------------------------------*/
/*
 * Violation of MISRA-C:2004 Rule 19.1:
 * Reason: Including Coding_MemMap.h is necessary throughout
 * the file according to memory abstraction. See PRQA 5087.
 */

/*------------------------------------------------------------------------------
                      Include Section
-------------------------------------------------------------------------------*/
#include "Coding_Cfg.h"              /* Own header file */
#include "BUtil/PlatformTypes.h"     /* BMW Platform Types          */
#include "Coding_Data.h"

/*------------------------------------------------------------------------------
                      Macros
-------------------------------------------------------------------------------*/

/* check version of the module */
#if (!Coding_CHECK_VERSION(5,2,1))
   #error "Version of Coding_Cfg.c does not match the version of the module!"
#endif

/*------------------------------------------------------------------------------
                      Global Constants
-------------------------------------------------------------------------------*/

#define Coding_START_SEC_CONST_SAVED_RECOVERY_ZONE_UNSPECIFIED
#include "Coding_MemMap.h" /* PRQA S 5087 */

/**
 * \brief Coding default data.
 *
 * \lhref COD_091, COD_097
 *
 */
const Coding_DataType Coding_CodingDataDefault =
{
/*------------------------------------------------------------------------------
*  AreaName: CodingArea
-------------------------------------------------------------------------------*/
/* Coding data size: 30 */
0x00u,0x00u,0x00u,0x00u,0x00u,0x00u,0x00u,0x00u,0x00u,0x00u,0x00u,0x00u,0x00u,0x00u,0x00u,0x00u,0x00u,0x00u,0x00u,0x00u,0x00u,0x00u,0x00u,0x00u,0x00u,0x00u,0x00u,0x00u,0x00u,0x00u,
/* CAF-ID size: 8 */
/** \lhref COD_108, COD_109 */
0x05u,0xFFu,0xFFu,0xFFu,0xFFu,0xFFu,0xFFu,0xFFu,
/* Signature size: 96 */
/** \lhref COD_147, COD_148 */
0x00u,0x00u,0x00u,0x00u,0x00u,0x00u,0x00u,0x00u,0x00u,0x00u,0x00u,0x00u,0x00u,0x00u,0x00u,0x00u,0x00u,0x00u,0x00u,0x00u,0x00u,0x00u,0x00u,0x00u,0x00u,0x00u,0x00u,0x00u,0x00u,0x00u,0x00u,0x00u,0x00u,0x00u,0x00u,0x00u,0x00u,0x00u,0x00u,0x00u,0x00u,0x00u,0x00u,0x00u,0x00u,0x00u,0x00u,0x00u,0x00u,0x00u,0x00u,0x00u,0x00u,0x00u,0x00u,0x00u,0x00u,0x00u,0x00u,0x00u,0x00u,0x00u,0x00u,0x00u,0x00u,0x00u,0x00u,0x00u,0x00u,0x00u,0x00u,0x00u,0x00u,0x00u,0x00u,0x00u,0x00u,0x00u,0x00u,0x00u,0x00u,0x00u,0x00u,0x00u,0x00u,0x00u,0x00u,0x00u,0x00u,0x00u,0x00u,0x00u,0x00u,0x00u,0x00u,0x00u,
/*------------------------------------------------------------------------------
*  Coding proof stamp size: 18
-------------------------------------------------------------------------------*/
/** \lhref COD_093, COD_105, COD_106 */
0xFFu,0xFFu,0xFFu,0xFFu,0xFFu,0xFFu,0xFFu,0xFFu,0xFFu,0xFFu,0xFFu,0xFFu,0xFFu,0xFFu,0xFFu,0xFFu,0xFFu,0xFFu,
/*------------------------------------------------------------------------------
*  Programming id information size: 8
-------------------------------------------------------------------------------*/
0xFFu,0xFFu,0xFFu,0xFFu,0xFFu,0xFFu,0xFFu,0xFFu
};

#define Coding_STOP_SEC_CONST_SAVED_RECOVERY_ZONE_UNSPECIFIED
#include "Coding_MemMap.h" /* PRQA S 5087 */

#define Coding_START_SEC_CONST_16
#include "Coding_MemMap.h" /* PRQA S 5087 */

/**
 * \brief Stores the index to the start byte of the coding area in the Coding_CodingDataDefault array
 */
const uint16 Coding_AreaOffsetTable[CODING_NUMBER_OF_AREAS] = {
    0u /* AreaName: CodingArea */
};

/**
 * \brief Stores the size of each area
 */
const uint16 Coding_AreaSizeTable[CODING_NUMBER_OF_AREAS] = {
  134u /* AreaName: CodingArea */
};

/**
 * \brief Stores the index to the start byte of the Caf id block in the Coding_CodingDataDefault array.
 */
const uint16 Coding_CafIdOffsetTable[CODING_NUMBER_OF_AREAS] = {
   30u /* AreaName: CodingArea */
};

#define Coding_STOP_SEC_CONST_16
#include "Coding_MemMap.h" /* PRQA S 5087 */
