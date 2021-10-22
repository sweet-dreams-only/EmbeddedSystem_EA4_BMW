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
 *         \file  E2E_SM.c
 *        \brief  E2E source file for AUTOSAR E2E State Machine
 *
 *      \details  E2E protection ensures data exchange which is protected at runtime against the effects of faults within
 *                the communication link. E2E Library provides mechanisms for E2E protection, adequate for safety-related
 *                communication having requirements up to ASIL D. The E2E Profile check()-functions verify data in one cycle.
 *                In contrary, the state machine builds up a state out of several results of check() function within a
 *                reception window, which is then provided to the consumer (RTE/SWC/COM).
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#include "E2E_SM.h"

/**********************************************************************************************************************
 *  LOCAL CONSTANT MACROS
 **********************************************************************************************************************/

#if !defined (E2E_LOCAL) /* COV_E2E_COMPATIBILITY */
# define E2E_LOCAL static
#endif

#if !defined (E2E_LOCAL_INLINE) /* COV_E2E_COMPATIBILITY */
# define E2E_LOCAL_INLINE LOCAL_INLINE
#endif

/* Utility Macros */

#define E2E_SM_INC_WRAPAROUND(x, max) (((x)==(max)) ? (0u)  : ((x)+1u)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#define E2E_SM_DEC_WRAPAROUND(x, max) (((x)==(0u))  ? (max) : ((x)-1u)) /* PRQA S 3453 */ /* MD_MSR_19.7 */

/**********************************************************************************************************************
 *  LOCAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/

#define E2E_START_SEC_CODE
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/**********************************************************************************************************************
 *  E2E_SMCheckParams()
 *********************************************************************************************************************/
/*!
 * \brief      Check function of E2Elib StateMachine call parameters
 * \details    Check configuration of E2Elib StateMachine
 * \param[in]  ProfileStatus  Unified profile status value
 * \param[in]  ConfigPtr      Pointer to StateMachine configuration
 * \param[in]  StatePtr       Pointer to StateMachine state
 * \return     Standard return value, indicating success/error
 * \pre        -
 * \context    TASK
 * \reentrant  FALSE
 * \synchronous TRUE
 */
E2E_LOCAL FUNC (Std_ReturnType, E2E_CODE) E2E_SMCheckParams(VAR (E2E_PCheckStatusType, AUTOMATIC) ProfileStatus,
                                                            P2CONST (E2E_SMConfigType, AUTOMATIC, E2E_APPL_CONST) ConfigPtr,
                                                            P2CONST (E2E_SMCheckStateType, AUTOMATIC, E2E_APPL_DATA) StatePtr);

/**********************************************************************************************************************
 *  E2E_SMAddStatus()
 *********************************************************************************************************************/
/*!
 * \brief      Status ring buffer handling function of E2Elib StateMachine
 * \details    Profile status is added to ring buffer, OkCount and ErrorCount are computed
 * \param[in]  ProfileStatus  Unified profile status value
 * \param[in]  ConfigPtr      Pointer to StateMachine configuration
 * \param[in]  StatePtr       Pointer to StateMachine state
 * \pre        -
 * \context    TASK
 * \reentrant  FALSE
 * \synchronous TRUE
 */
E2E_LOCAL FUNC (void, E2E_CODE) E2E_SMAddStatus(VAR (E2E_PCheckStatusType, AUTOMATIC) ProfileStatus,
                                                P2CONST (E2E_SMConfigType, AUTOMATIC, E2E_APPL_CONST) ConfigPtr,
                                                P2VAR (E2E_SMCheckStateType, AUTOMATIC, E2E_APPL_DATA) StatePtr);

/**********************************************************************************************************************
 *  E2E_CheckHandleSMNoData()
 *********************************************************************************************************************/
/*!
 * \brief      Check function of E2Elib StateMachine state SMNoData
 * \details    Check function of E2Elib StateMachine state SMNoData
 * \param[in]  ProfileStatus  Unified profile status value
 * \param[in]  ConfigPtr      Pointer to StateMachine configuration
 * \param[in]  StatePtr       Pointer to StateMachine state
 * \pre        -
 * \context    TASK
 * \reentrant  FALSE
 * \synchronous TRUE
 */
E2E_LOCAL FUNC (void, E2E_CODE) E2E_CheckHandleSMNoData(VAR (E2E_PCheckStatusType, AUTOMATIC) ProfileStatus,
                                                        P2CONST (E2E_SMConfigType, AUTOMATIC, E2E_APPL_CONST) ConfigPtr,
                                                        P2VAR (E2E_SMCheckStateType, AUTOMATIC, E2E_APPL_DATA) StatePtr);
    
