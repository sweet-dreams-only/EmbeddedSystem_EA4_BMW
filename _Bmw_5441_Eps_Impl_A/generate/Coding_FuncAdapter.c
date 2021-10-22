/**
 * \file
 *
 * \brief       Coding Func Adapter
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
*  GENERATION TIME : 2018-07-30 19:57:40.374125
*
------------------------------------------------------------------------------*/

/*------------------------------------------------------------------------------
                      MISRA-Deviations
------------------------------------------------------------------------------*/

/*------------------------------------------------------------------------------
                      Include Section
------------------------------------------------------------------------------*/

#include "Rte_Coding.h"
#include "Coding.h"                  /* Coding_ReturnType */
#include "Coding_Function.h"
#include "CodingClassic_Version.h"   /* Coding Classic Adapter Version */


/*------------------------------------------------------------------------------
                      Macros
------------------------------------------------------------------------------*/

/**
 * \brief check version of the module
 */
#if (!CodingClassic_CHECK_VERSION(5,2,1))
  #error "Version of Coding_FuncAdapter.c does not match the Classic adapter version!"
#endif


/*------------------------------------------------------------------------------
                      Global Functions
------------------------------------------------------------------------------*/
#define Coding_START_SEC_CODE
#include "Coding_MemMap.h" /* PRQA S 5087 */


/*----------------------------------------------------------------------------*/
/**
 * Service to get current Coding data value of 'NAME00_00_CalculationOfLoadMinusstateMinusdependentSteeringAssistance'
 */
/*----------------------------------------------------------------------------*/
Std_ReturnType Coding_Func_GetNAME00_00_CalculationOfLoadMinusstateMinusdependentSteeringAssistance(boolean *Value)
{
   Coding_ReturnType ret = CODING_RC_E_NOT_OK;

   ret = Coding_GetNAME00_00_CalculationOfLoadMinusstateMinusdependentSteeringAssistance( Value );

   /* convert return value */
   if ( ret != CODING_RC_E_NOT_OK )
   {
      return ( E_OK );
   }
   else
   {
      return ( E_NOT_OK );
   }
   /* PRQA S 5207 1 *//* Multiple exit points to make the code more readable */
}

/*----------------------------------------------------------------------------*/
/**
 * Service to get current Coding data value of 'NAME00_01_CalculationOfActiveReturn'
 */
/*----------------------------------------------------------------------------*/
Std_ReturnType Coding_Func_GetNAME00_01_CalculationOfActiveReturn(boolean *Value)
{
   Coding_ReturnType ret = CODING_RC_E_NOT_OK;

   ret = Coding_GetNAME00_01_CalculationOfActiveReturn( Value );

   /* convert return value */
   if ( ret != CODING_RC_E_NOT_OK )
   {
      return ( E_OK );
   }
   else
   {
      return ( E_NOT_OK );
   }
   /* PRQA S 5207 1 *//* Multiple exit points to make the code more readable */
}

/*----------------------------------------------------------------------------*/
/**
 * Service to get current Coding data value of 'NAME00_02_reserved'
 */
/*----------------------------------------------------------------------------*/
Std_ReturnType Coding_Func_GetNAME00_02_reserved(boolean *Value)
{
   Coding_ReturnType ret = CODING_RC_E_NOT_OK;

   ret = Coding_GetNAME00_02_reserved( Value );

   /* convert return value */
   if ( ret != CODING_RC_E_NOT_OK )
   {
      return ( E_OK );
   }
   else
   {
      return ( E_NOT_OK );
   }
   /* PRQA S 5207 1 *//* Multiple exit points to make the code more readable */
}

/*----------------------------------------------------------------------------*/
/**
 * Service to get current Coding data value of 'NAME00_03_ActiveInfluenceOnTheSteeringHysterisis'
 */
/*----------------------------------------------------------------------------*/
Std_ReturnType Coding_Func_GetNAME00_03_ActiveInfluenceOnTheSteeringHysterisis(boolean *Value)
{
   Coding_ReturnType ret = CODING_RC_E_NOT_OK;

   ret = Coding_GetNAME00_03_ActiveInfluenceOnTheSteeringHysterisis( Value );

   /* convert return value */
   if ( ret != CODING_RC_E_NOT_OK )
   {
      return ( E_OK );
   }
   else
   {
      return ( E_NOT_OK );
   }
   /* PRQA S 5207 1 *//* Multiple exit points to make the code more readable */
}

/*----------------------------------------------------------------------------*/
/**
 * Service to get current Coding data value of 'NAME00_04_reserved'
 */
/*----------------------------------------------------------------------------*/
Std_ReturnType Coding_Func_GetNAME00_04_reserved(boolean *Value)
{
   Coding_ReturnType ret = CODING_RC_E_NOT_OK;

   ret = Coding_GetNAME00_04_reserved( Value );

   /* convert return value */
   if ( ret != CODING_RC_E_NOT_OK )
   {
      return ( E_OK );
   }
   else
   {
      return ( E_NOT_OK );
   }
   /* PRQA S 5207 1 *//* Multiple exit points to make the code more readable */
}

/*----------------------------------------------------------------------------*/
/**
 * Service to get current Coding data value of 'NAME00_05_reserved'
 */
/*----------------------------------------------------------------------------*/
Std_ReturnType Coding_Func_GetNAME00_05_reserved(boolean *Value)
{
   Coding_ReturnType ret = CODING_RC_E_NOT_OK;

   ret = Coding_GetNAME00_05_reserved( Value );

   /* convert return value */
   if ( ret != CODING_RC_E_NOT_OK )
   {
      return ( E_OK );
   }
   else
   {
      return ( E_NOT_OK );
   }
   /* PRQA S 5207 1 *//* Multiple exit points to make the code more readable */
}

/*----------------------------------------------------------------------------*/
/**
 * Service to get current Coding data value of 'NAME00_06_reserved'
 */
/*----------------------------------------------------------------------------*/
Std_ReturnType Coding_Func_GetNAME00_06_reserved(boolean *Value)
{
   Coding_ReturnType ret = CODING_RC_E_NOT_OK;

   ret = Coding_GetNAME00_06_reserved( Value );

   /* convert return value */
   if ( ret != CODING_RC_E_NOT_OK )
   {
      return ( E_OK );
   }
   else
   {
      return ( E_NOT_OK );
   }
   /* PRQA S 5207 1 *//* Multiple exit points to make the code more readable */
}

