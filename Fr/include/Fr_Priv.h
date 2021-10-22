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
 *
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/**        \file  Fr_Priv.h
 *        \brief  FlexRay Driver private header file
 *
 *      \details  Private header for FlexRay Driver according to:
 *                AUTOSAR FlexRay Driver, AUTOSAR Release 4.0
 *
 *********************************************************************************************************************/

 /*********************************************************************************************************************
 *  REVISION HISTORY
 *  -------------------------------------------------------------------------------------------------------------------
 *  Refer to the module's header file.
 *********************************************************************************************************************/

#ifndef FR_PRIV_H
# define FR_PRIV_H


/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
# include "Platform_Types.h"
# include "Fr.h"


# include "SchM_Fr.h"

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/

/* FlexRay Driver limitations */
# define FR_VMAX_NUM_BUF_CONFIGS                                      1u
# define FR_VMAX_NUM_LOW_LEVEL_CONFIGS                                1u
# define FR_VMAX_NUM_CYCLE                                            64u
# define FR_INSTANCE_ID_DET                                           0u /* currently only one driver instance is supported */

# define FR_VFR_IBCM_INITVALUE                                        0x00000001u

#if !defined (STATIC)                                                 /* COV_FR_MSR_COMPATIBILITY */
# define STATIC                                                       static
#endif

# define EQUAL                                                        TRUE
# define NEQUAL                                                       FALSE

/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/

/* PRQA S 3453 FUNCTIONLIKEMACRO */ /* MD_MSR_19.7 */
# define FR_VENTER_CRITICAL_SECTION_0()                               SchM_Enter_Fr_FR_EXCLUSIVE_AREA_0() /*!< \trace SPEC-42540 */
# define FR_VLEAVE_CRITICAL_SECTION_0()                               SchM_Exit_Fr_FR_EXCLUSIVE_AREA_0() /*!< \trace SPEC-42540 */
# if !defined (FR_DUMMY_STATEMENT)                                    /* COV_FR_MSR_COMPATIBILITY */
#  define FR_DUMMY_STATEMENT(id)                                      (id) = (id)
# endif

/**********************************************************************************************************************
 * HARDWARE ABSTRACTION LAYER
 *********************************************************************************************************************/

#  define Fr_VCCGetPocState(Ctrl)                                     ((uint32)(Fr_VCCReadBits((Ctrl), FR_CCSV, FR_CCSV_POCS_MASK)))
#  define Fr_VCCWriteValueIBCM(Ctrl, Val)                             Fr_VCCWriteValue((Ctrl), FR_IBCM, (Val))
#  define Fr_VCCWriteValueIBCR(Ctrl, Val)                             Fr_VCCWriteValue((Ctrl), FR_IBCR, (Val))
#  define Fr_VCCWriteValueOBCM(Ctrl, Val)                             Fr_VCCWriteValue((Ctrl), FR_OBCM, (Val))
#  define Fr_VCCWriteValueOBCR(Ctrl, Val)                             Fr_VCCWriteValue((Ctrl), FR_OBCR, (Val))
#  define Fr_VCCWriteValueWRHS(Ctrl, Reg, Val)                        Fr_VCCWriteValue((Ctrl), (Reg), (Val))



# if (STD_ON == FR_PROD_ERROR_DETECT)
/* ESCAN00057357, ESCAN00061983 */
#  ifndef Fr_DemReportErrorStatus                                     /* COV_FR_TESTSUITE_INSTRUMENTATION */
#   define Fr_DemReportErrorStatus(ERROR_CODE, EvId)                  ((void)Dem_ReportErrorStatus((ERROR_CODE), (EvId)))
#  endif
# else
#  ifndef Fr_DemReportErrorStatus                                     /* COV_FR_TESTSUITE_INSTRUMENTATION */
#   define Fr_DemReportErrorStatus(ERROR_CODE, EvId)
#  endif
# endif

/* Macros to access CC Register (general access) */
# define Fr_VCCRegAddr(Ctrl, Reg)                                     ((volatile uint32*)((void*)(Fr_VCCGetRegStartAddr((Ctrl))+(Reg))))

# define Fr_VCCReadBits(Ctrl, Reg, Mask)                              ((Fr_VCCReadValue((Ctrl),(Reg)) & (Mask)))
# define Fr_VCCReadBitsShift(Ctrl, Reg, Mask, Shift)                  ((Fr_VCCReadValue((Ctrl),(Reg)) & (Mask)) >> (Shift))
# define Fr_VCCReadValueShiftdMask(Ctrl, Reg, Shift, Mask)            ((Fr_VCCReadValue((Ctrl),(Reg)) >> (Shift)) & (Mask))
/* Delete old bits and set new bits on the mask */
# define Fr_VCCSetBitsMask(Ctrl, Reg, Bits, Mask)                     Fr_VCCWriteValue((Ctrl),(Reg), (Fr_VCCReadBits((Ctrl),(Reg), (~(Mask))) | ((Bits) & (Mask))))
# define Fr_VCCIsBitSet(Ctrl, Reg, Bit)                               (Fr_VCCReadBits((Ctrl),(Reg), (Bit)) == (Bit))

