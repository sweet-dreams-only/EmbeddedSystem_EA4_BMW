/* ********************************************************************************************************************
 *  COPYRIGHT
 *  -------------------------------------------------------------------------------------------------------------------
 *  \verbatim
 *  Copyright (c) 2017 by Vctr Informatik GmbH.                                                  All rights reserved.
 *
 *                This software is copyright protected and proprietary to Vctr Informatik GmbH.
 *                Vctr Informatik GmbH grants to you only those rights as set out in the license conditions.
 *                All other rights remain with Vctr Informatik GmbH.
 *  \endverbatim
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 */
/*!
 *  \ingroup    Dem_Master
 *  \defgroup   Dem_DtrIF Diagnostic Test Result
 *  \{
 *  \file       Dem_DtrIF_Interface.h
 *  \brief      Diagnostic Event Manager (Dem) Interface declaration file
 *********************************************************************************************************************/

/* ********************************************************************************************************************
 *  AUTHOR IDENTITY
 *  -------------------------------------------------------------------------------------------------------------------
 *  Name                          Initials      Company
 *  -------------------------------------------------------------------------------------------------------------------
 *  Savas Ates                    vissat        Vctr Informatik GmbH
 *  Anna Bosch                    visanh        Vctr Informatik GmbH
 *  Stefan Huebner                vishrs        Vctr Informatik GmbH
 *  Thomas Dedler                 visdth        Vctr Informatik GmbH
 *  Alexander Ditte               visade        Vctr Informatik GmbH
 *  Matthias Heil                 vismhe        Vctr Informatik GmbH
 *  Erik Jeglorz                  visejz        Vctr Informatik GmbH
 *  Friederike Schulze            visfrs        Vctr Informatik GmbH
 *  Aswin Vijayamohanan Nair      visavi        Vctr Informatik GmbH
 *  Fabian Wild                   viszfa        Vctr Informatik GmbH
 *  -------------------------------------------------------------------------------------------------------------------
 *  REVISION HISTORY
 *  -------------------------------------------------------------------------------------------------------------------
 *  Version   Date        Author  Change Id     Description
 *  -------------------------------------------------------------------------------------------------------------------
 *  REFER TO DEM.H
 *********************************************************************************************************************/

#if !defined (DEM_DTRIF_INTERFACE_H)
#define DEM_DTRIF_INTERFACE_H


/* ********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/

                                                        /* Dem module header */
/* ------------------------------------------------------------------------- */
#include "Dem_DtrIF_Types.h"
/* ------------------------------------------------------------------------- */


/* *********************************************************************************************************************
 *  SUBCOMPONENT API FUNCTION DECLARATIONS
 **********************************************************************************************************************/
#define DEM_START_SEC_CODE
#include "MemMap.h"                                                                                                              /* PRQA S 5087 */ /* MD_MSR_19.1 */
/*!
 * \defgroup Dem_DtrIF_Public Public Methods
 * \{
 */

/* ****************************************************************************
 * Dem_DtrIF_Init
 *****************************************************************************/
/*!
 * \brief         Initializes Dtr functionality
 *
 * \details       This function controls initialization of the Dtr
 *                subcomponent.
 *
 * \pre           May only be called during initialization
 *
 * \context       TASK
 * \synchronous   TRUE
 * \reentrant     FALSE
 *****************************************************************************/
DEM_LOCAL_INLINE FUNC(void, DEM_CODE)
Dem_DtrIF_Init(
  void
  );

/* ****************************************************************************
 * Dem_DtrIF_PreInit
 *****************************************************************************/
/*!
 * \brief         Pre-initializes DTR data
 *
 * \details       This function performs basic initialization to allow later
 *                full initialization.
 *
 * \pre           May only be called during pre-initialization
 *
 * \context       TASK
 * \synchronous   TRUE
 * \reentrant     FALSE
 *****************************************************************************/
DEM_LOCAL_INLINE FUNC(void, DEM_CODE)
Dem_DtrIF_PreInit(
  void
  );

/* ****************************************************************************
 *  Dem_DtrIF_MainFunction
 *****************************************************************************/
/*!
 * \brief         Process Dtr functionality
 *
 * \details       This function performs asynchronous tasks related to DTR
 *                management.
 *
 * \pre           -
 *
 * \context       TASK
 * \synchronous   TRUE
 * \reentrant     FALSE
 *****************************************************************************/
