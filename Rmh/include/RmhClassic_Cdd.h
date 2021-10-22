/**
*  \file
*
*  \brief       BMW SWC Rmh
*
*  This file contains the implementation of the BMW SWC RmhClassic
*  for usage in the BMW AUTOSAR Core.
*
*  \project     BMW Platform Software
*
*  \copyright   BMW AG 2015 - 2017
*
*  \version     5.0.0
*
*/

#ifndef RMH_CLASSIC_CDD_H
#define RMH_CLASSIC_CDD_H

/*------------------------------------------------------------------------------
                      Include Section
------------------------------------------------------------------------------*/

#include <Std_Types.h>               /* AUTOSAR Standard Types */
#include "RmhClassic_Version.h"      /* Own version header file */
#include <Rte_Rmh_Cdd.h>             /* Rte generated interface for Rmh*/


/*------------------------------------------------------------------------------
                      Macros
------------------------------------------------------------------------------*/

/* check version of the module */
#if (!RmhClassic_CHECK_VERSION(5,0,0))
   #error "Version of Rmh_Cdd.h does not match the version of the module!"
#endif


/*------------------------------------------------------------------------------
                      Data Types
------------------------------------------------------------------------------*/

/*------------------------------------------------------------------------------
                      Global Variables
------------------------------------------------------------------------------*/

/*------------------------------------------------------------------------------
                      Global Constants
------------------------------------------------------------------------------*/

/*------------------------------------------------------------------------------
                      Global Function Declarations
------------------------------------------------------------------------------*/


#endif /* RMH_CLASSIC_CDD_H */

/*--- End of file ------------------------------------------------------------*/
