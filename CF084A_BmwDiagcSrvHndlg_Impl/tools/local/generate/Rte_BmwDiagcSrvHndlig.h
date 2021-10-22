/**********************************************************************************************************************
 *  COPYRIGHT
 *  -------------------------------------------------------------------------------------------------------------------
 *
 *                This software is copyright protected and proprietary to Vctr Informatik GmbH.
 *                Vctr Informatik GmbH grants to you only those rights as set out in the license conditions.
 *                All other rights remain with Vctr Informatik GmbH.
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *          File:  Rte_BmwDiagcSrvHndlig.h
 *        Config:  C:/Component/CF084A_BmwDiagcSrvHndlg_Impl/tools/Component.dpa
 *     SW-C Type:  BmwDiagcSrvHndlig
 *  Generated at:  Thu Nov 30 21:30:04 2017
 *
 *     Generator:  MICROSAR RTE Generator Version 4.13.0
 *                 RTE Core Version 1.13.0
 *       License:  Unlimited license CBD1400351 for Nxtr Automotive Corporation
 *
 *   Description:  Application header file for SW-C <BmwDiagcSrvHndlig> (Contract Phase)
 *********************************************************************************************************************/

/* double include prevention */
#ifndef _RTE_BMWDIAGCSRVHNDLIG_H
# define _RTE_BMWDIAGCSRVHNDLIG_H

# ifdef RTE_APPLICATION_HEADER_FILE
#  error Multiple application header files included.
# endif
# define RTE_APPLICATION_HEADER_FILE
# ifndef RTE_PTR2ARRAYBASETYPE_PASSING
#  define RTE_PTR2ARRAYBASETYPE_PASSING
# endif

# ifdef __cplusplus
extern "C"
{
# endif /* __cplusplus */

/* include files */

# include "Rte_BmwDiagcSrvHndlig_Type.h"
# include "Rte_DataHandleType.h"


/**********************************************************************************************************************
 * Component Data Structures and Port Data Structures
 *********************************************************************************************************************/

struct Rte_CDS_BmwDiagcSrvHndlig
{
  /* dummy entry */
  uint8 _dummy;
};

# define RTE_START_SEC_CONST_UNSPECIFIED
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

extern CONSTP2CONST(struct Rte_CDS_BmwDiagcSrvHndlig, RTE_CONST, RTE_CONST) Rte_Inst_BmwDiagcSrvHndlig; /* PRQA S 0850 */ /* MD_MSR_19.8 */

# define RTE_STOP_SEC_CONST_UNSPECIFIED
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

typedef P2CONST(struct Rte_CDS_BmwDiagcSrvHndlig, TYPEDEF, RTE_CONST) Rte_Instance;


# define RTE_START_SEC_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/**********************************************************************************************************************
 * API prototypes
 *********************************************************************************************************************/
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_BmwDiagcSrvHndlig_RackCentrMotAgErrPrsnt_Logl(P2VAR(boolean, AUTOMATIC, RTE_BMWDIAGCSRVHNDLIG_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_BmwDiagcSrvHndlig_TotRackTrvl_Val(P2VAR(float32, AUTOMATIC, RTE_BMWDIAGCSRVHNDLIG_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */

# define RTE_STOP_SEC_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */



/**********************************************************************************************************************
 * Rte_Read_<p>_<d> (explicit S/R communication with isQueued = false)
 *********************************************************************************************************************/
# define Rte_Read_RackCentrMotAgErrPrsnt_Logl Rte_Read_BmwDiagcSrvHndlig_RackCentrMotAgErrPrsnt_Logl
# define Rte_Read_TotRackTrvl_Val Rte_Read_BmwDiagcSrvHndlig_TotRackTrvl_Val




# define BmwDiagcSrvHndlig_START_SEC_CODE
# include "BmwDiagcSrvHndlig_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


/**********************************************************************************************************************
 *
 * Runnable Entity Name: BmwDiagcSrvHndlgInit1
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed once after the RTE is started
 *
 **********************************************************************************************************************
 *
 * Input Interfaces:
 * =================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Read_RackCentrMotAgErrPrsnt_Logl(boolean *data)
 *   Std_ReturnType Rte_Read_TotRackTrvl_Val(float32 *data)
 *
 *********************************************************************************************************************/

# define RTE_RUNNABLE_BmwDiagcSrvHndlgInit1 BmwDiagcSrvHndlgInit1
FUNC(void, BmwDiagcSrvHndlig_CODE) BmwDiagcSrvHndlgInit1(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */

/**********************************************************************************************************************
 *
 * Runnable Entity Name: BmwDiagcSrvHndlgPer1
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered on TimingEvent every 10ms
 *
 *********************************************************************************************************************/

# define RTE_RUNNABLE_BmwDiagcSrvHndlgPer1 BmwDiagcSrvHndlgPer1
FUNC(void, BmwDiagcSrvHndlig_CODE) BmwDiagcSrvHndlgPer1(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */

# define BmwDiagcSrvHndlig_STOP_SEC_CODE
# include "BmwDiagcSrvHndlig_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

# ifdef __cplusplus
} /* extern "C" */
# endif /* __cplusplus */

#endif /* _RTE_BMWDIAGCSRVHNDLIG_H */
