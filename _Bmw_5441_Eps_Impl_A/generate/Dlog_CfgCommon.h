/**
*  \file
*
*  \brief       Common configuration header file of module Dlog.
*
*  This file contains configuration parameters that are commonly used by
*  Application, Bootloader and Bootmanager
*
*  \project     BMW Platform Software
*
*  \copyright   BMW AG 2015 - 2017
*
*  \version     5.3.1
*
*/

/*------------------------------------------------------------------------------
*
*  THIS FILE WAS GENERATED. DO NOT MODIFY!
*
*  GENERATOR       : BMW PAGe 1.1.0
*
*  GENERATION TIME : 2018-07-30 19:57:39.604048
*
------------------------------------------------------------------------------*/

#ifndef DLOG_CFG_COMMON_H
#define DLOG_CFG_COMMON_H

/*------------------------------------------------------------------------------
                      Include Section
------------------------------------------------------------------------------*/

#include "DlogClassic_Version.h"
#include "BUtil_ByteMask.h"
#include <stddef.h>


/*------------------------------------------------------------------------------
                      MISRA-Deviations
------------------------------------------------------------------------------*/

/* Violation of MISRA rule 19.7, Reason: C90 does not support inline
 * functions, see PRQA 3453
 */


/*------------------------------------------------------------------------------
                      Macros
------------------------------------------------------------------------------*/

/* check version of the module */
#if (!DlogClassic_CHECK_VERSION(5,3,1))
   #error "Version of Dlog_CfgCommon.h does not match the version of the module!"
#endif


/**
 * fingerprint bit mask and length format identifier:
 */
#define DLOG_FINGERPRINT_LENGTH_MASK                                       0xF0u
#define DLOG_FINGERPRINT_TESTER_SERVICE_ID_MASK                            0x0Fu
#define DLOG_FINGERPRINT_SHORT                                             0x00u
#define DLOG_FINGERPRINT_LONG                                              0x80u
#define DLOG_FINGERPRINT_PRGDATE_INITIAL                                   0x99u
#define DLOG_FINGERPRINT_PRGDATE_YEAR_POS                                  0x00u
#define DLOG_FINGERPRINT_PRGDATE_MONTH_POS                                 0x01u
#define DLOG_FINGERPRINT_PRGDATE_DAY_POS                                   0x02u
#define DLOG_FINGERPRINT_FORMAT_POS                                        0x03u
#define DLOG_FINGERPRINT_TESTER_SERVICE_ID_INITIAL                         0x0Bu

#define DLOG_FINGERPRINT_INITIAL \
          /* programming date                                                     */ \
          (uint8)DLOG_FINGERPRINT_PRGDATE_INITIAL, \
          (uint8)DLOG_FINGERPRINT_PRGDATE_INITIAL, \
          (uint8)DLOG_FINGERPRINT_PRGDATE_INITIAL, \
           \
          /* fingerprint format / tester sevice id                                */ \
          ( \
          ( (uint8)DLOG_FINGERPRINT_SHORT        & \
          (uint8)DLOG_FINGERPRINT_LENGTH_MASK \
          ) \
          | \
          ( (uint8)DLOG_FINGERPRINT_TESTER_SERVICE_ID_INITIAL & \
          (uint8)DLOG_FINGERPRINT_TESTER_SERVICE_ID_MASK \
          ) \
          )


/* ----------------------------------------------------------------------- */
/*                     Flash timing parameters                             */
/* ----------------------------------------------------------------------- */
/* in seconds, according to FP5_5563 et seqq.                               */

#define DLOG_ERASEMEMORYTIME                   0x0064u     /* maximum 0x0078    */
#define DLOG_CHECKMEMORYTIME                   0x003cu     /* maximum 0x003C    */
#define DLOG_BOOTLOADERINSTALLATIONTIME        0x0064u     /* maximum 0x0078    */
#define DLOG_AUTHENTIFICATIONTIME              0x000au     /* maximum 0x000A    */
#define DLOG_RESETTIME                         0x000au     /* maximum 0x000A    */
#define DLOG_TRANSFERDATATIME                  0x003cu


/* ----------------------------------------------------------------------- */
/*                     Platform                                            */
/* ----------------------------------------------------------------------- */

   /******** ConvertExtAddress2IntPointer / ConvertIntPointer2ExtAddress *********/
   /* uint32 ConvertExtAddress2IntPointer(uint32 extAddress);                    */
   /* uint32 ConvertIntPointer2ExtAddress(uint32 intPointer);                    */
   /* Converts a logical block number sent by the tester (e.g. a pointer to a    */
   /* SWE table) to an internal (far) pointer and vice versa.                    */
   /*                                                                            */
   /* nothing to do on 32 bit platforms                                          */
   /*                                                                            */
   #define Dlog_ConvertExtAddress2IntPointer(extAddress)   ((uint32)extAddress) /* PRQA S 3453 */
   #define Dlog_ConvertIntPointer2ExtAddress(intPointer)   ((uint32)intPointer) /* PRQA S 3453 */


