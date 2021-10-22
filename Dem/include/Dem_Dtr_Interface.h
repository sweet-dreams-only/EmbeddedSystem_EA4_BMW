/* *********************************************************************************************************************
 *  COPYRIGHT
 *  --------------------------------------------------------------------------------------------------------------------
 *  \verbatim
 *  Copyright (c) 2017 by Vctr Informatik GmbH.                                                  All rights reserved.
 *
 *                This software is copyright protected and proprietary to Vctr Informatik GmbH.
 *                Vctr Informatik GmbH grants to you only those rights as set out in the license conditions.
 *                All other rights remain with Vctr Informatik GmbH.
 *  \endverbatim
 *  --------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  --------------------------------------------------------------------------------------------------------------------
 */
/*! \ingroup    Dem_DtrIF
 *  \defgroup   Dem_Dtr DTR Storage Handling
 *  \{
 *  \file       Dem_Dtr_Interface.h
 *  \brief      Diagnostic Event Manager (Dem) Interface declaration file
 *  \details    Diagnostic Event Manager (Dem) Interface declaration file
 *********************************************************************************************************************/

/* ********************************************************************************************************************
 *  AUTHOR IDENTITY
 *  --------------------------------------------------------------------------------------------------------------------
 *  Name                          Initials      Company
 *  --------------------------------------------------------------------------------------------------------------------
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
 *  --------------------------------------------------------------------------------------------------------------------
 *  REVISION HISTORY
 *  --------------------------------------------------------------------------------------------------------------------
 *  Version   Date        Author  Change Id     Description
 *  --------------------------------------------------------------------------------------------------------------------
 *  REFER TO DEM.H
 *********************************************************************************************************************/

#if !defined (DEM_DTR_INTERFACE_H)
#define DEM_DTR_INTERFACE_H


/* ********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/

                                                        /* Own module header */
/* ------------------------------------------------------------------------- */
#include "Dem_Dtr_Types.h"


#define DEM_START_SEC_CODE
#include "MemMap.h"                                                                                                            /* PRQA S 5087 */ /* MD_MSR_19.1 */

/* ********************************************************************************************************************
 *  SUBCOMPONENT API PRIVATE FUNCTION DECLARATIONS
 *********************************************************************************************************************/
/*!
 * \defgroup Dem_Dtr_Private Private Methods
 * \{
 */

/* ****************************************************************************
 * Dem_Dtr_RoundFloatToInt
 *****************************************************************************/
/*!
 * \brief         Round a floating number to the nearest integer
 *
 * \details       Round a floating number to the nearest integer
 *
 * \param[in]     Value
 *                Float32 value
 *
 * \return        Rounded uint16 value
 *
 * \pre           -
 * \config        -
 *
 * \context       TASK|ISR2
 * \synchronous   TRUE
 * \reentrant     TRUE
 *****************************************************************************/
DEM_LOCAL_INLINE FUNC(uint16, DEM_CODE)
Dem_Dtr_RoundFloatToInt(
  CONST(float32, AUTOMATIC)  Value
  );

/* ****************************************************************************
 * Dem_Dtr_GetUpdateKind
 *****************************************************************************/
/*!
 * \brief         Get the Update Kind for the Dtr
 *
 * \details       Get the Update Kind for the Dtr
 *
 * \param[in]     DtrId
 *                Unique handle of the Dtr.
 *                The DtrId must be in range [0..Dem_Dtr_GetGlobalDtrCount()-1[.
 *
 * \return        Update Kind for the Dtr.
 *
 * \pre           -
 *
 * \context       TASK|ISR2
 * \synchronous   TRUE
 * \reentrant     TRUE
 *****************************************************************************/
DEM_LOCAL_INLINE FUNC(uint8, DEM_CODE)
Dem_Dtr_GetUpdateKind(
  CONST(uint16, AUTOMATIC) DtrId
  );

/* ****************************************************************************
 * Dem_Dtr_GetDivisor
 *****************************************************************************/
