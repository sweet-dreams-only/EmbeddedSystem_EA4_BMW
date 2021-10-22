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
 *         \file  E2E_P01.c
 *        \brief  E2E source file for AUTOSAR E2E Library Profile 1
 *
 *      \details  E2E protection ensures data exchange which is protected at runtime against the effects of faults within
 *                the communication link. E2E Library provides mechanisms for E2E protection, adequate for safety-related
 *                communication having requirements up to ASIL D.
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#include "E2E_P01.h"

/**********************************************************************************************************************
 *  LOCAL CONSTANT MACROS
 **********************************************************************************************************************/

#define E2E_P01_MAX_COUNTER_VALUE 14u

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
 *  E2E_P01ProtectVerifyInputs()
 *********************************************************************************************************************/
/*!
 *
 * \brief      Checks the input data of E2E_P01Protect
 * \details    Checks if input pointer parameters are valid and if counter value is within range
 * \param[in]  ConfigPtr Pointer to the config data structure
 * \param[in]  StatePtr  Pointer to the state data structure
 * \param[in]  DataPtr   Pointer to the data to be protected
 * \return     Standard return value, indicating valid/invalid input
 * \pre        -
 * \context    TASK
 * \reentrant  FALSE
 * \synchronous TRUE
 */
E2E_LOCAL FUNC (Std_ReturnType, E2E_CODE) E2E_P01ProtectVerifyInputs( P2CONST (E2E_P01ConfigType, AUTOMATIC, E2E_APPL_CONST) ConfigPtr,
                                                                      P2CONST (E2E_P01ProtectStateType, AUTOMATIC, E2E_APPL_DATA ) StatePtr,
                                                                      P2CONST (uint8, AUTOMATIC, E2E_APPL_DATA ) DataPtr);

/**********************************************************************************************************************
 *  E2E_P01CheckVerifyInputs()
 *********************************************************************************************************************/
/*!
 * \brief      Checks the input data of E2E_P01Check
 * \details    Checks if input pointer parameters are valid and if counter values are within range
 * \param[in]  ConfigPtr Pointer to the config data structure
 * \param[in]  StatePtr  Pointer to the state data structure
 * \param[in]  DataPtr   Pointer to the data to be protected
 * \return     Standard return value, indicating valid/invalid input
 * \pre        -
 * \context    TASK
 * \reentrant  FALSE
 * \synchronous TRUE
 */
E2E_LOCAL FUNC (Std_ReturnType, E2E_CODE) E2E_P01CheckVerifyInputs(P2CONST (E2E_P01ConfigType, AUTOMATIC, E2E_APPL_CONST) ConfigPtr,
                                                                   P2CONST (E2E_P01CheckStateType, AUTOMATIC, E2E_APPL_DATA ) StatePtr,
                                                                   P2CONST (uint8, AUTOMATIC, E2E_APPL_DATA ) DataPtr);

/**********************************************************************************************************************
 *  E2E_P01CheckDataIDMode()
 *********************************************************************************************************************/
/*!
 * \brief      Checks if configured DataIDMode is valid
 * \details    Checks if configured DataIDMode is a valid E2E_P01DataIDMode
 * \param[in]  ConfigPtr
 * \return     E_OK     : DataIDMode is valid
 * \return     E_NOT_OK : DataIDMode is invalid
 * \pre        -
 * \context    TASK
 * \reentrant  FALSE
 * \synchronous TRUE
 */
E2E_LOCAL FUNC (Std_ReturnType, E2E_CODE) E2E_P01CheckDataIDMode(P2CONST (E2E_P01ConfigType, AUTOMATIC, E2E_APPL_CONST) ConfigPtr);

/**********************************************************************************************************************
 *  E2E_P01ComputeCRC()
 *********************************************************************************************************************/
