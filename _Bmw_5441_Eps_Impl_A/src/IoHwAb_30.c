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
 *            Module: IoHwAb
 *           Program: MSR BAC 4.x (MSR_Bmw_SLP4)
 *          Customer: Nxtr Automotive Corporation
 *       Expiry Date: Not restricted
 *  Ordered Derivat.: Renesas RH850 P1M R7F701363EAFP
 *    License Scope : The usage is restricted to CBD1700369_D04
 *
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *              File: IoHwAb_30.c
 *   Generation Time: 2018-04-25 15:31:26
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


#define IOHWAB_SOURCE

/**********************************************************************************************************************
 *  INCLUDES
 **********************************************************************************************************************/

/* ===== MODULE INCLUDES ================================================== */
#include "IoHwAb.h" 
#include "IoHwAb_Cbk.h"
#include "IoHwAb_Cfg.h"


/* ===== RTE INCLUDE ====================================================== */
#include "Rte_IoHwAb.h"


/* ===== USER INCLUDES ==================================================== */
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           <USERBLOCK User Includes>
 *********************************************************************************************************************/
/*****************************************************************************
* Copyright 2017 Nxtr 
* Nxtr Confidential
*
* Module File Name:   IoHwAb_30.c
* Module Description: Function definitions for IoHwAb generated functions
* Project           : CBD   
* Author            : Kevin Smith
*****************************************************************************
* Version Control:
* %version:          5 %
* %derived_by:       tzyksv %
*----------------------------------------------------------------------------------------------------------------------
* Date      Rev      Author         Change Description                                                           SCR #
* -------   -------  --------  ---------------------------------------------------------------------------     --------
* 09/26/17  1        KJS       Initial version							                                      EA4#14844
* 10/04/17  2        KJS       Updated function stubs with required content                                   EA4#14844
* 01/29/18  3        AR        Updated for ES330A_PhaDiscnct integration                                      EA4#19852
* 04/27/18  4        AR        Updated for Turns counter QEP implementation                                   EA4#22691
************************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           </USERBLOCK>
 *********************************************************************************************************************/



/**********************************************************************************************************************
 *  VERSION CHECK
 **********************************************************************************************************************/
#define IOHWAB_C_MAJOR_VERSION  (6u) 
#define IOHWAB_C_MINOR_VERSION  (00u) 
#define IOHWAB_C_PATCH_VERSION  (00u) 

#if (  (IOHWAB_CFG_MAJOR_VERSION != IOHWAB_C_MAJOR_VERSION) \
    || (IOHWAB_CFG_MINOR_VERSION != IOHWAB_C_MINOR_VERSION) )
        #error "Version numbers of IoHwAb.c and IoHwAb_Cfg.h are inconsistent!"
#endif

#if(   (IOHWAB_SW_MAJOR_VERSION != (3u)) \
    || (IOHWAB_SW_MINOR_VERSION != (0u)) )
    #error "Version numbers of IoHwAb.c and IoHwAb.h are inconsistent!"
#endif

#if(   (IOHWAB_CBK_MAJOR_VERSION != IOHWAB_C_MAJOR_VERSION) \
    || (IOHWAB_CBK_MINOR_VERSION != IOHWAB_C_MINOR_VERSION) )
    #error "Version numbers of IoHwAb.c and IoHwAb_Cbk.h are inconsistent!"
#endif



/**********************************************************************************************************************
 *  LOCAL CONSTANT MACROS
 **********************************************************************************************************************/

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           <USERBLOCK User Macros>
 *********************************************************************************************************************/
/* TODO: Add user macros here */
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           </USERBLOCK>
 *********************************************************************************************************************/



/**********************************************************************************************************************
 *  GLOBAL DATA
 **********************************************************************************************************************/

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           <USERBLOCK User Data>
 *********************************************************************************************************************/
/* TODO: Add user variables here */
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           </USERBLOCK>
 *********************************************************************************************************************/



/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 **********************************************************************************************************************/

#define IOHWAB_START_SEC_CODE
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


/* Hint: IoHwAb_Init() has been removed from the code. Use the configuration switch 'IoHwAbUseInitFunction'
   to enable it. */



/**********************************************************************************************************************
 *  CLIENT/SERVER PORTS
 **********************************************************************************************************************/


/* ----- Operations Of Client/Server Port SetGpioTmplMonrWdg ----- */

/**********************************************************************************************************************
 *  IoHwAb_SetGpioTmplMonrWdg_Oper
 **********************************************************************************************************************/
/*! \brief      The method IoHwAb_SetGpioTmplMonrWdg_Oper is an operation of the C/S port 
 *              SetGpioTmplMonrWdg
 *  \param[in]  PinSt_Arg                       Parameter 'PinSt_Arg'   
 **********************************************************************************************************************/
FUNC(Std_ReturnType, IOHWAB_CODE) IoHwAb_SetGpioTmplMonrWdg_Oper(
  IOHWAB_BOOL PinSt_Arg
)
{
  Std_ReturnType ReturnValue = E_OK;
  
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           <USERBLOCK SetGpioTmplMonrWdg_Oper>
 *********************************************************************************************************************/
    
    Dio_WriteChannel(DioConf_DioChannel_TmplMonrWdg, PinSt_Arg);
    
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           </USERBLOCK>
 *********************************************************************************************************************/

  return ReturnValue;    
} /* IoHwAb_SetGpioTmplMonrWdg_Oper() */ /* PRQA S 2006 */ /* MD_MSR_14.7 */




/* ----- Operations Of Client/Server Port SetGpioSysFlt2A ----- */

/**********************************************************************************************************************
 *  IoHwAb_SetGpioSysFlt2A_Oper
 **********************************************************************************************************************/
/*! \brief      The method IoHwAb_SetGpioSysFlt2A_Oper is an operation of the C/S port 
 *              SetGpioSysFlt2A
 *  \param[in]  PinSt_Arg                       Parameter 'PinSt_Arg'   
 **********************************************************************************************************************/
FUNC(Std_ReturnType, IOHWAB_CODE) IoHwAb_SetGpioSysFlt2A_Oper(
  IOHWAB_BOOL PinSt_Arg
)
{
  Std_ReturnType ReturnValue = E_OK;
  
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           <USERBLOCK SetGpioSysFlt2A_Oper>
 *********************************************************************************************************************/
    
    Dio_WriteChannel(DioConf_DioChannel_SysFlt2A, PinSt_Arg);
    
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           </USERBLOCK>
 *********************************************************************************************************************/

  return ReturnValue;    
} /* IoHwAb_SetGpioSysFlt2A_Oper() */ /* PRQA S 2006 */ /* MD_MSR_14.7 */




