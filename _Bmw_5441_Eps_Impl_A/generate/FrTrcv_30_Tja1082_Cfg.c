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
 *            Module: FrTrcv
 *           Program: MSR BAC 4.x (MSR_Bmw_SLP4)
 *          Customer: Nxtr Automotive Corporation
 *       Expiry Date: Not restricted
 *  Ordered Derivat.: Renesas RH850 P1M R7F701363EAFP
 *    License Scope : The usage is restricted to CBD1700369_D04
 *
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *              File: FrTrcv_30_Tja1082_Cfg.c
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


#include "FrTrcv_30_Tja1082.h"
#include "FrTrcv_30_Tja1082_Cfg.h"

#define FRTRCV_30_TJA1082_START_SEC_CONST_UNSPECIFIED
#include "MemMap.h"

/* -----------------------------------------------------------------------------
    &&&~ Data definition
 ----------------------------------------------------------------------------- */

/* Transceiver initial state and capabilities */
CONST(FrTrcv_30_Tja1082_GenConfigType, FRTRCV_30_TJA1082_CONST) FrTrcv_30_Tja1082_Config[FRTRCV_30_TJA1082_MAX_NUM_OF_BTR_BUSSES] = 
{
  {
    FRTRCV_TRCVMODE_NORMAL /*  FrTrcv_InitState  */ , 
    0x00000000UL /*  FrTrcv_WakeupSourceRef  */ , 
    0x00U /*  FrTrcv_WakeupSupported  */ , 
    0x00U /*  FrTrcv_WakeupPolling  */ , 
    0x01U /*  FrTrcv_ChannelUsed  */ 
  }
};


CONST( FrTrcv_30_Tja1082_ChannelType, FRTRCV_30_TJA1082_CONST ) FrTrcv_30_Tja1082_Channel[FRTRCV_30_TJA1082_MAX_NUM_OF_BTR_BUSSES] =
{
  {
    DioConf_DioChannel_FrStb, 
    DioConf_DioChannel_FrErr
  }
};




#define FRTRCV_30_TJA1082_STOP_SEC_CONST_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/* END of Checksum exclude for
  - DrvTrans_Tja1082FrAsrPreCompileCRC */
    