/*!
 * \brief      Computes the CRC over the given data, including the DataID
 * \details    Computes the CRC over the given data, including the DataID according to DataIdMode
 * \param[in]  DataPtr   Pointer to the data to be protected
 * \param[in]  ConfigPtr Pointer to the config data structure
 * \param[in]  Counter   Sequence counter value
 * \return     uint8     The computed CRC
 * \pre        -
 * \context    TASK
 * \reentrant  FALSE
 * \synchronous TRUE
 */
E2E_LOCAL FUNC (uint8, E2E_CODE) E2E_P01ComputeCRC(P2CONST (uint8, AUTOMATIC, E2E_APPL_DATA) DataPtr,
                                                   P2CONST (E2E_P01ConfigType, AUTOMATIC, E2E_APPL_CONST) ConfigPtr,
                                                   VAR (uint8, AUTOMATIC) Counter);

/**********************************************************************************************************************
 *  E2E_CheckDeltaCounter()
 *********************************************************************************************************************/
/*!
 * \brief      Applies further checks regarding delta counter
 * \details    Applies further checks regarding delta counter
 * \param[in]  ConfigPtr       Pointer to the config data structure
 * \param[in]  StatePtr        Pointer to the state data structure
 * \param[in]  ReceivedCounter Received counter value
 * \pre        -
 * \context    TASK
 * \reentrant  FALSE
 * \synchronous TRUE
 */
E2E_LOCAL FUNC (void, E2E_CODE) E2E_CheckDeltaCounter(P2CONST (E2E_P01ConfigType, AUTOMATIC, E2E_APPL_CONST) ConfigPtr,
                                                      P2VAR (E2E_P01CheckStateType, AUTOMATIC, E2E_APPL_DATA) StatePtr,
                                                      VAR (uint8, AUTOMATIC) ReceivedCounter);
    
/**********************************************************************************************************************
 *  E2E_CheckSync()
 *********************************************************************************************************************/
/*!
 * \brief          Applies further checks regarding sync, may change E2E status
 * \details        Applies further checks regarding sync, may change E2E status
 * \param[in]      ConfigPtr  Pointer to the config data structure
 * \param[in,out]  StatePtr   Pointer to the state data structure
 * \pre            -
 * \context        TASK
 * \reentrant      FALSE
 * \synchronous    TRUE
 */
E2E_LOCAL FUNC (void, E2E_CODE) E2E_CheckSync(P2CONST (E2E_P01ConfigType, AUTOMATIC, E2E_APPL_CONST) ConfigPtr,
                                              P2VAR (E2E_P01CheckStateType, AUTOMATIC, E2E_APPL_DATA) StatePtr);
    
/**********************************************************************************************************************
 *  LOCAL FUNCTIONS
 **********************************************************************************************************************/

/**********************************************************************************************************************
 *  E2E_P01ProtectVerifyInputs()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
E2E_LOCAL FUNC (Std_ReturnType, E2E_CODE) E2E_P01ProtectVerifyInputs( P2CONST (E2E_P01ConfigType, AUTOMATIC, E2E_APPL_CONST) ConfigPtr,
                                                                      P2CONST (E2E_P01ProtectStateType, AUTOMATIC, E2E_APPL_DATA ) StatePtr,
                                                                      P2CONST (uint8, AUTOMATIC, E2E_APPL_DATA ) DataPtr)
{
    Std_ReturnType ret = E2E_E_INPUTERR_NULL;
    
    /* #10 Check input pointer parameter for NULL_PTR */
    if ( (ConfigPtr != NULL_PTR) && (StatePtr != NULL_PTR) && (DataPtr != NULL_PTR) )
    {
        /* #20 Check if value of Counter is within valid range */
        if (StatePtr->Counter > E2E_P01_MAX_COUNTER_VALUE)
        {
            ret = E2E_E_INPUTERR_WRONG;
        }
        else if (E2E_P01CheckDataIDMode(ConfigPtr) == E_NOT_OK) /* SBSW_E2E_03 */
        {
            ret = E2E_E_INPUTERR_WRONG;
        }
        else
        {
            ret = E2E_E_OK;
        }
    }

    return ret;
}