/* ----- Operations Of Client/Server Port GetGpioMcuEna ----- */

/**********************************************************************************************************************
 *  IoHwAb_GetGpioMcuEna_Oper
 **********************************************************************************************************************/
/*! \brief      The method IoHwAb_GetGpioMcuEna_Oper is an operation of the C/S port 
 *              GetGpioMcuEna
 *  \param[out] PinSt_Arg                       Parameter 'PinSt_Arg'   
 **********************************************************************************************************************/
FUNC(Std_ReturnType, IOHWAB_CODE) IoHwAb_GetGpioMcuEna_Oper(
  P2VAR(IOHWAB_BOOL, AUTOMATIC, RTE_IOHWAB_APPL_VAR) PinSt_Arg
)
{
  Std_ReturnType ReturnValue = E_OK;
  
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           <USERBLOCK GetGpioMcuEna_Oper>
 *********************************************************************************************************************/
    
    *PinSt_Arg = Dio_ReadChannel(DioConf_DioChannel_McuEna);
    
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           </USERBLOCK>
 *********************************************************************************************************************/

  return ReturnValue;    
} /* IoHwAb_GetGpioMcuEna_Oper() */ /* PRQA S 2006 */ /* MD_MSR_14.7 */




/* ----- Operations Of Client/Server Port GetGpioPwrOutpEnaFb ----- */

/**********************************************************************************************************************
 *  IoHwAb_GetGpioPwrOutpEnaFb_Oper
 **********************************************************************************************************************/
/*! \brief      The method IoHwAb_GetGpioPwrOutpEnaFb_Oper is an operation of the C/S port 
 *              GetGpioPwrOutpEnaFb
 *  \param[out] PinSt_Arg                       Parameter 'PinSt_Arg'   
 **********************************************************************************************************************/
FUNC(Std_ReturnType, IOHWAB_CODE) IoHwAb_GetGpioPwrOutpEnaFb_Oper(
  P2VAR(IOHWAB_BOOL, AUTOMATIC, RTE_IOHWAB_APPL_VAR) PinSt_Arg
)
{
  Std_ReturnType ReturnValue = E_OK;
  
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           <USERBLOCK GetGpioPwrOutpEnaFb_Oper>
 *********************************************************************************************************************/
    
    *PinSt_Arg = Dio_ReadChannel(DioConf_DioChannel_PwrOutpEnaFb);
    
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           </USERBLOCK>
 *********************************************************************************************************************/

  return ReturnValue;    
} /* IoHwAb_GetGpioPwrOutpEnaFb_Oper() */ /* PRQA S 2006 */ /* MD_MSR_14.7 */




/* ----- Operations Of Client/Server Port GetGpioGateDrv0Diagc ----- */

/**********************************************************************************************************************
 *  IoHwAb_GetGpioGateDrv0Diagc_Oper
 **********************************************************************************************************************/
/*! \brief      The method IoHwAb_GetGpioGateDrv0Diagc_Oper is an operation of the C/S port 
 *              GetGpioGateDrv0Diagc
 *  \param[out] PinSt_Arg                       Parameter 'PinSt_Arg'   
 **********************************************************************************************************************/
FUNC(Std_ReturnType, IOHWAB_CODE) IoHwAb_GetGpioGateDrv0Diagc_Oper(
  P2VAR(IOHWAB_BOOL, AUTOMATIC, RTE_IOHWAB_APPL_VAR) PinSt_Arg
)
{
  Std_ReturnType ReturnValue = E_OK;
  
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           <USERBLOCK GetGpioGateDrv0Diagc_Oper>
 *********************************************************************************************************************/
    
    *PinSt_Arg = Dio_ReadChannel(DioConf_DioChannel_GateDrv0Diagc);
    
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           </USERBLOCK>
 *********************************************************************************************************************/

  return ReturnValue;    
} /* IoHwAb_GetGpioGateDrv0Diagc_Oper() */ /* PRQA S 2006 */ /* MD_MSR_14.7 */




/* ----- Operations Of Client/Server Port SetFctGpioPhaALowrCmd ----- */

/**********************************************************************************************************************
 *  IoHwAb_SetFctGpioPhaALowrCmd_Oper
 **********************************************************************************************************************/
/*! \brief      The method IoHwAb_SetFctGpioPhaALowrCmd_Oper is an operation of the C/S port 
 *              SetFctGpioPhaALowrCmd
 **********************************************************************************************************************/
FUNC(Std_ReturnType, IOHWAB_CODE) IoHwAb_SetFctGpioPhaALowrCmd_Oper()
{
  Std_ReturnType ReturnValue = E_OK;
  
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           <USERBLOCK SetFctGpioPhaALowrCmd_Oper>
 *********************************************************************************************************************/
    
    Port_SetToDioMode(Port_PortGroup3_PortPin8_PhaALowrCmd);
    
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           </USERBLOCK>
 *********************************************************************************************************************/

  return ReturnValue;    
} /* IoHwAb_SetFctGpioPhaALowrCmd_Oper() */ /* PRQA S 2006 */ /* MD_MSR_14.7 */




/* ----- Operations Of Client/Server Port SetFctGpioPhaAUpprCmd ----- */

/**********************************************************************************************************************
 *  IoHwAb_SetFctGpioPhaAUpprCmd_Oper
 **********************************************************************************************************************/
/*! \brief      The method IoHwAb_SetFctGpioPhaAUpprCmd_Oper is an operation of the C/S port 
 *              SetFctGpioPhaAUpprCmd
 **********************************************************************************************************************/
FUNC(Std_ReturnType, IOHWAB_CODE) IoHwAb_SetFctGpioPhaAUpprCmd_Oper()
{
  Std_ReturnType ReturnValue = E_OK;
  
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           <USERBLOCK SetFctGpioPhaAUpprCmd_Oper>
 *********************************************************************************************************************/
    
    Port_SetToDioMode(Port_PortGroup3_PortPin7_PhaAUpprCmd);
    
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           </USERBLOCK>
 *********************************************************************************************************************/

  return ReturnValue;    
} /* IoHwAb_SetFctGpioPhaAUpprCmd_Oper() */ /* PRQA S 2006 */ /* MD_MSR_14.7 */




/* ----- Operations Of Client/Server Port SetFctGpioPhaBUpprCmd ----- */

/**********************************************************************************************************************
 *  IoHwAb_SetFctGpioPhaBUpprCmd_Oper
 **********************************************************************************************************************/
/*! \brief      The method IoHwAb_SetFctGpioPhaBUpprCmd_Oper is an operation of the C/S port 
 *              SetFctGpioPhaBUpprCmd
 **********************************************************************************************************************/
