/**********************************************************************************************************************
 *  COPYRIGHT
 *  -------------------------------------------------------------------------------------------------------------------
 *  \verbatim
 *  Copyright (c) 2017 by Vctr Informatik GmbH.                                              All rights reserved.
 *
 *                This software is copyright protected and proprietary to Vctr Informatik GmbH.
 *                Vctr Informatik GmbH grants to you only those rights as set out in the license conditions.
 *                All other rights remain with Vctr Informatik GmbH.
 *  \endverbatim
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/*!
 *        \file   FrTp_Util.h
 *        \brief  Header file of the FrTp sub-module Util.
 *
 *      \details  Declares those functions of the sub-module Util that are called by other modules of the FrTp.
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  REVISION HISTORY
 *  -------------------------------------------------------------------------------------------------------------------
 *  Refer to the module's header file.
 * 
 *  FILE VERSION
 *  -------------------------------------------------------------------------------------------------------------------
 *  Refer to the VERSION CHECK in file FrTp.c
 *********************************************************************************************************************/

#if !defined (FRTP_UTIL_H)
#define FRTP_UTIL_H

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "Compiler.h"
#include "FrTp_Cfg.h"
#include "FrTp_GlobCfg.h"
#include "FrTp_Types.h"

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/

/* ----- Component version information (decimal version of ALM implementation package) ----- */
#define FRTP_UTIL_SW_MAJOR_VERSION                     (2u)
#define FRTP_UTIL_SW_MINOR_VERSION                     (4u)
#define FRTP_UTIL_SW_PATCH_VERSION                     (4u)

/* ----- API service IDs ----- */

/* ----- Error codes ----- */

/* ----- Modes ----- */

/* ----- Component specific stuff ----- */

/*!< Pdu layout */
#define FrTp_Util_OffsetTA                              (0u)
#define FrTp_Util_OffsetSA                              (2u)
#define FrTp_Util_OffsetTPCI                            (4u)
#define FrTp_Util_AddrOffsetByte1                       (0u)
#define FrTp_Util_AddrOffsetByte2                       (1u)
#define FrTp_Util_AddrOffsetByte3                       (2u)
#define FrTp_Util_AddrOffsetByte4                       (3u)

/*!< FrTp_NumPduTypes beinhaltet den FrTp_PCIinvalid ist also FrTp_PCIinvalid + 1 */
#define FrTp_NumPduTypes ((uint8)7u)

/*!< ISO10681-2 specific constants */
#define FrTp_NumberOfSCexponents  ((uint8)8u)

/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/
/* PRQA S 3453 FUNCTION_LIKE_MACROS */ /* MD_MSR_19.7 */

/**********************************************************************************************************************
  FrTp_Util_Make16Bit()
**********************************************************************************************************************/
/*!
 * \fn          16bitValue FrTp_Util_Make16Bit(hiByte, loByte)
 * \brief       Converts the given two 8-bit-values to one 16-bit value.
 * \details     Converts the given two hiByte and loByte values to one 16-bit value.
 * \param[in]   uint8 hiByte
 * \param[in]   uint8 loByte
 * \return      uint16: 16-bit value made from the two 8-bit parameters.
 * \pre         -
 * \context     TASK|ISR
 * \reentrant   TRUE
 * \synchronous TRUE
 * \trace       DSGN-FrTpAddressFiltering, DSGN-FrTpReception
 *********************************************************************************************************************/
#define FrTp_Util_Make16Bit(hiByte, loByte) ((uint16)((((uint16)(hiByte))<<8u) | ((uint16)(loByte))))

/**********************************************************************************************************************
  FrTp_Util_ReadFPL()
**********************************************************************************************************************/
/*!
 * \fn          fplValue FrTp_Util_ReadFPL(dataPtr)
 * \brief       Reads the frame payload length from the pdu.
 * \details     Reads the ISO10681-2 parameter FPL from the pdu starting at the given dataPtr, expecting *NO* C_AI.
 * \param[in]   uint8* dataPtr: The parameter dataPtr has to be non-NULL_PTR.
 *                              The pdu starting at dataPtr may *NOT* start with address bytes C_AI. but shall be *WITHOUT* these.
 * \return      uint8: 8-bit value FPL read from the FrTp Pdu pointed to be parameter dataPtr.
 * \pre         -
 * \context     TASK|ISR
 * \reentrant   TRUE
 * \synchronous TRUE
 * \trace       DSGN-FrTpReception
 *********************************************************************************************************************/
