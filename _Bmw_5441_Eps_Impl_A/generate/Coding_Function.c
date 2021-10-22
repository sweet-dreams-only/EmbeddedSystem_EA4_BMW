/**
 * \file
 *
 * \brief       Coding Function
 *
 * \project     BMW Platform Software
 *
 * \copyright   BMW AG 2016 - 2017
 *
 * \version     5.2.1
 *
 */

/*------------------------------------------------------------------------------
*
*  THIS FILE WAS GENERATED. DO NOT MODIFY!
*
*  GENERATOR       : BMW PAGe 1.1.0
*
*  GENERATION TIME : 2018-07-30 19:57:40.558144
*
------------------------------------------------------------------------------*/

/*------------------------------------------------------------------------------
                      Include Section
------------------------------------------------------------------------------*/

#include "Coding_Data.h"     /* The NvM data is defined here */
#include "Coding_Function.h"


/*------------------------------------------------------------------------------
                      Macros
------------------------------------------------------------------------------*/

/**
 * \brief check version of the module
 */
#if (!Coding_CHECK_VERSION(5,2,1))
  #error "Version of Coding_Function.c does not match the version of the module!"
#endif


/*------------------------------------------------------------------------------
                      Local Data Types
------------------------------------------------------------------------------*/

/**
 * \brief The following union is used to convert raw bytes to float32
 */
union Coding_FloatConvert
{ /* PRQA S 0750 */
   float32 val; /* PRQA S 3629 */
   uint8 byteVal[4];
};

/**
 * \brief The following union is used to convert raw bytes to float64
 */
union Coding_DoubleConvert
{ /* PRQA S 0750 */
   float64 val; /* PRQA S 3629 */
   uint8 byteVal[8];
};


/*------------------------------------------------------------------------------
                      Global Functions
------------------------------------------------------------------------------*/

#define Coding_START_SEC_CODE
#include "Coding_MemMap.h" /* PRQA S 5087 */



/*----------------------------------------------------------------------------*/
/**
 * Function to get current Coding data value of 'NAME00_00_CalculationOfLoadMinusstateMinusdependentSteeringAssistance'
 *
 * - Application Type....: boolean
 * - Nvram Type..........: boolean
 */
/*----------------------------------------------------------------------------*/
Coding_ReturnType Coding_GetNAME00_00_CalculationOfLoadMinusstateMinusdependentSteeringAssistance(boolean *funcVal)
{
   Coding_ReturnType retVal;

   retVal = Coding_GetAccessPermission();

   if ( CODING_RC_OK == retVal )
   {
      *funcVal = ( ( ( Coding_CodingData[ 0u ] & 0x01u ) >> 0x00u ) == 0u ) ? FALSE : TRUE;
   }

   return ( retVal );
}

/*----------------------------------------------------------------------------*/
/**
 * Function to get current Coding data value of 'NAME00_01_CalculationOfActiveReturn'
 *
 * - Application Type....: boolean
 * - Nvram Type..........: boolean
 */
/*----------------------------------------------------------------------------*/
Coding_ReturnType Coding_GetNAME00_01_CalculationOfActiveReturn(boolean *funcVal)
{
   Coding_ReturnType retVal;

   retVal = Coding_GetAccessPermission();

   if ( CODING_RC_OK == retVal )
   {
      *funcVal = ( ( ( Coding_CodingData[ 0u ] & 0x02u ) >> 0x01u ) == 0u ) ? FALSE : TRUE;
   }

   return ( retVal );
}

/*----------------------------------------------------------------------------*/
/**
 * Function to get current Coding data value of 'NAME00_02_reserved'
 *
 * - Application Type....: boolean
 * - Nvram Type..........: boolean
 */
/*----------------------------------------------------------------------------*/
Coding_ReturnType Coding_GetNAME00_02_reserved(boolean *funcVal)
{
   Coding_ReturnType retVal;

   retVal = Coding_GetAccessPermission();

   if ( CODING_RC_OK == retVal )
   {
      *funcVal = ( ( ( Coding_CodingData[ 0u ] & 0x04u ) >> 0x02u ) == 0u ) ? FALSE : TRUE;
   }

   return ( retVal );
}

/*----------------------------------------------------------------------------*/
/**
 * Function to get current Coding data value of 'NAME00_03_ActiveInfluenceOnTheSteeringHysterisis'
 *
 * - Application Type....: boolean
 * - Nvram Type..........: boolean
 */
/*----------------------------------------------------------------------------*/
Coding_ReturnType Coding_GetNAME00_03_ActiveInfluenceOnTheSteeringHysterisis(boolean *funcVal)
{
   Coding_ReturnType retVal;

   retVal = Coding_GetAccessPermission();

   if ( CODING_RC_OK == retVal )
   {
      *funcVal = ( ( ( Coding_CodingData[ 0u ] & 0x08u ) >> 0x03u ) == 0u ) ? FALSE : TRUE;
   }

   return ( retVal );
}

/*----------------------------------------------------------------------------*/
/**
 * Function to get current Coding data value of 'NAME00_04_reserved'
 *
 * - Application Type....: boolean
 * - Nvram Type..........: boolean
 */
/*----------------------------------------------------------------------------*/
Coding_ReturnType Coding_GetNAME00_04_reserved(boolean *funcVal)
{
   Coding_ReturnType retVal;

   retVal = Coding_GetAccessPermission();

   if ( CODING_RC_OK == retVal )
   {
      *funcVal = ( ( ( Coding_CodingData[ 0u ] & 0x10u ) >> 0x04u ) == 0u ) ? FALSE : TRUE;
   }

   return ( retVal );
}

/*----------------------------------------------------------------------------*/
/**
 * Function to get current Coding data value of 'NAME00_05_reserved'
 *
 * - Application Type....: boolean
 * - Nvram Type..........: boolean
 */
/*----------------------------------------------------------------------------*/
Coding_ReturnType Coding_GetNAME00_05_reserved(boolean *funcVal)
{
   Coding_ReturnType retVal;

   retVal = Coding_GetAccessPermission();

   if ( CODING_RC_OK == retVal )
   {
      *funcVal = ( ( ( Coding_CodingData[ 0u ] & 0x20u ) >> 0x05u ) == 0u ) ? FALSE : TRUE;
   }

   return ( retVal );
}

/*----------------------------------------------------------------------------*/
/**
 * Function to get current Coding data value of 'NAME00_06_reserved'
 *
 * - Application Type....: boolean
 * - Nvram Type..........: boolean
 */