FUNC(Std_ReturnType, IOHWAB_CODE) IoHwAb_SetFctGpioPhaBUpprCmd_Oper()
{
  Std_ReturnType ReturnValue = E_OK;
  
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           <USERBLOCK SetFctGpioPhaBUpprCmd_Oper>
 *********************************************************************************************************************/
    
    Port_SetToDioMode(Port_PortGroup3_PortPin9_PhaBUpprCmd);
    
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           </USERBLOCK>
 *********************************************************************************************************************/

  return ReturnValue;    
} /* IoHwAb_SetFctGpioPhaBUpprCmd_Oper() */ /* PRQA S 2006 */ /* MD_MSR_14.7 */




/* ----- Operations Of Client/Server Port SetFctGpioPhaCLowrCmd ----- */

/**********************************************************************************************************************
 *  IoHwAb_SetFctGpioPhaCLowrCmd_Oper
 **********************************************************************************************************************/
/*! \brief      The method IoHwAb_SetFctGpioPhaCLowrCmd_Oper is an operation of the C/S port 
 *              SetFctGpioPhaCLowrCmd
 **********************************************************************************************************************/
FUNC(Std_ReturnType, IOHWAB_CODE) IoHwAb_SetFctGpioPhaCLowrCmd_Oper()
{
  Std_ReturnType ReturnValue = E_OK;
  
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           <USERBLOCK SetFctGpioPhaCLowrCmd_Oper>
 *********************************************************************************************************************/
    
    Port_SetToDioMode(Port_PortGroup3_PortPin13_PhaCLowrCmd);
    
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           </USERBLOCK>
 *********************************************************************************************************************/

  return ReturnValue;    
} /* IoHwAb_SetFctGpioPhaCLowrCmd_Oper() */ /* PRQA S 2006 */ /* MD_MSR_14.7 */




/* ----- Operations Of Client/Server Port SetFctGpioPhaCUpprCmd ----- */

/**********************************************************************************************************************
 *  IoHwAb_SetFctGpioPhaCUpprCmd_Oper
 **********************************************************************************************************************/
/*! \brief      The method IoHwAb_SetFctGpioPhaCUpprCmd_Oper is an operation of the C/S port 
 *              SetFctGpioPhaCUpprCmd
 **********************************************************************************************************************/
FUNC(Std_ReturnType, IOHWAB_CODE) IoHwAb_SetFctGpioPhaCUpprCmd_Oper()
{
  Std_ReturnType ReturnValue = E_OK;
  
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           <USERBLOCK SetFctGpioPhaCUpprCmd_Oper>
 *********************************************************************************************************************/
    
    Port_SetToDioMode(Port_PortGroup3_PortPin12_PhaCUpprCmd);
    
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           </USERBLOCK>
 *********************************************************************************************************************/

  return ReturnValue;    
} /* IoHwAb_SetFctGpioPhaCUpprCmd_Oper() */ /* PRQA S 2006 */ /* MD_MSR_14.7 */




/* ----- Operations Of Client/Server Port SetFctPeriphPhaALowrCmd ----- */

/**********************************************************************************************************************
 *  IoHwAb_SetFctPeriphPhaALowrCmd_Oper
 **********************************************************************************************************************/
/*! \brief      The method IoHwAb_SetFctPeriphPhaALowrCmd_Oper is an operation of the C/S port 
 *              SetFctPeriphPhaALowrCmd
 **********************************************************************************************************************/
FUNC(Std_ReturnType, IOHWAB_CODE) IoHwAb_SetFctPeriphPhaALowrCmd_Oper()
{
  Std_ReturnType ReturnValue = E_OK;
  
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           <USERBLOCK SetFctPeriphPhaALowrCmd_Oper>
 *********************************************************************************************************************/
    
    Port_SetToAlternateMode(Port_PortGroup3_PortPin8_PhaALowrCmd);
    
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           </USERBLOCK>
 *********************************************************************************************************************/

  return ReturnValue;    
} /* IoHwAb_SetFctPeriphPhaALowrCmd_Oper() */ /* PRQA S 2006 */ /* MD_MSR_14.7 */




/* ----- Operations Of Client/Server Port SetFctGpioPhaBLowrCmd ----- */

/**********************************************************************************************************************
 *  IoHwAb_SetFctGpioPhaBLowrCmd_Oper
 **********************************************************************************************************************/
/*! \brief      The method IoHwAb_SetFctGpioPhaBLowrCmd_Oper is an operation of the C/S port 
 *              SetFctGpioPhaBLowrCmd
 **********************************************************************************************************************/
FUNC(Std_ReturnType, IOHWAB_CODE) IoHwAb_SetFctGpioPhaBLowrCmd_Oper()
{
  Std_ReturnType ReturnValue = E_OK;
  
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           <USERBLOCK SetFctGpioPhaBLowrCmd_Oper>
 *********************************************************************************************************************/
    
    Port_SetToDioMode(Port_PortGroup3_PortPin10_PhaBLowrCmd);
    
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           </USERBLOCK>
 *********************************************************************************************************************/

  return ReturnValue;    
} /* IoHwAb_SetFctGpioPhaBLowrCmd_Oper() */ /* PRQA S 2006 */ /* MD_MSR_14.7 */




/* ----- Operations Of Client/Server Port SetFctPeriphPhaAUpprCmd ----- */

/**********************************************************************************************************************
 *  IoHwAb_SetFctPeriphPhaAUpprCmd_Oper
 **********************************************************************************************************************/
/*! \brief      The method IoHwAb_SetFctPeriphPhaAUpprCmd_Oper is an operation of the C/S port 
 *              SetFctPeriphPhaAUpprCmd
 **********************************************************************************************************************/
FUNC(Std_ReturnType, IOHWAB_CODE) IoHwAb_SetFctPeriphPhaAUpprCmd_Oper()
{
  Std_ReturnType ReturnValue = E_OK;
  
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           <USERBLOCK SetFctPeriphPhaAUpprCmd_Oper>
 *********************************************************************************************************************/
    
    Port_SetToAlternateMode(Port_PortGroup3_PortPin7_PhaAUpprCmd);
    
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           </USERBLOCK>
 *********************************************************************************************************************/

  return ReturnValue;    
} /* IoHwAb_SetFctPeriphPhaAUpprCmd_Oper() */ /* PRQA S 2006 */ /* MD_MSR_14.7 */




/* ----- Operations Of Client/Server Port SetFctPeriphPhaBLowrCmd ----- */

/**********************************************************************************************************************
 *  IoHwAb_SetFctPeriphPhaBLowrCmd_Oper
 **********************************************************************************************************************/
