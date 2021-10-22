/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *          File:  CDD_XcpIf.c
 *        Config:  C:/Component/ES104B_XcpIf_Impl/tools/Component.dpa
 *     SW-C Type:  CDD_XcpIf
 *  Generated at:  Tue May 15 07:57:01 2018
 *
 *     Generator:  MICROSAR RTE Generator Version 4.13.0
 *                 RTE Core Version 1.13.0
 *       License:  Unlimited license CBD1400351 for Nxtr Automotive Corporation
 *
 *   Description:  C-Code implementation template for SW-C <CDD_XcpIf>
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of version logging area >>                DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
* Copyright 2018 Nxtr 
* Nxtr Confidential
*
* Module File Name:   CDD_XcpIf.c
* Module Description: Implementation of XCP Interface ES104B
* Project           : CBD 
* Author            : Kevin Smith
***********************************************************************************************************************
* Version Control:
* %version:          2 %
* %derived_by:       cz7lt6 %
*----------------------------------------------------------------------------------------------------------------------
* Date      Rev      Author         Change Description                                                           SCR #
* -------   -------  --------  ---------------------------------------------------------------------------     --------
* 01/19/18  1        KJS        Initial Version                                                               EA4#17610
* 05/15/18  2        KJS        Updates to support IninOptSetAIdx                                             EA4#23861
**********************************************************************************************************************/

/* PRQA S 0777, 0779 EOF */ /* MD_MSR_5.1_777, MD_MSR_5.1_779 */

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of version logging area >>                  DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *
 * AUTOSAR Modelling Object Descriptions
 *
 **********************************************************************************************************************
 *
 * Data Types:
 * ===========
 * AdrMpgReqTyp1
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * CalCopySts1
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * GetSegMod1
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * MfgEnaSt1
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 *********************************************************************************************************************/

#include "Rte_CDD_XcpIf.h" /* PRQA S 0857 */ /* MD_MSR_1.1_857 */


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of include and declaration area >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
#include "CDD_XcpIf_private.h"
#include "CDD_XcpIf_Cfg_private.h"

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of include and declaration area >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *
 * Used AUTOSAR Data Types
 *
 **********************************************************************************************************************
 *
 * Primitive Types:
 * ================
 * boolean: Boolean (standard type)
 * uint32: Integer in interval [0...4294967295] (standard type)
 * uint8: Integer in interval [0...255] (standard type)
 * uint8: Integer in interval [0...255] (standard type)
 *
 * Enumeration Types:
 * ==================
 * AdrMpgReqTyp1: Enumeration of integer in interval [0...255] with enumerators
 *   ADRMPGREQTYP_READ (0U)
 *   ADRMPGREQTYP_WR (1U)
 * CalCopySts1: Enumeration of integer in interval [0...255] with enumerators
 *   CALCOPYSTS_NOTRDY (0U)
 *   CALCOPYSTS_COPYPNDING (1U)
 *   CALCOPYSTS_COPYCMPL (2U)
 *   CALCOPYSTS_PROCERR (3U)
 * GetSegMod1: Enumeration of integer in interval [0...255] with enumerators
 *   GETSEGMOD_ADRINFO (0U)
 *   GETSEGMOD_STDINFO (1U)
 *   GETSEGMOD_ADRMPG (2U)
 * MfgEnaSt1: Enumeration of integer in interval [0...255] with enumerators
 *   MFGENAST_PRDNMOD (0U)
 *   MFGENAST_MFGMOD (1U)
 *   MFGENAST_TESTMOD (2U)
 *
 *********************************************************************************************************************/