/*----------------------------------------------------------------------------*/
Coding_ReturnType Coding_GetNAME00_06_reserved(boolean *funcVal)
{
   Coding_ReturnType retVal;

   retVal = Coding_GetAccessPermission();

   if ( CODING_RC_OK == retVal )
   {
      *funcVal = ( ( ( Coding_CodingData[ 0u ] & 0x40u ) >> 0x06u ) == 0u ) ? FALSE : TRUE;
   }

   return ( retVal );
}

/*----------------------------------------------------------------------------*/
/**
 * Function to get current Coding data value of 'NAME00_07_reserved'
 *
 * - Application Type....: boolean
 * - Nvram Type..........: boolean
 */
/*----------------------------------------------------------------------------*/
Coding_ReturnType Coding_GetNAME00_07_reserved(boolean *funcVal)
{
   Coding_ReturnType retVal;

   retVal = Coding_GetAccessPermission();

   if ( CODING_RC_OK == retVal )
   {
      *funcVal = ( ( ( Coding_CodingData[ 0u ] & 0x80u ) >> 0x07u ) == 0u ) ? FALSE : TRUE;
   }

   return ( retVal );
}

/*----------------------------------------------------------------------------*/
/**
 * Function to get current Coding data value of 'CurrentLimit'
 *
 * - Application Type....: uint8
 * - Nvram Type..........: uint8
 */
/*----------------------------------------------------------------------------*/
Coding_ReturnType Coding_GetCurrentLimit(uint8 *funcVal)
{
   Coding_ReturnType retVal;

   retVal = Coding_GetAccessPermission();

   if ( CODING_RC_OK == retVal )
   {
      *funcVal = (uint8) ((uint8)((uint8)((Coding_CodingData[1u] & 0xFFu) >> 0x00u)));
   }

   return ( retVal );
}

/*----------------------------------------------------------------------------*/
/**
 * Function to get current Coding data value of 'SpeedMinuslimitForMaxCurrent'
 *
 * - Application Type....: uint8
 * - Nvram Type..........: uint8
 */
/*----------------------------------------------------------------------------*/
Coding_ReturnType Coding_GetSpeedMinuslimitForMaxCurrent(uint8 *funcVal)
{
   Coding_ReturnType retVal;

   retVal = Coding_GetAccessPermission();

   if ( CODING_RC_OK == retVal )
   {
      *funcVal = (uint8) ((uint8)((uint8)((Coding_CodingData[2u] & 0xFFu) >> 0x00u)));
   }

   return ( retVal );
}

/*----------------------------------------------------------------------------*/
/**
 * Function to get current Coding data value of 'NAME08_reserved'
 *
 * - Application Type....: uint8
 * - Nvram Type..........: uint8
 */
/*----------------------------------------------------------------------------*/
Coding_ReturnType Coding_GetNAME08_reserved(uint8 *funcVal)
{
   Coding_ReturnType retVal;

   retVal = Coding_GetAccessPermission();

   if ( CODING_RC_OK == retVal )
   {
      *funcVal = (uint8) ((uint8)((uint8)((Coding_CodingData[3u] & 0xFFu) >> 0x00u)));
   }

   return ( retVal );
}

/*----------------------------------------------------------------------------*/
/**
 * Function to get current Coding data value of 'NAME09_reserved'
 *
 * - Application Type....: uint8
 * - Nvram Type..........: uint8
 */
/*----------------------------------------------------------------------------*/
Coding_ReturnType Coding_GetNAME09_reserved(uint8 *funcVal)
{
   Coding_ReturnType retVal;

   retVal = Coding_GetAccessPermission();

   if ( CODING_RC_OK == retVal )
   {
      *funcVal = (uint8) ((uint8)((uint8)((Coding_CodingData[4u] & 0xFFu) >> 0x00u)));
   }

   return ( retVal );
}

/*----------------------------------------------------------------------------*/
/**
 * Function to get current Coding data value of 'NAME10_reserved'
 *
 * - Application Type....: uint8
 * - Nvram Type..........: uint8
 */
/*----------------------------------------------------------------------------*/
Coding_ReturnType Coding_GetNAME10_reserved(uint8 *funcVal)
{
   Coding_ReturnType retVal;

   retVal = Coding_GetAccessPermission();

   if ( CODING_RC_OK == retVal )
   {
      *funcVal = (uint8) ((uint8)((uint8)((Coding_CodingData[5u] & 0xFFu) >> 0x00u)));
   }

   return ( retVal );
}

/*----------------------------------------------------------------------------*/
/**
 * Function to get current Coding data value of 'NAME11_reserved'
 *
 * - Application Type....: uint8
 * - Nvram Type..........: uint8
 */
/*----------------------------------------------------------------------------*/
Coding_ReturnType Coding_GetNAME11_reserved(uint8 *funcVal)
{
   Coding_ReturnType retVal;

   retVal = Coding_GetAccessPermission();

   if ( CODING_RC_OK == retVal )
   {
      *funcVal = (uint8) ((uint8)((uint8)((Coding_CodingData[6u] & 0xFFu) >> 0x00u)));
   }

   return ( retVal );
}

/*----------------------------------------------------------------------------*/
/**
 * Function to get current Coding data value of 'NAME12_reserved'
 *
 * - Application Type....: uint8
 * - Nvram Type..........: uint8
 */
/*----------------------------------------------------------------------------*/
Coding_ReturnType Coding_GetNAME12_reserved(uint8 *funcVal)
{
   Coding_ReturnType retVal;

   retVal = Coding_GetAccessPermission();

   if ( CODING_RC_OK == retVal )
   {
      *funcVal = (uint8) ((uint8)((uint8)((Coding_CodingData[7u] & 0xFFu) >> 0x00u)));
   }

   return ( retVal );
}

/*----------------------------------------------------------------------------*/
/**
 * Function to get current Coding data value of 'NAME13_reserved'
 *
 * - Application Type....: uint8
 * - Nvram Type..........: uint8
 */
/*----------------------------------------------------------------------------*/
Coding_ReturnType Coding_GetNAME13_reserved(uint8 *funcVal)
{
   Coding_ReturnType retVal;

   retVal = Coding_GetAccessPermission();

   if ( CODING_RC_OK == retVal )
   {
      *funcVal = (uint8) ((uint8)((uint8)((Coding_CodingData[8u] & 0xFFu) >> 0x00u)));
   }

   return ( retVal );
}

/*----------------------------------------------------------------------------*/
/**
 * Function to get current Coding data value of 'NAME14_reserved'
 *
 * - Application Type....: uint8
 * - Nvram Type..........: uint8
 */