/**********************************************************************************************************************
 *  E2E_CheckHandleSMInit()
 *********************************************************************************************************************/
/*!
 * \brief      Check function of E2Elib StateMachine state SMInit
 * \details    Check function of E2Elib StateMachine state SMInit
 * \param[in]  ProfileStatus  Unified profile status value
 * \param[in]  ConfigPtr      Pointer to StateMachine configuration
 * \param[in]  StatePtr       Pointer to StateMachine state
 * \pre        -
 * \context    TASK
 * \reentrant  FALSE
 * \synchronous TRUE
 */
E2E_LOCAL FUNC (void, E2E_CODE) E2E_CheckHandleSMInit(VAR (E2E_PCheckStatusType, AUTOMATIC) ProfileStatus,
                                                      P2CONST (E2E_SMConfigType, AUTOMATIC, E2E_APPL_CONST) ConfigPtr,
                                                      P2VAR (E2E_SMCheckStateType, AUTOMATIC, E2E_APPL_DATA) StatePtr);

/**********************************************************************************************************************
 *  E2E_CheckHandleSMValid()
 *********************************************************************************************************************/
/*!
 * \brief      Check function of E2Elib StateMachine state SMValid
 * \details    Check function of E2Elib StateMachine state SMValid
 * \param[in]  ProfileStatus  Unified profile status value
 * \param[in]  ConfigPtr      Pointer to StateMachine configuration
 * \param[in]  StatePtr       Pointer to StateMachine state
 * \pre        -
 * \context    TASK
 * \reentrant  FALSE
 * \synchronous TRUE
 */
E2E_LOCAL FUNC (void, E2E_CODE) E2E_CheckHandleSMValid(VAR (E2E_PCheckStatusType, AUTOMATIC) ProfileStatus,
                                                       P2CONST (E2E_SMConfigType, AUTOMATIC, E2E_APPL_CONST) ConfigPtr,
                                                       P2VAR (E2E_SMCheckStateType, AUTOMATIC, E2E_APPL_DATA) StatePtr);

/**********************************************************************************************************************
 *  E2E_CheckHandleSMInvalid()
 *********************************************************************************************************************/
/*!
 * \brief      Check function of E2Elib StateMachine state SMInvalid
 * \details    Check function of E2Elib StateMachine state SMInvalid
 * \param[in]  ProfileStatus  Unified profile status value
 * \param[in]  ConfigPtr      Pointer to StateMachine configuration
 * \param[in]  StatePtr       Pointer to StateMachine state
 * \return     Standard return value, indicating success/error
 * \pre        -
 * \context    TASK
 * \reentrant  FALSE
 * \synchronous TRUE
 */
E2E_LOCAL FUNC (void, E2E_CODE) E2E_CheckHandleSMInvalid(VAR (E2E_PCheckStatusType, AUTOMATIC) ProfileStatus,
                                                         P2CONST (E2E_SMConfigType, AUTOMATIC, E2E_APPL_CONST) ConfigPtr,
                                                         P2VAR (E2E_SMCheckStateType, AUTOMATIC, E2E_APPL_DATA) StatePtr);

/**********************************************************************************************************************
 *  LOCAL FUNCTIONS
 **********************************************************************************************************************/

/**********************************************************************************************************************
 *  E2E_SMCheckParams()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 */