#define CDD_XcpIf_START_SEC_CODE
#include "CDD_XcpIf_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/**********************************************************************************************************************
 *
 * Runnable Entity Name: ActvTunStsReq_Oper
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Oper> of PortPrototype <ActvTunStsReq>
 *
 **********************************************************************************************************************
 *
 * Input Interfaces:
 * =================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Read_ActvGroup_Val(uint8 *data)
 *   Std_ReturnType Rte_Read_ActvIninIdx_Val(uint8 *data)
 *   Std_ReturnType Rte_Read_ActvIninOptSetAIdx_Val(uint8 *data)
 *   Std_ReturnType Rte_Read_ActvRtIdx_Val(uint8 *data)
 *   Std_ReturnType Rte_Read_CalCopySts_Val(CalCopySts1 *data)
 *
 * Client/Server Interfaces:
 * =========================
 *   Server Invocation:
 *   ------------------
 *   Std_ReturnType Rte_Call_XcpCalChgReq_Oper(void)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_XcpCalChgReq_PortIf1_E_NOT_OK
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   void ActvTunStsReq_Oper(uint8 *ActvRtIdx_Arg, uint8 *ActvIninIdx_Arg, uint8 *ActvIninOptSetAIdx_Arg, uint8 *CalChgAllwd_Arg, uint8 *ActvGroup_Arg, uint8 *CalCopyCmpl_Arg)
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: ActvTunStsReq_Oper_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, CDD_XcpIf_CODE) ActvTunStsReq_Oper(P2VAR(uint8, AUTOMATIC, RTE_CDD_XCPIF_APPL_VAR) ActvRtIdx_Arg, P2VAR(uint8, AUTOMATIC, RTE_CDD_XCPIF_APPL_VAR) ActvIninIdx_Arg, P2VAR(uint8, AUTOMATIC, RTE_CDD_XCPIF_APPL_VAR) ActvIninOptSetAIdx_Arg, P2VAR(uint8, AUTOMATIC, RTE_CDD_XCPIF_APPL_VAR) CalChgAllwd_Arg, P2VAR(uint8, AUTOMATIC, RTE_CDD_XCPIF_APPL_VAR) ActvGroup_Arg, P2VAR(uint8, AUTOMATIC, RTE_CDD_XCPIF_APPL_VAR) CalCopyCmpl_Arg) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: ActvTunStsReq_Oper
 *********************************************************************************************************************/
    (void)Rte_Read_ActvIninIdx_Val(ActvIninIdx_Arg);
    (void)Rte_Read_ActvIninOptSetAIdx_Val(ActvIninOptSetAIdx_Arg);
    (void)Rte_Read_ActvRtIdx_Val(ActvRtIdx_Arg);
    *CalChgAllwd_Arg = Rte_Call_XcpCalChgReq_Oper();
    (void)Rte_Read_ActvGroup_Val(ActvGroup_Arg);
    (void)Rte_Read_CalCopySts_Val(CalCopyCmpl_Arg);

    return;
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: CDD_XcpIfInit1
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed once after the RTE is started
 *
 **********************************************************************************************************************
 *
 * Input Interfaces:
 * =================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Read_CustXcpEna_Logl(boolean *data)
 *   Std_ReturnType Rte_Read_MfgEnaSt_Val(MfgEnaSt1 *data)
 *
 * Client/Server Interfaces:
 * =========================
 *   Server Invocation:
 *   ------------------
 *   Std_ReturnType Rte_Call_CopyCalPageReq_Oper(uint8 Seg_Arg)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_CopyCalPageReq_PortIf1_E_NOT_OK
 *   Std_ReturnType Rte_Call_GetCalPageReq_Oper(uint8 Seg_Arg, uint8 Mod_Arg, uint8 *Page_Arg, uint8 *Rtn_Arg)
 *     Synchronous Server Invocation. Timeout: None
 *   Std_ReturnType Rte_Call_GetRefTmr1MicroSec32bit_Oper(uint32 *RefTmr_Arg)
 *     Synchronous Server Invocation. Timeout: None
 *   Std_ReturnType Rte_Call_GetSegInfoReq_Oper(GetSegMod1 Mod_Arg, uint8 Seg_Arg, uint8 SegInfo_Arg, uint8 MpgIdx_Arg, uint8 *Resp_Arg, uint8 *RespLen_Arg, uint8 *Rtn_Arg)
 *     Synchronous Server Invocation. Timeout: None
 *   Std_ReturnType Rte_Call_OnlineTunRamAdrMpg_Oper(uint32 ReqAdr_Arg, uint32 *CorrdAdr_Arg, AdrMpgReqTyp1 ReqTyp_Arg)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_OnlineTunRamAdrMpg_PortIf1_E_NOT_OK
 *   Std_ReturnType Rte_Call_SetCalPageReq_Oper(uint8 Seg_Arg, uint8 Mod_Arg, uint8 Page_Arg)
 *     Synchronous Server Invocation. Timeout: None
 *   Std_ReturnType Rte_Call_XcpCalChgReq_Oper(void)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_XcpCalChgReq_PortIf1_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: CDD_XcpIfInit1_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, CDD_XcpIf_CODE) CDD_XcpIfInit1(void) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: CDD_XcpIfInit1
 *********************************************************************************************************************/
    
    VAR(MfgEnaSt1, AUTOMATIC) MfgEnaSt_T_Cnt;
    VAR(boolean, AUTOMATIC) CustXcpEna_Cnt_T_Logl;

    (void)Rte_Read_MfgEnaSt_Val(&MfgEnaSt_T_Cnt);
    (void)Rte_Read_CustXcpEna_Logl(&CustXcpEna_Cnt_T_Logl);

    /* XCP is enabled only if MfgEnaSt is not in production mode or if customer function allows */
    if ( (MfgEnaSt_T_Cnt != MFGENAST_PRDNMOD) || (CustXcpEna_Cnt_T_Logl == TRUE) )
    {
        XCPIF_XCPCNTRLENA();
    }
    else
    {
        XCPIF_XCPCNTRLDI();
    }

    return;
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: CDD_XcpIfPer1
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered on TimingEvent every 100ms
 *
 **********************************************************************************************************************
 *
 * Input Interfaces:
 * =================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Read_CustXcpEna_Logl(boolean *data)
 *   Std_ReturnType Rte_Read_MfgEnaSt_Val(MfgEnaSt1 *data)
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: CDD_XcpIfPer1_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, CDD_XcpIf_CODE) CDD_XcpIfPer1(void) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: CDD_XcpIfPer1
 *********************************************************************************************************************/

    VAR(MfgEnaSt1, AUTOMATIC) MfgEnaSt_T_Cnt;
    VAR(boolean, AUTOMATIC) CustXcpEna_Cnt_T_Logl;

    (void)Rte_Read_MfgEnaSt_Val(&MfgEnaSt_T_Cnt);
    (void)Rte_Read_CustXcpEna_Logl(&CustXcpEna_Cnt_T_Logl);

    /* XCP is enabled only if MfgEnaSt is not in production mode or if customer function allows */
    if ( (MfgEnaSt_T_Cnt != MFGENAST_PRDNMOD) || (CustXcpEna_Cnt_T_Logl == TRUE) )
    {
        XCPIF_XCPCNTRLENA();
    }
    else
    {
        XCPIF_XCPCNTRLDI();
    }

    return;
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}


#define CDD_XcpIf_STOP_SEC_CODE
#include "CDD_XcpIf_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of function definition area >>            DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