#define FrTp_Util_ReadFPL(dataPtr) ((dataPtr)[FrTp_FmtOffsetFPL])

/**********************************************************************************************************************
  FrTp_Util_ReadML()
**********************************************************************************************************************/
/*!
 * \fn          mlValue FrTp_Util_ReadML(dataPtr)
 * \brief       Reads message length from the pdu.
 * \details     Reads the ISO10681-2 parameter ML from the pdu starting at the given dataPtr, expecting *NO* C_AI.
 * \param[in]   uint8* dataPtr: The parameter dataPtr has to be non-NULL_PTR.
 *                              The pdu starting at dataPtr may *NOT* start with address bytes C_AI. but shall be *WITHOUT* these.
 * \return      uint16: 16-bit value ML read from the FrTp Pdu pointed to be parameter dataPtr.
 * \pre         -
 * \context     TASK|ISR
 * \reentrant   TRUE
 * \synchronous TRUE
 * \trace       DSGN-FrTpReception, DSGN-FrTpTransmission
 *********************************************************************************************************************/
#define FrTp_Util_ReadML(dataPtr) FrTp_Util_Make16Bit(((dataPtr)[FrTp_Iso_MlLowByteOffset]), ((dataPtr)[FrTp_Iso_MlHighByteOffset]))

/**********************************************************************************************************************
  FrTp_Util_ReadBfS()
**********************************************************************************************************************/
/*!
 * \fn          mlValue FrTp_Util_ReadBfS(dataPtr)
 * \brief       Reads the buffer size from the pdu.
 * \details     Reads the ISO10681-2 parameter BfS from the pdu starting at the given dataPtr, expecting *NO* C_AI.
 * \param[in]   uint8* dataPtr: The parameter dataPtr has to be non-NULL_PTR.
 *                              The pdu starting at dataPtr may *NOT* start with address bytes C_AI. but shall be *WITHOUT* these.
 * \return      uint16: 16-bit value BfS read from the FrTp Pdu pointed to be parameter dataPtr.
 * \pre         -
 * \context     TASK|ISR
 * \reentrant   TRUE
 * \synchronous TRUE
 * \trace       DSGN-FrTpReception, DSGN-FrTpTransmission
 *********************************************************************************************************************/
#define FrTp_Util_ReadBfS(dataPtr) FrTp_Util_ReadML(dataPtr)

/**********************************************************************************************************************
  FrTp_Util_ReadTA()
**********************************************************************************************************************/
/*!
 * \fn          taValue FrTp_Util_ReadTA(dataPtr)
 * \brief       Reads the target address from the pdu.
 * \details     Reads the ISO10681-2 parameter TA from the pdu starting at the given dataPtr, expecting *NO* C_AI.
 * \param[in]   uint8* dataPtr: The parameter dataPtr has to be non-NULL_PTR.
 *                              The pdu starting at dataPtr may *NOT* start with address bytes C_AI. but shall be *WITHOUT* these.
 * \return      uint16: 16-bit value TA read from the FrTp Pdu pointed to be parameter dataPtr.
 * \pre         -
 * \context     TASK|ISR
 * \reentrant   TRUE
 * \synchronous TRUE
 * \trace       DSGN-FrTpAddressFiltering, DSGN-FrTpReception, DSGN-FrTpTransmission
 *********************************************************************************************************************/
#define FrTp_Util_ReadTA(dataPtr) FrTp_Util_Make16Bit(((dataPtr)[FrTp_Util_OffsetTA + 0u]), ((dataPtr)[FrTp_Util_OffsetTA + 1u]))