/**********************************************************************************************************************
 *  E2E_P01CheckVerifyInputs()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
E2E_LOCAL FUNC (Std_ReturnType, E2E_CODE) E2E_P01CheckVerifyInputs(P2CONST (E2E_P01ConfigType, AUTOMATIC, E2E_APPL_CONST) ConfigPtr,
                                                                   P2CONST (E2E_P01CheckStateType, AUTOMATIC, E2E_APPL_DATA ) StatePtr,
                                                                   P2CONST (uint8, AUTOMATIC, E2E_APPL_DATA ) DataPtr)
{
    Std_ReturnType ret = E2E_E_INPUTERR_NULL;
    
    /* #10 Check input parameter for NULL_PTR */
    if (  (ConfigPtr != NULL_PTR)
       && (StatePtr != NULL_PTR)
       && (DataPtr != NULL_PTR)
    )
    {
        /* #20 Check if counter values are within valid range */
        if (  (StatePtr->LastValidCounter > E2E_P01_MAX_COUNTER_VALUE)
           || (StatePtr->MaxDeltaCounter > E2E_P01_MAX_COUNTER_VALUE)
           || (StatePtr->SyncCounter > ConfigPtr->SyncCounterInit)
           || (StatePtr->NoNewOrRepeatedDataCounter > E2E_P01_MAX_COUNTER_VALUE)
           )
        {
            ret = E2E_E_INPUTERR_WRONG;
        }
        else if (E2E_P01CheckDataIDMode(ConfigPtr) == E_NOT_OK) /* SBSW_E2E_03 */
        {
            ret = E2E_E_INPUTERR_WRONG;
        }
        else
        {
            ret = E2E_E_OK;
        }
    }

    return ret;
}
 