/* -------------------------------------------------------------------------- */
/*                     SWE status specific defines                            */
/* -------------------------------------------------------------------------- */

/**
 * Length of the SWE CRC checksum area. It must have a correct size for HIS
 * flash driver
 */
#define DLOG_SWE_CRC_CHECKSUM_AREA_LENGTH      (0x100u * sizeof(size_t) / 4)
/** SWE CRC checksum data. It must have size of 'SWE_CRC_CHECKSUM_AREA_LENGTH'*/
#define DLOG_SWE_CRC_CHECKSUM_DATA                               \
   (uint8)0x00u,    (uint8)0x00u,    (uint8)0x00u,    (uint8)0x00u,  \
   (uint8)0x00u,    (uint8)0x00u,    (uint8)0x00u,    (uint8)0x00u,  \
   (uint8)0x00u,    (uint8)0x00u,    (uint8)0x00u,    (uint8)0x00u,  \
   (uint8)0x00u,    (uint8)0x00u,    (uint8)0x00u,    (uint8)0x00u,  \
   (uint8)0x00u,    (uint8)0x00u,    (uint8)0x00u,    (uint8)0x00u,  \
   (uint8)0x00u,    (uint8)0x00u,    (uint8)0x00u,    (uint8)0x00u,  \
   (uint8)0x00u,    (uint8)0x00u,    (uint8)0x00u,    (uint8)0x00u,  \
   (uint8)0x00u,    (uint8)0x00u,    (uint8)0x00u,    (uint8)0x00u,  \
   (uint8)0x00u,    (uint8)0x00u,    (uint8)0x00u,    (uint8)0x00u,  \
   (uint8)0x00u,    (uint8)0x00u,    (uint8)0x00u,    (uint8)0x00u,  \
   (uint8)0x00u,    (uint8)0x00u,    (uint8)0x00u,    (uint8)0x00u,  \
   (uint8)0x00u,    (uint8)0x00u,    (uint8)0x00u,    (uint8)0x00u,  \
   (uint8)0x00u,    (uint8)0x00u,    (uint8)0x00u,    (uint8)0x00u,  \
   (uint8)0x00u,    (uint8)0x00u,    (uint8)0x00u,    (uint8)0x00u,  \
   (uint8)0x00u,    (uint8)0x00u,    (uint8)0x00u,    (uint8)0x00u,  \
   (uint8)0x00u,    (uint8)0x00u,    (uint8)0x00u,    (uint8)0x00u,  \
   (uint8)0x00u,    (uint8)0x00u,    (uint8)0x00u,    (uint8)0x00u,  \
   (uint8)0x00u,    (uint8)0x00u,    (uint8)0x00u,    (uint8)0x00u,  \
   (uint8)0x00u,    (uint8)0x00u,    (uint8)0x00u,    (uint8)0x00u,  \
   (uint8)0x00u,    (uint8)0x00u,    (uint8)0x00u,    (uint8)0x00u,  \
   (uint8)0x00u,    (uint8)0x00u,    (uint8)0x00u,    (uint8)0x00u,  \
   (uint8)0x00u,    (uint8)0x00u,    (uint8)0x00u,    (uint8)0x00u,  \
   (uint8)0x00u,    (uint8)0x00u,    (uint8)0x00u,    (uint8)0x00u,  \
   (uint8)0x00u,    (uint8)0x00u,    (uint8)0x00u,    (uint8)0x00u,  \
   (uint8)0x00u,    (uint8)0x00u,    (uint8)0x00u,    (uint8)0x00u,  \
   (uint8)0x00u,    (uint8)0x00u,    (uint8)0x00u,    (uint8)0x00u,  \
   (uint8)0x00u,    (uint8)0x00u,    (uint8)0x00u,    (uint8)0x00u,  \
   (uint8)0x00u,    (uint8)0x00u,    (uint8)0x00u,    (uint8)0x00u,  \
   (uint8)0x00u,    (uint8)0x00u,    (uint8)0x00u,    (uint8)0x00u,  \
   (uint8)0x00u,    (uint8)0x00u,    (uint8)0x00u,    (uint8)0x00u,  \
   (uint8)0x00u,    (uint8)0x00u,    (uint8)0x00u,    (uint8)0x00u,  \
   (uint8)0x00u,    (uint8)0x00u,    (uint8)0x00u,    (uint8)0x00u,  \
   (uint8)0x00u,    (uint8)0x00u,    (uint8)0x00u,    (uint8)0x00u,  \
   (uint8)0x00u,    (uint8)0x00u,    (uint8)0x00u,    (uint8)0x00u,  \
   (uint8)0x00u,    (uint8)0x00u,    (uint8)0x00u,    (uint8)0x00u,  \
   (uint8)0x00u,    (uint8)0x00u,    (uint8)0x00u,    (uint8)0x00u,  \
   (uint8)0x00u,    (uint8)0x00u,    (uint8)0x00u,    (uint8)0x00u,  \
   (uint8)0x00u,    (uint8)0x00u,    (uint8)0x00u,    (uint8)0x00u,  \
   (uint8)0x00u,    (uint8)0x00u,    (uint8)0x00u,    (uint8)0x00u,  \
   (uint8)0x00u,    (uint8)0x00u,    (uint8)0x00u,    (uint8)0x00u,  \
   (uint8)0x00u,    (uint8)0x00u,    (uint8)0x00u,    (uint8)0x00u,  \
   (uint8)0x00u,    (uint8)0x00u,    (uint8)0x00u,    (uint8)0x00u,  \
   (uint8)0x00u,    (uint8)0x00u,    (uint8)0x00u,    (uint8)0x00u,  \
   (uint8)0x00u,    (uint8)0x00u,    (uint8)0x00u,    (uint8)0x00u,  \
   (uint8)0x00u,    (uint8)0x00u,    (uint8)0x00u,    (uint8)0x00u,  \
   (uint8)0x00u,    (uint8)0x00u,    (uint8)0x00u,    (uint8)0x00u,  \
   (uint8)0x00u,    (uint8)0x00u,    (uint8)0x00u,    (uint8)0x00u,  \
   (uint8)0x00u,    (uint8)0x00u,    (uint8)0x00u,    (uint8)0x00u,  \
   (uint8)0x00u,    (uint8)0x00u,    (uint8)0x00u,    (uint8)0x00u,  \
   (uint8)0x00u,    (uint8)0x00u,    (uint8)0x00u,    (uint8)0x00u,  \
   (uint8)0x00u,    (uint8)0x00u,    (uint8)0x00u,    (uint8)0x00u,  \
   (uint8)0x00u,    (uint8)0x00u,    (uint8)0x00u,    (uint8)0x00u,  \
   (uint8)0x00u,    (uint8)0x00u,    (uint8)0x00u,    (uint8)0x00u,  \
   (uint8)0x00u,    (uint8)0x00u,    (uint8)0x00u,    (uint8)0x00u,  \
   (uint8)0x00u,    (uint8)0x00u,    (uint8)0x00u,    (uint8)0x00u,  \
   (uint8)0x00u,    (uint8)0x00u,    (uint8)0x00u,    (uint8)0x00u,  \
   (uint8)0x00u,    (uint8)0x00u,    (uint8)0x00u,    (uint8)0x00u,  \
   (uint8)0x00u,    (uint8)0x00u,    (uint8)0x00u,    (uint8)0x00u,  \
   (uint8)0x00u,    (uint8)0x00u,    (uint8)0x00u,    (uint8)0x00u,  \
   (uint8)0x00u,    (uint8)0x00u,    (uint8)0x00u,    (uint8)0x00u,  \
   (uint8)0x00u,    (uint8)0x00u,    (uint8)0x00u,    (uint8)0x00u,  \
   (uint8)0x00u,    (uint8)0x00u,    (uint8)0x00u,    (uint8)0x00u,  \
   (uint8)0x00u,    (uint8)0x00u,    (uint8)0x00u,    (uint8)0x00u,  \
   (uint8)0x00u,    (uint8)0x00u,    (uint8)0x00u,    (uint8)0x00u   
