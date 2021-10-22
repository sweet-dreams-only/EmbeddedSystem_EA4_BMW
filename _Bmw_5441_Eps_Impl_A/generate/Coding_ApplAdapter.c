/**
 * \file
 *
 * \brief       Coding Appl Adapter
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
*  GENERATION TIME : 2018-07-30 19:57:39.584046
*
------------------------------------------------------------------------------*/

/*------------------------------------------------------------------------------
                      MISRA-Deviations
------------------------------------------------------------------------------*/

/*------------------------------------------------------------------------------
                      Include Section
------------------------------------------------------------------------------*/

#include "Coding_ApplAdapter.h"
#include "Rte_Coding.h"
#include "Coding_Function.h"
#include "CodingClassic_Version.h"   /* Coding Classic Adapter Version */

/*------------------------------------------------------------------------------
                      Macros
------------------------------------------------------------------------------*/

/**
 * \brief check version of the module
 */
#if (!CodingClassic_CHECK_VERSION(5,2,1))
  #error "Version of Coding_ConcAdapter.c does not match the Classic adapter version!"
#endif


/*------------------------------------------------------------------------------
                      Global Functions
------------------------------------------------------------------------------*/

#define Coding_START_SEC_CODE
#include "Coding_MemMap.h" /* PRQA S 5087 */

/*----------------------------------------------------------------------------*/
/**
 *  Service to check if coding function value(s) are in allowed ranges.
 */
/*----------------------------------------------------------------------------*/
Coding_ReturnType Coding_Appl_CheckPlausibility(void)
{
   if ( E_NOT_OK == Rte_Call_CheckCurrentLimit_CheckPlausibility( Coding_CheckCurrentLimit() ) )
   {
      return ( CODING_RC_E_NOT_OK );
   }
   return ( CODING_RC_OK );
   /* PRQA S 5203 3 *//* Splitting the function makes the code more unreadable */
   /* PRQA S 5207 2 *//* Multiple exit points to make the code more readable */
   /* PRQA S 5208 1 *//* Splitting the function makes the code more unreadable */
}

#define Coding_STOP_SEC_CODE
#include "Coding_MemMap.h" /* PRQA S 5087 */