/**********************************************************************************************************************
 *  E2E_P01CheckDataIDMode()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
E2E_LOCAL FUNC (Std_ReturnType, E2E_CODE) E2E_P01CheckDataIDMode(P2CONST (E2E_P01ConfigType, AUTOMATIC, E2E_APPL_CONST) ConfigPtr)
{
  Std_ReturnType ret;

  if (ConfigPtr->DataIDMode == E2E_P01_DATAID_ALT)
  {
    ret = E_OK;
  }
  else if (ConfigPtr->DataIDMode == E2E_P01_DATAID_BOTH)
  {
    ret = E_OK;
  }
  else if (ConfigPtr->DataIDMode == E2E_P01_DATAID_LOW)
  {
    ret = E_OK;
  }
  else if (ConfigPtr->DataIDMode == E2E_P01_DATAID_NIBBLE)
  {
    ret = E_OK;
  }
  else
  {
    ret = E_NOT_OK;
  }

  return ret;
}

/**********************************************************************************************************************
 *  E2E_P01ComputeCRC()
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
E2E_LOCAL FUNC (uint8, E2E_CODE) E2E_P01ComputeCRC(P2CONST (uint8, AUTOMATIC, E2E_APPL_DATA) DataPtr,
                                                   P2CONST (E2E_P01ConfigType, AUTOMATIC, E2E_APPL_CONST) ConfigPtr,
                                                   VAR (uint8, AUTOMATIC) Counter)
{
    uint8 crc;
    uint8 CrcLength = 0;
    uint8 LocalDataID[2];
    uint16 CalculatedOffset;
    uint16 CalculatedLength;

    switch (ConfigPtr->DataIDMode)
    {
        case E2E_P01_DATAID_BOTH:
            /* #10 Both two bytes of DataID are included in CRC, first low byte and then high byte */
            LocalDataID[0] = (uint8)ConfigPtr->DataID; /* SBSW_E2E_05 */
            LocalDataID[1] = (uint8)(ConfigPtr->DataID >> 8u); /* SBSW_E2E_05 */
            CrcLength = 2;
            break;
        case E2E_P01_DATAID_LOW:
            /* #11 Only the low byte of DataID is included in CRC */
            LocalDataID[0] = (uint8)ConfigPtr->DataID; /* SBSW_E2E_05 */
            CrcLength = 1;
            break;
        case E2E_P01_DATAID_NIBBLE:
            /* #12 The low byte of DataID is included in CRC and afterwards CRC for value 0 is computed */
            LocalDataID[0] = (uint8)ConfigPtr->DataID; /* SBSW_E2E_05 */
            LocalDataID[1] = 0; /* SBSW_E2E_05 */
            CrcLength = 2;
            break;
        case E2E_P01_DATAID_ALT:
            CrcLength = 1;
            /* #13 The low byte of DataID is included in CRC if value of Counter is even */
            if ((Counter & 0x01u) == 0u)
            {
                LocalDataID[0] = (uint8)ConfigPtr->DataID; /* SBSW_E2E_05 */
            }
            /* #14 The high byte of DataID is included in CRC if value of Counter is odd */
            else
            {
                LocalDataID[0] = (uint8)(ConfigPtr->DataID >> 8u); /* SBSW_E2E_05 */
            }
            break;
        default:  break; /* PRQA S 2018 */ /* MD_EtoE_14.1 */ /* COV_E2E_MISRA */
    }
    /* #20 Calculate CRC for DataID */
    /* #21 Initial CRC value 0xff is chosen in order to compensate initial XOR with 0xFF in CRC routine. */
    /* #22 This procedure is similar to an initial XOR with 0x00, as supported by AR3.x CRC calculation */
    crc = Crc_CalculateCRC8 (LocalDataID, CrcLength, 0xff, FALSE); /* SBSW_E2E_02 */

    CalculatedOffset = ConfigPtr->CRCOffset >> 3u;
    /* #30 CRC is computed over the area before the CRC position (if CRC is not the first byte)  */
    if ((CalculatedOffset) > 0u)
    {
        crc = Crc_CalculateCRC8 ( DataPtr       /* SBSW_E2E_03 */
                                , CalculatedOffset
                                , crc
                                , FALSE
                                );
    }
    CalculatedLength = ConfigPtr->DataLength >> 3u;
    /* #40 CRC is computed over the area after CRC position, if CRC is not the last byte */
    if (CalculatedOffset < (CalculatedLength - 1u))
    {
        crc = Crc_CalculateCRC8 ( &DataPtr[CalculatedOffset + 1u]   /* SBSW_E2E_03 */
                                , CalculatedLength - CalculatedOffset - 1u
                                , crc
                                , FALSE
                                );
    }

    /* #50 Revert final XOR of CRC routine */
    return crc ^ 0xffu;
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
E2E_LOCAL FUNC (void, E2E_CODE) E2E_CheckDeltaCounter(P2CONST (E2E_P01ConfigType, AUTOMATIC, E2E_APPL_CONST) ConfigPtr,
                                                      P2VAR (E2E_P01CheckStateType, AUTOMATIC, E2E_APPL_DATA) StatePtr,
                                                      VAR (uint8, AUTOMATIC) ReceivedCounter)
{
    /* #10 Calculate delta between received and last valid counter. Overflow is also considered */
    uint8 DeltaCounter = (uint8)(ReceivedCounter - StatePtr->LastValidCounter) & 0x0fu;
    if (StatePtr->LastValidCounter > ReceivedCounter)
    {
        DeltaCounter--;
    }
    
    /* #20 Check if counter didn't change, thus no new data was received*/
    if (DeltaCounter == 0u)
    {
        if (StatePtr->NoNewOrRepeatedDataCounter < E2E_P01_MAX_COUNTER_VALUE)
        {
            StatePtr->NoNewOrRepeatedDataCounter++; /* SBSW_E2E_03 */
        }
        StatePtr->Status = E2E_P01STATUS_REPEATED; /* SBSW_E2E_03 */
    }
    else
    {
        /* #30 If DeltaCounter equals 1, the correct data was received. No message was lost in between */
        if (DeltaCounter == 1u)
        {
            StatePtr->MaxDeltaCounter = ConfigPtr->MaxDeltaCounterInit; /* SBSW_E2E_03 */
            StatePtr->LastValidCounter = ReceivedCounter; /* SBSW_E2E_03 */
            StatePtr->LostData = 0u; /* SBSW_E2E_03 */
            StatePtr->Status = E2E_P01STATUS_OK; /* SBSW_E2E_03 */
            E2E_CheckSync (ConfigPtr, StatePtr); /* SBSW_E2E_03 */
        }
        else
        {
            /* #40 Received data is not subsequent data, but counter is still tolerable */
            if (DeltaCounter <= StatePtr->MaxDeltaCounter)
            {
                StatePtr->MaxDeltaCounter = ConfigPtr->MaxDeltaCounterInit; /* SBSW_E2E_03 */
                StatePtr->LastValidCounter = ReceivedCounter; /* SBSW_E2E_03 */
                StatePtr->LostData = DeltaCounter - 1u; /* SBSW_E2E_03 */
                StatePtr->Status = E2E_P01STATUS_OKSOMELOST; /* SBSW_E2E_03 */
                E2E_CheckSync (ConfigPtr, StatePtr); /* SBSW_E2E_03 */
            }
            /* #50 Counter of received data is out of range */
            else
            {
                StatePtr->NoNewOrRepeatedDataCounter = 0u; /* SBSW_E2E_03 */
                StatePtr->SyncCounter = ConfigPtr->SyncCounterInit; /* SBSW_E2E_03 */
                if (StatePtr->SyncCounter > 0u)
                {
                    StatePtr->MaxDeltaCounter = ConfigPtr->MaxDeltaCounterInit; /* SBSW_E2E_03 */
                    StatePtr->LastValidCounter = ReceivedCounter; /* SBSW_E2E_03 */
                }
                StatePtr->Status = E2E_P01STATUS_WRONGSEQUENCE; /* SBSW_E2E_03 */
            }
        }
    }
}

