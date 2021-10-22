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
 *            Module: EcuM
 *           Program: MSR BAC 4.x (MSR_Bmw_SLP4)
 *          Customer: Nxtr Automotive Corporation
 *       Expiry Date: Not restricted
 *  Ordered Derivat.: Renesas RH850 P1M R7F701363EAFP
 *    License Scope : The usage is restricted to CBD1700369_D04
 *
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *              File: EcuM_Callout_Stubs.c
 *   Generation Time: 2018-06-29 12:37:54
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
 * DO NOT CHANGE THIS COMMENT!           <USERBLOCK User Version>                           DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
* Copyright 2017 Nxtr
* Nxtr Confidential
*
* Module File Name:   EcuM_Callout_Stubs.c
* Module Description: Stub for EcuM configuration hooks
* Project           : BMW 5441
* Author            : Kevin Smith
***********************************************************************************************************************
* Version Control:
* %version:          8 %
* %derived_by:       tzyksv %
*----------------------------------------------------------------------------------------------------------------------
* Date      Rev      Author         Change Description                                                           SCR #
* -------   -------  --------  ---------------------------------------------------------------------------     --------
* 09/06/17  1        KJS       Initial Version                                                                EA4#14844
* 09/26/17  2        KJS       Updates to EcuM naminig                                                        EA4#14844
* 11/23/17  3        AR        Start-up and shutdown sequences are updated                                    EA4#17066
* 12/18/17  4        AR        Added ECC related changes for Fls init                                         EA4#XXXXX
* 04/27/18  5        AR        Turns counter QEP implementation and DNF updates                               EA4#22691
* 06/29/18  6        AR        Anomaly EA4#25375 fix                                                          EA4#25375
**********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           </USERBLOCK>                                       DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

/*********************************************************************************************************************
    INCLUDES
 *********************************************************************************************************************/
/* PRQA S 0857 EOF */ /* MD_MSR_1.1_857 */
#define ECUM_CALLOUT_STUBS_SOURCE
#include "EcuM.h"

#define ECUM_PRIVATE_CFG_INCLUDE
#include "EcuM_PrivateCfg.h"
#undef ECUM_PRIVATE_CFG_INCLUDE /* PRQA S 0841 */ /* MD_EcuM_0841 */



/**********************************************************************************************************************
 *  All configured EcuM Wakeup Sources (as bitmasks) for usage in Callouts
 *********************************************************************************************************************/
/*
 * ECUM_WKSOURCE_NONE           (EcuM_WakeupSourceType)(0x00000000UL) 
 * ECUM_WKSOURCE_ALL_SOURCES    (EcuM_WakeupSourceType)(~((EcuM_WakeupSourceType)0x00UL)) 
 * ECUM_WKSOURCE_POWER          (EcuM_WakeupSourceType)(1UL) 
 * ECUM_WKSOURCE_RESET          (EcuM_WakeupSourceType)(2UL) 
 * ECUM_WKSOURCE_INTERNAL_RESET (EcuM_WakeupSourceType)(4UL) 
 * ECUM_WKSOURCE_INTERNAL_WDG   (EcuM_WakeupSourceType)(8UL) 
 * ECUM_WKSOURCE_EXTERNAL_WDG   (EcuM_WakeupSourceType)(16UL) 
 */

/**********************************************************************************************************************
 *  Additional configured User includes
 *********************************************************************************************************************/
#include "Det.h" 


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           <USERBLOCK User Includes>                          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
#include "Dem.h" 
#include "Port.h" 
#include "Mcu.h" 
#include "Dio.h" 
#include "Wdg_59_DriverA.h" 
#include "Fls.h" 
#include "Os.h" 
#include "Spi.h" 
#include "CDD_ExcpnHndlg.h" 
#include "CDD_NxtrTi.h" 
#include "WdgIf.h" 
#include "intc_regs.h" 
#include "NxtrMcuSuprtLib.h" 
#include "ecc_regs.h" 
#include "CDD_McuCoreCfgAndDiagc.h" 
#include "CDD_CoreVltgMonr.h" 
#include "CDD_DataAndAdrPar.h" 
#include "CDD_MotAg0Meas.h" 
#include "CDD_MotAg1Meas.h" 


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           </USERBLOCK>                                       DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/




/**********************************************************************************************************************
 *  CALLOUT FUNCTIONS
 *********************************************************************************************************************/
#define ECUM_START_SEC_CODE
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */




/**********************************************************************************************************************
 *  GENERIC CALLOUTS
 *********************************************************************************************************************/

