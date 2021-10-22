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
 *              File: Os_Cfg.h
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

#if !defined (OS_CFG_H)                                                              /* PRQA S 0883 */ /* MD_Os_0883 */
# define OS_CFG_H

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/

/* AUTOSAR includes */

/* Os module declarations */

/* Os kernel module dependencies */

/* Os hal dependencies */
# include "Os_Hal_Cfg.h"


/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/

/*! Configuration major version identification. */
# define OS_CFG_MAJOR_VERSION                    (2U)

/*! Configuration minor version identification. */
# define OS_CFG_MINOR_VERSION                    (14U)


/*! Defines which platform is used. */
# define OS_CFG_PLATFORM_RH850     (STD_ON)

/*! Defines which derivative group is configured. */
# define OS_CFG_DERIVATIVEGROUP_RH850P1M     (STD_ON)

/*! Defines which derivative is configured. */
# define OS_CFG_DERIVATIVE_RH850_1363     (STD_ON)

/*! Defines which compiler is configured. */
# define OS_CFG_COMPILER_GREENHILLS     (STD_ON)


/*! Defines whether access macros to get context related information in the error hook are enabled (STD_ON) or not (STD_OFF). */
# define OS_CFG_ERR_PARAMETERACCESS              (STD_OFF)

/*! Defines whether access macros to get service ID information in the error hook are enabled (STD_ON) or not (STD_OFF). */
# define OS_CFG_ERR_GETSERVICEID                 (STD_OFF)

/*! Defines whether the pre-task hook is active (STD_ON) or not (STD_OFF). */
# define OS_CFG_PRETASKHOOK                      (STD_OFF)

/*! Defines whether the post-task hook is active (STD_ON) or not (STD_OFF). */
# define OS_CFG_POSTTASKHOOK                     (STD_OFF)

/*! Defines whether the OS shall call the panic hook (STD_ON) or not (STD_OFF). */
# define OS_CFG_PANICHOOK                        (STD_OFF)

/*! Defines whether the system startup hook is configured (STD_ON) or not (STD_OFF). */
# define OS_CFG_STARTUPHOOK_SYSTEM               (STD_OFF)

/*! Defines whether the system shutdown hook is configured (STD_ON) or not (STD_OFF). */
# define OS_CFG_SHUTDOWNHOOK_SYSTEM              (STD_ON)

/*! Defines whether the system error hook is configured (STD_ON) or not (STD_OFF). */
# define OS_CFG_ERRORHOOK_SYSTEM                 (STD_ON)

/*! Defines whether the system protection hook is configured (STD_ON) or not (STD_OFF). */
# define OS_CFG_PROTECTIONHOOK_SYSTEM            (STD_OFF)

/*! Defines whether backward compatibility defines are needed (STD_ON) or not (STD_OFF). */
# define OS_CFG_PERIPHERAL_COMPATIBILITY         (STD_ON)


/* OS application modes */
# define DONOTCARE     ((AppModeType)0)
# define OS_APPMODE_NONE     ((AppModeType)0)
# define OSDEFAULTAPPMODE     ((AppModeType)1)
# define OS_APPMODE_ANY     ((AppModeType)255)


