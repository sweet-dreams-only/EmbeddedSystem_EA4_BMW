/**********************************************************************************************************************
 *  COPYRIGHT
 *  -------------------------------------------------------------------------------------------------------------------
 *  \verbatim
 *  Copyright (c) 2017 by Vctr Informatik GmbH.                                                  All rights reserved.
 *
 *                This software is copyright protected and proprietary to Vctr Informatik GmbH.
 *                Vctr Informatik GmbH grants to you only those rights as set out in the license conditions.
 *                All other rights remain with Vctr Informatik GmbH.
 *  \endverbatim
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/*
 *        \file   FrTp_Util.c
 *        \brief  Source file of the FrTp sub-module Util
 *
 *      \details  Source file containing the internal service functions of the sub-module Util of the FrTp.
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  REVISION HISTORY
 *  -------------------------------------------------------------------------------------------------------------------
 *  Refer to the module's header file.
 * 
 *  FILE VERSION
 *  -------------------------------------------------------------------------------------------------------------------
 *  Refer to the VERSION CHECK below.
 *********************************************************************************************************************/

#define FRTP_UTIL_SOURCE

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/

#include "FrTp_Util.h"
#include "vstdlib.h"

/**********************************************************************************************************************
 *  VERSION CHECK
 *********************************************************************************************************************/

/* Check the version of FrTp header file */
#if (  (FRTP_UTIL_SW_MAJOR_VERSION != (2u)) \
    || (FRTP_UTIL_SW_MINOR_VERSION != (4u)) \
    || (FRTP_UTIL_SW_PATCH_VERSION != (4u)) )
# error "Vendor specific version numbers of FrTp_Util.c and FrTp.h are inconsistent"
#endif

/* Check the version of the configuration header file */
#if (  (FRTP_CFG_MAJOR_VERSION != (2u)) \
    || (FRTP_CFG_MINOR_VERSION != (4u)) )
# error "Version numbers of FrTp_Util.c and FrTp_Cfg.h are inconsistent!"
#endif

/**********************************************************************************************************************
 *  LOCAL CONSTANT MACROS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL FUNCTION MACROS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL DATA PROTOTYPES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL DATA
 *********************************************************************************************************************/

#define FRTP_START_SEC_CONST_UNSPECIFIED 
/* PRQA S 5087 1 */ /* MD_MSR_19.1 */
#include "MemMap.h" /*lint -e{451} */

/*!< Local static constant map to quickly look up the format offset within a TP-pdu for a given pdu type */
CONST(uint8, FRTP_CONST) FrTp_FmtOffset[FrTp_NumPduTypes] =
{
  (uint8)4u, /* FrTp_PCISTFunseg ((uint8)(0x40u)), FrTp_PCISTFseg   ((uint8)(0x41u)) */
  (uint8)2u, /* FrTp_PCICF1      ((uint8)(0x50u)) */
  (uint8)2u, /* FrTp_PCICF2      ((uint8)(0x60u)) */
  (uint8)2u, /* FrTp_PCICFEOB    ((uint8)(0x70u)) */
  (uint8)0u, /* FrTp_PCIFC       ((uint8)(0x80u)) */
  (uint8)4u, /* FrTp_PCILF       ((uint8)(0x90u)) */
  (uint8)0u  /* FrTp_PCIinvalid  ((uint8)(0xA0u)) */
};

/*!< Local static constant map to quickly calculate the separation cycles for a given separation cycle exponent */
/*!< Timer for:
Pause   SC  SCexp Main/Cycle=1  Main/Cycle=2  Main/Cycle=4
0       1   0     1             1             1
1       2   1     2             2             2
3       4   2     4             2             2
7       8   3     8             4             2
15      16  4     16            8             4
31      32  5     32            16            8
63      64  6     64            32            16
127     128 7     128           64            32
*/
CONST(uint8, FRTP_CONST) FrTp_TxSm_GetSepCyclesFor[FrTp_NumberOfSCexponents] =
{
  (uint8)1u, /* SCexp = 0, i.e. SC=(2^0)-1 + 1 because of minimal value '1' of internal channel timer */
  (uint8)2u, /* SCexp = 1, i.e. SC=(2^1)-1 */
  (uint8)4u, /* SCexp = 2, i.e. SC=(2^2)-1 */
  (uint8)8u, /* SCexp = 3, i.e. SC=(2^3)-1 */
  (uint8)16u, /* SCexp = 4, i.e. SC=(2^4)-1 */
  (uint8)32u, /* SCexp = 5, i.e. SC=(2^5)-1 */
  (uint8)64u, /* SCexp = 6, i.e. SC=(2^6)-1 */
  (uint8)128u /* SCexp = 7, i.e. SC=(2^7)-1 */
};

