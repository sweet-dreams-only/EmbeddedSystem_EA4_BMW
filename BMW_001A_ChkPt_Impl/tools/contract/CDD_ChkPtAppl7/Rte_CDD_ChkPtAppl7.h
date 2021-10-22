/**********************************************************************************************************************
 *  COPYRIGHT
 *  -------------------------------------------------------------------------------------------------------------------
 *  Copyright (c) 2006-2014 by Vctr Informatik GmbH.                                             All rights reserved.
 *
 *                This software is copyright protected and proprietary to Vctr Informatik GmbH.
 *                Vctr Informatik GmbH grants to you only those rights as set out in the license conditions.
 *                All other rights remain with Vctr Informatik GmbH.
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *          File:  Rte_CDD_ChkPtAppl7.h
 *     SW-C Type:  CDD_ChkPtAppl7
 *  Generated at:  Wed Nov  1 13:31:53 2017
 *
 *     Generator:  MICROSAR RTE Generator Version 4.3.0
 *                 RTE Core Version 1.3.0
 *       License:  Unlimited license CBD1400351 (THE ECU PRODUCT "STEERING SYSTEMS", THE ECU SUPPLIER "NXTR", THE VEHICLE MANUFACTURER "GENERAL MOTORS CORPORATION") for Nxtr Automotive Corporation
 *
 *   Description:  Application header file for SW-C <CDD_ChkPtAppl7> (Contract Phase)
 *********************************************************************************************************************/

/* double include prevention */
#ifndef _RTE_CDD_CHKPTAPPL7_H
# define _RTE_CDD_CHKPTAPPL7_H

# ifdef RTE_APPLICATION_HEADER_FILE
#  error Multiple application header files included.
# endif
# define RTE_APPLICATION_HEADER_FILE
# define RTE_PTR2ARRAYBASETYPE_PASSING

