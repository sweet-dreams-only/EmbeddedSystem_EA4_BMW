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
 *         \file  E2E_SM.h
 *        \brief  E2E header file for AUTOSAR E2E State Machine
 *
 *      \details  E2E protection ensures data exchange which is protected at runtime against the effects of faults within
 *                the communication link. E2E Library provides mechanisms for E2E protection, adequate for safety-related
 *                communication having requirements up to ASIL D. The E2E Profile check()-functions verify data in one cycle.
 *                In contrary, the state machine builds up a state out of several results of check() function within a
 *                reception window, which is then provided to the consumer (RTE/SWC/COM).
 *
 *********************************************************************************************************************/

/**** Protection against multiple inclusion **************************************************************************/
#if !defined (E2E_SM_H)
# define E2E_SM_H

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#include "Std_Types.h"

/**********************************************************************************************************************
 *  LOCAL CONSTANT MACROS
 *********************************************************************************************************************/

/* Error flags used by all E2E Library functions */

# define E2E_E_INPUTERR_NULL  0x13 /**< Error: At least one pointer parameter is NULL    */

# define E2E_E_INPUTERR_WRONG 0x17 /**< Error: At least one input parameter is erroneous, e.g. out of range    */

# define E2E_E_INTERR         0x19 /**< Error: An internal library error has occurred    */

# define E2E_E_WRONGSTATE     0x1a /**< Error: Function executed in wrong state */

# define E2E_E_OK             0x00 /**< Function completed successfully       */

/**********************************************************************************************************************
 *  LOCAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/

typedef enum
{
    E2E_P_OK = 0x00u,
    E2E_P_REPEATED = 0x01u,
    E2E_P_WRONGSEQUENCE = 0x02u,
    E2E_P_ERROR = 0x03u,
    E2E_P_NOTAVAILABLE = 0x04u    
} E2E_PCheckStatusType;

typedef struct
{
    uint8 WindowSize; /*!< Number of consecutive messages which are considered at determining SM status */

    uint8 MinOkStateInit; /*!< Number of successful messages that are needed to get from E2E_SM_INIT to E2E_SM_VALID */
    uint8 MaxErrorStateInit; /*!< Number of erroneous messages that needs to be exceeded to get from E2E_SM_INIT to E2E_SM_INVALID */

    uint8 MinOkStateValid; /*!< Number of successful messages that are needed to stay in E2E_SM_VALID */
    uint8 MaxErrorStateValid; /*!< Number of erroneous messages that needs to be exceeded to get from E2E_SM_VALID to E2E_SM_INVALID */
    
    uint8 MinOkStateInvalid; /*!< Number of successful messages that needs to be exceeded to get from E2E_SM_INVALID to E2E_SM_VALID */
    uint8 MaxErrorStateInvalid; /*!< Number of erroneous messages that needs to be exceeded to stay in E2E_SM_INVALID */
} E2E_SMConfigType;

typedef enum
{
    E2E_SM_VALID   = 0x00u,
    E2E_SM_DEINIT  = 0x01u,
    E2E_SM_NODATA  = 0x02u,
    E2E_SM_INIT    = 0x03u,
    E2E_SM_INVALID = 0x04u
} E2E_SMStateType;

typedef struct
{
    P2VAR(uint8, AUTOMATIC, E2E_APPL_DATA) ProfileStatusWindow; /*!< Contains list of statuses of most recent messages */
    uint8  WindowTopIndex; /*!< Index where next message status in ProfileStatusWindow */
    uint8  OkCount; /*!< Number of successful messages within the ProfileStatusWindow */
    uint8  ErrorCount; /*!< Number of erroneous messages within the ProfileStatusWindow */
    E2E_SMStateType SMState; /*!< Current state of state machine */
} E2E_SMCheckStateType;

/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/

# define E2E_START_SEC_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/**********************************************************************************************************************
 *  E2E_SMCheck()
 *********************************************************************************************************************/
/*!
 * \brief           Check function of E2Elib StateMachine
 * \details         Checks the communication channel. It determines if the data can be used for safety-related application,
 *                  based on history of checks performed by a corresponding E2E_P0XCheck() function.
 * \param[in]       ProfileStatus Unified profile status value
 * \param[in]       ConfigPtr     Pointer to StateMachine configuration
 * \param[in,out]   StatePtr      Pointer to StateMachine state
 * \return          E2E_E_INPUTERR_NULL: A pointer parameter is NULL
 * \return          E2E_E_INPUTERR_WRONG: One parameter is erroneous
 * \return          E2E_E_INTERR: Internal library error
 * \return          E2E_E_OK: Protection successful
 * \return          E2E_E_WRONGSTATE: Function executed in wrong state
 * \pre             -
 * \context         TASK
 * \reentrant       FALSE
 * \synchronous     TRUE
 * \trace           CREQ-1091
 */
FUNC (Std_ReturnType, E2E_CODE) E2E_SMCheck (VAR (E2E_PCheckStatusType, AUTOMATIC) ProfileStatus,
                                             P2CONST (E2E_SMConfigType, AUTOMATIC, E2E_APPL_CONST) ConfigPtr,
                                             P2VAR (E2E_SMCheckStateType, AUTOMATIC, E2E_APPL_DATA) StatePtr);


/**********************************************************************************************************************
 *  E2E_SMCheckInit()
 *********************************************************************************************************************/
/*!
 * \brief           State initialization function of E2Elib StateMachine
 * \details         State initialization function of E2Elib StateMachine
 * \param[in,out]   StatePtr  Pointer to StateMachine state
 * \param[in]       ConfigPtr Pointer to StateMachine configuration
 * \return          E2E_E_INPUTERR_NULL: A pointer parameter is NULL
 * \return          E2E_E_OK: Protection successful
 * \pre             -
 * \context         TASK
 * \reentrant       FALSE
 * \synchronous     TRUE
 * \trace           CREQ-1092
 */
FUNC (Std_ReturnType, E2E_CODE) E2E_SMCheckInit (P2VAR (E2E_SMCheckStateType, AUTOMATIC, E2E_APPL_DATA) StatePtr,
                                                 P2CONST (E2E_SMConfigType, AUTOMATIC, E2E_APPL_CONST) ConfigPtr);

# define E2E_STOP_SEC_CODE
# include "MemMap.h" /* PRQA S 5087 */  /* MD_MSR_19.1 */

#endif /* E2E_SM_H */

/**********************************************************************************************************************
 *  END OF FILE: E2E_SM.h
 *********************************************************************************************************************/
