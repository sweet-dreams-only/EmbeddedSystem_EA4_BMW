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
 *         \file  E2E_P05.c
 *        \brief  E2E source file for AUTOSAR E2E Library Profile 5
 *
 *      \details  E2E protection ensures data exchange which is protected at runtime against the effects of faults within
 *                the communication link. E2E Library provides mechanisms for E2E protection, adequate for safety-related
 *                communication having requirements up to ASIL D.
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#include "E2E_P05.h"

/**********************************************************************************************************************
 *  LOCAL CONSTANT MACROS
 **********************************************************************************************************************/

#if !defined (E2E_LOCAL) /* COV_E2E_COMPATIBILITY */
# define E2E_LOCAL static
#endif

#if !defined (E2E_LOCAL_INLINE) /* COV_E2E_COMPATIBILITY */
# define E2E_LOCAL_INLINE LOCAL_INLINE
#endif

/**********************************************************************************************************************
 *  LOCAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/
#define E2E_START_SEC_CODE
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/**********************************************************************************************************************
 *  E2E_P05ProtectVerifyInputs()
 *********************************************************************************************************************/
/*!
 * \brief      Checks the input data of E2E_P05Protect
 * \details    All relevant input parameters are checked in order to proceed with E2E_P05Protect service
 * \param[in]  ConfigPtr  Pointer to the config data structure
 * \param[in]  StatePtr   Pointer to the state data structure
 * \param[in]  DataPtr    Pointer to the data to be protected
 * \param[in]  Length     Length of the content of DataPtr
 * \return     Standard return value, indicating valid/invalid input
 * \pre        -
 * \context    TASK
 * \reentrant  FALSE
 * \synchronous TRUE
 */
E2E_LOCAL FUNC (Std_ReturnType, E2E_CODE) E2E_P05ProtectVerifyInputs(P2CONST (E2E_P05ConfigType, AUTOMATIC, E2E_APPL_CONST) ConfigPtr,
                                                                     P2CONST (E2E_P05ProtectStateType, AUTOMATIC, E2E_APPL_DATA ) StatePtr,
                                                                     P2CONST (uint8, AUTOMATIC, E2E_APPL_DATA ) DataPtr,
                                                                     VAR (uint16, AUTOMATIC) Length);

/**********************************************************************************************************************
 *  E2E_P05CheckVerifyInputs()
 *********************************************************************************************************************/
/*!
 * \brief      Checks the input data of E2E_P05Check
 * \details    All relevant input parameters are checked in order to proceed with E2E_P05Check service
 * \param[in]  ConfigPtr            Pointer to the config data structure
 * \param[in]  StatePtr             Pointer to the state data structure
 * \param[in]  DataPtr              Pointer to the data to be protected
 * \param[in]  Length               Length of the content of DataPtr
 * \param[in]  NewDataAvailablePtr  Pointer to variable where new data available indication shall be stored
 * \return     Standard return value, indicating valid/invalid input
 * \pre        -
 * \context    TASK
 * \reentrant  FALSE
 * \synchronous TRUE
 */
E2E_LOCAL FUNC (Std_ReturnType, E2E_CODE) E2E_P05CheckVerifyInputs(P2CONST (E2E_P05ConfigType, AUTOMATIC, E2E_APPL_CONST) ConfigPtr,
                                                                   P2CONST (E2E_P05CheckStateType, AUTOMATIC, E2E_APPL_DATA ) StatePtr,
                                                                   P2CONST (uint8, AUTOMATIC, E2E_APPL_DATA ) DataPtr,
                                                                   VAR (uint16, AUTOMATIC) Length,
                                                                   P2VAR (boolean, AUTOMATIC, E2E_APPL_DATA ) NewDataAvailablePtr);

/**********************************************************************************************************************
 *  E2E_CheckDeltaCounter()
 *********************************************************************************************************************/