FUNC(void, ECUM_CODE) EcuM_ErrorHook(Std_ReturnType reason) /* COV_ECUM_CALLOUT */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           <USERBLOCK EcuM_ErrorHook>                         DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
#if (ECUM_USE_DUMMY_STATEMENT == STD_ON)
  /* dummy assignment to prevent compiler warnings on most of the compilers. */
  (void)reason;     /* PRQA S 3112 */ /* MD_EcuM_3112 */
#endif
  /* Add implementation of EcuM_ErrorHook() */
  
  /* In case of an inconsistent configuration data, abort initialization here */
  if(reason == ECUM_E_HOOK_CONFIGURATION_DATA_INCONSISTENT)
  {
    while(1)
    {
    }
  }
  
# if(ECUM_NUMBER_OF_CORES > 1)
  /* In case of an invalid coreId, returned by the OS */
  if(reason == ECUM_E_HOOK_INVALID_COREID)
  {
    while(1)
    {
    }
  }
# endif
  
  return;
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           </USERBLOCK>                                       DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
} /* End of EcuM_ErrorHook() */




/**********************************************************************************************************************
 *  CALLOUTS FROM THE SHUTDOWN PHASE
 *********************************************************************************************************************/



FUNC(void, ECUM_CODE) EcuM_OnGoOffOne(void)
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           <USERBLOCK EcuM_OnGoOffOne>                        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
  (void)Rte_Stop();
  
  return;
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           </USERBLOCK>                                       DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
} /* End of EcuM_OnGoOffOne() */

FUNC(void, ECUM_CODE) EcuM_ShutdownOS(Std_ReturnType ErrCode)
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           <USERBLOCK EcuM_ShutdownOS>                        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
  /* Add implementation of EcuM_ShutdownOS() */
#if ( ECUM_NUMBER_OF_CORES > 1 )
  ShutdownAllCores(ErrCode);
#else
  ShutdownOS(ErrCode);
#endif
  
  return;
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           </USERBLOCK>                                       DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
} /* End of EcuM_ShutdownOS() */

FUNC(void, ECUM_CODE) EcuM_OnGoOffTwo(void)
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           <USERBLOCK EcuM_OnGoOffTwo>                        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
  /* Add implementation of EcuM_OnGoOffTwo() */
  VAR(boolean, AUTOMATIC) PinSt_Cnt_T_Logl;
  
  /* Set MotAg measurement to low power mode */
	MotAg0CfgLoPwrMod();
	MotAg1CfgLoPwrMod();

	while (1)
	{
		(void)IoHwAb_GetGpioMcuEna_Oper(&PinSt_Cnt_T_Logl);
		/* Quick ignition cycle - reset the part*/
		if (PinSt_Cnt_T_Logl == STD_HIGH)
		{
			NxtrSwRst(MCUDIAGC_QUICKIGNRST, 0U);			
		}
		else
		{
			(void)IoHwAb_SetGpioPwrTurnOffCtrl_Oper(STD_LOW);
		}
	}
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           </USERBLOCK>                                       DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
} /* End of EcuM_OnGoOffTwo() */

FUNC(void, ECUM_CODE) EcuM_AL_SwitchOff(void)
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           <USERBLOCK EcuM_AL_SwitchOff>                      DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
 
  while(1);

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           </USERBLOCK>                                       DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
} /* End of EcuM_AL_SwitchOff() */

FUNC(void, ECUM_CODE) EcuM_AL_Reset(EcuM_ResetType Reset)
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           <USERBLOCK EcuM_AL_Reset>                          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

  while(1);

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           </USERBLOCK>                                       DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
} /* End of EcuM_AL_Reset() */



/**********************************************************************************************************************
 *  CALLOUTS FROM THE STARTUP PHASE
 *********************************************************************************************************************/


