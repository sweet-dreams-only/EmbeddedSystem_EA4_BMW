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
 *            Module: Os
 *           Program: MSR BAC 4.x (MSR_Bmw_SLP4)
 *          Customer: Nxtr Automotive Corporation
 *       Expiry Date: Not restricted
 *  Ordered Derivat.: Renesas RH850 P1M R7F701363EAFP
 *    License Scope : The usage is restricted to CBD1700369_D04
 *
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *              File: Os_Compiler_Cfg.h
 *   Generation Time: 2018-07-30 19:49:08
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

#if !defined (OS_COMPILER_CFG_H)                                                     /* PRQA S 0883 */ /* MD_Os_0883 */
# define OS_COMPILER_CFG_H

/**********************************************************************************************************************
 *  OS USER CALLOUT CODE SECTIONS
 *********************************************************************************************************************/

# define OS_FR_IRQLINE0_CODE
# define OS_FR_IRQTIMER0_CODE
# define OS_MCU_ECM_EIC_CAT2_ISR_CODE
# define OS_NTWRAPS_CMNMFGSRV_CALLSVC10_CODE
# define OS_NTWRAPS_CMNMFGSRV_CALLSVC7_CODE
# define OS_NTWRAPS_NVM_ERASENVBLOCK_CODE
# define OS_NTWRAPS_NVM_GETDATAINDEX_CODE
# define OS_NTWRAPS_NVM_GETERRORSTATUS_CODE
# define OS_NTWRAPS_NVM_INVALIDATENVBLOCK_CODE
# define OS_NTWRAPS_NVM_READBLOCK_CODE
# define OS_NTWRAPS_NVM_SETBLOCKPROTECTION_CODE
# define OS_NTWRAPS_NVM_SETDATAINDEX_CODE
# define OS_NTWRAPS_NVM_SETRAMBLOCKSTATUS_CODE
# define OS_NTWRAPS_NVM_WRITEBLOCK_CODE
# define OS_NTWRAPS_RTE_CALL_COPYCALPAGEREQ_OPER_CODE
# define OS_NTWRAPS_RTE_CALL_SETCALPAGEREQ_OPER_CODE
# define OS_NTWRAPS_SYNCCRC_GETAVLCRCHWUNIT_CODE
# define OS_NTWRAPS_SYNCCRC_RELSCRCHWUNIT_CODE
# define OS_NTWRAPS_XCP_EVENT_CODE
# define OS_SPI_CSIG0_TIC_CAT2_ISR_CODE
# define OS_SPI_CSIG0_TIRE_CAT2_ISR_CODE
# define OS_SPI_CSIG0_TIR_CAT2_ISR_CODE
# define OS_SPI_CSIH2_TIC_CAT2_ISR_CODE
# define OS_SPI_CSIH2_TIRE_CAT2_ISR_CODE
# define OS_SPI_CSIH2_TIR_CAT2_ISR_CODE
# define OS_TASK_100MS_APPL10_CODE
# define OS_TASK_100MS_APPL7_CODE
# define OS_TASK_100MS_APPL9_CODE
# define OS_TASK_10MSBSW_APPL10_CODE
# define OS_TASK_10MS_APPL10_CODE
# define OS_TASK_10MS_APPL7_CODE
# define OS_TASK_10MS_APPL8_CODE
# define OS_TASK_10MS_APPL9_CODE
# define OS_TASK_2MSA_APPL10_CODE
# define OS_TASK_2MSB_APPL10_CODE
# define OS_TASK_2MSTMPLMONR_APPL10_CODE
# define OS_TASK_2MS_APPL7_CODE
# define OS_TASK_2MS_APPL8_CODE
# define OS_TASK_2MS_APPL9_CODE
# define OS_TASK_4MSBSW_APPL10_CODE
# define OS_TASK_4MS_APPL10_CODE
# define OS_TASK_4MS_APPL7_CODE
# define OS_TASK_5MSBSW_APPL10_CODE
# define OS_TASK_CODING_APPL10_CODE
# define OS_TASK_COMBSW_APPL10_CODE
# define OS_TASK_INITBSW_APPL10_CODE
# define OS_TASK_INIT_APPL10_CODE
# define OS_TASK_INIT_APPL7_CODE
# define OS_TASK_INIT_APPL8_CODE
# define OS_TASK_INIT_APPL9_CODE


#endif /* OS_COMPILER_CFG_H */

/**********************************************************************************************************************
 *  END OF FILE: Os_Compiler_Cfg.h
 *********************************************************************************************************************/