/*!
 * \brief          Applies further checks regarding delta counter
 * \details        Performs checks on the received counter value and updates StatePtr->Status
 * \param[in]      ConfigPtr        Pointer to the config data structure
 * \param[in,out]  StatePtr         Pointer to the state data structure
 * \param[in]      ReceivedCounter  The actual received counter value
 * \pre            -
 * \context        TASK
 * \reentrant      FALSE
 * \synchronous    TRUE
 */
E2E_LOCAL FUNC (void, E2E_CODE) E2E_CheckDeltaCounter(P2CONST (E2E_P05ConfigType, AUTOMATIC, E2E_APPL_CONST) ConfigPtr,
                                                      P2VAR (E2E_P05CheckStateType, AUTOMATIC, E2E_APPL_DATA) StatePtr,
                                                      VAR (uint8, AUTOMATIC) ReceivedCounter);

/**********************************************************************************************************************
 *  E2E_P05ComputeCRC()
 *********************************************************************************************************************/
/*!
 * \brief      Compute the CRC over payload and header
 * \details    Compute the CRC over payload and header using CRC16 routine
 * \param[in]  DataPtr           Pointer to the data to be protected
 * \param[in]  Length            Length of the data in bytes
 * \param[in]  Offset            Offset of the E2E header in DataPtr in bytes
 * \param[in]  DataID            DataID to be added to CRC calculation
 * \return     uint16            The calculated CRC value
 * \pre        -
 * \context    TASK
 * \reentrant  FALSE
 * \synchronous TRUE
 */
E2E_LOCAL FUNC (uint16, E2E_CODE) E2E_P05ComputeCRC(P2CONST (uint8, AUTOMATIC, E2E_APPL_DATA) DataPtr,
                                                    VAR (uint16, AUTOMATIC ) Length,
                                                    VAR (uint16, AUTOMATIC ) Offset,
                                                    VAR (uint16, AUTOMATIC ) DataID);
    
/**********************************************************************************************************************
 *  LOCAL FUNCTIONS
 **********************************************************************************************************************/

/**********************************************************************************************************************
 *  E2E_P05ProtectVerifyInputs()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
E2E_LOCAL FUNC (Std_ReturnType, E2E_CODE) E2E_P05ProtectVerifyInputs(P2CONST (E2E_P05ConfigType, AUTOMATIC, E2E_APPL_CONST) ConfigPtr,
                                                                     P2CONST (E2E_P05ProtectStateType, AUTOMATIC, E2E_APPL_DATA ) StatePtr,
                                                                     P2CONST (uint8, AUTOMATIC, E2E_APPL_DATA ) DataPtr,
                                                                     VAR (uint16, AUTOMATIC) Length)
{
    Std_ReturnType ret = E2E_E_INPUTERR_NULL;

    /* #10 Check if input pointer parameters are valid and if Length matches with configuration */
    if (  (ConfigPtr != NULL_PTR)
       && (StatePtr != NULL_PTR)
       && (DataPtr != NULL_PTR)
       )
    {
        if (Length == (ConfigPtr->DataLength >> 3))
        {
            ret = E2E_E_OK;
        }
        else
        {
            ret = E2E_E_INPUTERR_WRONG;
        }
    }

    return ret;
}

/**********************************************************************************************************************
 *  E2E_P05CheckVerifyInputs()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 */