/*!
 * \brief         Get the Divisor for the Dtr
 *
 * \details       Get the Divisor for the linear conversion of the Dtr data
 *
 * \param[in]     DtrId
 *                Unique handle of the Dtr.
 *                The DtrId must be in range [0..Dem_Dtr_GetGlobalDtrCount()-1[.
 *
 * \return        Divisor for the Dtr.
 *
 * \pre           -
 *
 * \context       TASK|ISR2
 * \synchronous   TRUE
 * \reentrant     TRUE
 *****************************************************************************/
DEM_LOCAL_INLINE FUNC(float32, DEM_CODE)
Dem_Dtr_GetDivisor(
  CONST(uint16, AUTOMATIC) DtrId
  );

/* ****************************************************************************
 * Dem_Dtr_GetLinearFactor
 *****************************************************************************/
/*!
 * \brief         Get the Linear Factor for the Dtr
 *
 * \details       Get the Linear Factor for the linear conversion of the Dtr data
 *
 * \param[in]     DtrId
 *                Unique handle of the Dtr.
 *                The DtrId must be in range [0..Dem_Dtr_GetGlobalDtrCount()-1[.
 *
 * \return        Linear Factor for the Dtr.
 *
 * \pre           -
 *
 * \context       TASK|ISR2
 * \synchronous   TRUE
 * \reentrant     TRUE
 *****************************************************************************/
DEM_LOCAL_INLINE FUNC(float32, DEM_CODE)
Dem_Dtr_GetLinearFactor(
  CONST(uint16, AUTOMATIC) DtrId
  );

/* ****************************************************************************
 * Dem_Dtr_GetOffset
 *****************************************************************************/
/*!
 * \brief         Get the Offset for the Dtr
 *
 * \details       Get the Offset for the linear conversion of the Dtr data
 *
 * \param[in]     DtrId
 *                Unique handle of the Dtr.
 *                The DtrId must be in range [0..Dem_Dtr_GetGlobalDtrCount()-1[.
 *
 * \return        Offset for the Dtr.
 *
 * \pre           -
 *
 * \context       TASK|ISR2
 * \synchronous   TRUE
 * \reentrant     TRUE
 *****************************************************************************/
DEM_LOCAL_INLINE FUNC(float32, DEM_CODE)
Dem_Dtr_GetOffset(
  CONST(uint16, AUTOMATIC) DtrId
  );

/* ****************************************************************************
 * Dem_Dtr_GetStatus
 *****************************************************************************/
/*!
 * \brief         Get current status of Dtr
 *
 * \details       Get current status of Dtr
 *
 * \param[in]     DtrId
 *                Unique handle of the Dtr.
 *                The DtrId must be in range [0..Dem_Dtr_GetGlobalDtrCount()-1[.
 *
 * \return        The current status of Dtr
 *
 * \pre           -
 *
 * \context       TASK|ISR2
 * \synchronous   TRUE
 * \reentrant     TRUE
 *****************************************************************************/
DEM_LOCAL_INLINE FUNC(uint8, DEM_CODE)
Dem_Dtr_GetStatus(
  CONST(uint16, AUTOMATIC) DtrId
  );

/* ****************************************************************************
 * Dem_Dtr_SetStatus
 *****************************************************************************/
/*!
 * \brief         Set current status of Dtr
 *
 * \details       Set current status of Dtr
 *
 * \param[in]     DtrId
 *                Unique handle of the Dtr.
 *                The DtrId must be in range [0..Dem_Dtr_GetGlobalDtrCount()-1[.
 * \param[in]     Status
 *                New status of Dtr
 *
 * \pre           -
 *
 * \context       TASK|ISR2
 * \synchronous   TRUE
 * \reentrant     TRUE
 *****************************************************************************/
DEM_LOCAL_INLINE FUNC(void, DEM_CODE)
Dem_Dtr_SetStatus(
  CONST(uint16, AUTOMATIC) DtrId,
  CONST(uint8, AUTOMATIC) Status
  );

/* ****************************************************************************
 * Dem_Dtr_TestWriteOnShutdown
 *****************************************************************************/
/*!
 * \brief         Read the current WriteOnShutdown
 *
 * \details       Read the current WriteOnShutdown
 *
 * \return        State of the bit
 *
 * \pre           -
 * \context       TASK|ISR2
 * \synchronous   TRUE
 * \reentrant     TRUE
 *****************************************************************************/