/**********************************************************************************************************************
 *  E2E_CheckSync()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
E2E_LOCAL FUNC (void, E2E_CODE) E2E_CheckSync(P2CONST (E2E_P01ConfigType, AUTOMATIC, E2E_APPL_CONST) ConfigPtr,
                                              P2VAR (E2E_P01CheckStateType, AUTOMATIC, E2E_APPL_DATA) StatePtr)
{
    /* #10 Check if NoNewOrRepeatedDataCounter didn't reach its limit */
    if (StatePtr->NoNewOrRepeatedDataCounter <= ConfigPtr->MaxNoNewOrRepeatedData)
    {
        StatePtr->NoNewOrRepeatedDataCounter = 0u; /* SBSW_E2E_03 */

        /* #20 Status is STATUS_SYNC in case SyncCounter is greater than 0 */
        if (StatePtr->SyncCounter > 0u)
        {
            StatePtr->SyncCounter--; /* SBSW_E2E_03 */
            StatePtr->Status = E2E_P01STATUS_SYNC; /* SBSW_E2E_03 */
        }
    }
    else
    {
        StatePtr->NoNewOrRepeatedDataCounter = 0u; /* SBSW_E2E_03 */
        StatePtr->SyncCounter = ConfigPtr->SyncCounterInit; /* SBSW_E2E_03 */
        StatePtr->Status = E2E_P01STATUS_SYNC; /* SBSW_E2E_03 */
    }
}

/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 **********************************************************************************************************************/

/**********************************************************************************************************************
 *  E2E_P01Protect()
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
 */
