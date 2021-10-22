/**********************************************************************************************************************
 *  COPYRIGHT
 *  -------------------------------------------------------------------------------------------------------------------
 *  \verbatim
 *  Copyright (c) 2015 by Vctr Informatik GmbH.
 *
 *                This software is copyright protected and proprietary to Vctr Informatik GmbH.
 *                Vctr Informatik GmbH grants to you only those rights as set out in the license conditions.
 *                All other rights remain with Vctr Informatik GmbH.
 *  \endverbatim
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         \file  E2E_P05.h
 *        \brief  E2E header file for AUTOSAR E2E Library Profile 5
 *
 *      \details  E2E protection ensures data exchange which is protected at runtime against the effects of faults within
 *                the communication link. E2E Library provides mechanisms for E2E protection, adequate for safety-related
 *                communication having requirements up to ASIL D.
 *
 *********************************************************************************************************************/

/**** Protection against multiple inclusion **************************************************************************/
#if !defined (E2E_P05_H)
# define E2E_P05_H

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
# include "E2E.h"

/**********************************************************************************************************************
 *  LOCAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/

typedef struct {
    uint16 Offset; /*!< Bit offset of the first bit of the E2E header from the beginning */
    uint16 DataLength; /*!< Length of Data, in bits */
    uint16 DataID; /*!< Unique identifier for protection against masquerading */
    uint8 MaxDeltaCounter; /*!< Maximum allowed difference between two counter values of consecutively received valid messages */
} E2E_P05ConfigType;

typedef struct {
    uint8  Counter; /*!< Counter to be used for protecting the next Data */
} E2E_P05ProtectStateType;

typedef enum {
    E2E_P05STATUS_OK = 0x00,
    E2E_P05STATUS_NONEWDATA = 0x01,
    E2E_P05STATUS_ERROR = 0x07,
    E2E_P05STATUS_REPEATED = 0x08,
    E2E_P05STATUS_OKSOMELOST = 0x20,
    E2E_P05STATUS_WRONGSEQUENCE = 0x40
} E2E_P05CheckStatusType;

typedef struct {
    E2E_P05CheckStatusType  Status; /*!< Result of verification of the Data in this cycle */
    uint8 Counter; /*!< Counter of the Data in previous cycle */
} E2E_P05CheckStateType;



/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/

# define E2E_START_SEC_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/**********************************************************************************************************************
 *  E2E_P05Protect()
 *********************************************************************************************************************/
/*!
 * \brief           Protection function of E2Elib Profile 5
 * \details         Protects the array/buffer to be transmitted using the E2E Profile 5. This includes checksum calculation,
 *                  handling of counter and Data ID.
 * \param[in]       ConfigPtr Pointer to profile configuration
 * \param[in,out]   StatePtr  Pointer to communication state
 * \param[in,out]   DataPtr   Pointer to data to be protected
 * \param[in]       Length    Length of data in bytes
 * \return          E2E_E_INPUTERR_NULL: A pointer parameter is NULL
 * \return          E2E_E_INPUTERR_WRONG: One parameter is erroneous
 * \return          E2E_E_INTERR: Internal library error
 * \return          E2E_E_OK: Protection successful
 * \pre             -
 * \context         TASK
 * \reentrant       FALSE
 * \synchronous     TRUE
 * \trace           CREQ-1086
 */
FUNC (Std_ReturnType, E2E_CODE) E2E_P05Protect( P2CONST (E2E_P05ConfigType, AUTOMATIC, E2E_APPL_CONST) ConfigPtr,
                                                P2VAR (E2E_P05ProtectStateType, AUTOMATIC, E2E_APPL_DATA) StatePtr,
                                                P2VAR (uint8, AUTOMATIC, E2E_APPL_DATA) DataPtr,
                                                VAR (uint16, AUTOMATIC) Length);


/**********************************************************************************************************************
 *  E2E_P05ProtectInit()
 *********************************************************************************************************************/
