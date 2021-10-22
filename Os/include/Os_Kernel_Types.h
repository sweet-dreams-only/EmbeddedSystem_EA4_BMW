/***********************************************************************************************************************
 *  COPYRIGHT
 *  --------------------------------------------------------------------------------------------------------------------
 *  \verbatim
 *  Copyright (c) 2017 by Vctr Informatik GmbH.                                              All rights reserved.
 *
 *                This software is copyright protected and proprietary to Vctr Informatik GmbH.
 *                Vctr Informatik GmbH grants to you only those rights as set out in the license conditions.
 *                All other rights remain with Vctr Informatik GmbH.
 *  \endverbatim
 *  --------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  ------------------------------------------------------------------------------------------------------------------*/
/**
 * \addtogroup    Os_Kernel
 * \{
 *
 *
 * \file
 * \brief      This interface provides high-level kernel types.
 * \details    --no details--
 **********************************************************************************************************************/
/***********************************************************************************************************************
 *  REVISION HISTORY
 *  --------------------------------------------------------------------------------------------------------------------
 *  Refer to Os.h.
 **********************************************************************************************************************/


#if !defined (OS_KERNEL_TYPES_H)                                                                                        /* PRQA S 0883 */ /* MD_Os_0883 */
# define OS_KERNEL_TYPES_H

/***********************************************************************************************************************
 *  INCLUDES
 **********************************************************************************************************************/
/* AUTOSAR includes */
# include "Std_Types.h"

/* Os module declarations */

/* Os module dependencies */
# include "Os_Common_Types.h"
# include "Os_Isr_Types.h"
# include "Os_Core_Types.h"
# include "Os_Error_Types.h"
# include "Os_Interrupt_Types.h"
# include "Os_Task_Types.h"
# include "Os_Counter_Types.h"
# include "Os_Alarm_Types.h"
# include "Os_Resource_Types.h"
# include "Os_ScheduleTable_Types.h"
# include "Os_Application_Types.h"
# include "Os_Peripheral_Types.h"
# include "Os_Spinlock_Types.h"
# include "Os_ServiceFunction_Types.h"


/* Os Hal dependencies */

#if !defined(OS_VCAST_INSTRUMENTATION_OS_KERNEL)
/*VCAST_DONT_INSTRUMENT_START*/
#endif

/***********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 **********************************************************************************************************************/


/***********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 **********************************************************************************************************************/

/***********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 **********************************************************************************************************************/


/***********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 **********************************************************************************************************************/


/***********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 **********************************************************************************************************************/



#if !defined(OS_VCAST_INSTRUMENTATION_OS_KERNEL)
/*VCAST_DONT_INSTRUMENT_END*/
#endif

#endif /* OS_KERNEL_TYPES_H */

/* module specific MISRA deviations:
 */

/*!
 * \}
 */

/***********************************************************************************************************************
 *  END OF FILE: Os_Kernel_Types.h
 **********************************************************************************************************************/