/*----------------------------------------------------------------------------*/
Coding_ReturnType Coding_GetNAME14_reserved(uint8 *funcVal)
{
   Coding_ReturnType retVal;

   retVal = Coding_GetAccessPermission();

   if ( CODING_RC_OK == retVal )
   {
      *funcVal = (uint8) ((uint8)((uint8)((Coding_CodingData[9u] & 0xFFu) >> 0x00u)));
   }

   return ( retVal );
}

/*----------------------------------------------------------------------------*/
/**
 * Function to get current Coding data value of 'NAME15_reserved'
 *
 * - Application Type....: uint8
 * - Nvram Type..........: uint8
 */
/*----------------------------------------------------------------------------*/
Coding_ReturnType Coding_GetNAME15_reserved(uint8 *funcVal)
{
   Coding_ReturnType retVal;

   retVal = Coding_GetAccessPermission();

   if ( CODING_RC_OK == retVal )
   {
      *funcVal = (uint8) ((uint8)((uint8)((Coding_CodingData[10u] & 0xFFu) >> 0x00u)));
   }

   return ( retVal );
}

/*----------------------------------------------------------------------------*/
/**
 * Function to get current Coding data value of 'NAME16_reserved'
 *
 * - Application Type....: uint8
 * - Nvram Type..........: uint8
 */
/*----------------------------------------------------------------------------*/
Coding_ReturnType Coding_GetNAME16_reserved(uint8 *funcVal)
{
   Coding_ReturnType retVal;

   retVal = Coding_GetAccessPermission();

   if ( CODING_RC_OK == retVal )
   {
      *funcVal = (uint8) ((uint8)((uint8)((Coding_CodingData[11u] & 0xFFu) >> 0x00u)));
   }

   return ( retVal );
}

/*----------------------------------------------------------------------------*/
/**
 * Function to get current Coding data value of 'NAME17_reserved'
 *
 * - Application Type....: uint8
 * - Nvram Type..........: uint8
 */
/*----------------------------------------------------------------------------*/
Coding_ReturnType Coding_GetNAME17_reserved(uint8 *funcVal)
{
   Coding_ReturnType retVal;

   retVal = Coding_GetAccessPermission();

   if ( CODING_RC_OK == retVal )
   {
      *funcVal = (uint8) ((uint8)((uint8)((Coding_CodingData[12u] & 0xFFu) >> 0x00u)));
   }

   return ( retVal );
}

/*----------------------------------------------------------------------------*/
/**
 * Function to get current Coding data value of 'NAME18_reserved'
 *
 * - Application Type....: uint8
 * - Nvram Type..........: uint8
 */
/*----------------------------------------------------------------------------*/
Coding_ReturnType Coding_GetNAME18_reserved(uint8 *funcVal)
{
   Coding_ReturnType retVal;

   retVal = Coding_GetAccessPermission();

   if ( CODING_RC_OK == retVal )
   {
      *funcVal = (uint8) ((uint8)((uint8)((Coding_CodingData[13u] & 0xFFu) >> 0x00u)));
   }

   return ( retVal );
}

/*----------------------------------------------------------------------------*/
/**
 * Function to get current Coding data value of 'NAME19_reserved'
 *
 * - Application Type....: uint8
 * - Nvram Type..........: uint8
 */
/*----------------------------------------------------------------------------*/
Coding_ReturnType Coding_GetNAME19_reserved(uint8 *funcVal)
{
   Coding_ReturnType retVal;

   retVal = Coding_GetAccessPermission();

   if ( CODING_RC_OK == retVal )
   {
      *funcVal = (uint8) ((uint8)((uint8)((Coding_CodingData[14u] & 0xFFu) >> 0x00u)));
   }

   return ( retVal );
}

/*----------------------------------------------------------------------------*/
/**
 * Function to get current Coding data value of 'NAME20_reserved'
 *
 * - Application Type....: uint8
 * - Nvram Type..........: uint8
 */
/*----------------------------------------------------------------------------*/
Coding_ReturnType Coding_GetNAME20_reserved(uint8 *funcVal)
{
   Coding_ReturnType retVal;

   retVal = Coding_GetAccessPermission();

   if ( CODING_RC_OK == retVal )
   {
      *funcVal = (uint8) ((uint8)((uint8)((Coding_CodingData[15u] & 0xFFu) >> 0x00u)));
   }

   return ( retVal );
}

/*----------------------------------------------------------------------------*/
/**
 * Function to get current Coding data value of 'NAME21_reserved'
 *
 * - Application Type....: uint8
 * - Nvram Type..........: uint8
 */
/*----------------------------------------------------------------------------*/
Coding_ReturnType Coding_GetNAME21_reserved(uint8 *funcVal)
{
   Coding_ReturnType retVal;

   retVal = Coding_GetAccessPermission();

   if ( CODING_RC_OK == retVal )
   {
      *funcVal = (uint8) ((uint8)((uint8)((Coding_CodingData[16u] & 0xFFu) >> 0x00u)));
   }

   return ( retVal );
}

/*----------------------------------------------------------------------------*/
/**
 * Function to get current Coding data value of 'NAME22_reserved'
 *
 * - Application Type....: uint8
 * - Nvram Type..........: uint8
 */
/*----------------------------------------------------------------------------*/
Coding_ReturnType Coding_GetNAME22_reserved(uint8 *funcVal)
{
   Coding_ReturnType retVal;

   retVal = Coding_GetAccessPermission();

   if ( CODING_RC_OK == retVal )
   {
      *funcVal = (uint8) ((uint8)((uint8)((Coding_CodingData[17u] & 0xFFu) >> 0x00u)));
   }

   return ( retVal );
}

/*----------------------------------------------------------------------------*/
/**
 * Function to get current Coding data value of 'NAME23_reserved'
 *
 * - Application Type....: uint8
 * - Nvram Type..........: uint8
 */
/*----------------------------------------------------------------------------*/
Coding_ReturnType Coding_GetNAME23_reserved(uint8 *funcVal)
{
   Coding_ReturnType retVal;

   retVal = Coding_GetAccessPermission();

   if ( CODING_RC_OK == retVal )
   {
      *funcVal = (uint8) ((uint8)((uint8)((Coding_CodingData[18u] & 0xFFu) >> 0x00u)));
   }

   return ( retVal );
}

/*----------------------------------------------------------------------------*/
/**
 * Function to get current Coding data value of 'NAME24_reserved'
 *
 * - Application Type....: uint8
 * - Nvram Type..........: uint8
 */