/*! \brief      The method IoHwAb_SetFctPeriphPhaBLowrCmd_Oper is an operation of the C/S port 
 *              SetFctPeriphPhaBLowrCmd
 **********************************************************************************************************************/
FUNC(Std_ReturnType, IOHWAB_CODE) IoHwAb_SetFctPeriphPhaBLowrCmd_Oper()
{
  Std_ReturnType ReturnValue = E_OK;
  
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           <USERBLOCK SetFctPeriphPhaBLowrCmd_Oper>
 *********************************************************************************************************************/
    
    Port_SetToAlternateMode(Port_PortGroup3_PortPin10_PhaBLowrCmd);
    
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           </USERBLOCK>
 *********************************************************************************************************************/

  return ReturnValue;    
} /* IoHwAb_SetFctPeriphPhaBLowrCmd_Oper() */ /* PRQA S 2006 */ /* MD_MSR_14.7 */




/* ----- Operations Of Client/Server Port SetFctPeriphPhaBUpprCmd ----- */

/**********************************************************************************************************************
 *  IoHwAb_SetFctPeriphPhaBUpprCmd_Oper
 **********************************************************************************************************************/
/*! \brief      The method IoHwAb_SetFctPeriphPhaBUpprCmd_Oper is an operation of the C/S port 
 *              SetFctPeriphPhaBUpprCmd
 **********************************************************************************************************************/
FUNC(Std_ReturnType, IOHWAB_CODE) IoHwAb_SetFctPeriphPhaBUpprCmd_Oper()
{
  Std_ReturnType ReturnValue = E_OK;
  
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           <USERBLOCK SetFctPeriphPhaBUpprCmd_Oper>
 *********************************************************************************************************************/
    
    Port_SetToAlternateMode(Port_PortGroup3_PortPin9_PhaBUpprCmd);
    
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           </USERBLOCK>
 *********************************************************************************************************************/

  return ReturnValue;    
} /* IoHwAb_SetFctPeriphPhaBUpprCmd_Oper() */ /* PRQA S 2006 */ /* MD_MSR_14.7 */




/* ----- Operations Of Client/Server Port SetFctPeriphPhaCLowrCmd ----- */

/**********************************************************************************************************************
 *  IoHwAb_SetFctPeriphPhaCLowrCmd_Oper
 **********************************************************************************************************************/
/*! \brief      The method IoHwAb_SetFctPeriphPhaCLowrCmd_Oper is an operation of the C/S port 
 *              SetFctPeriphPhaCLowrCmd
 **********************************************************************************************************************/
FUNC(Std_ReturnType, IOHWAB_CODE) IoHwAb_SetFctPeriphPhaCLowrCmd_Oper()
{
  Std_ReturnType ReturnValue = E_OK;
  
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           <USERBLOCK SetFctPeriphPhaCLowrCmd_Oper>
 *********************************************************************************************************************/
    
    Port_SetToAlternateMode(Port_PortGroup3_PortPin13_PhaCLowrCmd);
    
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           </USERBLOCK>
 *********************************************************************************************************************/

  return ReturnValue;    
} /* IoHwAb_SetFctPeriphPhaCLowrCmd_Oper() */ /* PRQA S 2006 */ /* MD_MSR_14.7 */




/* ----- Operations Of Client/Server Port SetFctPeriphPhaCUpprCmd ----- */

/**********************************************************************************************************************
 *  IoHwAb_SetFctPeriphPhaCUpprCmd_Oper
 **********************************************************************************************************************/
/*! \brief      The method IoHwAb_SetFctPeriphPhaCUpprCmd_Oper is an operation of the C/S port 
 *              SetFctPeriphPhaCUpprCmd
 **********************************************************************************************************************/
FUNC(Std_ReturnType, IOHWAB_CODE) IoHwAb_SetFctPeriphPhaCUpprCmd_Oper()
{
  Std_ReturnType ReturnValue = E_OK;
  
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           <USERBLOCK SetFctPeriphPhaCUpprCmd_Oper>
 *********************************************************************************************************************/
    
    Port_SetToAlternateMode(Port_PortGroup3_PortPin12_PhaCUpprCmd);
    
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           </USERBLOCK>
 *********************************************************************************************************************/

  return ReturnValue;    
} /* IoHwAb_SetFctPeriphPhaCUpprCmd_Oper() */ /* PRQA S 2006 */ /* MD_MSR_14.7 */




/* ----- Operations Of Client/Server Port SetGpioGateDrv0Rst ----- */

/**********************************************************************************************************************
 *  IoHwAb_SetGpioGateDrv0Rst_Oper
 **********************************************************************************************************************/
/*! \brief      The method IoHwAb_SetGpioGateDrv0Rst_Oper is an operation of the C/S port 
 *              SetGpioGateDrv0Rst
 *  \param[in]  PinSt_Arg                       Parameter 'PinSt_Arg'   
 **********************************************************************************************************************/
FUNC(Std_ReturnType, IOHWAB_CODE) IoHwAb_SetGpioGateDrv0Rst_Oper(
  IOHWAB_BOOL PinSt_Arg
)
{
  Std_ReturnType ReturnValue = E_OK;
  
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           <USERBLOCK SetGpioGateDrv0Rst_Oper>
 *********************************************************************************************************************/
    
    Dio_WriteChannel(DioConf_DioChannel_GateDrv0Rst, PinSt_Arg);
    
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           </USERBLOCK>
 *********************************************************************************************************************/

  return ReturnValue;    
} /* IoHwAb_SetGpioGateDrv0Rst_Oper() */ /* PRQA S 2006 */ /* MD_MSR_14.7 */




/* ----- Operations Of Client/Server Port SetGpioPhaALowrCmd ----- */

/**********************************************************************************************************************
 *  IoHwAb_SetGpioPhaALowrCmd_Oper
 **********************************************************************************************************************/
/*! \brief      The method IoHwAb_SetGpioPhaALowrCmd_Oper is an operation of the C/S port 
 *              SetGpioPhaALowrCmd
 *  \param[in]  PinSt_Arg                       Parameter 'PinSt_Arg'   
 **********************************************************************************************************************/
FUNC(Std_ReturnType, IOHWAB_CODE) IoHwAb_SetGpioPhaALowrCmd_Oper(
  IOHWAB_BOOL PinSt_Arg
)
{
  Std_ReturnType ReturnValue = E_OK;
  
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           <USERBLOCK SetGpioPhaALowrCmd_Oper>
 *********************************************************************************************************************/
    
    Dio_WriteChannel(DioConf_DioChannel_PhaALowrCmd, PinSt_Arg);
    
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           </USERBLOCK>
 *********************************************************************************************************************/

  return ReturnValue;    
} /* IoHwAb_SetGpioPhaALowrCmd_Oper() */ /* PRQA S 2006 */ /* MD_MSR_14.7 */