/**********************************************************************************************************************
* EcuM_AL_DriverInitZero
**********************************************************************************************************************/
FUNC(void, ECUM_CODE) EcuM_AL_DriverInitZero(void) 
{
  {
  #if defined (DET_ENABLED)
    Det_InitMemory();
    Det_Init(Det_Config);
  #endif
  };

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           <USERBLOCK EcuM_AL_DriverInitZero>                 DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/* Add implementation of EcuM_AL_DriverInitZero  */
  CoreVltgMonrInit1();
  McuCoreCfgAndDiagcInit1();
  McuCoreCfgAndDiagcInit2();
  
  return;
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           </USERBLOCK>                                       DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
* EcuM_AL_DriverInitOne
**********************************************************************************************************************/
FUNC(void, ECUM_CODE) EcuM_AL_DriverInitOne(void) 
{

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           <USERBLOCK EcuM_AL_DriverInitOne>                  DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/* Add implementation of EcuM_AL_DriverInitOne  */
  Os_InitMemory();  
  Os_Init();
  Dem_PreInit(NULL_PTR);

  EcmOutpAndDiagcInit3();
  Mcu_Init(McuModuleConfiguration);
  (void)Mcu_InitClock(McuConf_McuClockSettingConfig_McuClockSettingConfig);
  EcmOutpAndDiagcInit4();
  EcmOutpAndDiagcInit1();
  Spi_Init(SpiDriver);
  Bmw5441McuCfgInit4();
  Port_Init(PortConfigSet);
  INTC1IMR0EIMK9 = 0U; 
  Wdg_59_DriverA_Init(WdgSettingsConfig);
  GuardCfgAndDiagcInit3();  
  DataAndAdrParInit1();
  Dio_Init(DioConfig);  
  /* Save and restore DF ECC   registers so Fls_Init passes DET checks */
  {
    uint16 SavedReg1_Cnt_T_u16 = ECCEEPDFECCCTL ;
    uint8  SavedReg2_Cnt_T_u08 = ECCEEPDFERRINT ;

    ECCEEPDFECCCTL = 0x4000U;
    ECCEEPDFERRINT = 0x02U;

    Fls_Init(FlsConfigSet);

    ECCEEPDFECCCTL =0x4000U | SavedReg1_Cnt_T_u16;
    ECCEEPDFERRINT = SavedReg2_Cnt_T_u08;
  };
  ExcpnHndlgInit1();
  NxtrTiInit0();

  return;
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           </USERBLOCK>                                       DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
* EcuM_AL_DriverRestartList
**********************************************************************************************************************/
FUNC(void, ECUM_CODE) EcuM_AL_DriverRestartList(void) 
{

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           <USERBLOCK EcuM_AL_DriverRestartList>              DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/* Add implementation of EcuM_AL_DriverRestartList  */

return;
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           </USERBLOCK>                                       DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}




FUNC(void, ECUM_CODE) EcuM_StartOS(AppModeType appMode)
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           <USERBLOCK EcuM_StartOS>                           DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
  /* Add implementation of EcuM_StartOS() */
#if ( ECUM_NUMBER_OF_CORES > 1 )
  uint8 coreId;
  StatusType status;
  if(GetCoreID()==ECUM_CORE_ID_STARTUP)
  {
    for(coreId=0; coreId < ECUM_NUMBER_OF_CORES; coreId++)
    {
      if(coreId!=ECUM_CORE_ID_STARTUP)
      {
        StartCore(coreId, &status); /* SBSW_ECUM_ADRESSPARAMETER_TOOS */
      }
    }
  }
#endif

  /* Start OS must be called for each core */
  StartOS(appMode);

  return;
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           </USERBLOCK>                                       DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
} /* End of EcuM_StartOS() */

FUNC(void, ECUM_CODE) EcuM_AL_SetProgrammableInterrupts(void)
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           <USERBLOCK EcuM_AL_SetProgrammableInterrupts>      DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
  /* Add implementation of EcuM_AL_SetProgrammableInterrupts() */

  return;
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           </USERBLOCK>                                       DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
} /* End of EcuM_AL_SetProgrammableInterrupts() */

#if((ECUM_CONFIGURATION_VARIANT == ECUM_CONFIGURATION_VARIANT_POSTBUILD_LOADABLE) || (ECUM_POSTBUILD_VARIANT_SUPPORT == STD_ON))
FUNC(EcuM_GlobalConfigRefType, ECUM_CODE) EcuM_DeterminePbConfiguration(void)
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           <USERBLOCK EcuM_DeterminePbConfiguration>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
  /* Add implementation of EcuM_DeterminePbConfiguration() */
  
  return ;
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           </USERBLOCK>                                       DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
} /* End of EcuM_DeterminePbConfiguration() */
#endif

#if (ECUM_ALARM_CLOCK_PRESENT == STD_ON)
FUNC(void, ECUM_CODE) EcuM_GptStartClock(Gpt_ChannelType GptChannel, Gpt_ModeType Mode, Gpt_ValueType Value)
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           <USERBLOCK EcuM_GptStartClock>                     DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
  /* Add implementation of EcuM_GptStartClock() */

  Gpt_EnableNotification(GptChannel);
  Gpt_StartTimer(GptChannel, Value);
  Gpt_SetMode(Mode);

  return;
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           </USERBLOCK>                                       DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
} /* End of EcuM_GptStartClock() */
#endif




