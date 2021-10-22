/**
 * \file
 *
 * \brief       Dlog SWE.
 *
 * \project     BMW Platform Software
 *
 * \copyright   BMW AG 2015 - 2016
 *
 * \version     5.1.1
 *
 */

#ifndef BPS_DLOG_SWEGEN_H
#define BPS_DLOG_SWEGEN_H

/*------------------------------------------------------------------------------
                      Include Section
-------------------------------------------------------------------------------*/

#include "Dlog_Data.h"

#include "BUtil/PlatformTypes.h"
#include "BUtil/GenericUDSTypes.h"

#include <stddef.h>

/*------------------------------------------------------------------------------
                      Macros
-------------------------------------------------------------------------------*/

/* check version of the module */
#if (!Dlog_CHECK_VERSION(5,1,1))
#error "Version of Dlog_SweGen.h does not match the version of the module!"
#endif


#ifdef __cplusplus
extern "C" {
#endif

/**
 * This enum type contains the process classes
 *
 * \swsid DLOG_0129
 *
 */
typedef enum
{
  DLOG_PROCESSCLASS_RES_00        = 0x00u, /**< Reserved for invalid SGBM-Identifier */
  DLOG_PROCESSCLASS_HWEL          = 0x01u, /**< Hardware e.g. ECU */
  /**
   * Hardware development, non relevant technical programming hardware development
   * e.g. radio frequency, fixing or mounting part
   */
  DLOG_PROCESSCLASS_HWAP          = 0x02u,
  DLOG_PROCESSCLASS_HWFR          = 0x03u, /**< Hardware color, relevant for the replacement order */
  /**
   * Coding data, parameterized software to configure the ECU in accordance with the vehicle order.
   */
  DLOG_PROCESSCLASS_CAFD          = 0x05u,
  /**
   * Bootloader software, which contains all the necessary Flashloader software for the ECU programming
   */
  DLOG_PROCESSCLASS_BTLD          = 0x06u,
  /**
   * Flashloader used to programm slave controllers on multi processor systems.
   */
  DLOG_PROCESSCLASS_FLSL          = 0x07u,
  /**
   * ECU memory image, Software for the ECU Flash memory with the Application, routines,
   * parameters, Data and characteristic
   */
  DLOG_PROCESSCLASS_SWFL          = 0x08u,
  DLOG_PROCESSCLASS_SWFF          = 0x09u, /**< Flash file software for Flash-File-System ECUs */
  DLOG_PROCESSCLASS_SWPF          = 0x0Au, /**< Verification software, special software for flash verification */
  DLOG_PROCESSCLASS_ONPS          = 0x0Bu, /**< Onboard Programming System */
  DLOG_PROCESSCLASS_IBAD          = 0x0Cu, /**< Data for integrated operating manual */
  DLOG_PROCESSCLASS_SWFK          = 0x0Du, /**< Optional software unit */
  DLOG_PROCESSCLASS_FAFP          = 0x0Fu, /**< Mapping table for mapping of the vehicle order to a vehicle profile */
  DLOG_PROCESSCLASS_FCFA          = 0x10u, /**< Activation code, dependend on the vehicle order */
  DLOG_PROCESSCLASS_TLRT          = 0x1Au, /**< Temporary erase routine, non persistent software */
  DLOG_PROCESSCLASS_TPRG          = 0x1Bu, /**< Temporary erase routine, non persistent software */
  DLOG_PROCESSCLASS_BLUP          = 0x1Cu, /**< Bootloader Updater */
  DLOG_PROCESSCLASS_ENTD          = 0xA0u, /**< Entertainment data */
  DLOG_PROCESSCLASS_NAVD          = 0xA1u, /**< Navigation data */
  DLOG_PROCESSCLASS_FCFN          = 0xA2u, /**< Activation code, dependend on the service */
  DLOG_PROCESSCLASS_RES_FF        = 0xFFu  /**< Reserved for invalid SGBM-identifier */
} Dlog_ProcessClassType;


UDS_ReturnType Dlog_RoutineControlReadDevelopmentInfoFieldStart(
    const uint8* requestData,
    size_t requestDataLength,
    uint8* responseData,
    size_t* responseDataLength,
    UDS_ErrorCodeType* errorCode);

void Dlog_UserReadDevelopmentInfoField_ResultOk(const uint8* developmentInfoField, size_t developmentInfoFieldLength);
void Dlog_UserReadDevelopmentInfoField_ResultError(UDS_ErrorCodeType errorCode);

Dlog_SweValidStateType Dlog_GetValidState(void);

boolean Dlog_GetSweIdBySgbmId(const uint8* SgbmId, uint8* SweId);


#ifdef __cplusplus
}
#endif

#endif /* BPS_DLOG_SWEGEN_H */