E2E_LOCAL FUNC (Std_ReturnType, E2E_CODE) E2E_P05CheckVerifyInputs(P2CONST (E2E_P05ConfigType, AUTOMATIC, E2E_APPL_CONST) ConfigPtr,
                                                                   P2CONST (E2E_P05CheckStateType, AUTOMATIC, E2E_APPL_DATA ) StatePtr,
                                                                   P2CONST (uint8, AUTOMATIC, E2E_APPL_DATA ) DataPtr,
                                                                   VAR (uint16, AUTOMATIC) Length,
                                                                   P2VAR (boolean, AUTOMATIC, E2E_APPL_DATA ) NewDataAvailablePtr)
{
    Std_ReturnType ret = E2E_E_INPUTERR_WRONG;
    *NewDataAvailablePtr = FALSE; /* SBSW_E2E_04 */

    /* #10 Check if input pointer parameters are valid */
    if ( (ConfigPtr != NULL_PTR) && (StatePtr != NULL_PTR) )
    {
        /* #20 Check if both DataPtr and Length are set */
        if ((DataPtr != NULL_PTR) && (Length != 0u))
        {
            /* #25 Check if Length matches with configured length */
            if ( Length == (ConfigPtr->DataLength >> 3) )
            {
                *NewDataAvailablePtr = TRUE; /* SBSW_E2E_04 */
                ret = E2E_E_OK;        
            }
        }
        /* #30 Check if both DataPtr and Length are null. This may happen at runtime if queued communication is used and no data is available */
        else if ((DataPtr == NULL_PTR) && (Length == 0u))
        {
            ret = E2E_E_OK;
        }
        else
        {
            ret = E2E_E_INPUTERR_WRONG;
        }
    }
    else
    {
        ret = E2E_E_INPUTERR_NULL;
    }

    return ret;
}

/**********************************************************************************************************************
 *  E2E_CheckDeltaCounter()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 */
E2E_LOCAL FUNC (void, E2E_CODE) E2E_CheckDeltaCounter(P2CONST (E2E_P05ConfigType, AUTOMATIC, E2E_APPL_CONST) ConfigPtr,
                                                      P2VAR (E2E_P05CheckStateType, AUTOMATIC, E2E_APPL_DATA) StatePtr,
                                                      VAR (uint8, AUTOMATIC) ReceivedCounter)
{
    /* #10 Compute DeltaCounter. Wrap around is also considered */
    uint8 DeltaCounter = ReceivedCounter - StatePtr->Counter;

    /* #20 Check if DeltaCounter is within valid range */
    if (DeltaCounter <= ConfigPtr->MaxDeltaCounter)
    {
        /* #30 Check if message was not repeated */
        if (DeltaCounter > 0u)
        {
            /* #40 Check if correct subsequent message was received. No data was lost in between communication */
            if (DeltaCounter == 1u)
            {
                StatePtr->Status = E2E_P05STATUS_OK; /* SBSW_E2E_03 */
            }
            /* #50 Data was lost, but it's still tolerable */
            else
            {
                StatePtr->Status = E2E_P05STATUS_OKSOMELOST; /* SBSW_E2E_03 */
            }
        }
        else
        {
            StatePtr->Status = E2E_P05STATUS_REPEATED; /* SBSW_E2E_03 */
        }
    }
    else
    {
        StatePtr->Status = E2E_P05STATUS_WRONGSEQUENCE; /* SBSW_E2E_03 */
    }
    StatePtr->Counter = ReceivedCounter; /* SBSW_E2E_03 */
    return;
}

/**********************************************************************************************************************
 *  E2E_P05ComputeCRC()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 */
E2E_LOCAL FUNC (uint16, E2E_CODE) E2E_P05ComputeCRC(P2CONST (uint8, AUTOMATIC, E2E_APPL_DATA) DataPtr,
                                                    VAR (uint16, AUTOMATIC ) Length,
                                                    VAR (uint16, AUTOMATIC ) Offset,
                                                    VAR (uint16, AUTOMATIC ) DataID)
{
    uint8 byte[2];
    uint16 crc;

    /* #10 Check if CRC is not positioned in first bytes of DataPtr */
    if (Offset > 0)
    {
        /* #12 Calculate CRC over Data bytes before CRC position */
        crc = Crc_CalculateCRC16 ( DataPtr /* SBSW_E2E_03 */
                                 , Offset
                                 , 0xffffu
                                 , TRUE
                                 );
        /* #14 Calculate CRC over Data bytes after CRC position */
        crc = Crc_CalculateCRC16 ( &DataPtr[Offset + 2u] /* SBSW_E2E_03 */
                                 , Length - Offset - 2u
                                 , crc
                                 , FALSE
                                 );
    }
    else
    {
        /* #16 CRC is positioned in first bytes of DataPtr. Calculate CRC over all residual bytes */
        crc = Crc_CalculateCRC16 ( &DataPtr[2u] /* SBSW_E2E_03 */
                                 , Length - 2u
                                 , 0xffffu
                                 , TRUE
                                 );
    }
    /* #20 Calculate CRC over DataID _after_ calculating CRC over the data. Use little endian byte order */
    byte[0] = (uint8) (DataID & 0xffu); /* SBSW_E2E_05 */
    byte[1] = (uint8) (DataID >> 8u); /* SBSW_E2E_05 */
    crc = Crc_CalculateCRC16 (&byte[0], 2u, crc, FALSE); /* SBSW_E2E_02 */

    return crc;
}