/* Event masks */
# define Rte_Ev_Cyclic2_Task_5msBsw_Appl10_0_5ms     ((EventMaskType)1ULL)
# define Rte_Ev_Cyclic2_Task_ComBsw_Appl10_0_5ms     ((EventMaskType)1ULL)
# define Rte_Ev_Cyclic_Task_100ms_Appl10_0_100ms     ((EventMaskType)1ULL)
# define Rte_Ev_Cyclic_Task_10ms_Appl10_0_10ms     ((EventMaskType)1ULL)
# define Rte_Ev_Cyclic_Task_ComBsw_Appl10_0_10ms     ((EventMaskType)2ULL)
# define Rte_Ev_MS_Task_100ms_Appl10     ((EventMaskType)4ULL)
# define Rte_Ev_MS_Task_10ms_Appl10     ((EventMaskType)4ULL)
# define Rte_Ev_Run1_Darh_QueueHandler     ((EventMaskType)2ULL)
# define Rte_Ev_Run1_Stm_Runnable_InitialCELSupervision     ((EventMaskType)2ULL)
# define Rte_Ev_Run1_Stm_Runnable_StopCentralErrorLockSupervision     ((EventMaskType)8ULL)
# define Rte_Ev_Run1_SysTime_ReceiveSignal     ((EventMaskType)16ULL)
# define Rte_Ev_Run_BmwMsgSlot107Bas0Repn1BusFrChA_OFFS_QUAD_EPS_Missing_Oper     ((EventMaskType)32ULL)
# define Rte_Ev_Run_BmwMsgSlot107Bas0Repn1BusFrChA_OFFS_QUAD_EPS_Received_Oper     ((EventMaskType)64ULL)
# define Rte_Ev_Run_BmwMsgSlot108Bas0Repn2BusFrChA_STEA_OFFS_Missing_Oper     ((EventMaskType)128ULL)
# define Rte_Ev_Run_BmwMsgSlot108Bas0Repn2BusFrChA_STEA_OFFS_Received_Oper     ((EventMaskType)256ULL)
# define Rte_Ev_Run_BmwMsgSlot121Bas1Repn2BusFrChA_CON_VEH_Missing_Oper     ((EventMaskType)8ULL)
# define Rte_Ev_Run_BmwMsgSlot121Bas1Repn2BusFrChA_CON_VEH_Received_Oper     ((EventMaskType)16ULL)
# define Rte_Ev_Run_BmwMsgSlot269Bas2Repn4BusFrChA_CTR_VIB_STW_DISP_EXMI_SP2015_Missing     ((EventMaskType)512ULL)
# define Rte_Ev_Run_BmwMsgSlot269Bas2Repn4BusFrChA_CTR_VIB_STW_DISP_EXMI_SP2015_Received     ((EventMaskType)1024ULL)
# define Rte_Ev_Run_BmwMsgSlot276Bas4Repn8BusFrChA_MILE_KM_Missing_Oper     ((EventMaskType)2048ULL)
# define Rte_Ev_Run_BmwMsgSlot276Bas4Repn8BusFrChA_MILE_KM_Received_Oper     ((EventMaskType)4096ULL)
# define Rte_Ev_Run_BmwMsgSlot53Bas3Repn8BusFrChA_SU_CLE_DRDY_DXP_Miss     ((EventMaskType)8192ULL)
# define Rte_Ev_Run_BmwMsgSlot53Bas3Repn8BusFrChA_SU_CLE_DRDY_DXP_Rxd     ((EventMaskType)16384ULL)
# define Rte_Ev_Run_BmwMsgSlot55Bas0Repn2BusFrChA_ACLNY_MASSCNTR_Missing_Oper     ((EventMaskType)32768ULL)
# define Rte_Ev_Run_BmwMsgSlot55Bas0Repn2BusFrChA_ACLNY_MASSCNTR_Received_Oper     ((EventMaskType)65536ULL)
# define Rte_Ev_Run_BmwMsgSlot55Bas3Repn4BusFrChA_V_VEH_Missing_Oper     ((EventMaskType)32ULL)
# define Rte_Ev_Run_BmwMsgSlot55Bas3Repn4BusFrChA_V_VEH_Received_Oper     ((EventMaskType)64ULL)
# define Rte_Ev_Run_BmwMsgSlot56Bas0Repn2BusFrChA_VYAW_VEH_Missing_Oper     ((EventMaskType)131072ULL)
# define Rte_Ev_Run_BmwMsgSlot56Bas0Repn2BusFrChA_VYAW_VEH_Received_Oper     ((EventMaskType)262144ULL)
# define Rte_Ev_Run_BmwMsgSlot68Bas0Repn2BusFrChA_TAR_QTA_STRMOM_DV_Miss     ((EventMaskType)524288ULL)
# define Rte_Ev_Run_BmwMsgSlot68Bas0Repn2BusFrChA_TAR_QTA_STRMOM_DV_Rxd     ((EventMaskType)1048576ULL)
# define Rte_Ev_Run_BmwMsgSlot68Bas0Repn2BusFrChA_TAR_STMOM_DV_ACT_Miss     ((EventMaskType)2097152ULL)
# define Rte_Ev_Run_BmwMsgSlot68Bas0Repn2BusFrChA_TAR_STMOM_DV_ACT_Rxd     ((EventMaskType)4194304ULL)
# define Rte_Ev_Run_BmwMsgSlot68Bas1Repn2BusFrChA_ENERG_DGR_DRDY_Missing_Oper     ((EventMaskType)8388608ULL)
# define Rte_Ev_Run_BmwMsgSlot68Bas1Repn2BusFrChA_ENERG_DGR_DRDY_Received_Oper     ((EventMaskType)16777216ULL)
# define Rte_Ev_Run_BswM_BswM_Read_StdDiag_ComControlModeRequest     ((EventMaskType)33554432ULL)
# define Rte_Ev_Run_Coding_LifeCycleHandler     ((EventMaskType)67108864ULL)
# define Rte_Ev_Run_Coding_R_CheckNCD     ((EventMaskType)1ULL)
# define Rte_Ev_Run_Coding_R_ConditionCheckReadCPS     ((EventMaskType)2ULL)
# define Rte_Ev_Run_Coding_R_ReadCPS     ((EventMaskType)4ULL)
# define Rte_Ev_Run_Coding_R_ReadNCD     ((EventMaskType)8ULL)
# define Rte_Ev_Run_Coding_R_ReadProtocolData     ((EventMaskType)16ULL)
# define Rte_Ev_Run_Coding_R_WriteNCD     ((EventMaskType)32ULL)
# define Rte_Ev_Run_Coding_SessionChange     ((EventMaskType)134217728ULL)
# define Rte_Ev_Run_Coding_VinReceiveHandler     ((EventMaskType)268435456ULL)
# define Rte_Ev_Run_Darh_LifeCycleHandler     ((EventMaskType)536870912ULL)
# define Rte_Ev_Run_Dlog_Dlog_ModeSwitchAckLifeCycle     ((EventMaskType)1073741824ULL)
# define Rte_Ev_Run_Dlog_Dlog_ModeSwitchRequestLifeCycle     ((EventMaskType)2147483648ULL)
# define Rte_Ev_Run_Omc_LifeCycleHandler     ((EventMaskType)4294967296ULL)
# define Rte_Ev_Run_Rmh_RxRequestMsg     ((EventMaskType)8589934592ULL)
# define Rte_Ev_Run_StdDiag_LifeCycleHandler     ((EventMaskType)17179869184ULL)
# define Rte_Ev_Run_StdDiag_SessionChange_DefaultSession     ((EventMaskType)34359738368ULL)
# define Rte_Ev_Run_StdDiag_SessionChange_OtherSession     ((EventMaskType)68719476736ULL)
# define Rte_Ev_Run_Stm_Runnable_ErrorCentralErrorLock     ((EventMaskType)137438953472ULL)
# define Rte_Ev_Run_Stm_Runnable_ErrorEnergyMode     ((EventMaskType)274877906944ULL)
# define Rte_Ev_Run_Stm_Runnable_ReceiveCentralErrorLock     ((EventMaskType)549755813888ULL)
# define Rte_Ev_Run_Stm_Runnable_ReceiveEnergyMode     ((EventMaskType)1099511627776ULL)
# define Rte_Ev_Run_SysTime_LifeCycleHandler     ((EventMaskType)2199023255552ULL)
# define Rte_Ev_Run_Vin_Vin_LifeCycleModeRequest     ((EventMaskType)128ULL)
# define Rte_Ev_Run_Vin_Vin_OnComOff     ((EventMaskType)256ULL)
# define Rte_Ev_Run_Vin_Vin_OnComOn     ((EventMaskType)512ULL)
# define Rte_Ev_Run_Vin_Vin_OnVinChangeIndicatorAck     ((EventMaskType)1024ULL)
# define Rte_Ev_Run_Vin_Vin_ReceiveFromCom     ((EventMaskType)2048ULL)
# define Rte_Ev_WP_Task_5msBsw_Appl10     ((EventMaskType)2ULL)