/*----------------------------------------------------------------------------*/
Coding_ReturnType Coding_GetNAME24_reserved(uint8 *funcVal)
{
   Coding_ReturnType retVal;

   retVal = Coding_GetAccessPermission();

   if ( CODING_RC_OK == retVal )
   {
      *funcVal = (uint8) ((uint8)((uint8)((Coding_CodingData[19u] & 0xFFu) >> 0x00u)));
   }

   return ( retVal );
}

/*----------------------------------------------------------------------------*/
/**
 * Function to get current Coding data value of 'NAME25_reserved'
 *
 * - Application Type....: uint8
 * - Nvram Type..........: uint8
 */
/*----------------------------------------------------------------------------*/
Coding_ReturnType Coding_GetNAME25_reserved(uint8 *funcVal)
{
   Coding_ReturnType retVal;

   retVal = Coding_GetAccessPermission();

   if ( CODING_RC_OK == retVal )
   {
      *funcVal = (uint8) ((uint8)((uint8)((Coding_CodingData[20u] & 0xFFu) >> 0x00u)));
   }

   return ( retVal );
}

/*----------------------------------------------------------------------------*/
/**
 * Function to get current Coding data value of 'NAME26_reserved'
 *
 * - Application Type....: uint8
 * - Nvram Type..........: uint8
 */
/*----------------------------------------------------------------------------*/
Coding_ReturnType Coding_GetNAME26_reserved(uint8 *funcVal)
{
   Coding_ReturnType retVal;

   retVal = Coding_GetAccessPermission();

   if ( CODING_RC_OK == retVal )
   {
      *funcVal = (uint8) ((uint8)((uint8)((Coding_CodingData[21u] & 0xFFu) >> 0x00u)));
   }

   return ( retVal );
}

/*----------------------------------------------------------------------------*/
/**
 * Function to get current Coding data value of 'NAME27_reserved'
 *
 * - Application Type....: uint8
 * - Nvram Type..........: uint8
 */
/*----------------------------------------------------------------------------*/
Coding_ReturnType Coding_GetNAME27_reserved(uint8 *funcVal)
{
   Coding_ReturnType retVal;

   retVal = Coding_GetAccessPermission();

   if ( CODING_RC_OK == retVal )
   {
      *funcVal = (uint8) ((uint8)((uint8)((Coding_CodingData[22u] & 0xFFu) >> 0x00u)));
   }

   return ( retVal );
}

/*----------------------------------------------------------------------------*/
/**
 * Function to get current Coding data value of 'NAME28_reserved'
 *
 * - Application Type....: uint8
 * - Nvram Type..........: uint8
 */
/*----------------------------------------------------------------------------*/
Coding_ReturnType Coding_GetNAME28_reserved(uint8 *funcVal)
{
   Coding_ReturnType retVal;

   retVal = Coding_GetAccessPermission();

   if ( CODING_RC_OK == retVal )
   {
      *funcVal = (uint8) ((uint8)((uint8)((Coding_CodingData[23u] & 0xFFu) >> 0x00u)));
   }

   return ( retVal );
}

/*----------------------------------------------------------------------------*/
/**
 * Function to get current Coding data value of 'NAME01_00_reserved'
 *
 * - Application Type....: boolean
 * - Nvram Type..........: boolean
 */
/*----------------------------------------------------------------------------*/
Coding_ReturnType Coding_GetNAME01_00_reserved(boolean *funcVal)
{
   Coding_ReturnType retVal;

   retVal = Coding_GetAccessPermission();

   if ( CODING_RC_OK == retVal )
   {
      *funcVal = ( ( ( Coding_CodingData[ 24u ] & 0x01u ) >> 0x00u ) == 0u ) ? FALSE : TRUE;
   }

   return ( retVal );
}

/*----------------------------------------------------------------------------*/
/**
 * Function to get current Coding data value of 'NAME01_01_reserved'
 *
 * - Application Type....: boolean
 * - Nvram Type..........: boolean
 */
/*----------------------------------------------------------------------------*/
Coding_ReturnType Coding_GetNAME01_01_reserved(boolean *funcVal)
{
   Coding_ReturnType retVal;

   retVal = Coding_GetAccessPermission();

   if ( CODING_RC_OK == retVal )
   {
      *funcVal = ( ( ( Coding_CodingData[ 24u ] & 0x02u ) >> 0x01u ) == 0u ) ? FALSE : TRUE;
   }

   return ( retVal );
}

/*----------------------------------------------------------------------------*/
/**
 * Function to get current Coding data value of 'NAME01_02_reserved'
 *
 * - Application Type....: boolean
 * - Nvram Type..........: boolean
 */
/*----------------------------------------------------------------------------*/
Coding_ReturnType Coding_GetNAME01_02_reserved(boolean *funcVal)
{
   Coding_ReturnType retVal;

   retVal = Coding_GetAccessPermission();

   if ( CODING_RC_OK == retVal )
   {
      *funcVal = ( ( ( Coding_CodingData[ 24u ] & 0x04u ) >> 0x02u ) == 0u ) ? FALSE : TRUE;
   }

   return ( retVal );
}

/*----------------------------------------------------------------------------*/
/**
 * Function to get current Coding data value of 'NAME01_03_ParkingPowerDamping'
 *
 * - Application Type....: boolean
 * - Nvram Type..........: boolean
 */
/*----------------------------------------------------------------------------*/
Coding_ReturnType Coding_GetNAME01_03_ParkingPowerDamping(boolean *funcVal)
{
   Coding_ReturnType retVal;

   retVal = Coding_GetAccessPermission();

   if ( CODING_RC_OK == retVal )
   {
      *funcVal = ( ( ( Coding_CodingData[ 24u ] & 0x08u ) >> 0x03u ) == 0u ) ? FALSE : TRUE;
   }

   return ( retVal );
}

/*----------------------------------------------------------------------------*/
/**
 * Function to get current Coding data value of 'NAME01_04_reserved'
 *
 * - Application Type....: boolean
 * - Nvram Type..........: boolean
 */
/*----------------------------------------------------------------------------*/
Coding_ReturnType Coding_GetNAME01_04_reserved(boolean *funcVal)
{
   Coding_ReturnType retVal;

   retVal = Coding_GetAccessPermission();

   if ( CODING_RC_OK == retVal )
   {
      *funcVal = ( ( ( Coding_CodingData[ 24u ] & 0x10u ) >> 0x04u ) == 0u ) ? FALSE : TRUE;
   }

   return ( retVal );
}

