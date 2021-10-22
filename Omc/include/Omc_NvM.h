/**
*  \file
*
*  \brief       BMW SWC Omc
*
*  This file contains the definition of the NvM RAM mirror and ROM default
*  data. It is included by NvM_Include.h
*
*  \project     BMW Platform Software
*
*  \copyright   BMW AG 2015 - 2017
*
*  \version     5.2.0
*
*/
#ifndef OMC_NVM_H
#define OMC_NVM_H

/*------------------------------------------------------------------------------
                      Include Section
------------------------------------------------------------------------------*/
#include "OmcClassic_Version.h"

#include "Rte_Omc_Type.h"
#include "Omc_Data.h" /* The NvM data is defined here */

/*------------------------------------------------------------------------------
                      Macros
------------------------------------------------------------------------------*/
/**
 * \brief check version of the module
 */
#if (!OmcClassic_CHECK_VERSION(5, 2, 0))
#error "Version of Omc_NvM.h does not match the version of the module!"
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

#endif /* OMC_NVM_H */