FUNC (Std_ReturnType, E2E_CODE) E2E_P01Protect (P2CONST(E2E_P01ConfigType, AUTOMATIC, E2E_APPL_CONST) ConfigPtr,
                                                P2VAR(E2E_P01ProtectStateType, AUTOMATIC, E2E_APPL_DATA) StatePtr,
                                                P2VAR(uint8, AUTOMATIC, E2E_APPL_DATA) DataPtr)
{
    /* #10 Check validity of input parameters */
    Std_ReturnType ret = E2E_P01ProtectVerifyInputs (ConfigPtr, StatePtr, DataPtr); /* SBSW_E2E_03 */

    if (ret == E2E_E_OK)
    {
        uint8 ComputedCRC;
        uint16 ComputedOffset = ConfigPtr->CounterOffset >> 3u;
        /* #20 Counter is written to position in DataPtr, Offset is pointing to */
        /* #21 Write value of Counter to low nibble in DataPtr, ComputedOffset is pointing to */
        if ((ConfigPtr->CounterOffset & 0x07) == 0u)
        {
            DataPtr[ComputedOffset] = (DataPtr[ComputedOffset] & 0xf0u) /* SBSW_E2E_03 */
                                    | StatePtr->Counter;    
        }
        /* #22 Write value of Counter to high nibble in DataPtr, ComputedOffset is pointing to */
        else
        {
            DataPtr[ComputedOffset] = (DataPtr[ComputedOffset] & 0x0fu) /* SBSW_E2E_03 */
                                    | ((StatePtr->Counter << 4u) & 0xf0u);
        }
        /* #30 DataID is written to DataPtr, where DataIDNibbleOffset is pointing to, if DataIDMode equals DATAID_NIBBLE */
        if (ConfigPtr->DataIDMode == E2E_P01_DATAID_NIBBLE)
        {
            ComputedOffset = ConfigPtr->DataIDNibbleOffset >> 3u;
            /* #31 Write low nibble of high byte of DataID to low nibble in DataPtr, ComputedOffset is pointing to */
            if ((ConfigPtr->DataIDNibbleOffset & 0x07) == 0u)
            {
                DataPtr[ComputedOffset] = ( (DataPtr[ComputedOffset] & 0xf0u)   /* SBSW_E2E_03 */
                                          | ((uint8)(ConfigPtr->DataID >> 8u) & 0x0fu)
                                          );
            }
            /* #32 Write low nibble of high byte of DataID to high nibble in DataPtr, ComputedOffset is pointing to */
            else
            {
                DataPtr[ComputedOffset] = ( (DataPtr[ComputedOffset] & 0x0fu)   /* SBSW_E2E_03 */
                                          | ((uint8)(ConfigPtr->DataID >> 4u) & 0xf0u)
                                          );
            }
        }
        /* #40 Compute CRC8 over DataPtr including Counter and DataID */
        ComputedCRC = E2E_P01ComputeCRC ( DataPtr, ConfigPtr, StatePtr->Counter); /* SBSW_E2E_03 */

        /* #50 Write computed CRC to DataPtr, where CRCOffset is pointing to */
        DataPtr[ConfigPtr->CRCOffset >> 3u] = ComputedCRC; /* SBSW_E2E_03 */

        /* #60 Increment value of Counter. Valid values are 0..14 */
        StatePtr->Counter = (StatePtr->Counter + 1u) % (E2E_P01_MAX_COUNTER_VALUE + 1); /* SBSW_E2E_03 */
    }
    return ret;
}
 
/**********************************************************************************************************************
 *  E2E_P01ProtectInit()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FUNC (Std_ReturnType, E2E_CODE) E2E_P01ProtectInit (P2VAR(E2E_P01ProtectStateType, AUTOMATIC, E2E_APPL_DATA) StatePtr)
{
    Std_ReturnType ret = E2E_E_INPUTERR_NULL;

    /* #10 Reset Counter value in case StatePtr is valid */
    if (StatePtr != NULL_PTR)
    {
        StatePtr->Counter = 0u; /* SBSW_E2E_03 */
        ret = E2E_E_OK;
    }

    return ret;
}
 