DEM_LOCAL_INLINE FUNC(void, DEM_CODE)
Dem_DtrIF_MainFunction(
  void
  );

/* ****************************************************************************
 * Dem_DtrIF_Shutdown
 *****************************************************************************/
/*!
 * \brief         Finalize DTR data
 *
 * \details       This function finalizese DTR data for writing into NV ram
 *
 * \pre           May only be called during shutdown
 *
 * \context       TASK
 * \synchronous   TRUE
 * \reentrant     FALSE
 *****************************************************************************/
DEM_LOCAL_INLINE FUNC(void, DEM_CODE)
Dem_DtrIF_Shutdown(
  void
  );

/* ****************************************************************************
 * Dem_DtrIF_ClearDtrOfEvent
 *****************************************************************************/
/*!
 * \brief         Resets Dtr Values of all Dtrs referencing a specific event
 *
 * \details       Resets Dtr Values of all Dtrs referencing a specific event
 *
 * \param[in]     EventId
 *                Unique handle of the Event.
 *                When passing DEM_EVENT_INVALID, this resets all DTRs that do
 *                not reference an event
 *
 * \pre           -
 *
 * \context       TASK|ISR2
 * \synchronous   TRUE
 * \reentrant     TRUE
 *****************************************************************************/
DEM_LOCAL_INLINE FUNC(void, DEM_CODE)
Dem_DtrIF_ClearDtrOfEvent(
  CONST(Dem_EventIdType, AUTOMATIC)  EventId
  );

/* ****************************************************************************
 * Dem_DtrIF_SetDtr
 *****************************************************************************/
/*!
 * \brief         Reports a DTR result with lower and upper limit
 *
 * \details       Reports a DTR result with lower and upper limit.
 *                Depending on the reported control value and the configured
 *                DTR attributes the DTR values are either ignored, processed
 *                or reset.
 *
 * \param[in]     DTRId
 *                Dtr Index
 * \param[in]     TestResult
 *                Test Result
 * \param[in]     LowerLimit
 *                Lower Limit
 * \param[in]     UpperLimit
 *                Upper Limit
 * \param[in]     Ctrlval
 *                Dtr Control Value
 *
 * \return        E_OK
 *                Report of DTR result was succesful
 * \return        E_NOT_OK
 *                Report of DTR result failed
 *
 * \pre           -
 * \config        -
 *
 * \context       TASK|ISR2
 * \synchronous   TRUE
 * \reentrant     TRUE
 *****************************************************************************/
DEM_LOCAL_INLINE FUNC(Std_ReturnType, DEM_CODE)
Dem_DtrIF_SetDtr(
  CONST(uint16, AUTOMATIC) DTRId,
  CONST(sint32, AUTOMATIC) TestResult,
  CONST(sint32, AUTOMATIC) LowerLimit,
  CONST(sint32, AUTOMATIC) UpperLimit,
  CONST(Dem_DTRControlType, AUTOMATIC) Ctrlval
  );

/* ****************************************************************************
 * Dem_DtrIF_UpdateMidVisibility
 *****************************************************************************/
/*!
 * \brief         Requests the update of the available OBD MIDs
 *
 * \details       As the visibility status of Dtrs can change during runtime
 *                and therefore MIDs might also not be visible anymore
 *                the application can trigger the update of the available
 *                OBD MIDs
 *
 * \pre           -
 *
 * \context       TASK|ISR2
 * \synchronous   TRUE
 * \reentrant     FALSE
 *****************************************************************************/
DEM_LOCAL_INLINE FUNC(void, DEM_CODE)
Dem_DtrIF_UpdateMidVisibility(
  void
  );

/* ****************************************************************************
 * Dem_DtrIF_GetSupportedMidValue
 *****************************************************************************/
/*!
 * \brief         Get the value of a SupportedMid
 *
 * \details       Get the value of a SupportedMid
 *
 * \param[in]     Mid
 *                MonitorId to read. Must be a SupportedMid.
 * \param[out]    MidValue
 *                Buffer to receive the Mid value.
 *
 * \return        TRUE
 *                MonitorId is a SupportedMid. The value is returned.
 * \return        TRUE
 *                MonitorId is not SupportedMid. The value is not returned.
 *
 * \pre           -
 *
 * \context       TASK|ISR2
 * \synchronous   TRUE
 * \reentrant     FALSE
 *****************************************************************************/