E2E_LOCAL FUNC (Std_ReturnType, E2E_CODE) E2E_SMCheckParams(VAR (E2E_PCheckStatusType, AUTOMATIC) ProfileStatus,
                                                            P2CONST (E2E_SMConfigType, AUTOMATIC, E2E_APPL_CONST) ConfigPtr,
                                                            P2CONST (E2E_SMCheckStateType, AUTOMATIC, E2E_APPL_DATA) StatePtr)
{
    Std_ReturnType ret = E2E_E_OK;
    
    /* #10 Check if ProfileStatus is valid */
    switch (ProfileStatus)
    {
        case E2E_P_OK:            break;
        case E2E_P_REPEATED:      break;
        case E2E_P_WRONGSEQUENCE: break;
        case E2E_P_ERROR:         break;
        case E2E_P_NOTAVAILABLE:  break;
        default: ret = E2E_E_INPUTERR_WRONG; /* PRQA S 2018 */ /* MD_EtoE_14.1 */
    }
    
    /* #20 Check if WindowSize is valid */
    if ( ConfigPtr->WindowSize == 0 )
    {
        ret = E2E_E_INPUTERR_WRONG;
    }
    /* #30 Check if WindowSize is greater than MinOkStateInit */
    else if (ConfigPtr->MinOkStateInit > ConfigPtr->WindowSize )
    {
        ret = E2E_E_INPUTERR_WRONG;
    }
    /* #35 Check if WindowSize is greater than MaxErrorStateInit */
    else if ( ConfigPtr->MaxErrorStateInit > ConfigPtr->WindowSize )
    {
        ret = E2E_E_INPUTERR_WRONG;
    }
    /* #40 Check if WindowSize is greater than MinOkStateValid */
    else if ( ConfigPtr->MinOkStateValid > ConfigPtr->WindowSize )
    {
        ret = E2E_E_INPUTERR_WRONG;
    }
    /* #50 Check if WindowSize is greater than MaxErrorStateValid */
    else if ( ConfigPtr->MaxErrorStateValid > ConfigPtr->WindowSize )
    {
        ret = E2E_E_INPUTERR_WRONG;
    }
    /* #60 Check if WindowSize is greater than MinOkStateInvalid */
    else if ( ConfigPtr->MinOkStateInvalid > ConfigPtr->WindowSize )
    {
        ret = E2E_E_INPUTERR_WRONG;
    }
    /* #70 Check if WindowSize is greater than MaxErrorStateInvalid */
    else if ( ConfigPtr->MaxErrorStateInvalid > ConfigPtr->WindowSize )
    {
        ret = E2E_E_INPUTERR_WRONG;
    }
    /* #80 Check if ProfileStatusWindow is null */
    else if ( StatePtr->ProfileStatusWindow == NULL_PTR )
    {
        ret = E2E_E_INPUTERR_WRONG;    
    }
    /* #90 Check if WindowTopIndex is greater than WindowSize */
    else if ( StatePtr->WindowTopIndex >= ConfigPtr->WindowSize )
    {
        ret = E2E_E_INPUTERR_WRONG;    
    }
    /* #100 Check if SMState is valid */
    else
    {
        switch (StatePtr->SMState)
        {
            case E2E_SM_VALID: break;
            case E2E_SM_DEINIT: break;
            case E2E_SM_NODATA: break;
            case E2E_SM_INIT: break;
            case E2E_SM_INVALID: break;
            default: ret = E2E_E_INPUTERR_WRONG;
        }
    }
    return ret;    
} /* PRQA S 6010, 6030, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STMIF */

/**********************************************************************************************************************
 *  E2E_SMAddStatus()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 */
E2E_LOCAL FUNC (void, E2E_CODE) E2E_SMAddStatus(VAR (E2E_PCheckStatusType, AUTOMATIC) ProfileStatus,
                                                P2CONST (E2E_SMConfigType, AUTOMATIC, E2E_APPL_CONST) ConfigPtr,
                                                P2VAR (E2E_SMCheckStateType, AUTOMATIC, E2E_APPL_DATA) StatePtr)
{
    uint8 i;

    /* #10 Add ProfileStatus to top of ProfileStatusWindow array */
    StatePtr->ProfileStatusWindow[StatePtr->WindowTopIndex] = (uint8) ProfileStatus; /* SBSW_E2E_03 */
    
    /* #20 Increment WindowTopIndex */
    StatePtr->WindowTopIndex =  E2E_SM_INC_WRAPAROUND ( StatePtr->WindowTopIndex, ConfigPtr->WindowSize - 1u); /* SBSW_E2E_03 */
  
    /* #30 Set OkCount to number of elements in ProfileStatusWindow with values E2E_P_OK */
    /* #31 Set ErrorCount to number of elements in ProfileStatusWindow with values E2E_P_ERROR */
    StatePtr->OkCount = 0u; /* SBSW_E2E_03 */
    StatePtr->ErrorCount = 0u; /* SBSW_E2E_03 */
    for (i = 0u; i < ConfigPtr->WindowSize; i++)
    {
        switch (StatePtr->ProfileStatusWindow[i])
        {
            case E2E_P_OK:    StatePtr->OkCount++;    break; /* SBSW_E2E_03 */
            case E2E_P_ERROR: StatePtr->ErrorCount++; break; /* SBSW_E2E_03 */
            default: break;
        }
    }
}