/**********************************************************************************************************************
 *  CALLOUTS FROM THE SLEEP PHASE
 *********************************************************************************************************************/



#if (( ECUM_NUMBER_OF_CORES > 1 ) && (ECUM_SLEEPMODELIST == STD_ON))
FUNC(void, ECUM_CODE) EcuM_WaitForSlaveCores(void)
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           <USERBLOCK EcuM_WaitForSlaveCores>                 DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
  /* Add implementation of EcuM_WaitForSlaveCores() */
  
  return;
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           </USERBLOCK>                                       DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
} /* End of EcuM_WaitForSlaveCores() */
#endif

#if(ECUM_SLEEPMODELIST == STD_ON)

FUNC(void, ECUM_CODE) EcuM_GenerateRamHash(void)
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           <USERBLOCK EcuM_GenerateRamHash>                   DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
  /* Add implementation of EcuM_GenerateRamHash() */
  
  return;
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           </USERBLOCK>                                       DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
} /* End of EcuM_GenerateRamHash() */

FUNC(uint8, ECUM_CODE) EcuM_CheckRamHash(void)
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           <USERBLOCK EcuM_CheckRamHash>                      DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
  /* Add implementation of EcuM_CheckRamHash() */
  
  return (1u);
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           </USERBLOCK>                                       DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
} /* End of EcuM_CheckRamHash() */

FUNC(void, ECUM_CODE) EcuM_McuSetMode(Mcu_ModeType McuMode)
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           <USERBLOCK EcuM_McuSetMode>                        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
  /* Add implementation of EcuM_McuSetMode() */
  Mcu_SetMode(McuMode);
  
  return;
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           </USERBLOCK>                                       DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
} /* End of EcuM_McuSetMode() */

#if(ECUM_POLLINGOFSLEEPMODELIST == STD_ON)
FUNC(void, ECUM_CODE) EcuM_SleepActivity(void)
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           <USERBLOCK EcuM_SleepActivity>                     DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
  /* Add implementation of EcuM_SleepActivity() */
  
  return;
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           </USERBLOCK>                                       DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
} /* End of EcuM_SleepActivity() */
#endif

FUNC(void, ECUM_CODE) EcuM_EnableWakeupSources(EcuM_WakeupSourceType wakeupSource)
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           <USERBLOCK EcuM_EnableWakeupSources>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
#if (ECUM_USE_DUMMY_STATEMENT == STD_ON)
  /* dummy assignment to prevent compiler warnings on most of the compilers. */
  (void)wakeupSource; /* PRQA S 3112 */ /* MD_EcuM_3112 */
#endif
  /* Add implementation of EcuM_EnableWakeupSources() */
  
  return;
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           </USERBLOCK>                                       DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
} /* End of EcuM_EnableWakeupSources() */

FUNC(void, ECUM_CODE) EcuM_DisableWakeupSources(EcuM_WakeupSourceType wakeupSource)
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           <USERBLOCK EcuM_DisableWakeupSources>              DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
#if (ECUM_USE_DUMMY_STATEMENT == STD_ON)
  /* dummy assignment to prevent compiler warnings on most of the compilers. */
  (void)wakeupSource; /* PRQA S 3112 */ /* MD_EcuM_3112 */
#endif
  /* Add implementation of EcuM_DisableWakeupSources() */
  
  return;
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           </USERBLOCK>                                       DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
} /* End of EcuM_DisableWakeupSources() */
#endif

FUNC(void, ECUM_CODE) EcuM_CheckWakeup(EcuM_WakeupSourceType wakeupSource)/* PRQA S 1503 */ /* MD_MSR_14.1 */ /* COV_ECUM_CALLOUT */
{
#if (ECUM_CHECKWAKEUPTIMEOFWAKEUPSOURCELIST == STD_ON)
  /* Do not remove the following function call. It is necessary for the CheckWakeup timeout mechanism */
  EcuM_StartCheckWakeup(wakeupSource);
#endif

#if (ECUM_ALARM_CLOCK_PRESENT == STD_ON)
  if((ECUM_ALARM_WKSOURCE & wakeupSource) != 0)
  {
    EcuM_AlarmCheckWakeup();
  }
#endif

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           <USERBLOCK EcuM_CheckWakeup>                       DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
#if (ECUM_USE_DUMMY_STATEMENT == STD_ON)
  /* dummy assignment to prevent compiler warnings on most of the compilers. */
  (void)wakeupSource; /* PRQA S 3112 */ /* MD_EcuM_3112 */
#endif
  /* Add implementation of EcuM_CheckWakeup() */

  return;
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           </USERBLOCK>                                       DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
} /* End of EcuM_CheckWakeup() */