#if( XCP_DAQ_TIMESTAMP_SIZE > 0 )
/**********************************************************************************************************************
* Name:         XcpAppl_GetTimestamp
*
* Description:  Returns the current timestamp. The timestamp can be uint8, uint15, or uint32 depending on the 
*               configuration. 
*
* Inputs:       N/A
*
* Outputs:      XcpDaqTimestampType - Timestamp value based on XcpDaqTimestampType format.
*
* Usage Notes:  This XCP callout function is a synchronous, non-reentrant function that is available only if 
*               XCP_DAQ_TIMESTAMP_SIZE is greater than zero.
**********************************************************************************************************************/
FUNC(Xcp_TimestampType, XCP_CODE) XcpAppl_GetTimestamp( void )
{
    VAR(uint32, AUTOMATIC) TiStamp_Cnt_T_u32;

    (void)Rte_Call_GetRefTmr1MicroSec32bit_Oper( &TiStamp_Cnt_T_u32 );
    return (Xcp_TimestampType)TiStamp_Cnt_T_u32;
}
#endif

#if !defined ( XcpAppl_MemCpy )
/**********************************************************************************************************************
* Name:         XcpAppl_MemCpy
*
* Description:  Copies data from Src to Dst.
*
* Inputs:       Dst - Pointer to target to copy data to.
*               Src - Pointer to source to copy data from.
*               Size - Length of data to copy.
*
* Outputs:      N/A
*
* Usage Notes:  This XCP callout function is a synchronous, non-reentrant function.
**********************************************************************************************************************/
FUNC(void, XCP_CODE) XcpAppl_MemCpy( P2VAR(uint8, AUTOMATIC, AUTOMATIC) Dst,
                                     P2CONST(uint8, AUTOMATIC, AUTOMATIC) Src,
                                     VAR(uint16, AUTOMATIC) Size )
{
    VAR(uint8, AUTOMATIC) Idx_Cnt_T_u08;

    for (Idx_Cnt_T_u08 = 0U; Idx_Cnt_T_u08 < Size; Idx_Cnt_T_u08++)
    {
        Dst[Idx_Cnt_T_u08] = Src[Idx_Cnt_T_u08];
    }
    
    return;
}
#endif

/**********************************************************************************************************************
* Name:         XcpAppl_MeasurementRead
*
* Description:  Read n bytes from Src to Dst.
*
* Inputs:       Dst - Pointer to target to copy data to.
*               Src - Pointer to source to copy data from.
*               Size - Length of data to copy.
*
* Outputs:      uint8 - Returns XCPIF_CMDOK_CNT_U08 on success or XCPIF_CMDDENIED_CNT_U08 on error.
*
* Usage Notes:  This XCP callout function is a synchronous, non-reentrant function. More details are described below.
*                -- A maximum of 255 Bytes can be copied at once.
**********************************************************************************************************************/
FUNC(uint8, XCP_CODE) XcpAppl_MeasurementRead( P2VAR(uint8, AUTOMATIC, XCP_APPL_VAR) Dst,
                                               VAR(Xcp_AddressPtrType, AUTOMATIC) Src,
                                               VAR(uint8, AUTOMATIC) Size )
{
    VAR(uint8, AUTOMATIC) Idx_Cnt_T_u08;
    VAR(uint32, AUTOMATIC) CorrAdr_Cnt_T_u32;
    VAR(uint8, AUTOMATIC) MpgAdrRes_Cnt_T_u08;
    VAR(uint8, AUTOMATIC) Rtn_Cnt_T_u08;

    MpgAdrRes_Cnt_T_u08 = Rte_Call_OnlineTunRamAdrMpg_Oper(Src, &CorrAdr_Cnt_T_u32, ADRMPGREQTYP_READ);
    if (MpgAdrRes_Cnt_T_u08 == E_OK)
    {
        for (Idx_Cnt_T_u08 = 0U; Idx_Cnt_T_u08 < Size; Idx_Cnt_T_u08++)
        {
            Dst[Idx_Cnt_T_u08] = ((uint8 *)CorrAdr_Cnt_T_u32)[Idx_Cnt_T_u08];
        }
        Rtn_Cnt_T_u08 = (uint8)XCPIF_CMDOK_CNT_U08;
    }
    else
    {
        Rtn_Cnt_T_u08 = (uint8)XCPIF_CMDDENIED_CNT_U08;
    }

    return(Rtn_Cnt_T_u08);
}

#if( XCP_CALIBRATION == STD_ON )
/**********************************************************************************************************************
* Name:         XcpAppl_CalibrationWrite
*
* Description:  Copy n bytes from Src to Dst. This function checks to make sure the address selected as write access
*               and returns an error in the case there is no access or the value is out of range.
*
* Inputs:       Dst - Pointer to target to copy data to.
*               Src - Pointer to source to copy data from.
*               Size - Length of data to copy.
*
* Outputs:      uint8 - Returns XCPIF_CMDOK_CNT_U08 on success or XCPIF_CMDDENIED_CNT_U08 on error.
*
* Usage Notes:  This XCP callout function is a synchronous, non-reentrant function. More details are described below.
*                -- A maximum of 255 Bytes can be copied at once.
**********************************************************************************************************************/
FUNC(uint8, XCP_CODE) XcpAppl_CalibrationWrite( VAR(Xcp_AddressPtrType, AUTOMATIC) Dst,
                                                P2CONST(uint8, AUTOMATIC, XCP_APPL_VAR) Src,
                                                VAR(uint8, AUTOMATIC) Size )
{
    VAR(uint8, AUTOMATIC) Rtn_Cnt_T_u08 = (uint8)XCPIF_CMDOK_CNT_U08;
    VAR(Std_ReturnType, AUTOMATIC) MpgAdrRes_Cnt_T_u08;
    VAR(uint32, AUTOMATIC) CorrAdr_Cnt_T_u32 = 0U;
    VAR(MfgEnaSt1, AUTOMATIC) MfgEnaSt_T_Cnt;

    (void)Rte_Read_MfgEnaSt_Val(&MfgEnaSt_T_Cnt);

    #if(STD_ON == FLTINJENA)
    /* XcpCalChgReq is not called when fault injection is enabled */
    if( (MfgEnaSt_T_Cnt != MFGENAST_PRDNMOD) )
    #else
    if( (E_OK == Rte_Call_XcpCalChgReq_Oper()) && (MfgEnaSt_T_Cnt != MFGENAST_PRDNMOD) )
    #endif
    {
        /* If the write request is within the range of Flash, the OnlineTunRamAdrMpg function will update the address, 
         * to the RAM equivalent provided that segment is active in online calibration. If the write request is in 
         * RAM, the function will also check to ensure it is within a valid range.*/
        MpgAdrRes_Cnt_T_u08 = Rte_Call_OnlineTunRamAdrMpg_Oper((uint32)Dst, &CorrAdr_Cnt_T_u32, ADRMPGREQTYP_WR);
        if (MpgAdrRes_Cnt_T_u08 == E_OK)
        {
            /* This call is a trusted function, therefore the address must be checked and validated by OnlineTunRamAdrMpg_Oper
             * before a call can be made */
            Call_XcpAppl_CalibrationWriteTrustd((Xcp_AddressPtrType)CorrAdr_Cnt_T_u32, Src, Size);
        }
        else
        {
            Rtn_Cnt_T_u08 = (uint8)XCPIF_CMDDENIED_CNT_U08;
        }
    }
    else
    {
        Rtn_Cnt_T_u08 = (uint8)XCPIF_CMDDENIED_CNT_U08;
    }

    return (Rtn_Cnt_T_u08);
}