/* ----- Operations Of Client/Server Port SetGpioPhaAUpprCmd ----- */

/**********************************************************************************************************************
 *  IoHwAb_SetGpioPhaAUpprCmd_Oper
 **********************************************************************************************************************/
/*! \brief      The method IoHwAb_SetGpioPhaAUpprCmd_Oper is an operation of the C/S port 
 *              SetGpioPhaAUpprCmd
 *  \param[in]  PinSt_Arg                       Parameter 'PinSt_Arg'   
 **********************************************************************************************************************/
FUNC(Std_ReturnType, IOHWAB_CODE) IoHwAb_SetGpioPhaAUpprCmd_Oper(
  IOHWAB_BOOL PinSt_Arg
)
{
  Std_ReturnType ReturnValue = E_OK;
  
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           <USERBLOCK SetGpioPhaAUpprCmd_Oper>
 *********************************************************************************************************************/
    
    Dio_WriteChannel(DioConf_DioChannel_PhaAUpprCmd, PinSt_Arg);
    
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           </USERBLOCK>
 *********************************************************************************************************************/

  return ReturnValue;    
} /* IoHwAb_SetGpioPhaAUpprCmd_Oper() */ /* PRQA S 2006 */ /* MD_MSR_14.7 */




/* ----- Operations Of Client/Server Port SetGpioPhaBLowrCmd ----- */

/**********************************************************************************************************************
 *  IoHwAb_SetGpioPhaBLowrCmd_Oper
 **********************************************************************************************************************/
/*! \brief      The method IoHwAb_SetGpioPhaBLowrCmd_Oper is an operation of the C/S port 
 *              SetGpioPhaBLowrCmd
 *  \param[in]  PinSt_Arg                       Parameter 'PinSt_Arg'   
 **********************************************************************************************************************/
FUNC(Std_ReturnType, IOHWAB_CODE) IoHwAb_SetGpioPhaBLowrCmd_Oper(
  IOHWAB_BOOL PinSt_Arg
)
{
  Std_ReturnType ReturnValue = E_OK;
  
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           <USERBLOCK SetGpioPhaBLowrCmd_Oper>
 *********************************************************************************************************************/
    
    Dio_WriteChannel(DioConf_DioChannel_PhaBLowrCmd, PinSt_Arg);
    
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           </USERBLOCK>
 *********************************************************************************************************************/

  return ReturnValue;    
} /* IoHwAb_SetGpioPhaBLowrCmd_Oper() */ /* PRQA S 2006 */ /* MD_MSR_14.7 */




/* ----- Operations Of Client/Server Port SetGpioPhaBUpprCmd ----- */

/**********************************************************************************************************************
 *  IoHwAb_SetGpioPhaBUpprCmd_Oper
 **********************************************************************************************************************/
/*! \brief      The method IoHwAb_SetGpioPhaBUpprCmd_Oper is an operation of the C/S port 
 *              SetGpioPhaBUpprCmd
 *  \param[in]  PinSt_Arg                       Parameter 'PinSt_Arg'   
 **********************************************************************************************************************/
FUNC(Std_ReturnType, IOHWAB_CODE) IoHwAb_SetGpioPhaBUpprCmd_Oper(
  IOHWAB_BOOL PinSt_Arg
)
{
  Std_ReturnType ReturnValue = E_OK;
  
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           <USERBLOCK SetGpioPhaBUpprCmd_Oper>
 *********************************************************************************************************************/
    
    Dio_WriteChannel(DioConf_DioChannel_PhaBUpprCmd, PinSt_Arg);
    
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           </USERBLOCK>
 *********************************************************************************************************************/

  return ReturnValue;    
} /* IoHwAb_SetGpioPhaBUpprCmd_Oper() */ /* PRQA S 2006 */ /* MD_MSR_14.7 */




/* ----- Operations Of Client/Server Port SetGpioPhaCLowrCmd ----- */

/**********************************************************************************************************************
 *  IoHwAb_SetGpioPhaCLowrCmd_Oper
 **********************************************************************************************************************/
/*! \brief      The method IoHwAb_SetGpioPhaCLowrCmd_Oper is an operation of the C/S port 
 *              SetGpioPhaCLowrCmd
 *  \param[in]  PinSt_Arg                       Parameter 'PinSt_Arg'   
 **********************************************************************************************************************/
FUNC(Std_ReturnType, IOHWAB_CODE) IoHwAb_SetGpioPhaCLowrCmd_Oper(
  IOHWAB_BOOL PinSt_Arg
)
{
  Std_ReturnType ReturnValue = E_OK;
  
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           <USERBLOCK SetGpioPhaCLowrCmd_Oper>
 *********************************************************************************************************************/
    
    Dio_WriteChannel(DioConf_DioChannel_PhaCLowrCmd, PinSt_Arg);
    
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           </USERBLOCK>
 *********************************************************************************************************************/

  return ReturnValue;    
} /* IoHwAb_SetGpioPhaCLowrCmd_Oper() */ /* PRQA S 2006 */ /* MD_MSR_14.7 */




/* ----- Operations Of Client/Server Port SetGpioPhaCUpprCmd ----- */

/**********************************************************************************************************************
 *  IoHwAb_SetGpioPhaCUpprCmd_Oper
 **********************************************************************************************************************/
/*! \brief      The method IoHwAb_SetGpioPhaCUpprCmd_Oper is an operation of the C/S port 
 *              SetGpioPhaCUpprCmd
 *  \param[in]  PinSt_Arg                       Parameter 'PinSt_Arg'   
 **********************************************************************************************************************/
FUNC(Std_ReturnType, IOHWAB_CODE) IoHwAb_SetGpioPhaCUpprCmd_Oper(
  IOHWAB_BOOL PinSt_Arg
)
{
  Std_ReturnType ReturnValue = E_OK;
  
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           <USERBLOCK SetGpioPhaCUpprCmd_Oper>
 *********************************************************************************************************************/
    
    Dio_WriteChannel(DioConf_DioChannel_PhaCUpprCmd, PinSt_Arg);
    
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           </USERBLOCK>
 *********************************************************************************************************************/

  return ReturnValue;    
} /* IoHwAb_SetGpioPhaCUpprCmd_Oper() */ /* PRQA S 2006 */ /* MD_MSR_14.7 */




/* ----- Operations Of Client/Server Port SetGpioPwrTurnOffCtrl ----- */

/**********************************************************************************************************************
 *  IoHwAb_SetGpioPwrTurnOffCtrl_Oper
 **********************************************************************************************************************/