/*----------------------------------------------------------------------------*/
/**
 * Function to get current Coding data value of 'NAME01_05_reserved'
 *
 * - Application Type....: boolean
 * - Nvram Type..........: boolean
 */
/*----------------------------------------------------------------------------*/
Coding_ReturnType Coding_GetNAME01_05_reserved(boolean *funcVal)
{
   Coding_ReturnType retVal;

   retVal = Coding_GetAccessPermission();

   if ( CODING_RC_OK == retVal )
   {
      *funcVal = ( ( ( Coding_CodingData[ 24u ] & 0x20u ) >> 0x05u ) == 0u ) ? FALSE : TRUE;
   }

   return ( retVal );
}

/*----------------------------------------------------------------------------*/
/**
 * Function to get current Coding data value of 'NAME01_06_reserved'
 *
 * - Application Type....: boolean
 * - Nvram Type..........: boolean
 */
/*----------------------------------------------------------------------------*/
Coding_ReturnType Coding_GetNAME01_06_reserved(boolean *funcVal)
{
   Coding_ReturnType retVal;

   retVal = Coding_GetAccessPermission();

   if ( CODING_RC_OK == retVal )
   {
      *funcVal = ( ( ( Coding_CodingData[ 24u ] & 0x40u ) >> 0x06u ) == 0u ) ? FALSE : TRUE;
   }

   return ( retVal );
}

/*----------------------------------------------------------------------------*/
/**
 * Function to get current Coding data value of 'NAME01_07_reserved'
 *
 * - Application Type....: boolean
 * - Nvram Type..........: boolean
 */
/*----------------------------------------------------------------------------*/
Coding_ReturnType Coding_GetNAME01_07_reserved(boolean *funcVal)
{
   Coding_ReturnType retVal;

   retVal = Coding_GetAccessPermission();

   if ( CODING_RC_OK == retVal )
   {
      *funcVal = ( ( ( Coding_CodingData[ 24u ] & 0x80u ) >> 0x07u ) == 0u ) ? FALSE : TRUE;
   }

   return ( retVal );
}

/*----------------------------------------------------------------------------*/
/**
 * Function to get current Coding data value of 'NAME02_00_CompensationOfFriction'
 *
 * - Application Type....: boolean
 * - Nvram Type..........: boolean
 */
/*----------------------------------------------------------------------------*/
Coding_ReturnType Coding_GetNAME02_00_CompensationOfFriction(boolean *funcVal)
{
   Coding_ReturnType retVal;

   retVal = Coding_GetAccessPermission();

   if ( CODING_RC_OK == retVal )
   {
      *funcVal = ( ( ( Coding_CodingData[ 25u ] & 0x01u ) >> 0x00u ) == 0u ) ? FALSE : TRUE;
   }

   return ( retVal );
}

/*----------------------------------------------------------------------------*/
/**
 * Function to get current Coding data value of 'NAME02_01_CompensationOfConstantSteeringPullAndLateralInclinationPull'
 *
 * - Application Type....: boolean
 * - Nvram Type..........: boolean
 */
/*----------------------------------------------------------------------------*/
Coding_ReturnType Coding_GetNAME02_01_CompensationOfConstantSteeringPullAndLateralInclinationPull(boolean *funcVal)
{
   Coding_ReturnType retVal;

   retVal = Coding_GetAccessPermission();

   if ( CODING_RC_OK == retVal )
   {
      *funcVal = ( ( ( Coding_CodingData[ 25u ] & 0x02u ) >> 0x01u ) == 0u ) ? FALSE : TRUE;
   }

   return ( retVal );
}

/*----------------------------------------------------------------------------*/
/**
 * Function to get current Coding data value of 'NAME02_02'
 *
 * - Application Type....: boolean
 * - Nvram Type..........: boolean
 */
/*----------------------------------------------------------------------------*/
Coding_ReturnType Coding_GetNAME02_02(boolean *funcVal)
{
   Coding_ReturnType retVal;

   retVal = Coding_GetAccessPermission();

   if ( CODING_RC_OK == retVal )
   {
      *funcVal = ( ( ( Coding_CodingData[ 25u ] & 0x04u ) >> 0x02u ) == 0u ) ? FALSE : TRUE;
   }

   return ( retVal );
}

/*----------------------------------------------------------------------------*/
/**
 * Function to get current Coding data value of 'NAME02_03'
 *
 * - Application Type....: boolean
 * - Nvram Type..........: boolean
 */
/*----------------------------------------------------------------------------*/
Coding_ReturnType Coding_GetNAME02_03(boolean *funcVal)
{
   Coding_ReturnType retVal;

   retVal = Coding_GetAccessPermission();

   if ( CODING_RC_OK == retVal )
   {
      *funcVal = ( ( ( Coding_CodingData[ 25u ] & 0x08u ) >> 0x03u ) == 0u ) ? FALSE : TRUE;
   }

   return ( retVal );
}

/*----------------------------------------------------------------------------*/
/**
 * Function to get current Coding data value of 'NAME02_04_CompensationOfInertiaOfTheSteeringGear'
 *
 * - Application Type....: boolean
 * - Nvram Type..........: boolean
 */
/*----------------------------------------------------------------------------*/
Coding_ReturnType Coding_GetNAME02_04_CompensationOfInertiaOfTheSteeringGear(boolean *funcVal)
{
   Coding_ReturnType retVal;

   retVal = Coding_GetAccessPermission();

   if ( CODING_RC_OK == retVal )
   {
      *funcVal = ( ( ( Coding_CodingData[ 25u ] & 0x10u ) >> 0x04u ) == 0u ) ? FALSE : TRUE;
   }

   return ( retVal );
}

/*----------------------------------------------------------------------------*/
/**
 * Function to get current Coding data value of 'NAME02_05_CompensationOfInertiaOfTheSteeringWheel'
 *
 * - Application Type....: boolean
 * - Nvram Type..........: boolean
 */
/*----------------------------------------------------------------------------*/
Coding_ReturnType Coding_GetNAME02_05_CompensationOfInertiaOfTheSteeringWheel(boolean *funcVal)
{
   Coding_ReturnType retVal;

   retVal = Coding_GetAccessPermission();

   if ( CODING_RC_OK == retVal )
   {
      *funcVal = ( ( ( Coding_CodingData[ 25u ] & 0x20u ) >> 0x05u ) == 0u ) ? FALSE : TRUE;
   }

   return ( retVal );
}