# define Fr_VCCIsIrqActive(SIES, SIR)                                 (0UL != ((SIES) & (SIR)))
# define Fr_VCheckIrqFlag(Flag, EnableReg, IrqReg)                    (((Flag) & (EnableReg)) & (IrqReg))
# define Fr_VCCCheckIrqFlag(Ctrl, Flag, EnableReg, IrqReg)            (Fr_VCheckIrqFlag((Flag), Fr_VCCReadValue((Ctrl), (EnableReg)), Fr_VCCReadValue((Ctrl), (IrqReg))))
# define Fr_VCCCheckIrqStatusFlag(Ctrl, Flag)                         (Fr_VCCCheckIrqFlag((Ctrl), (Flag), FR_SIES, FR_SIR))
# define Fr_VCCCheckIrqErrorFlag(Ctrl, Flag)                          (Fr_VCCCheckIrqFlag((Ctrl), (Flag), FR_EIES, FR_EIR))
# define Fr_VCCClearIrqErrorFlag(Ctrl, Flag)                          Fr_VCCWriteValue((Ctrl), FR_EIR, (Flag))
# define Fr_VCCEnableIrqStatusFlag(Ctrl, Flag)                        Fr_VCCWriteValue((Ctrl), FR_SIES, (Flag))
# define Fr_VCCDisableIrqStatusFlag(Ctrl, Flag)                       Fr_VCCWriteValue((Ctrl), FR_SIER, (Flag))
# define Fr_VCCGetCmd(Ctrl)                                           (Fr_VCCReadBits((Ctrl), FR_SUCC1, FR_SUCC1_CMD_MASK))
# define Fr_VCCGetTxMsgBufferNumber(Ctrl)                             (Fr_VCCReadBits((Ctrl), FR_MHDS, FR_MHDS_MBT_MASK) >> FR_MHDS_MBT_SHIFT)
# define Fr_VCCGetRxMsgBufferNumber(Ctrl)                             (Fr_VCCReadBits((Ctrl), FR_MHDS, FR_MHDS_MBU_MASK) >> FR_MHDS_MBU_SHIFT)
# define Fr_VCCCheckMTS(Ctrl, Flag, Shift)                            (Fr_VCCReadBits((Ctrl), FR_SWNIT, ((Flag) << (Shift))))
# define Fr_VCCIsColdStarter(Ctrl)                                    (Fr_VCCIsBitSet((Ctrl), FR_SUCC1, FR_SUCC1_TXST))
# define Fr_VCCGetReceiveLength(Ctrl)                                 ((uint8)(Fr_VCCReadBitsShift((Ctrl), FR_RDHS2,FR_RDHS2_PLR_MASK,FR_RDHS2_PLR_SHIFT)))

/* Macros to access CC Register (message buffer) */
/* 32 buffer/register, 4 addr/register: 4*(Idx/32) == Idx & 0xE0 (i.e. NDAT1: Addr 330, NDAT2: Addr 334, ...) */
# define Fr_VCCMsgBufRegAddr(Reg, Idx)                                ((Reg) + ((((uint32)(Idx)) >> 3) & 0xFFFFFFFCUL) )
# define Fr_VCCNewDatReg(Idx)                                         (Fr_VCCMsgBufRegAddr(FR_NDATn,(Idx)))
# define Fr_VCCNewData(Ctrl, Idx)                                     ((Fr_VCCReadValue((Ctrl), Fr_VCCNewDatReg((Idx))) >> (((uint32)(Idx)) & 31UL)) & 1UL)
# define Fr_VCCNewDataDfi(Ctrl, Idx)                                  (Fr_VCCNewData((Ctrl), (Idx)))

# define Fr_VCCNewReqReg(Idx)                                         (Fr_VCCMsgBufRegAddr(FR_TXRQn,(Idx)))
# define Fr_VCCNewReq(Ctrl, Idx)                                      ((Fr_VCCReadValue((Ctrl), Fr_VCCNewReqReg((Idx))) >> (((uint32)(Idx)) & 31UL)) & 1UL)
# define Fr_VCCNullFrameReceived(Ctrl)                                (Fr_VCCReadBits((Ctrl), FR_RDHS3, FR_RDHS3_NFI))
# define Fr_VCCNewDataCycleCnt(Ctrl)                                  (Fr_VCCReadBitsShift((Ctrl), FR_RDHS3, FR_RDHS3_RCC_MASK, FR_RDHS3_RCC_SHIFT))

/* PRQA L:FUNCTIONLIKEMACRO */ /* MD_MSR_19.7 */

/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/
# if (FR_DEV_ERROR_DETECT == STD_ON )
/*! \typedef Variables of this type represent the internal state of the Fr module */
typedef enum
{
  FR_VUNINITPTR = 0x00,  /*!< The AUTOSAR FR module has no valid pointer */
  FR_VUNINITCFG = 0x01,  /*!< The AUTOSAR FR module is not initialized or not usable. */
  FR_VINIT      = 0x02   /*!< The AUTOSAR FR module is initialized and usable */
}Fr_VFrDrvStateType;
# endif

# define FR_START_SEC_VAR_ZERO_INIT_UNSPECIFIED
# include "MemMap.h" /* PRQA S 5087 */ /*  MD_MSR_19.1 */ /*lint -e{451} */

# if (FR_DEV_ERROR_DETECT == STD_ON )
extern VAR(Fr_VFrDrvStateType, FR_VAR_ZERO_INIT) Fr_VFrDrvState;
# endif /* FR_DEV_ERROR_DETECT == STD_ON */

# define FR_STOP_SEC_VAR_ZERO_INIT_UNSPECIFIED
# include "MemMap.h" /* PRQA S 5087 */ /*  MD_MSR_19.1 */ /*lint -e{451} */



/***** end of header file ********************************************************************************************/
#endif
/* FR_PRIV_H */
