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
 *          File:  Rte_CDD_ChkPtAppl9.h
 *     SW-C Type:  CDD_ChkPtAppl9
 *  Generated at:  Wed Nov  1 13:31:57 2017
 *
 *     Generator:  MICROSAR RTE Generator Version 4.3.0
 *                 RTE Core Version 1.3.0
 *       License:  Unlimited license CBD1400351 (THE ECU PRODUCT "STEERING SYSTEMS", THE ECU SUPPLIER "NXTR", THE VEHICLE MANUFACTURER "GENERAL MOTORS CORPORATION") for Nxtr Automotive Corporation
 *
 *   Description:  Application header file for SW-C <CDD_ChkPtAppl9> (Contract Phase)
 *********************************************************************************************************************/

/* double include prevention */
#ifndef _RTE_CDD_CHKPTAPPL9_H
# define _RTE_CDD_CHKPTAPPL9_H

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

# include "Rte_CDD_ChkPtAppl9_Type.h"
# include "Rte_DataHandleType.h"


/**********************************************************************************************************************
 * Component Data Structures and Port Data Structures
 *********************************************************************************************************************/

struct Rte_CDS_CDD_ChkPtAppl9
{
  /* dummy entry */
  uint8 _dummy;
};

# define RTE_START_SEC_CONST_UNSPECIFIED
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

extern CONSTP2CONST(struct Rte_CDS_CDD_ChkPtAppl9, RTE_CONST, RTE_CONST) Rte_Inst_CDD_ChkPtAppl9; /* PRQA S 0850 */ /* MD_MSR_19.8 */

# define RTE_STOP_SEC_CONST_UNSPECIFIED
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

typedef P2CONST(struct Rte_CDS_CDD_ChkPtAppl9, TYPEDEF, RTE_CONST) Rte_Instance;