/**********************************************************************************************************************
* Name:         XcpAppl_CalibrationWriteTrustd
*
* Description:  Trusted function call to write the data to the provided destination address. The address is checked
*               from XcpAppl_CalibrationWrite. XcpAppl_CalibrationWrite also calls this function. 
*
* Inputs:       Dst - Pointer to target to copy data to.
*               Src - Pointer to source to copy data from.
*               Size - Length of data to copy.
*
* Outputs:      uint8 - Always returns XCPIF_CMDOK_CNT_U08.
*
* Usage Notes:  This XCP callout function is a synchronous, non-reentrant function. More details are described below.
*                -- A maximum of 255 Bytes can be copied at once.
*                -- Optimizations are possible depending on the platform used:
*                -- Shall only be called by XcpAppl_CalibrationWrite.
**********************************************************************************************************************/
FUNC(uint8, XCP_CODE) XcpAppl_CalibrationWriteTrustd( VAR(Xcp_AddressPtrType, AUTOMATIC) Dst,
                                                P2CONST(uint8, AUTOMATIC, XCP_APPL_VAR) Src,
                                                VAR(uint8, AUTOMATIC) Size )
{
    /* 8-Bit Read Acces: Copy the bytes from the source to the destiniation via the mem copy function */
    XcpAppl_MemCpy((uint8 *)Dst, Src, Size);
    
    /* MemCpy doesn't provide a response so assume command is OK */
    return (uint8)XCPIF_CMDOK_CNT_U08;
}
#endif

#if !defined ( XcpAppl_GetPointer )
/**********************************************************************************************************************
* Name:         XcpAppl_GetPointer
*
* Description:  Convert XCP address to platform address.
*
* Inputs:       XcpChannel - The channel the service is triggered from.
*               AddrExt - The XCP address extension.
*               Addr - The XCP address.
*
* Outputs:      Xcp_AddressPtrType - The converted platform address.
*
* Usage Notes:  This XCP callout function is a synchronous, non-reentrant function.
**********************************************************************************************************************/
extern FUNC(Xcp_AddressPtrType, XCP_CODE) XcpAppl_GetPointer( VAR(Xcp_ChannelType, AUTOMATIC) XcpChannel,
                                                              VAR(uint8, AUTOMATIC) AddrExt,
                                                              CONST(Xcp_AddressPtrType, AUTOMATIC) Addr )
{
    VAR(Xcp_AddressPtrType, AUTOMATIC) RtnAddr_Cnt_T_u32;
    RtnAddr_Cnt_T_u32 = Addr;

    return RtnAddr_Cnt_T_u32;
}
#endif

#if( XCP_READ_PROTECTION == STD_ON )
/**********************************************************************************************************************
* Name:         XcpAppl_CheckReadAccess
*
* Description:  Checks if memory range is valid for read/CRC access.
*
* Inputs:       XcpChannel - The channel the service is triggered from.
*               Address - The address of the memory range.
*               Size - The size of the memory range.
*
* Outputs:      XCPIF_CMDOK_CNT_U08 - Access is granted.
*               XCPIF_CMDDENIED_CNT_U08 - Access is denied.
*
* Usage Notes:  This XCP callout function is a synchronous, non-reentrant function. This is available only 
*               if XCP_READ_PROTECTION is enabled.
**********************************************************************************************************************/
extern FUNC(uint8, XCP_CODE) XcpAppl_CheckReadAccess( VAR(Xcp_ChannelType, AUTOMATIC) XcpChannel, 
                                                      VAR(Xcp_AddressPtrType, AUTOMATIC) Address,
                                                      VAR(uint32, AUTOMATIC) Size )
{
    /* TODO: Check if any requirements are needed for read access */
    return XCPIF_CMDOK_CNT_U08;
}
#endif