/*! \brief      The method IoHwAb_SetGpioPwrTurnOffCtrl_Oper is an operation of the C/S port 
 *              SetGpioPwrTurnOffCtrl
 *  \param[in]  PinSt_Arg                       Parameter 'PinSt_Arg'   
 **********************************************************************************************************************/
FUNC(Std_ReturnType, IOHWAB_CODE) IoHwAb_SetGpioPwrTurnOffCtrl_Oper(
  IOHWAB_BOOL PinSt_Arg
)
{
  Std_ReturnType ReturnValue = E_OK;
  
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           <USERBLOCK SetGpioPwrTurnOffCtrl_Oper>
 *********************************************************************************************************************/
    
    Dio_WriteChannel(DioConf_DioChannel_PwrTurnOffCtrl, PinSt_Arg);
    
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           </USERBLOCK>
 *********************************************************************************************************************/

  return ReturnValue;    
} /* IoHwAb_SetGpioPwrTurnOffCtrl_Oper() */ /* PRQA S 2006 */ /* MD_MSR_14.7 */




/* ----- Operations Of Client/Server Port SetGpioPhaDiscnctA ----- */

/**********************************************************************************************************************
 *  IoHwAb_SetGpioPhaDiscnctA_Oper
 **********************************************************************************************************************/
/*! \brief      The method IoHwAb_SetGpioPhaDiscnctA_Oper is an operation of the C/S port 
 *              SetGpioPhaDiscnctA
 *  \param[in]  PinSt_Arg                       Parameter 'PinSt_Arg'   
 **********************************************************************************************************************/
FUNC(Std_ReturnType, IOHWAB_CODE) IoHwAb_SetGpioPhaDiscnctA_Oper(
  IOHWAB_BOOL PinSt_Arg
)
{
  Std_ReturnType ReturnValue = E_OK;
  
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           <USERBLOCK SetGpioPhaDiscnctA_Oper>
 *********************************************************************************************************************/

	Dio_WriteChannel(DioConf_DioChannel_PhaDiscnctA, PinSt_Arg);
	
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           </USERBLOCK>
 *********************************************************************************************************************/

  return ReturnValue;    
} /* IoHwAb_SetGpioPhaDiscnctA_Oper() */ /* PRQA S 2006 */ /* MD_MSR_14.7 */




/* ----- Operations Of Client/Server Port SetGpioPhaDiscnctB ----- */

/**********************************************************************************************************************
 *  IoHwAb_SetGpioPhaDiscnctB_Oper
 **********************************************************************************************************************/
/*! \brief      The method IoHwAb_SetGpioPhaDiscnctB_Oper is an operation of the C/S port 
 *              SetGpioPhaDiscnctB
 *  \param[in]  PinSt_Arg                       Parameter 'PinSt_Arg'   
 **********************************************************************************************************************/
FUNC(Std_ReturnType, IOHWAB_CODE) IoHwAb_SetGpioPhaDiscnctB_Oper(
  IOHWAB_BOOL PinSt_Arg
)
{
  Std_ReturnType ReturnValue = E_OK;
  
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           <USERBLOCK SetGpioPhaDiscnctB_Oper>
 *********************************************************************************************************************/

	Dio_WriteChannel(DioConf_DioChannel_PhaDiscnctB, PinSt_Arg);
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           </USERBLOCK>
 *********************************************************************************************************************/

  return ReturnValue;    
} /* IoHwAb_SetGpioPhaDiscnctB_Oper() */ /* PRQA S 2006 */ /* MD_MSR_14.7 */




/* ----- Operations Of Client/Server Port SetGpioPhaDiscnctC ----- */

/**********************************************************************************************************************
 *  IoHwAb_SetGpioPhaDiscnctC_Oper
 **********************************************************************************************************************/
/*! \brief      The method IoHwAb_SetGpioPhaDiscnctC_Oper is an operation of the C/S port 
 *              SetGpioPhaDiscnctC
 *  \param[in]  PinSt_Arg                       Parameter 'PinSt_Arg'   
 **********************************************************************************************************************/
FUNC(Std_ReturnType, IOHWAB_CODE) IoHwAb_SetGpioPhaDiscnctC_Oper(
  IOHWAB_BOOL PinSt_Arg
)
{
  Std_ReturnType ReturnValue = E_OK;
  
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           <USERBLOCK SetGpioPhaDiscnctC_Oper>
 *********************************************************************************************************************/
	Dio_WriteChannel(DioConf_DioChannel_PhaDiscnctC, PinSt_Arg);
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           </USERBLOCK>
 *********************************************************************************************************************/

  return ReturnValue;    
} /* IoHwAb_SetGpioPhaDiscnctC_Oper() */ /* PRQA S 2006 */ /* MD_MSR_14.7 */




/* ----- Operations Of Client/Server Port SetGpioMotAg0Mosi ----- */

/**********************************************************************************************************************
 *  IoHwAb_SetGpioMotAg0Mosi_Oper
 **********************************************************************************************************************/
/*! \brief      The method IoHwAb_SetGpioMotAg0Mosi_Oper is an operation of the C/S port 
 *              SetGpioMotAg0Mosi
 *  \param[in]  PinSt_Arg                       Parameter 'PinSt_Arg'   
 **********************************************************************************************************************/
FUNC(Std_ReturnType, IOHWAB_CODE) IoHwAb_SetGpioMotAg0Mosi_Oper(
  IOHWAB_BOOL PinSt_Arg
)
{
  Std_ReturnType ReturnValue = E_OK;
  
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           <USERBLOCK SetGpioMotAg0Mosi_Oper>
 *********************************************************************************************************************/
	Dio_WriteChannel(DioConf_DioChannel_MotAg0Mosi,PinSt_Arg);
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           </USERBLOCK>
 *********************************************************************************************************************/

  return ReturnValue;    
} /* IoHwAb_SetGpioMotAg0Mosi_Oper() */ /* PRQA S 2006 */ /* MD_MSR_14.7 */




/* ----- Operations Of Client/Server Port SetFctGpioMotAg0Mosi ----- */

/**********************************************************************************************************************
 *  IoHwAb_SetFctGpioMotAg0Mosi_Oper
 **********************************************************************************************************************/
/*! \brief      The method IoHwAb_SetFctGpioMotAg0Mosi_Oper is an operation of the C/S port 
 *              SetFctGpioMotAg0Mosi
 **********************************************************************************************************************/