/**
 * Length of the SWE valid flag area. It must have a correct size for HIS flash
 * driver
 */
#define DLOG_SWE_VALID_FLAG_AREA_LENGTH        0x100u
/** SWE valid flag data. It must have size of 'SWE_VALID_FLAG_AREA_LENGTH'    */
#define DLOG_SWE_VALID_FLAG_DATA                                 \
   (uint8)0x5Au, (uint8)0x5Au, (uint8)0x00u, (uint8)0x00u,  \
   (uint8)0x00u,    (uint8)0x00u,    (uint8)0x00u,    (uint8)0x00u,  \
   (uint8)0x00u,    (uint8)0x00u,    (uint8)0x00u,    (uint8)0x00u,  \
   (uint8)0x00u,    (uint8)0x00u,    (uint8)0x00u,    (uint8)0x00u,  \
   (uint8)0x00u,    (uint8)0x00u,    (uint8)0x00u,    (uint8)0x00u,  \
   (uint8)0x00u,    (uint8)0x00u,    (uint8)0x00u,    (uint8)0x00u,  \
   (uint8)0x00u,    (uint8)0x00u,    (uint8)0x00u,    (uint8)0x00u,  \
   (uint8)0x00u,    (uint8)0x00u,    (uint8)0x00u,    (uint8)0x00u,  \
   (uint8)0x00u,    (uint8)0x00u,    (uint8)0x00u,    (uint8)0x00u,  \
   (uint8)0x00u,    (uint8)0x00u,    (uint8)0x00u,    (uint8)0x00u,  \
   (uint8)0x00u,    (uint8)0x00u,    (uint8)0x00u,    (uint8)0x00u,  \
   (uint8)0x00u,    (uint8)0x00u,    (uint8)0x00u,    (uint8)0x00u,  \
   (uint8)0x00u,    (uint8)0x00u,    (uint8)0x00u,    (uint8)0x00u,  \
   (uint8)0x00u,    (uint8)0x00u,    (uint8)0x00u,    (uint8)0x00u,  \
   (uint8)0x00u,    (uint8)0x00u,    (uint8)0x00u,    (uint8)0x00u,  \
   (uint8)0x00u,    (uint8)0x00u,    (uint8)0x00u,    (uint8)0x00u,  \
   (uint8)0x00u,    (uint8)0x00u,    (uint8)0x00u,    (uint8)0x00u,  \
   (uint8)0x00u,    (uint8)0x00u,    (uint8)0x00u,    (uint8)0x00u,  \
   (uint8)0x00u,    (uint8)0x00u,    (uint8)0x00u,    (uint8)0x00u,  \
   (uint8)0x00u,    (uint8)0x00u,    (uint8)0x00u,    (uint8)0x00u,  \
   (uint8)0x00u,    (uint8)0x00u,    (uint8)0x00u,    (uint8)0x00u,  \
   (uint8)0x00u,    (uint8)0x00u,    (uint8)0x00u,    (uint8)0x00u,  \
   (uint8)0x00u,    (uint8)0x00u,    (uint8)0x00u,    (uint8)0x00u,  \
   (uint8)0x00u,    (uint8)0x00u,    (uint8)0x00u,    (uint8)0x00u,  \
   (uint8)0x00u,    (uint8)0x00u,    (uint8)0x00u,    (uint8)0x00u,  \
   (uint8)0x00u,    (uint8)0x00u,    (uint8)0x00u,    (uint8)0x00u,  \
   (uint8)0x00u,    (uint8)0x00u,    (uint8)0x00u,    (uint8)0x00u,  \
   (uint8)0x00u,    (uint8)0x00u,    (uint8)0x00u,    (uint8)0x00u,  \
   (uint8)0x00u,    (uint8)0x00u,    (uint8)0x00u,    (uint8)0x00u,  \
   (uint8)0x00u,    (uint8)0x00u,    (uint8)0x00u,    (uint8)0x00u,  \
   (uint8)0x00u,    (uint8)0x00u,    (uint8)0x00u,    (uint8)0x00u,  \
   (uint8)0x00u,    (uint8)0x00u,    (uint8)0x00u,    (uint8)0x00u,  \
   (uint8)0x00u,    (uint8)0x00u,    (uint8)0x00u,    (uint8)0x00u,  \
   (uint8)0x00u,    (uint8)0x00u,    (uint8)0x00u,    (uint8)0x00u,  \
   (uint8)0x00u,    (uint8)0x00u,    (uint8)0x00u,    (uint8)0x00u,  \
   (uint8)0x00u,    (uint8)0x00u,    (uint8)0x00u,    (uint8)0x00u,  \
   (uint8)0x00u,    (uint8)0x00u,    (uint8)0x00u,    (uint8)0x00u,  \
   (uint8)0x00u,    (uint8)0x00u,    (uint8)0x00u,    (uint8)0x00u,  \
   (uint8)0x00u,    (uint8)0x00u,    (uint8)0x00u,    (uint8)0x00u,  \
   (uint8)0x00u,    (uint8)0x00u,    (uint8)0x00u,    (uint8)0x00u,  \
   (uint8)0x00u,    (uint8)0x00u,    (uint8)0x00u,    (uint8)0x00u,  \
   (uint8)0x00u,    (uint8)0x00u,    (uint8)0x00u,    (uint8)0x00u,  \
   (uint8)0x00u,    (uint8)0x00u,    (uint8)0x00u,    (uint8)0x00u,  \
   (uint8)0x00u,    (uint8)0x00u,    (uint8)0x00u,    (uint8)0x00u,  \
   (uint8)0x00u,    (uint8)0x00u,    (uint8)0x00u,    (uint8)0x00u,  \
   (uint8)0x00u,    (uint8)0x00u,    (uint8)0x00u,    (uint8)0x00u,  \
   (uint8)0x00u,    (uint8)0x00u,    (uint8)0x00u,    (uint8)0x00u,  \
   (uint8)0x00u,    (uint8)0x00u,    (uint8)0x00u,    (uint8)0x00u,  \
   (uint8)0x00u,    (uint8)0x00u,    (uint8)0x00u,    (uint8)0x00u,  \
   (uint8)0x00u,    (uint8)0x00u,    (uint8)0x00u,    (uint8)0x00u,  \
   (uint8)0x00u,    (uint8)0x00u,    (uint8)0x00u,    (uint8)0x00u,  \
   (uint8)0x00u,    (uint8)0x00u,    (uint8)0x00u,    (uint8)0x00u,  \
   (uint8)0x00u,    (uint8)0x00u,    (uint8)0x00u,    (uint8)0x00u,  \
   (uint8)0x00u,    (uint8)0x00u,    (uint8)0x00u,    (uint8)0x00u,  \
   (uint8)0x00u,    (uint8)0x00u,    (uint8)0x00u,    (uint8)0x00u,  \
   (uint8)0x00u,    (uint8)0x00u,    (uint8)0x00u,    (uint8)0x00u,  \
   (uint8)0x00u,    (uint8)0x00u,    (uint8)0x00u,    (uint8)0x00u,  \
   (uint8)0x00u,    (uint8)0x00u,    (uint8)0x00u,    (uint8)0x00u,  \
   (uint8)0x00u,    (uint8)0x00u,    (uint8)0x00u,    (uint8)0x00u,  \
   (uint8)0x00u,    (uint8)0x00u,    (uint8)0x00u,    (uint8)0x00u,  \
   (uint8)0x00u,    (uint8)0x00u,    (uint8)0x00u,    (uint8)0x00u,  \
   (uint8)0x00u,    (uint8)0x00u,    (uint8)0x00u,    (uint8)0x00u,  \
   (uint8)0x00u,    (uint8)0x00u,    (uint8)0x00u,    (uint8)0x00u,  \
   (uint8)0x00u,    (uint8)0x00u,    (uint8)0x00u,    (uint8)0x00u   