/*----------------------------------------------------------------------------*/
/**
 * Service to get current Coding data value of 'NAME00_07_reserved'
 */
/*----------------------------------------------------------------------------*/
Std_ReturnType Coding_Func_GetNAME00_07_reserved(boolean *Value)
{
   Coding_ReturnType ret = CODING_RC_E_NOT_OK;

   ret = Coding_GetNAME00_07_reserved( Value );

   /* convert return value */
   if ( ret != CODING_RC_E_NOT_OK )
   {
      return ( E_OK );
   }
   else
   {
      return ( E_NOT_OK );
   }
   /* PRQA S 5207 1 *//* Multiple exit points to make the code more readable */
}

/*----------------------------------------------------------------------------*/
/**
 * Service to get current Coding data value of 'CurrentLimit'
 */
/*----------------------------------------------------------------------------*/
Std_ReturnType Coding_Func_GetCurrentLimit(uint8 *Value)
{
   Coding_ReturnType ret = CODING_RC_E_NOT_OK;

   ret = Coding_GetCurrentLimit( Value );

   /* convert return value */
   if ( ret != CODING_RC_E_NOT_OK )
   {
      return ( E_OK );
   }
   else
   {
      return ( E_NOT_OK );
   }
   /* PRQA S 5207 1 *//* Multiple exit points to make the code more readable */
}

/*----------------------------------------------------------------------------*/
/**
 * Service to get current Coding data value of 'SpeedMinuslimitForMaxCurrent'
 */
/*----------------------------------------------------------------------------*/
Std_ReturnType Coding_Func_GetSpeedMinuslimitForMaxCurrent(uint8 *Value)
{
   Coding_ReturnType ret = CODING_RC_E_NOT_OK;

   ret = Coding_GetSpeedMinuslimitForMaxCurrent( Value );

   /* convert return value */
   if ( ret != CODING_RC_E_NOT_OK )
   {
      return ( E_OK );
   }
   else
   {
      return ( E_NOT_OK );
   }
   /* PRQA S 5207 1 *//* Multiple exit points to make the code more readable */
}

/*----------------------------------------------------------------------------*/
/**
 * Service to get current Coding data value of 'NAME08_reserved'
 */
/*----------------------------------------------------------------------------*/
Std_ReturnType Coding_Func_GetNAME08_reserved(uint8 *Value)
{
   Coding_ReturnType ret = CODING_RC_E_NOT_OK;

   ret = Coding_GetNAME08_reserved( Value );

   /* convert return value */
   if ( ret != CODING_RC_E_NOT_OK )
   {
      return ( E_OK );
   }
   else
   {
      return ( E_NOT_OK );
   }
   /* PRQA S 5207 1 *//* Multiple exit points to make the code more readable */
}

/*----------------------------------------------------------------------------*/
/**
 * Service to get current Coding data value of 'NAME09_reserved'
 */
/*----------------------------------------------------------------------------*/
Std_ReturnType Coding_Func_GetNAME09_reserved(uint8 *Value)
{
   Coding_ReturnType ret = CODING_RC_E_NOT_OK;

   ret = Coding_GetNAME09_reserved( Value );

   /* convert return value */
   if ( ret != CODING_RC_E_NOT_OK )
   {
      return ( E_OK );
   }
   else
   {
      return ( E_NOT_OK );
   }
   /* PRQA S 5207 1 *//* Multiple exit points to make the code more readable */
}

/*----------------------------------------------------------------------------*/
/**
 * Service to get current Coding data value of 'NAME10_reserved'
 */
/*----------------------------------------------------------------------------*/
Std_ReturnType Coding_Func_GetNAME10_reserved(uint8 *Value)
{
   Coding_ReturnType ret = CODING_RC_E_NOT_OK;

   ret = Coding_GetNAME10_reserved( Value );

   /* convert return value */
   if ( ret != CODING_RC_E_NOT_OK )
   {
      return ( E_OK );
   }
   else
   {
      return ( E_NOT_OK );
   }
   /* PRQA S 5207 1 *//* Multiple exit points to make the code more readable */
}

/*----------------------------------------------------------------------------*/
/**
 * Service to get current Coding data value of 'NAME11_reserved'
 */
/*----------------------------------------------------------------------------*/
Std_ReturnType Coding_Func_GetNAME11_reserved(uint8 *Value)
{
   Coding_ReturnType ret = CODING_RC_E_NOT_OK;

   ret = Coding_GetNAME11_reserved( Value );

   /* convert return value */
   if ( ret != CODING_RC_E_NOT_OK )
   {
      return ( E_OK );
   }
   else
   {
      return ( E_NOT_OK );
   }
   /* PRQA S 5207 1 *//* Multiple exit points to make the code more readable */
}

/*----------------------------------------------------------------------------*/
/**
 * Service to get current Coding data value of 'NAME12_reserved'
 */
/*----------------------------------------------------------------------------*/
Std_ReturnType Coding_Func_GetNAME12_reserved(uint8 *Value)
{
   Coding_ReturnType ret = CODING_RC_E_NOT_OK;

   ret = Coding_GetNAME12_reserved( Value );

   /* convert return value */
   if ( ret != CODING_RC_E_NOT_OK )
   {
      return ( E_OK );
   }
   else
   {
      return ( E_NOT_OK );
   }
   /* PRQA S 5207 1 *//* Multiple exit points to make the code more readable */
}

/*----------------------------------------------------------------------------*/
/**
 * Service to get current Coding data value of 'NAME13_reserved'
 */
/*----------------------------------------------------------------------------*/
Std_ReturnType Coding_Func_GetNAME13_reserved(uint8 *Value)
{
   Coding_ReturnType ret = CODING_RC_E_NOT_OK;

   ret = Coding_GetNAME13_reserved( Value );

   /* convert return value */
   if ( ret != CODING_RC_E_NOT_OK )
   {
      return ( E_OK );
   }
   else
   {
      return ( E_NOT_OK );
   }
   /* PRQA S 5207 1 *//* Multiple exit points to make the code more readable */
}

/*----------------------------------------------------------------------------*/
/**
 * Service to get current Coding data value of 'NAME14_reserved'
 */
/*----------------------------------------------------------------------------*/
Std_ReturnType Coding_Func_GetNAME14_reserved(uint8 *Value)
{
   Coding_ReturnType ret = CODING_RC_E_NOT_OK;

   ret = Coding_GetNAME14_reserved( Value );

   /* convert return value */
   if ( ret != CODING_RC_E_NOT_OK )
   {
      return ( E_OK );
   }
   else
   {
      return ( E_NOT_OK );
   }
   /* PRQA S 5207 1 *//* Multiple exit points to make the code more readable */
}

