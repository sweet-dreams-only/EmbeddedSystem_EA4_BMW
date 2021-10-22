/**********************************************************************************************************************
 *  COPYRIGHT
 *  -------------------------------------------------------------------------------------------------------------------
 *  \verbatim
 *
 *                 This software is copyright protected and proprietary to Vctr Informatik GmbH.
 *                 Vctr Informatik GmbH grants to you only those rights as set out in the license conditions.
 *                 All other rights remain with Vctr Informatik GmbH.
 *  \endverbatim
 *  -------------------------------------------------------------------------------------------------------------------
 *  LICENSE
 *  -------------------------------------------------------------------------------------------------------------------
 *            Module: MemIf
 *           Program: MSR BAC 4.x (MSR_Bmw_SLP4)
 *          Customer: Nxtr Automotive Corporation
 *       Expiry Date: Not restricted
 *  Ordered Derivat.: Renesas RH850 P1M R7F701363EAFP
 *    License Scope : The usage is restricted to CBD1700369_D04
 *
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *              File: MemIf_Cfg.c
 *   Generation Time: 2018-07-30 19:49:07
 *           Project: EPS - Version 1.0
 *          Delivery: CBD1700369_D04
 *      Tool Version: DaVinci Configurator (beta) 5.16.35 SP2
 *
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 ! BETA VERSION                                                                                                       !
 !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
 ! These programs are fully operative programs. With regard to the fact that the programs are a beta-version only,    !
 ! Vctr Informatik's liability shall be expressly excluded in cases of ordinary negligence, to the extent           !
 ! admissible by law or statute.                                                                                      !
 !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
**********************************************************************************************************************/

    
/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "Std_Types.h"
#include "MemIf.h"

/****  Include of MemHwA Modules  ************************************************************************************/
#include "Fee_30_SmallSector.h" 



/**********************************************************************************************************************
 *  VERSION CHECK
 *********************************************************************************************************************/
 
#if (   (MEMIF_CFG_MAJOR_VERSION != (5u)) \
     || (MEMIF_CFG_MINOR_VERSION != (2u)))
# error "Version numbers of MemIf_Cfg.c and MemIf_Cfg.h are inconsistent!"
#endif

#if (   (MEMIF_SW_MAJOR_VERSION != (3u)) \
     || (MEMIF_SW_MINOR_VERSION != (3u)))
# error "Version numbers of MemIf_Cfg.c and MemIf.h are inconsistent!"
#endif


/**********************************************************************************************************************
 *  GLOBAL DATA
 *********************************************************************************************************************/
 
#ifndef MEMIF_LOCAL /* COV_MEMIF_COMPATIBILITY */
# define MEMIF_LOCAL static
#endif

#if !defined (MEMIF_LOCAL_INLINE) /* COV_MEMIF_COMPATIBILITY */
# define MEMIF_LOCAL_INLINE LOCAL_INLINE
#endif
 
#define MEMIF_START_SEC_CONST_8BIT
#include "MemMap.h"	/* PRQA S 5087 */ /* MD_MSR_19.1 */

CONST(uint8, MEMIF_CONST) MemIf_NumberOfDevices = MEMIF_NUMBER_OF_DEVICES;

#define MEMIF_STOP_SEC_CONST_8BIT
#include "MemMap.h"	/* PRQA S 5087 */ /* MD_MSR_19.1 */

/**********************************************************************************************************************
 *  MemHwA Function Pointer Tables
 *********************************************************************************************************************/
#define MEMIF_START_SEC_CODE
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/**-- MemHwA Write Wrapper Functions --**/
MEMIF_LOCAL_INLINE FUNC (Std_ReturnType, MEMIF_PRIVATE_CODE) MemIf_Fee_30_SmallSector_WriteWrapper(uint16 BlockNumber, MemIf_DataPtr_pu8 DataBufferPtr); 

 
MEMIF_LOCAL_INLINE FUNC (Std_ReturnType, MEMIF_PRIVATE_CODE) MemIf_Fee_30_SmallSector_WriteWrapper(uint16 BlockNumber, MemIf_DataPtr_pu8 DataBufferPtr) /* PRQA S 3673 */ /* MD_MEMIF_16.7 */ 
{ 
    return Fee_30_SmallSector_Write(BlockNumber, DataBufferPtr); /* SBSW_MEMIF_04 */ 
}
 

#define MEMIF_STOP_SEC_CODE
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#define MEMIF_START_SEC_CONST_32BIT
#include "MemMap.h"	/* PRQA S 5087 */ /* MD_MSR_19.1 */

/**-- MemHwA Function Pointers --**/
CONST(MemIf_MemHwAApi_Type, MEMIF_CONST) MemIf_MemHwaApis[MEMIF_NUMBER_OF_DEVICES] =
{
   /*  Fee_30_SmallSector  */ {
    Fee_30_SmallSector_Read, 
    MemIf_Fee_30_SmallSector_WriteWrapper, 
    Fee_30_SmallSector_EraseImmediateBlock, 
    Fee_30_SmallSector_InvalidateBlock, 
    Fee_30_SmallSector_Cancel, 
    Fee_30_SmallSector_GetStatus, 
    Fee_30_SmallSector_GetJobResult, 
    Fee_30_SmallSector_SetMode
  }
};
    
#define MEMIF_STOP_SEC_CONST_32BIT
#include "MemMap.h"	/* PRQA S 5087 */ /* MD_MSR_19.1 */
    
/* Justification for module-specific MISRA deviations:     
  MD_MEMIF_16.7: rule 16.7
      Reason:     Buffer pointer is not declared const in order to support EA/FEE write interfaces with const and non-const buffers.
      Risk:       No risk. By using this wrapper functions without const pointers compiler warnings are solved.
      Prevention: Program flow has been verified by component tests and review.
*/
        
/**********************************************************************************************************************
 *  END OF FILE: MemIf_Cfg.c
 *********************************************************************************************************************/   