/**********************************************************************************************************************
  FrTp_Util_ReadSA()
**********************************************************************************************************************/
/*!
 * \fn          saValue FrTp_Util_ReadSA(dataPtr)
 * \brief       Reads the source address from the pdu.
 * \details     Reads the ISO10681-2 parameter SA from the pdu starting at the given dataPtr, expecting *NO* C_AI.
 * \param[in]   uint8* dataPtr: The parameter dataPtr has to be non-NULL_PTR.
 *                              The pdu starting at dataPtr may *NOT* start with address bytes C_AI. but shall be *WITHOUT* these.
 * \return      uint16: 16-bit value SA read from the FrTp Pdu pointed to be parameter dataPtr.
 * \pre         -
 * \context     TASK|ISR
 * \reentrant   TRUE
 * \synchronous TRUE
 * \trace       DSGN-FrTpAddressFiltering, DSGN-FrTpReception, DSGN-FrTpTransmission
 *********************************************************************************************************************/
#define FrTp_Util_ReadSA(dataPtr) FrTp_Util_Make16Bit(((dataPtr)[FrTp_Util_OffsetSA + 0u]), ((dataPtr)[FrTp_Util_OffsetSA + 1u]))

/**********************************************************************************************************************
  FrTp_Util_WriteFPL()
**********************************************************************************************************************/
/*!
 * \fn          fplValue FrTp_Util_WriteFPL(dataPtr)
 * \brief       Writes the frame payload length to the pdu.
 * \details     Writes the ISO10681-2 parameter FPL to the pdu starting at the given dataPtr, expecting *NO* C_AI.
 * \param[in]   uint8* dataPtr: The parameter dataPtr has to be non-NULL_PTR.
 *                              The pdu starting at dataPtr may *NOT* start with address bytes C_AI. but shall be *WITHOUT* these.
 * \param[in]   uint8: 8-bit value FPL written to the FrTp Pdu pointed to be parameter dataPtr.
 * \pre         PRE_FRTP_SM_ACCESS
 * \pre         PRE_FRTP_INIT
 * \context     TASK|ISR
 * \reentrant   TRUE
 * \synchronous TRUE
 * \trace       DSGN-FrTpReception
 *********************************************************************************************************************/
#define FrTp_Util_WriteFPL(dataPtr, FPL) ((dataPtr)[FrTp_FmtOffsetFPL] = (FPL))

/**********************************************************************************************************************
  FrTp_Util_ReadBC()
**********************************************************************************************************************/
/*!
 * \fn          bcValue FrTp_Util_ReadBC(dataPtr)
 * \brief       Reads the bandwidth control from the FC pdu.
 * \details     Reads the ISO10681-2 parameter BC from the FC pdu, starting at the given dataPtr, expecting *NO* C_AI.
 * \param[in]   uint8* dataPtr: The parameter dataPtr has to be non-NULL_PTR.
 *                              The pdu starting at dataPtr may *NOT* start with address bytes C_AI. but shall be *WITHOUT* these.
 * \return      uint8: 8-bit value BC read from the FrTp Pdu pointed to be parameter dataPtr.
 * \pre         -
 * \context     TASK|ISR
 * \reentrant   TRUE
 * \synchronous TRUE
 * \trace       DSGN-FrTpTransmission
 *********************************************************************************************************************/
#define FrTp_Util_ReadBC(dataPtr) ((dataPtr)[FrTp_FmtOffsetBc])

/**********************************************************************************************************************
  FrTp_Util_WriteBC()
**********************************************************************************************************************/
/*!
 * \fn          bcValue FrTp_Util_WriteBC(dataPtr)
 * \brief       Writes the bandwidth control to the FC pdu.
 * \details     Writes the ISO10681-2 parameter BC to the FC pdu, starting at the given dataPtr, expecting *NO* C_AI.
 * \param[in]   uint8* dataPtr: The parameter dataPtr has to be non-NULL_PTR.
 *                              The pdu starting at dataPtr may *NOT* start with address bytes C_AI. but shall be *WITHOUT* these.
 * \param[in]   uint8: 8-bit value BC written to the FrTp Pdu pointed to be parameter dataPtr.
 * \pre         PRE_FRTP_SM_ACCESS
 * \pre         PRE_FRTP_INIT
 * \context     TASK|ISR
 * \reentrant   TRUE
 * \synchronous TRUE
 * \trace       DSGN-FrTpTransmission
 *********************************************************************************************************************/