#if( XCP_CHECKSUM == STD_ON ) && ( XCP_CUSTOM_CRC == STD_ON )
/**********************************************************************************************************************
* Name:         XcpAppl_CalculateChecksum
*
* Description:  Calculates checksum over memory range.
*
* Inputs:       MemArea - Pointer to memory area to create checksum from.
*               Result - Result string, sent as response.
*               Length - The size of the memory area.
*
* Outputs:      XCPIF_CMDOK_CNT_U08 - Access is granted.
*               XCPIF_CMDPND_CNT_U08 - Pending response, triggered by call of Xcp_SendCrm.
*               XCPIF_CMDDENIED_CNT_U08 - Access is denied. 
*
* Usage Notes:  This XCP callout function is a asynchronous, non-reentrant function. This is available 
*               only if XCP_CHECKSUM and XCP_CUSTOM_CRC is enabled.
**********************************************************************************************************************/
FUNC(uint8, XCP_CODE) XcpAppl_CalculateChecksum( P2CONST(uint8, AUTOMATIC, XCP_APPL_VAR) MemArea, 
                                                 P2VAR(uint8, AUTOMATIC, XCP_VAR_NOINIT) Result, 
                                                 VAR(uint32, AUTOMATIC) Length )
{
    /* TODO: Determine what type of checksum if any is required */
    #error "XCP Checksum/CRC is not available in this version of XcpIf."

    return XCPIF_CMDOK_CNT_U08;
}
#endif

#if( XCP_OPEN_COMMAND_IF == STD_ON )
/**********************************************************************************************************************
* Name:         XcpAppl_OpenCmdIf
*
* Description:  User specific command handler.
*
* Inputs:       XcpChannel - Related XCP channel.
*               Cmd - Pointer to command string.
*               Response - Pointer to response string.
*               Length - Pointer to response length.
*
* Outputs:      XCPIF_CMDOK_CNT_U08 - Access is granted.
*               XCP_CMD_UNKNOWN - Command not accepted.
*               XCPIF_CMDPND_CNT_U08 - Pending response, triggered by call of Xcp_SendCrm. 
*
* Usage Notes:  This XCP callout function is a synchronous, non-reentrant function. This is available 
*               only if XCP_OPEN_COMMAND_IF is enabled.
**********************************************************************************************************************/
FUNC(uint8, XCP_CODE) XcpAppl_OpenCmdIf( VAR(Xcp_ChannelType, AUTOMATIC) XcpChannel,
                                         P2CONST(uint8, AUTOMATIC, XCP_APPL_VAR) Cmd,
                                         P2VAR(uint8, AUTOMATIC, XCP_VAR_NOINIT) Response,
                                         P2VAR(uint8, AUTOMATIC, XCP_VAR_NOINIT) Length )
{
    VAR(uint8, AUTOMATIC) Rtn_Cnt_T_u08;

    switch(Cmd[0])
    {
        case GETSEGINFO_CNT_U08:
            /*  XCP Service 0xE8: GET_SEGMENT_INFO */
            (void)Rte_Call_GetSegInfoReq_Oper(Cmd[1], Cmd[2], Cmd[3], Cmd[4], Response, Length, &Rtn_Cnt_T_u08);
        break;
        case GETPAGEPROCRINFO_CNT_U08:
            /* XCP Service 0xE9: GET_PAG_PROCESSOR_INFO */
            /* Service returns the number of available segments and the page properties */

            *Length = 3U;
            Response[0] = 0xFFU;
            Response[1] = XCPIF_MAXCALSEG_CNT_U08;
            Response[2] = 0U; /* Hard coded 0 since FREEZE mode is currently not supported */
            Rtn_Cnt_T_u08 = (uint8)XCPIF_CMDOK_CNT_U08;
        break;
        default:
            Rtn_Cnt_T_u08 = (uint8)XCPIF_CMDDENIED_CNT_U08;
        break;
    }

    return(Rtn_Cnt_T_u08);
}
#endif

# if( XCP_SEED_KEY == STD_ON )
/**********************************************************************************************************************
* Name:         XcpAppl_GetSeed
*
* Description:  Generates a seed to unlock XCP access.
*
* Inputs:       Resource - Resource to unlock can be one or more of the following values: 
*                            XCP_RM_CAL_PAG         0x01U
*                            XCP_RM_DAQ             0x04U
*                            XCP_RM_STIM            0x08U
*                            XCP_RM_PGM             0x10U
*                            XCP_RM_ALL_RESOURCES   0x1DU
*               Seed - Pointer to the generated seed.
*
* Outputs:      SeedLen_Cnt_T_u08 - The length of the seed.
*
* Usage Notes:  This XCP callout function is a synchronous, non-reentrant function. This is available 
*               only if XCP_SEED_KEY is enabled.
**********************************************************************************************************************/
FUNC(uint8, XCP_CODE) XcpAppl_GetSeed( CONST(uint8, AUTOMATIC) Resource, P2VAR(uint8, AUTOMATIC, XCP_APPL_DATA) Seed )
{
    VAR(uint8, AUTOMATIC) SeedLen_Cnt_T_u08 = 0U;

    /* TODO: Add for future security features, or now return a compiler error if enabled to notifiy integrator. */
    #error "XCP Seed/Key is not available in this version of XcpIf."

    return SeedLen_Cnt_T_u08;
}

/**********************************************************************************************************************
* Name:         XcpAppl_Unlock
*
* Description:  Checks if the key fits to the previously requested seed and indicates which resource is unlocked.
*
* Inputs:       Key - Pointer to the key.
*               Length - Length of the key.
*
* Outputs:      Rtn_Cnt_T_u08 - Indicates the resource which is unlocked. 
*                               0U - The key was not valid (no resource is unlocked)
*                               XCP_RM_CAL_PAG (0x01U) - The calibration page resource is unlocked.
*                               XCP_RM_DAQ (0x04U) - The data acquisition resource is unlocked.
*                               XCP_RM_STIM (0x08U) - The data stimulation resource is unlocked.
*                               XCP_RM_PGM (0x10U) - The programming resource is unlocked.
*                               XCP_RM_ALL_RESOURCES (0x1DU) - All resources are unlocked.
*
* Usage Notes:  This XCP callout function is a synchronous, non-reentrant function. This is available 
*               only if XCP_SEED_KEY is enabled.
**********************************************************************************************************************/
FUNC(uint8, XCP_CODE) XcpAppl_Unlock( P2CONST(uint8, AUTOMATIC, XCP_APPL_DATA) Key, 
                                      CONST(uint8, AUTOMATIC) Length )
{
    VAR(uint8, AUTOMATIC) Rtn_Cnt_T_u08 = 0U;

    /* TODO: Add for future security features, or now return a compiler error if enabled to notifiy integrator. */
    #error "XCP Seed/Key is not available in this version of XcpIf."
    return Rtn_Cnt_T_u08;
}
# endif