/* Software counter timing macros */
/* Counter timing macros and constants: FrCycleCounter */
# define OSMAXALLOWEDVALUE_FrCycleCounter     (1073741823UL) /* 0x3FFFFFFFUL */
# define OSMINCYCLE_FrCycleCounter            (1UL)
# define OSTICKSPERBASE_FrCycleCounter        (1UL)
# define OSTICKDURATION_FrCycleCounter        (5000000UL)

/*! Macro OS_NS2TICKS_FrCycleCounter was approximated with a deviation of 1.1102230246251565E-10ppm. */
# define OS_NS2TICKS_FrCycleCounter(x)     ( (TickType) (((((uint32)(x)) * 1) + 2500000) / 5000000) )     /* PRQA S 3453 */ /* MD_MSR_19.7 */
/*! Macro OS_TICKS2NS_FrCycleCounter was approximated with a deviation of 0.0ppm. */
# define OS_TICKS2NS_FrCycleCounter(x)     ( (PhysicalTimeType) (((((uint32)(x)) * 5000000) + 0) / 1) )     /* PRQA S 3453 */ /* MD_MSR_19.7 */

/*! Macro OS_US2TICKS_FrCycleCounter was approximated with a deviation of 2.220446049250313E-10ppm. */
# define OS_US2TICKS_FrCycleCounter(x)     ( (TickType) (((((uint32)(x)) * 1) + 2500) / 5000) )     /* PRQA S 3453 */ /* MD_MSR_19.7 */
/*! Macro OS_TICKS2US_FrCycleCounter was approximated with a deviation of 0.0ppm. */
# define OS_TICKS2US_FrCycleCounter(x)     ( (PhysicalTimeType) (((((uint32)(x)) * 5000) + 0) / 1) )     /* PRQA S 3453 */ /* MD_MSR_19.7 */