DEM_LOCAL_INLINE FUNC(boolean, DEM_CODE)
Dem_Dtr_TestWriteOnShutdown(
  void
  );

/* ****************************************************************************
 * Dem_Dtr_SetWriteOnShutdown
 *****************************************************************************/
/*!
 * \brief         Set the WriteOnShutdown state
 *
 * \details       Set the WriteOnShutdown state
 *
 * \pre           -
 * \context       TASK|ISR2
 * \synchronous   TRUE
 * \reentrant     TRUE
 *****************************************************************************/
DEM_LOCAL_INLINE FUNC(void, DEM_CODE)
Dem_Dtr_SetWriteOnShutdown(
  void
  );

/* ****************************************************************************
 * Dem_Dtr_ResetWriteOnShutdown
 *****************************************************************************/
/*!
 * \brief         Reset the WriteOnShutdown state
 *
 * \details       Reset the WriteOnShutdown state
 *
 * \pre           -
 * \context       TASK|ISR2
 * \synchronous   TRUE
 * \reentrant     TRUE
 *****************************************************************************/
DEM_LOCAL_INLINE FUNC(void, DEM_CODE)
Dem_Dtr_ResetWriteOnShutdown(
  void
  );

/* ****************************************************************************
 * Dem_Dtr_SetTestValue
 *****************************************************************************/
/*!
 * \brief         Set the test value of the Dtr
 *
 * \details       Set the test value of the Dtr
 *
 * \param[in]     DtrIndex
 *                Unique handle of the Dtr
 *                The DtrIndex must be in range [0..Dem_Dtr_GetGlobalDtrCount()[.
 * \param[in]     Value
 *                New test value
 *
 * \pre           -
 *
 * \context       TASK|ISR2
 * \synchronous   TRUE
 * \reentrant     TRUE
 *****************************************************************************/
DEM_LOCAL_INLINE FUNC(void, DEM_CODE)
Dem_Dtr_SetTestValue(
  CONST(uint16, AUTOMATIC)  DtrIndex,
  CONST(uint16, AUTOMATIC)  Value
  );

/* ****************************************************************************
 * Dem_Dtr_SetLowerLimit
 *****************************************************************************/
/*!
 * \brief         Set the lower limit of the Dtr
 *
 * \details       Set the lower limit of the Dtr
 *
 * \param[in]     DtrIndex
 *                Unique handle of the Dtr
 *                The DtrIndex must be in range [0..Dem_Dtr_GetGlobalDtrCount()[.
 * \param[in]     Value
 *                New lower limit
 *
 * \pre           -
 *
 * \context       TASK|ISR2
 * \synchronous   TRUE
 * \reentrant     TRUE
 *****************************************************************************/
DEM_LOCAL_INLINE FUNC(void, DEM_CODE)
Dem_Dtr_SetLowerLimit(
  CONST(uint16, AUTOMATIC)  DtrIndex,
  CONST(uint16, AUTOMATIC)  Value
  );

/* ****************************************************************************
 * Dem_Dtr_SetUpperLimit
 *****************************************************************************/
/*!
 * \brief         Set the upper limit of the Dtr
 *
 * \details       Set the upper limit of the Dtr
 *
 * \param[in]     DtrIndex
 *                Unique handle of the Dtr
 *                The DtrIndex must be in range [0..Dem_Dtr_GetGlobalDtrCount()[.
 * \param[in]     Value
 *                New upper limit
 *
 * \pre           -
 *
 * \context       TASK|ISR2
 * \synchronous   TRUE
 * \reentrant     TRUE
 *****************************************************************************/
DEM_LOCAL_INLINE FUNC(void, DEM_CODE)
Dem_Dtr_SetUpperLimit(
  CONST(uint16, AUTOMATIC)  DtrIndex,
  CONST(uint16, AUTOMATIC)  Value
  );

/* ****************************************************************************
 * Dem_Dtr_IsTestResultInLimits
 *****************************************************************************/
