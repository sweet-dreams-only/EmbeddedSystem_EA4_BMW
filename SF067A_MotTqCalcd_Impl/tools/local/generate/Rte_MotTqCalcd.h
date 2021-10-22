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
 *          File:  Rte_MotTqCalcd.h
 *        Config:  C:/Nimmy/Autocode/BMW/BMW_Production/SF067/SF067A_MotTqCalcd_Impl/tools/Component.dpa
 *     SW-C Type:  MotTqCalcd
 *  Generated at:  Wed Mar 21 13:42:23 2018
 *
 *     Generator:  MICROSAR RTE Generator Version 4.13.0
 *                 RTE Core Version 1.13.0
 *       License:  Unlimited license CBD1400351 for Nxtr Automotive Corporation
 *
 *   Description:  Application header file for SW-C <MotTqCalcd> (Contract Phase)
 *********************************************************************************************************************/

/* double include prevention */
#ifndef _RTE_MOTTQCALCD_H
# define _RTE_MOTTQCALCD_H

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

# include "Rte_MotTqCalcd_Type.h"
# include "Rte_DataHandleType.h"


/**********************************************************************************************************************
 * Component Data Structures and Port Data Structures
 *********************************************************************************************************************/

struct Rte_CDS_MotTqCalcd
{
  /* dummy entry */
  uint8 _dummy;
};

# define RTE_START_SEC_CONST_UNSPECIFIED
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

extern CONSTP2CONST(struct Rte_CDS_MotTqCalcd, RTE_CONST, RTE_CONST) Rte_Inst_MotTqCalcd; /* PRQA S 0850 */ /* MD_MSR_19.8 */

# define RTE_STOP_SEC_CONST_UNSPECIFIED
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

typedef P2CONST(struct Rte_CDS_MotTqCalcd, TYPEDEF, RTE_CONST) Rte_Instance;


/**********************************************************************************************************************
 * Init Values for unqueued S/R communication (primitive types only)
 *********************************************************************************************************************/

# define Rte_InitValue_MotAndThermProtnLoaMod_Val (0U)
# define Rte_InitValue_MotBackEmfConEstimd_Val (0.025F)
# define Rte_InitValue_MotCurrDax_Val (0.0F)
# define Rte_InitValue_MotCurrDaxCmd_Val (0.0F)
# define Rte_InitValue_MotCurrQax_Val (0.0F)
# define Rte_InitValue_MotCurrQaxCmd_Val (0.0F)
# define Rte_InitValue_MotInduDaxEstimd_Val (0.00011889F)
# define Rte_InitValue_MotInduQaxEstimd_Val (0.00011889F)
# define Rte_InitValue_MotTqEstimd_Val (0.0F)