/**
 * Length of the programming dependencies flag area. It must have a correct
 * size for his flash driver
 *
 * 4 Bytes Counter, 1 Byte ProgDepFlag, 3 Bytes Padding, 4 Bytes Fingerprint, 8 Bytes ProgId
 */
#define DLOG_PROG_DEP_AREA_LENGTH              0x100u
/** Programming dependencies data. It must have size of 'PROG_DEP_AREA_LENGTH'*/
#define DLOG_PROG_DEP_DATA                                       \
  (uint8)0x00u, (uint8)0x00u, (uint8)0x00u, (uint8)0x01u,  \
  (uint8)0x01u, (uint8)0x00u, (uint8)0x00u, (uint8)0x00u,  \
  DLOG_FINGERPRINT_INITIAL,  \
  (uint8)0x01u, (uint8)0x02u, (uint8)0x03u, (uint8)0x04u,  \
  (uint8)0x05u, (uint8)0x06u, (uint8)0x07u, (uint8)0x08u,  \
  (uint8)0x00u,   (uint8)0x00u,   (uint8)0x00u,   (uint8)0x00u,  \
  (uint8)0x00u,   (uint8)0x00u,   (uint8)0x00u,   (uint8)0x00u,  \
  (uint8)0x00u,   (uint8)0x00u,   (uint8)0x00u,   (uint8)0x00u,  \
  (uint8)0x00u,   (uint8)0x00u,   (uint8)0x00u,   (uint8)0x00u,  \
  (uint8)0x00u,   (uint8)0x00u,   (uint8)0x00u,   (uint8)0x00u,  \
  (uint8)0x00u,   (uint8)0x00u,   (uint8)0x00u,   (uint8)0x00u,  \
  (uint8)0x00u,   (uint8)0x00u,   (uint8)0x00u,   (uint8)0x00u,  \
  (uint8)0x00u,   (uint8)0x00u,   (uint8)0x00u,   (uint8)0x00u,  \
  (uint8)0x00u,   (uint8)0x00u,   (uint8)0x00u,   (uint8)0x00u,  \
  (uint8)0x00u,   (uint8)0x00u,   (uint8)0x00u,   (uint8)0x00u,  \
  (uint8)0x00u,   (uint8)0x00u,   (uint8)0x00u,   (uint8)0x00u,  \
  (uint8)0x00u,   (uint8)0x00u,   (uint8)0x00u,   (uint8)0x00u,  \
  (uint8)0x00u,   (uint8)0x00u,   (uint8)0x00u,   (uint8)0x00u,  \
  (uint8)0x00u,   (uint8)0x00u,   (uint8)0x00u,   (uint8)0x00u,  \
  (uint8)0x00u,   (uint8)0x00u,   (uint8)0x00u,   (uint8)0x00u,  \
  (uint8)0x00u,   (uint8)0x00u,   (uint8)0x00u,   (uint8)0x00u,  \
  (uint8)0x00u,   (uint8)0x00u,   (uint8)0x00u,   (uint8)0x00u,  \
  (uint8)0x00u,   (uint8)0x00u,   (uint8)0x00u,   (uint8)0x00u,  \
  (uint8)0x00u,   (uint8)0x00u,   (uint8)0x00u,   (uint8)0x00u,  \
  (uint8)0x00u,   (uint8)0x00u,   (uint8)0x00u,   (uint8)0x00u,  \
  (uint8)0x00u,   (uint8)0x00u,   (uint8)0x00u,   (uint8)0x00u,  \
  (uint8)0x00u,   (uint8)0x00u,   (uint8)0x00u,   (uint8)0x00u,  \
  (uint8)0x00u,   (uint8)0x00u,   (uint8)0x00u,   (uint8)0x00u,  \
  (uint8)0x00u,   (uint8)0x00u,   (uint8)0x00u,   (uint8)0x00u,  \
  (uint8)0x00u,   (uint8)0x00u,   (uint8)0x00u,   (uint8)0x00u,  \
  (uint8)0x00u,   (uint8)0x00u,   (uint8)0x00u,   (uint8)0x00u,  \
  (uint8)0x00u,   (uint8)0x00u,   (uint8)0x00u,   (uint8)0x00u,  \
  (uint8)0x00u,   (uint8)0x00u,   (uint8)0x00u,   (uint8)0x00u,  \
  (uint8)0x00u,   (uint8)0x00u,   (uint8)0x00u,   (uint8)0x00u,  \
  (uint8)0x00u,   (uint8)0x00u,   (uint8)0x00u,   (uint8)0x00u,  \
  (uint8)0x00u,   (uint8)0x00u,   (uint8)0x00u,   (uint8)0x00u,  \
  (uint8)0x00u,   (uint8)0x00u,   (uint8)0x00u,   (uint8)0x00u,  \
  (uint8)0x00u,   (uint8)0x00u,   (uint8)0x00u,   (uint8)0x00u,  \
  (uint8)0x00u,   (uint8)0x00u,   (uint8)0x00u,   (uint8)0x00u,  \
  (uint8)0x00u,   (uint8)0x00u,   (uint8)0x00u,   (uint8)0x00u,  \
  (uint8)0x00u,   (uint8)0x00u,   (uint8)0x00u,   (uint8)0x00u,  \
  (uint8)0x00u,   (uint8)0x00u,   (uint8)0x00u,   (uint8)0x00u,  \
  (uint8)0x00u,   (uint8)0x00u,   (uint8)0x00u,   (uint8)0x00u,  \
  (uint8)0x00u,   (uint8)0x00u,   (uint8)0x00u,   (uint8)0x00u,  \
  (uint8)0x00u,   (uint8)0x00u,   (uint8)0x00u,   (uint8)0x00u,  \
  (uint8)0x00u,   (uint8)0x00u,   (uint8)0x00u,   (uint8)0x00u,  \
  (uint8)0x00u,   (uint8)0x00u,   (uint8)0x00u,   (uint8)0x00u,  \
  (uint8)0x00u,   (uint8)0x00u,   (uint8)0x00u,   (uint8)0x00u,  \
  (uint8)0x00u,   (uint8)0x00u,   (uint8)0x00u,   (uint8)0x00u,  \
  (uint8)0x00u,   (uint8)0x00u,   (uint8)0x00u,   (uint8)0x00u,  \
  (uint8)0x00u,   (uint8)0x00u,   (uint8)0x00u,   (uint8)0x00u,  \
  (uint8)0x00u,   (uint8)0x00u,   (uint8)0x00u,   (uint8)0x00u,  \
  (uint8)0x00u,   (uint8)0x00u,   (uint8)0x00u,   (uint8)0x00u,  \
  (uint8)0x00u,   (uint8)0x00u,   (uint8)0x00u,   (uint8)0x00u,  \
  (uint8)0x00u,   (uint8)0x00u,   (uint8)0x00u,   (uint8)0x00u,  \
  (uint8)0x00u,   (uint8)0x00u,   (uint8)0x00u,   (uint8)0x00u,  \
  (uint8)0x00u,   (uint8)0x00u,   (uint8)0x00u,   (uint8)0x00u,  \
  (uint8)0x00u,   (uint8)0x00u,   (uint8)0x00u,   (uint8)0x00u,  \
  (uint8)0x00u,   (uint8)0x00u,   (uint8)0x00u,   (uint8)0x00u,  \
  (uint8)0x00u,   (uint8)0x00u,   (uint8)0x00u,   (uint8)0x00u,  \
  (uint8)0x00u,   (uint8)0x00u,   (uint8)0x00u,   (uint8)0x00u,  \
  (uint8)0x00u,   (uint8)0x00u,   (uint8)0x00u,   (uint8)0x00u  