/*----------------------------------------------------------------------------*/
/**
 * Service to get current Coding data value of 'NAME15_reserved'
 */
/*----------------------------------------------------------------------------*/
Std_ReturnType Coding_Func_GetNAME15_reserved(uint8 *Value)
{
   Coding_ReturnType ret = CODING_RC_E_NOT_OK;

   ret = Coding_GetNAME15_reserved( Value );

   /* convert return value */
   if ( ret != CODING_RC_E_NOT_OK )
   {
      return ( E_OK );
   }
   else
   {
      return ( E_NOT_OK );
   }
   /* PRQA S 5207 1 *//* Multiple exit points to make the code more readable */
}

/*----------------------------------------------------------------------------*/
/**
 * Service to get current Coding data value of 'NAME16_reserved'
 */
/*----------------------------------------------------------------------------*/
Std_ReturnType Coding_Func_GetNAME16_reserved(uint8 *Value)
{
   Coding_ReturnType ret = CODING_RC_E_NOT_OK;

   ret = Coding_GetNAME16_reserved( Value );

   /* convert return value */
   if ( ret != CODING_RC_E_NOT_OK )
   {
      return ( E_OK );
   }
   else
   {
      return ( E_NOT_OK );
   }
   /* PRQA S 5207 1 *//* Multiple exit points to make the code more readable */
}

/*----------------------------------------------------------------------------*/
/**
 * Service to get current Coding data value of 'NAME17_reserved'
 */
/*----------------------------------------------------------------------------*/
Std_ReturnType Coding_Func_GetNAME17_reserved(uint8 *Value)
{
   Coding_ReturnType ret = CODING_RC_E_NOT_OK;

   ret = Coding_GetNAME17_reserved( Value );

   /* convert return value */
   if ( ret != CODING_RC_E_NOT_OK )
   {
      return ( E_OK );
   }
   else
   {
      return ( E_NOT_OK );
   }
   /* PRQA S 5207 1 *//* Multiple exit points to make the code more readable */
}

/*----------------------------------------------------------------------------*/
/**
 * Service to get current Coding data value of 'NAME18_reserved'
 */
/*----------------------------------------------------------------------------*/
Std_ReturnType Coding_Func_GetNAME18_reserved(uint8 *Value)
{
   Coding_ReturnType ret = CODING_RC_E_NOT_OK;

   ret = Coding_GetNAME18_reserved( Value );

   /* convert return value */
   if ( ret != CODING_RC_E_NOT_OK )
   {
      return ( E_OK );
   }
   else
   {
      return ( E_NOT_OK );
   }
   /* PRQA S 5207 1 *//* Multiple exit points to make the code more readable */
}

/*----------------------------------------------------------------------------*/
/**
 * Service to get current Coding data value of 'NAME19_reserved'
 */
/*----------------------------------------------------------------------------*/
Std_ReturnType Coding_Func_GetNAME19_reserved(uint8 *Value)
{
   Coding_ReturnType ret = CODING_RC_E_NOT_OK;

   ret = Coding_GetNAME19_reserved( Value );

   /* convert return value */
   if ( ret != CODING_RC_E_NOT_OK )
   {
      return ( E_OK );
   }
   else
   {
      return ( E_NOT_OK );
   }
   /* PRQA S 5207 1 *//* Multiple exit points to make the code more readable */
}

/*----------------------------------------------------------------------------*/
/**
 * Service to get current Coding data value of 'NAME20_reserved'
 */
/*----------------------------------------------------------------------------*/
Std_ReturnType Coding_Func_GetNAME20_reserved(uint8 *Value)
{
   Coding_ReturnType ret = CODING_RC_E_NOT_OK;

   ret = Coding_GetNAME20_reserved( Value );

   /* convert return value */
   if ( ret != CODING_RC_E_NOT_OK )
   {
      return ( E_OK );
   }
   else
   {
      return ( E_NOT_OK );
   }
   /* PRQA S 5207 1 *//* Multiple exit points to make the code more readable */
}

/*----------------------------------------------------------------------------*/
/**
 * Service to get current Coding data value of 'NAME21_reserved'
 */
/*----------------------------------------------------------------------------*/
Std_ReturnType Coding_Func_GetNAME21_reserved(uint8 *Value)
{
   Coding_ReturnType ret = CODING_RC_E_NOT_OK;

   ret = Coding_GetNAME21_reserved( Value );

   /* convert return value */
   if ( ret != CODING_RC_E_NOT_OK )
   {
      return ( E_OK );
   }
   else
   {
      return ( E_NOT_OK );
   }
   /* PRQA S 5207 1 *//* Multiple exit points to make the code more readable */
}

/*----------------------------------------------------------------------------*/
/**
 * Service to get current Coding data value of 'NAME22_reserved'
 */
/*----------------------------------------------------------------------------*/
Std_ReturnType Coding_Func_GetNAME22_reserved(uint8 *Value)
{
   Coding_ReturnType ret = CODING_RC_E_NOT_OK;

   ret = Coding_GetNAME22_reserved( Value );

   /* convert return value */
   if ( ret != CODING_RC_E_NOT_OK )
   {
      return ( E_OK );
   }
   else
   {
      return ( E_NOT_OK );
   }
   /* PRQA S 5207 1 *//* Multiple exit points to make the code more readable */
}

/*----------------------------------------------------------------------------*/
/**
 * Service to get current Coding data value of 'NAME23_reserved'
 */
/*----------------------------------------------------------------------------*/
Std_ReturnType Coding_Func_GetNAME23_reserved(uint8 *Value)
{
   Coding_ReturnType ret = CODING_RC_E_NOT_OK;

   ret = Coding_GetNAME23_reserved( Value );

   /* convert return value */
   if ( ret != CODING_RC_E_NOT_OK )
   {
      return ( E_OK );
   }
   else
   {
      return ( E_NOT_OK );
   }
   /* PRQA S 5207 1 *//* Multiple exit points to make the code more readable */
}

/*----------------------------------------------------------------------------*/
/**
 * Service to get current Coding data value of 'NAME24_reserved'
 */
