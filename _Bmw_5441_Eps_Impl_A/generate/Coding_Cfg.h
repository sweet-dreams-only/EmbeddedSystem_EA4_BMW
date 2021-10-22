/**
 * \file
 *
 * \brief       Coding - This file is the configuration header file for the
 *              Coding module.
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
*  GENERATION TIME : 2018-07-30 19:57:39.907079
*
------------------------------------------------------------------------------*/

#ifndef CODING_CFG_H
#define CODING_CFG_H

/*------------------------------------------------------------------------------
                      Include Section
-------------------------------------------------------------------------------*/

#include "BUtil/PlatformTypes.h"     /* BMW Platform Types          */
#include "Coding_Version.h"          /* Include check version macro */

/*------------------------------------------------------------------------------
                      Macros
-------------------------------------------------------------------------------*/

/* check version of the module */
#if (!Coding_CHECK_VERSION(5,2,1))
   #error "Version of Coding_Cfg.h does not match the version of the module!"
#endif

/**
 * \brief Coding condition check feature is needed
 *
 * Coding condition check feature is needed
 *
 * \remarks This macro depends on the configuration parameter CodingConditionCheck
 *
 */
#define CODING_CONDITIONCHECK_SUPPORT            STD_ON

/**
 * \brief Coding crypto support feature is needed
 *
 * Coding crypto support feature is needed
 *
 * \remarks This macro depends on the configuration parameter CodingCryptoEnable
 *
 */
#define CODING_CRYPTO_SUPPORT                    STD_ON

/**
 * \brief Coding data check feature is needed
 *
 * Coding data check feature is needed
 *
 * \remarks This macro depends on configuration parameter CodingDataCheck
 *
 */
#define CODING_DATACHECK_SUPPORT                 STD_ON

/**
 * \brief Coding dev error detect off
 *
 * Coding dev error detect off
 *
 * \remarks This macro depends on configuration parameter CodingDevErrorDetect
 *
 */
#define CODING_DEV_ERROR_DETECT                  STD_OFF

/**
 * \brief Coding producton CEUD detection off
 *
 * Coding producton CEUD detection off
 *
 * \remarks This macro depends on configuration parameter CodingProdErrorCEUDDetection
 *
 */
#define CODING_PROD_ERROR_CEUD_DETECTION         STD_OFF

/**
 * \brief Coding CPS offset
 *
 * Coding CPS offset
 * CodingUserBlockSize + 8(Caf id size) + CodingSignatureSize
 *
 * \remarks -
 *
 */
#define CODING_CPS_OFFSET                        134u

/**
 * \brief Coding ProgId offset
 *
 * Coding ProgId offset
 * CodingUserBlockSize + 8(Caf id size) + CodingSignatureSize + 18 (Cps size)
 *
 * \remarks -
 *
 */
#define CODING_PROGID_OFFSET                     152u

/**
 * \brief Number of areas
 *
 * Number of areas
 *
 * \remarks This macro depends on configuration parameter CodingArea
 *
 */
#define CODING_NUMBER_OF_AREAS                   1u

/**
 * \brief Number of Caf Blocks
 *
 * Number of Caf Blocks.
 * It can only be one Caf block per area.
 *
 * \remarks -
 *
 */
#define CODING_NUMBER_OF_CAF                     1u

/**
 * \brief Coding signature block size.
 *
 * Coding signature block size.
 *
 * \lhref COD_092
 *
 * \remarks This macro depends on configuration parameter CodingSignatureSize
 *
 */
#define CODING_SIGNATURE_BLOCK_SIZE              96u

/**
 * \brief Coding proof stamp size.
 *
 * Coding proof stamp size.
 *
 * \lhref COD_092, COD_186
 *
 * \remarks -
 *
 */
#define CODING_CPS_SIZE                          18u

/**
 * \brief Total codig data size
 *
 * Total codig data size. Its calculated from
 * CodingUserBlockSize + 8(Caf id size) + CodingSignatureSize + 18(Cps size) + 8(FirstStart size)
 *
 * \remarks This macro depends on configuration parameter CodingUserBlockSize and CodingSignatureSize
 *
 */
#define CODING_DATA_SIZE                         160u

/**
 * \brief Coding transport receive buffer size
 *
 * Coding transport receive buffer size
 *
 * \remarks This macro depends on configuration parameter CodingTransportReceiveBufferSize
 *
 */
#define CODING_RX_BUFFER_SIZE                    1024u

/**
 * \brief Coding transport send buffer size
 *
 * Coding transport send buffer size
 *
 * \remarks This macro depends on configuration parameter CodingTransportSendBufferSize
 *
 */
#define CODING_TX_BUFFER_SIZE                    1024u

/**
 * \brief Size of the coding protocol data information.
 *
 * Its calculated from: 2 byte (size of receive buffer) + 2 byte (size of send buffer)
 *                      + 1 byte (codingAreaCount) + 2 byte (ncdLength) per codingArea
 */
#define CODING_RDBIPROTOCOLDATA_SIZE             7u

/*------------------------------------------------------------------------------
                      Global Constants
-------------------------------------------------------------------------------*/

#define Coding_START_SEC_CONST_16
#include "Coding_MemMap.h" /* PRQA S 5087 */

/**
 * \brief Extern CAF id offset table.
 */
extern const uint16 Coding_CafIdOffsetTable[CODING_NUMBER_OF_AREAS];

/**
 * \brief Extern area offset table.
 */
extern const uint16 Coding_AreaOffsetTable[CODING_NUMBER_OF_AREAS];

/**
 * \brief Extern area size table.
 */
extern const uint16 Coding_AreaSizeTable[CODING_NUMBER_OF_AREAS];

#define Coding_STOP_SEC_CONST_16
#include "Coding_MemMap.h" /* PRQA S 5087 */

#endif /* CODING_CFG_H */