/**********************************************************************************************************************
 *  E2E_CheckHandleSMNoData()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
E2E_LOCAL FUNC (void, E2E_CODE) E2E_CheckHandleSMNoData(VAR (E2E_PCheckStatusType, AUTOMATIC) ProfileStatus,
                                                        P2CONST (E2E_SMConfigType, AUTOMATIC, E2E_APPL_CONST) ConfigPtr,
                                                        P2VAR (E2E_SMCheckStateType, AUTOMATIC, E2E_APPL_DATA) StatePtr)
{
    /* #10 Check if ProfileStatus is valid */
    if (ProfileStatus != E2E_P_ERROR)
    {
        /* #20 Add ProfileStatus to ProfileStatusWindow and recalculate OkCount and ErrorCount */
        E2E_SMAddStatus (ProfileStatus, ConfigPtr, StatePtr); /* SBSW_E2E_03 */
        /* #30 State is always changed to E2E_SM_INIT */
        StatePtr->SMState = E2E_SM_INIT; /* SBSW_E2E_03 */
    }
}

/**********************************************************************************************************************
 *  E2E_CheckHandleSMInit()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 */
E2E_LOCAL FUNC (void, E2E_CODE) E2E_CheckHandleSMInit(VAR (E2E_PCheckStatusType, AUTOMATIC) ProfileStatus,
                                                      P2CONST (E2E_SMConfigType, AUTOMATIC, E2E_APPL_CONST) ConfigPtr,
                                                      P2VAR (E2E_SMCheckStateType, AUTOMATIC, E2E_APPL_DATA) StatePtr)
{
    /* #10 Add ProfileStatus to ProfileStatusWindow and recalculate OkCount and ErrorCount */
    E2E_SMAddStatus (ProfileStatus, ConfigPtr, StatePtr); /* SBSW_E2E_03 */

    /* #20 Check if ErrorCount exceeds its configured maximum */
    if (StatePtr->ErrorCount > ConfigPtr->MaxErrorStateInit)
    {
        StatePtr->SMState = E2E_SM_INVALID; /* SBSW_E2E_03 */
    }
    else
    {
        /* #30 State is changed to E2E_SM_VALID if OkCount is within boundary */
        if (StatePtr->OkCount >= ConfigPtr->MinOkStateInit)
        {
            StatePtr->SMState = E2E_SM_VALID; /* SBSW_E2E_03 */
        }
        /* #40 else: stay in E2E_SM_INIT */
    }
}

/**********************************************************************************************************************
 *  E2E_CheckHandleSMValid()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
E2E_LOCAL FUNC (void, E2E_CODE) E2E_CheckHandleSMValid(VAR (E2E_PCheckStatusType, AUTOMATIC) ProfileStatus,
                                                       P2CONST (E2E_SMConfigType, AUTOMATIC, E2E_APPL_CONST) ConfigPtr,
                                                       P2VAR (E2E_SMCheckStateType, AUTOMATIC, E2E_APPL_DATA) StatePtr)
{
    /* #10 Add ProfileStatus to ProfileStatusWindow and recalculate OkCount and ErrorCount */
    E2E_SMAddStatus (ProfileStatus, ConfigPtr, StatePtr); /* SBSW_E2E_03 */

    /* #20 As long as ErrorCount is smaller than allowed maximum and OkCount is greater than minimum, stay in state E2E_SM_VALID. Otherwise change to E2E_SM_INVALID */
    if (  (StatePtr->ErrorCount <= ConfigPtr->MaxErrorStateValid)
       && (StatePtr->OkCount    >= ConfigPtr->MinOkStateValid)  )
    {
        StatePtr->SMState = E2E_SM_VALID; /* SBSW_E2E_03 */
    }
    else
    {
        StatePtr->SMState = E2E_SM_INVALID; /* SBSW_E2E_03 */
    }
}