/*----------------------------------------------------------------------------*/
Std_ReturnType Coding_Func_GetNAME24_reserved(uint8 *Value)
{
   Coding_ReturnType ret = CODING_RC_E_NOT_OK;

   ret = Coding_GetNAME24_reserved( Value );

   /* convert return value */
   if ( ret != CODING_RC_E_NOT_OK )
   {
      return ( E_OK );
   }
   else
   {
      return ( E_NOT_OK );
   }
   /* PRQA S 5207 1 *//* Multiple exit points to make the code more readable */
}

/*----------------------------------------------------------------------------*/
/**
 * Service to get current Coding data value of 'NAME25_reserved'
 */
/*----------------------------------------------------------------------------*/
Std_ReturnType Coding_Func_GetNAME25_reserved(uint8 *Value)
{
   Coding_ReturnType ret = CODING_RC_E_NOT_OK;

   ret = Coding_GetNAME25_reserved( Value );

   /* convert return value */
   if ( ret != CODING_RC_E_NOT_OK )
   {
      return ( E_OK );
   }
   else
   {
      return ( E_NOT_OK );
   }
   /* PRQA S 5207 1 *//* Multiple exit points to make the code more readable */
}

/*----------------------------------------------------------------------------*/
/**
 * Service to get current Coding data value of 'NAME26_reserved'
 */
/*----------------------------------------------------------------------------*/
Std_ReturnType Coding_Func_GetNAME26_reserved(uint8 *Value)
{
   Coding_ReturnType ret = CODING_RC_E_NOT_OK;

   ret = Coding_GetNAME26_reserved( Value );

   /* convert return value */
   if ( ret != CODING_RC_E_NOT_OK )
   {
      return ( E_OK );
   }
   else
   {
      return ( E_NOT_OK );
   }
   /* PRQA S 5207 1 *//* Multiple exit points to make the code more readable */
}

/*----------------------------------------------------------------------------*/
/**
 * Service to get current Coding data value of 'NAME27_reserved'
 */
/*----------------------------------------------------------------------------*/
Std_ReturnType Coding_Func_GetNAME27_reserved(uint8 *Value)
{
   Coding_ReturnType ret = CODING_RC_E_NOT_OK;

   ret = Coding_GetNAME27_reserved( Value );

   /* convert return value */
   if ( ret != CODING_RC_E_NOT_OK )
   {
      return ( E_OK );
   }
   else
   {
      return ( E_NOT_OK );
   }
   /* PRQA S 5207 1 *//* Multiple exit points to make the code more readable */
}

/*----------------------------------------------------------------------------*/
/**
 * Service to get current Coding data value of 'NAME28_reserved'
 */
/*----------------------------------------------------------------------------*/
Std_ReturnType Coding_Func_GetNAME28_reserved(uint8 *Value)
{
   Coding_ReturnType ret = CODING_RC_E_NOT_OK;

   ret = Coding_GetNAME28_reserved( Value );

   /* convert return value */
   if ( ret != CODING_RC_E_NOT_OK )
   {
      return ( E_OK );
   }
   else
   {
      return ( E_NOT_OK );
   }
   /* PRQA S 5207 1 *//* Multiple exit points to make the code more readable */
}

/*----------------------------------------------------------------------------*/
/**
 * Service to get current Coding data value of 'NAME01_00_reserved'
 */
/*----------------------------------------------------------------------------*/
Std_ReturnType Coding_Func_GetNAME01_00_reserved(boolean *Value)
{
   Coding_ReturnType ret = CODING_RC_E_NOT_OK;

   ret = Coding_GetNAME01_00_reserved( Value );

   /* convert return value */
   if ( ret != CODING_RC_E_NOT_OK )
   {
      return ( E_OK );
   }
   else
   {
      return ( E_NOT_OK );
   }
   /* PRQA S 5207 1 *//* Multiple exit points to make the code more readable */
}

/*----------------------------------------------------------------------------*/
/**
 * Service to get current Coding data value of 'NAME01_01_reserved'
 */
/*----------------------------------------------------------------------------*/
Std_ReturnType Coding_Func_GetNAME01_01_reserved(boolean *Value)
{
   Coding_ReturnType ret = CODING_RC_E_NOT_OK;

   ret = Coding_GetNAME01_01_reserved( Value );

   /* convert return value */
   if ( ret != CODING_RC_E_NOT_OK )
   {
      return ( E_OK );
   }
   else
   {
      return ( E_NOT_OK );
   }
   /* PRQA S 5207 1 *//* Multiple exit points to make the code more readable */
}

/*----------------------------------------------------------------------------*/
/**
 * Service to get current Coding data value of 'NAME01_02_reserved'
 */
/*----------------------------------------------------------------------------*/
Std_ReturnType Coding_Func_GetNAME01_02_reserved(boolean *Value)
{
   Coding_ReturnType ret = CODING_RC_E_NOT_OK;

   ret = Coding_GetNAME01_02_reserved( Value );

   /* convert return value */
   if ( ret != CODING_RC_E_NOT_OK )
   {
      return ( E_OK );
   }
   else
   {
      return ( E_NOT_OK );
   }
   /* PRQA S 5207 1 *//* Multiple exit points to make the code more readable */
}

/*----------------------------------------------------------------------------*/
/**
 * Service to get current Coding data value of 'NAME01_03_ParkingPowerDamping'
 */
/*----------------------------------------------------------------------------*/
Std_ReturnType Coding_Func_GetNAME01_03_ParkingPowerDamping(boolean *Value)
{
   Coding_ReturnType ret = CODING_RC_E_NOT_OK;

   ret = Coding_GetNAME01_03_ParkingPowerDamping( Value );

   /* convert return value */
   if ( ret != CODING_RC_E_NOT_OK )
   {
      return ( E_OK );
   }
   else
   {
      return ( E_NOT_OK );
   }
   /* PRQA S 5207 1 *//* Multiple exit points to make the code more readable */
}

/*----------------------------------------------------------------------------*/
/**
 * Service to get current Coding data value of 'NAME01_04_reserved'
 */
/*----------------------------------------------------------------------------*/
Std_ReturnType Coding_Func_GetNAME01_04_reserved(boolean *Value)
{
   Coding_ReturnType ret = CODING_RC_E_NOT_OK;

   ret = Coding_GetNAME01_04_reserved( Value );

   /* convert return value */
   if ( ret != CODING_RC_E_NOT_OK )
   {
      return ( E_OK );
   }
   else
   {
      return ( E_NOT_OK );
   }
   /* PRQA S 5207 1 *//* Multiple exit points to make the code more readable */
}

