/**
*  \file
*
*  \brief       Read and write ECU data.
*
*  This file contains functions to read and write ECU related data.
*
*  \project     BMW Platform Software
*
*  \copyright   BMW AG 2015 - 2017
*
*  \version     5.3.1
*
*/

/*------------------------------------------------------------------------------
                      Include Section
-------------------------------------------------------------------------------*/

/* -------------------------------------------------------------------------- */
#include "Dlog_Ecu.h"          /* module own header file                      */

#if (DLOG_ENABLE_ECU == STD_ON)

/* -------------------------------------------------------------------------- */
#include "Dlog_PBCfg.h"
#include "Dlog_Nvm.h"
#include "Dlog_Swe.h"
#include "Dlog_HweTable.h"
#include "Dlog_Data.h"
#include <string.h>

#if ( DLOG_ENABLE_RTE == STD_ON )
#include "Rte_Dlog.h"
#else
#include "Dlog_Rte2C.h"
#endif

#include "BUtil_ByteMask.h"

/* -------------------------------------------------------------------------- */


/*------------------------------------------------------------------------------
                      MISRA-Deviations
------------------------------------------------------------------------------*/

/* Violation of MISRA rule 17.4. Reason: RTE uses pointers for arrays, see PRQA: 0492 */

/* Violation of MISRA Rule 14.2. Reason: void cast for unused parameter, see PRQA: 3112 */

/* Violation of MISRA rule 14.7. Reason: early return in case of errors makes code more readable,
   see PRQA: 2006, 5207 */

/* Violation of MISRA Rule 16.7. Reason: parameter given by Autosar, see PRQA: 3673 */

/* Violation of MISRA rule 19.1. Reason: Including Dlog_MemMap.h is necessary throughout
   the file according to memory abstraction, see PRQA: 5087 */


/*------------------------------------------------------------------------------
                        Local Macros
-------------------------------------------------------------------------------*/

/* check version of the module */
#if (!DlogClassic_CHECK_VERSION(5,3,1))
   #error "Version of Dlog_Ecu.c does not match the version of the module!"
#endif

/**
 * initial value of VIN
 */
#define DLOG_VIN_INITIAL                                                   0x30u


/*------------------------------------------------------------------------------
                      Global Variables
-------------------------------------------------------------------------------*/

#define Dlog_START_SEC_VAR_SAVED_ZONE_UNSPECIFIED
#include "Dlog_MemMap.h"  /* PRQA S 5087 */

VAR(Dlog_ProgDataType, Dlog_VAR_NOINIT) Dlog_ProgData;

#define Dlog_STOP_SEC_VAR_SAVED_ZONE_UNSPECIFIED
#include "Dlog_MemMap.h"  /* PRQA S 5087 */

#define Dlog_START_SEC_VAR_NO_INIT_8
#include "Dlog_MemMap.h"  /* PRQA S 5087 */

VAR(uint8, Dlog_VAR_NOINIT) Dlog_FingerprintInRam[DLOG_FINGERPRINTLENGTH];
                                            /* reserved memory for the        */
                                            /* temporary, new fingerprint     */

#define Dlog_STOP_SEC_VAR_NO_INIT_8
#include "Dlog_MemMap.h"  /* PRQA S 5087 */


/*------------------------------------------------------------------------------
                      Local Functions Prototypes
-------------------------------------------------------------------------------*/

#define Dlog_START_SEC_CODE
#include "Dlog_MemMap.h"  /* PRQA S 5087 */

/*------------------------------------------------------------------------------
                      Local Functions
-------------------------------------------------------------------------------*/


/*------------------------------------------------------------------------------
                      Global Functions
-------------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/**
 * Initialize 'Dlog_ProgData' struct with default data.
 *
 * \global #Dlog_ProgData
 *
 * \return Always E_OK
 *
 * \remark This function is called from bootloader and application.
 *
 * \swsid SWS_Dlog_0484
 *
 */
/*----------------------------------------------------------------------------*/
Std_ReturnType Dlog_InitProgData( void ) {
   /* write initial fingerprint into Dlog_ProgData                             */
   (void)memcpy( &Dlog_ProgData.FingerPrint[0],
                        &Dlog_CommonLogisticBtld.FINGERPRINT_INIT_VAL[0],
                        sizeof(Dlog_ProgData.FingerPrint)
                      );

   /* set VIN to init value                                                   */
   (void)memset( &Dlog_ProgData.VIN[0],
                        DLOG_VIN_INITIAL,
                        sizeof(Dlog_ProgData.VIN)
                      );

   return E_OK;
} /* end of function 'Dlog_InitProgData'                                      */

