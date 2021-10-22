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
 *            Module: FrTp
 *           Program: MSR BAC 4.x (MSR_Bmw_SLP4)
 *          Customer: Nxtr Automotive Corporation
 *       Expiry Date: Not restricted
 *  Ordered Derivat.: Renesas RH850 P1M R7F701363EAFP
 *    License Scope : The usage is restricted to CBD1700369_D04
 *
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *              File: FrTp_Lcfg.c
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

#define TP_ISO10681_LCFG_SOURCE
#define FRTP_LCFG_SOURCE

#include "PduR_FrTp.h" /* for PduR symbolic name value defines and callback functions */
#include "FrIf.h" /* for FrIf symbolic name value defines */
#include "FrTp_Lcfg.h"
#include "FrTp_Common.h"
 
#include "Det.h"
 

/* -----------------------------------------------------------------------------
    &&&~ Linktime configuration definitions
 ----------------------------------------------------------------------------- */





#define FRTP_START_SEC_VAR_NOINIT_UNSPECIFIED
/* PRQA S 5087 1 */ /* MD_MSR_19.1 */
#include "MemMap.h"

/* Channel-administration data */
/* PRQA S 3408 1 */ /* MD_FrTp_3408 */
VAR(FrTp_RxStateType, FRTP_VAR_NOINIT) FrTp_RxState[28];
/* PRQA S 3408 1 */ /* MD_FrTp_3408 */
VAR(FrTp_TxStateType, FRTP_VAR_NOINIT) FrTp_TxState[14];


/* All other runtime data */
/* Connection- and FrIfTxPdu-administration data */
/* PRQA S 3408 2 */ /* MD_FrTp_3408 */
VAR(FrTp_ConnStateType, FRTP_VAR_NOINIT) FrTp_ConnState[28];
/* PRQA S 3408 2 */ /* MD_FrTp_3408 */
VAR(uint8, FRTP_VAR_NOINIT) FrTp_RxFrIfPending[1];
/* PRQA S 3408 2 */ /* MD_FrTp_3408 */
VAR(uint8, FRTP_VAR_NOINIT) FrTp_TxFrIfPending[1];
/* Admin data for transmission using the "Trigger-Transmit"-functionality */
/* PRQA S 3408 2 */ /* MD_FrTp_3408 */
 VAR(FrTp_DecoupPduAdminType, FRTP_VAR_NOINIT) FrTp_DecoupPduAdminData[1];

/* Admin data for Tx-Pdu-Pools */
/* PRQA S 3408 2 */ /* MD_FrTp_3408 */
VAR(FrTp_TxPduPoolDataType, FRTP_VAR_NOINIT) FrTp_PoolData[1];
/* Buffer to assemble FrTp-frames and parts of them */
VAR(uint32, FRTP_VAR_NOINIT) FrTp_FrIfTxBuf[8U];


#define FRTP_STOP_SEC_VAR_NOINIT_UNSPECIFIED
/* PRQA S 5087 1 */ /* MD_MSR_19.1 */
#include "MemMap.h"


#define FRTP_START_SEC_VAR_NOINIT_16BIT
/* PRQA S 5087 1 */ /* MD_MSR_19.1 */
#include "MemMap.h"

/* -----------------------------------------------------------------------------
    &&&~ FrTp_RxBuf_Ch
 ----------------------------------------------------------------------------- */