/*----------------------------------------------------------------------------*/
/**
 * Service to get current Coding data value of 'NAME01_05_reserved'
 */
/*----------------------------------------------------------------------------*/
Std_ReturnType Coding_Func_GetNAME01_05_reserved(boolean *Value)
{
   Coding_ReturnType ret = CODING_RC_E_NOT_OK;

   ret = Coding_GetNAME01_05_reserved( Value );

   /* convert return value */
   if ( ret != CODING_RC_E_NOT_OK )
   {
      return ( E_OK );
   }
   else
   {
      return ( E_NOT_OK );
   }
   /* PRQA S 5207 1 *//* Multiple exit points to make the code more readable */
}

/*----------------------------------------------------------------------------*/
/**
 * Service to get current Coding data value of 'NAME01_06_reserved'
 */
/*----------------------------------------------------------------------------*/
Std_ReturnType Coding_Func_GetNAME01_06_reserved(boolean *Value)
{
   Coding_ReturnType ret = CODING_RC_E_NOT_OK;

   ret = Coding_GetNAME01_06_reserved( Value );

   /* convert return value */
   if ( ret != CODING_RC_E_NOT_OK )
   {
      return ( E_OK );
   }
   else
   {
      return ( E_NOT_OK );
   }
   /* PRQA S 5207 1 *//* Multiple exit points to make the code more readable */
}

/*----------------------------------------------------------------------------*/
/**
 * Service to get current Coding data value of 'NAME01_07_reserved'
 */
/*----------------------------------------------------------------------------*/
Std_ReturnType Coding_Func_GetNAME01_07_reserved(boolean *Value)
{
   Coding_ReturnType ret = CODING_RC_E_NOT_OK;

   ret = Coding_GetNAME01_07_reserved( Value );

   /* convert return value */
   if ( ret != CODING_RC_E_NOT_OK )
   {
      return ( E_OK );
   }
   else
   {
      return ( E_NOT_OK );
   }
   /* PRQA S 5207 1 *//* Multiple exit points to make the code more readable */
}

/*----------------------------------------------------------------------------*/
/**
 * Service to get current Coding data value of 'NAME02_00_CompensationOfFriction'
 */
/*----------------------------------------------------------------------------*/
Std_ReturnType Coding_Func_GetNAME02_00_CompensationOfFriction(boolean *Value)
{
   Coding_ReturnType ret = CODING_RC_E_NOT_OK;

   ret = Coding_GetNAME02_00_CompensationOfFriction( Value );

   /* convert return value */
   if ( ret != CODING_RC_E_NOT_OK )
   {
      return ( E_OK );
   }
   else
   {
      return ( E_NOT_OK );
   }
   /* PRQA S 5207 1 *//* Multiple exit points to make the code more readable */
}

/*----------------------------------------------------------------------------*/
/**
 * Service to get current Coding data value of 'NAME02_01_CompensationOfConstantSteeringPullAndLateralInclinationPull'
 */
/*----------------------------------------------------------------------------*/
Std_ReturnType Coding_Func_GetNAME02_01_CompensationOfConstantSteeringPullAndLateralInclinationPull(boolean *Value)
{
   Coding_ReturnType ret = CODING_RC_E_NOT_OK;

   ret = Coding_GetNAME02_01_CompensationOfConstantSteeringPullAndLateralInclinationPull( Value );

   /* convert return value */
   if ( ret != CODING_RC_E_NOT_OK )
   {
      return ( E_OK );
   }
   else
   {
      return ( E_NOT_OK );
   }
   /* PRQA S 5207 1 *//* Multiple exit points to make the code more readable */
}

/*----------------------------------------------------------------------------*/
/**
 * Service to get current Coding data value of 'NAME02_02'
 */
/*----------------------------------------------------------------------------*/
Std_ReturnType Coding_Func_GetNAME02_02(boolean *Value)
{
   Coding_ReturnType ret = CODING_RC_E_NOT_OK;

   ret = Coding_GetNAME02_02( Value );

   /* convert return value */
   if ( ret != CODING_RC_E_NOT_OK )
   {
      return ( E_OK );
   }
   else
   {
      return ( E_NOT_OK );
   }
   /* PRQA S 5207 1 *//* Multiple exit points to make the code more readable */
}

/*----------------------------------------------------------------------------*/
/**
 * Service to get current Coding data value of 'NAME02_03'
 */
/*----------------------------------------------------------------------------*/
Std_ReturnType Coding_Func_GetNAME02_03(boolean *Value)
{
   Coding_ReturnType ret = CODING_RC_E_NOT_OK;

   ret = Coding_GetNAME02_03( Value );

   /* convert return value */
   if ( ret != CODING_RC_E_NOT_OK )
   {
      return ( E_OK );
   }
   else
   {
      return ( E_NOT_OK );
   }
   /* PRQA S 5207 1 *//* Multiple exit points to make the code more readable */
}

/*----------------------------------------------------------------------------*/
/**
 * Service to get current Coding data value of 'NAME02_04_CompensationOfInertiaOfTheSteeringGear'
 */
/*----------------------------------------------------------------------------*/
Std_ReturnType Coding_Func_GetNAME02_04_CompensationOfInertiaOfTheSteeringGear(boolean *Value)
{
   Coding_ReturnType ret = CODING_RC_E_NOT_OK;

   ret = Coding_GetNAME02_04_CompensationOfInertiaOfTheSteeringGear( Value );

   /* convert return value */
   if ( ret != CODING_RC_E_NOT_OK )
   {
      return ( E_OK );
   }
   else
   {
      return ( E_NOT_OK );
   }
   /* PRQA S 5207 1 *//* Multiple exit points to make the code more readable */
}

/*----------------------------------------------------------------------------*/
/**
 * Service to get current Coding data value of 'NAME02_05_CompensationOfInertiaOfTheSteeringWheel'
 */
/*----------------------------------------------------------------------------*/
Std_ReturnType Coding_Func_GetNAME02_05_CompensationOfInertiaOfTheSteeringWheel(boolean *Value)
{
   Coding_ReturnType ret = CODING_RC_E_NOT_OK;

   ret = Coding_GetNAME02_05_CompensationOfInertiaOfTheSteeringWheel( Value );

   /* convert return value */
   if ( ret != CODING_RC_E_NOT_OK )
   {
      return ( E_OK );
   }
   else
   {
      return ( E_NOT_OK );
   }
   /* PRQA S 5207 1 *//* Multiple exit points to make the code more readable */
}

