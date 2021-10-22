/**
*  \file
*
*  \brief       BMW SWC StdDiag
*
*  This file is the Dcm header file of the classic adapter part of the module StdDiag
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

#ifndef STDDIAG_DCMTYPES_H
#define STDDIAG_DCMTYPES_H

/*------------------------------------------------------------------------------
                      Include Section
-------------------------------------------------------------------------------*/
#include "BUtil/PlatformTypes.h"
#include "StdDiagClassic_Version.h"
#include "Dcm_Types.h"

/*------------------------------------------------------------------------------
                      Macros
-------------------------------------------------------------------------------*/

/* check version of the module */
#if (!StdDiagClassic_CHECK_VERSION(5,4,0))
   #error "Version of StdDiag_Dcm.h does not match the version of the module!"
#endif

/*------------------------------------------------------------------------------
                      Extern Declarations (provided by Dcm_Cfg.c)
------------------------------------------------------------------------------*/
/**
 * \brief Callout Function for diagnostic service 0x34 Request Download
 */
extern Std_ReturnType StdDiag_RequestDownload(
    Dcm_OpStatusType OpStatus,
    Dcm_MsgContextType* pMsgContext,
    Dcm_NegativeResponseCodeType* ErrorCode
);

/**
 * \brief Callout Function for diagnostic service 0x35 Request Upload
 */
extern Std_ReturnType StdDiag_RequestUpload(
    Dcm_OpStatusType OpStatus,
    Dcm_MsgContextType* pMsgContext,
    Dcm_NegativeResponseCodeType* ErrorCode
);

/**
 * \brief Callout Function for diagnostic service 0x36 Transfer Data
 */
extern Std_ReturnType StdDiag_TransferData(
    Dcm_OpStatusType OpStatus,
    Dcm_MsgContextType* pMsgContext,
    Dcm_NegativeResponseCodeType* ErrorCode
);

/**
 * \brief Callout Function for diagnostic service 0x37 Request Transfer Exit
 */
extern Std_ReturnType StdDiag_RequestTransferExit(
    Dcm_OpStatusType OpStatus,
    Dcm_MsgContextType* pMsgContext,
    Dcm_NegativeResponseCodeType* ErrorCode
);

#endif /* STDDIAG_DCMTYPES_H */