/* Channel-wise Rx-buffers */
/* PRQA S 0750 7 */ /* MD_MSR_18.4 */
/* PRQA S 3448 6 */ /* MD_FrTp_3448 */
typedef union
{
    VAR(uint32, FRTP_VAR_NOINIT) w32[63U];
    VAR(uint16, FRTP_VAR_NOINIT) w16[127U];
    VAR(uint8, FRTP_VAR_NOINIT)  b8[254U];
} FrTp_RxBuf_Channel0Type;
VAR(FrTp_RxBuf_Channel0Type, FRTP_VAR_NOINIT) FrTp_RxBuf_Channel0; /* PRQA S 3408, 0759 */ /* MD_FrTp_3408, MD_MSR_18.4 */
/* PRQA S 0750 7 */ /* MD_MSR_18.4 */
/* PRQA S 3448 6 */ /* MD_FrTp_3448 */
typedef union
{
    VAR(uint32, FRTP_VAR_NOINIT) w32[63U];
    VAR(uint16, FRTP_VAR_NOINIT) w16[127U];
    VAR(uint8, FRTP_VAR_NOINIT)  b8[254U];
} FrTp_RxBuf_Channel1Type;
VAR(FrTp_RxBuf_Channel1Type, FRTP_VAR_NOINIT) FrTp_RxBuf_Channel1; /* PRQA S 3408, 0759 */ /* MD_FrTp_3408, MD_MSR_18.4 */
/* PRQA S 0750 7 */ /* MD_MSR_18.4 */
/* PRQA S 3448 6 */ /* MD_FrTp_3448 */
typedef union
{
    VAR(uint32, FRTP_VAR_NOINIT) w32[63U];
    VAR(uint16, FRTP_VAR_NOINIT) w16[127U];
    VAR(uint8, FRTP_VAR_NOINIT)  b8[254U];
} FrTp_RxBuf_Channel2Type;
VAR(FrTp_RxBuf_Channel2Type, FRTP_VAR_NOINIT) FrTp_RxBuf_Channel2; /* PRQA S 3408, 0759 */ /* MD_FrTp_3408, MD_MSR_18.4 */
/* PRQA S 0750 7 */ /* MD_MSR_18.4 */
/* PRQA S 3448 6 */ /* MD_FrTp_3448 */
typedef union
{
    VAR(uint32, FRTP_VAR_NOINIT) w32[63U];
    VAR(uint16, FRTP_VAR_NOINIT) w16[127U];
    VAR(uint8, FRTP_VAR_NOINIT)  b8[254U];
} FrTp_RxBuf_Channel3Type;
VAR(FrTp_RxBuf_Channel3Type, FRTP_VAR_NOINIT) FrTp_RxBuf_Channel3; /* PRQA S 3408, 0759 */ /* MD_FrTp_3408, MD_MSR_18.4 */
/* PRQA S 0750 7 */ /* MD_MSR_18.4 */
/* PRQA S 3448 6 */ /* MD_FrTp_3448 */
typedef union
{
    VAR(uint32, FRTP_VAR_NOINIT) w32[63U];
    VAR(uint16, FRTP_VAR_NOINIT) w16[127U];
    VAR(uint8, FRTP_VAR_NOINIT)  b8[254U];
} FrTp_RxBuf_Channel4Type;
VAR(FrTp_RxBuf_Channel4Type, FRTP_VAR_NOINIT) FrTp_RxBuf_Channel4; /* PRQA S 3408, 0759 */ /* MD_FrTp_3408, MD_MSR_18.4 */
/* PRQA S 0750 7 */ /* MD_MSR_18.4 */
/* PRQA S 3448 6 */ /* MD_FrTp_3448 */
typedef union
{
    VAR(uint32, FRTP_VAR_NOINIT) w32[63U];
    VAR(uint16, FRTP_VAR_NOINIT) w16[127U];
    VAR(uint8, FRTP_VAR_NOINIT)  b8[254U];
} FrTp_RxBuf_Channel5Type;
VAR(FrTp_RxBuf_Channel5Type, FRTP_VAR_NOINIT) FrTp_RxBuf_Channel5; /* PRQA S 3408, 0759 */ /* MD_FrTp_3408, MD_MSR_18.4 */
/* PRQA S 0750 7 */ /* MD_MSR_18.4 */
/* PRQA S 3448 6 */ /* MD_FrTp_3448 */
typedef union
{
    VAR(uint32, FRTP_VAR_NOINIT) w32[63U];
    VAR(uint16, FRTP_VAR_NOINIT) w16[127U];
    VAR(uint8, FRTP_VAR_NOINIT)  b8[254U];
} FrTp_RxBuf_Channel6Type;
VAR(FrTp_RxBuf_Channel6Type, FRTP_VAR_NOINIT) FrTp_RxBuf_Channel6; /* PRQA S 3408, 0759 */ /* MD_FrTp_3408, MD_MSR_18.4 */
/* PRQA S 0750 7 */ /* MD_MSR_18.4 */
/* PRQA S 3448 6 */ /* MD_FrTp_3448 */
typedef union
{
    VAR(uint32, FRTP_VAR_NOINIT) w32[63U];
    VAR(uint16, FRTP_VAR_NOINIT) w16[127U];
    VAR(uint8, FRTP_VAR_NOINIT)  b8[254U];
} FrTp_RxBuf_Channel7Type;
VAR(FrTp_RxBuf_Channel7Type, FRTP_VAR_NOINIT) FrTp_RxBuf_Channel7; /* PRQA S 3408, 0759 */ /* MD_FrTp_3408, MD_MSR_18.4 */
/* PRQA S 0750 7 */ /* MD_MSR_18.4 */
/* PRQA S 3448 6 */ /* MD_FrTp_3448 */
typedef union
{
    VAR(uint32, FRTP_VAR_NOINIT) w32[63U];
    VAR(uint16, FRTP_VAR_NOINIT) w16[127U];
    VAR(uint8, FRTP_VAR_NOINIT)  b8[254U];
} FrTp_RxBuf_Channel8Type;
VAR(FrTp_RxBuf_Channel8Type, FRTP_VAR_NOINIT) FrTp_RxBuf_Channel8; /* PRQA S 3408, 0759 */ /* MD_FrTp_3408, MD_MSR_18.4 */
/* PRQA S 0750 7 */ /* MD_MSR_18.4 */
/* PRQA S 3448 6 */ /* MD_FrTp_3448 */
typedef union
{
    VAR(uint32, FRTP_VAR_NOINIT) w32[63U];
    VAR(uint16, FRTP_VAR_NOINIT) w16[127U];
    VAR(uint8, FRTP_VAR_NOINIT)  b8[254U];
} FrTp_RxBuf_Channel9Type;
VAR(FrTp_RxBuf_Channel9Type, FRTP_VAR_NOINIT) FrTp_RxBuf_Channel9; /* PRQA S 3408, 0759 */ /* MD_FrTp_3408, MD_MSR_18.4 */
/* PRQA S 0750 7 */ /* MD_MSR_18.4 */
/* PRQA S 3448 6 */ /* MD_FrTp_3448 */
typedef union
{
    VAR(uint32, FRTP_VAR_NOINIT) w32[63U];
    VAR(uint16, FRTP_VAR_NOINIT) w16[127U];
    VAR(uint8, FRTP_VAR_NOINIT)  b8[254U];
} FrTp_RxBuf_Channel10Type;
VAR(FrTp_RxBuf_Channel10Type, FRTP_VAR_NOINIT) FrTp_RxBuf_Channel10; /* PRQA S 3408, 0759 */ /* MD_FrTp_3408, MD_MSR_18.4 */
/* PRQA S 0750 7 */ /* MD_MSR_18.4 */
/* PRQA S 3448 6 */ /* MD_FrTp_3448 */
typedef union
{
    VAR(uint32, FRTP_VAR_NOINIT) w32[63U];
    VAR(uint16, FRTP_VAR_NOINIT) w16[127U];
    VAR(uint8, FRTP_VAR_NOINIT)  b8[254U];
} FrTp_RxBuf_Channel11Type;
VAR(FrTp_RxBuf_Channel11Type, FRTP_VAR_NOINIT) FrTp_RxBuf_Channel11; /* PRQA S 3408, 0759 */ /* MD_FrTp_3408, MD_MSR_18.4 */
/* PRQA S 0750 7 */ /* MD_MSR_18.4 */
/* PRQA S 3448 6 */ /* MD_FrTp_3448 */
typedef union
{
    VAR(uint32, FRTP_VAR_NOINIT) w32[63U];
    VAR(uint16, FRTP_VAR_NOINIT) w16[127U];
    VAR(uint8, FRTP_VAR_NOINIT)  b8[254U];
} FrTp_RxBuf_Channel12Type;
VAR(FrTp_RxBuf_Channel12Type, FRTP_VAR_NOINIT) FrTp_RxBuf_Channel12; /* PRQA S 3408, 0759 */ /* MD_FrTp_3408, MD_MSR_18.4 */
/* PRQA S 0750 7 */ /* MD_MSR_18.4 */
/* PRQA S 3448 6 */ /* MD_FrTp_3448 */
typedef union
{
    VAR(uint32, FRTP_VAR_NOINIT) w32[63U];
    VAR(uint16, FRTP_VAR_NOINIT) w16[127U];
    VAR(uint8, FRTP_VAR_NOINIT)  b8[254U];
} FrTp_RxBuf_Channel13Type;
VAR(FrTp_RxBuf_Channel13Type, FRTP_VAR_NOINIT) FrTp_RxBuf_Channel13; /* PRQA S 3408, 0759 */ /* MD_FrTp_3408, MD_MSR_18.4 */
/* PRQA S 0750 7 */ /* MD_MSR_18.4 */
/* PRQA S 3448 6 */ /* MD_FrTp_3448 */
typedef union
{
    VAR(uint32, FRTP_VAR_NOINIT) w32[63U];
    VAR(uint16, FRTP_VAR_NOINIT) w16[127U];
    VAR(uint8, FRTP_VAR_NOINIT)  b8[254U];
} FrTp_RxBuf_Channel14Type;
VAR(FrTp_RxBuf_Channel14Type, FRTP_VAR_NOINIT) FrTp_RxBuf_Channel14; /* PRQA S 3408, 0759 */ /* MD_FrTp_3408, MD_MSR_18.4 */
/* PRQA S 0750 7 */ /* MD_MSR_18.4 */
/* PRQA S 3448 6 */ /* MD_FrTp_3448 */
typedef union
{
    VAR(uint32, FRTP_VAR_NOINIT) w32[63U];
    VAR(uint16, FRTP_VAR_NOINIT) w16[127U];
    VAR(uint8, FRTP_VAR_NOINIT)  b8[254U];
} FrTp_RxBuf_Channel15Type;
VAR(FrTp_RxBuf_Channel15Type, FRTP_VAR_NOINIT) FrTp_RxBuf_Channel15; /* PRQA S 3408, 0759 */ /* MD_FrTp_3408, MD_MSR_18.4 */
/* PRQA S 0750 7 */ /* MD_MSR_18.4 */
/* PRQA S 3448 6 */ /* MD_FrTp_3448 */
typedef union
{
    VAR(uint32, FRTP_VAR_NOINIT) w32[63U];
    VAR(uint16, FRTP_VAR_NOINIT) w16[127U];
    VAR(uint8, FRTP_VAR_NOINIT)  b8[254U];
} FrTp_RxBuf_Channel16Type;
VAR(FrTp_RxBuf_Channel16Type, FRTP_VAR_NOINIT) FrTp_RxBuf_Channel16; /* PRQA S 3408, 0759 */ /* MD_FrTp_3408, MD_MSR_18.4 */
/* PRQA S 0750 7 */ /* MD_MSR_18.4 */
/* PRQA S 3448 6 */ /* MD_FrTp_3448 */
typedef union
{
    VAR(uint32, FRTP_VAR_NOINIT) w32[63U];
    VAR(uint16, FRTP_VAR_NOINIT) w16[127U];
    VAR(uint8, FRTP_VAR_NOINIT)  b8[254U];
} FrTp_RxBuf_Channel17Type;
VAR(FrTp_RxBuf_Channel17Type, FRTP_VAR_NOINIT) FrTp_RxBuf_Channel17; /* PRQA S 3408, 0759 */ /* MD_FrTp_3408, MD_MSR_18.4 */
/* PRQA S 0750 7 */ /* MD_MSR_18.4 */
/* PRQA S 3448 6 */ /* MD_FrTp_3448 */
typedef union
{
    VAR(uint32, FRTP_VAR_NOINIT) w32[63U];
    VAR(uint16, FRTP_VAR_NOINIT) w16[127U];
    VAR(uint8, FRTP_VAR_NOINIT)  b8[254U];
} FrTp_RxBuf_Channel18Type;
VAR(FrTp_RxBuf_Channel18Type, FRTP_VAR_NOINIT) FrTp_RxBuf_Channel18; /* PRQA S 3408, 0759 */ /* MD_FrTp_3408, MD_MSR_18.4 */
/* PRQA S 0750 7 */ /* MD_MSR_18.4 */
/* PRQA S 3448 6 */ /* MD_FrTp_3448 */
typedef union
{
    VAR(uint32, FRTP_VAR_NOINIT) w32[63U];
    VAR(uint16, FRTP_VAR_NOINIT) w16[127U];
    VAR(uint8, FRTP_VAR_NOINIT)  b8[254U];
} FrTp_RxBuf_Channel19Type;
VAR(FrTp_RxBuf_Channel19Type, FRTP_VAR_NOINIT) FrTp_RxBuf_Channel19; /* PRQA S 3408, 0759 */ /* MD_FrTp_3408, MD_MSR_18.4 */
/* PRQA S 0750 7 */ /* MD_MSR_18.4 */
/* PRQA S 3448 6 */ /* MD_FrTp_3448 */
typedef union
{
    VAR(uint32, FRTP_VAR_NOINIT) w32[63U];
    VAR(uint16, FRTP_VAR_NOINIT) w16[127U];
    VAR(uint8, FRTP_VAR_NOINIT)  b8[254U];
} FrTp_RxBuf_Channel20Type;
VAR(FrTp_RxBuf_Channel20Type, FRTP_VAR_NOINIT) FrTp_RxBuf_Channel20; /* PRQA S 3408, 0759 */ /* MD_FrTp_3408, MD_MSR_18.4 */
/* PRQA S 0750 7 */ /* MD_MSR_18.4 */
/* PRQA S 3448 6 */ /* MD_FrTp_3448 */
typedef union
{
    VAR(uint32, FRTP_VAR_NOINIT) w32[63U];
    VAR(uint16, FRTP_VAR_NOINIT) w16[127U];
    VAR(uint8, FRTP_VAR_NOINIT)  b8[254U];
} FrTp_RxBuf_Channel21Type;
VAR(FrTp_RxBuf_Channel21Type, FRTP_VAR_NOINIT) FrTp_RxBuf_Channel21; /* PRQA S 3408, 0759 */ /* MD_FrTp_3408, MD_MSR_18.4 */
/* PRQA S 0750 7 */ /* MD_MSR_18.4 */
/* PRQA S 3448 6 */ /* MD_FrTp_3448 */
typedef union
{
    VAR(uint32, FRTP_VAR_NOINIT) w32[63U];
    VAR(uint16, FRTP_VAR_NOINIT) w16[127U];
    VAR(uint8, FRTP_VAR_NOINIT)  b8[254U];
} FrTp_RxBuf_Channel22Type;
VAR(FrTp_RxBuf_Channel22Type, FRTP_VAR_NOINIT) FrTp_RxBuf_Channel22; /* PRQA S 3408, 0759 */ /* MD_FrTp_3408, MD_MSR_18.4 */
/* PRQA S 0750 7 */ /* MD_MSR_18.4 */
/* PRQA S 3448 6 */ /* MD_FrTp_3448 */
typedef union
{
    VAR(uint32, FRTP_VAR_NOINIT) w32[63U];
    VAR(uint16, FRTP_VAR_NOINIT) w16[127U];
    VAR(uint8, FRTP_VAR_NOINIT)  b8[254U];
} FrTp_RxBuf_Channel23Type;
VAR(FrTp_RxBuf_Channel23Type, FRTP_VAR_NOINIT) FrTp_RxBuf_Channel23; /* PRQA S 3408, 0759 */ /* MD_FrTp_3408, MD_MSR_18.4 */
/* PRQA S 0750 7 */ /* MD_MSR_18.4 */
/* PRQA S 3448 6 */ /* MD_FrTp_3448 */
typedef union
{
    VAR(uint32, FRTP_VAR_NOINIT) w32[63U];
    VAR(uint16, FRTP_VAR_NOINIT) w16[127U];
    VAR(uint8, FRTP_VAR_NOINIT)  b8[254U];
} FrTp_RxBuf_Channel24Type;
VAR(FrTp_RxBuf_Channel24Type, FRTP_VAR_NOINIT) FrTp_RxBuf_Channel24; /* PRQA S 3408, 0759 */ /* MD_FrTp_3408, MD_MSR_18.4 */
/* PRQA S 0750 7 */ /* MD_MSR_18.4 */
/* PRQA S 3448 6 */ /* MD_FrTp_3448 */
typedef union
{
    VAR(uint32, FRTP_VAR_NOINIT) w32[63U];
    VAR(uint16, FRTP_VAR_NOINIT) w16[127U];
    VAR(uint8, FRTP_VAR_NOINIT)  b8[254U];
} FrTp_RxBuf_Channel25Type;
VAR(FrTp_RxBuf_Channel25Type, FRTP_VAR_NOINIT) FrTp_RxBuf_Channel25; /* PRQA S 3408, 0759 */ /* MD_FrTp_3408, MD_MSR_18.4 */
/* PRQA S 0750 7 */ /* MD_MSR_18.4 */
/* PRQA S 3448 6 */ /* MD_FrTp_3448 */
typedef union
{
    VAR(uint32, FRTP_VAR_NOINIT) w32[63U];
    VAR(uint16, FRTP_VAR_NOINIT) w16[127U];
    VAR(uint8, FRTP_VAR_NOINIT)  b8[254U];
} FrTp_RxBuf_Channel26Type;
VAR(FrTp_RxBuf_Channel26Type, FRTP_VAR_NOINIT) FrTp_RxBuf_Channel26; /* PRQA S 3408, 0759 */ /* MD_FrTp_3408, MD_MSR_18.4 */
/* PRQA S 0750 7 */ /* MD_MSR_18.4 */
/* PRQA S 3448 6 */ /* MD_FrTp_3448 */
typedef union
{
    VAR(uint32, FRTP_VAR_NOINIT) w32[63U];
    VAR(uint16, FRTP_VAR_NOINIT) w16[127U];
    VAR(uint8, FRTP_VAR_NOINIT)  b8[254U];
} FrTp_RxBuf_Channel27Type;
VAR(FrTp_RxBuf_Channel27Type, FRTP_VAR_NOINIT) FrTp_RxBuf_Channel27; /* PRQA S 3408, 0759 */ /* MD_FrTp_3408, MD_MSR_18.4 */

/* -----------------------------------------------------------------------------
    &&&~ FrTp_TxBuf_Ch
 ----------------------------------------------------------------------------- */