/*!
 * \brief         Tests whether a test result is valid
 *
 * \details       Tests whether a test result is within the limits
 *
 * \param[in]     TestResult
 *                Test Result
 * \param[in]     LowerLimit
 *                Lower Limit
 * \param[in]     UpperLimit
 *                Upper Limit
 * \param[in]     Ctrlval
 *                Dtr Control Value
 *
 * \return        TRUE
 *                The Test result is valid
 * \return        FALSE
 *                The Test result is not valid
 *
 * \pre           -
 *
 * \context       TASK|ISR2
 * \synchronous   TRUE
 * \reentrant     TRUE
 *****************************************************************************/
DEM_LOCAL_INLINE FUNC(boolean, DEM_CODE)
Dem_Dtr_IsTestResultInLimits(
  CONST(sint32, AUTOMATIC)  TestResult,
  CONST(sint32, AUTOMATIC)  LowerLimit,
  CONST(sint32, AUTOMATIC)  UpperLimit,
  CONST(Dem_DTRControlType, AUTOMATIC)  Ctrlval
  );

/* ****************************************************************************
 * Dem_Dtr_IsProcessable
 *****************************************************************************/
/*!
 * \brief         Tests whether a Dtr is processable
 *
 * \details       Tests whether a Dtr is processable
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
 *                Dtr Control Value (values DEM_DTR_CTL_INVISIBLE and
 *                                   DEM_DTR_CTL_RESET are invalid)
 *
 * \return        TRUE
 *                The Dtr shall be processed
 * \return        FALSE
 *                The Dtr shall not be processed
 *
 * \pre           -
 *
 * \context       TASK|ISR2
 * \synchronous   TRUE
 * \reentrant     TRUE
 *****************************************************************************/
DEM_LOCAL_INLINE FUNC(boolean, DEM_CODE)
Dem_Dtr_IsProcessable(
  CONST(uint16, AUTOMATIC)  DTRId,
  CONST(sint32, AUTOMATIC)  TestResult,
  CONST(sint32, AUTOMATIC)  LowerLimit,
  CONST(sint32, AUTOMATIC)  UpperLimit,
  CONST(Dem_DTRControlType, AUTOMATIC)  Ctrlval
  );

/* ****************************************************************************
 * Dem_Dtr_ConvertValue
 *****************************************************************************/
/*!
 * \brief         Converts value
 *
 * \details       Converts value from uint32 to uint16 using configured
 *                formula coefficients
 *
 * \param[in]     DTRId
 *                Dtr Index
 * \param[in]     InitialValue
 *                initial value
 * \param[out]    ConvertedValue
 *                converted value
 *
 * \return        DEM_DTR_OK
 *                Initial value was converted correctly to uint16 value
 * \return        DEM_DTR_CONVERSION_UNDERFLOW
 *                Converted value underran uint16 range and was set to 0
 * \return        DEM_DTR_CONVERSION_OVERFLOW
 *                Converted value overran uint16 range and was set to 0xffff
 *
 * \pre           -
 *
 * \context       TASK|ISR2
 * \synchronous   TRUE
 * \reentrant     TRUE
 *****************************************************************************/
DEM_LOCAL FUNC(Std_ReturnType, DEM_CODE)
Dem_Dtr_ConvertValue(
  CONST(uint16, AUTOMATIC) DTRId,
  CONST(sint32, AUTOMATIC) InitialValue,
  CONSTP2VAR(uint16, AUTOMATIC, AUTOMATIC) ConvertedValue
  );

/* ****************************************************************************
 * Dem_Dtr_ShiftThresholds
 *****************************************************************************/
/*!
 * \brief         Shifts Thresholds if necessary
 *
 * \details       If thresholds are (not) violated prior to the conversion, they
 *                shall (not) be violated after the conversion. Therefore
 *                thresholds can be shifted by one if meaning has changed.
 *
 * \param[in]     TestValue
 *                Test Value
 * \param[in]     LimitViolation
 *                Indicates if test value was within thresholds before conversion
 *                or if lower or upper limit was violated
 * \param[in,out] LowerLimit
 *                Lower Limit
 * \param[in,out] UpperLimit
 *                Upper Limit
 *
 * \return        E_OK
 *                Lower and upper limits have been corrected
 * \return        E_NOT_OK
 *                Lower and upper limits would have been shifted by more than one
 *
 * \pre           -
 *
 * \context       TASK|ISR2
 * \synchronous   TRUE
 * \reentrant     TRUE
 *****************************************************************************/
