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
 *  \addtogroup Os_Hal_Os
 *  \{
 *
 *  \file       Os_Hal_Os.h
 *  \brief      HAL interfaces which are visible to the user.
 *
 **********************************************************************************************************************/
/***********************************************************************************************************************
 *  AUTHOR IDENTITY
 *  --------------------------------------------------------------------------------------------------------------------
 *  Name                          Initials      Company
 *  --------------------------------------------------------------------------------------------------------------------
 *  Benjamin Seifert              virbse        Vctr Informatik GmbH
 *  Bilal Parvez                  visbpz        Vctr Informatik GmbH
 *  Da He                         visdhe        Vctr Informatik GmbH
 *  Michael Kock                  vismkk        Vctr Informatik GmbH
 *  Senol Cendere                 visces        Vctr Informatik GmbH
 *  Stefano Simoncelli            virsso        Vctr Informatik GmbH
 *  Torsten Schmidt               visto         Vctr Informatik GmbH
 *  David Feuerstein              visdfe        Vctr Informatik GmbH
 *  Bilal Parvez                  visbpz        Vctr Informatik GmbH
 *  Martin Schultheiss            virsmn        Vctr Informatik GmbH
 *  --------------------------------------------------------------------------------------------------------------------
 *  REVISION HISTORY
 *  --------------------------------------------------------------------------------------------------------------------
 *  Version   Date        Author  Change Id     Description
 *  --------------------------------------------------------------------------------------------------------------------
 *  01.00.00  2016-02-16  visces  -             Initial version
 *  01.00.01  2016-03-24  visces  -             Development version
 *  01.00.02  2016-04-25  visces  -             Development version
 *  01.00.03  2016-05-26  visces  -             Development version
 *  01.00.04  2016-06-22  visces  -             Development version
 *  01.00.05  2016-07-04  visces  -             QM Release
 *  01.00.06  2016-07-26  visces  -             Beta Release
 *  01.00.07  2016-08-01  visces  -             QM Release
 *                                              Fixed ESCAN00091248
 *  01.00.08  2016-08-24  visces  -             QM Release
 *                                              Fixed ESCAN00090971
 *                                              Fixed ESCAN00091490
 *                                              Fixed ESCAN00091503
 *  01.00.09  2016-09-08  visdhe  -             QM Release
 *                                FEAT-1931     Provide access to interrupt control register (Step2)
 *  01.00.10  2016-09-21  visces  -             QM Release
 *                                              Fixed ESCAN00091824
 *  01.01.00  2016-09-30  visces  -             QM Release
 *                                              Fixed ESCAN00092100
 *                                              Fixed ESCAN00091880
 *                                              Switch MPU in Os_Hal_CallFuncOnStack only for SC3 and SC4
 *  01.01.01  2016-10-28  vismkk                QM Release
 *                                              Added coverage justifications
 *  01.02.00  2016-11-04  virsso  WORKITEM9682  Added ReviewHelper justifications and countermeasures
 *                        virbse                Updated Generator to latest BSWMD version
 *  01.03.00  2016-11-28  visdhe  WORKITEM10645 Code Coverage Analysis
 *  01.04.00  2016-12-02  vismkk  WORKITEM11170 Extended naming convention for HAL context interface
 *                        virbse  WORKITEM11413 Reworked Os_Hal_DerivativeInt.h to use OS_CFG_DERIVATIVEGROUP_x defines
 *  01.05.00  2016-12-15  -       -             Internal improvements
 *  01.06.00  2017-01-20  -       -             Internal improvements
 *  02.00.00  2017-02-01  -       -             Internal improvements
 *  02.01.00  2017-03-20  visdhe  ESCAN00094148 The cross core communication does work on systems with mixed core IDs
 *  02.02.00  2017-03-28  visto   WORKITEM14883 Keep compatibility to core generator
 *  02.03.00  2017-05-11  virsmn  ESCAN00094346 Interrupt initialization fails if the OS master core does not have full
 *                                              access to all hardware registers
 *  02.04.00  2017-06-01  visdfe  ESCAN00094046 Wrong validation of the maximum available MPU regions
 *            2017-06-14  visces  ESCAN00094888 Stack protection is disabled when PreTaskHook runs for the first time
 *  02.05.00  2017-06-28  visces  ESCAN00094900 Compiler error: "non-void function "OS_HAL_ISR1_DEFINE" should return 
 *                                              a value"
 *                                STORYC-1306   Added support for category 0 ISRs
 *  02.06.00  2017-07-12  visces  STORYC-1176   Support RH850 P1M-C and P1H-C with extended support for timer STM.
 *            2017-07-13  visces  STORYC-1209   Support all internal processor interrupts for XSignal interrupts.
 *            2017-07-13  visces  ESCAN00095798 Cross core communication does not work
 *            2017-07-14  visces  ESCAN00095885 Missing global interrupt lock leads to an unstable system state
 *  02.07.00  2017-07-24  virsmn  ESCAN00094867 Compiler warning: warning #1514-D: incorrect GHS #pragma: small data
 *                                              area is not supported in this configuration
 *            2017-07-25  visces  STORYC-1799   Added support for derivative F1KM
 *  02.08.00  2017-08-16  visces  STORYC-2063   Added core1 for E1xFCCS
 *  02.09.00  2017-09-14  vismkk  STORYC-1658   #Core:Generator: Remove support of IOC inline interface
 *  02.10.00  2017-10-25  visces  ESCAN00095552 Free Running Timers configured as non High Resolution Counters do not 
 *                                              work properly.
 *  02.11.00  2017-10-18  virbse  FEAT-2816     Support shared stack for non-preemptive Basic tasks
 *                                FEAT-2815     Support shared stack for tasks with same internal resource
 *  02.12.00  2017-11-03  virsmn  ESCAN00096854 Usage of High Resolution Timer and Master Protection Mechanism of INTC
 *                                              could lead to protection violation.
 *  02.13.00  2017-11-22  visbpz  STORYC-1751   Performance improvements by performing traps only from user mode
 *                        visbpz  STORY-2769    OS Interrupt API optimization by replacement of a call sequence for 
 *                                              modification of the global interrupt flag.
 **********************************************************************************************************************/

#if !defined (OS_HAL_OS_H)                                                                                              /* PRQA S 0883 */ /* MD_Os_Hal_0883 */
# define OS_HAL_OS_H

/***********************************************************************************************************************
 *  INCLUDES
 **********************************************************************************************************************/
/* AUTOSAR includes */
# include "Std_Types.h"

/* Os module declarations */
# include "Os_Hal_OsInt.h"

/* Os kernel module dependencies */
# include "Os_Lcfg.h"

/* Os HAL dependencies */


/***********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 **********************************************************************************************************************/
/* ----- Component version information ----- */
# define OS_HAL_SW_MAJOR_VERSION   (2u)
# define OS_HAL_SW_MINOR_VERSION   (13u)
# define OS_HAL_SW_PATCH_VERSION   (0u)

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

#endif /* OS_HAL_OS_H */

/*!
 * \}
 */

/***********************************************************************************************************************
 *  END OF FILE: Os_Hal_Os.h
 **********************************************************************************************************************/