FUNC(Std_ReturnType, IOHWAB_CODE) IoHwAb_SetFctGpioMotAg0Mosi_Oper()
{
  Std_ReturnType ReturnValue = E_OK;
  
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           <USERBLOCK SetFctGpioMotAg0Mosi_Oper>
 *********************************************************************************************************************/
	Port_SetToDioMode(Port_PortGroup2_PortPin8_MotAg0Mosi);
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           </USERBLOCK>
 *********************************************************************************************************************/

  return ReturnValue;    
} /* IoHwAb_SetFctGpioMotAg0Mosi_Oper() */ /* PRQA S 2006 */ /* MD_MSR_14.7 */




/* ----- Operations Of Client/Server Port SetGpioMotAg0Clk ----- */

/**********************************************************************************************************************
 *  IoHwAb_SetGpioMotAg0Clk_Oper
 **********************************************************************************************************************/
/*! \brief      The method IoHwAb_SetGpioMotAg0Clk_Oper is an operation of the C/S port 
 *              SetGpioMotAg0Clk
 *  \param[in]  PinSt_Arg                       Parameter 'PinSt_Arg'   
 **********************************************************************************************************************/
FUNC(Std_ReturnType, IOHWAB_CODE) IoHwAb_SetGpioMotAg0Clk_Oper(
  IOHWAB_BOOL PinSt_Arg
)
{
  Std_ReturnType ReturnValue = E_OK;
  
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           <USERBLOCK SetGpioMotAg0Clk_Oper>
 *********************************************************************************************************************/
	Dio_WriteChannel(DioConf_DioChannel_MotAg0Clk,PinSt_Arg);
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           </USERBLOCK>
 *********************************************************************************************************************/

  return ReturnValue;    
} /* IoHwAb_SetGpioMotAg0Clk_Oper() */ /* PRQA S 2006 */ /* MD_MSR_14.7 */




/* ----- Operations Of Client/Server Port SetFctGpioMotAg0Clk ----- */

/**********************************************************************************************************************
 *  IoHwAb_SetFctGpioMotAg0Clk_Oper
 **********************************************************************************************************************/
/*! \brief      The method IoHwAb_SetFctGpioMotAg0Clk_Oper is an operation of the C/S port 
 *              SetFctGpioMotAg0Clk
 **********************************************************************************************************************/
FUNC(Std_ReturnType, IOHWAB_CODE) IoHwAb_SetFctGpioMotAg0Clk_Oper()
{
  Std_ReturnType ReturnValue = E_OK;
  
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           <USERBLOCK SetFctGpioMotAg0Clk_Oper>
 *********************************************************************************************************************/
	Port_SetToDioMode(Port_PortGroup2_PortPin9_MotAg0Clk);
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           </USERBLOCK>
 *********************************************************************************************************************/

  return ReturnValue;    
} /* IoHwAb_SetFctGpioMotAg0Clk_Oper() */ /* PRQA S 2006 */ /* MD_MSR_14.7 */




/* ----- Operations Of Client/Server Port SetGpioMotAg0Cs ----- */

/**********************************************************************************************************************
 *  IoHwAb_SetGpioMotAg0Cs_Oper
 **********************************************************************************************************************/
/*! \brief      The method IoHwAb_SetGpioMotAg0Cs_Oper is an operation of the C/S port 
 *              SetGpioMotAg0Cs
 *  \param[in]  PinSt_Arg                       Parameter 'PinSt_Arg'   
 **********************************************************************************************************************/
FUNC(Std_ReturnType, IOHWAB_CODE) IoHwAb_SetGpioMotAg0Cs_Oper(
  IOHWAB_BOOL PinSt_Arg
)
{
  Std_ReturnType ReturnValue = E_OK;
  
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           <USERBLOCK SetGpioMotAg0Cs_Oper>
 *********************************************************************************************************************/
	Dio_WriteChannel(DioConf_DioChannel_MotAg0Cs,PinSt_Arg);
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           </USERBLOCK>
 *********************************************************************************************************************/

  return ReturnValue;    
} /* IoHwAb_SetGpioMotAg0Cs_Oper() */ /* PRQA S 2006 */ /* MD_MSR_14.7 */




/* ----- Operations Of Client/Server Port SetFctGpioMotAg0Cs ----- */

/**********************************************************************************************************************
 *  IoHwAb_SetFctGpioMotAg0Cs_Oper
 **********************************************************************************************************************/
/*! \brief      The method IoHwAb_SetFctGpioMotAg0Cs_Oper is an operation of the C/S port 
 *              SetFctGpioMotAg0Cs
 **********************************************************************************************************************/
FUNC(Std_ReturnType, IOHWAB_CODE) IoHwAb_SetFctGpioMotAg0Cs_Oper()
{
  Std_ReturnType ReturnValue = E_OK;
  
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           <USERBLOCK SetFctGpioMotAg0Cs_Oper>
 *********************************************************************************************************************/
	Port_SetToDioMode(Port_PortGroup4_PortPin3_MotAg0Cs);
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           </USERBLOCK>
 *********************************************************************************************************************/

  return ReturnValue;    
} /* IoHwAb_SetFctGpioMotAg0Cs_Oper() */ /* PRQA S 2006 */ /* MD_MSR_14.7 */




/* ----- Operations Of Client/Server Port SetGpioMotAg1Mosi ----- */

/**********************************************************************************************************************
 *  IoHwAb_SetGpioMotAg1Mosi_Oper
 **********************************************************************************************************************/
/*! \brief      The method IoHwAb_SetGpioMotAg1Mosi_Oper is an operation of the C/S port 
 *              SetGpioMotAg1Mosi
 *  \param[in]  PinSt_Arg                       Parameter 'PinSt_Arg'   
 **********************************************************************************************************************/
FUNC(Std_ReturnType, IOHWAB_CODE) IoHwAb_SetGpioMotAg1Mosi_Oper(
  IOHWAB_BOOL PinSt_Arg
)
{
  Std_ReturnType ReturnValue = E_OK;
  
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           <USERBLOCK SetGpioMotAg1Mosi_Oper>
 *********************************************************************************************************************/
	Dio_WriteChannel(DioConf_DioChannel_MotAg2Mosi,PinSt_Arg);
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           </USERBLOCK>
 *********************************************************************************************************************/

  return ReturnValue;    
} /* IoHwAb_SetGpioMotAg1Mosi_Oper() */ /* PRQA S 2006 */ /* MD_MSR_14.7 */




/* ----- Operations Of Client/Server Port SetFctGpioMotAg1Mosi ----- */

/**********************************************************************************************************************
 *  IoHwAb_SetFctGpioMotAg1Mosi_Oper
 **********************************************************************************************************************/
/*! \brief      The method IoHwAb_SetFctGpioMotAg1Mosi_Oper is an operation of the C/S port 
 *              SetFctGpioMotAg1Mosi
 **********************************************************************************************************************/