#define DLOG_PROG_DEP_OFS_COUNTER      0u
#define DLOG_PROG_DEP_OFS_FLAG         4u
#define DLOG_PROG_DEP_OFS_FINGERPRINT  8u
#define DLOG_PROG_DEP_OFS_PROGID      12u

/**
 * Length of the whole SWE flash status area
 */
#define DLOG_SWE_FLASH_STATUS_AREA_LENGTH                                           \
   ( DLOG_SWE_CRC_CHECKSUM_AREA_LENGTH +                                            \
     DLOG_SWE_VALID_FLAG_AREA_LENGTH   +                                            \
     DLOG_PROG_DEP_AREA_LENGTH                                                      \
   )


/**
 * This defines the value which indicates erased flash memory. This is usually
 * 0xFF, however on Tricore it is 0x00.
 */
#define FLASH_ERASED_BYTE                 0xffu


/* -------------------------------------------------------------------------- */
/*            SWE / Programming Dependencies State on ECC error               */
/* -------------------------------------------------------------------------- */

#define DLOG_SWE_STATE_ECC_ERROR DLOG_SWE_STATE_INVALID
#define DLOG_PROG_DEP_ECC_ERROR  DLOG_PROG_DEP_INVALID

/* ----------------------------------------------------------------------- */
/*                     Logistic Data                                       */
/* ----------------------------------------------------------------------- */