/*----------------------------------------------------------------------------*/
/**
 * Function to get current Coding data value of 'NAME02_06'
 *
 * - Application Type....: boolean
 * - Nvram Type..........: boolean
 */
/*----------------------------------------------------------------------------*/
Coding_ReturnType Coding_GetNAME02_06(boolean *funcVal)
{
   Coding_ReturnType retVal;

   retVal = Coding_GetAccessPermission();

   if ( CODING_RC_OK == retVal )
   {
      *funcVal = ( ( ( Coding_CodingData[ 25u ] & 0x40u ) >> 0x06u ) == 0u ) ? FALSE : TRUE;
   }

   return ( retVal );
}

/*----------------------------------------------------------------------------*/
/**
 * Function to get current Coding data value of 'NAME02_07'
 *
 * - Application Type....: boolean
 * - Nvram Type..........: boolean
 */
/*----------------------------------------------------------------------------*/
Coding_ReturnType Coding_GetNAME02_07(boolean *funcVal)
{
   Coding_ReturnType retVal;

   retVal = Coding_GetAccessPermission();

   if ( CODING_RC_OK == retVal )
   {
      *funcVal = ( ( ( Coding_CodingData[ 25u ] & 0x80u ) >> 0x07u ) == 0u ) ? FALSE : TRUE;
   }

   return ( retVal );
}

/*----------------------------------------------------------------------------*/
/**
 * Function to get current Coding data value of 'NAME03_00_reserved'
 *
 * - Application Type....: boolean
 * - Nvram Type..........: boolean
 */
/*----------------------------------------------------------------------------*/
Coding_ReturnType Coding_GetNAME03_00_reserved(boolean *funcVal)
{
   Coding_ReturnType retVal;

   retVal = Coding_GetAccessPermission();

   if ( CODING_RC_OK == retVal )
   {
      *funcVal = ( ( ( Coding_CodingData[ 26u ] & 0x01u ) >> 0x00u ) == 0u ) ? FALSE : TRUE;
   }

   return ( retVal );
}

/*----------------------------------------------------------------------------*/
/**
 * Function to get current Coding data value of 'NAME03_01_VoltageDependantDegredation'
 *
 * - Application Type....: boolean
 * - Nvram Type..........: boolean
 */
/*----------------------------------------------------------------------------*/
Coding_ReturnType Coding_GetNAME03_01_VoltageDependantDegredation(boolean *funcVal)
{
   Coding_ReturnType retVal;

   retVal = Coding_GetAccessPermission();

   if ( CODING_RC_OK == retVal )
   {
      *funcVal = ( ( ( Coding_CodingData[ 26u ] & 0x02u ) >> 0x01u ) == 0u ) ? FALSE : TRUE;
   }

   return ( retVal );
}

/*----------------------------------------------------------------------------*/
/**
 * Function to get current Coding data value of 'NAME03_02_SpeedDependantDegredation'
 *
 * - Application Type....: boolean
 * - Nvram Type..........: boolean
 */
/*----------------------------------------------------------------------------*/
Coding_ReturnType Coding_GetNAME03_02_SpeedDependantDegredation(boolean *funcVal)
{
   Coding_ReturnType retVal;

   retVal = Coding_GetAccessPermission();

   if ( CODING_RC_OK == retVal )
   {
      *funcVal = ( ( ( Coding_CodingData[ 26u ] & 0x04u ) >> 0x02u ) == 0u ) ? FALSE : TRUE;
   }

   return ( retVal );
}

/*----------------------------------------------------------------------------*/
/**
 * Function to get current Coding data value of 'NAME03_03_reserved'
 *
 * - Application Type....: boolean
 * - Nvram Type..........: boolean
 */
/*----------------------------------------------------------------------------*/
Coding_ReturnType Coding_GetNAME03_03_reserved(boolean *funcVal)
{
   Coding_ReturnType retVal;

   retVal = Coding_GetAccessPermission();

   if ( CODING_RC_OK == retVal )
   {
      *funcVal = ( ( ( Coding_CodingData[ 26u ] & 0x08u ) >> 0x03u ) == 0u ) ? FALSE : TRUE;
   }

   return ( retVal );
}

/*----------------------------------------------------------------------------*/
/**
 * Function to get current Coding data value of 'NAME03_04_reserved'
 *
 * - Application Type....: boolean
 * - Nvram Type..........: boolean
 */
/*----------------------------------------------------------------------------*/
Coding_ReturnType Coding_GetNAME03_04_reserved(boolean *funcVal)
{
   Coding_ReturnType retVal;

   retVal = Coding_GetAccessPermission();

   if ( CODING_RC_OK == retVal )
   {
      *funcVal = ( ( ( Coding_CodingData[ 26u ] & 0x10u ) >> 0x04u ) == 0u ) ? FALSE : TRUE;
   }

   return ( retVal );
}

/*----------------------------------------------------------------------------*/
/**
 * Function to get current Coding data value of 'NAME03_05_reserved'
 *
 * - Application Type....: boolean
 * - Nvram Type..........: boolean
 */
/*----------------------------------------------------------------------------*/
Coding_ReturnType Coding_GetNAME03_05_reserved(boolean *funcVal)
{
   Coding_ReturnType retVal;

   retVal = Coding_GetAccessPermission();

   if ( CODING_RC_OK == retVal )
   {
      *funcVal = ( ( ( Coding_CodingData[ 26u ] & 0x20u ) >> 0x05u ) == 0u ) ? FALSE : TRUE;
   }

   return ( retVal );
}

/*----------------------------------------------------------------------------*/
/**
 * Function to get current Coding data value of 'NAME03_06_reserved'
 *
 * - Application Type....: boolean
 * - Nvram Type..........: boolean
 */
/*----------------------------------------------------------------------------*/
Coding_ReturnType Coding_GetNAME03_06_reserved(boolean *funcVal)
{
   Coding_ReturnType retVal;

   retVal = Coding_GetAccessPermission();

   if ( CODING_RC_OK == retVal )
   {
      *funcVal = ( ( ( Coding_CodingData[ 26u ] & 0x40u ) >> 0x06u ) == 0u ) ? FALSE : TRUE;
   }

   return ( retVal );
}

/*----------------------------------------------------------------------------*/
/**
 * Function to get current Coding data value of 'NAME03_07_reserved'
 *
 * - Application Type....: boolean
 * - Nvram Type..........: boolean
 */