/* Channel-wise Tx-buffers */
/* PRQA S 0750 7 */ /* MD_MSR_18.4 */
/* PRQA S 3448 6 */ /* MD_FrTp_3448 */
typedef union
{
  VAR(uint16, FRTP_VAR_NOINIT) w32[8U];
    VAR(uint16, FRTP_VAR_NOINIT) w16[16U];
    VAR(uint8, FRTP_VAR_NOINIT)  b8[32U];
} FrTp_TxBuf_Channel0Type;
VAR(FrTp_TxBuf_Channel0Type, FRTP_VAR_NOINIT) FrTp_TxBuf_Channel0; /* PRQA S 0759, 3408 */ /* MD_MSR_18.4, MD_FrTp_3408 */
/* PRQA S 0750 7 */ /* MD_MSR_18.4 */
/* PRQA S 3448 6 */ /* MD_FrTp_3448 */
typedef union
{
  VAR(uint16, FRTP_VAR_NOINIT) w32[8U];
    VAR(uint16, FRTP_VAR_NOINIT) w16[16U];
    VAR(uint8, FRTP_VAR_NOINIT)  b8[32U];
} FrTp_TxBuf_Channel1Type;
VAR(FrTp_TxBuf_Channel1Type, FRTP_VAR_NOINIT) FrTp_TxBuf_Channel1; /* PRQA S 0759, 3408 */ /* MD_MSR_18.4, MD_FrTp_3408 */
/* PRQA S 0750 7 */ /* MD_MSR_18.4 */
/* PRQA S 3448 6 */ /* MD_FrTp_3448 */
typedef union
{
  VAR(uint16, FRTP_VAR_NOINIT) w32[8U];
    VAR(uint16, FRTP_VAR_NOINIT) w16[16U];
    VAR(uint8, FRTP_VAR_NOINIT)  b8[32U];
} FrTp_TxBuf_Channel2Type;
VAR(FrTp_TxBuf_Channel2Type, FRTP_VAR_NOINIT) FrTp_TxBuf_Channel2; /* PRQA S 0759, 3408 */ /* MD_MSR_18.4, MD_FrTp_3408 */
/* PRQA S 0750 7 */ /* MD_MSR_18.4 */
/* PRQA S 3448 6 */ /* MD_FrTp_3448 */
typedef union
{
  VAR(uint16, FRTP_VAR_NOINIT) w32[8U];
    VAR(uint16, FRTP_VAR_NOINIT) w16[16U];
    VAR(uint8, FRTP_VAR_NOINIT)  b8[32U];
} FrTp_TxBuf_Channel3Type;
VAR(FrTp_TxBuf_Channel3Type, FRTP_VAR_NOINIT) FrTp_TxBuf_Channel3; /* PRQA S 0759, 3408 */ /* MD_MSR_18.4, MD_FrTp_3408 */
/* PRQA S 0750 7 */ /* MD_MSR_18.4 */
/* PRQA S 3448 6 */ /* MD_FrTp_3448 */
typedef union
{
  VAR(uint16, FRTP_VAR_NOINIT) w32[8U];
    VAR(uint16, FRTP_VAR_NOINIT) w16[16U];
    VAR(uint8, FRTP_VAR_NOINIT)  b8[32U];
} FrTp_TxBuf_Channel4Type;
VAR(FrTp_TxBuf_Channel4Type, FRTP_VAR_NOINIT) FrTp_TxBuf_Channel4; /* PRQA S 0759, 3408 */ /* MD_MSR_18.4, MD_FrTp_3408 */
/* PRQA S 0750 7 */ /* MD_MSR_18.4 */
/* PRQA S 3448 6 */ /* MD_FrTp_3448 */
typedef union
{
  VAR(uint16, FRTP_VAR_NOINIT) w32[8U];
    VAR(uint16, FRTP_VAR_NOINIT) w16[16U];
    VAR(uint8, FRTP_VAR_NOINIT)  b8[32U];
} FrTp_TxBuf_Channel5Type;
VAR(FrTp_TxBuf_Channel5Type, FRTP_VAR_NOINIT) FrTp_TxBuf_Channel5; /* PRQA S 0759, 3408 */ /* MD_MSR_18.4, MD_FrTp_3408 */
/* PRQA S 0750 7 */ /* MD_MSR_18.4 */
/* PRQA S 3448 6 */ /* MD_FrTp_3448 */
typedef union
{
  VAR(uint16, FRTP_VAR_NOINIT) w32[8U];
    VAR(uint16, FRTP_VAR_NOINIT) w16[16U];
    VAR(uint8, FRTP_VAR_NOINIT)  b8[32U];
} FrTp_TxBuf_Channel6Type;
VAR(FrTp_TxBuf_Channel6Type, FRTP_VAR_NOINIT) FrTp_TxBuf_Channel6; /* PRQA S 0759, 3408 */ /* MD_MSR_18.4, MD_FrTp_3408 */
/* PRQA S 0750 7 */ /* MD_MSR_18.4 */
/* PRQA S 3448 6 */ /* MD_FrTp_3448 */
typedef union
{
  VAR(uint16, FRTP_VAR_NOINIT) w32[8U];
    VAR(uint16, FRTP_VAR_NOINIT) w16[16U];
    VAR(uint8, FRTP_VAR_NOINIT)  b8[32U];
} FrTp_TxBuf_Channel7Type;
VAR(FrTp_TxBuf_Channel7Type, FRTP_VAR_NOINIT) FrTp_TxBuf_Channel7; /* PRQA S 0759, 3408 */ /* MD_MSR_18.4, MD_FrTp_3408 */
/* PRQA S 0750 7 */ /* MD_MSR_18.4 */
/* PRQA S 3448 6 */ /* MD_FrTp_3448 */
typedef union
{
  VAR(uint16, FRTP_VAR_NOINIT) w32[8U];
    VAR(uint16, FRTP_VAR_NOINIT) w16[16U];
    VAR(uint8, FRTP_VAR_NOINIT)  b8[32U];
} FrTp_TxBuf_Channel8Type;
VAR(FrTp_TxBuf_Channel8Type, FRTP_VAR_NOINIT) FrTp_TxBuf_Channel8; /* PRQA S 0759, 3408 */ /* MD_MSR_18.4, MD_FrTp_3408 */
/* PRQA S 0750 7 */ /* MD_MSR_18.4 */
/* PRQA S 3448 6 */ /* MD_FrTp_3448 */
typedef union
{
  VAR(uint16, FRTP_VAR_NOINIT) w32[8U];
    VAR(uint16, FRTP_VAR_NOINIT) w16[16U];
    VAR(uint8, FRTP_VAR_NOINIT)  b8[32U];
} FrTp_TxBuf_Channel9Type;
VAR(FrTp_TxBuf_Channel9Type, FRTP_VAR_NOINIT) FrTp_TxBuf_Channel9; /* PRQA S 0759, 3408 */ /* MD_MSR_18.4, MD_FrTp_3408 */
/* PRQA S 0750 7 */ /* MD_MSR_18.4 */
/* PRQA S 3448 6 */ /* MD_FrTp_3448 */
typedef union
{
  VAR(uint16, FRTP_VAR_NOINIT) w32[8U];
    VAR(uint16, FRTP_VAR_NOINIT) w16[16U];
    VAR(uint8, FRTP_VAR_NOINIT)  b8[32U];
} FrTp_TxBuf_Channel10Type;
VAR(FrTp_TxBuf_Channel10Type, FRTP_VAR_NOINIT) FrTp_TxBuf_Channel10; /* PRQA S 0759, 3408 */ /* MD_MSR_18.4, MD_FrTp_3408 */
/* PRQA S 0750 7 */ /* MD_MSR_18.4 */
/* PRQA S 3448 6 */ /* MD_FrTp_3448 */
typedef union
{
  VAR(uint16, FRTP_VAR_NOINIT) w32[8U];
    VAR(uint16, FRTP_VAR_NOINIT) w16[16U];
    VAR(uint8, FRTP_VAR_NOINIT)  b8[32U];
} FrTp_TxBuf_Channel11Type;
VAR(FrTp_TxBuf_Channel11Type, FRTP_VAR_NOINIT) FrTp_TxBuf_Channel11; /* PRQA S 0759, 3408 */ /* MD_MSR_18.4, MD_FrTp_3408 */
/* PRQA S 0750 7 */ /* MD_MSR_18.4 */
/* PRQA S 3448 6 */ /* MD_FrTp_3448 */
typedef union
{
  VAR(uint16, FRTP_VAR_NOINIT) w32[8U];
    VAR(uint16, FRTP_VAR_NOINIT) w16[16U];
    VAR(uint8, FRTP_VAR_NOINIT)  b8[32U];
} FrTp_TxBuf_Channel12Type;
VAR(FrTp_TxBuf_Channel12Type, FRTP_VAR_NOINIT) FrTp_TxBuf_Channel12; /* PRQA S 0759, 3408 */ /* MD_MSR_18.4, MD_FrTp_3408 */
/* PRQA S 0750 7 */ /* MD_MSR_18.4 */
/* PRQA S 3448 6 */ /* MD_FrTp_3448 */
typedef union
{
  VAR(uint16, FRTP_VAR_NOINIT) w32[8U];
    VAR(uint16, FRTP_VAR_NOINIT) w16[16U];
    VAR(uint8, FRTP_VAR_NOINIT)  b8[32U];
} FrTp_TxBuf_Channel13Type;
VAR(FrTp_TxBuf_Channel13Type, FRTP_VAR_NOINIT) FrTp_TxBuf_Channel13; /* PRQA S 0759, 3408 */ /* MD_MSR_18.4, MD_FrTp_3408 */


#define FRTP_STOP_SEC_VAR_NOINIT_16BIT
/* PRQA S 5087 1 */ /* MD_MSR_19.1 */
#include "MemMap.h"





#define FRTP_START_SEC_VAR_NOINIT_UNSPECIFIED
/* PRQA S 5087 1 */ /* MD_MSR_19.1 */
#include "MemMap.h"


/* All other runtime data */ /* PRQA S 3408 5 */ /* MD_FrTp_3408 */
VAR(uint8, FRTP_VAR_NOINIT) FrTp_RxCurrRoundRobChan; /*!< Counter variable to store the index of the rx-state-machine that is to be operated next during the round-robin-process. */
VAR(uint8, FRTP_VAR_NOINIT) FrTp_TxCurrRoundRobChan; /*!< Counter variable to store the index of the tx-state-machine that is to be operated next during the round-robin-process. */
VAR(uint16_least, FRTP_VAR_NOINIT) FrTp_RxSm_MaxIterations; /*!< Max. number of iterations in the round-robin-while-loop according to the number of rx-state-machines and tx-pdus used by these state-machines. */
VAR(uint16_least, FRTP_VAR_NOINIT) FrTp_TxSm_MaxIterations; /*!< Max. number of iterations in the round-robin-while-loop according to the number of tx-state-machines and tx-pdus used by these state-machines. */

#define FRTP_STOP_SEC_VAR_NOINIT_UNSPECIFIED
/* PRQA S 5087 1 */ /* MD_MSR_19.1 */
#include "MemMap.h"


#define FRTP_START_SEC_VAR_ZERO_INIT_8BIT
/* PRQA S 5087 1 */ /* MD_MSR_19.1 */
#include "MemMap.h"

/* Flag to check initialization */
/* PRQA S 3408 2 */ /* MD_FrTp_3408 */
VAR(uint8, FRTP_VAR_ZERO_INIT) FrTp_InitState = 0u; /*!< Flag to store the initialization state of the FrTp, during runtime. */


#define FRTP_STOP_SEC_VAR_ZERO_INIT_8BIT
/* PRQA S 5087 1 */ /* MD_MSR_19.1 */
#include "MemMap.h"

/* -----------------------------------------------------------------------------
    &&&~ Tp_Iso10681_PB_Config_Source_LinktimeConfig
 ----------------------------------------------------------------------------- */
 
 /* ----------------------------------------------------------------------------
     &&&~ Tp_Iso10681_Variant_Independent_Data
 ----------------------------------------------------------------------------- */
 

#define FRTP_START_SEC_CONST_UNSPECIFIED
/* PRQA S 5087 1 */ /* MD_MSR_19.1 */
#include "MemMap.h"

/* -----------------------------------------------------------------------------
    &&&~ FrTp_TxBuf
 ----------------------------------------------------------------------------- */