/**********************************************************************************************************************
 *  E2E_P01Check()
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
FUNC (Std_ReturnType, E2E_CODE) E2E_P01Check (P2CONST(E2E_P01ConfigType, AUTOMATIC, E2E_APPL_CONST) ConfigPtr,
                                              P2VAR(E2E_P01CheckStateType, AUTOMATIC, E2E_APPL_DATA) StatePtr,
                                              P2CONST (uint8, AUTOMATIC, E2E_APPL_DATA) DataPtr)
{
    /* #10 Check validity of input parameters */
    Std_ReturnType ret = E2E_P01CheckVerifyInputs(ConfigPtr, StatePtr, DataPtr); /* SBSW_E2E_03 */

    if (ret == E2E_E_OK)
    {
        uint8 ReceivedCounter;
        uint8 ReceivedDataIDNibble = 0u;
        uint8 ComputedCRC;
        uint8 ReceivedCRC;
        uint16 ComputedOffset;

        /* #20 Maximum allowed delta between previous and current counter is incremented every function invocation */
        if (StatePtr->MaxDeltaCounter < E2E_P01_MAX_COUNTER_VALUE)
        {
            StatePtr->MaxDeltaCounter++; /* SBSW_E2E_03 */
        }
        /* #30 Check if new data is available */
        if (StatePtr->NewDataAvailable == TRUE)
        {
            ComputedOffset  = ConfigPtr->CounterOffset >> 3u;
            /* #40 Counter is read from Data, at the configured offset */
            if ((ConfigPtr->CounterOffset & 0x07u) == 0u)
            {
                ReceivedCounter = DataPtr[ComputedOffset] & 0x0fu;
            }
            else
            {
                ReceivedCounter = (DataPtr[ComputedOffset] & 0xf0u) >> 4u;            
            }

            /* #50 CRC is read from Data */
            ComputedOffset  = ConfigPtr->CRCOffset >> 3u;
            ReceivedCRC     = DataPtr[ComputedOffset];

            /* #60 Read low nibble of high byte of DataID from Data in case DATAID_NIBBLE is configured */
            if (ConfigPtr->DataIDMode == E2E_P01_DATAID_NIBBLE)
            {
                ComputedOffset = ConfigPtr->DataIDNibbleOffset >> 3u;
                if ((ConfigPtr->DataIDNibbleOffset & 0x7u) == 0u)
                {
                    ReceivedDataIDNibble = DataPtr[ComputedOffset] & 0x0fu;
                }
                else
                {
                    ReceivedDataIDNibble = (DataPtr[ComputedOffset] & 0xf0u) >> 4u;
                }
            }
            /* #70 Calculate CRC in the same way as the Sender did */
            ComputedCRC = E2E_P01ComputeCRC(DataPtr, ConfigPtr, ReceivedCounter); /* SBSW_E2E_03 */

            /* #80 Check if received nibble is identical to the one in DataID */
            if (  (ConfigPtr->DataIDMode == E2E_P01_DATAID_NIBBLE)
               && (ReceivedDataIDNibble != ((ConfigPtr->DataID >> 8u) & 0x0fu))
               )
            {
                StatePtr->Status = E2E_P01STATUS_WRONGCRC; /* SBSW_E2E_03 */
            }
            else
            {
                /* #90 Check if received CRC matches the computed one */
                if (ReceivedCRC == ComputedCRC)
                {
                    /* #100 Check if any correct data has already been received */
                    if (StatePtr->WaitForFirstData == FALSE)
                    {
                        /* #110 Evaluate counter value of subsequent data */
                        E2E_CheckDeltaCounter (ConfigPtr, StatePtr, ReceivedCounter); /* SBSW_E2E_03 */
                    }
                    else
                    {
                        StatePtr->WaitForFirstData = FALSE; /* SBSW_E2E_03 */
                        StatePtr->MaxDeltaCounter = ConfigPtr->MaxDeltaCounterInit; /* SBSW_E2E_03 */
                        StatePtr->LastValidCounter = ReceivedCounter; /* SBSW_E2E_03 */
                        StatePtr->Status = E2E_P01STATUS_INITIAL; /* SBSW_E2E_03 */
                    }
                }
                else
                {
                    StatePtr->Status = E2E_P01STATUS_WRONGCRC; /* SBSW_E2E_03 */
                }
            }
        }
        else
        {
            if (StatePtr->NoNewOrRepeatedDataCounter < E2E_P01_MAX_COUNTER_VALUE)
            {
                StatePtr->NoNewOrRepeatedDataCounter++; /* SBSW_E2E_03 */
            }
            StatePtr->Status = E2E_P01STATUS_NONEWDATA; /* SBSW_E2E_03 */
        }
    }

    return ret;
} /* PRQA S 6030, 6080 */ /* MD_MSR_STCYC, MD_MSR_STMIF */

