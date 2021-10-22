/**
*  \file
*
*  \brief       BMW SWC StdDiag
*
*  This file is the Adt types header file of the classic adapter part of the module StdDiag
*  for usage in the BMW AUTOSAR Core.
*
*  \project     BMW Platform Software
*
*  \copyright   BMW AG 2017
*
*  \version     5.4.0
*
*  \remarks     The StdDiag module is responsible for BMW specific session
*               handling and handles a number of BMW specific diagnostic requests.
*
*/

#ifndef STDDIAG_ADTTYPES_H
#define STDDIAG_ADTTYPES_H

/*------------------------------------------------------------------------------
                      Include Section
-------------------------------------------------------------------------------*/
#include "StdDiagClassic_Version.h"
#include "StdDiagClassic_Cfg.h"
#include "Rte_StdDiag.h"


/*------------------------------------------------------------------------------
                      Macros
-------------------------------------------------------------------------------*/

/* check version of the module */
#if (!StdDiagClassic_CHECK_VERSION(5,4,0))
   #error "Version of StdDiag_AdtTypes.h does not match the version of the module!"
#endif

#if( STDDIAG_ADT_SUPPORT == STD_ON )
/*------------------------------------------------------------------------------
                      Type Definitions
------------------------------------------------------------------------------*/

typedef uint8 StdDiag_ControlIdType[11];

typedef struct {
  uint16 routineId;
  uint16 subRoutineId;
  uint8 controlIdLength;
  StdDiag_ControlIdType controlId;
} StdDiag_MemObjIdType;

/**
 * \brief type definition of the function pointer to rte call for up/download pre/postprocessing
 */

typedef Std_ReturnType (* StdDiag_FuncPtrRteCallPrePostProcessingType)(const uint8 * parameter, uint16 parameterSize, Dcm_NegativeResponseCodeType *errorCode);
typedef Std_ReturnType (* StdDiag_FuncPtrRteCallCancelType)(void);
typedef Std_ReturnType (* StdDiag_FuncPtrRteCallUploadType)(uint8 blockSequenceCounter, uint8 *data, uint32 length, Dcm_NegativeResponseCodeType *errorCode);
typedef Std_ReturnType (* StdDiag_FuncPtrRteCallDownloadType)(uint8 blockSequenceCounter, const uint8 *data, uint32 length, Dcm_NegativeResponseCodeType *errorCode);
typedef Std_ReturnType (* StdDiag_FuncPtrRteCallRequestUpDownloadType)(uint8 dataFormatIdentifier, uint32 size, uint32 *maxBlockLength, Dcm_NegativeResponseCodeType *errorCode);
typedef Std_ReturnType (* StdDiag_FuncPtrRteCallRequestExitType)(void);


typedef struct {
  StdDiag_FuncPtrRteCallCancelType            fctPtrCancelOperation;
  StdDiag_FuncPtrRteCallPrePostProcessingType fctPtrUploadPreprocess;
  StdDiag_FuncPtrRteCallPrePostProcessingType fctPtrUploadPostprocess;
  StdDiag_FuncPtrRteCallPrePostProcessingType fctPtrDownloadPreprocess;
  StdDiag_FuncPtrRteCallPrePostProcessingType fctPtrDownloadPostprocess;
  StdDiag_FuncPtrRteCallUploadType            fctPtrUpload;
  StdDiag_FuncPtrRteCallDownloadType          fctPtrDownload;
  StdDiag_FuncPtrRteCallRequestUpDownloadType fctPtrRequestUpload;
  StdDiag_FuncPtrRteCallRequestUpDownloadType fctPtrRequestDownload;
  StdDiag_FuncPtrRteCallRequestExitType       fctPtrRequestUploadExit;
  StdDiag_FuncPtrRteCallRequestExitType       fctPtrRequestDownloadExit;
} StdDiag_AdtFctPtrListType;


/*------------------------------------------------------------------------------
                      Global Function Declarations
-------------------------------------------------------------------------------*/

/* PRQA S 5087 2 */
#define StdDiag_START_SEC_CODE
#include "StdDiag_MemMap.h"

extern const StdDiag_MemObjIdType StdDiag_MemoryObjectIdArray[STDDIAG_NUMBER_MEMORY_OBJECT_IDENTIFIER];

extern const StdDiag_AdtFctPtrListType StdDiag_AdtFctPtrArray[STDDIAG_NUMBER_MEMORY_OBJECT_IDENTIFIER];

/* PRQA S 5087 2 */
#define StdDiag_STOP_SEC_CODE
#include "StdDiag_MemMap.h"

#endif /* STDDIAG_ADT_SUPPORT */

#endif /* STDDIAG_ADTTYPES_H */