/* PRQA S 3408 4 */ /* MD_FrTp_3408 */
/* PRQA S 0310 DIFF_PTR_TYPE_CAST_FOR_TX_BUFFERS */ /* MD_FrTp_0310 */
CONSTP2VAR(uint8, FRTP_CONST, FRTP_VAR_NOINIT) FrTp_TxBuf[14] =  
{
  FrTp_TxBuf_Channel0.b8 /*  !< Pointer to buffer to store tx-pdus in, used for tx-state-machine No.: 0  */ , 
  FrTp_TxBuf_Channel1.b8 /*  !< Pointer to buffer to store tx-pdus in, used for tx-state-machine No.: 1  */ , 
  FrTp_TxBuf_Channel2.b8 /*  !< Pointer to buffer to store tx-pdus in, used for tx-state-machine No.: 2  */ , 
  FrTp_TxBuf_Channel3.b8 /*  !< Pointer to buffer to store tx-pdus in, used for tx-state-machine No.: 3  */ , 
  FrTp_TxBuf_Channel4.b8 /*  !< Pointer to buffer to store tx-pdus in, used for tx-state-machine No.: 4  */ , 
  FrTp_TxBuf_Channel5.b8 /*  !< Pointer to buffer to store tx-pdus in, used for tx-state-machine No.: 5  */ , 
  FrTp_TxBuf_Channel6.b8 /*  !< Pointer to buffer to store tx-pdus in, used for tx-state-machine No.: 6  */ , 
  FrTp_TxBuf_Channel7.b8 /*  !< Pointer to buffer to store tx-pdus in, used for tx-state-machine No.: 7  */ , 
  FrTp_TxBuf_Channel8.b8 /*  !< Pointer to buffer to store tx-pdus in, used for tx-state-machine No.: 8  */ , 
  FrTp_TxBuf_Channel9.b8 /*  !< Pointer to buffer to store tx-pdus in, used for tx-state-machine No.: 9  */ , 
  FrTp_TxBuf_Channel10.b8 /*  !< Pointer to buffer to store tx-pdus in, used for tx-state-machine No.: 10  */ , 
  FrTp_TxBuf_Channel11.b8 /*  !< Pointer to buffer to store tx-pdus in, used for tx-state-machine No.: 11  */ , 
  FrTp_TxBuf_Channel12.b8 /*  !< Pointer to buffer to store tx-pdus in, used for tx-state-machine No.: 12  */ , 
  FrTp_TxBuf_Channel13.b8 /*  !< Pointer to buffer to store tx-pdus in, used for tx-state-machine No.: 13  */ 
}; /*!< Array to access the state-machine-individual buffers by using the state-machines index-value. */
/* PRQA L:NO_CAST_FOR_TX_BUFFERS */
/* PRQA L:DIFF_PTR_TYPE_CAST_FOR_TX_BUFFERS */ 

/* -----------------------------------------------------------------------------
    &&&~ FrTp_RxBuf
 ----------------------------------------------------------------------------- */

/* PRQA S 3408 4 */ /* MD_FrTp_3408 */
/* PRQA S 0310 DIFF_PTR_TYPE_CAST_FOR_RX_BUFFERS */ /* MD_FrTp_0310 */
CONSTP2VAR(uint8, FRTP_CONST, FRTP_VAR_NOINIT) FrTp_RxBuf[28] = 
{
  FrTp_RxBuf_Channel0.b8 /*  !< Pointer to buffer to store rx-pdus in, used for rx-state-machine No.: 0  */ , 
  FrTp_RxBuf_Channel1.b8 /*  !< Pointer to buffer to store rx-pdus in, used for rx-state-machine No.: 1  */ , 
  FrTp_RxBuf_Channel2.b8 /*  !< Pointer to buffer to store rx-pdus in, used for rx-state-machine No.: 2  */ , 
  FrTp_RxBuf_Channel3.b8 /*  !< Pointer to buffer to store rx-pdus in, used for rx-state-machine No.: 3  */ , 
  FrTp_RxBuf_Channel4.b8 /*  !< Pointer to buffer to store rx-pdus in, used for rx-state-machine No.: 4  */ , 
  FrTp_RxBuf_Channel5.b8 /*  !< Pointer to buffer to store rx-pdus in, used for rx-state-machine No.: 5  */ , 
  FrTp_RxBuf_Channel6.b8 /*  !< Pointer to buffer to store rx-pdus in, used for rx-state-machine No.: 6  */ , 
  FrTp_RxBuf_Channel7.b8 /*  !< Pointer to buffer to store rx-pdus in, used for rx-state-machine No.: 7  */ , 
  FrTp_RxBuf_Channel8.b8 /*  !< Pointer to buffer to store rx-pdus in, used for rx-state-machine No.: 8  */ , 
  FrTp_RxBuf_Channel9.b8 /*  !< Pointer to buffer to store rx-pdus in, used for rx-state-machine No.: 9  */ , 
  FrTp_RxBuf_Channel10.b8 /*  !< Pointer to buffer to store rx-pdus in, used for rx-state-machine No.: 10  */ , 
  FrTp_RxBuf_Channel11.b8 /*  !< Pointer to buffer to store rx-pdus in, used for rx-state-machine No.: 11  */ , 
  FrTp_RxBuf_Channel12.b8 /*  !< Pointer to buffer to store rx-pdus in, used for rx-state-machine No.: 12  */ , 
  FrTp_RxBuf_Channel13.b8 /*  !< Pointer to buffer to store rx-pdus in, used for rx-state-machine No.: 13  */ , 
  FrTp_RxBuf_Channel14.b8 /*  !< Pointer to buffer to store rx-pdus in, used for rx-state-machine No.: 14  */ , 
  FrTp_RxBuf_Channel15.b8 /*  !< Pointer to buffer to store rx-pdus in, used for rx-state-machine No.: 15  */ , 
  FrTp_RxBuf_Channel16.b8 /*  !< Pointer to buffer to store rx-pdus in, used for rx-state-machine No.: 16  */ , 
  FrTp_RxBuf_Channel17.b8 /*  !< Pointer to buffer to store rx-pdus in, used for rx-state-machine No.: 17  */ , 
  FrTp_RxBuf_Channel18.b8 /*  !< Pointer to buffer to store rx-pdus in, used for rx-state-machine No.: 18  */ , 
  FrTp_RxBuf_Channel19.b8 /*  !< Pointer to buffer to store rx-pdus in, used for rx-state-machine No.: 19  */ , 
  FrTp_RxBuf_Channel20.b8 /*  !< Pointer to buffer to store rx-pdus in, used for rx-state-machine No.: 20  */ , 
  FrTp_RxBuf_Channel21.b8 /*  !< Pointer to buffer to store rx-pdus in, used for rx-state-machine No.: 21  */ , 
  FrTp_RxBuf_Channel22.b8 /*  !< Pointer to buffer to store rx-pdus in, used for rx-state-machine No.: 22  */ , 
  FrTp_RxBuf_Channel23.b8 /*  !< Pointer to buffer to store rx-pdus in, used for rx-state-machine No.: 23  */ , 
  FrTp_RxBuf_Channel24.b8 /*  !< Pointer to buffer to store rx-pdus in, used for rx-state-machine No.: 24  */ , 
  FrTp_RxBuf_Channel25.b8 /*  !< Pointer to buffer to store rx-pdus in, used for rx-state-machine No.: 25  */ , 
  FrTp_RxBuf_Channel26.b8 /*  !< Pointer to buffer to store rx-pdus in, used for rx-state-machine No.: 26  */ , 
  FrTp_RxBuf_Channel27.b8 /*  !< Pointer to buffer to store rx-pdus in, used for rx-state-machine No.: 27  */ 
}; /*!< Array to access the state-machine-individual buffers by using the state-machines index-value. */
/* PRQA L:NO_CAST_FOR_RX_BUFFERS */
/* PRQA L:DIFF_PTR_TYPE_CAST_FOR_RX_BUFFERS */ 

 /* ----------------------------------------------------------------------------
     &&&~ Tp_Iso10681_Variant_Dependent_Data
 ----------------------------------------------------------------------------- */


/* -----------------------------------------------------------------------------
    &&&~ FrTp_PoolsOfTxPdus
 ----------------------------------------------------------------------------- */
/* PRQA S 3408 2 */ /* MD_FrTp_3408 */
STATIC CONST(uint8, FRTP_CONST) FrTp_P2P_Pdu0_Variant0_FrTpTxPduTRNSM[1] = 
{
  0 /*  TxPduPool_TL_ECU_TRNSM_FR_32  */ 
}; /*!< Array of offsets of the TxPduPools containing the FrTpTxPdu: FrTpTxPduTRNSM (). */

/* -----------------------------------------------------------------------------
    &&&~ FrTp_FrIfTxPdus
 ----------------------------------------------------------------------------- */

/* PRQA S 3408, 0781 2 */ /* MD_FrTp_3408, MD_FrTp_0781 */
CONST(FrTp_TxPduInfoType, FRTP_CONST) FrTp_FrIfTxPdus[] = 
{
  {
    FrTp_P2P_Pdu0_Variant0_FrTpTxPduTRNSM /*  uint8* PoolOffsetsPtr  */ , 
    FrIfConf_FrIfTxPdu_FrIfTxPdu_TL_ECU_TRNSM_FR_32 /*  PduIdType FRTP_PDUID  */ , 
    0 /*  uint8 FrTp_DecoupPduAdminDataOffset  */ , 
    32 /*  uint8 Length  */ , 
    1 /*  uint8 NumPools  */ 
  } /*  FrTpTxPduTRNSM  */ 
}; /*!< Initializer list of the global, aggregated list of all FrTpTxPdus used by the FrTp. */

/* -----------------------------------------------------------------------------
    &&&~ FrTp_ConnsOfRxPdus
 ----------------------------------------------------------------------------- */
/* PRQA S 3408 2 */ /* MD_FrTp_3408 */
STATIC CONST(uint8, FRTP_CONST) FrTp_P2C_Pdu0_Variant0_FrTpRxPduTRNSM[14] = 
{
  0 /*  TL_MST_GW_TRNSM_FR_254_0xF0  */ , 
  1 /*  TL_MST_GW_TRNSM_FR_254_0xF1  */ , 
  2 /*  TL_MST_GW_TRNSM_FR_254_0xF2  */ , 
  3 /*  TL_MST_GW_TRNSM_FR_254_0xF3  */ , 
  4 /*  TL_MST_GW_TRNSM_FR_254_0xF4  */ , 
  5 /*  TL_MST_GW_TRNSM_FR_254_0xF5  */ , 
  6 /*  TL_MST_GW_TRNSM_FR_254_0xF6  */ , 
  7 /*  TL_MST_GW_TRNSM_FR_254_0xF7  */ , 
  8 /*  TL_MST_GW_TRNSM_FR_254_0xF8  */ , 
  9 /*  TL_MST_GW_TRNSM_FR_254_0xF9  */ , 
  10 /*  TL_MST_GW_TRNSM_FR_254_0xFA  */ , 
  11 /*  TL_MST_GW_TRNSM_FR_254_0xFB  */ , 
  12 /*  TL_MST_GW_TRNSM_FR_254_0xFC  */ , 
  13 /*  TL_MST_GW_TRNSM_FR_254_0xFD  */ 
}; /*!< Array of offsets of the FrTpConnections that reference FrTpRxPduPools that contain the FrTpRxPdu: FrTpRxPduTRNSM (). */
/* PRQA S 3408 2 */ /* MD_FrTp_3408 */
STATIC CONST(uint8, FRTP_CONST) FrTp_P2C_Pdu1_Variant0_FrTpRxPduBRC[14] = 
{
  14 /*  TL_BRC_FR_32_0xDF_0xF0  */ , 
  15 /*  TL_BRC_FR_32_0xDF_0xF1  */ , 
  16 /*  TL_BRC_FR_32_0xDF_0xF2  */ , 
  17 /*  TL_BRC_FR_32_0xDF_0xF3  */ , 
  18 /*  TL_BRC_FR_32_0xDF_0xF4  */ , 
  19 /*  TL_BRC_FR_32_0xDF_0xF5  */ , 
  20 /*  TL_BRC_FR_32_0xDF_0xF6  */ , 
  21 /*  TL_BRC_FR_32_0xDF_0xF7  */ , 
  22 /*  TL_BRC_FR_32_0xDF_0xF8  */ , 
  23 /*  TL_BRC_FR_32_0xDF_0xF9  */ , 
  24 /*  TL_BRC_FR_32_0xDF_0xFA  */ , 
  25 /*  TL_BRC_FR_32_0xDF_0xFB  */ , 
  26 /*  TL_BRC_FR_32_0xDF_0xFC  */ , 
  27 /*  TL_BRC_FR_32_0xDF_0xFD  */ 
}; /*!< Array of offsets of the FrTpConnections that reference FrTpRxPduPools that contain the FrTpRxPdu: FrTpRxPduBRC (). */

