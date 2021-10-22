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

#ifndef RMH_CLASSIC_H
#define RMH_CLASSIC_H

/* <req refid="RMH_002">
 * <version>1</version><coverage>SRC</coverage></req> */

/*------------------------------------------------------------------------------
                      Include Section
------------------------------------------------------------------------------*/

#include <Std_Types.h>               /* AUTOSAR Standard Types */
#include "RmhClassic_Version.h"      /* Own version header file */
#include <Rte_Rmh.h>                 /* Rte generated interface for Rmh */


/*------------------------------------------------------------------------------
                      Macros
------------------------------------------------------------------------------*/

/* check version of the module */
#if (!RmhClassic_CHECK_VERSION(5,0,0))
   #error "Version of Rmh.h does not match the version of the module!"
#endif

/*--------------------[API service IDs]---------------------------------------*/
#if (defined RMH_RXREQUESTMSG_ID)
#error "Rmh.h: RMH_RXREQUESTMSG_ID already defined"
#endif


/**
 * \brief Macro definition of the Rmh_RxRequestMsg() service ID
 */
#define       RMH_RXREQUESTMSG_ID      0x00U

/*--------------------[Development error codes]-------------------------------*/
#if (defined RMH_E_PARAM)
#error "Rmh.h: RMH_E_PARAM already defined"
#endif

/**
 * \brief Macro definition of error code RMH_E_PARAM API service of RMH called
 *        with wrong parameter
 */
#define       RMH_E_PARAM              0x01U

#if (defined RMH_E_RETURN)
#error "Rmh.h: RMH_E_RETURN already defined"
#endif

/**
 * \brief Macro definition of error code RMH_E_RETURN API service of other
 *        module called by RMH with unexpected return value
 */
#define       RMH_E_RETURN             0x02U

/*--------------------[Configuration]-----------------------------------------*/
#if (defined RMH_INSTANCE_ID)
#error "Rmh.h: RMH_INSTANCE_ID already defined"
#endif

/**
 * \brief Macro definition of the Rmh Instance ID
 */
#define       RMH_INSTANCE_ID          0x00U

#if (defined RMH_TRIGGER_VALUE)
#error "Rmh.h: RMH_TRIGGER_VALUE already defined"
#endif

/**
 * \brief Macro definition of RMH_TRIGGER_VALUE for dummy signal trigger
 */
#define       RMH_TRIGGER_VALUE        0x01U

#if (defined RMH_RMID_INVALID_VALUE)
#error "Rmh.h: RMH_RMID_INVALID_VALUE already defined"
#endif

/**
 * \brief Macro definition of Rmh request message id invalid value
 */
#define       RMH_RMID_INVALID_VALUE   0xFFFFU


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


#endif /* RMH_CLASSIC_H */

/*--- End of file ------------------------------------------------------------*/