# if( XCP_CALIBRATION_PAGE == STD_ON )
/**********************************************************************************************************************
* Name:         XcpAppl_SetCalPage
*
* Description:  Set active calibration page.
*
* Inputs:       Segment - The segment of the page. 
*               Page - The working page.
*               Mode - The requested mode for the working page.
*
* Outputs:      Rtn_Cnt_T_u08 - The return is one of the following values: 
*                                  XCPIF_CMDOK_CNT_U08 - Operation completed successfully.
*                                  XCPIF_CMDPND_CNT_U08 - Command execution is pending, call XcpSendCrm() when it is finished.
*                                  CRC_OUT_OF_RANGE - Segement check failed.
*                                  CRC_PAGE_NOT_VALID - Page check failed.
*                                  CRC_PAGE_MODE_NOT_VALID - Mode check failed.
*
* Usage Notes:  This XCP callout function is a synchronous, non-reentrant function. This is available 
*               only if XCP_CALIBRATION_PAGE is enabled.
**********************************************************************************************************************/
FUNC(uint8, XCP_CODE) XcpAppl_SetCalPage( VAR(uint8, AUTOMATIC) Segment, 
                                          VAR(uint8, AUTOMATIC) Page, 
                                          VAR(uint8, AUTOMATIC) Mode )
{
    VAR(uint8, AUTOMATIC) DataPage_Cnt_T_u08;
    VAR(uint8, AUTOMATIC) Rtn_Cnt_T_u08;
    VAR(NtSetCalPageTyp, AUTOMATIC) Prm_Cnt_T_str;

    if(Segment < XCPIF_MAXCALSEG_CNT_U08)
    {
        /* Check the range for the Mod argument. CANape sends a range of 0x80-0x83, while other tools do not use the
         * bit 7 for all access */
        if( ( (uint8)XCPIF_ONLINECALXCPANDECUACS_CNT_U08 >= Mode ) ||
            ( ( ((uint8)XCPIF_ONLINECALALLACS_CNT_U08 | (uint8)XCPIF_ONLINECALXCPANDECUACS_CNT_U08) >= Mode ) && 
              ( Mode >= (uint8)XCPIF_ONLINECALALLACS_CNT_U08 ) ) )
        {
            Prm_Cnt_T_str.Seg_u08 = Segment;
            Prm_Cnt_T_str.Mod_u08 = Mode;
            Prm_Cnt_T_str.Page_u08 = Page;
            if( XCPIF_XCPOSAPPL_CNT_U08 == GetApplicationID() )
            {
                (void)Rte_Call_SetCalPageReq_Oper(Segment, Mode, Page);
            }
            else
            {
                 (void)Os_CallNonTrustedFunction((Os_NonTrustedFunctionIndexType)NtWrapS_Rte_Call_SetCalPageReq_Oper, &Prm_Cnt_T_str);
            }
            
            /* Verify the cal page change was successful */
            (void)Rte_Call_GetCalPageReq_Oper(Segment, Mode, &DataPage_Cnt_T_u08, &Rtn_Cnt_T_u08);
            
            if( ((uint8)XCPIF_CMDOK_CNT_U08 == Rtn_Cnt_T_u08) && (Page != DataPage_Cnt_T_u08) )
            {
                Rtn_Cnt_T_u08 = (uint8)XCPIF_RTNPAGENOTVLD_CNT_U08;
            }
        }
        else
        {
            Rtn_Cnt_T_u08 = (uint8)XCPIF_RTNPAGENOTVLD_CNT_U08;
        }
    }
    else
    {
        Rtn_Cnt_T_u08 = (uint8)XCPIF_RTNSEGNOTVLD_CNT_U08;
    }
    
    if(Rtn_Cnt_T_u08 == (uint8)XCPIF_CMDOK_CNT_U08)
    {
        /* This return is evaluated by the XCP driver's error check marco. Which is if it is anything other 
         * than 0, an error is returned. Since XCPIF_CMDOK_CNT_U08 is defined as 1, hard coding this return to 0 to provide 
         * a positive response */
        Rtn_Cnt_T_u08 = 0U;
    }

    return Rtn_Cnt_T_u08;
}

/**********************************************************************************************************************
* Name:         XcpAppl_SetCalPage
*
* Description:  Get active calibration page.
*
* Inputs:       Segment - The segment of the page. 
*               Mode - The requested mode for the working page.
*
* Outputs:      DataPage_Cnt_T_u08 - The return is the currently active page for the mode requested.
*
* Usage Notes:  This XCP callout function is a synchronous, non-reentrant function. This is available 
*               only if XCP_CALIBRATION_PAGE is enabled.
**********************************************************************************************************************/
extern FUNC(uint8, XCP_CODE) XcpAppl_GetCalPage( VAR(uint8, AUTOMATIC) Segment, 
                                                 VAR(uint8, AUTOMATIC) Mode )
{
    VAR(uint8, AUTOMATIC) DataPage_Cnt_T_u08;
    VAR(uint8, AUTOMATIC) TmpCnt_T_u08;
    VAR(uint8, AUTOMATIC) Rtn_Cnt_T_u08;

    /* Verify segment is within range */
    if(Segment < XCPIF_MAXCALSEG_CNT_U08)
    {
        /* Remove bit 7 and any non-supported bits if sent as it is not required for this function */
        TmpCnt_T_u08 = Mode & (uint8)XCPIF_ONLINECALXCPANDECUACS_CNT_U08;
        
        /* Mode can only be ECU access or XCP access, but not both according to the XCP specifications */
        if( ((uint8)XCPIF_ONLINECALECUACS_CNT_U08 == TmpCnt_T_u08) || ((uint8)XCPIF_ONLINECALXCPACS_CNT_U08 == TmpCnt_T_u08) )
        {
            (void)Rte_Call_GetCalPageReq_Oper(Segment, Mode, &DataPage_Cnt_T_u08, &Rtn_Cnt_T_u08);
        }
        else
        {
            Rtn_Cnt_T_u08 = (uint8)XCPIF_RTNPAGEMODNOTVLD_CNT_U08;
        }
    }
    else
    {
        Rtn_Cnt_T_u08 = (uint8)XCPIF_RTNSEGNOTVLD_CNT_U08;
    }
    
    if(Rtn_Cnt_T_u08 != (uint8)XCPIF_CMDOK_CNT_U08)
    {
        DataPage_Cnt_T_u08 = 0U;
    }

    return (DataPage_Cnt_T_u08);
}
# endif