/* -----------------------------------------------------------------------------
    &&&~ FrTp_FrIfRxPdus
 ----------------------------------------------------------------------------- */

/* PRQA S 3408, 0781 2 */ /* MD_FrTp_3408, MD_FrTp_0781 */
CONST(FrTp_RxPduInfoType, FRTP_CONST) FrTp_FrIfRxPdus[] = 
{
  {
    FrTp_P2C_Pdu0_Variant0_FrTpRxPduTRNSM /*  uint8* ConnOffsetsPtr  */ , 
    14 /*  uint8 NumConns  */ , 
    254 /*  uint8 Length  */ 
  } /*  FrTpRxPduTRNSM  */ , 
  {
    FrTp_P2C_Pdu1_Variant0_FrTpRxPduBRC /*  uint8* ConnOffsetsPtr  */ , 
    14 /*  uint8 NumConns  */ , 
    32 /*  uint8 Length  */ 
  } /*  FrTpRxPduBRC  */ 
}; /*!< Initializer list of the global, aggregated list of all FrTpRxPdus used by the FrTp. */

/* -----------------------------------------------------------------------------
    &&&~ FrTp_RxPduPools
 ----------------------------------------------------------------------------- */

/* PRQA S 3408, 0781 2 */ /* MD_FrTp_3408, MD_FrTp_0781 */ 
CONST(FrTp_RxPduPoolType, FRTP_CONST) FrTp_RxPduPools[2] = 
{
  {
    254 /*  uint8 MinPduLen  */ 
   /*  RxPduPool_GW_TRNSM_FR_254  */ }, 
  {
    32 /*  uint8 MinPduLen  */ 
   /*  RxPduPool_TL_BRC_FR_32  */ }
}; /*!< Initializer list of all configured FrTpRxPduPools. */

/* -----------------------------------------------------------------------------
    &&&~ FrTp_TxPduPoolOffsets
 ----------------------------------------------------------------------------- */
/* PRQA S 3408 2 */ /* MD_FrTp_3408  */ /* Array of offsets of the TxPdus of pool TxPduPool_TL_ECU_TRNSM_FR_32 () */
STATIC CONST(uint8, FRTP_CONST)TxPduPool_TL_ECU_TRNSM_FR_32[]=
{
  0 /*  FrTpTxPduTRNSM (FrTpTxPduTRNSM)  */ 
}; /*!< Offsets in the global list of FrTpTxPdus for each configured FrTpTxPduPool. */

/* -----------------------------------------------------------------------------
    &&&~ FrTp_TxPduPools
 ----------------------------------------------------------------------------- */

/* PRQA S 3408, 0781 2 */ /* MD_FrTp_3408, MD_FrTp_0781 */
CONST(FrTp_TxPduPoolType, FRTP_CONST) FrTp_TxPduPools[1] = 
{
  {
    TxPduPool_TL_ECU_TRNSM_FR_32 /*   uint8* PduOffsetsPtr  */ , 
    1 /*  uint8 NumPdus  */ , 
    32 /*  uint8 MinPduLen  */ 
   /*  TxPduPool_TL_ECU_TRNSM_FR_32  */ }
}; /*!< Initializer list of all configured FrTpTxPduPools. */

/* -----------------------------------------------------------------------------
    &&&~ FrTp_RxPduSnv2RxPduIdx
 ----------------------------------------------------------------------------- */
 /* PRQA S 3408, 0781 2 */ /* MD_FrTp_3408, MD_FrTp_0781 */
CONST(PduIdType, FRTP_CONST) FrTp_RxPduSnv2RxPduIdx[2] =
{
  1U /*  FrTpRxPduBRC (0U), FrTpRxPduBRC  */ , 
  0U /*  FrTpRxPduTRNSM (1U), FrTpRxPduTRNSM  */ 
}; /*!< Map from the SNV of a FrTpRxPdu to the internal idx. of that FrTpRxPdu. */

/* -----------------------------------------------------------------------------
    &&&~ FrTp_TxPduSnv2TxPduIdx
 ----------------------------------------------------------------------------- */
 /* PRQA S 3408, 0781 2 */ /* MD_FrTp_3408, MD_FrTp_0781 */
CONST(PduIdType, FRTP_CONST) FrTp_TxPduSnv2TxPduIdx[1] =
{
  0U /*  FrTpTxPduTRNSM (0U), FrTpTxPduTRNSM  */ 
}; /*!< Map from the SNV of a FrTpTxPdu to the internal idx. of that FrTpTxPdu. */

/* -----------------------------------------------------------------------------
    &&&~ FrTp_RxSduSnv2ConnIdx
 ----------------------------------------------------------------------------- */
 /* PRQA S 3408, 0781 2 */ /* MD_FrTp_3408, MD_FrTp_0781 */
CONST(PduIdType, FRTP_CONST) FrTp_RxSduSnv2ConnIdx[28] =
{
  14U /*  TL_BRC_FR_32_0xDF_0xF0 (0U), TL_BRC_FR_32_0xDF_0xF0  */ , 
  15U /*  TL_BRC_FR_32_0xDF_0xF1 (1U), TL_BRC_FR_32_0xDF_0xF1  */ , 
  16U /*  TL_BRC_FR_32_0xDF_0xF2 (2U), TL_BRC_FR_32_0xDF_0xF2  */ , 
  17U /*  TL_BRC_FR_32_0xDF_0xF3 (3U), TL_BRC_FR_32_0xDF_0xF3  */ , 
  18U /*  TL_BRC_FR_32_0xDF_0xF4 (4U), TL_BRC_FR_32_0xDF_0xF4  */ , 
  19U /*  TL_BRC_FR_32_0xDF_0xF5 (5U), TL_BRC_FR_32_0xDF_0xF5  */ , 
  20U /*  TL_BRC_FR_32_0xDF_0xF6 (6U), TL_BRC_FR_32_0xDF_0xF6  */ , 
  21U /*  TL_BRC_FR_32_0xDF_0xF7 (7U), TL_BRC_FR_32_0xDF_0xF7  */ , 
  22U /*  TL_BRC_FR_32_0xDF_0xF8 (8U), TL_BRC_FR_32_0xDF_0xF8  */ , 
  23U /*  TL_BRC_FR_32_0xDF_0xF9 (9U), TL_BRC_FR_32_0xDF_0xF9  */ , 
  24U /*  TL_BRC_FR_32_0xDF_0xFA (10U), TL_BRC_FR_32_0xDF_0xFA  */ , 
  25U /*  TL_BRC_FR_32_0xDF_0xFB (11U), TL_BRC_FR_32_0xDF_0xFB  */ , 
  26U /*  TL_BRC_FR_32_0xDF_0xFC (12U), TL_BRC_FR_32_0xDF_0xFC  */ , 
  27U /*  TL_BRC_FR_32_0xDF_0xFD (13U), TL_BRC_FR_32_0xDF_0xFD  */ , 
  0U /*  TL_MST_GW_TRNSM_FR_254_0xF0 (14U), TL_MST_GW_TRNSM_FR_254_0xF0  */ , 
  1U /*  TL_MST_GW_TRNSM_FR_254_0xF1 (15U), TL_MST_GW_TRNSM_FR_254_0xF1  */ , 
  2U /*  TL_MST_GW_TRNSM_FR_254_0xF2 (16U), TL_MST_GW_TRNSM_FR_254_0xF2  */ , 
  3U /*  TL_MST_GW_TRNSM_FR_254_0xF3 (17U), TL_MST_GW_TRNSM_FR_254_0xF3  */ , 
  4U /*  TL_MST_GW_TRNSM_FR_254_0xF4 (18U), TL_MST_GW_TRNSM_FR_254_0xF4  */ , 
  5U /*  TL_MST_GW_TRNSM_FR_254_0xF5 (19U), TL_MST_GW_TRNSM_FR_254_0xF5  */ , 
  6U /*  TL_MST_GW_TRNSM_FR_254_0xF6 (20U), TL_MST_GW_TRNSM_FR_254_0xF6  */ , 
  7U /*  TL_MST_GW_TRNSM_FR_254_0xF7 (21U), TL_MST_GW_TRNSM_FR_254_0xF7  */ , 
  8U /*  TL_MST_GW_TRNSM_FR_254_0xF8 (22U), TL_MST_GW_TRNSM_FR_254_0xF8  */ , 
  9U /*  TL_MST_GW_TRNSM_FR_254_0xF9 (23U), TL_MST_GW_TRNSM_FR_254_0xF9  */ , 
  10U /*  TL_MST_GW_TRNSM_FR_254_0xFA (24U), TL_MST_GW_TRNSM_FR_254_0xFA  */ , 
  11U /*  TL_MST_GW_TRNSM_FR_254_0xFB (25U), TL_MST_GW_TRNSM_FR_254_0xFB  */ , 
  12U /*  TL_MST_GW_TRNSM_FR_254_0xFC (26U), TL_MST_GW_TRNSM_FR_254_0xFC  */ , 
  13U /*  TL_MST_GW_TRNSM_FR_254_0xFD (27U), TL_MST_GW_TRNSM_FR_254_0xFD  */ 
}; /*!< Map from the SNV of a FrTpRxSdu to the internal idx. of the related FrTpConnection. */

/* -----------------------------------------------------------------------------
    &&&~ FrTp_TxSduSnv2ConnIdx
 ----------------------------------------------------------------------------- */
 /* PRQA S 3408, 0781 2 */ /* MD_FrTp_3408, MD_FrTp_0781 */
CONST(PduIdType, FRTP_CONST) FrTp_TxSduSnv2ConnIdx[14] =
{
  0U /*  TL_MST_GW_TRNSM_FR_254_0xF0 (0U), TL_MST_GW_TRNSM_FR_254_0xF0  */ , 
  1U /*  TL_MST_GW_TRNSM_FR_254_0xF1 (1U), TL_MST_GW_TRNSM_FR_254_0xF1  */ , 
  2U /*  TL_MST_GW_TRNSM_FR_254_0xF2 (2U), TL_MST_GW_TRNSM_FR_254_0xF2  */ , 
  3U /*  TL_MST_GW_TRNSM_FR_254_0xF3 (3U), TL_MST_GW_TRNSM_FR_254_0xF3  */ , 
  4U /*  TL_MST_GW_TRNSM_FR_254_0xF4 (4U), TL_MST_GW_TRNSM_FR_254_0xF4  */ , 
  5U /*  TL_MST_GW_TRNSM_FR_254_0xF5 (5U), TL_MST_GW_TRNSM_FR_254_0xF5  */ , 
  6U /*  TL_MST_GW_TRNSM_FR_254_0xF6 (6U), TL_MST_GW_TRNSM_FR_254_0xF6  */ , 
  7U /*  TL_MST_GW_TRNSM_FR_254_0xF7 (7U), TL_MST_GW_TRNSM_FR_254_0xF7  */ , 
  8U /*  TL_MST_GW_TRNSM_FR_254_0xF8 (8U), TL_MST_GW_TRNSM_FR_254_0xF8  */ , 
  9U /*  TL_MST_GW_TRNSM_FR_254_0xF9 (9U), TL_MST_GW_TRNSM_FR_254_0xF9  */ , 
  10U /*  TL_MST_GW_TRNSM_FR_254_0xFA (10U), TL_MST_GW_TRNSM_FR_254_0xFA  */ , 
  11U /*  TL_MST_GW_TRNSM_FR_254_0xFB (11U), TL_MST_GW_TRNSM_FR_254_0xFB  */ , 
  12U /*  TL_MST_GW_TRNSM_FR_254_0xFC (12U), TL_MST_GW_TRNSM_FR_254_0xFC  */ , 
  13U /*  TL_MST_GW_TRNSM_FR_254_0xFD (13U), TL_MST_GW_TRNSM_FR_254_0xFD  */ 
}; /*!< Map from the SNV of a FrTpTxSdu to the internal idx. of the related FrTpConnection. */

 
/* -----------------------------------------------------------------------------
    &&&~ FrTp_ConnCtrl
 ----------------------------------------------------------------------------- */

