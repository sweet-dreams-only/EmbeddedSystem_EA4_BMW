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
 * \addtogroup Os_Lock
 *
 * \{
 *
 * \file
 * \brief       Interface implementation of lock objects.
 * \details     --no details--
 *
 *
 **********************************************************************************************************************/
/***********************************************************************************************************************
 *  REVISION HISTORY
 *  --------------------------------------------------------------------------------------------------------------------
 *  Refer to Os.h.
 **********************************************************************************************************************/

#if !defined(OS_LOCK_H)                                                                                                 /* PRQA S 0883 */ /* MD_Os_0883 */
# define OS_LOCK_H

/***********************************************************************************************************************
 *  INCLUDES
 **********************************************************************************************************************/
/* AUTOSAR includes */
# include "Std_Types.h"

/* Os module declarations */
# include "Os_Lock_Types.h"
# include "Os_LockInt.h"

/* Os module dependencies */
# include "Os_Error.h"
# include "Os_Application.h"

/* Os Hal dependencies */
#include "Os_Hal_Compiler.h"

#if !defined(OS_VCAST_INSTRUMENTATION_OS_LOCK)
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

# define OS_START_SEC_CODE
# include "Os_MemMap_OsCode.h"                                                                                          /* PRQA S 5087 */ /* MD_MSR_19.1 */

/***********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 **********************************************************************************************************************/

/***********************************************************************************************************************
 *  Os_LockListInit()
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE void, OS_CODE,                                                             /* PRQA S 3219 */ /* MD_Os_3219 */
OS_ALWAYS_INLINE, Os_LockListInit,
(
  P2VAR(Os_LockListType, AUTOMATIC, OS_CONST) LockList
))
{
  *LockList = OS_LOCK_LIST_END;                                                                                         /* SBSW_OS_PWA_PRECONDITION */
}

/***********************************************************************************************************************
 *  Os_LockListPush()
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE void, OS_CODE,                                                             /* PRQA S 3219 */ /* MD_Os_3219 */
OS_ALWAYS_INLINE, Os_LockListPush,
(
  P2VAR(Os_LockListType, AUTOMATIC, OS_CONST) LockList,
  P2CONST(Os_LockConfigType, AUTOMATIC, OS_CONST) Lock
))
{
  Lock->Dyn->Next = *LockList;                                                                                          /* SBSW_OS_LOCK_LOCKGETDYN_001 */
  *LockList = Lock;                                                                                                     /* SBSW_OS_PWA_PRECONDITION */
}

/***********************************************************************************************************************
 *  Os_LockListPop()
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE void, OS_CODE,                                                             /* PRQA S 3219 */ /* MD_Os_3219 */
OS_ALWAYS_INLINE, Os_LockListPop,
(
  P2VAR(Os_LockListType, AUTOMATIC, OS_VAR_NOINIT) LockList
))
{
  P2CONST(Os_LockConfigType, AUTOMATIC, OS_CONST) lock;

  lock = *LockList;
  *LockList = lock->Dyn->Next;                                                                                          /* SBSW_OS_PWA_PRECONDITION */
  lock->Dyn->Next = OS_LOCK_NOT_LINKED;                                                                                 /* PRQA S 0306 */ /* MD_Os_0306_ListEnd */ /* SBSW_OS_LOCK_LOCKGETDYN_001 */
}

/***********************************************************************************************************************
 *  Os_LockListDelete()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE void, OS_CODE,                                                             /* PRQA S 3219, 3673 */ /* MD_Os_3219, MD_Os_3673_ModifiedArgument */ /* COV_OS_HALPLATFORMMULTICOREUNSUPPORTED */
OS_ALWAYS_INLINE, Os_LockListDelete,
(
  P2VAR(Os_LockListType, AUTOMATIC, OS_VAR_NOINIT) LockList,
  P2CONST(Os_LockConfigType, AUTOMATIC, OS_CONST) Lock
))                                                                                                                      /* COV_OS_HALPLATFORMMULTICOREUNSUPPORTED */
{
  Os_LockListType  *it;

  it = LockList;

  while(Os_LockListIsEmpty(it) == 0)                                                                                    /* COV_OS_INVSTATE */ /* SBSW_OS_LOCK_LOCKLISTISEMPTY_001 */
  {
    if(Lock == *it)
    {
      *it = Lock->Dyn->Next;                                                                                            /* SBSW_OS_PWA_PRECONDITION */
      Lock->Dyn->Next = OS_LOCK_NOT_LINKED;                                                                             /* PRQA S 0306 */ /* MD_Os_0306_ListEnd */ /* SBSW_OS_PWA_PRECONDITION */
      break;
    }
    it = Os_LockListNextIterator(it);                                                                                   /* SBSW_OS_LOCK_LOCKLISTNEXTITERATOR_001 */
  }
}