#if( XCP_COPY_CAL_PAGE == STD_ON )
/**********************************************************************************************************************
* Name:         XcpAppl_CopyCalPage
*
* Description:  Get active calibration page.
*
* Inputs:       SrcSeg - Source segment to copy from.
*               SrcPage - Source page to copy from.
*               DestSeg - Destination segment to copy to.
*               DestPage - Destination page to copy to.
*
* Outputs:      Rtn_Cnt_T_u08 - The return from the function will have one of the following values:
*                 XCPIF_CMDOK_CNT_U08            Operation completed successfully.
*                 XCPIF_CMDPND_CNT_U08           Command execution is pending, call XcpSendCrm() when it is finished.
*                 XCPIF_RTNPAGENOTVLD_CNT_U08    Page check failed
*                 XCPIF_RTNSEGNOTVLD_CNT_U08     Segment check failed
*                 XCPIF_RTNWRPROTD_CNT_U08       Destination page is write protected
*
* Usage Notes:  This XCP callout function is a asynchronous, non-reentrant function. This is available 
*               only if XCP_COPY_CAL_PAGE is enabled.
**********************************************************************************************************************/
FUNC(uint8, XCP_CODE) XcpAppl_CopyCalPage( VAR(uint8, AUTOMATIC) SrcSeg, VAR(uint8, AUTOMATIC) SrcPage, 
                                           VAR(uint8, AUTOMATIC) DestSeg,VAR(uint8, AUTOMATIC) DestPage )
{
    VAR(uint8, AUTOMATIC) Rtn_Cnt_T_u08 = (uint8)XCPIF_CMDDENIED_CNT_U08;
    VAR(uint8, AUTOMATIC) PageMod_Cnt_T_u08;
    VAR(NtCopyCalPageTyp, AUTOMATIC) Prm_Cnt_T_str;
    
    /* Ensure requested segment is valid */
    if( (SrcSeg == DestSeg) && (SrcSeg < XCPIF_MAXCALSEG_CNT_U08) )
    {
        /* Ensure the requested page mode is valid */
        if( (SrcPage == XCPIF_FLSPAGE_CNT_U08) && (DestPage == XCPIF_RAMPAGE_CNT_U08) )
        {
            /* In order for the command to be accepted, ECU access must be on the flash page, or page 0 */
            (void)Rte_Call_GetCalPageReq_Oper(DestSeg, (uint8)XCPIF_ONLINECALECUACS_CNT_U08, &PageMod_Cnt_T_u08, &Rtn_Cnt_T_u08);
            
            if( (XCPIF_FLSPAGE_CNT_U08 == PageMod_Cnt_T_u08 ) && ((uint8)XCP_CMD_OK == Rtn_Cnt_T_u08) )
            {
            if( XCPIF_XCPOSAPPL_CNT_U08 == GetApplicationID() )
            {
                (void)Rte_Call_CopyCalPageReq_Oper(DestSeg);
            }
            else
            {
                Prm_Cnt_T_str.Seg_u08 = DestSeg;
                (void)Os_CallNonTrustedFunction((Os_NonTrustedFunctionIndexType)NtWrapS_Rte_Call_CopyCalPageReq_Oper, &Prm_Cnt_T_str);
            }
		     
                
                /* Return is hard coded 0. XCP_CMD_OK is defined as 1 in XcpProf.h, yet the OK condition in the XCP 
                 * documentation is a 0. If the non-trusted call fails, the user would have to look at the online 
                 * calibration table status in TunSelnMngt */
                Rtn_Cnt_T_u08 = 0U;
            }
            else
            {
                /* Return the error returned from GetCalPageReq_Oper() */
                Rtn_Cnt_T_u08 = Rtn_Cnt_T_u08;
            }
        }
        else
        {
            /* Source of destination page are not correctly passed */
            Rtn_Cnt_T_u08 = (uint8)XCPIF_RTNPAGENOTVLD_CNT_U08;
        }
    }
    else
    {
        /* Segments do not match or are out of range */
        Rtn_Cnt_T_u08 = (uint8)XCPIF_RTNSEGNOTVLD_CNT_U08;
    }
    
    return(Rtn_Cnt_T_u08);
}
#endif