#define FRTP_STOP_SEC_CONST_UNSPECIFIED 
/* PRQA S 5087 1 */ /* MD_MSR_19.1 */
#include "MemMap.h" /*lint -e{451} */

/**********************************************************************************************************************
 *  LOCAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL FUNCTIONS
 *********************************************************************************************************************/

#define FRTP_START_SEC_CODE 
/* PRQA S 5087 1 */ /* MD_MSR_19.1 */
#include "MemMap.h" /*lint -e{451} */

/***********************************************************************************************************************
 * FrTp_Util_WriteML()
 **********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 */
FUNC(void, FRTP_CODE) FrTp_Util_WriteML(
  P2VAR(uint8, AUTOMATIC, FRTP_APPL_DATA) dataPtr, 
  uint16 ML)
{
  /* ----- Implementation ----------------------------------------------- */
  /* #10 Write the hi and lo byte of the ML-value into the memory area given by dataPtr at the correct offset */
  dataPtr[FrTp_Iso_MlHighByteOffset] = (uint8)((ML)); /* SBSW_FRTP_WRITE_ML */
  dataPtr[FrTp_Iso_MlLowByteOffset] = (uint8)((ML) >> 8); /* SBSW_FRTP_WRITE_ML */
} /* FrTp_Util_WriteML */

/***********************************************************************************************************************
 * FrTp_Util_AssemblePdu()
 **********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 *
 *
 */
FUNC(uint8, FRTP_CODE) FrTp_Util_AssemblePdu(
  P2CONST(FrTp_ConnCfgType, AUTOMATIC, FRTP_CONST) pConnCfg,
  P2CONST(PduInfoType, AUTOMATIC, FRTP_CONST) pTPCI, 
  P2CONST(PduInfoType, AUTOMATIC, FRTP_CONST) pPayload, 
  P2VAR(uint8, AUTOMATIC, FRTP_APPL_DATA) pPduBuffer)
{
  /* ----- Local Variables ---------------------------------------------- */
  uint8 posInFrame = FrTp_Util_OffsetTPCI;
  /* #10 Retrieve RA and LA from the connection configuration provided by the caller
   *          Assemble the address information into the pPduBuffer provided by the caller */
  uint16 LA = pConnCfg->LocalAddress;
  uint16 RA = pConnCfg->RemoteAddress;
  
  /* ----- Implementation ----------------------------------------------- */
  pPduBuffer[FrTp_Util_AddrOffsetByte1] = (uint8)((RA & 0xff00) >> 8); /* SBSW_FRTP_ASSEMBLE_PDU_ADDR */
  pPduBuffer[FrTp_Util_AddrOffsetByte2] = (uint8)(RA & 0x00ff); /* SBSW_FRTP_ASSEMBLE_PDU_ADDR */
  pPduBuffer[FrTp_Util_AddrOffsetByte3] = (uint8)((LA & 0xff00) >> 8); /* SBSW_FRTP_ASSEMBLE_PDU_ADDR */
  pPduBuffer[FrTp_Util_AddrOffsetByte4] = (uint8)(LA & 0x00ff); /* SBSW_FRTP_ASSEMBLE_PDU_ADDR */
  
  /* #20 Copy the PCI into the pPduBuffer, both provided by the caller
   *          Increase posInFrame by the length of the PCI in order to continue pdu-assembly with the optional payload */
  VStdLib_MemCpy(&(pPduBuffer[posInFrame]), pTPCI->SduDataPtr, pTPCI->SduLength); /* SBSW_FRTP_ASSEMBLE_PDU_TPCI */
  posInFrame = (uint8)(posInFrame + pTPCI->SduLength);

  /* #30 In case the pduInfo-struct contains a valid pointer to payload-data:
   *          Copy the payload provided by the caller into pPduBuffer
   *          Increase posInFrame by the length of the payload in order to be able to return the length of the assembled-pdu to the caller */
  if(pPayload->SduDataPtr != NULL_PTR)
  {
    VStdLib_MemCpy(&(pPduBuffer[posInFrame]), pPayload->SduDataPtr, pPayload->SduLength); /* SBSW_FRTP_ASSEMBLE_PDU_PAYLOAD */
    posInFrame = (uint8)((posInFrame) + (pPayload->SduLength));
  }
  /* else: Frame contains no payload (FC) */
  return posInFrame;
} /* FrTp_Util_AssemblePdu */

#define FRTP_STOP_SEC_CODE 
/* PRQA S 5087 1 */ /* MD_MSR_19.1 */
#include "MemMap.h" /*lint -e{451} */

/**********************************************************************************************************************
 *  END OF FILE: FrTp_Util.c
 *********************************************************************************************************************/