/*----------------------------------------------------------------------------*/
Coding_ReturnType Coding_GetNAME03_07_reserved(boolean *funcVal)
{
   Coding_ReturnType retVal;

   retVal = Coding_GetAccessPermission();

   if ( CODING_RC_OK == retVal )
   {
      *funcVal = ( ( ( Coding_CodingData[ 26u ] & 0x80u ) >> 0x07u ) == 0u ) ? FALSE : TRUE;
   }

   return ( retVal );
}

/*----------------------------------------------------------------------------*/
/**
 * Function to get current Coding data value of 'NAME04_00_DrivingDynamicsInterfaceMinusDriversTorque'
 *
 * - Application Type....: boolean
 * - Nvram Type..........: boolean
 */
/*----------------------------------------------------------------------------*/
Coding_ReturnType Coding_GetNAME04_00_DrivingDynamicsInterfaceMinusDriversTorque(boolean *funcVal)
{
   Coding_ReturnType retVal;

   retVal = Coding_GetAccessPermission();

   if ( CODING_RC_OK == retVal )
   {
      *funcVal = ( ( ( Coding_CodingData[ 27u ] & 0x01u ) >> 0x00u ) == 0u ) ? FALSE : TRUE;
   }

   return ( retVal );
}

/*----------------------------------------------------------------------------*/
/**
 * Function to get current Coding data value of 'NAME04_00_DrivingDynamicsInterfaceMinusMotorTorque'
 *
 * - Application Type....: boolean
 * - Nvram Type..........: boolean
 */
/*----------------------------------------------------------------------------*/
Coding_ReturnType Coding_GetNAME04_00_DrivingDynamicsInterfaceMinusMotorTorque(boolean *funcVal)
{
   Coding_ReturnType retVal;

   retVal = Coding_GetAccessPermission();

   if ( CODING_RC_OK == retVal )
   {
      *funcVal = ( ( ( Coding_CodingData[ 27u ] & 0x02u ) >> 0x01u ) == 0u ) ? FALSE : TRUE;
   }

   return ( retVal );
}

/*----------------------------------------------------------------------------*/
/**
 * Function to get current Coding data value of 'NAME04_02_DrivingDynamicsInterfaceMinusFactors'
 *
 * - Application Type....: boolean
 * - Nvram Type..........: boolean
 */
/*----------------------------------------------------------------------------*/
Coding_ReturnType Coding_GetNAME04_02_DrivingDynamicsInterfaceMinusFactors(boolean *funcVal)
{
   Coding_ReturnType retVal;

   retVal = Coding_GetAccessPermission();

   if ( CODING_RC_OK == retVal )
   {
      *funcVal = ( ( ( Coding_CodingData[ 27u ] & 0x04u ) >> 0x02u ) == 0u ) ? FALSE : TRUE;
   }

   return ( retVal );
}

/*----------------------------------------------------------------------------*/
/**
 * Function to get current Coding data value of 'NAME04_03_DrivingDynamicsInterfaceMinusAdditionalDamping'
 *
 * - Application Type....: boolean
 * - Nvram Type..........: boolean
 */
/*----------------------------------------------------------------------------*/
Coding_ReturnType Coding_GetNAME04_03_DrivingDynamicsInterfaceMinusAdditionalDamping(boolean *funcVal)
{
   Coding_ReturnType retVal;

   retVal = Coding_GetAccessPermission();

   if ( CODING_RC_OK == retVal )
   {
      *funcVal = ( ( ( Coding_CodingData[ 27u ] & 0x08u ) >> 0x03u ) == 0u ) ? FALSE : TRUE;
   }

   return ( retVal );
}

/*----------------------------------------------------------------------------*/
/**
 * Function to get current Coding data value of 'NAME04_04_EPSVibration'
 *
 * - Application Type....: boolean
 * - Nvram Type..........: boolean
 */
/*----------------------------------------------------------------------------*/
Coding_ReturnType Coding_GetNAME04_04_EPSVibration(boolean *funcVal)
{
   Coding_ReturnType retVal;

   retVal = Coding_GetAccessPermission();

   if ( CODING_RC_OK == retVal )
   {
      *funcVal = ( ( ( Coding_CodingData[ 27u ] & 0x10u ) >> 0x04u ) == 0u ) ? FALSE : TRUE;
   }

   return ( retVal );
}

/*----------------------------------------------------------------------------*/
/**
 * Function to get current Coding data value of 'NAME04_05_DrivingExperienceSwitch'
 *
 * - Application Type....: boolean
 * - Nvram Type..........: boolean
 */
/*----------------------------------------------------------------------------*/
Coding_ReturnType Coding_GetNAME04_05_DrivingExperienceSwitch(boolean *funcVal)
{
   Coding_ReturnType retVal;

   retVal = Coding_GetAccessPermission();

   if ( CODING_RC_OK == retVal )
   {
      *funcVal = ( ( ( Coding_CodingData[ 27u ] & 0x20u ) >> 0x05u ) == 0u ) ? FALSE : TRUE;
   }

   return ( retVal );
}

/*----------------------------------------------------------------------------*/
/**
 * Function to get current Coding data value of 'NAME04_06_reserved'
 *
 * - Application Type....: boolean
 * - Nvram Type..........: boolean
 */
/*----------------------------------------------------------------------------*/
Coding_ReturnType Coding_GetNAME04_06_reserved(boolean *funcVal)
{
   Coding_ReturnType retVal;

   retVal = Coding_GetAccessPermission();

   if ( CODING_RC_OK == retVal )
   {
      *funcVal = ( ( ( Coding_CodingData[ 27u ] & 0x40u ) >> 0x06u ) == 0u ) ? FALSE : TRUE;
   }

   return ( retVal );
}

/*----------------------------------------------------------------------------*/
/**
 * Function to get current Coding data value of 'NAME04_07_automaticEngineStartStopFunction'
 *
 * - Application Type....: boolean
 * - Nvram Type..........: boolean
 */
/*----------------------------------------------------------------------------*/
Coding_ReturnType Coding_GetNAME04_07_automaticEngineStartStopFunction(boolean *funcVal)
{
   Coding_ReturnType retVal;

   retVal = Coding_GetAccessPermission();

   if ( CODING_RC_OK == retVal )
   {
      *funcVal = ( ( ( Coding_CodingData[ 27u ] & 0x80u ) >> 0x07u ) == 0u ) ? FALSE : TRUE;
   }

   return ( retVal );
}

/*----------------------------------------------------------------------------*/
/**
 * Function to get current Coding data value of 'NAME05_00_ActiveFanActuation'
 *
 * - Application Type....: boolean
 * - Nvram Type..........: boolean
 */