DEM_LOCAL FUNC(Std_ReturnType, DEM_CODE)
Dem_Dtr_ShiftThresholds(
  CONST(uint16, AUTOMATIC)  TestValue,
  CONST(uint8, AUTOMATIC)   LimitViolation,
  CONSTP2VAR(uint16, AUTOMATIC, AUTOMATIC) LowerLimit,
  CONSTP2VAR(uint16, AUTOMATIC, AUTOMATIC) UpperLimit
  );

/* ****************************************************************************
 * Dem_Dtr_ProcessDtrValues
 *****************************************************************************/
/*!
 * \brief         Processes the Dtr values
 *
 * \details       Processes the Dtr values
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
 *                Dtr Control Value (values DEM_DTR_CTL_INVISIBLE and
 *                                   DEM_DTR_CTL_RESET are invalid)
 *
 * \pre           -
 *
 * \context       TASK|ISR2
 * \synchronous   TRUE
 * \reentrant     TRUE
 *****************************************************************************/
DEM_LOCAL_INLINE FUNC(void, DEM_CODE)
Dem_Dtr_ProcessDtrValues(
  CONST(uint16, AUTOMATIC)  DTRId,
  CONST(sint32, AUTOMATIC)  TestResult,
  CONST(sint32, AUTOMATIC)  LowerLimit,
  CONST(sint32, AUTOMATIC)  UpperLimit,
  CONST(Dem_DTRControlType, AUTOMATIC)  Ctrlval
  );

/* ****************************************************************************
 * Dem_Dtr_SetDtrValues
 *****************************************************************************/
/*!
 * \brief         Writes DTR values into memory.
 *
 * \details       -
 *
 * \param[in]     DTRId
 *                DTR ID
 * \param[in]     TestValue
 *                The result value of a test.
 * \param[in]     LowerLimit
 *                The the lower limit of TestValue.
 * \param[in]     UpperLimit
 *                The the upper limit of TestValue.
 *
 * \pre           -
 *
 * \context       TASK|ISR2
 * \synchronous   TRUE
 * \reentrant     TRUE
 *****************************************************************************/
DEM_LOCAL_INLINE FUNC(void, DEM_CODE)
Dem_Dtr_SetDtrValues(
  CONST(uint16, AUTOMATIC) DTRId,
  CONST(uint16, AUTOMATIC) TestValue,
  CONST(uint16, AUTOMATIC) LowerLimit,
  CONST(uint16, AUTOMATIC) UpperLimit
  );

/* ****************************************************************************
 * Dem_Dtr_GetRelatedEvent
 *****************************************************************************/
/*!
 * \brief         Get the Event configuration of a Dtr
 *
 * \details       Get the Event configuration of a Dtr
 *
 * \param[in]     DtrId
 *                Unique handle of the Dtr.
 *                The DtrId must be in range [0..Dem_Dtr_GetGlobalDtrCount()-1[.
 *
 * \return        Handle to the Event configuration for a Dtr
 *
 * \pre           -
 *
 * \context       TASK|ISR2
 * \synchronous   TRUE
 * \reentrant     TRUE
 *****************************************************************************/
DEM_LOCAL_INLINE FUNC(Dem_EventIdType, DEM_CODE)
Dem_Dtr_GetRelatedEvent(
  CONST(uint16, AUTOMATIC) DtrId
  );

/*!
 * \}
 */
#define DEM_STOP_SEC_CODE
#include "MemMap.h"                                                                                                              /* PRQA S 5087 */ /* MD_MSR_19.1 */


/* ********************************************************************************************************************
 *  SUBCOMPONENT OBJECT FUNCTION DECLARATIONS
 *********************************************************************************************************************/