/***********************************************************************************************************************
 *  Os_LockListNext()
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE P2CONST(Os_LockConfigType, AUTOMATIC, OS_CONST), OS_CODE,                  /* COV_OS_HALPLATFORMMULTICOREUNSUPPORTED */
OS_ALWAYS_INLINE, Os_LockListNext,
(
  P2CONST(Os_LockConfigType, AUTOMATIC, OS_CONST) Lock
))                                                                                                                      /* COV_OS_HALPLATFORMMULTICOREUNSUPPORTED */
{
  return Lock->Dyn->Next;
}

/***********************************************************************************************************************
 *  Os_LockListNextIterator()
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE P2VAR(Os_LockListType, AUTOMATIC, OS_VAR_NOINIT) , OS_CODE,                /* COV_OS_HALPLATFORMMULTICOREUNSUPPORTED */
OS_ALWAYS_INLINE, Os_LockListNextIterator,
(
  P2CONST(Os_LockListType, AUTOMATIC, OS_VAR_NOINIT) Iterator
))                                                                                                                      /* COV_OS_HALPLATFORMMULTICOREUNSUPPORTED */
{
  return &((*Iterator)->Dyn->Next);
}

/***********************************************************************************************************************
 *  Os_LockListIsEmpty()
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE Os_StdReturnType, OS_CODE,                                                 /* PRQA S 3219 */ /* MD_Os_3219 */
OS_ALWAYS_INLINE, Os_LockListIsEmpty,
(
  P2CONST(Os_LockListType, AUTOMATIC, OS_CONST) LockList
))
{
  return ((Os_StdReturnType)(*LockList == OS_LOCK_LIST_END));
}

/***********************************************************************************************************************
 *  Os_LockListIsTopRes()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE Os_StdReturnType, OS_CODE,                                                 /* PRQA S 3219 */ /* MD_Os_3219 */
OS_ALWAYS_INLINE, Os_LockListIsTopRes,
(
  P2CONST(Os_LockListType, AUTOMATIC, OS_VAR_NOINIT) LockList
))
{
  Os_StdReturnType result;

  result = 0;

  /* #10 If the list is not empty */
  if(Os_LockListIsEmpty(LockList) == 0)                                                                                 /* SBSW_OS_FC_PRECONDITION */
  {
    /* #20 and if the top element is a resource: return !0  */
    result = (Os_StdReturnType)(Os_LockIsResource(*LockList) != 0);                                                     /* SBSW_OS_LOCK_LOCKISRESOURCE_001 */
  }

  /* #30 otherwise return 0. */
  return result;
}

/***********************************************************************************************************************
 *  Os_LockListCheckIsListTop()
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE Os_StdReturnType, OS_CODE,                                                 /* PRQA S 3219 */ /* MD_Os_3219 */
OS_ALWAYS_INLINE, Os_LockListCheckIsListTop,
(
  P2CONST(Os_LockListType, AUTOMATIC, OS_VAR_NOINIT) LockList,
  P2CONST(Os_LockConfigType, AUTOMATIC, OS_CONST) Lock
))
{
  return Os_ErrExtendedCheck((Os_StdReturnType)(*LockList == Lock));
}

/***********************************************************************************************************************
 *  Os_LockListCheckTopIsRes()
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE Os_StdReturnType, OS_CODE,                                                 /* PRQA S 3219 */ /* MD_Os_3219 */
OS_ALWAYS_INLINE, Os_LockListCheckTopIsRes,
(
  P2CONST(Os_LockListType, AUTOMATIC, OS_VAR_NOINIT) LockList
))
{
  return Os_ErrExtendedCheck( Os_LockListIsTopRes(LockList) );                                                          /* SBSW_OS_FC_PRECONDITION */
}

/***********************************************************************************************************************
 *  Os_LockListIsTopSpinlock()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE Os_StdReturnType, OS_CODE,                                                 /* PRQA S 3219 */ /* MD_Os_3219 */
OS_ALWAYS_INLINE, Os_LockListIsTopSpinlock,
(
  P2CONST(Os_LockListType, AUTOMATIC, OS_VAR_NOINIT) LockList
))
{
  Os_StdReturnType result;

  result = 0;

  /* #10 If the list is not empty. */
  if(Os_LockListIsEmpty(LockList) == 0)                                                                                 /* SBSW_OS_FC_PRECONDITION */
  {
    /* #20 And if the top element is a spinlock: return !0. */
    result = (Os_StdReturnType)(((*LockList)->Type == OS_LOCKTYPE_SPINLOCK));
  }

  /* #30 Otherwise return 0. */
  return result;
}

/***********************************************************************************************************************
 *  Os_LockListCheckTopIsSpinlock()
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE Os_StdReturnType, OS_CODE,                                                 /* PRQA S 3219 */ /* MD_Os_3219 */
OS_ALWAYS_INLINE, Os_LockListCheckTopIsSpinlock,
(
  P2CONST(Os_LockListType, AUTOMATIC, OS_VAR_NOINIT) LockList
))
{
  return Os_ErrExtendedCheck( Os_LockListIsTopSpinlock(LockList) );                                                     /* SBSW_OS_FC_PRECONDITION */
}