/*----------------------------------------------------------------------------*/
Coding_ReturnType Coding_GetNAME05_00_ActiveFanActuation(boolean *funcVal)
{
   Coding_ReturnType retVal;

   retVal = Coding_GetAccessPermission();

   if ( CODING_RC_OK == retVal )
   {
      *funcVal = ( ( ( Coding_CodingData[ 28u ] & 0x01u ) >> 0x00u ) == 0u ) ? FALSE : TRUE;
   }

   return ( retVal );
}

/*----------------------------------------------------------------------------*/
/**
 * Function to get current Coding data value of 'NAME05_01_reserved'
 *
 * - Application Type....: boolean
 * - Nvram Type..........: boolean
 */
/*----------------------------------------------------------------------------*/
Coding_ReturnType Coding_GetNAME05_01_reserved(boolean *funcVal)
{
   Coding_ReturnType retVal;

   retVal = Coding_GetAccessPermission();

   if ( CODING_RC_OK == retVal )
   {
      *funcVal = ( ( ( Coding_CodingData[ 28u ] & 0x02u ) >> 0x01u ) == 0u ) ? FALSE : TRUE;
   }

   return ( retVal );
}

/*----------------------------------------------------------------------------*/
/**
 * Function to get current Coding data value of 'NAME05_02_reserved'
 *
 * - Application Type....: boolean
 * - Nvram Type..........: boolean
 */
/*----------------------------------------------------------------------------*/
Coding_ReturnType Coding_GetNAME05_02_reserved(boolean *funcVal)
{
   Coding_ReturnType retVal;

   retVal = Coding_GetAccessPermission();

   if ( CODING_RC_OK == retVal )
   {
      *funcVal = ( ( ( Coding_CodingData[ 28u ] & 0x04u ) >> 0x02u ) == 0u ) ? FALSE : TRUE;
   }

   return ( retVal );
}

/*----------------------------------------------------------------------------*/
/**
 * Function to get current Coding data value of 'NAME05_03_reserved'
 *
 * - Application Type....: boolean
 * - Nvram Type..........: boolean
 */
/*----------------------------------------------------------------------------*/
Coding_ReturnType Coding_GetNAME05_03_reserved(boolean *funcVal)
{
   Coding_ReturnType retVal;

   retVal = Coding_GetAccessPermission();

   if ( CODING_RC_OK == retVal )
   {
      *funcVal = ( ( ( Coding_CodingData[ 28u ] & 0x08u ) >> 0x03u ) == 0u ) ? FALSE : TRUE;
   }

   return ( retVal );
}

/*----------------------------------------------------------------------------*/
/**
 * Function to get current Coding data value of 'NAME05_04_reserved'
 *
 * - Application Type....: boolean
 * - Nvram Type..........: boolean
 */
/*----------------------------------------------------------------------------*/
Coding_ReturnType Coding_GetNAME05_04_reserved(boolean *funcVal)
{
   Coding_ReturnType retVal;

   retVal = Coding_GetAccessPermission();

   if ( CODING_RC_OK == retVal )
   {
      *funcVal = ( ( ( Coding_CodingData[ 28u ] & 0x10u ) >> 0x04u ) == 0u ) ? FALSE : TRUE;
   }

   return ( retVal );
}

/*----------------------------------------------------------------------------*/
/**
 * Function to get current Coding data value of 'NAME05_05_reserved'
 *
 * - Application Type....: boolean
 * - Nvram Type..........: boolean
 */
/*----------------------------------------------------------------------------*/
Coding_ReturnType Coding_GetNAME05_05_reserved(boolean *funcVal)
{
   Coding_ReturnType retVal;

   retVal = Coding_GetAccessPermission();

   if ( CODING_RC_OK == retVal )
   {
      *funcVal = ( ( ( Coding_CodingData[ 28u ] & 0x20u ) >> 0x05u ) == 0u ) ? FALSE : TRUE;
   }

   return ( retVal );
}

/*----------------------------------------------------------------------------*/
/**
 * Function to get current Coding data value of 'NAME05_06_reserved'
 *
 * - Application Type....: boolean
 * - Nvram Type..........: boolean
 */
/*----------------------------------------------------------------------------*/
Coding_ReturnType Coding_GetNAME05_06_reserved(boolean *funcVal)
{
   Coding_ReturnType retVal;

   retVal = Coding_GetAccessPermission();

   if ( CODING_RC_OK == retVal )
   {
      *funcVal = ( ( ( Coding_CodingData[ 28u ] & 0x40u ) >> 0x06u ) == 0u ) ? FALSE : TRUE;
   }

   return ( retVal );
}

/*----------------------------------------------------------------------------*/
/**
 * Function to get current Coding data value of 'NAME05_07_reserved'
 *
 * - Application Type....: boolean
 * - Nvram Type..........: boolean
 */
/*----------------------------------------------------------------------------*/
Coding_ReturnType Coding_GetNAME05_07_reserved(boolean *funcVal)
{
   Coding_ReturnType retVal;

   retVal = Coding_GetAccessPermission();

   if ( CODING_RC_OK == retVal )
   {
      *funcVal = ( ( ( Coding_CodingData[ 28u ] & 0x80u ) >> 0x07u ) == 0u ) ? FALSE : TRUE;
   }

   return ( retVal );
}

/*----------------------------------------------------------------------------*/
/**
 * Function to get current Coding data value of 'NAME29_reserved'
 *
 * - Application Type....: uint8
 * - Nvram Type..........: uint8
 */
/*----------------------------------------------------------------------------*/
Coding_ReturnType Coding_GetNAME29_reserved(uint8 *funcVal)
{
   Coding_ReturnType retVal;

   retVal = Coding_GetAccessPermission();

   if ( CODING_RC_OK == retVal )
   {
      *funcVal = (uint8) ((uint8)((uint8)((Coding_CodingData[29u] & 0xFFu) >> 0x00u)));
   }

   return ( retVal );
}

/*----------------------------------------------------------------------------*/
/**
 * Function to get current Coding data value of 'CurrentLimit' for range check
 *
 * - Application Type....: uint8
 * - Nvram Type..........: uint8
 */
/*----------------------------------------------------------------------------*/
uint8 Coding_CheckCurrentLimit(void)
{
   uint8 value;
   value = (uint8) ((uint8)((uint8)((uint8)((Coding_CodingData[1u] & 0xFFu) >> 0x00u))));
   return ( value );
}


#define Coding_STOP_SEC_CODE
#include "Coding_MemMap.h" /* PRQA S 5087 */