#define DEM_START_SEC_CODE
#include "MemMap.h"                                                                                                              /* PRQA S 5087 */ /* MD_MSR_19.1 */
/*!
 * \defgroup Dem_Dtr_Properties Properties
 * \{
 */

/* ****************************************************************************
 * Dem_Dtr_GetGlobalDtrCount
 *****************************************************************************/
/*!
 * \brief         Get the number of configured Dtrs
 *
 * \details       Get the number of configured Dtrs.
 *
 * \return        The number of configured Dtr
 *
 * \pre           -
 *
 * \context       TASK|ISR2
 * \synchronous   TRUE
 * \reentrant     TRUE
 *****************************************************************************/
DEM_LOCAL_INLINE FUNC(uint16, DEM_CODE)
Dem_Dtr_GetGlobalDtrCount(
  void
  );

/*!
 * \}
 */
#define DEM_STOP_SEC_CODE
#include "MemMap.h"                                                                                                              /* PRQA S 5087 */ /* MD_MSR_19.1 */

/* ********************************************************************************************************************
 *  SUBCOMPONENT API FUNCTION DECLARATIONS
 *********************************************************************************************************************/
#define DEM_START_SEC_CODE
#include "MemMap.h"                                                                                                              /* PRQA S 5087 */ /* MD_MSR_19.1 */
/*!
 * \defgroup Dem_Dtr_Public Public Methods
 * \{
 */

/* ****************************************************************************
 * Dem_Dtr_Init
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
Dem_Dtr_Init(
  void
  );

/* ****************************************************************************
 * Dem_Dtr_PreInit
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
Dem_Dtr_PreInit(
  void
  );

/* ****************************************************************************
 *  Dem_Dtr_MainFunction
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
Dem_Dtr_MainFunction(
  void
  );

/* ****************************************************************************
 * Dem_Dtr_Shutdown
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
Dem_Dtr_Shutdown(
  void
  );

/* ****************************************************************************
 * Dem_Dtr_IsValidHandle
 *****************************************************************************/
/*!
 * \brief         Tests whether a Dtr Id is valid
 *
 * \details       Tests whether a Dtr Id is valid
 *
 * \param[in]     DtrId
 *                Unique handle of the Dtr.
 *
 * \return        returns whether a Dtr Id is valid
 *
 * \pre           -
 *
 * \context       TASK|ISR2
 * \synchronous   TRUE
 * \reentrant     TRUE
 *****************************************************************************/
DEM_LOCAL_INLINE FUNC(boolean, DEM_CODE)
Dem_Dtr_IsValidHandle(
  CONST(uint16, AUTOMATIC) DtrId
  );

/* ****************************************************************************
 * Dem_Dtr_ClearDtrOfEvent
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
Dem_Dtr_ClearDtrOfEvent(
  CONST(Dem_EventIdType, AUTOMATIC)  EventId
  );

/* ****************************************************************************
 * Dem_Dtr_SetDtr
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
 * \config        DEM_CFG_SUPPORT_DTR == STD_ON
 *
 * \context       TASK|ISR2
 * \synchronous   TRUE
 * \reentrant     TRUE for different Dtr Ids
 *****************************************************************************/
DEM_LOCAL_INLINE FUNC(Std_ReturnType, DEM_CODE)
Dem_Dtr_SetDtr(
  CONST(uint16, AUTOMATIC) DTRId,
  CONST(sint32, AUTOMATIC) TestResult,
  CONST(sint32, AUTOMATIC) LowerLimit,
  CONST(sint32, AUTOMATIC) UpperLimit,
  CONST(Dem_DTRControlType, AUTOMATIC) Ctrlval
  );

#if (DEM_CFG_SUPPORT_DTR == STD_ON)
/* ****************************************************************************
 * Dem_Dtr_TestDtrVisibility
 *****************************************************************************/
/*!
 * \brief         Test whether the Dtr is visible to the diagnostic tester
 *
 * \details       Test whether the Dtr is visible to the diagnostic tester
 *
 * \param[in]     DTRId
 *                Dtr Index
 *
 * \return        TRUE
 *                The Dtr may be reported to a tester
 * \return        FALSE
 *                The Dtr may not be reported to a tester
 *
 * \pre           -
 * \config        DEM_CFG_SUPPORT_DTR == STD_ON
 *
 * \context       TASK|ISR2
 * \synchronous   TRUE
 * \reentrant     TRUE
 *****************************************************************************/
