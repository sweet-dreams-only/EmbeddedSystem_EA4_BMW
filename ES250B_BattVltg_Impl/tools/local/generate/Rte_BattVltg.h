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
 *          File:  Rte_BattVltg.h
 *        Config:  C:/Users/nz3893/Documents/Synergy/EA4/Working/ES250B_BattVltg_Impl/tools/Component.dpa
 *     SW-C Type:  BattVltg
 *  Generated at:  Wed Sep 27 14:07:38 2017
 *
 *     Generator:  MICROSAR RTE Generator Version 4.13.0
 *                 RTE Core Version 1.13.0
 *       License:  Unlimited license CBD1400351 for Nxtr Automotive Corporation
 *
 *   Description:  Application header file for SW-C <BattVltg> (Contract Phase)
 *********************************************************************************************************************/

/* double include prevention */
#ifndef _RTE_BATTVLTG_H
# define _RTE_BATTVLTG_H

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

# include "Rte_BattVltg_Type.h"
# include "Rte_DataHandleType.h"


/**********************************************************************************************************************
 * Component Data Structures and Port Data Structures
 *********************************************************************************************************************/

struct Rte_CDS_BattVltg
{
  /* dummy entry */
  uint8 _dummy;
};

# define RTE_START_SEC_CONST_UNSPECIFIED
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

extern CONSTP2CONST(struct Rte_CDS_BattVltg, RTE_CONST, RTE_CONST) Rte_Inst_BattVltg; /* PRQA S 0850 */ /* MD_MSR_19.8 */

# define RTE_STOP_SEC_CONST_UNSPECIFIED
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

typedef P2CONST(struct Rte_CDS_BattVltg, TYPEDEF, RTE_CONST) Rte_Instance;


/**********************************************************************************************************************
 * Init Values for unqueued S/R communication (primitive types only)
 *********************************************************************************************************************/

# define Rte_InitValue_BattSwdVltgCorrlnSts_Val (2U)
# define Rte_InitValue_BattVltg_Val (0.0F)
# define Rte_InitValue_BattVltgSwd1_Val (0.0F)
# define Rte_InitValue_BrdgVltg_Val (6.0F)


# define RTE_START_SEC_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/**********************************************************************************************************************
 * API prototypes
 *********************************************************************************************************************/
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_BattVltg_BattSwdVltgCorrlnSts_Val(P2VAR(uint8, AUTOMATIC, RTE_BATTVLTG_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_BattVltg_BattVltg_Val(P2VAR(float32, AUTOMATIC, RTE_BATTVLTG_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_BattVltg_BattVltgSwd1_Val(P2VAR(float32, AUTOMATIC, RTE_BATTVLTG_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_BattVltg_BrdgVltg_Val(float32 data); /* PRQA S 0850 */ /* MD_MSR_19.8 */

# define RTE_STOP_SEC_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */



/**********************************************************************************************************************
 * Rte_Read_<p>_<d> (explicit S/R communication with isQueued = false)
 *********************************************************************************************************************/
# define Rte_Read_BattSwdVltgCorrlnSts_Val Rte_Read_BattVltg_BattSwdVltgCorrlnSts_Val
# define Rte_Read_BattVltg_Val Rte_Read_BattVltg_BattVltg_Val
# define Rte_Read_BattVltgSwd1_Val Rte_Read_BattVltg_BattVltgSwd1_Val


/**********************************************************************************************************************
 * Rte_Write_<p>_<d> (explicit S/R communication with isQueued = false)
 *********************************************************************************************************************/
# define Rte_Write_BrdgVltg_Val Rte_Write_BattVltg_BrdgVltg_Val




# define BattVltg_START_SEC_CODE
# include "BattVltg_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


/**********************************************************************************************************************
 *
 * Runnable Entity Name: BattVltgInit1
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed once after the RTE is started
 *
 *********************************************************************************************************************/

# define RTE_RUNNABLE_BattVltgInit1 BattVltgInit1
FUNC(void, BattVltg_CODE) BattVltgInit1(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */

/**********************************************************************************************************************
 *
 * Runnable Entity Name: BattVltgPer1
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered on TimingEvent every 2ms
 *
 **********************************************************************************************************************
 *
 * Input Interfaces:
 * =================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Read_BattSwdVltgCorrlnSts_Val(uint8 *data)
 *   Std_ReturnType Rte_Read_BattVltg_Val(float32 *data)
 *   Std_ReturnType Rte_Read_BattVltgSwd1_Val(float32 *data)
 *
 * Output Interfaces:
 * ==================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Write_BrdgVltg_Val(float32 data)
 *
 *********************************************************************************************************************/

# define RTE_RUNNABLE_BattVltgPer1 BattVltgPer1
FUNC(void, BattVltg_CODE) BattVltgPer1(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */

# define BattVltg_STOP_SEC_CODE
# include "BattVltg_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

# ifdef __cplusplus
} /* extern "C" */
# endif /* __cplusplus */

#endif /* _RTE_BATTVLTG_H */

#include "Rte_Stubs.h"