# ifdef __cplusplus
extern "C"
{
# endif /* __cplusplus */

/* include files */

# include "Rte_CDD_ChkPtAppl7_Type.h"
# include "Rte_DataHandleType.h"


/**********************************************************************************************************************
 * Component Data Structures and Port Data Structures
 *********************************************************************************************************************/

struct Rte_CDS_CDD_ChkPtAppl7
{
  /* dummy entry */
  uint8 _dummy;
};

# define RTE_START_SEC_CONST_UNSPECIFIED
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

extern CONSTP2CONST(struct Rte_CDS_CDD_ChkPtAppl7, RTE_CONST, RTE_CONST) Rte_Inst_CDD_ChkPtAppl7; /* PRQA S 0850 */ /* MD_MSR_19.8 */

# define RTE_STOP_SEC_CONST_UNSPECIFIED
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

typedef P2CONST(struct Rte_CDS_CDD_ChkPtAppl7, TYPEDEF, RTE_CONST) Rte_Instance;


# define RTE_START_SEC_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/**********************************************************************************************************************
 * API prototypes
 *********************************************************************************************************************/
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_CDD_ChkPtAppl7_ChkPt_100ms_Appl7_End_CheckpointReached(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_CDD_ChkPtAppl7_ChkPt_100ms_Appl7_Strt_CheckpointReached(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_CDD_ChkPtAppl7_ChkPt_10ms_Appl7_End_CheckpointReached(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_CDD_ChkPtAppl7_ChkPt_10ms_Appl7_Strt_CheckpointReached(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_CDD_ChkPtAppl7_ChkPt_2ms_Appl7_End_CheckpointReached(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_CDD_ChkPtAppl7_ChkPt_2ms_Appl7_Strt_CheckpointReached(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_CDD_ChkPtAppl7_ChkPt_4ms_Appl7_End_CheckpointReached(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_CDD_ChkPtAppl7_ChkPt_4ms_Appl7_Strt_CheckpointReached(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */

# define RTE_STOP_SEC_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */



/**********************************************************************************************************************
 * Rte_Call_<p>_<o> (C/S invocation)
 *********************************************************************************************************************/
# define Rte_Call_ChkPt_100ms_Appl7_End_CheckpointReached Rte_Call_CDD_ChkPtAppl7_ChkPt_100ms_Appl7_End_CheckpointReached
# define Rte_Call_ChkPt_100ms_Appl7_Strt_CheckpointReached Rte_Call_CDD_ChkPtAppl7_ChkPt_100ms_Appl7_Strt_CheckpointReached
# define Rte_Call_ChkPt_10ms_Appl7_End_CheckpointReached Rte_Call_CDD_ChkPtAppl7_ChkPt_10ms_Appl7_End_CheckpointReached
# define Rte_Call_ChkPt_10ms_Appl7_Strt_CheckpointReached Rte_Call_CDD_ChkPtAppl7_ChkPt_10ms_Appl7_Strt_CheckpointReached
# define Rte_Call_ChkPt_2ms_Appl7_End_CheckpointReached Rte_Call_CDD_ChkPtAppl7_ChkPt_2ms_Appl7_End_CheckpointReached
# define Rte_Call_ChkPt_2ms_Appl7_Strt_CheckpointReached Rte_Call_CDD_ChkPtAppl7_ChkPt_2ms_Appl7_Strt_CheckpointReached
# define Rte_Call_ChkPt_4ms_Appl7_End_CheckpointReached Rte_Call_CDD_ChkPtAppl7_ChkPt_4ms_Appl7_End_CheckpointReached
# define Rte_Call_ChkPt_4ms_Appl7_Strt_CheckpointReached Rte_Call_CDD_ChkPtAppl7_ChkPt_4ms_Appl7_Strt_CheckpointReached




# define CDD_ChkPtAppl7_START_SEC_CODE
# include "CDD_ChkPtAppl7_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


/**********************************************************************************************************************
 *
 * Runnable Entity Name: ChkPt_100msAppl7End
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered on TimingEvent every 100ms
 *
 **********************************************************************************************************************
 *
 * Service Calls:
 * ==============
 *   Service Invocation:
 *   -------------------
 *   Std_ReturnType Rte_Call_ChkPt_100ms_Appl7_End_CheckpointReached(void)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_WdgM_AliveSupervision_E_NOT_OK
 *
 *********************************************************************************************************************/

# define RTE_RUNNABLE_ChkPt_100msAppl7End ChkPt_100msAppl7End
FUNC(void, CDD_ChkPtAppl7_CODE) ChkPt_100msAppl7End(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */

/**********************************************************************************************************************
 *
 * Runnable Entity Name: ChkPt_100msAppl7Strt
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered on TimingEvent every 100ms
 *
 **********************************************************************************************************************
 *
 * Service Calls:
 * ==============
 *   Service Invocation:
 *   -------------------
 *   Std_ReturnType Rte_Call_ChkPt_100ms_Appl7_Strt_CheckpointReached(void)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_WdgM_AliveSupervision_E_NOT_OK
 *
 *********************************************************************************************************************/

# define RTE_RUNNABLE_ChkPt_100msAppl7Strt ChkPt_100msAppl7Strt
FUNC(void, CDD_ChkPtAppl7_CODE) ChkPt_100msAppl7Strt(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */

/**********************************************************************************************************************
 *
 * Runnable Entity Name: ChkPt_10msAppl7End
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered on TimingEvent every 10ms
 *
 **********************************************************************************************************************
 *
 * Service Calls:
 * ==============
 *   Service Invocation:
 *   -------------------
 *   Std_ReturnType Rte_Call_ChkPt_10ms_Appl7_End_CheckpointReached(void)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_WdgM_AliveSupervision_E_NOT_OK
 *
 *********************************************************************************************************************/

# define RTE_RUNNABLE_ChkPt_10msAppl7End ChkPt_10msAppl7End
FUNC(void, CDD_ChkPtAppl7_CODE) ChkPt_10msAppl7End(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */

/**********************************************************************************************************************
 *
 * Runnable Entity Name: ChkPt_10msAppl7Strt
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered on TimingEvent every 10ms
 *
 **********************************************************************************************************************
 *
 * Service Calls:
 * ==============
 *   Service Invocation:
 *   -------------------
 *   Std_ReturnType Rte_Call_ChkPt_10ms_Appl7_Strt_CheckpointReached(void)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_WdgM_AliveSupervision_E_NOT_OK
 *
 *********************************************************************************************************************/

# define RTE_RUNNABLE_ChkPt_10msAppl7Strt ChkPt_10msAppl7Strt
FUNC(void, CDD_ChkPtAppl7_CODE) ChkPt_10msAppl7Strt(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */

/**********************************************************************************************************************
 *
 * Runnable Entity Name: ChkPt_2msAppl7End
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered on TimingEvent every 2ms
 *
 **********************************************************************************************************************
 *
 * Service Calls:
 * ==============
 *   Service Invocation:
 *   -------------------
 *   Std_ReturnType Rte_Call_ChkPt_2ms_Appl7_End_CheckpointReached(void)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_WdgM_AliveSupervision_E_NOT_OK
 *
 *********************************************************************************************************************/

# define RTE_RUNNABLE_ChkPt_2msAppl7End ChkPt_2msAppl7End
FUNC(void, CDD_ChkPtAppl7_CODE) ChkPt_2msAppl7End(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */

/**********************************************************************************************************************
 *
 * Runnable Entity Name: ChkPt_2msAppl7Strt
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered on TimingEvent every 2ms
 *
 **********************************************************************************************************************
 *
 * Service Calls:
 * ==============
 *   Service Invocation:
 *   -------------------
 *   Std_ReturnType Rte_Call_ChkPt_2ms_Appl7_Strt_CheckpointReached(void)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_WdgM_AliveSupervision_E_NOT_OK
 *
 *********************************************************************************************************************/

# define RTE_RUNNABLE_ChkPt_2msAppl7Strt ChkPt_2msAppl7Strt
FUNC(void, CDD_ChkPtAppl7_CODE) ChkPt_2msAppl7Strt(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */

/**********************************************************************************************************************
 *
 * Runnable Entity Name: ChkPt_4msAppl7End
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered on TimingEvent every 4ms
 *
 **********************************************************************************************************************
 *
 * Service Calls:
 * ==============
 *   Service Invocation:
 *   -------------------
 *   Std_ReturnType Rte_Call_ChkPt_4ms_Appl7_End_CheckpointReached(void)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_WdgM_AliveSupervision_E_NOT_OK
 *
 *********************************************************************************************************************/

# define RTE_RUNNABLE_ChkPt_4msAppl7End ChkPt_4msAppl7End
FUNC(void, CDD_ChkPtAppl7_CODE) ChkPt_4msAppl7End(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */

/**********************************************************************************************************************
 *
 * Runnable Entity Name: ChkPt_4msAppl7Strt
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered on TimingEvent every 4ms
 *
 **********************************************************************************************************************
 *
 * Service Calls:
 * ==============
 *   Service Invocation:
 *   -------------------
 *   Std_ReturnType Rte_Call_ChkPt_4ms_Appl7_Strt_CheckpointReached(void)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_WdgM_AliveSupervision_E_NOT_OK
 *
 *********************************************************************************************************************/

# define RTE_RUNNABLE_ChkPt_4msAppl7Strt ChkPt_4msAppl7Strt
FUNC(void, CDD_ChkPtAppl7_CODE) ChkPt_4msAppl7Strt(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */

# define CDD_ChkPtAppl7_STOP_SEC_CODE
# include "CDD_ChkPtAppl7_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


/**********************************************************************************************************************
 * Application errors
 *********************************************************************************************************************/

# define RTE_E_WdgM_AliveSupervision_E_NOT_OK (1U)

# ifdef __cplusplus
} /* extern "C" */
# endif /* __cplusplus */

/* begin Fileversion check */
# ifndef SKIP_MAGIC_NUMBER
#  ifdef RTE_MAGIC_NUMBER
#   if RTE_MAGIC_NUMBER != 1509567804
#    error "The magic number of the generated file <C:/Component/BMW_001A_ChkPt_Impl/tools/contract/CDD_ChkPtAppl7/Rte_CDD_ChkPtAppl7.h> is different. Please check time and date of the generated RTE files!"
#   endif
#  else
#   define RTE_MAGIC_NUMBER 1509567804
#  endif  /* RTE_MAGIC_NUMBER */
# endif  /* SKIP_MAGIC_NUMBER */
/* end Fileversion check */

#endif /* _RTE_CDD_CHKPTAPPL7_H */
