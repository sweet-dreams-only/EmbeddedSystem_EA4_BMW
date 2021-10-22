/**
 * \file
 *
 * \brief       Dlog Data.
 *
 * \project     BMW Platform Software
 *
 * \copyright   BMW AG 2015 - 2016
 *
 * \version     5.1.1
 *
 */
#ifndef BPS_DLOG_DATA_H_H
#define BPS_DLOG_DATA_H_H

/*------------------------------------------------------------------------------
                      Include Section
-------------------------------------------------------------------------------*/

#include "Dlog_Cfg.h"
#include "BUtil/PlatformTypes.h"


/*------------------------------------------------------------------------------
                      Macros
-------------------------------------------------------------------------------*/

/* check version of the module */
#if (!Dlog_CHECK_VERSION(5,1,1))
#error "Version of Dlog_Data.h does not match the version of the module!"
#endif


#define DLOG_FINGERPRINTLENGTH           4u /**< use short fingerprint only */
#define DLOG_SGBM_ID_LENGTH              8u
#define DLOG_ECUSERIALNUMBERLENGTH      10u
#define DLOG_ECUMANUFACTURINGDATELENGTH  3u
#define DLOG_PROG_ID_LENGTH              8u
#define DLOG_ECU_UID_LENGTH             16u

/**
 * SWE group defines
 */
#define DLOG_SWEGROUP_ALLOBLIGATORY 0u
#define DLOG_SWEGROUP_ONEOBLIGATORY 1u
#define DLOG_SWEGROUP_OPTIONAL      2u


/*------------------------------------------------------------------------------
                      Data Types
-------------------------------------------------------------------------------*/
/**
 * This enum type contains the dependencies check possible values
 *
 * \lhref FL853
 *
 */
typedef enum
{
  DLOG_PROG_DEP_UNCHECKED_APPL    = 0x00u, /**< Application not checked */
  DLOG_PROG_DEP_CONSISTENT_APPL   = 0x01u, /**< Application consistent */
  DLOG_PROG_DEP_INVALID           = 0x02u, /**< SWE invalid */
  DLOG_PROG_DEP_WRONG_APPL        = 0x03u, /**< Application wrong */
  DLOG_PROG_DEP_INCONSISTENT_APPL = 0x04u, /**< Application not consistent */
  DLOG_PROG_DEP_WARNING_APPL      = 0x05u,
  DLOG_PROG_DEP_INCONSISTENT_SLAVE= 0x06u, /**< Slave not consistent */
  DLOG_PROG_DEP_FLASH_ERASED      = 0xffu
} Dlog_SweProgDepStateType;

typedef enum
{
  DLOG_SWE_STATE_INVALID    = 0x00u,
  DLOG_SWE_STATE_VALID_SWFL = 0x01u,
  DLOG_SWE_STATE_VALID_BTLD = 0x02u,
  DLOG_SWE_STATE_UNCHECKED  = 0x03u
} Dlog_SweValidStateType;


typedef struct {
  uint8 sgmbId[DLOG_SGBM_ID_LENGTH];
  const uint8* developmentInfo;
  Dlog_SweValidStateType validState;
  /** Index into SweGroupTable */
  uint8 group;
} Dlog_SweInfoType;

/**
 * Contains the hardware SGBM-ID and Development info field.
 *
 * \swsid SWS_Dlog_0141
 *
 */
typedef struct {
  uint8 sgmbId[DLOG_SGBM_ID_LENGTH];
  const uint8* developmentInfo;
} Dlog_HweInfoType;

typedef struct {
  /** ECUSerialNumber                                                        */
  uint8 ECUSerialNumber[DLOG_ECUSERIALNUMBERLENGTH];
  /** ECUManufacturingDate                                                   */
  uint8 ECUManufacturingDate[DLOG_ECUMANUFACTURINGDATELENGTH];
  /** HWModificationIndex */
  uint8 HWModificationIndex[2];
  /** ECU UID */
  uint8 ECUUID[DLOG_ECU_UID_LENGTH];
} Dlog_HWDataType;

typedef struct {
  uint8 numberOfSwe;
  Dlog_SweInfoType* sweInfo;
  Dlog_SweProgDepStateType sweProgDepState;

  const uint8* sweGroupInfo;

  uint8 numberOfHwe;
  const Dlog_HweInfoType* hweInfo;

  const Dlog_HWDataType* hwData;

  uint8 fingerprint[DLOG_FINGERPRINTLENGTH];
  uint8 progId[DLOG_PROG_ID_LENGTH];
} Dlog_DataType;


/*------------------------------------------------------------------------------
                      Global Variables
-------------------------------------------------------------------------------*/

#ifdef __cplusplus
extern "C" {
#endif

#define Dlog_START_SEC_VAR_SHARED_SWESTATUS
#include "Dlog_MemMap.h"  /* PRQA S 5087 */

extern Dlog_DataType Dlog_Data;

#define Dlog_STOP_SEC_VAR_SHARED_SWESTATUS
#include "Dlog_MemMap.h"  /* PRQA S 5087 */


/*------------------------------------------------------------------------------
                      Global Function Declarations
-------------------------------------------------------------------------------*/

/**
 * Initializes the Dlog module.
 *
 * \param data pointer to the already initialized data structure
 */
extern void Dlog_Init(Dlog_DataType* data);

#ifdef __cplusplus
}
#endif

#endif /* BPS_DLOG_DATA_H_H */