DEM_LOCAL_INLINE FUNC(boolean, DEM_CODE)
Dem_Dtr_TestDtrVisibility(
  CONST(uint16, AUTOMATIC) DTRId
  );
#endif

/* ****************************************************************************
 * Dem_Dtr_GetUaSId
 *****************************************************************************/
/*!
 * \brief         Get the UaSId for the Dtr
 *
 * \details       Get the UaSId for the Dtr
 *
 * \param[in]     DtrId
 *                Unique handle of the Dtr.
 *                The DtrId must be in range [0..Dem_Dtr_GetGlobalDtrCount()-1[.
 *
 * \return        UaSId for the Dtr.
 *
 * \pre           -
 *
 * \context       TASK|ISR2
 * \synchronous   TRUE
 * \reentrant     TRUE
 *****************************************************************************/
DEM_LOCAL_INLINE FUNC(uint8, DEM_CODE)
Dem_Dtr_GetUaSId(
  CONST(uint16, AUTOMATIC) DtrId
  );

/* ****************************************************************************
 * Dem_Dtr_GetTestValue
 *****************************************************************************/
/*!
 * \brief         Get the test value of the Dtr
 *
 * \details       Get the test value of the Dtr
 *
 * \param[in]     DtrIndex
 *                Unique handle of the Dtr
 *                The DtrIndex must be in range [0..Dem_Dtr_GetGlobalDtrCount()[.
 *
 * \return        The test value
 *
 * \pre           -
 *
 * \context       TASK|ISR2
 * \synchronous   TRUE
 * \reentrant     TRUE
 *****************************************************************************/
DEM_LOCAL_INLINE FUNC(uint16, DEM_CODE)
Dem_Dtr_GetTestValue(
  CONST(uint16, AUTOMATIC)  DtrIndex
  );

/* ****************************************************************************
 * Dem_Dtr_GetLowerLimit
 *****************************************************************************/
/*!
 * \brief         Get the lower limit of the Dtr
 *
 * \details       Get the lower limit of the Dtr
 *
 * \param[in]     DtrIndex
 *                Unique handle of the Dtr
 *                The DtrIndex must be in range [0..Dem_Dtr_GetGlobalDtrCount()[.
 *
 * \return        The lower limit
 *
 * \pre           -
 *
 * \context       TASK|ISR2
 * \synchronous   TRUE
 * \reentrant     TRUE
 *****************************************************************************/
DEM_LOCAL_INLINE FUNC(uint16, DEM_CODE)
Dem_Dtr_GetLowerLimit(
  CONST(uint16, AUTOMATIC)  DtrIndex
  );

/* ****************************************************************************
 * Dem_Dtr_GetUpperLimit
 *****************************************************************************/
 /*!
 * \brief         Get the upper limit of the Dtr
 *
 * \details       Get the upper limit of the Dtr
 *
 * \param[in]     DtrIndex
 *                Unique handle of the Dtr
 *                The DtrIndex must be in range [0..Dem_Dtr_GetGlobalDtrCount()[.
 *
 * \return        The upper limit
 *
 * \pre           -
 *
 * \context       TASK|ISR2
 * \synchronous   TRUE
 * \reentrant     TRUE
 *****************************************************************************/
DEM_LOCAL_INLINE FUNC(uint16, DEM_CODE)
Dem_Dtr_GetUpperLimit(
  CONST(uint16, AUTOMATIC)  DtrIndex
  );

/*!
 * \}
 */

#define DEM_STOP_SEC_CODE
#include "MemMap.h"                                                                                                              /* PRQA S 5087 */ /* MD_MSR_19.1 */

#endif /* DEM_DTR_INTERFACE_H */

/*!
 * \}
 */


/* ********************************************************************************************************************
 *  END OF FILE: Dem_Dtr_Interface.h
 *********************************************************************************************************************/