FUNC(Std_ReturnType, IOHWAB_CODE) IoHwAb_SetFctGpioMotAg1Mosi_Oper()
{
  Std_ReturnType ReturnValue = E_OK;
  
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           <USERBLOCK SetFctGpioMotAg1Mosi_Oper>
 *********************************************************************************************************************/
	Port_SetToDioMode(Port_PortGroup2_PortPin5_MotAg2Mosi);
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           </USERBLOCK>
 *********************************************************************************************************************/

  return ReturnValue;    
} /* IoHwAb_SetFctGpioMotAg1Mosi_Oper() */ /* PRQA S 2006 */ /* MD_MSR_14.7 */




/* ----- Operations Of Client/Server Port SetGpioMotAg1Clk ----- */

/**********************************************************************************************************************
 *  IoHwAb_SetGpioMotAg1Clk_Oper
 **********************************************************************************************************************/
/*! \brief      The method IoHwAb_SetGpioMotAg1Clk_Oper is an operation of the C/S port 
 *              SetGpioMotAg1Clk
 *  \param[in]  PinSt_Arg                       Parameter 'PinSt_Arg'   
 **********************************************************************************************************************/
FUNC(Std_ReturnType, IOHWAB_CODE) IoHwAb_SetGpioMotAg1Clk_Oper(
  IOHWAB_BOOL PinSt_Arg
)
{
  Std_ReturnType ReturnValue = E_OK;
  
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           <USERBLOCK SetGpioMotAg1Clk_Oper>
 *********************************************************************************************************************/
	Dio_WriteChannel(DioConf_DioChannel_MotAg2Clk,PinSt_Arg);
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           </USERBLOCK>
 *********************************************************************************************************************/

  return ReturnValue;    
} /* IoHwAb_SetGpioMotAg1Clk_Oper() */ /* PRQA S 2006 */ /* MD_MSR_14.7 */




/* ----- Operations Of Client/Server Port SetFctGpioMotAg1Clk ----- */

/**********************************************************************************************************************
 *  IoHwAb_SetFctGpioMotAg1Clk_Oper
 **********************************************************************************************************************/
/*! \brief      The method IoHwAb_SetFctGpioMotAg1Clk_Oper is an operation of the C/S port 
 *              SetFctGpioMotAg1Clk
 **********************************************************************************************************************/
FUNC(Std_ReturnType, IOHWAB_CODE) IoHwAb_SetFctGpioMotAg1Clk_Oper()
{
  Std_ReturnType ReturnValue = E_OK;
  
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           <USERBLOCK SetFctGpioMotAg1Clk_Oper>
 *********************************************************************************************************************/
	Port_SetToDioMode(Port_PortGroup2_PortPin7_MotAg2Clk);
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           </USERBLOCK>
 *********************************************************************************************************************/

  return ReturnValue;    
} /* IoHwAb_SetFctGpioMotAg1Clk_Oper() */ /* PRQA S 2006 */ /* MD_MSR_14.7 */




/* ----- Operations Of Client/Server Port SetGpioMotAg1Cs ----- */

/**********************************************************************************************************************
 *  IoHwAb_SetGpioMotAg1Cs_Oper
 **********************************************************************************************************************/
/*! \brief      The method IoHwAb_SetGpioMotAg1Cs_Oper is an operation of the C/S port 
 *              SetGpioMotAg1Cs
 *  \param[in]  PinSt_Arg                       Parameter 'PinSt_Arg'   
 **********************************************************************************************************************/
FUNC(Std_ReturnType, IOHWAB_CODE) IoHwAb_SetGpioMotAg1Cs_Oper(
  IOHWAB_BOOL PinSt_Arg
)
{
  Std_ReturnType ReturnValue = E_OK;
  
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           <USERBLOCK SetGpioMotAg1Cs_Oper>
 *********************************************************************************************************************/
	Dio_WriteChannel(DioConf_DioChannel_MotAg2Cs,PinSt_Arg);
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           </USERBLOCK>
 *********************************************************************************************************************/

  return ReturnValue;    
} /* IoHwAb_SetGpioMotAg1Cs_Oper() */ /* PRQA S 2006 */ /* MD_MSR_14.7 */




/* ----- Operations Of Client/Server Port SetFctGpioMotAg1Cs ----- */

/**********************************************************************************************************************
 *  IoHwAb_SetFctGpioMotAg1Cs_Oper
 **********************************************************************************************************************/
/*! \brief      The method IoHwAb_SetFctGpioMotAg1Cs_Oper is an operation of the C/S port 
 *              SetFctGpioMotAg1Cs
 **********************************************************************************************************************/
FUNC(Std_ReturnType, IOHWAB_CODE) IoHwAb_SetFctGpioMotAg1Cs_Oper()
{
  Std_ReturnType ReturnValue = E_OK;
  
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           <USERBLOCK SetFctGpioMotAg1Cs_Oper>
 *********************************************************************************************************************/
	Port_SetToDioMode(Port_PortGroup3_PortPin3_MotAg2Cs);
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           </USERBLOCK>
 *********************************************************************************************************************/

  return ReturnValue;    
} /* IoHwAb_SetFctGpioMotAg1Cs_Oper() */ /* PRQA S 2006 */ /* MD_MSR_14.7 */



/**********************************************************************************************************************
 *  SENDER/RECEIVER PORTS
 **********************************************************************************************************************/


/**********************************************************************************************************************
 *  RUNNABLES
 **********************************************************************************************************************/

/**********************************************************************************************************************
 *  IoHwAb_Per1
 **********************************************************************************************************************/
/*! \brief      The method Per1 is a user defined runnable entity function that will be called
 *              every 100 msec by the RTE.
 *  \retval     void
 **********************************************************************************************************************/
FUNC(void, IOHWAB_APPL_CODE) IoHwAb_Per1(void)
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           <USERBLOCK Per1>
 *********************************************************************************************************************/
    
    /* Runnable intentionally empty.  Runnable is only present to allow mapping of IoHwAb component to a specific application */
    
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           </USERBLOCK>
 *********************************************************************************************************************/

  return;
} /* IoHwAb_Per1() */ 



/**********************************************************************************************************************
 *  SCHEDULABLES
 **********************************************************************************************************************/



/* Hint: IoHwAb_GetVersionInfo() has been removed from the code. Use the configuration switch 'IoHwAbVersionInfoApi'
   to enable it. */



/* Section for deleted/unregonized user blocks: */
#if 0
#endif


#define IOHWAB_STOP_SEC_CODE
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
/**********************************************************************************************************************
 *  END OF FILE: IoHwAb_30.c
 **********************************************************************************************************************/