#if (ECUM_ALARM_CLOCK_PRESENT == STD_ON)
FUNC(void, ECUM_CODE) EcuM_GptSetNormal(Gpt_ChannelType GptChannel, Gpt_ModeType Mode)
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           <USERBLOCK EcuM_GptSetNormal>                      DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
  /* Add implementation of EcuM_GptSetNormal() */

  Gpt_EnableNotification(GptChannel);
  Gpt_SetMode(Mode);

  return;
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           </USERBLOCK>                                       DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
} /* End of EcuM_GptSetNormal() */

FUNC(void, ECUM_CODE) EcuM_GptSetSleep(Gpt_ChannelType GptChannel, Gpt_ModeType Mode)
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           <USERBLOCK EcuM_GptSetSleep>                       DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
  /* Add implementation of EcuM_GptSetSleep() */

  Gpt_EnableWakeup(GptChannel);
  Gpt_SetMode(Mode);

  return;
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           </USERBLOCK>                                       DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
} /* End of EcuM_GptSetSleep() */
#endif



/**********************************************************************************************************************
 *  CALLOUTS FROM THE UP PHASE
 *********************************************************************************************************************/

#if(ECUM_VALIDATIONTIMEOFWAKEUPSOURCELIST == STD_ON)

FUNC(void, ECUM_CODE) EcuM_StartWakeupSources(EcuM_WakeupSourceType wakeupSource)
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           <USERBLOCK EcuM_StartWakeupSources>                DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
#if (ECUM_USE_DUMMY_STATEMENT == STD_ON)
  /* dummy assignment to prevent compiler warnings on most of the compilers. */
  (void)wakeupSource; /* PRQA S 3112 */ /* MD_EcuM_3112 */
#endif
  /* Add implementation of EcuM_StartWakeupSources() */
  
  return;
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           </USERBLOCK>                                       DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
} /* End of EcuM_StartWakeupSources() */

FUNC(void, ECUM_CODE) EcuM_StopWakeupSources(EcuM_WakeupSourceType wakeupSource)
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           <USERBLOCK EcuM_StopWakeupSources>                 DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
#if (ECUM_USE_DUMMY_STATEMENT == STD_ON)
  /* dummy assignment to prevent compiler warnings on most of the compilers. */
  (void)wakeupSource; /* PRQA S 3112 */ /* MD_EcuM_3112 */
#endif
  /* Add implementation of EcuM_StopWakeupSources() */
  
  return;
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           </USERBLOCK>                                       DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
} /* End of EcuM_StopWakeupSources() */

FUNC(void, ECUM_CODE) EcuM_CheckValidation(EcuM_WakeupSourceType wakeupSource)
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           <USERBLOCK EcuM_CheckValidation>                   DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
#if (ECUM_USE_DUMMY_STATEMENT == STD_ON)
  /* dummy assignment to prevent compiler warnings on most of the compilers. */
  (void)wakeupSource; /* PRQA S 3112 */ /* MD_EcuM_3112 */
#endif
  /* Add implementation of EcuM_CheckValidation() */

  return;
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           </USERBLOCK>                                       DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
} /* End of EcuM_CheckValidation() */

#endif



#if (ECUM_BSW_ERROR_HOOK == STD_ON)
/**********************************************************************************************************************
 *  Errorhook for BSW errors during initialization
 *********************************************************************************************************************/
FUNC(void, ECUM_CODE) EcuM_BswErrorHook(uint16 BswModuleId, uint8 ErrorId)
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           <USERBLOCK EcuM_BswErrorHook>                      DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
 
#if (ECUM_USE_DUMMY_STATEMENT == STD_ON)
  /* dummy assignment to prevent compiler warnings on most of the compilers. */
  (void)BswModuleId;  /* PRQA S 3112 */ /* MD_EcuM_3112 */
  (void)ErrorId;      /* PRQA S 3112 */ /* MD_EcuM_3112 */
#endif
  /* Add implementation of EcuM_BswErrorHook() */
  
  if(BswModuleId == ECUM_MODULE_ID)
  {
    /* Abort initialization per default if the EcuM has reported an BswError */
    while(1)
    {
    }
  }

  return;
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           </USERBLOCK>                                       DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
} /* End of EcuM_BswErrorHook() */
#endif

#define ECUM_STOP_SEC_CODE
#include "MemMap.h"  /* PRQA S 5087 */ /* MD_MSR_19.1 */

#if 0
#endif


/**********************************************************************************************************************
 *  END OF FILE: ECUM_CALLOUT_STUBS.C
 *********************************************************************************************************************/