/*----------------------------------------------------------------------------*/
/**
 * Service to get current Coding data value of 'NAME02_06'
 */
/*----------------------------------------------------------------------------*/
Std_ReturnType Coding_Func_GetNAME02_06(boolean *Value)
{
   Coding_ReturnType ret = CODING_RC_E_NOT_OK;

   ret = Coding_GetNAME02_06( Value );

   /* convert return value */
   if ( ret != CODING_RC_E_NOT_OK )
   {
      return ( E_OK );
   }
   else
   {
      return ( E_NOT_OK );
   }
   /* PRQA S 5207 1 *//* Multiple exit points to make the code more readable */
}

/*----------------------------------------------------------------------------*/
/**
 * Service to get current Coding data value of 'NAME02_07'
 */
/*----------------------------------------------------------------------------*/
Std_ReturnType Coding_Func_GetNAME02_07(boolean *Value)
{
   Coding_ReturnType ret = CODING_RC_E_NOT_OK;

   ret = Coding_GetNAME02_07( Value );

   /* convert return value */
   if ( ret != CODING_RC_E_NOT_OK )
   {
      return ( E_OK );
   }
   else
   {
      return ( E_NOT_OK );
   }
   /* PRQA S 5207 1 *//* Multiple exit points to make the code more readable */
}

/*----------------------------------------------------------------------------*/
/**
 * Service to get current Coding data value of 'NAME03_00_reserved'
 */
/*----------------------------------------------------------------------------*/
Std_ReturnType Coding_Func_GetNAME03_00_reserved(boolean *Value)
{
   Coding_ReturnType ret = CODING_RC_E_NOT_OK;

   ret = Coding_GetNAME03_00_reserved( Value );

   /* convert return value */
   if ( ret != CODING_RC_E_NOT_OK )
   {
      return ( E_OK );
   }
   else
   {
      return ( E_NOT_OK );
   }
   /* PRQA S 5207 1 *//* Multiple exit points to make the code more readable */
}

/*----------------------------------------------------------------------------*/
/**
 * Service to get current Coding data value of 'NAME03_01_VoltageDependantDegredation'
 */
/*----------------------------------------------------------------------------*/
Std_ReturnType Coding_Func_GetNAME03_01_VoltageDependantDegredation(boolean *Value)
{
   Coding_ReturnType ret = CODING_RC_E_NOT_OK;

   ret = Coding_GetNAME03_01_VoltageDependantDegredation( Value );

   /* convert return value */
   if ( ret != CODING_RC_E_NOT_OK )
   {
      return ( E_OK );
   }
   else
   {
      return ( E_NOT_OK );
   }
   /* PRQA S 5207 1 *//* Multiple exit points to make the code more readable */
}

/*----------------------------------------------------------------------------*/
/**
 * Service to get current Coding data value of 'NAME03_02_SpeedDependantDegredation'
 */
/*----------------------------------------------------------------------------*/
Std_ReturnType Coding_Func_GetNAME03_02_SpeedDependantDegredation(boolean *Value)
{
   Coding_ReturnType ret = CODING_RC_E_NOT_OK;

   ret = Coding_GetNAME03_02_SpeedDependantDegredation( Value );

   /* convert return value */
   if ( ret != CODING_RC_E_NOT_OK )
   {
      return ( E_OK );
   }
   else
   {
      return ( E_NOT_OK );
   }
   /* PRQA S 5207 1 *//* Multiple exit points to make the code more readable */
}

/*----------------------------------------------------------------------------*/
/**
 * Service to get current Coding data value of 'NAME03_03_reserved'
 */
/*----------------------------------------------------------------------------*/
Std_ReturnType Coding_Func_GetNAME03_03_reserved(boolean *Value)
{
   Coding_ReturnType ret = CODING_RC_E_NOT_OK;

   ret = Coding_GetNAME03_03_reserved( Value );

   /* convert return value */
   if ( ret != CODING_RC_E_NOT_OK )
   {
      return ( E_OK );
   }
   else
   {
      return ( E_NOT_OK );
   }
   /* PRQA S 5207 1 *//* Multiple exit points to make the code more readable */
}

/*----------------------------------------------------------------------------*/
/**
 * Service to get current Coding data value of 'NAME03_04_reserved'
 */
/*----------------------------------------------------------------------------*/
Std_ReturnType Coding_Func_GetNAME03_04_reserved(boolean *Value)
{
   Coding_ReturnType ret = CODING_RC_E_NOT_OK;

   ret = Coding_GetNAME03_04_reserved( Value );

   /* convert return value */
   if ( ret != CODING_RC_E_NOT_OK )
   {
      return ( E_OK );
   }
   else
   {
      return ( E_NOT_OK );
   }
   /* PRQA S 5207 1 *//* Multiple exit points to make the code more readable */
}

/*----------------------------------------------------------------------------*/
/**
 * Service to get current Coding data value of 'NAME03_05_reserved'
 */
/*----------------------------------------------------------------------------*/
Std_ReturnType Coding_Func_GetNAME03_05_reserved(boolean *Value)
{
   Coding_ReturnType ret = CODING_RC_E_NOT_OK;

   ret = Coding_GetNAME03_05_reserved( Value );

   /* convert return value */
   if ( ret != CODING_RC_E_NOT_OK )
   {
      return ( E_OK );
   }
   else
   {
      return ( E_NOT_OK );
   }
   /* PRQA S 5207 1 *//* Multiple exit points to make the code more readable */
}

/*----------------------------------------------------------------------------*/
/**
 * Service to get current Coding data value of 'NAME03_06_reserved'
 */
/*----------------------------------------------------------------------------*/
Std_ReturnType Coding_Func_GetNAME03_06_reserved(boolean *Value)
{
   Coding_ReturnType ret = CODING_RC_E_NOT_OK;

   ret = Coding_GetNAME03_06_reserved( Value );

   /* convert return value */
   if ( ret != CODING_RC_E_NOT_OK )
   {
      return ( E_OK );
   }
   else
   {
      return ( E_NOT_OK );
   }
   /* PRQA S 5207 1 *//* Multiple exit points to make the code more readable */
}

/*----------------------------------------------------------------------------*/
/**
 * Service to get current Coding data value of 'NAME03_07_reserved'
 */