/**********************************************************************************************************************
 *  E2E_P01CheckInit()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FUNC (Std_ReturnType, E2E_CODE) E2E_P01CheckInit (P2VAR (E2E_P01CheckStateType, AUTOMATIC, E2E_APPL_DATA) StatePtr)
{
    Std_ReturnType ret = E2E_E_INPUTERR_NULL;

    /* #10 Reset State structure in case StatePtr is valid */
    if (StatePtr != NULL_PTR)
    {
        StatePtr->LastValidCounter           = 0u; /* SBSW_E2E_03 */
        StatePtr->MaxDeltaCounter            = 0u; /* SBSW_E2E_03 */
        StatePtr->WaitForFirstData           = TRUE; /* SBSW_E2E_03 */
        StatePtr->NewDataAvailable           = FALSE; /* SBSW_E2E_03 */
        StatePtr->LostData                   = 0u; /* SBSW_E2E_03 */
        StatePtr->Status                     = E2E_P01STATUS_NONEWDATA; /* SBSW_E2E_03 */
        StatePtr->NoNewOrRepeatedDataCounter = 0u; /* SBSW_E2E_03 */
        StatePtr->SyncCounter                = 0u; /* SBSW_E2E_03 */
        ret = E2E_E_OK;
    }

    return ret;
}

/**********************************************************************************************************************
 *  E2E_P01MapStatusToSM()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
FUNC (E2E_PCheckStatusType, E2E_CODE) E2E_P01MapStatusToSM (VAR (Std_ReturnType, AUTOMATIC) CheckReturn,
                                                            VAR (E2E_P01CheckStatusType, AUTOMATIC) Status,
                                                            VAR (boolean, AUTOMATIC) profileBehavior)
{
    E2E_PCheckStatusType ret = E2E_P_ERROR;

    /* #10 Status is only mapped to state machine if check-function returned successfully */
    if (CheckReturn == E2E_E_OK)
    {
        /* #20 SYNC and INITIAL status are set according to profileBehavior. Either the legacy behavior (before R4.2) or new behavior is chosen */
        E2E_PCheckStatusType sync_ret = E2E_P_OK;
        E2E_PCheckStatusType init_ret = E2E_P_WRONGSEQUENCE;
        if (profileBehavior == FALSE)
        {
            sync_ret = E2E_P_WRONGSEQUENCE;        
            init_ret = E2E_P_OK;
        }
    
        /* #30 Status of Profile 1 is mapped to state machine status, which is not that fine-grained */
        switch (Status)
        {
            case E2E_P01STATUS_OK           : ret = E2E_P_OK;            break;
            case E2E_P01STATUS_NONEWDATA    : ret = E2E_P_REPEATED;      break;
            case E2E_P01STATUS_WRONGCRC     : ret = E2E_P_ERROR;         break;
            case E2E_P01STATUS_SYNC         : ret = sync_ret;            break;
            case E2E_P01STATUS_INITIAL      : ret = init_ret;            break;
            case E2E_P01STATUS_REPEATED     : ret = E2E_P_REPEATED;      break;
            case E2E_P01STATUS_OKSOMELOST   : ret = E2E_P_OK;            break;
            case E2E_P01STATUS_WRONGSEQUENCE: ret = E2E_P_WRONGSEQUENCE; break;
            default: break; /* PRQA S 2018 */ /* MD_EtoE_14.1 */
        }
    }

    return ret;    
} /* PRQA S 6030 */ /* MD_MSR_STCYC */

#define E2E_STOP_SEC_CODE
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/**********************************************************************************************************************
 *  END OF FILE: E2E_P01.c
 *********************************************************************************************************************/