/**
 * The number of Svk backups beside the system supplier and plan svk history.
 * Svk backups are not mandatory. Choose '0u' to disable this feature. Dont't
 * forget to update NvM configuration.
 * 0u <= NUMBEROFSVKBACKUPS <= 61u
 */
#define DLOG_SVKBACKUPENABLE            STD_OFF
#define DLOG_NUMBEROFSVKBACKUPS         0u
#define DLOG_ECUSERIALNUMBERDEFAULT     '1','2','3','4','5','6','7','8','9','0'

#define DLOG_ECUMANUFACTURINGDATELENGTH      3u
#define DLOG_ECUMANUFACTURINGDATEDEFAULT     0x00,0x00,0x00

#define DLOG_ECUUIDDEFAULT 0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08, 0x09, 0x0a, 0x0b, 0x0c, 0x0d, 0x0e, 0xee

/**
 * Length of the HWE development info field:
 * The HardwareDevelopmentInfo CAN NOT be overwritten by the SWE-Generator tool.
 * The length that is configured here will be reserved in a protected ROM space
 * (in the BootManager). It is not designated that the size can be increased
 * during ECU livetime.
 */
#define DLOG_HWEDEVELOPMENTINFOLENGTH        10u

#define DLOG_SWE_DEV_INFO_LENGTH             10u