/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 **********************************************************************************************************************/

/**********************************************************************************************************************
 *  E2E_P05Protect()
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
 */
FUNC (Std_ReturnType, E2E_CODE) E2E_P05Protect( P2CONST (E2E_P05ConfigType, AUTOMATIC, E2E_APPL_CONST) ConfigPtr,
                                                P2VAR (E2E_P05ProtectStateType, AUTOMATIC, E2E_APPL_DATA) StatePtr,
                                                P2VAR (uint8, AUTOMATIC, E2E_APPL_DATA) DataPtr,
                                                VAR (uint16, AUTOMATIC) Length)
{
    /* #10 Verify inputs of the protect function */
    Std_ReturnType ret = E2E_P05ProtectVerifyInputs (ConfigPtr, StatePtr, DataPtr, Length); /* SBSW_E2E_03 */

    if (ret == E2E_E_OK)
    {
        uint16 ComputedCRC;
        /* #20 Compute Offset */
        uint16 ByteOffset = ConfigPtr->Offset >> 3u;

        /* #30 Write Counter */
        DataPtr[ByteOffset + 2u] = StatePtr->Counter; /* SBSW_E2E_03 */

        /* #40 Compute CRC */
        ComputedCRC = E2E_P05ComputeCRC ( DataPtr /* SBSW_E2E_03 */
                                        , Length
                                        , ByteOffset
                                        , ConfigPtr->DataID
                                        );

        /* #50 Write CRC in little endian order (low byte first) */
        DataPtr[ByteOffset]      = (uint8)(ComputedCRC & 0xffu); /* SBSW_E2E_03 */
        DataPtr[ByteOffset + 1u] = (uint8)(ComputedCRC >> 8u); /* SBSW_E2E_03 */

        /* #60 Increment Counter. Implicit wrap-around 255 -> 0 */
        StatePtr->Counter++; /* SBSW_E2E_03 */
    }

    return ret;
}

/**********************************************************************************************************************
 *  E2E_P05ProtectInit()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FUNC (Std_ReturnType, E2E_CODE) E2E_P05ProtectInit( P2VAR (E2E_P05ProtectStateType, AUTOMATIC, E2E_APPL_DATA) StatePtr)
{
    Std_ReturnType ret = E2E_E_INPUTERR_NULL;

    /* #10 Initialize Counter in case StatePtr is valid */
    if (StatePtr != NULL_PTR)
    {
        StatePtr->Counter = 0u; /* SBSW_E2E_03 */
        ret = E2E_E_OK;
    }

    return ret;
}

/**********************************************************************************************************************
 *  E2E_P05Check()
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
 */