#if( XCP_USER_COMMAND == STD_ON )
/**********************************************************************************************************************
* Name:         XcpAppl_CopyCalPage
*
* Description:  Get active calibration page.
*
* Inputs:       Cmd - Pointer to command string.
*
* Outputs:      Rtn_Cnt_T_u08 - The return from the function will have one of the following values:
*                 XCPIF_CMDOK_CNT_U08        Operation completed successfully.
*                 XCPIF_CMDPND_CNT_U08       Command execution is pending, call XcpSendCrm() when it is finished.
*                 XCPIF_CMDSYNTAX_CNT_U08    Command not accepted.
*
* Usage Notes:  This XCP callout function is a asynchronous, non-reentrant function. This is available 
*               only if XCP_USER_COMMAND is enabled.
**********************************************************************************************************************/
FUNC(uint8, XCP_CODE) XcpAppl_UserService( P2CONST(uint8, AUTOMATIC, XCP_APPL_VAR) Cmd )
{
    VAR(uint8, AUTOMATIC) Rtn_Cnt_T_u08;
    VAR(uint16, AUTOMATIC) UsrCmd_Cnt_T_u16;
    
    if(APPLXCPUSRSRV_CNT_U08 == Cmd[0])
    {
        UsrCmd_Cnt_T_u16 = (uint16)((uint16)((uint16)(Cmd[1]) << 8U) | Cmd[2]);
        switch(UsrCmd_Cnt_T_u16)
        {
            case ACTVTUNSTSREQ_CNT_U16:
                ActvTunStsReq_Oper( (uint8 *)&(XCPIF_RESPBUF_CNT_U08(1)), (uint8 *)&(XCPIF_RESPBUF_CNT_U08(2)), 
                                    (uint8 *)&(XCPIF_RESPBUF_CNT_U08(3)), (uint8 *)&(XCPIF_RESPBUF_CNT_U08(4)), 
                                    (uint8 *)&(XCPIF_RESPBUF_CNT_U08(5)), (uint8 *)&(XCPIF_RESPBUF_CNT_U08(6)) );
                XCPIF_RESPBUFLEN_CNT_U08 = 7U;
                Rtn_Cnt_T_u08 = (uint8)XCPIF_CMDOK_CNT_U08;
            break;
            default:
                Rtn_Cnt_T_u08 = (uint8)XCPIF_CMDSYNTAX_CNT_U08;
            break;
        }
    }
    else
    {
        Rtn_Cnt_T_u08 = (uint8)XCPIF_CMDSYNTAX_CNT_U08;
    }
    
    return(Rtn_Cnt_T_u08);
}
 #endif

/**********************************************************************************************************************
* Name:         XcpAppl_ConStateNotification
*
* Description:  Call back function to notifiy the application of connection state changes.
*
* Inputs:       XcpChannel - XCP Channel (0 for single channel applications)
*               ConnectionState - Current state of the XCP connection.
*
* Outputs:      N/A
*
* Usage Notes:  None, presently not required by design but is required by the XCP driver.
**********************************************************************************************************************/
FUNC(void, XCP_CODE) XcpAppl_ConStateNotification( Xcp_ChannelType XcpChannel, uint8 ConnectionState )
{
    /* #10 Remember the new connection state (XCP_CON_STATE_DISCONNECTED, XCP_CON_STATE_RESUME or XCP_CON_STATE_CONNECTED)
     *     of the specified XcpChannel. */

    /* TODO: Required due to XCP settings, however, not used functionally for anything for this version of the design
    and thus intentionally left blank. */
    return;
}
 
 /**********************************************************************************************************************
* Name:        NONTRUSTED_NtWrapS_TunSelnMngt_CopyCalPageReq_Oper
*
* Description: Non-trusted function call for CopyCalPageReq_Oper
*
* Inputs:      FunctionIndex - Non-trusted function index
*              FunctionParams - Pointer to parameter structure 
*
* Outputs:      None
*
* Usage Notes: 
**********************************************************************************************************************/
FUNC(void, CDD_NvMProxy_CODE) NONTRUSTED_NtWrapS_Rte_Call_CopyCalPageReq_Oper( Os_NonTrustedFunctionIndexType FunctionIndex, 
                                                                               Os_NonTrustedFunctionParameterRefType FunctionParams)
{
    (void)Rte_Call_CopyCalPageReq_Oper( ((NtCopyCalPageTyp*)FunctionParams)->Seg_u08 );
    return;
}

/**********************************************************************************************************************
* Name:        NONTRUSTED_NtWrapS_Rte_Call_SetCalPageReq_Oper
*
* Description: Non-trusted function call for SetCalPageReq_Oper
*
* Inputs:      FunctionIndex - Non-trusted function index
*              FunctionParams - Pointer to parameter structure 
*
* Outputs:      None
*
* Usage Notes: 
**********************************************************************************************************************/
FUNC(void, CDD_NvMProxy_CODE) NONTRUSTED_NtWrapS_Rte_Call_SetCalPageReq_Oper( Os_NonTrustedFunctionIndexType FunctionIndex, 
                                                                              Os_NonTrustedFunctionParameterRefType FunctionParams)
{
    (void)Rte_Call_SetCalPageReq_Oper( ((NtSetCalPageTyp*)FunctionParams)->Seg_u08, ((NtSetCalPageTyp*)FunctionParams)->Mod_u08,
                                       ((NtSetCalPageTyp*)FunctionParams)->Page_u08 );
    return;
}
/**********************************************************************************************************************
* Name:        NONTRUSTED_NtWrapS_Xcp_Event
*
* Description: Non-trusted function call for Xcp_Event
*
* Inputs:      FunctionIndex - Non-trusted function index
*              FunctionParams - Pointer to parameter structure 
*
* Outputs:      None
*
* Usage Notes: 
**********************************************************************************************************************/
extern FUNC(void, OS_NTWRAPS_XCP_EVENT_CODE) NONTRUSTED_NtWrapS_Xcp_Event( Os_NonTrustedFunctionIndexType FunctionIndex,
                                                                           Os_NonTrustedFunctionParameterRefType FunctionParams)
{
    (void)Xcp_Event( ((NtXcpEveTyp*)FunctionParams)->XcpEve_u16 );
    return;
}
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of function definition area >>              DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of removed code area >>                   DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of removed code area >>                     DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