/*----------------------------------------------------------------------------*/
/**
 * Function returns the Manufacturing Data of an ECU for a
 * ReadDataByIdentifier Request. This API fulfills the API
 * that the Dcm expects when connected to the DLOG SWC for
 * its required Port of Type ClientServerInterface
 * DataServices_<Data>.
 *
 * \param[out] Data Manufacturing Data
 *
 * \return Always E_OK
 *
 * \pre The DLOG NV-Data has been read into the RAM mirror
 *
 * \lhref FL170
 *
 */
/*----------------------------------------------------------------------------*/
/**
 *
 * Description of response out parameter data:
 * Offset | Value | Description
 * ------ | ----- | -----------------
 *    0   |  0xYY | Year (BCD 01..99)
 *    1   |  0xMM | Month (BCD 01..12)
 *    2   |  0xDD | Day (BCD 01..31)
 * \lhref FL914,FL915,FL916,FL918
 *
 */
/*----------------------------------------------------------------------------*/
Std_ReturnType Dlog_ReadDataByIdentifierManufacturingDate(uint8* Data) {
   /* copy ECUManufacturingData to response                                   */
   (void)memcpy( Data,
                 &Dlog_Data.hwData->ECUManufacturingDate[0],
                 sizeof(Dlog_Data.hwData->ECUManufacturingDate)
               );
   return E_OK;
}

/*----------------------------------------------------------------------------*/
/**
 * Contains the functionality of the diag service
 * ReadDataByIdentifier (0x22) - DIAG_DID_F18C_ECU_SERIAL_NUMBER
 * Read the ECU SerialNumber.
 *
 * \param[out] Data Ecu Serial Number
 *
 * \return Always E_OK
 *
 * \pre The DLOG NV-Data has been read into the RAM mirror
 *
 * \lhref FL164
 *
 */
/*----------------------------------------------------------------------------*/
/**
 *
 * Description of response out parameter data:
 * Offset | Value      | Description
 * ------ | ---------- | -----------------
 *    0   | 0x30..0x39 | ECU Serial Number, 1st digit
 *    1   | 0x30..0x39 | ECU Serial Number, 2nd digit
 *   ...  |     ...    | ...
 *    9   | 0x30..0x39 | ECU Serial Number, 10th digit
 * \lhref FL907,FL908,FL909,FL910
 *
 */
/*----------------------------------------------------------------------------*/
Std_ReturnType Dlog_ReadDataByIdentifierEcuSerialNumber(uint8* Data) {
   /* copy EcuSerialNumber to response                                        */
   (void)memcpy( Data,
                 &Dlog_Data.hwData->ECUSerialNumber[0],
                 sizeof(Dlog_Data.hwData->ECUSerialNumber)
               );
   return E_OK;
}

/**
 * Contains the functionality of the diag service
 * ReadDataByIdentifier (0x22) - DIAG_DID_8000_ECU_UID
 * Read the ECU UID
 *
 * \param[out] Data ECU UID
 *
 * \return Always E_OK
 *
 * \pre Dlog_Data.hwData is initialized
 *
 * \lhref SEC1427
 *
 */
Std_ReturnType Dlog_ReadDataByIdentifierEcuUid(uint8* Data) {
   /* copy EcuUid to response                                        */
   (void)memcpy( Data,
                 &Dlog_Data.hwData->ECUUID[0],
                 sizeof(Dlog_Data.hwData->ECUUID)
               );
   return E_OK;
}

/*----------------------------------------------------------------------------*/
/**
 * Contains the functionality of the diag service
 * ReadDataByIdentifier (0x22) - DIAG_DID_F152_HW_MODIFICATION_INDEX
 * Read the HW Modification Index.
 *
 * \param[out] Data HW Modification Index
 *
 * \return Always E_OK
 *
 * \lhref FL175
 *
 */