/*----------------------------------------------------------------------------*/
Std_ReturnType Coding_Func_GetNAME03_07_reserved(boolean *Value)
{
   Coding_ReturnType ret = CODING_RC_E_NOT_OK;

   ret = Coding_GetNAME03_07_reserved( Value );

   /* convert return value */
   if ( ret != CODING_RC_E_NOT_OK )
   {
      return ( E_OK );
   }
   else
   {
      return ( E_NOT_OK );
   }
   /* PRQA S 5207 1 *//* Multiple exit points to make the code more readable */
}

/*----------------------------------------------------------------------------*/
/**
 * Service to get current Coding data value of 'NAME04_00_DrivingDynamicsInterfaceMinusDriversTorque'
 */
/*----------------------------------------------------------------------------*/
Std_ReturnType Coding_Func_GetNAME04_00_DrivingDynamicsInterfaceMinusDriversTorque(boolean *Value)
{
   Coding_ReturnType ret = CODING_RC_E_NOT_OK;

   ret = Coding_GetNAME04_00_DrivingDynamicsInterfaceMinusDriversTorque( Value );

   /* convert return value */
   if ( ret != CODING_RC_E_NOT_OK )
   {
      return ( E_OK );
   }
   else
   {
      return ( E_NOT_OK );
   }
   /* PRQA S 5207 1 *//* Multiple exit points to make the code more readable */
}

/*----------------------------------------------------------------------------*/
/**
 * Service to get current Coding data value of 'NAME04_00_DrivingDynamicsInterfaceMinusMotorTorque'
 */
/*----------------------------------------------------------------------------*/
Std_ReturnType Coding_Func_GetNAME04_00_DrivingDynamicsInterfaceMinusMotorTorque(boolean *Value)
{
   Coding_ReturnType ret = CODING_RC_E_NOT_OK;

   ret = Coding_GetNAME04_00_DrivingDynamicsInterfaceMinusMotorTorque( Value );

   /* convert return value */
   if ( ret != CODING_RC_E_NOT_OK )
   {
      return ( E_OK );
   }
   else
   {
      return ( E_NOT_OK );
   }
   /* PRQA S 5207 1 *//* Multiple exit points to make the code more readable */
}

/*----------------------------------------------------------------------------*/
/**
 * Service to get current Coding data value of 'NAME04_02_DrivingDynamicsInterfaceMinusFactors'
 */
/*----------------------------------------------------------------------------*/
Std_ReturnType Coding_Func_GetNAME04_02_DrivingDynamicsInterfaceMinusFactors(boolean *Value)
{
   Coding_ReturnType ret = CODING_RC_E_NOT_OK;

   ret = Coding_GetNAME04_02_DrivingDynamicsInterfaceMinusFactors( Value );

   /* convert return value */
   if ( ret != CODING_RC_E_NOT_OK )
   {
      return ( E_OK );
   }
   else
   {
      return ( E_NOT_OK );
   }
   /* PRQA S 5207 1 *//* Multiple exit points to make the code more readable */
}

/*----------------------------------------------------------------------------*/
/**
 * Service to get current Coding data value of 'NAME04_03_DrivingDynamicsInterfaceMinusAdditionalDamping'
 */
/*----------------------------------------------------------------------------*/
Std_ReturnType Coding_Func_GetNAME04_03_DrivingDynamicsInterfaceMinusAdditionalDamping(boolean *Value)
{
   Coding_ReturnType ret = CODING_RC_E_NOT_OK;

   ret = Coding_GetNAME04_03_DrivingDynamicsInterfaceMinusAdditionalDamping( Value );

   /* convert return value */
   if ( ret != CODING_RC_E_NOT_OK )
   {
      return ( E_OK );
   }
   else
   {
      return ( E_NOT_OK );
   }
   /* PRQA S 5207 1 *//* Multiple exit points to make the code more readable */
}

/*----------------------------------------------------------------------------*/
/**
 * Service to get current Coding data value of 'NAME04_04_EPSVibration'
 */
/*----------------------------------------------------------------------------*/
Std_ReturnType Coding_Func_GetNAME04_04_EPSVibration(boolean *Value)
{
   Coding_ReturnType ret = CODING_RC_E_NOT_OK;

   ret = Coding_GetNAME04_04_EPSVibration( Value );

   /* convert return value */
   if ( ret != CODING_RC_E_NOT_OK )
   {
      return ( E_OK );
   }
   else
   {
      return ( E_NOT_OK );
   }
   /* PRQA S 5207 1 *//* Multiple exit points to make the code more readable */
}

/*----------------------------------------------------------------------------*/
/**
 * Service to get current Coding data value of 'NAME04_05_DrivingExperienceSwitch'
 */
/*----------------------------------------------------------------------------*/
Std_ReturnType Coding_Func_GetNAME04_05_DrivingExperienceSwitch(boolean *Value)
{
   Coding_ReturnType ret = CODING_RC_E_NOT_OK;

   ret = Coding_GetNAME04_05_DrivingExperienceSwitch( Value );

   /* convert return value */
   if ( ret != CODING_RC_E_NOT_OK )
   {
      return ( E_OK );
   }
   else
   {
      return ( E_NOT_OK );
   }
   /* PRQA S 5207 1 *//* Multiple exit points to make the code more readable */
}

/*----------------------------------------------------------------------------*/
/**
 * Service to get current Coding data value of 'NAME04_06_reserved'
 */
/*----------------------------------------------------------------------------*/
Std_ReturnType Coding_Func_GetNAME04_06_reserved(boolean *Value)
{
   Coding_ReturnType ret = CODING_RC_E_NOT_OK;

   ret = Coding_GetNAME04_06_reserved( Value );

   /* convert return value */
   if ( ret != CODING_RC_E_NOT_OK )
   {
      return ( E_OK );
   }
   else
   {
      return ( E_NOT_OK );
   }
   /* PRQA S 5207 1 *//* Multiple exit points to make the code more readable */
}

/*----------------------------------------------------------------------------*/
/**
 * Service to get current Coding data value of 'NAME04_07_automaticEngineStartStopFunction'
 */
/*----------------------------------------------------------------------------*/
Std_ReturnType Coding_Func_GetNAME04_07_automaticEngineStartStopFunction(boolean *Value)
{
   Coding_ReturnType ret = CODING_RC_E_NOT_OK;

   ret = Coding_GetNAME04_07_automaticEngineStartStopFunction( Value );

   /* convert return value */
   if ( ret != CODING_RC_E_NOT_OK )
   {
      return ( E_OK );
   }
   else
   {
      return ( E_NOT_OK );
   }
   /* PRQA S 5207 1 *//* Multiple exit points to make the code more readable */
}