FUNC (Std_ReturnType, E2E_CODE) E2E_P05Check( P2CONST (E2E_P05ConfigType, AUTOMATIC, E2E_APPL_CONST) ConfigPtr,
                                              P2VAR (E2E_P05CheckStateType, AUTOMATIC, E2E_APPL_DATA) StatePtr,
                                              P2CONST (uint8, AUTOMATIC, E2E_APPL_DATA) DataPtr,
                                              VAR (uint16, AUTOMATIC) Length)
{
    boolean NewDataAvailable = FALSE;
    /* #10 Verify inputs of the check function */
    Std_ReturnType ret = E2E_P05CheckVerifyInputs ( ConfigPtr /* SBSW_E2E_02 */
                                   , StatePtr
                                   , DataPtr
                                   , Length
                                   , &NewDataAvailable
                                   );

    if (ret == E2E_E_OK)
    {
        /* #20 Check if new data is available */
        if (NewDataAvailable == TRUE) 
        {
            /* #30 Compute offset */
            uint16 ByteOffset = ConfigPtr->Offset >> 3;

            /* #40 Read Counter */
            uint8 ReceivedCounter = DataPtr[ByteOffset + 2u];

            /* #50 Read CRC */
            uint16 ReceivedCRC = (  (uint16) DataPtr[ByteOffset + 0u]
                        | ( ((uint16) DataPtr[ByteOffset + 1u]) << 8u));

            /* #60 Compute CRC */
            uint16 ComputedCRC = E2E_P05ComputeCRC (DataPtr, Length, ByteOffset, ConfigPtr->DataID); /* SBSW_E2E_03 */

            /* #70 Do checks */
            if (ReceivedCRC == ComputedCRC)
            {
                E2E_CheckDeltaCounter (ConfigPtr, StatePtr, ReceivedCounter); /* SBSW_E2E_03 */
            }
            else
            {
                StatePtr->Status = E2E_P05STATUS_ERROR; /* SBSW_E2E_03 */
            }
        }
        else
        {
            StatePtr->Status = E2E_P05STATUS_NONEWDATA; /* SBSW_E2E_03 */
        }
    }

    return ret;
}

/**********************************************************************************************************************
 *  E2E_P05CheckInit()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FUNC (Std_ReturnType, E2E_CODE) E2E_P05CheckInit( P2VAR (E2E_P05CheckStateType, AUTOMATIC, E2E_APPL_DATA) StatePtr)
{
    Std_ReturnType ret = E2E_E_INPUTERR_NULL;
    /* #10 Reset State structure in case StatePtr is valid */
    if (StatePtr != NULL_PTR)
    {
        StatePtr->Counter = 0xFFu; /* SBSW_E2E_03 */
        StatePtr->Status  = E2E_P05STATUS_ERROR; /* SBSW_E2E_03 */
        ret = E2E_E_OK;
    }

    return ret;
}

/**********************************************************************************************************************
 *  E2E_P05MapStatusToSM()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
FUNC (E2E_PCheckStatusType, E2E_CODE) E2E_P05MapStatusToSM( VAR (Std_ReturnType, AUTOMATIC) CheckReturn,
                                                            VAR (E2E_P05CheckStatusType, AUTOMATIC) Status)
{
    E2E_PCheckStatusType ret = E2E_P_ERROR;

    /* #10 Status is only mapped to state machine if check-function returned successfully */
    if (CheckReturn == E2E_E_OK)
    {
        /* #20 Status of Profile 5 is mapped to state machine status, which is not that fine-grained */
        switch (Status)
        {
            case E2E_P05STATUS_OK           : ret = E2E_P_OK; break;
            case E2E_P05STATUS_OKSOMELOST   : ret = E2E_P_OK; break;
            case E2E_P05STATUS_ERROR        : ret = E2E_P_ERROR; break;
            case E2E_P05STATUS_REPEATED     : ret = E2E_P_REPEATED; break;
            case E2E_P05STATUS_NONEWDATA    : ret = E2E_P_REPEATED; break;
            case E2E_P05STATUS_WRONGSEQUENCE: ret = E2E_P_WRONGSEQUENCE; break;
            default: break; /* PRQA S 2018 */ /* MD_EtoE_14.1 */
        }
    }

    return ret;    
}

#define E2E_STOP_SEC_CODE
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/**********************************************************************************************************************
 *  END OF FILE: E2E_P05.c
 *********************************************************************************************************************/