# define RTE_START_SEC_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/**********************************************************************************************************************
 * API prototypes
 *********************************************************************************************************************/
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_MotTqCalcd_MotAndThermProtnLoaMod_Val(P2VAR(uint8, AUTOMATIC, RTE_MOTTQCALCD_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_MotTqCalcd_MotBackEmfConEstimd_Val(P2VAR(float32, AUTOMATIC, RTE_MOTTQCALCD_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_MotTqCalcd_MotCurrDax_Val(P2VAR(float32, AUTOMATIC, RTE_MOTTQCALCD_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_MotTqCalcd_MotCurrDaxCmd_Val(P2VAR(float32, AUTOMATIC, RTE_MOTTQCALCD_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_MotTqCalcd_MotCurrQax_Val(P2VAR(float32, AUTOMATIC, RTE_MOTTQCALCD_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_MotTqCalcd_MotCurrQaxCmd_Val(P2VAR(float32, AUTOMATIC, RTE_MOTTQCALCD_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_MotTqCalcd_MotInduDaxEstimd_Val(P2VAR(float32, AUTOMATIC, RTE_MOTTQCALCD_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_MotTqCalcd_MotInduQaxEstimd_Val(P2VAR(float32, AUTOMATIC, RTE_MOTTQCALCD_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_MotTqCalcd_MotTqEstimd_Val(float32 data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(uint8, RTE_CODE) Rte_Prm_MotTqCalcd_SysGlbPrmMotPoleCnt_Val(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */

# define RTE_STOP_SEC_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */



/**********************************************************************************************************************
 * Rte_Read_<p>_<d> (explicit S/R communication with isQueued = false)
 *********************************************************************************************************************/
# define Rte_Read_MotAndThermProtnLoaMod_Val Rte_Read_MotTqCalcd_MotAndThermProtnLoaMod_Val
# define Rte_Read_MotBackEmfConEstimd_Val Rte_Read_MotTqCalcd_MotBackEmfConEstimd_Val
# define Rte_Read_MotCurrDax_Val Rte_Read_MotTqCalcd_MotCurrDax_Val
# define Rte_Read_MotCurrDaxCmd_Val Rte_Read_MotTqCalcd_MotCurrDaxCmd_Val
# define Rte_Read_MotCurrQax_Val Rte_Read_MotTqCalcd_MotCurrQax_Val
# define Rte_Read_MotCurrQaxCmd_Val Rte_Read_MotTqCalcd_MotCurrQaxCmd_Val
# define Rte_Read_MotInduDaxEstimd_Val Rte_Read_MotTqCalcd_MotInduDaxEstimd_Val
# define Rte_Read_MotInduQaxEstimd_Val Rte_Read_MotTqCalcd_MotInduQaxEstimd_Val


/**********************************************************************************************************************
 * Rte_Write_<p>_<d> (explicit S/R communication with isQueued = false)
 *********************************************************************************************************************/
# define Rte_Write_MotTqEstimd_Val Rte_Write_MotTqCalcd_MotTqEstimd_Val


/**********************************************************************************************************************
 * Rte_Prm (Calibration component calibration parameters)
 *********************************************************************************************************************/

# define Rte_Prm_SysGlbPrmMotPoleCnt_Val Rte_Prm_MotTqCalcd_SysGlbPrmMotPoleCnt_Val



/**********************************************************************************************************************
 *
 * APIs which are accessible from all runnable entities of the SW-C
 *
 **********************************************************************************************************************
 * Calibration Parameters:
 * =======================
 *   Calibration Component Calibration Parameters:
 *   ---------------------------------------------
 *   uint8 Rte_Prm_SysGlbPrmMotPoleCnt_Val(void)
 *
 *********************************************************************************************************************/


# define MotTqCalcd_START_SEC_CODE
# include "MotTqCalcd_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


/**********************************************************************************************************************
 *
 * Runnable Entity Name: MotTqCalcdInit1
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed once after the RTE is started
 *
 *********************************************************************************************************************/

# define RTE_RUNNABLE_MotTqCalcdInit1 MotTqCalcdInit1
FUNC(void, MotTqCalcd_CODE) MotTqCalcdInit1(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */

/**********************************************************************************************************************
 *
 * Runnable Entity Name: MotTqCalcdPer1
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
 *   Std_ReturnType Rte_Read_MotAndThermProtnLoaMod_Val(uint8 *data)
 *   Std_ReturnType Rte_Read_MotBackEmfConEstimd_Val(float32 *data)
 *   Std_ReturnType Rte_Read_MotCurrDax_Val(float32 *data)
 *   Std_ReturnType Rte_Read_MotCurrDaxCmd_Val(float32 *data)
 *   Std_ReturnType Rte_Read_MotCurrQax_Val(float32 *data)
 *   Std_ReturnType Rte_Read_MotCurrQaxCmd_Val(float32 *data)
 *   Std_ReturnType Rte_Read_MotInduDaxEstimd_Val(float32 *data)
 *   Std_ReturnType Rte_Read_MotInduQaxEstimd_Val(float32 *data)
 *
 * Output Interfaces:
 * ==================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Write_MotTqEstimd_Val(float32 data)
 *
 *********************************************************************************************************************/

# define RTE_RUNNABLE_MotTqCalcdPer1 MotTqCalcdPer1
FUNC(void, MotTqCalcd_CODE) MotTqCalcdPer1(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */

# define MotTqCalcd_STOP_SEC_CODE
# include "MotTqCalcd_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

# ifdef __cplusplus
} /* extern "C" */
# endif /* __cplusplus */

#endif /* _RTE_MOTTQCALCD_H */
