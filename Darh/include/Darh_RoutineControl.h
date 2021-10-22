/**
*  \file
*
*  \brief       Darh Routine Control
*
*  Declarations of the Darh Routine Control job to stimulate the 2 dummy
*  tests DTCs from Darh: Application and Network.
*
*  \project     BMW Platform Software
*
*  \copyright   BMW AG 2015 - 2016
*
*  \version     5.1.0
*
*  \remarks     -
*
*/
#ifndef DARH_ROUTINECONTROL_H
#define DARH_ROUTINECONTROL_H

/*------------------------------------------------------------------------------
                      Include Section
------------------------------------------------------------------------------*/
#include "Darh_Version.h"
#include "BUtil/GenericUDSTypes.h"
#include "BUtil/PlatformTypes.h"

#ifdef __cplusplus
extern "C" {
#endif
/*------------------------------------------------------------------------------
                      Macros
------------------------------------------------------------------------------*/
/*
 * \brief  check version of the module
 */
#if (!Darh_CHECK_VERSION(5, 1, 0))
#error "Version of Darh_RoutineControl.h does not match the version of the module!"
#endif

/*------------------------------------------------------------------------------
                      Global Function Declarations
------------------------------------------------------------------------------*/
#define Darh_START_SEC_CODE
#include "Darh_MemMap.h"

/**
 * \brief Description of function Darh_StartRoutineTriggerDtc
 *
 * Function is called by Diagnostic Communication Manager in the context of an
 * RC (operation start) request. The interface is used to stimulate the 2 Dummy
 * DTCs from Darh.
 *
 * \param[in] DTCType Type of DTC/Event, that shall be triggered by this RC.
 *            0x00: ApplicationDTC
 *            0x01: NetworkDTC
 * \param[out] DTCTypeOut Copy of the input parameter DTCType
 * \param[out] DTCByte1 Byte 1 (MSB) of the DTC that has been triggered
 * \param[out] DTCByte2 Byte 2 of the DTC that has been triggered
 * \param[out] DTCByte3 Byte 3 (LSB) of the DTC that has been triggered
 * \param[out] ErrorCode ErrorCode according to the Dcm specification. Is only
 *             set in case of return value E_NOT_OK
 *
 * \return TRUE if success, FALSE if not. If FALSE the content of the out parameters
 *         is undefined.
 *
 */
extern boolean Darh_StartRoutineTriggerDtc(uint8 DTCType, uint8 *DTCTypeOut,
                                           uint8 *DTCByte1, uint8 *DTCByte2, uint8 *DTCByte3,
                                           UDS_ErrorCodeType *ErrorCode);

/**
 * \brief Start Routine to start and store the Diagnose Master state
 *
 * This routine starts the Diagnose Master and stores the new state in non volatile memory.
 *
 * \param[out] ErrorCode ErrorCode to be responses if the function returns FALSE
 *
 * \return TRUE if success, FALSE if something fails. If FALSE is returned the ErrorCode is set
 *          to the corresponding UDS Error Value.
 */
extern boolean Darh_StartRoutineDiagnoseMaster(UDS_ErrorCodeType* ErrorCode);

/**
 * \brief Stop Routine to stop and store the Diagnose Master state
 *
 * This routine stops the Diagnose Master and stores the new state in non volatile memory.
 *
 * \param[out] ErrorCode ErrorCode to be responses if the function returns FALSE
 *
 * \return TRUE if success, FALSE if something fails. If FALSE is returned the ErrorCode is set
 *          to the corresponding UDS Error Value.
 */
extern boolean Darh_StopRoutineDiagnoseMaster(UDS_ErrorCodeType* ErrorCode);

#define Darh_STOP_SEC_CODE
#include "Darh_MemMap.h"

#ifdef __cplusplus
}
#endif

#endif /* DARH_ROUTINECONTROL_H */