/*! Macro OS_MS2TICKS_FrCycleCounter was approximated with a deviation of 0.0ppm. */
# define OS_MS2TICKS_FrCycleCounter(x)     ( (TickType) (((((uint32)(x)) * 1) + 2) / 5) )     /* PRQA S 3453 */ /* MD_MSR_19.7 */
/*! Macro OS_TICKS2MS_FrCycleCounter was approximated with a deviation of 0.0ppm. */
# define OS_TICKS2MS_FrCycleCounter(x)     ( (PhysicalTimeType) (((((uint32)(x)) * 5) + 0) / 1) )     /* PRQA S 3453 */ /* MD_MSR_19.7 */

/*! Macro OS_SEC2TICKS_FrCycleCounter was approximated with a deviation of 0.0ppm. */
# define OS_SEC2TICKS_FrCycleCounter(x)     ( (TickType) (((((uint32)(x)) * 200) + 0) / 1) )     /* PRQA S 3453 */ /* MD_MSR_19.7 */
/*! Macro OS_TICKS2SEC_FrCycleCounter was approximated with a deviation of 0.0ppm. */
# define OS_TICKS2SEC_FrCycleCounter(x)     ( (PhysicalTimeType) (((((uint32)(x)) * 1) + 100) / 200) )     /* PRQA S 3453 */ /* MD_MSR_19.7 */



/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/


#endif /* OS_CFG_H */

/**********************************************************************************************************************
 *  END OF FILE: Os_Cfg.h
 *********************************************************************************************************************/