#define DLOG_HWETABLE_INIT_FROM_ROM  STD_ON

/* -------------------------------------------------------------------------- */
/*                    initialisation data of HWE Sgbm Id(s)                   */
/* -------------------------------------------------------------------------- */

#define DLOG_HWE1CLASSIFICATIONDATA      DLOG_PROCESSCLASS_HWEL
#define DLOG_HWE1LOGISTICIDENTIFIERDATA  (uint8)0x00u, (uint8)0x00u, (uint8)0x00u, (uint8)0x01u
#define DLOG_HWE1VERSIONDATA             (uint8)0x01u, (uint8)0x00u, (uint8)0x00u
/* HWEDevelopmentInfo */
#if (DLOG_HWEDEVELOPMENTINFOLENGTH > 0u)
   #define DLOG_HWE1DEVELOPMENTINFO      (uint8)7u,'H','W','E','D','A','T','A'
/*                                         'H','W','E','L','H','W','E','D','E','V','I','N','F','O' */
#endif

#define DLOG_HWE1_TABLE_ENTRY \
      {                                      \
         {                                   \
            DLOG_HWE1CLASSIFICATIONDATA,     \
            DLOG_HWE1LOGISTICIDENTIFIERDATA, \
            DLOG_HWE1VERSIONDATA             \
         },                                  \
         {DLOG_HWE1DEVELOPMENTINFO}          \
      }


/* -------------------------------------------------------------------------- */
/*                 initialisation data of Boot.-SWE1 Sgbm Id                  */
/* -------------------------------------------------------------------------- */
/* BTLD: Bootloader                                                           */
#define BOOTSWECLASSIFICATIONDATA   DLOG_PROCESSCLASS_BTLD
#if (DLOG_SWE_DEV_INFO_LENGTH > 0u)
   #define BOOTSWEDEVINFO           (uint8)4u,'B','T','L','D'
#endif

/* -------------------------------------------------------------------------- */
/*                 initialisation data of Appl.-SWE1 Sgbm Id                  */
/* -------------------------------------------------------------------------- */
/* SWFL: Software ECU memory image                                            */
#define SWE1SWECLASSIFICATIONDATA   DLOG_PROCESSCLASS_SWFL
#if (DLOG_SWE_DEV_INFO_LENGTH > 0u)
   #define SWE1SWEDEVINFO           (uint8)8u,'S','W','F','L','A','P','P','L'
#endif


/* -------------------------------------------------------------------------- */
/*                 initialisation data of Appl.-SWE2 Sgbm Id                  */
/* -------------------------------------------------------------------------- */
/* SWFL: Software ECU memory image                                            */
#define SWE2SWECLASSIFICATIONDATA   DLOG_PROCESSCLASS_SWFL
#if (DLOG_SWE_DEV_INFO_LENGTH > 0u)
   #define SWE2SWEDEVINFO           (uint8)4u,'S','W','F','L'
#endif


/* -------------------------------------------------------------------------- */
/*                 initialisation data of Appl.-SWE3 Sgbm Id                  */
/* -------------------------------------------------------------------------- */
/* SWFL: Software ECU memory image                                            */
#define SWE3SWECLASSIFICATIONDATA   DLOG_PROCESSCLASS_SWFL
#if (DLOG_SWE_DEV_INFO_LENGTH > 0u)
   #define SWE3SWEDEVINFO           (uint8)4u,'S','W','F','L'
