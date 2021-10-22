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
 * \addtogroup Os_Spinlock
 *
 * \{
 *
 * \file
 * \brief       Data types provided by \ref Os_Spinlock.
 * \details     --no details--
 *
 *
 **********************************************************************************************************************/
/***********************************************************************************************************************
 *  REVISION HISTORY
 *  --------------------------------------------------------------------------------------------------------------------
 *  Refer to Os.h.
 **********************************************************************************************************************/

#if !defined(OS_SPINLOCK_TYPES_H)                                                                                       /* PRQA S 0883 */ /* MD_Os_0883 */
# define OS_SPINLOCK_TYPES_H

/***********************************************************************************************************************
 *  INCLUDES
 **********************************************************************************************************************/
# include "Std_Types.h"


/***********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 **********************************************************************************************************************/


/***********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 **********************************************************************************************************************/


/***********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 **********************************************************************************************************************/
struct Os_SpinlockType_Tag;
typedef struct Os_SpinlockType_Tag Os_SpinlockType;


struct Os_SpinlockConfigType_Tag;
typedef struct Os_SpinlockConfigType_Tag Os_SpinlockConfigType;


/*! Linked list of spinlocks. */
typedef P2CONST(Os_SpinlockConfigType, TYPEDEF, OS_CONST) Os_SpinlockListType;


/***********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 **********************************************************************************************************************/


/***********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 **********************************************************************************************************************/


/***********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 **********************************************************************************************************************/



#endif /* OS_SPINLOCK_TYPES_H */

/* module specific MISRA deviations:
 */

/*!
 * \}
 */
/***********************************************************************************************************************
 *  END OF FILE: Os_Spinlock_Types.h
 **********************************************************************************************************************/