/*----------------------------------------------------------------------------*/
/**
 * Service to get current Coding data value of 'NAME05_00_ActiveFanActuation'
 */
/*----------------------------------------------------------------------------*/
Std_ReturnType Coding_Func_GetNAME05_00_ActiveFanActuation(boolean *Value)
{
   Coding_ReturnType ret = CODING_RC_E_NOT_OK;

   ret = Coding_GetNAME05_00_ActiveFanActuation( Value );

   /* convert return value */
   if ( ret != CODING_RC_E_NOT_OK )
   {
      return ( E_OK );
   }
   else
   {
      return ( E_NOT_OK );
   }
   /* PRQA S 5207 1 *//* Multiple exit points to make the code more readable */
}

/*----------------------------------------------------------------------------*/
/**
 * Service to get current Coding data value of 'NAME05_01_reserved'
 */
/*----------------------------------------------------------------------------*/
Std_ReturnType Coding_Func_GetNAME05_01_reserved(boolean *Value)
{
   Coding_ReturnType ret = CODING_RC_E_NOT_OK;

   ret = Coding_GetNAME05_01_reserved( Value );

   /* convert return value */
   if ( ret != CODING_RC_E_NOT_OK )
   {
      return ( E_OK );
   }
   else
   {
      return ( E_NOT_OK );
   }
   /* PRQA S 5207 1 *//* Multiple exit points to make the code more readable */
}

/*----------------------------------------------------------------------------*/
/**
 * Service to get current Coding data value of 'NAME05_02_reserved'
 */
/*----------------------------------------------------------------------------*/
Std_ReturnType Coding_Func_GetNAME05_02_reserved(boolean *Value)
{
   Coding_ReturnType ret = CODING_RC_E_NOT_OK;

   ret = Coding_GetNAME05_02_reserved( Value );

   /* convert return value */
   if ( ret != CODING_RC_E_NOT_OK )
   {
      return ( E_OK );
   }
   else
   {
      return ( E_NOT_OK );
   }
   /* PRQA S 5207 1 *//* Multiple exit points to make the code more readable */
}

/*----------------------------------------------------------------------------*/
/**
 * Service to get current Coding data value of 'NAME05_03_reserved'
 */
/*----------------------------------------------------------------------------*/
Std_ReturnType Coding_Func_GetNAME05_03_reserved(boolean *Value)
{
   Coding_ReturnType ret = CODING_RC_E_NOT_OK;

   ret = Coding_GetNAME05_03_reserved( Value );

   /* convert return value */
   if ( ret != CODING_RC_E_NOT_OK )
   {
      return ( E_OK );
   }
   else
   {
      return ( E_NOT_OK );
   }
   /* PRQA S 5207 1 *//* Multiple exit points to make the code more readable */
}

/*----------------------------------------------------------------------------*/
/**
 * Service to get current Coding data value of 'NAME05_04_reserved'
 */
/*----------------------------------------------------------------------------*/
Std_ReturnType Coding_Func_GetNAME05_04_reserved(boolean *Value)
{
   Coding_ReturnType ret = CODING_RC_E_NOT_OK;

   ret = Coding_GetNAME05_04_reserved( Value );

   /* convert return value */
   if ( ret != CODING_RC_E_NOT_OK )
   {
      return ( E_OK );
   }
   else
   {
      return ( E_NOT_OK );
   }
   /* PRQA S 5207 1 *//* Multiple exit points to make the code more readable */
}

/*----------------------------------------------------------------------------*/
/**
 * Service to get current Coding data value of 'NAME05_05_reserved'
 */
/*----------------------------------------------------------------------------*/
Std_ReturnType Coding_Func_GetNAME05_05_reserved(boolean *Value)
{
   Coding_ReturnType ret = CODING_RC_E_NOT_OK;

   ret = Coding_GetNAME05_05_reserved( Value );

   /* convert return value */
   if ( ret != CODING_RC_E_NOT_OK )
   {
      return ( E_OK );
   }
   else
   {
      return ( E_NOT_OK );
   }
   /* PRQA S 5207 1 *//* Multiple exit points to make the code more readable */
}

/*----------------------------------------------------------------------------*/
/**
 * Service to get current Coding data value of 'NAME05_06_reserved'
 */
/*----------------------------------------------------------------------------*/
Std_ReturnType Coding_Func_GetNAME05_06_reserved(boolean *Value)
{
   Coding_ReturnType ret = CODING_RC_E_NOT_OK;

   ret = Coding_GetNAME05_06_reserved( Value );

   /* convert return value */
   if ( ret != CODING_RC_E_NOT_OK )
   {
      return ( E_OK );
   }
   else
   {
      return ( E_NOT_OK );
   }
   /* PRQA S 5207 1 *//* Multiple exit points to make the code more readable */
}

/*----------------------------------------------------------------------------*/
/**
 * Service to get current Coding data value of 'NAME05_07_reserved'
 */
/*----------------------------------------------------------------------------*/
Std_ReturnType Coding_Func_GetNAME05_07_reserved(boolean *Value)
{
   Coding_ReturnType ret = CODING_RC_E_NOT_OK;

   ret = Coding_GetNAME05_07_reserved( Value );

   /* convert return value */
   if ( ret != CODING_RC_E_NOT_OK )
   {
      return ( E_OK );
   }
   else
   {
      return ( E_NOT_OK );
   }
   /* PRQA S 5207 1 *//* Multiple exit points to make the code more readable */
}

/*----------------------------------------------------------------------------*/
/**
 * Service to get current Coding data value of 'NAME29_reserved'
 */
/*----------------------------------------------------------------------------*/
Std_ReturnType Coding_Func_GetNAME29_reserved(uint8 *Value)
{
   Coding_ReturnType ret = CODING_RC_E_NOT_OK;

   ret = Coding_GetNAME29_reserved( Value );

   /* convert return value */
   if ( ret != CODING_RC_E_NOT_OK )
   {
      return ( E_OK );
   }
   else
   {
      return ( E_NOT_OK );
   }
   /* PRQA S 5207 1 *//* Multiple exit points to make the code more readable */
}

#define Coding_STOP_SEC_CODE
#include "Coding_MemMap.h" /* PRQA S 5087 */