/**********************************************************************************************************************
 *  E2E_CheckHandleSMInvalid()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
E2E_LOCAL FUNC (void, E2E_CODE) E2E_CheckHandleSMInvalid(VAR (E2E_PCheckStatusType, AUTOMATIC) ProfileStatus,
                                                         P2CONST (E2E_SMConfigType, AUTOMATIC, E2E_APPL_CONST) ConfigPtr,
                                                         P2VAR (E2E_SMCheckStateType, AUTOMATIC, E2E_APPL_DATA) StatePtr)
{
    /* #10 Add ProfileStatus to ProfileStatusWindow and recalculate OkCount and ErrorCount */
    E2E_SMAddStatus (ProfileStatus, ConfigPtr, StatePtr); /* SBSW_E2E_03 */

    /* #20 As long as ErrorCount is smaller than allowed maximum and OkCount is greater than minimum, change state to E2E_SM_VALID. Otherwise stay in E2E_SM_INVALID */
    if (  (StatePtr->ErrorCount <= ConfigPtr->MaxErrorStateInvalid)
       && (StatePtr->OkCount    >= ConfigPtr->MinOkStateInvalid)
       )
    {
        StatePtr->SMState = E2E_SM_VALID; /* SBSW_E2E_03 */
    }
    else
    {
        StatePtr->SMState = E2E_SM_INVALID; /* SBSW_E2E_03 */
    }
}

/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 **********************************************************************************************************************/

/**********************************************************************************************************************
 *  E2E_SMCheckInit()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
FUNC (Std_ReturnType, E2E_CODE) E2E_SMCheckInit (P2VAR (E2E_SMCheckStateType, AUTOMATIC, E2E_APPL_DATA) StatePtr,
                                                 P2CONST (E2E_SMConfigType, AUTOMATIC, E2E_APPL_CONST) ConfigPtr)
{  
    uint8 i;
    Std_ReturnType ret = E2E_E_INPUTERR_NULL;

    /* #10 Check if both StatePtr and ConfigPtr are valid */
    if ( (StatePtr != NULL_PTR) && (ConfigPtr != NULL_PTR) )
    {
        /* #20 Initialize ProfileStatus for all elements within the window */
        for (i = 0; i < ConfigPtr->WindowSize; i++)
        {
            StatePtr->ProfileStatusWindow[i] = E2E_P_NOTAVAILABLE; /* SBSW_E2E_03 */
        }
        /* #30 Initialize parameters of state structure */
        StatePtr->WindowTopIndex = 0; /* SBSW_E2E_03 */
        StatePtr->OkCount = 0; /* SBSW_E2E_03 */
        StatePtr->ErrorCount = 0; /* SBSW_E2E_03 */
        StatePtr->SMState = E2E_SM_NODATA; /* SBSW_E2E_03 */
        ret = E2E_E_OK;
    }

    return ret;
}

/**********************************************************************************************************************
 *  E2E_SMCheck()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
FUNC (Std_ReturnType, E2E_CODE) E2E_SMCheck (VAR (E2E_PCheckStatusType, AUTOMATIC) ProfileStatus,
                                             P2CONST (E2E_SMConfigType, AUTOMATIC, E2E_APPL_CONST) ConfigPtr,
                                             P2VAR (E2E_SMCheckStateType, AUTOMATIC, E2E_APPL_DATA) StatePtr)
{
    Std_ReturnType ret = E2E_E_INPUTERR_NULL;

    /* #10 Check if both StatePtr and ConfigPtr are valid */
    if ( (StatePtr != NULL_PTR) && (ConfigPtr != NULL_PTR) )
    {
        /* #20 Check if parameters of Config- and State-structure are valid */
        ret = E2E_SMCheckParams (ProfileStatus, ConfigPtr, StatePtr); /* SBSW_E2E_03 */
        if (ret == E2E_E_OK)
        {
            /* #30 Compute state machine */
            switch (StatePtr->SMState)
            {
                case E2E_SM_DEINIT:
                    ret = E2E_E_WRONGSTATE;
                    break;
        
                case E2E_SM_NODATA:
                    E2E_CheckHandleSMNoData (ProfileStatus, ConfigPtr, StatePtr); /* SBSW_E2E_03 */
                    break;
        
                case E2E_SM_INIT:
                    E2E_CheckHandleSMInit (ProfileStatus, ConfigPtr, StatePtr); /* SBSW_E2E_03 */
                    break;
        
                case E2E_SM_VALID:
                    E2E_CheckHandleSMValid (ProfileStatus, ConfigPtr, StatePtr); /* SBSW_E2E_03 */
                    break;
        
                case E2E_SM_INVALID:
                    E2E_CheckHandleSMInvalid (ProfileStatus, ConfigPtr, StatePtr); /* SBSW_E2E_03 */
                    break;
        
                default:  ret = E2E_E_INTERR;  break; /* COV_E2E_MISRA */
            }
        }
    }
    return ret;
}

#define E2E_STOP_SEC_CODE
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/**********************************************************************************************************************
 *  END OF FILE: E2E_SM.c
 *********************************************************************************************************************/