/*!
 * \brief           Protection initialization function of E2Elib Profile 5
 * \details         Initializes the protection state by resetting the counter
 * \param[in,out]   StatePtr  Pointer to communication state
 * \return          E2E_E_INPUTERR_NULL: Pointer parameter is NULL
 * \return          E2E_E_OK: Initialization successful
 * \pre             -
 * \context         TASK
 * \reentrant       FALSE
 * \synchronous     TRUE
 * \trace           CREQ-1087
 */
FUNC (Std_ReturnType, E2E_CODE) E2E_P05ProtectInit( P2VAR (E2E_P05ProtectStateType, AUTOMATIC, E2E_APPL_DATA) StatePtr);


/**********************************************************************************************************************
 *  E2E_P05Check()
 *********************************************************************************************************************/
/*!
 * \brief           Check function of E2Elib Profile 5
 * \details         Checks the Data received using the E2E Profile 5. This includes CRC calculation, handling of
 *                  the counter and Data ID.
 * \param[in]       ConfigPtr Pointer to profile configuration
 * \param[in,out]   StatePtr  Pointer to communication state
 * \param[in]       DataPtr   Pointer to data to be protected
 * \param[in]       Length    Length of data in bytes
 * \return          E2E_E_INPUTERR_NULL: A pointer parameter is NULL
 * \return          E2E_E_INPUTERR_WRONG: One parameter is erroneous
 * \return          E2E_E_INTERR: Internal library error
 * \return          E2E_E_OK: Protection successful
 * \pre             -
 * \context         TASK
 * \reentrant       FALSE
 * \synchronous     TRUE
 * \trace           CREQ-1088
 */
FUNC (Std_ReturnType, E2E_CODE) E2E_P05Check( P2CONST (E2E_P05ConfigType, AUTOMATIC, E2E_APPL_CONST) ConfigPtr,
                                              P2VAR (E2E_P05CheckStateType, AUTOMATIC, E2E_APPL_DATA) StatePtr,
                                              P2CONST (uint8, AUTOMATIC, E2E_APPL_DATA) DataPtr,
                                              VAR (uint16, AUTOMATIC) Length);


/**********************************************************************************************************************
 *  E2E_P05CheckInit()
 *********************************************************************************************************************/
/*!
 * \brief           Check initialization function of E2Elib Profile 5
 * \details         Check initialization function of E2Elib Profile 5
 * \param[in,out]   StatePtr  Pointer to communication state
 * \return          E2E_E_INPUTERR_NULL: Pointer parameter is NULL
 * \return          E2E_E_OK: Initialization successful
 * \pre             -
 * \context         TASK
 * \reentrant       FALSE
 * \synchronous     TRUE
 * \trace           CREQ-1089
 */
FUNC (Std_ReturnType, E2E_CODE) E2E_P05CheckInit( P2VAR (E2E_P05CheckStateType, AUTOMATIC, E2E_APPL_DATA) StatePtr);


/**********************************************************************************************************************
 *  E2E_P05MapStatusToSM()
 *********************************************************************************************************************/
/*!
 * \brief           State mapping function of E2Elib Profile 5
 * \details         Maps the check status of Profile 5 to a generic check status, which can be used by E2E state machine
 *                  check function. The E2E Profile 5 delivers a more fine-grained status, but this is not relevant for
 *                  the E2E state machine.
 * \param[in]       CheckReturn     Return value of E2E_P05Check
 * \param[in]       Status          communication state
 * \return          Standard state value to be used in E2Elib state machine
 * \pre             -
 * \context         TASK
 * \reentrant       FALSE
 * \synchronous     TRUE
 * \trace           CREQ-1175
 * \trace           SPEC-2056747
 */
FUNC (E2E_PCheckStatusType, E2E_CODE) E2E_P05MapStatusToSM( VAR (Std_ReturnType, AUTOMATIC) CheckReturn,
                                                            VAR (E2E_P05CheckStatusType, AUTOMATIC) Status);

# define E2E_STOP_SEC_CODE
# include "MemMap.h" /* PRQA S 5087 */  /* MD_MSR_19.1 */

#endif /* E2E_P05_H */

/**********************************************************************************************************************
 *  END OF FILE: E2E_P05.h
 *********************************************************************************************************************/
