/**
 * \file
 *
 * \brief       Coding
 *
 * \project     BMW Platform Software
 *
 * \copyright   BMW AG 2016 - 2017
 *
 * \version     5.2.1
 *
 */

#ifndef CODING_H
#define CODING_H

/*------------------------------------------------------------------------------
                      Include Section
-------------------------------------------------------------------------------*/

#include "Coding_Cfg.h"              /* CODING_DATA_SIZE */
#include "BUtil/GenericUDSTypes.h"   /* BMW Generic UDS Types */


/*------------------------------------------------------------------------------
                      Macros
------------------------------------------------------------------------------*/
/**
 *  Check version of the module
 */
#if (!Coding_CHECK_VERSION(5, 2, 1))
#error "Version of Coding.h does not match the version of the module!"
#endif

/**
 * \brief Size of the vehicle identification number information.
 */
#define CODING_VIN_SIZE                ((uint8)7u) /* in bytes */

/**
 * \brief Definition of the CAF-ID size in bytes
 *
 * \lhref COD_092
 *
 */
#define CODING_CAFID_SIZE              ((uint8)8u) /* in bytes */


/*------------------------------------------------------------------------------
                      Data Types
-------------------------------------------------------------------------------*/

/* Return Code Type */
typedef enum {
  CODING_RC_OK = 0U,
  CODING_RC_E_NOT_OK = 1U
} Coding_ReturnType;

/* Net Coding Data State Type */
/** \lhref COD_121 */
typedef enum {
  DATA_ST_UNDEFINED,
  DATA_ST_DEFAULT,
  DATA_ST_UNQUALIFIED,
  DATA_ST_QUALIFIED,
  DATA_ST_INPROGRESS
} Coding_NCDStateType;

typedef enum {
  CODING_ST_STOP,         /* Stop state */
  CODING_ST_INIT,         /* Initializing state, i.e. load and check coding data. When initialized, Coding switches to CODING_ST_RUN_IDLE */
  CODING_ST_RUN_IDLE,     /* Run idle state */
  CODING_ST_RUN_DIAG,     /* Run diag state, i.e. read NCD, write NCD, check NCD or read CPS. To go into details see 'Coding_State.diagState' */
  CODING_ST_RUN_RESTORE   /* Restore state, i.e. when leaving coding session due to timeout or request 'switch to default session' */
} Coding_RunStateType;

/* Coding Diag State Type */
typedef enum {
  DIAG_ST_IDLE,              /* Idle state                               */
  DIAG_ST_RC_READ_NCD,       /* RoutineControl, read NCD                 */
  DIAG_ST_RC_WRITE_NCD,      /* RoutineControl, write NCD                */
  DIAG_ST_RC_CHECK_NCD,      /* RoutineControl, check NCD                */
  DIAG_ST_RDBI_CPS,          /* ReadDataByIdentifier, read CPS           */
  DIAG_ST_RDBI_PROTOCOLDATA  /* ReadDataByIdentifier, read protocol data */
} Coding_DiagStateType;

/* Coding Result Type */
typedef enum {
  CODING_CODINGPASSED = 0U,
  CODING_WRONGCPS = 1U,
  CODING_SIGERROR = 2U,
  CODING_INVALIDDATA = 3U
} Coding_ResultType;

/* Coding State Type */
typedef struct {
  Coding_RunStateType runState;
  Coding_NCDStateType ncdState;
  Coding_DiagStateType diagState;
  boolean waitForVin;
  boolean checkCPSPending;
  boolean shutdownPending;
} Coding_StateType;

/* Coding Vin Type */
typedef uint8 Coding_VinType[CODING_VIN_SIZE];

/* Coding Data Type */
typedef uint8 Coding_DataType[CODING_DATA_SIZE];

/*------------------------------------------------------------------------------
                      Global Variables
-------------------------------------------------------------------------------*/

/*------------------------------------------------------------------------------
                      Global Constants
-------------------------------------------------------------------------------*/

/*------------------------------------------------------------------------------
                      Global Function Declarations
-------------------------------------------------------------------------------*/

#ifdef __cplusplus
extern "C" {
#endif

#define Coding_START_SEC_CODE
#include "Coding_MemMap.h" /* PRQA S 5087 */

/* Vin Adapter -> Coding */
extern void Coding_VinReceivedCallback(const uint8 Coding_BusVin[CODING_VIN_SIZE]);

/* Uds Adapter -> Coding */
extern UDS_ReturnType Coding_RoutineControlreadNCD_Start(
    const uint8* inSignal,
    uint8* outSignal,
    uint16* dataLength,
    UDS_ErrorCodeType* errorCode);

/* Uds Adapter -> Coding */
extern UDS_ReturnType Coding_RoutineControlwriteNCD_Start(
    const uint8* inSignal,
    uint16 dataLength,
    UDS_ErrorCodeType* errorCode);

/* Uds Adapter -> Coding */
extern UDS_ReturnType Coding_RoutineControlcheckNCD_Start(
    const uint8* cps,
    uint16 dataLength,
    Coding_ResultType* code,
    UDS_ErrorCodeType* errorCode);

/* Uds Adapter -> Coding */
extern UDS_ReturnType Coding_ReadCPS(uint8* cps, UDS_ErrorCodeType* errorCode);

/* Uds Adapter -> Coding */
extern UDS_ReturnType Coding_ReadProtocolData(uint8* protocolData, UDS_ErrorCodeType* errorCode);

/* Uds Adapter -> Coding */
extern UDS_ReturnType Coding_DiagRequest_Indication(
    uint8 serviceId,
    const uint8* requestData,
    uint16 dataLength,
    uint16 sourceAddress,
    UDS_ErrorCodeType* errorCode);

/* Dlog Adapter -> Coding */
extern void Coding_GetCafIds(uint8* cafIds, uint16* numberOfCafIds);

/* Uds Adapter -> Coding */
extern void Coding_NotifySessionChange(void);

/* Function -> Coding */
extern Coding_ReturnType Coding_GetAccessPermission(void);

/* Run Time System -> Coding */
extern void Coding_Init(void);

extern void Coding_Run(void);

extern void Coding_Shutdown(void);

#define Coding_STOP_SEC_CODE
#include "Coding_MemMap.h" /* PRQA S 5087 */

#ifdef __cplusplus
}
#endif

#endif /* CODING_H */