/* PRQA S 3408 2 */ /* MD_FrTp_3408 */
/* PRQA S 3408 2 */ /* MD_FrTp_3408 */
STATIC CONST(FrTp_ConnCtrlType, FRTP_CONST) FrTpConnectionControl =
{
  30U /*  TimeoutAs  */ , 
  30U /*  TimeoutAr  */ , 
  100U /*  TimeoutBs  */ , 
  120U /*  TimeoutCr  */ , 
  10U /*  TimeBr  */ , 
  10U /*  TimeCs  */ , 
  0 /*  MaxBfs  */ , 
  19 /*  MaxWft  */ , 
  0 /*  BandwidthCtrl  */ 
}; /*!< Initializer list of all FrTpConnection controls (i.e. parameter-sets) used by the FrTp. */
 

/* -----------------------------------------------------------------------------
    &&&~ FrTp_ConnCfg
 ----------------------------------------------------------------------------- */

/* PRQA S 3408, 0781 2 */ /* MD_FrTp_3408, MD_FrTp_0781 */
CONST(FrTp_ConnCfgType, FRTP_CONST) FrTp_ConnCfg[] = 
{
  {
    &FrTpConnectionControl /*  FrTp_ConnCtrlType* ConnCtrlPtr  */ , 
    0x0030U /*  uint16 LocalAddress = 48U  */ , 
    0x00F0U /*  uint16 RemoteAddress = 240U  */ , 
    0 /*  PduIdType ConnIdx   */ , 
    PduRConf_PduRSrcPdu_SRC_Dcm_GW_TRNSM_FR_254_0xF0 /*  uint8 FrTpSduRxId (Referenced by SRC_Dcm_GW_TRNSM_FR_254_0xF0)  */ , 
    PduRConf_PduRDestPdu_DST_Dcm_ECU_TRNSM_FR_32_0xF0 /*  uint8 FrTpSduTxId (Referenced by DST_Dcm_ECU_TRNSM_FR_32_0xF0)  */ , 
    0U /*  uint8 RxPduPoolOffset to pool: RxPduPool_GW_TRNSM_FR_254  */ , 
    0U /*  uint8 TxPduPoolOffset to pool: TxPduPool_TL_ECU_TRNSM_FR_32  */ , 
    0U /*  uint8 MultRec   */ , 
    0U /*  uint8 FrTpBandwidthLimitation   */ 
  } /*  TL_MST_GW_TRNSM_FR_254_0xF0  */ , 
  {
    &FrTpConnectionControl /*  FrTp_ConnCtrlType* ConnCtrlPtr  */ , 
    0x0030U /*  uint16 LocalAddress = 48U  */ , 
    0x00F1U /*  uint16 RemoteAddress = 241U  */ , 
    1 /*  PduIdType ConnIdx   */ , 
    PduRConf_PduRSrcPdu_SRC_Dcm_GW_TRNSM_FR_254_0xF1 /*  uint8 FrTpSduRxId (Referenced by SRC_Dcm_GW_TRNSM_FR_254_0xF1)  */ , 
    PduRConf_PduRDestPdu_DST_Dcm_ECU_TRNSM_FR_32_0xF1 /*  uint8 FrTpSduTxId (Referenced by DST_Dcm_ECU_TRNSM_FR_32_0xF1)  */ , 
    0U /*  uint8 RxPduPoolOffset to pool: RxPduPool_GW_TRNSM_FR_254  */ , 
    0U /*  uint8 TxPduPoolOffset to pool: TxPduPool_TL_ECU_TRNSM_FR_32  */ , 
    0U /*  uint8 MultRec   */ , 
    0U /*  uint8 FrTpBandwidthLimitation   */ 
  } /*  TL_MST_GW_TRNSM_FR_254_0xF1  */ , 
  {
    &FrTpConnectionControl /*  FrTp_ConnCtrlType* ConnCtrlPtr  */ , 
    0x0030U /*  uint16 LocalAddress = 48U  */ , 
    0x00F2U /*  uint16 RemoteAddress = 242U  */ , 
    2 /*  PduIdType ConnIdx   */ , 
    PduRConf_PduRSrcPdu_SRC_Dcm_GW_TRNSM_FR_254_0xF2 /*  uint8 FrTpSduRxId (Referenced by SRC_Dcm_GW_TRNSM_FR_254_0xF2)  */ , 
    PduRConf_PduRDestPdu_DST_Dcm_ECU_TRNSM_FR_32_0xF2 /*  uint8 FrTpSduTxId (Referenced by DST_Dcm_ECU_TRNSM_FR_32_0xF2)  */ , 
    0U /*  uint8 RxPduPoolOffset to pool: RxPduPool_GW_TRNSM_FR_254  */ , 
    0U /*  uint8 TxPduPoolOffset to pool: TxPduPool_TL_ECU_TRNSM_FR_32  */ , 
    0U /*  uint8 MultRec   */ , 
    0U /*  uint8 FrTpBandwidthLimitation   */ 
  } /*  TL_MST_GW_TRNSM_FR_254_0xF2  */ , 
  {
    &FrTpConnectionControl /*  FrTp_ConnCtrlType* ConnCtrlPtr  */ , 
    0x0030U /*  uint16 LocalAddress = 48U  */ , 
    0x00F3U /*  uint16 RemoteAddress = 243U  */ , 
    3 /*  PduIdType ConnIdx   */ , 
    PduRConf_PduRSrcPdu_SRC_Dcm_GW_TRNSM_FR_254_0xF3 /*  uint8 FrTpSduRxId (Referenced by SRC_Dcm_GW_TRNSM_FR_254_0xF3)  */ , 
    PduRConf_PduRDestPdu_DST_Dcm_ECU_TRNSM_FR_32_0xF3 /*  uint8 FrTpSduTxId (Referenced by DST_Dcm_ECU_TRNSM_FR_32_0xF3)  */ , 
    0U /*  uint8 RxPduPoolOffset to pool: RxPduPool_GW_TRNSM_FR_254  */ , 
    0U /*  uint8 TxPduPoolOffset to pool: TxPduPool_TL_ECU_TRNSM_FR_32  */ , 
    0U /*  uint8 MultRec   */ , 
    0U /*  uint8 FrTpBandwidthLimitation   */ 
  } /*  TL_MST_GW_TRNSM_FR_254_0xF3  */ , 
  {
    &FrTpConnectionControl /*  FrTp_ConnCtrlType* ConnCtrlPtr  */ , 
    0x0030U /*  uint16 LocalAddress = 48U  */ , 
    0x00F4U /*  uint16 RemoteAddress = 244U  */ , 
    4 /*  PduIdType ConnIdx   */ , 
    PduRConf_PduRSrcPdu_SRC_Dcm_GW_TRNSM_FR_254_0xF4 /*  uint8 FrTpSduRxId (Referenced by SRC_Dcm_GW_TRNSM_FR_254_0xF4)  */ , 
    PduRConf_PduRDestPdu_DST_Dcm_ECU_TRNSM_FR_32_0xF4 /*  uint8 FrTpSduTxId (Referenced by DST_Dcm_ECU_TRNSM_FR_32_0xF4)  */ , 
    0U /*  uint8 RxPduPoolOffset to pool: RxPduPool_GW_TRNSM_FR_254  */ , 
    0U /*  uint8 TxPduPoolOffset to pool: TxPduPool_TL_ECU_TRNSM_FR_32  */ , 
    0U /*  uint8 MultRec   */ , 
    0U /*  uint8 FrTpBandwidthLimitation   */ 
  } /*  TL_MST_GW_TRNSM_FR_254_0xF4  */ , 
  {
    &FrTpConnectionControl /*  FrTp_ConnCtrlType* ConnCtrlPtr  */ , 
    0x0030U /*  uint16 LocalAddress = 48U  */ , 
    0x00F5U /*  uint16 RemoteAddress = 245U  */ , 
    5 /*  PduIdType ConnIdx   */ , 
    PduRConf_PduRSrcPdu_SRC_Dcm_GW_TRNSM_FR_254_0xF5 /*  uint8 FrTpSduRxId (Referenced by SRC_Dcm_GW_TRNSM_FR_254_0xF5)  */ , 
    PduRConf_PduRDestPdu_DST_Dcm_ECU_TRNSM_FR_32_0xF5 /*  uint8 FrTpSduTxId (Referenced by DST_Dcm_ECU_TRNSM_FR_32_0xF5)  */ , 
    0U /*  uint8 RxPduPoolOffset to pool: RxPduPool_GW_TRNSM_FR_254  */ , 
    0U /*  uint8 TxPduPoolOffset to pool: TxPduPool_TL_ECU_TRNSM_FR_32  */ , 
    0U /*  uint8 MultRec   */ , 
    0U /*  uint8 FrTpBandwidthLimitation   */ 
  } /*  TL_MST_GW_TRNSM_FR_254_0xF5  */ , 
  {
    &FrTpConnectionControl /*  FrTp_ConnCtrlType* ConnCtrlPtr  */ , 
    0x0030U /*  uint16 LocalAddress = 48U  */ , 
    0x00F6U /*  uint16 RemoteAddress = 246U  */ , 
    6 /*  PduIdType ConnIdx   */ , 
    PduRConf_PduRSrcPdu_SRC_Dcm_GW_TRNSM_FR_254_0xF6 /*  uint8 FrTpSduRxId (Referenced by SRC_Dcm_GW_TRNSM_FR_254_0xF6)  */ , 
    PduRConf_PduRDestPdu_DST_Dcm_ECU_TRNSM_FR_32_0xF6 /*  uint8 FrTpSduTxId (Referenced by DST_Dcm_ECU_TRNSM_FR_32_0xF6)  */ , 
    0U /*  uint8 RxPduPoolOffset to pool: RxPduPool_GW_TRNSM_FR_254  */ , 
    0U /*  uint8 TxPduPoolOffset to pool: TxPduPool_TL_ECU_TRNSM_FR_32  */ , 
    0U /*  uint8 MultRec   */ , 
    0U /*  uint8 FrTpBandwidthLimitation   */ 
  } /*  TL_MST_GW_TRNSM_FR_254_0xF6  */ , 
  {
    &FrTpConnectionControl /*  FrTp_ConnCtrlType* ConnCtrlPtr  */ , 
    0x0030U /*  uint16 LocalAddress = 48U  */ , 
    0x00F7U /*  uint16 RemoteAddress = 247U  */ , 
    7 /*  PduIdType ConnIdx   */ , 
    PduRConf_PduRSrcPdu_SRC_Dcm_GW_TRNSM_FR_254_0xF7 /*  uint8 FrTpSduRxId (Referenced by SRC_Dcm_GW_TRNSM_FR_254_0xF7)  */ , 
    PduRConf_PduRDestPdu_DST_Dcm_ECU_TRNSM_FR_32_0xF7 /*  uint8 FrTpSduTxId (Referenced by DST_Dcm_ECU_TRNSM_FR_32_0xF7)  */ , 
    0U /*  uint8 RxPduPoolOffset to pool: RxPduPool_GW_TRNSM_FR_254  */ , 
    0U /*  uint8 TxPduPoolOffset to pool: TxPduPool_TL_ECU_TRNSM_FR_32  */ , 
    0U /*  uint8 MultRec   */ , 
    0U /*  uint8 FrTpBandwidthLimitation   */ 
  } /*  TL_MST_GW_TRNSM_FR_254_0xF7  */ , 
  {
    &FrTpConnectionControl /*  FrTp_ConnCtrlType* ConnCtrlPtr  */ , 
    0x0030U /*  uint16 LocalAddress = 48U  */ , 
    0x00F8U /*  uint16 RemoteAddress = 248U  */ , 
    8 /*  PduIdType ConnIdx   */ , 
    PduRConf_PduRSrcPdu_SRC_Dcm_GW_TRNSM_FR_254_0xF8 /*  uint8 FrTpSduRxId (Referenced by SRC_Dcm_GW_TRNSM_FR_254_0xF8)  */ , 
    PduRConf_PduRDestPdu_DST_Dcm_ECU_TRNSM_FR_32_0xF8 /*  uint8 FrTpSduTxId (Referenced by DST_Dcm_ECU_TRNSM_FR_32_0xF8)  */ , 
    0U /*  uint8 RxPduPoolOffset to pool: RxPduPool_GW_TRNSM_FR_254  */ , 
    0U /*  uint8 TxPduPoolOffset to pool: TxPduPool_TL_ECU_TRNSM_FR_32  */ , 
    0U /*  uint8 MultRec   */ , 
    0U /*  uint8 FrTpBandwidthLimitation   */ 
  } /*  TL_MST_GW_TRNSM_FR_254_0xF8  */ , 
  {
    &FrTpConnectionControl /*  FrTp_ConnCtrlType* ConnCtrlPtr  */ , 
    0x0030U /*  uint16 LocalAddress = 48U  */ , 
    0x00F9U /*  uint16 RemoteAddress = 249U  */ , 
    9 /*  PduIdType ConnIdx   */ , 
    PduRConf_PduRSrcPdu_SRC_Dcm_GW_TRNSM_FR_254_0xF9 /*  uint8 FrTpSduRxId (Referenced by SRC_Dcm_GW_TRNSM_FR_254_0xF9)  */ , 
    PduRConf_PduRDestPdu_DST_Dcm_ECU_TRNSM_FR_32_0xF9 /*  uint8 FrTpSduTxId (Referenced by DST_Dcm_ECU_TRNSM_FR_32_0xF9)  */ , 
    0U /*  uint8 RxPduPoolOffset to pool: RxPduPool_GW_TRNSM_FR_254  */ , 
    0U /*  uint8 TxPduPoolOffset to pool: TxPduPool_TL_ECU_TRNSM_FR_32  */ , 
    0U /*  uint8 MultRec   */ , 
    0U /*  uint8 FrTpBandwidthLimitation   */ 
  } /*  TL_MST_GW_TRNSM_FR_254_0xF9  */ , 
  {
    &FrTpConnectionControl /*  FrTp_ConnCtrlType* ConnCtrlPtr  */ , 
    0x0030U /*  uint16 LocalAddress = 48U  */ , 
    0x00FAU /*  uint16 RemoteAddress = 250U  */ , 
    10 /*  PduIdType ConnIdx   */ , 
    PduRConf_PduRSrcPdu_SRC_Dcm_GW_TRNSM_FR_254_0xFA /*  uint8 FrTpSduRxId (Referenced by SRC_Dcm_GW_TRNSM_FR_254_0xFA)  */ , 
    PduRConf_PduRDestPdu_DST_Dcm_ECU_TRNSM_FR_32_0xFA /*  uint8 FrTpSduTxId (Referenced by DST_Dcm_ECU_TRNSM_FR_32_0xFA)  */ , 
    0U /*  uint8 RxPduPoolOffset to pool: RxPduPool_GW_TRNSM_FR_254  */ , 
    0U /*  uint8 TxPduPoolOffset to pool: TxPduPool_TL_ECU_TRNSM_FR_32  */ , 
    0U /*  uint8 MultRec   */ , 
    0U /*  uint8 FrTpBandwidthLimitation   */ 
  } /*  TL_MST_GW_TRNSM_FR_254_0xFA  */ , 
  {
    &FrTpConnectionControl /*  FrTp_ConnCtrlType* ConnCtrlPtr  */ , 
    0x0030U /*  uint16 LocalAddress = 48U  */ , 
    0x00FBU /*  uint16 RemoteAddress = 251U  */ , 
    11 /*  PduIdType ConnIdx   */ , 
    PduRConf_PduRSrcPdu_SRC_Dcm_GW_TRNSM_FR_254_0xFB /*  uint8 FrTpSduRxId (Referenced by SRC_Dcm_GW_TRNSM_FR_254_0xFB)  */ , 
    PduRConf_PduRDestPdu_DST_Dcm_ECU_TRNSM_FR_32_0xFB /*  uint8 FrTpSduTxId (Referenced by DST_Dcm_ECU_TRNSM_FR_32_0xFB)  */ , 
    0U /*  uint8 RxPduPoolOffset to pool: RxPduPool_GW_TRNSM_FR_254  */ , 
    0U /*  uint8 TxPduPoolOffset to pool: TxPduPool_TL_ECU_TRNSM_FR_32  */ , 
    0U /*  uint8 MultRec   */ , 
    0U /*  uint8 FrTpBandwidthLimitation   */ 
  } /*  TL_MST_GW_TRNSM_FR_254_0xFB  */ , 
  {
    &FrTpConnectionControl /*  FrTp_ConnCtrlType* ConnCtrlPtr  */ , 
    0x0030U /*  uint16 LocalAddress = 48U  */ , 
    0x00FCU /*  uint16 RemoteAddress = 252U  */ , 
    12 /*  PduIdType ConnIdx   */ , 
    PduRConf_PduRSrcPdu_SRC_Dcm_GW_TRNSM_FR_254_0xFC /*  uint8 FrTpSduRxId (Referenced by SRC_Dcm_GW_TRNSM_FR_254_0xFC)  */ , 
    PduRConf_PduRDestPdu_DST_Dcm_ECU_TRNSM_FR_32_0xFC /*  uint8 FrTpSduTxId (Referenced by DST_Dcm_ECU_TRNSM_FR_32_0xFC)  */ , 
    0U /*  uint8 RxPduPoolOffset to pool: RxPduPool_GW_TRNSM_FR_254  */ , 
    0U /*  uint8 TxPduPoolOffset to pool: TxPduPool_TL_ECU_TRNSM_FR_32  */ , 
    0U /*  uint8 MultRec   */ , 
    0U /*  uint8 FrTpBandwidthLimitation   */ 
  } /*  TL_MST_GW_TRNSM_FR_254_0xFC  */ , 
  {
    &FrTpConnectionControl /*  FrTp_ConnCtrlType* ConnCtrlPtr  */ , 
    0x0030U /*  uint16 LocalAddress = 48U  */ , 
    0x00FDU /*  uint16 RemoteAddress = 253U  */ , 
    13 /*  PduIdType ConnIdx   */ , 
    PduRConf_PduRSrcPdu_SRC_Dcm_GW_TRNSM_FR_254_0xFD /*  uint8 FrTpSduRxId (Referenced by SRC_Dcm_GW_TRNSM_FR_254_0xFD)  */ , 
    PduRConf_PduRDestPdu_DST_Dcm_ECU_TRNSM_FR_32_0xFD /*  uint8 FrTpSduTxId (Referenced by DST_Dcm_ECU_TRNSM_FR_32_0xFD)  */ , 
    0U /*  uint8 RxPduPoolOffset to pool: RxPduPool_GW_TRNSM_FR_254  */ , 
    0U /*  uint8 TxPduPoolOffset to pool: TxPduPool_TL_ECU_TRNSM_FR_32  */ , 
    0U /*  uint8 MultRec   */ , 
    0U /*  uint8 FrTpBandwidthLimitation   */ 
  } /*  TL_MST_GW_TRNSM_FR_254_0xFD  */ , 
  {
    &FrTpConnectionControl /*  FrTp_ConnCtrlType* ConnCtrlPtr  */ , 
    0x00DFU /*  uint16 LocalAddress = 223U  */ , 
    0x00F0U /*  uint16 RemoteAddress = 240U  */ , 
    14 /*  PduIdType ConnIdx   */ , 
    PduRConf_PduRSrcPdu_SRC_Dcm_BRC_FR_32_0xF0 /*  uint8 FrTpSduRxId (Referenced by SRC_Dcm_BRC_FR_32_0xF0)  */ , 
    0xFFU /*  No PdurDestPduRef found: Connection will not be able to transmit TP-data!  */ , 
    1U /*  uint8 RxPduPoolOffset to pool: RxPduPool_TL_BRC_FR_32  */ , 
    1U /*  uint8 TxPduPoolOffset to pool: no TxPduPool configured!  */ , 
    1U /*  uint8 MultRec   */ , 
    0U /*  uint8 FrTpBandwidthLimitation   */ 
  } /*  TL_BRC_FR_32_0xDF_0xF0  */ , 
  {
    &FrTpConnectionControl /*  FrTp_ConnCtrlType* ConnCtrlPtr  */ , 
    0x00DFU /*  uint16 LocalAddress = 223U  */ , 
    0x00F1U /*  uint16 RemoteAddress = 241U  */ , 
    15 /*  PduIdType ConnIdx   */ , 
    PduRConf_PduRSrcPdu_SRC_Dcm_BRC_FR_32_0xF1 /*  uint8 FrTpSduRxId (Referenced by SRC_Dcm_BRC_FR_32_0xF1)  */ , 
    0xFFU /*  No PdurDestPduRef found: Connection will not be able to transmit TP-data!  */ , 
    1U /*  uint8 RxPduPoolOffset to pool: RxPduPool_TL_BRC_FR_32  */ , 
    1U /*  uint8 TxPduPoolOffset to pool: no TxPduPool configured!  */ , 
    1U /*  uint8 MultRec   */ , 
    0U /*  uint8 FrTpBandwidthLimitation   */ 
  } /*  TL_BRC_FR_32_0xDF_0xF1  */ , 
  {
    &FrTpConnectionControl /*  FrTp_ConnCtrlType* ConnCtrlPtr  */ , 
    0x00DFU /*  uint16 LocalAddress = 223U  */ , 
    0x00F2U /*  uint16 RemoteAddress = 242U  */ , 
    16 /*  PduIdType ConnIdx   */ , 
    PduRConf_PduRSrcPdu_SRC_Dcm_BRC_FR_32_0xF2 /*  uint8 FrTpSduRxId (Referenced by SRC_Dcm_BRC_FR_32_0xF2)  */ , 
    0xFFU /*  No PdurDestPduRef found: Connection will not be able to transmit TP-data!  */ , 
    1U /*  uint8 RxPduPoolOffset to pool: RxPduPool_TL_BRC_FR_32  */ , 
    1U /*  uint8 TxPduPoolOffset to pool: no TxPduPool configured!  */ , 
    1U /*  uint8 MultRec   */ , 
    0U /*  uint8 FrTpBandwidthLimitation   */ 
  } /*  TL_BRC_FR_32_0xDF_0xF2  */ , 
  {
    &FrTpConnectionControl /*  FrTp_ConnCtrlType* ConnCtrlPtr  */ , 
    0x00DFU /*  uint16 LocalAddress = 223U  */ , 
    0x00F3U /*  uint16 RemoteAddress = 243U  */ , 
    17 /*  PduIdType ConnIdx   */ , 
    PduRConf_PduRSrcPdu_SRC_Dcm_BRC_FR_32_0xF3 /*  uint8 FrTpSduRxId (Referenced by SRC_Dcm_BRC_FR_32_0xF3)  */ , 
    0xFFU /*  No PdurDestPduRef found: Connection will not be able to transmit TP-data!  */ , 
    1U /*  uint8 RxPduPoolOffset to pool: RxPduPool_TL_BRC_FR_32  */ , 
    1U /*  uint8 TxPduPoolOffset to pool: no TxPduPool configured!  */ , 
    1U /*  uint8 MultRec   */ , 
    0U /*  uint8 FrTpBandwidthLimitation   */ 
  } /*  TL_BRC_FR_32_0xDF_0xF3  */ , 
  {
    &FrTpConnectionControl /*  FrTp_ConnCtrlType* ConnCtrlPtr  */ , 
    0x00DFU /*  uint16 LocalAddress = 223U  */ , 
    0x00F4U /*  uint16 RemoteAddress = 244U  */ , 
    18 /*  PduIdType ConnIdx   */ , 
    PduRConf_PduRSrcPdu_SRC_Dcm_BRC_FR_32_0xF4 /*  uint8 FrTpSduRxId (Referenced by SRC_Dcm_BRC_FR_32_0xF4)  */ , 
    0xFFU /*  No PdurDestPduRef found: Connection will not be able to transmit TP-data!  */ , 
    1U /*  uint8 RxPduPoolOffset to pool: RxPduPool_TL_BRC_FR_32  */ , 
    1U /*  uint8 TxPduPoolOffset to pool: no TxPduPool configured!  */ , 
    1U /*  uint8 MultRec   */ , 
    0U /*  uint8 FrTpBandwidthLimitation   */ 
  } /*  TL_BRC_FR_32_0xDF_0xF4  */ , 
  {
    &FrTpConnectionControl /*  FrTp_ConnCtrlType* ConnCtrlPtr  */ , 
    0x00DFU /*  uint16 LocalAddress = 223U  */ , 
    0x00F5U /*  uint16 RemoteAddress = 245U  */ , 
    19 /*  PduIdType ConnIdx   */ , 
    PduRConf_PduRSrcPdu_SRC_Dcm_BRC_FR_32_0xF5 /*  uint8 FrTpSduRxId (Referenced by SRC_Dcm_BRC_FR_32_0xF5)  */ , 
    0xFFU /*  No PdurDestPduRef found: Connection will not be able to transmit TP-data!  */ , 
    1U /*  uint8 RxPduPoolOffset to pool: RxPduPool_TL_BRC_FR_32  */ , 
    1U /*  uint8 TxPduPoolOffset to pool: no TxPduPool configured!  */ , 
    1U /*  uint8 MultRec   */ , 
    0U /*  uint8 FrTpBandwidthLimitation   */ 
  } /*  TL_BRC_FR_32_0xDF_0xF5  */ , 
  {
    &FrTpConnectionControl /*  FrTp_ConnCtrlType* ConnCtrlPtr  */ , 
    0x00DFU /*  uint16 LocalAddress = 223U  */ , 
    0x00F6U /*  uint16 RemoteAddress = 246U  */ , 
    20 /*  PduIdType ConnIdx   */ , 
    PduRConf_PduRSrcPdu_SRC_Dcm_BRC_FR_32_0xF6 /*  uint8 FrTpSduRxId (Referenced by SRC_Dcm_BRC_FR_32_0xF6)  */ , 
    0xFFU /*  No PdurDestPduRef found: Connection will not be able to transmit TP-data!  */ , 
    1U /*  uint8 RxPduPoolOffset to pool: RxPduPool_TL_BRC_FR_32  */ , 
    1U /*  uint8 TxPduPoolOffset to pool: no TxPduPool configured!  */ , 
    1U /*  uint8 MultRec   */ , 
    0U /*  uint8 FrTpBandwidthLimitation   */ 
  } /*  TL_BRC_FR_32_0xDF_0xF6  */ , 
  {
    &FrTpConnectionControl /*  FrTp_ConnCtrlType* ConnCtrlPtr  */ , 
    0x00DFU /*  uint16 LocalAddress = 223U  */ , 
    0x00F7U /*  uint16 RemoteAddress = 247U  */ , 
    21 /*  PduIdType ConnIdx   */ , 
    PduRConf_PduRSrcPdu_SRC_Dcm_BRC_FR_32_0xF7 /*  uint8 FrTpSduRxId (Referenced by SRC_Dcm_BRC_FR_32_0xF7)  */ , 
    0xFFU /*  No PdurDestPduRef found: Connection will not be able to transmit TP-data!  */ , 
    1U /*  uint8 RxPduPoolOffset to pool: RxPduPool_TL_BRC_FR_32  */ , 
    1U /*  uint8 TxPduPoolOffset to pool: no TxPduPool configured!  */ , 
    1U /*  uint8 MultRec   */ , 
    0U /*  uint8 FrTpBandwidthLimitation   */ 
  } /*  TL_BRC_FR_32_0xDF_0xF7  */ , 
  {
    &FrTpConnectionControl /*  FrTp_ConnCtrlType* ConnCtrlPtr  */ , 
    0x00DFU /*  uint16 LocalAddress = 223U  */ , 
    0x00F8U /*  uint16 RemoteAddress = 248U  */ , 
    22 /*  PduIdType ConnIdx   */ , 
    PduRConf_PduRSrcPdu_SRC_Dcm_BRC_FR_32_0xF8 /*  uint8 FrTpSduRxId (Referenced by SRC_Dcm_BRC_FR_32_0xF8)  */ , 
    0xFFU /*  No PdurDestPduRef found: Connection will not be able to transmit TP-data!  */ , 
    1U /*  uint8 RxPduPoolOffset to pool: RxPduPool_TL_BRC_FR_32  */ , 
    1U /*  uint8 TxPduPoolOffset to pool: no TxPduPool configured!  */ , 
    1U /*  uint8 MultRec   */ , 
    0U /*  uint8 FrTpBandwidthLimitation   */ 
  } /*  TL_BRC_FR_32_0xDF_0xF8  */ , 
  {
    &FrTpConnectionControl /*  FrTp_ConnCtrlType* ConnCtrlPtr  */ , 
    0x00DFU /*  uint16 LocalAddress = 223U  */ , 
    0x00F9U /*  uint16 RemoteAddress = 249U  */ , 
    23 /*  PduIdType ConnIdx   */ , 
    PduRConf_PduRSrcPdu_SRC_Dcm_BRC_FR_32_0xF9 /*  uint8 FrTpSduRxId (Referenced by SRC_Dcm_BRC_FR_32_0xF9)  */ , 
    0xFFU /*  No PdurDestPduRef found: Connection will not be able to transmit TP-data!  */ , 
    1U /*  uint8 RxPduPoolOffset to pool: RxPduPool_TL_BRC_FR_32  */ , 
    1U /*  uint8 TxPduPoolOffset to pool: no TxPduPool configured!  */ , 
    1U /*  uint8 MultRec   */ , 
    0U /*  uint8 FrTpBandwidthLimitation   */ 
  } /*  TL_BRC_FR_32_0xDF_0xF9  */ , 
  {
    &FrTpConnectionControl /*  FrTp_ConnCtrlType* ConnCtrlPtr  */ , 
    0x00DFU /*  uint16 LocalAddress = 223U  */ , 
    0x00FAU /*  uint16 RemoteAddress = 250U  */ , 
    24 /*  PduIdType ConnIdx   */ , 
    PduRConf_PduRSrcPdu_SRC_Dcm_BRC_FR_32_0xFA /*  uint8 FrTpSduRxId (Referenced by SRC_Dcm_BRC_FR_32_0xFA)  */ , 
    0xFFU /*  No PdurDestPduRef found: Connection will not be able to transmit TP-data!  */ , 
    1U /*  uint8 RxPduPoolOffset to pool: RxPduPool_TL_BRC_FR_32  */ , 
    1U /*  uint8 TxPduPoolOffset to pool: no TxPduPool configured!  */ , 
    1U /*  uint8 MultRec   */ , 
    0U /*  uint8 FrTpBandwidthLimitation   */ 
  } /*  TL_BRC_FR_32_0xDF_0xFA  */ , 
  {
    &FrTpConnectionControl /*  FrTp_ConnCtrlType* ConnCtrlPtr  */ , 
    0x00DFU /*  uint16 LocalAddress = 223U  */ , 
    0x00FBU /*  uint16 RemoteAddress = 251U  */ , 
    25 /*  PduIdType ConnIdx   */ , 
    PduRConf_PduRSrcPdu_SRC_Dcm_BRC_FR_32_0xFB /*  uint8 FrTpSduRxId (Referenced by SRC_Dcm_BRC_FR_32_0xFB)  */ , 
    0xFFU /*  No PdurDestPduRef found: Connection will not be able to transmit TP-data!  */ , 
    1U /*  uint8 RxPduPoolOffset to pool: RxPduPool_TL_BRC_FR_32  */ , 
    1U /*  uint8 TxPduPoolOffset to pool: no TxPduPool configured!  */ , 
    1U /*  uint8 MultRec   */ , 
    0U /*  uint8 FrTpBandwidthLimitation   */ 
  } /*  TL_BRC_FR_32_0xDF_0xFB  */ , 
  {
    &FrTpConnectionControl /*  FrTp_ConnCtrlType* ConnCtrlPtr  */ , 
    0x00DFU /*  uint16 LocalAddress = 223U  */ , 
    0x00FCU /*  uint16 RemoteAddress = 252U  */ , 
    26 /*  PduIdType ConnIdx   */ , 
    PduRConf_PduRSrcPdu_SRC_Dcm_BRC_FR_32_0xFC /*  uint8 FrTpSduRxId (Referenced by SRC_Dcm_BRC_FR_32_0xFC)  */ , 
    0xFFU /*  No PdurDestPduRef found: Connection will not be able to transmit TP-data!  */ , 
    1U /*  uint8 RxPduPoolOffset to pool: RxPduPool_TL_BRC_FR_32  */ , 
    1U /*  uint8 TxPduPoolOffset to pool: no TxPduPool configured!  */ , 
    1U /*  uint8 MultRec   */ , 
    0U /*  uint8 FrTpBandwidthLimitation   */ 
  } /*  TL_BRC_FR_32_0xDF_0xFC  */ , 
  {
    &FrTpConnectionControl /*  FrTp_ConnCtrlType* ConnCtrlPtr  */ , 
    0x00DFU /*  uint16 LocalAddress = 223U  */ , 
    0x00FDU /*  uint16 RemoteAddress = 253U  */ , 
    27 /*  PduIdType ConnIdx   */ , 
    PduRConf_PduRSrcPdu_SRC_Dcm_BRC_FR_32_0xFD /*  uint8 FrTpSduRxId (Referenced by SRC_Dcm_BRC_FR_32_0xFD)  */ , 
    0xFFU /*  No PdurDestPduRef found: Connection will not be able to transmit TP-data!  */ , 
    1U /*  uint8 RxPduPoolOffset to pool: RxPduPool_TL_BRC_FR_32  */ , 
    1U /*  uint8 TxPduPoolOffset to pool: no TxPduPool configured!  */ , 
    1U /*  uint8 MultRec   */ , 
    0U /*  uint8 FrTpBandwidthLimitation   */ 
  } /*  TL_BRC_FR_32_0xDF_0xFD  */ 
}; /*!< Initializer list of all FrTpConnections used by the FrTp. */




#define FRTP_STOP_SEC_CONST_UNSPECIFIED
/* PRQA S 5087 1 */ /* MD_MSR_19.1 */
#include "MemMap.h"



#define FRTP_START_SEC_CONST_8BIT
/* PRQA S 5087 1 */ /* MD_MSR_19.1 */
#include "MemMap.h"

/* -----------------------------------------------------------------------------
    &&&~ Variable to satisfy FrTp_Init
 ----------------------------------------------------------------------------- */

/* PRQA S 3408 5 */ /* MD_FrTp_3408 */
CONST(uint8, FRTP_CONST) FrTp_Config = 0; /*!< Variable to satisfy FrTp_Init() for non-postbuild usage of the FrTp. */
/* PRQA S 5087 6 */ /* MD_MSR_19.1 */


#define FRTP_STOP_SEC_CONST_8BIT
/* PRQA S 5087 1 */ /* MD_MSR_19.1 */
#include "MemMap.h"





/* end Fileversion check */