# define RTE_START_SEC_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/**********************************************************************************************************************
 * API prototypes
 *********************************************************************************************************************/
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_CDD_ChkPtAppl9_ChkPt_100ms_Appl9_End_CheckpointReached(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_CDD_ChkPtAppl9_ChkPt_100ms_Appl9_Strt_CheckpointReached(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_CDD_ChkPtAppl9_ChkPt_10ms_Appl9_End_CheckpointReached(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_CDD_ChkPtAppl9_ChkPt_10ms_Appl9_Strt_CheckpointReached(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_CDD_ChkPtAppl9_ChkPt_2ms_Appl9_End_CheckpointReached(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_CDD_ChkPtAppl9_ChkPt_2ms_Appl9_Strt_CheckpointReached(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */

# define RTE_STOP_SEC_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */



/**********************************************************************************************************************
 * Rte_Call_<p>_<o> (C/S invocation)
 *********************************************************************************************************************/
# define Rte_Call_ChkPt_100ms_Appl9_End_CheckpointReached Rte_Call_CDD_ChkPtAppl9_ChkPt_100ms_Appl9_End_CheckpointReached
# define Rte_Call_ChkPt_100ms_Appl9_Strt_CheckpointReached Rte_Call_CDD_ChkPtAppl9_ChkPt_100ms_Appl9_Strt_CheckpointReached
# define Rte_Call_ChkPt_10ms_Appl9_End_CheckpointReached Rte_Call_CDD_ChkPtAppl9_ChkPt_10ms_Appl9_End_CheckpointReached
# define Rte_Call_ChkPt_10ms_Appl9_Strt_CheckpointReached Rte_Call_CDD_ChkPtAppl9_ChkPt_10ms_Appl9_Strt_CheckpointReached
# define Rte_Call_ChkPt_2ms_Appl9_End_CheckpointReached Rte_Call_CDD_ChkPtAppl9_ChkPt_2ms_Appl9_End_CheckpointReached
# define Rte_Call_ChkPt_2ms_Appl9_Strt_CheckpointReached Rte_Call_CDD_ChkPtAppl9_ChkPt_2ms_Appl9_Strt_CheckpointReached




# define CDD_ChkPtAppl9_START_SEC_CODE
# include "CDD_ChkPtAppl9_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


/**********************************************************************************************************************
 *
 * Runnable Entity Name: ChkPt_100msAppl9End
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
 *   Std_ReturnType Rte_Call_ChkPt_100ms_Appl9_End_CheckpointReached(void)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_WdgM_AliveSupervision_E_NOT_OK
 *
 *********************************************************************************************************************/

# define RTE_RUNNABLE_ChkPt_100msAppl9End ChkPt_100msAppl9End
FUNC(void, CDD_ChkPtAppl9_CODE) ChkPt_100msAppl9End(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */

/**********************************************************************************************************************
 *
 * Runnable Entity Name: ChkPt_100msAppl9Strt
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
 *   Std_ReturnType Rte_Call_ChkPt_100ms_Appl9_Strt_CheckpointReached(void)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_WdgM_AliveSupervision_E_NOT_OK
 *
 *********************************************************************************************************************/

# define RTE_RUNNABLE_ChkPt_100msAppl9Strt ChkPt_100msAppl9Strt
FUNC(void, CDD_ChkPtAppl9_CODE) ChkPt_100msAppl9Strt(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */

/**********************************************************************************************************************
 *
 * Runnable Entity Name: ChkPt_10msAppl9End
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
 *   Std_ReturnType Rte_Call_ChkPt_10ms_Appl9_End_CheckpointReached(void)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_WdgM_AliveSupervision_E_NOT_OK
 *
 *********************************************************************************************************************/

# define RTE_RUNNABLE_ChkPt_10msAppl9End ChkPt_10msAppl9End
FUNC(void, CDD_ChkPtAppl9_CODE) ChkPt_10msAppl9End(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */

/**********************************************************************************************************************
 *
 * Runnable Entity Name: ChkPt_10msAppl9Strt
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
 *   Std_ReturnType Rte_Call_ChkPt_10ms_Appl9_Strt_CheckpointReached(void)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_WdgM_AliveSupervision_E_NOT_OK
 *
 *********************************************************************************************************************/

# define RTE_RUNNABLE_ChkPt_10msAppl9Strt ChkPt_10msAppl9Strt
FUNC(void, CDD_ChkPtAppl9_CODE) ChkPt_10msAppl9Strt(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */

/**********************************************************************************************************************
 *
 * Runnable Entity Name: ChkPt_2msAppl9End
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
 *   Std_ReturnType Rte_Call_ChkPt_2ms_Appl9_End_CheckpointReached(void)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_WdgM_AliveSupervision_E_NOT_OK
 *
 *********************************************************************************************************************/

# define RTE_RUNNABLE_ChkPt_2msAppl9End ChkPt_2msAppl9End
FUNC(void, CDD_ChkPtAppl9_CODE) ChkPt_2msAppl9End(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */

/**********************************************************************************************************************
 *
 * Runnable Entity Name: ChkPt_2msAppl9Strt
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
 *   Std_ReturnType Rte_Call_ChkPt_2ms_Appl9_Strt_CheckpointReached(void)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_WdgM_AliveSupervision_E_NOT_OK
 *
 *********************************************************************************************************************/

# define RTE_RUNNABLE_ChkPt_2msAppl9Strt ChkPt_2msAppl9Strt
FUNC(void, CDD_ChkPtAppl9_CODE) ChkPt_2msAppl9Strt(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */

# define CDD_ChkPtAppl9_STOP_SEC_CODE
# include "CDD_ChkPtAppl9_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


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
#   if RTE_MAGIC_NUMBER != 1509566591
#    error "The magic number of the generated file <C:/Component/BMW_001A_ChkPt_Impl/tools/contract/CDD_ChkPtAppl9/Rte_CDD_ChkPtAppl9.h> is different. Please check time and date of the generated RTE files!"
#   endif
#  else
#   define RTE_MAGIC_NUMBER 1509566591
#  endif  /* RTE_MAGIC_NUMBER */
# endif  /* SKIP_MAGIC_NUMBER */
/* end Fileversion check */

#endif /* _RTE_CDD_CHKPTAPPL9_H */