#define FrTp_Util_WriteBC(dataPtr, BC) ((dataPtr)[FrTp_FmtOffsetBc] = (BC))

/**********************************************************************************************************************
  FrTp_Util_ReadFType()
**********************************************************************************************************************/
/*!
 * \fn          bcValue FrTp_Util_ReadFType(dataPtr)
 * \brief       Reads the ISO10681-2 frame-type from the FC pdu.
 * \details     Reads the ISO10681-2 FT from the FC pdu, starting at the given dataPtr, expecting *NO* C_AI.
 * \param[in]   uint8* dataPtr: The parameter dataPtr has to be non-NULL_PTR.
 *                              The pdu starting at dataPtr may *NOT* start with address bytes C_AI. but shall be *WITHOUT* these.
 * \return      uint8: 8-bit value frame-type read from the FrTp Pdu pointed to be parameter dataPtr.
 * \pre         -
 * \context     TASK|ISR
 * \reentrant   TRUE
 * \synchronous TRUE
 * \trace       DSGN-FrTpTransmission
 *********************************************************************************************************************/
#define FrTp_Util_ReadFType(dataPtr) ((dataPtr)[FrTp_FmtOffsetFrameType])

/**********************************************************************************************************************
  FrTp_Util_WriteFType()
**********************************************************************************************************************/
/*!
 * \fn          bcValue FrTp_Util_WriteFType(dataPtr)
 * \brief       Writes the ISO10681-2 parameter frame-type to the FC pdu.
 * \details     Writes the ISO10681-2 parameter FT to the FC pdu, starting at the given dataPtr, expecting *NO* C_AI.
 * \param[in]   uint8* dataPtr: The parameter dataPtr has to be non-NULL_PTR.
 *                              The pdu starting at dataPtr may *NOT* start with address bytes C_AI. but shall be *WITHOUT* these.
 * \param[in]   uint8: 8-bit value frame-type written to the FrTp Pdu pointed to be parameter dataPtr.
 * \pre         PRE_FRTP_SM_ACCESS
 * \pre         PRE_FRTP_INIT
 * \context     TASK|ISR
 * \reentrant   TRUE
 * \synchronous TRUE
 * \trace       DSGN-FrTpTransmission
 *********************************************************************************************************************/
#define FrTp_Util_WriteFType(dataPtr, FType) ((dataPtr)[FrTp_FmtOffsetBc] = (FType))
/* PRQA L:FUNCTION_LIKE_MACROS */

/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/

#define FRTP_START_SEC_CONST_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /*  MD_MSR_19.1 */ /*lint -e{451} */

 /**********************************************************************************************************************
  FrTp_TxSm_GetSepCyclesFor()
**********************************************************************************************************************/
/*!
 * \fn          scValue FrTp_TxSm_GetSepCyclesFor(scExpValue)
 * \brief       Calculates the number of separating FlexRay-cycles based on the given Separation Cycle Exponent.
 * \details     Calculates the number of separating FlexRay-cycles based on the given ISO10681-2 parameter BC.SCexp.
 * \param[in]   uint8 BC.SCexp: The value of the given parameter BC.SCexp has to be valid according to ISO10681-2.
 * \return      Number of separating FlexRay-cycles according to ISO10681-2.
 * \pre         -
 * \context     TASK|ISR
 * \reentrant   TRUE
 * \synchronous TRUE
 * \trace       DSGN-FrTpTransmission
 *********************************************************************************************************************/
extern CONST(uint8, FRTP_CONST) FrTp_TxSm_GetSepCyclesFor[FrTp_NumberOfSCexponents];

/*!< Local static constant map to quickly look up the format offset within a TP-pdu for a given pdu type */
extern CONST(uint8, FRTP_CONST) FrTp_FmtOffset[FrTp_NumPduTypes];