/***********************************************************************************************************************
 *  Os_LockListGetTop()
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE                                                                            /* PRQA S 3219 */ /* MD_Os_3219 */
P2CONST(Os_LockConfigType, AUTOMATIC, OS_CONST), OS_CODE, OS_ALWAYS_INLINE, Os_LockListGetTop,
(
  P2CONST(Os_LockListType, AUTOMATIC, OS_VAR_NOINIT) LockList
))
{
  return (*LockList);
}

/***********************************************************************************************************************
 *  Os_LockInit()
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE void, OS_CODE,                                                             /* PRQA S 3219 */ /* MD_Os_3219 */
OS_ALWAYS_INLINE, Os_LockInit,
(
  P2CONST(Os_LockConfigType, AUTOMATIC, OS_CONST) Lock
))
{
  Lock->Dyn->Next = OS_LOCK_NOT_LINKED;                                                                                 /* PRQA S 0306 */ /* MD_Os_0306_ListEnd */ /* SBSW_OS_LOCK_LOCKGETDYN_001 */
}

/***********************************************************************************************************************
 *  Os_LockIsIntResource()
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE Os_StdReturnType, OS_CODE,                                                 /* PRQA S 3219 */ /* MD_Os_3219 */
OS_ALWAYS_INLINE, Os_LockIsIntResource,
(
  P2CONST(Os_LockConfigType, AUTOMATIC, OS_CONST) Lock
))
{
  return (Os_StdReturnType)(Lock->Type == OS_LOCKTYPE_RESOURCE_INTERRUPT);
}

/***********************************************************************************************************************
 *  Os_LockIsResource()
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE Os_StdReturnType, OS_CODE,                                                 /* PRQA S 3219 */ /* MD_Os_3219 */
OS_ALWAYS_INLINE, Os_LockIsResource,
(
  P2CONST(Os_LockConfigType, AUTOMATIC, OS_CONST) Lock
))
{
  return (Os_StdReturnType)(    (Lock->Type == OS_LOCKTYPE_RESOURCE_STANDARD)
                            ||  (Lock->Type == OS_LOCKTYPE_RESOURCE_INTERRUPT));                                        /* COV_OS_HALPLATFORMMULTICOREUNSUPPORTED */
}

/***********************************************************************************************************************
 *  Os_LockCheckIsAvailable()
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE Os_StdReturnType, OS_CODE,                                                 /* PRQA S 3219 */ /* MD_Os_3219 */
OS_ALWAYS_INLINE, Os_LockCheckIsAvailable,
(
  P2CONST(Os_LockConfigType, AUTOMATIC, OS_CONST) Lock
))
{
  return Os_ErrExtendedCheck(
      (Os_StdReturnType)(Lock->Dyn->Next == OS_LOCK_NOT_LINKED));                                                       /* PRQA S 0306 */ /* MD_Os_0306_ListEnd */
}

/***********************************************************************************************************************
 *  Os_LockCheckIsOccupied()
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE Os_StdReturnType, OS_CODE,                                                 /* PRQA S 3219 */ /* MD_Os_3219 */
OS_ALWAYS_INLINE, Os_LockCheckIsOccupied,
(
  P2CONST(Os_LockConfigType, AUTOMATIC, OS_CONST) Lock
))
{
  return Os_ErrExtendedCheck(
      (Os_StdReturnType)(Lock->Dyn->Next != OS_LOCK_NOT_LINKED));                                                       /* PRQA S 0306 */ /* MD_Os_0306_ListEnd */
}

/***********************************************************************************************************************
 *  Os_LockGetDyn()
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE                                                                            /* PRQA S 3219 */ /* MD_Os_3219 */
P2VAR(Os_LockType, TYPEDEF, OS_VAR_NOINIT), OS_CODE, OS_ALWAYS_INLINE, Os_LockGetDyn,
(
  P2CONST(Os_LockConfigType, AUTOMATIC, OS_CONST) Lock
))
{
  return Lock->Dyn;
}

/***********************************************************************************************************************
 *  Os_LockGetAccessingApplications()
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE Os_AppAccessMaskType, OS_CODE,                                             /* PRQA S 3219 */ /* MD_Os_3219 */
OS_ALWAYS_INLINE, Os_LockGetAccessingApplications,
(
  P2CONST(Os_LockConfigType, AUTOMATIC, OS_CONST) Lock
))
{
  return Lock->AccessingApplications;
}

# define OS_STOP_SEC_CODE
# include "Os_MemMap_OsCode.h"                                                                                          /* PRQA S 5087 */ /* MD_MSR_19.1 */

#if !defined(OS_VCAST_INSTRUMENTATION_OS_LOCK)
/*VCAST_DONT_INSTRUMENT_END*/
#endif

#endif /* OS_LOCK_H */

/* module specific MISRA deviations:
 */

/*!
 * \}
 */
/***********************************************************************************************************************
 *  END OF FILE: Os_LockInt.h
 **********************************************************************************************************************/