/*----------------------------------------------------------------------------*/
/**
 *
 * Description of response out parameter data:
 * Offset        | Value      | Description
 * ------------- | ---------- | -----------------
 *  0            | 0x00..0xfe | HWModificationIndex
 *  1 (bit 7..6) | 0x00..0x03 | HWModel
 *  1 (bit 5..0) | 0x00..0x3f | Supplier Info Field
 * \lhref FL924,FL925,FL926,FL927
 *
 */
/*----------------------------------------------------------------------------*/
Std_ReturnType Dlog_ReadDataByIdentifierHWModificationIndex(uint8* Data) {
   /* copy HW Modification Index to response                                  */
   (void)memcpy( Data,
                 &Dlog_Data.hwData->HWModificationIndex[0],
                 sizeof(Dlog_Data.hwData->HWModificationIndex)
               );
   return E_OK;
}



/*----------------------------------------------------------------------------*/
/**
 * Contains the condition check functionality of the diag service
 * ReadDataByIdentifier (0x22) - DIAG_DID_F190_VIN Read VIN.
 *
 * \param[in]  OpStatus    See Dcm specification
 * \param[out] ErrorCode   Contains the error code in case E_NOT_OK is returned
 *
 * \return Always E_OK
 *
 */
/*----------------------------------------------------------------------------*/
Std_ReturnType Dlog_ConditionCheckVin
               (
                  Dcm_OpStatusType OpStatus,
                  /* MISRA-C:2004 Rule 16.7: parameter given by Autosar */
                  /* PRQA S 3673 1 */
                  Dcm_NegativeResponseCodeType* ErrorCode
               )
{
   /* MISRA-C:2004 Rule 14.2: parameter needed by Autosar */
   /* PRQA S 3112 2 */
   (void)OpStatus;
   (void)ErrorCode;
   return E_OK;
}

/*----------------------------------------------------------------------------*/
/**
 * Contains the functionality of the diag service
 * ReadDataByIdentifier (0x22) - DIAG_DID_F190_VIN
 * Read VIN.
 *
 * \param[in]  OpStatus
 * \param[out] Data     VIN
 *
 * \return Always E_OK
 *
 * \pre The DLOG NV-Data has been read into the RAM mirror
 *
 * \lhref FL1068
 *
 */
/*----------------------------------------------------------------------------*/
/**
 *
 * Description of response out parameter data:
 * Offset | Value | Description
 * ------ | ----- | -----------------
 *    0   |  0x.. | VIN Digit 1 (ASCII)
 *    1   |  0x.. | VIN Digit 2 (ASCII)
 *   ...  |   ... | ...
 *   16   |  0x.. | VIN Digit 17 (ASCII)
 *
 */
/*----------------------------------------------------------------------------*/
Std_ReturnType Dlog_ReadDataByIdentifierVin(Dcm_OpStatusType OpStatus, uint8* Data) {
   /* MISRA-C:2004 Rule 14.2: parameter needed by Autosar */
   /* PRQA S 3112 1 */
   (void)OpStatus;

   /* copy VIN to response                                                    */
   (void)memcpy( Data,
                 &Dlog_ProgData.VIN[0],
                 sizeof(Dlog_ProgData.VIN)
               );
   return E_OK;
}

/*----------------------------------------------------------------------------*/
/**
 * Copies the VIN into the given buffer
 *
 * \param[out] Vin VIN
 *
 * \retval E_OK     Data is filled with the VIN
 * \retval E_NOT_OK VIN has not been written yet (the default VIN is returned in Data)
 *
 * \pre Data must be a valid pointer to a buffer of at least DLOG_VINLENGTH bytes
 *
 */
/*----------------------------------------------------------------------------*/
/* PRQA S 0492 PTAR */
Std_ReturnType Dlog_GetVin(uint8* Vin)
{
   uint8 i;
   (void)Dlog_ReadDataByIdentifierVin(DCM_INITIAL, Vin);
   for (i = 0; i < DLOG_VINLENGTH; ++i)
   {
      if (DLOG_VIN_INITIAL != Vin[i]) {
         break;
      }
   }
   if (i >= DLOG_VINLENGTH) {
      return E_NOT_OK;
   }
   return E_OK;
   /* PRQA S 2006,5207 1 */
}
/* PRQA L:PTAR */


#if (DLOG_ENABLE_ECU_WRITE_VIN == STD_ON)