#endif


#define DLOG_HWE_TABLE                      \
    DLOG_HWE1_TABLE_ENTRY
#define DLOG_HWE_TABLE_INDICES 0, 1

/** total number of HWE Sgbm Id(s)                                            */
#define DLOG_TOTALNUMBEROFHWESGBMIDS    1u
/** max number of HWE Sgbm Id(s) per config set                               */
#define DLOG_MAXNUMBEROFHWESGBMIDS      1u
/** number of HWE config sets                                                 */
#define DLOG_NUMBEROFHWECONFIGSETS      1u
/** number of bootloader SWEs                                                 */
#define DLOG_NUMBEROFBOOTSWESGBMIDS     1u
/** number of application SWEs                                                */
#define DLOG_NUMBEROFAPPLSWESGBMIDS     3u
/** number of bootloader and application SWEs                                 */
#define DLOG_NUMBEROFALLSWESGBMIDS      (DLOG_NUMBEROFBOOTSWESGBMIDS +   \
                                         DLOG_NUMBEROFAPPLSWESGBMIDS)

/** \deprecated use DLOG_NUMBEROFALLSWESGBMIDS instead */
#define DLOG_NUMBEROFALLPHYSSWESGBMIDS  DLOG_NUMBEROFALLSWESGBMIDS

/* ----------------------------------------------------------------------- */
/*                     Memory Segmentation Table                           */
/* ----------------------------------------------------------------------- */

   #define DLOG_MEMSEGTABLE_NUM_SEGMENTS   70
   #define DLOG_MEMSEGTABLE_NUM_ENTRIES    2

   #define DLOG_MEMSEGTABLE_START_ADDRESSES                                    \
      {                                                                        \
          0x00000000uL,       \
          0x00010000uL       \
      }

   #define DLOG_MEMSEGTABLE_SIZES                                              \
      {                                                                        \
          0x00002000uL,       \
          0x00008000uL       \
      }

   #define DLOG_MEMSEGTABLE_NUMBERS_OF_SEGMENTS                                \
      {                                                                        \
          8u,     \
          62u     \
      }


/* ----------------------------------------------------------------------- */
/*                     SWE configuration                                   */
/* ----------------------------------------------------------------------- */
   #define SWE_SEGMENT_NUMBER_APPL                                             \
      SWE1_SEGMENT_NUMBER_APPL,                                                \
      SWE2_SEGMENT_NUMBER_APPL,                                                \
      SWE3_SEGMENT_NUMBER_APPL

   #define SWE_SEGMENT_INDEX_APPL                                              \
      SWE1_SEGMENT_INDEX_APPL,                                                 \
      SWE2_SEGMENT_INDEX_APPL,                                                 \
      SWE3_SEGMENT_INDEX_APPL
   /* *************************  boot  ************************************** */

   /** Defines the total number of memory areas dedicated for the bootloader  */
   #define FLASH_SEGMENT_NUMBER_BOOT    0u


   /* ************************  appl  *************************************** */

   /** calculates the number of memory segments of all application SWEs       */
   #define FLASH_SEGMENT_NUMBER_APPL (            \
           (SWE1_SEGMENT_NUMBER_APPL) +                                           \
           (SWE2_SEGMENT_NUMBER_APPL) +                                           \
           (SWE3_SEGMENT_NUMBER_APPL)                                          \
   )

   /** calculates the number of memory segments of all SWEs                   */
   #define FLASH_SEGMENT_NUMBER_ALL  (FLASH_SEGMENT_NUMBER_BOOT +              \
                                      FLASH_SEGMENT_NUMBER_APPL)


/**
 * Maximum number of supported SWEs by the bootmanager (reserved)
 */
#define DLOG_MAX_NUMBER_OF_SWES                16u

/**
 * Number of Bytes to skip after processing one byte during CRC calculation.
 * Set this value to 0 to include all bytes in CRC calculation. A value of 255
 * processes every 256'th byte.
 */
#define DLOG_CRC_CALC_BLOCK_SKIP_SIZE          255u

/**
 * Number of blocks (bytes) that are checked in one Crc_CalculateCRC32 call
 */
#define DLOG_CRC_CALC_BLOCK_LENGTH             0x01u

#define DLOG_SWE_ID_OF_BLU_SWE                 1u
#define DLOG_DIRECT_BLU_SWE_TABLE              Dlog_Swe1Table
#define DLOG_DIRECT_BLU_SWE_FLASHSTATUS        Dlog_Swe1FlashStatus


/**
 * Defines whether the job RDBI SwfkDeleteSupported is available
 */
#define DLOG_SWFK_DELSUP_AVAILABLE             STD_OFF
#define DLOG_CHECK_FOR_OPTIONAL_SWFK           STD_OFF


#endif /* DLOG_CFG_COMMON_H */


/*** End of file **************************************************************/

