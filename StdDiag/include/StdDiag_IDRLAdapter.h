/**
*  \file
*
*  \brief       BMW SWC StdDiag
*
*  This file is the IDRL header file of the classic adapter part of the module StdDiag
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

#ifndef STDDIAG_IDRLADAPTER_H
#define STDDIAG_IDRLADAPTER_H

/*------------------------------------------------------------------------------
                      Include Section
-------------------------------------------------------------------------------*/
#include "StdDiagClassic_Cfg.h"
#include "StdDiag_Cfg.h"
#include "Rte_StdDiag.h"


/*------------------------------------------------------------------------------
                      Data Types
-------------------------------------------------------------------------------*/

#if (STDDIAG_IDRL_SUPPORT == STD_ON)
#if (STDDIAG_INDIV_DID_NUMBER > 0)
/**
 * \brief type definition of the function pointer to rte call for reading the individual data
 */
typedef Std_ReturnType (*StdDiag_FuncPtrRteCallReadIndivDataType)(StdDiag_IDRLOpStatusType OpStatus, uint16 DataLength);

/**
 * \brief type definition of the function pointer to rte result for reading the individual data
 */
typedef Std_ReturnType (*StdDiag_FuncPtrRteResultReadIndivDataType)(uint16 *DataLength, uint8 *Data);

/**
 * \brief struct definition including both function pointers RteCall and RteResult for reading individual data
 */
typedef struct {
  uint16 dataIdentifier;
  StdDiag_FuncPtrRteCallReadIndivDataType rteCallFuncPtr;
  StdDiag_FuncPtrRteResultReadIndivDataType rteResultFuncPtr;
} StdDiag_ReadIndivDataType;

/**
 * \brief type definition of the function pointer to rte call for writing the individual data
 */
typedef Std_ReturnType (*StdDiag_FuncPtrRteCallWriteIndivDataType)(StdDiag_IDRLOpStatusType OpStatus, uint16 DataLength, const uint8 *Data);

/**
 * \brief type definition of the function pointer to rte result for writing the individual data
 */
typedef Std_ReturnType (*StdDiag_FuncPtrRteResultWriteIndivDataType)(void);

/**
 * \brief struct definition including both function pointers RteCall and RteResult for writing individual data
 */
typedef struct {
  uint16 dataIdentifier;
  StdDiag_FuncPtrRteCallWriteIndivDataType rteCallFuncPtr;
  StdDiag_FuncPtrRteResultWriteIndivDataType rteResultFuncPtr;
} StdDiag_WriteIndivDataType;
#endif /* STDDIAG_INDIV_DID_NUMBER > 0 */

#if (STDDIAG_IDRL_CLIENT_NUMBER > 0)
/**
 * \brief type definition of the function pointer to rte call for resetting the individual data
 */
typedef Std_ReturnType (*StdDiag_FuncPtrRteCallResetIndivDataType)(StdDiag_IDRLOpStatusType OpStatus);

/**
 * \brief type definition of the function pointer to rte result for resetting the individual data
 */
typedef Std_ReturnType (*StdDiag_FuncPtrRteResultResetIndivDataType)(void);

/**
 * \brief struct definition including both function pointers RteCall and RteResult for resetting individual data
 */
typedef struct {
  StdDiag_FuncPtrRteCallResetIndivDataType rteCallFuncPtr;
  StdDiag_FuncPtrRteResultResetIndivDataType rteResultFuncPtr;
} StdDiag_ResetIndivDataType;
#endif /* STDDIAG_IDRL_CLIENT_NUMBER > 0 */

/*------------------------------------------------------------------------------
                      Extern Declarations
-------------------------------------------------------------------------------*/
#define StdDiag_START_SEC_CONST_UNSPECIFIED
#include "StdDiag_MemMap.h"

/* the extern const arrays that are defined in StdDiag_Cfg.c */
#if (STDDIAG_INDIV_DID_NUMBER > 0)
extern const StdDiag_ReadIndivDataType StdDiag_ReadIndivDataAccess[STDDIAG_INDIV_DID_NUMBER];
extern const StdDiag_WriteIndivDataType StdDiag_WriteIndivDataAccess[STDDIAG_INDIV_DID_NUMBER];
#endif /* STDDIAG_INDIV_DID_NUMBER > 0 */

#if (STDDIAG_IDRL_CLIENT_NUMBER > 0)
extern const StdDiag_ResetIndivDataType StdDiag_ResetIndivDataAccess[STDDIAG_IDRL_CLIENT_NUMBER];
#endif /* STDDIAG_IDRL_CLIENT_NUMBER > 0 */

#define StdDiag_STOP_SEC_CONST_UNSPECIFIED
#include "StdDiag_MemMap.h"

#endif /* (STDDIAG_IDRL_SUPPORT == STD_ON) */

#endif /* STDDIAG_IDRLADAPTER_H */
