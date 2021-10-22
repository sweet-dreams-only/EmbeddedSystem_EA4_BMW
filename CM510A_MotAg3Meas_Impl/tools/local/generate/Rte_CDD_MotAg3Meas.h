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
 *          File:  Rte_CDD_MotAg3Meas.h
 *        Config:  C:/Users/NZ5334/Documents/Synergy/Working/ses_dev_ea4/CM510A_MotAg3Meas_Impl/tools/Component.dpa
 *     SW-C Type:  CDD_MotAg3Meas
 *  Generated at:  Thu Mar 29 12:09:32 2018
 *
 *     Generator:  MICROSAR RTE Generator Version 4.13.0
 *                 RTE Core Version 1.13.0
 *       License:  Unlimited license CBD1400351 for Nxtr Automotive Corporation
 *
 *   Description:  Application header file for SW-C <CDD_MotAg3Meas> (Contract Phase)
 *********************************************************************************************************************/

/* double include prevention */
#ifndef _RTE_CDD_MOTAG3MEAS_H
# define _RTE_CDD_MOTAG3MEAS_H

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

# include "Rte_CDD_MotAg3Meas_Type.h"
# include "Rte_DataHandleType.h"


/**********************************************************************************************************************
 * Component Data Structures and Port Data Structures
 *********************************************************************************************************************/

struct Rte_CDS_CDD_MotAg3Meas
{
  /* dummy entry */
  uint8 _dummy;
};

# define RTE_START_SEC_CONST_UNSPECIFIED
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

extern CONSTP2CONST(struct Rte_CDS_CDD_MotAg3Meas, RTE_CONST, RTE_CONST) Rte_Inst_CDD_MotAg3Meas; /* PRQA S 0850 */ /* MD_MSR_19.8 */

# define RTE_STOP_SEC_CONST_UNSPECIFIED
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

typedef P2CONST(struct Rte_CDS_CDD_MotAg3Meas, TYPEDEF, RTE_CONST) Rte_Instance;


/**********************************************************************************************************************
 * Init Values for unqueued S/R communication (primitive types only)
 *********************************************************************************************************************/

# define Rte_InitValue_MotAgMecl3Polarity_Val (1)


# define RTE_START_SEC_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/**********************************************************************************************************************
 * API prototypes
 *********************************************************************************************************************/
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CDD_MotAg3Meas_MotAgMecl3Polarity_Val(P2VAR(sint8, AUTOMATIC, RTE_CDD_MOTAG3MEAS_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */

# define RTE_STOP_SEC_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */



/**********************************************************************************************************************
 * Rte_Read_<p>_<d> (explicit S/R communication with isQueued = false)
 *********************************************************************************************************************/
# define Rte_Read_MotAgMecl3Polarity_Val Rte_Read_CDD_MotAg3Meas_MotAgMecl3Polarity_Val




# define CDD_MotAg3Meas_START_SEC_CODE
# include "CDD_MotAg3Meas_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


/**********************************************************************************************************************
 *
 * Runnable Entity Name: GetMotAg3Mecl_Oper
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Oper> of PortPrototype <GetMotAg3Mecl>
 *
 **********************************************************************************************************************
 *
 * Input Interfaces:
 * =================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Read_MotAgMecl3Polarity_Val(sint8 *data)
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   void GetMotAg3Mecl_Oper(u0p16 *MotAgMecl_Arg)
 *
 *********************************************************************************************************************/

# define RTE_RUNNABLE_GetMotAg3Mecl_Oper GetMotAg3Mecl_Oper
FUNC(void, CDD_MotAg3Meas_CODE) GetMotAg3Mecl_Oper(P2VAR(u0p16, AUTOMATIC, RTE_CDD_MOTAG3MEAS_APPL_VAR) MotAgMecl_Arg); /* PRQA S 0850 */ /* MD_MSR_19.8 */

/**********************************************************************************************************************
 *
 * Runnable Entity Name: MotAg3MeasInit1
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed once after the RTE is started
 *
 *********************************************************************************************************************/

# define RTE_RUNNABLE_MotAg3MeasInit1 MotAg3MeasInit1
FUNC(void, CDD_MotAg3Meas_CODE) MotAg3MeasInit1(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */

# define CDD_MotAg3Meas_STOP_SEC_CODE
# include "CDD_MotAg3Meas_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

# ifdef __cplusplus
} /* extern "C" */
# endif /* __cplusplus */

#endif /* _RTE_CDD_MOTAG3MEAS_H */

#include "Rte_Stubs.h"