DEM_LOCAL_INLINE FUNC(boolean, DEM_CODE)
Dem_DtrIF_GetSupportedMidValue(
  CONST(uint8, AUTOMATIC)  Mid,
  CONSTP2VAR(uint32, AUTOMATIC, AUTOMATIC)  MidValue
  );

/* ****************************************************************************
 * Dem_DtrIF_GetTidCountOfMid
 *****************************************************************************/
/*!
 * \brief         Get the number of TIDs for a MID
 *
 * \details       Get the number of TIDs for a MID.
 *
 * \param[in]     Mid
 *                MonitorId
 * \param[out]    TidCount
 *                Number of Tid for the requested Mid
 *
 * \return        E_OK
 *                DTR data was successfully copied
 * \return        E_NOT_OK
 *                DTR data was not copied
 *
 * \pre           -
 *
 * \context       TASK|ISR2
 * \synchronous   TRUE
 * \reentrant     FALSE
 *****************************************************************************/
DEM_LOCAL_INLINE FUNC(Std_ReturnType, DEM_CODE)
Dem_DtrIF_GetTidCountOfMid(
  CONST(uint8, AUTOMATIC)  Mid,
  CONSTP2VAR(uint8, AUTOMATIC, DEM_DCM_DATA)  TidCount
  );

/* ****************************************************************************
 * Dem_DtrIF_GetDataAndTidOfMid
 *****************************************************************************/
/*!
 * \brief         Get the DTR data for a OBDMID / TID combination
 *
 * \details       Returns the stored DTR data for a OBDMID / TID combination
 *
 * \param[in]     Mid
 *                Mid number
 * \param[in]     TidIndex
 *                Zero based index of the requested Tid
 * \param[out]    Tid
 *                Tid number of the selected Tid
 * \param[out]    UaSid
 *                Unit and Scaling ID
 * \param[out]    TestResult
 *                Test result stored for the test
 * \param[out]    LowerLimit
 *                Lower Limit stored for the test
 * \param[out]    UpperLimit
 *                Upper Limit stored for the test
 *
 * \return        E_OK
 *                The data was successfully copied
 * \return        E_NOT_OK
 *                The requested data was not copied
 *
 * \pre           -
 *
 * \context       TASK|ISR2
 * \synchronous   TRUE
 * \reentrant     FALSE
 *****************************************************************************/
DEM_LOCAL_INLINE FUNC(Std_ReturnType, DEM_CODE)
Dem_DtrIF_GetDataAndTidOfMid(
  CONST(uint8, AUTOMATIC) Mid,
  CONST(uint8, AUTOMATIC) TidIndex,
  CONSTP2VAR(uint8, AUTOMATIC, DEM_DCM_DATA)  Tid,                                                                               /* PRQA S 3673 */ /* MD_DEM_16.7 */
  CONSTP2VAR(uint8, AUTOMATIC, DEM_DCM_DATA)  UaSid,                                                                             /* PRQA S 3673 */ /* MD_DEM_16.7 */
  CONSTP2VAR(uint16, AUTOMATIC, DEM_DCM_DATA) TestResult,                                                                        /* PRQA S 3673 */ /* MD_DEM_16.7 */
  CONSTP2VAR(uint16, AUTOMATIC, DEM_DCM_DATA) LowerLimit,                                                                        /* PRQA S 3673 */ /* MD_DEM_16.7 */
  CONSTP2VAR(uint16, AUTOMATIC, DEM_DCM_DATA) UpperLimit                                                                         /* PRQA S 3673 */ /* MD_DEM_16.7 */
  );

/*!
 * \}
 */

#define DEM_STOP_SEC_CODE
#include "MemMap.h"                                                                                                              /* PRQA S 5087 */ /* MD_MSR_19.1 */

#endif /* DEM_DTRIF_INTERFACE_H */

/*!
 * \}
 */


/* *********************************************************************************************************************
 *  END OF FILE: Dem_DtrIF_Interface.h
 **********************************************************************************************************************/