/*----------------------------------------------------------------------------*/
/**
 * write VIN to EEPROM
 *
 * \global #Dlog_ProgData
 *
 * \param[in] Data VIN
 * \param[in] OpStatus
 * \param[out] ErrorCode
 *
 * \retval E_OK     VIN successfully written
 * \retval E_NOT_OK An error occurred
 *
 */
/*----------------------------------------------------------------------------*/
/**
 *
 * Description of request in parameter Data:
 * Offset |  Value                               |  Description
 * ------ | ------------------------------------ | -----------------
 *     0  |  (ASCII: 'A' to 'Z' and '0' to '9')  | VIN Digit 1
 *     1  |  (ASCII: 'A' to 'Z' and '0' to '9')  | VIN Digit 2
 *   ...  |  ...                                 | ...
 *    16  |  (ASCII: 'A' to 'Z' and '0' to '9')  | VIN Digit 17
 * \lhref FL1063,FL1064
 *
 */
/*----------------------------------------------------------------------------*/
/* PRQA S 0492 PTAR */
Std_ReturnType Dlog_WriteDataByIdentifierVin
      (
            const uint8* Data,
            Dcm_OpStatusType OpStatus,
            Dcm_NegativeResponseCodeType* ErrorCode
      )
{
   uint8_least iLoop;

   if (DCM_PENDING == OpStatus) {
      Dlog_NvmBlockState state = Dlog_WriteNvmBlockAsync(DLOG_NVM_BLOCK_PROG_DATA,
         (Dlog_NvmMirrorPtr)&Dlog_ProgData,
         DLOG_PENDING
         );
      switch (state)
      {
      case DLOG_NVM_OK:
         return E_OK;
      case DLOG_NVM_PENDING:
         return RTE_E_DataServices_Vin_DCM_E_PENDING;
      default:
         *ErrorCode = DCM_E_GENERALPROGRAMMINGFAILURE;
         return E_NOT_OK;
      }
   }

   /* check values of VIN: only 'A' to 'Z' and '0' to '9' is valid            */
   iLoop = (uint8_least)0x00u;
   while ( ( ((Data[iLoop] >= 'A') && (Data[iLoop] <= 'Z')) ||
             ((Data[iLoop] >= '0') && (Data[iLoop] <= '9'))
           ) &&
           (iLoop < (uint8_least)sizeof(Dlog_ProgData.VIN))
         )
   {
      ++iLoop;
   }

   if ( iLoop < (uint8_least)sizeof(Dlog_ProgData.VIN) )
   {
      /* invalid digit found in VIN                                           */
      *ErrorCode = DCM_E_REQUESTOUTOFRANGE;
      return E_NOT_OK;
   }

   /** preconditions are correct                                          **/

   (void)memcpy( &Dlog_ProgData.VIN[0],
                 &Data[0],
                 sizeof(Dlog_ProgData.VIN)
               );

   if ( DLOG_NVM_PENDING != Dlog_WriteNvmBlockAsync(DLOG_NVM_BLOCK_PROG_DATA,
                                   (Dlog_NvmMirrorPtr)&Dlog_ProgData,
                                   DLOG_INITIAL
                                  )
      )
   {
      /* writing failed - set negative response                            */
      *ErrorCode = DCM_E_GENERALPROGRAMMINGFAILURE;
      return E_NOT_OK;
   }

   return RTE_E_DataServices_Vin_DCM_E_PENDING;
   /* PRQA S 2006,5207 1 */
} /* end of function 'ApplDcmWriteDataByIdentifierVin'                        */
/* PRQA L:PTAR */

#endif /* #if (DLOG_ENABLE_ECU_WRITE_VIN == STD_ON) */

/*----------------------------------------------------------------------------*/
/**
 * Returns the ECU Id.
 *
 * \global_r Dlog_PBConfigSetPtr->EcuId
 *
 * \param[out] ecuId ECU Id
 *
 * \return Always E_OK
 *
 */
/*----------------------------------------------------------------------------*/
Std_ReturnType Dlog_GetEcuId(uint8* ecuId)
{
   *ecuId = Dlog_PBConfigSetPtr->EcuId;
   return E_OK;
}


#define Dlog_STOP_SEC_CODE
#include "Dlog_MemMap.h"  /* PRQA S 5087 */

#endif /* #if (DLOG_ENABLE_ECU == STD_ON) */