#define FRTP_STOP_SEC_CONST_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /*  MD_MSR_19.1 */ /*lint -e{451} */

/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/

#define FRTP_START_SEC_CODE 
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/**********************************************************************************************************************
  FrTp_Util_WriteML()
**********************************************************************************************************************/
/*! 
 * \brief       Writes ML, BfS or BP to the given dataPtr (offset 0 regarding a dataPtr).
 * \details     Writes the ISO10681-2 parameter ML, BfS or BP to the pdu starting at the given dataPtr, expecting *NO* C_AI.
 * \param[in]   P2CONST(uint8, AUTOMATIC, FRTP_APPL_DATA) dataPtr: Ptr to where the ML shall be written
 *              Pointer dataPtr has to be non-NULL and valid and has to point to an array of uint8 of the length of range [0..(FrTp_TPCIMaxLength - 1)]
 * \param[in]   uint16 ML: Message length to be contained in the TP-message
 * \pre         PRE_FRTP_SM_ACCESS
 * \pre         PRE_FRTP_INIT
 * \context     TASK|ISR
 * \reentrant   FALSE
 * \synchronous TRUE
 * \trace       DSGN-FrTpTransmission
 *********************************************************************************************************************/
extern FUNC(void, FRTP_CODE) FrTp_Util_WriteML(
  P2VAR(uint8, AUTOMATIC, FRTP_APPL_DATA) dataPtr,
  uint16 ML
);

/**********************************************************************************************************************
  FrTp_Util_AssemblePdu()
**********************************************************************************************************************/
/*!
 * \brief       Assembles a FrTp-pdu.
 * \details     The pdu is assembled from the information coming from FrTp and FrTpCfg using the STATIC and unique 
 *              FrTp-pdu buffer of this module.
 * \param[in]   P2CONST(FrTp_ConnCfgType, FRTP_CONST, FRTP_CONST) pConnCfg <=> Configuration of the
 *              connection the pdu shall be assembled for
 * \param[in]   P2CONST(PduInfoType, FRTP_CONST, FRTP_CONST) pTPCI <=> Pointer to TPCI of the pdu to be assembled.
 *              PRE_FRTP_VALID_PDU_INFO_TYPE pTPCI
 * \param[in]   P2CONST(PduInfoType, FRTP_CONST, FRTP_CONST) pPayload <=> Pointer to the payload fragment that shall be copied into the pdu.
 *              PRE_FRTP_VALID_PDU_INFO_TYPE pPayload
 * \param[in]   P2VAR(uint8, AUTOMATIC, FRTP_APPL_DATA) pPduBuffer <=> Pointer to the pdu buffer.
 *              Pointer pPduBuffer has to point to a valid variable of type uint8[].
 * \return      uint8 length of the FrTp-pdu (Actual length of assembled pdu in bytes)
 * \pre         PRE_FRTP_SM_ACCESS
 * \pre         PRE_FRTP_INIT
 * \context     TASK|ISR
 * \reentrant   FALSE
 * \synchronous TRUE
 * \trace       DSGN-FrTpReception, DSGN-FrTpTransmission, DSGN-FrTpAddressFiltering
 *********************************************************************************************************************/
extern FUNC(uint8, FRTP_CODE) FrTp_Util_AssemblePdu(
  P2CONST(FrTp_ConnCfgType, FRTP_CONST, FRTP_CONST) pConnCfg,
  P2CONST(PduInfoType, AUTOMATIC, FRTP_CONST) pTPCI,
  P2CONST(PduInfoType, AUTOMATIC, FRTP_CONST) pPayload,
  P2VAR(uint8, AUTOMATIC, FRTP_APPL_DATA) pPduBuffer
);

#define FRTP_STOP_SEC_CODE 
#include "MemMap.h" /* PRQA S 5087 */  /* MD_MSR_19.1 */

#endif /* FRTP_UTIL_H */

/**********************************************************************************************************************
 *  END OF FILE: FrTp_Util.h
 *********************************************************************************************************************/


