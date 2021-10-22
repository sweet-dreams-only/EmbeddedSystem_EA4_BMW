
/**********************************************************************************************************************
  COPYRIGHT
-----------------------------------------------------------------------------------------------------------------------
  \par      copyright
  \verbatim
  Copyright (c) 2015 by Vctr Informatik GmbH.                                                  All rights reserved.

                This software is copyright protected and proprietary to Vctr Informatik GmbH.
                Vctr Informatik GmbH grants to you only those rights as set out in the license conditions.
                All other rights remain with Vctr Informatik GmbH.
  \endverbatim
-----------------------------------------------------------------------------------------------------------------------
  FILE DESCRIPTION
-----------------------------------------------------------------------------------------------------------------------
  \file  File:  Dcm_Callout_Stubs.c
      Project:  Vector Basic Runtime System for MICROSAR4
       Module:  BrsAsrMain
    Generator:  -

  \brief Description:  File for implementation of DCM callouts.
                       This file is a template only - please implement the callouts according to your needs.
  
  \attention Please note:
    The demo and example programs only show special aspects of the software. With regard to the fact
    that these programs are meant for demonstration purposes only, Vctr Informatik liability shall be
    expressly excluded in cases of ordinary negligence, to the extent admissible by law or statute.
**********************************************************************************************************************/

/**********************************************************************************************************************
  AUTHOR IDENTITY
-----------------------------------------------------------------------------------------------------------------------
  Name                          Initials      Company
-----------------------------------------------------------------------------------------------------------------------
  Benjamin Walter               visbwa        Vctr Informatik GmbH
-----------------------------------------------------------------------------------------------------------------------
  REVISION HISTORY
 ----------------------------------------------------------------------------------------------------------------------
  Version   Date        Author  Description
 ----------------------------------------------------------------------------------------------------------------------
  01.00.00  2015-07-14  visbwa  Initial creation for usage with StartApplication
  02.00.00  2018-03-17  akilan  Updated for flash programming support and NM02C integration             CR EA4#20395
  02.01.00  2018-03-22  akilan  Added wrapper interface for the services that are missed out by NM02C   CR EA4#21810
  03.00.00  2018-03-30  akilan  Changed return value of Dcm_GetProgConditions() to fix "stuck in 
                                bootloader" issue                                                       CR EA4#22216
**********************************************************************************************************************/

/**********************************************************************************************************************
  INCLUDES
**********************************************************************************************************************/
#include "Dcm.h"
#include "Dlog_BootMode.h"

/**********************************************************************************************************************
  LOCAL FUNCTIONS
**********************************************************************************************************************/
# define DCM_START_SEC_CALLOUT_CODE
# include "MemMap.h"


/*********************************************************************************************************************
 * Name:        CmnMfgSrvIfDcmWrpSrvFD40Rd
 * Description: 0xFD42: Vehicle Speed Override - Read Data by Identifier
 * Inputs:      NONE
 * Outputs:     data - DID data
 * Usage Notes: NONE
 *********************************************************************************************************************/
FUNC(Std_ReturnType, DCM_CALLOUT_CODE) CmnMfgSrvIfDcmWrpSrvFD40Rd(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, DCM_VAR_NOINIT) Data) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
    /* Pass data to CmnMfgSrv main function */
    CmnMfgSrv_SrvFD40Rd(Data);
    return E_OK;
}

/*********************************************************************************************************************
 * Name:        CmnMfgSrvIfDcmWrpSrvFD40CtrlRtn
 * Description: 0xFD40 - Manual Torque Command - Return Control
 * Inputs:      NONE
 * Outputs:     NONE
 * Usage Notes: NONE
 *********************************************************************************************************************/
FUNC(Std_ReturnType, DCM_CALLOUT_CODE) CmnMfgSrvIfDcmWrpSrvFD40CtrlRtn(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR_NOINIT) ErrorCode) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
    /* In DCM module its not compatible currently to configure the 2F service DIDs like other DIDs */
  VAR(uint8, AUTOMATIC) TmpData_Cnt_T_u08[1];  
  
  CmnMfgSrv_SrvFD40CtrlRtn( TmpData_Cnt_T_u08);

  return E_OK;
}


/*********************************************************************************************************************
 * Name:        CmnMfgSrvIfDcmWrpSrvFD40CtrlAdj
 * Description: 0xFD40 - Manual Torque Command - Short Term Adjust 
 * Inputs:      Short Term Adjust data
 * Outputs:     NONE
 * Usage Notes: NONE
 *********************************************************************************************************************/
FUNC(Std_ReturnType, DCM_CALLOUT_CODE) CmnMfgSrvIfDcmWrpSrvFD40CtrlAdj(P2CONST(uint8, AUTOMATIC, DCM_VAR_NOINIT) Data, Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR_NOINIT) ErrorCode)/* PRQA S 0850 */ /* MD_MSR_19.8 */
{
    
    /* Pass data to CmnMfgSrv main function */
    CmnMfgSrv_SrvFD40CtrlAdj((P2VAR(uint8, AUTOMATIC, RTE_CMNMFGSRV_APPL_VAR))Data);
    return E_OK;
}

/*********************************************************************************************************************
 * Name:        CmnMfgSrvIfDcmWrpSrvFD41Rd
 * Description: 0xFD42: Vehicle Speed Override - Read Data by Identifier
 * Inputs:      NONE
 * Outputs:     data - DID data
 * Usage Notes: NONE
 *********************************************************************************************************************/
FUNC(Std_ReturnType, DCM_CALLOUT_CODE) CmnMfgSrvIfDcmWrpSrvFD41Rd(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_CMNMFGSRVIF_APPL_VAR) data) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
    /* Pass data to CmnMfgSrv main function */
    CmnMfgSrv_SrvFD41Rd(data);
    return E_OK;
}

/*********************************************************************************************************************
 * Name:        CmnMfgSrvIfDcmWrpSrvFD41CtrlRtn
 * Description: FD41 - Assist Linear Gain Set - Return Control
 * Inputs:      Short Term Adjust data
 * Outputs:     NONE
 * Usage Notes: NONE
 *********************************************************************************************************************/
FUNC(Std_ReturnType, DCM_CALLOUT_CODE) CmnMfgSrvIfDcmWrpSrvFD41CtrlRtn(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_CMNMFGSRVIF_APPL_VAR) ErrorCode) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
    VAR(uint8, AUTOMATIC) TmpData_Cnt_T_u08[1];
    
    /* Pass data to CmnMfgSrv main function */
    CmnMfgSrv_SrvFD41CtrlRtn(TmpData_Cnt_T_u08);
    return E_OK;
}


/*********************************************************************************************************************
 * Name:        CmnMfgSrvIfDcmWrpSrvFD41CtrlAdj
 * Description: FD41 - Assist Linear Gain - Short Term Adjust 
 * Inputs:      Short Term Adjust data
 * Outputs:     NONE
 * Usage Notes: NONE
 *********************************************************************************************************************/
FUNC(Std_ReturnType, DCM_CALLOUT_CODE) CmnMfgSrvIfDcmWrpSrvFD41CtrlAdj(P2CONST(uint8, AUTOMATIC, RTE_CMNMFGSRVIF_APPL_DATA) Data, 
Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_CMNMFGSRVIF_APPL_VAR) ErrorCode) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
    
    /* Pass data to CmnMfgSrv main function */
    CmnMfgSrv_SrvFD41CtrlAdj((P2VAR(uint8, AUTOMATIC, RTE_CMNMFGSRV_APPL_VAR))Data);
    return E_OK;
}



/*********************************************************************************************************************
 * Name:        CmnMfgSrvIfDcmWrpSrvFD42Rd
 * Description: 0xFD42: Vehicle Speed Override - Read Data by Identifier
 * Inputs:      NONE
 * Outputs:     data - DID data
 * Usage Notes: NONE
 *********************************************************************************************************************/
FUNC(Std_ReturnType, DCM_CALLOUT_CODE) CmnMfgSrvIfDcmWrpSrvFD42Rd(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_CMNMFGSRVIF_APPL_VAR) data) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
    /* Pass data to CmnMfgSrv main function */
    CmnMfgSrv_SrvFD42Rd(data);
    return E_OK;
}

/*********************************************************************************************************************
 * Name:        CmnMfgSrvIfDcmWrpSrvFD42CtrlRtn
 * Description: 0xFD42: Vehicle Speed Override Return Control
 * Inputs:      Short Term Adjust data
 * Outputs:     NONE
 * Usage Notes: NONE
 *********************************************************************************************************************/
FUNC(Std_ReturnType, DCM_CALLOUT_CODE) CmnMfgSrvIfDcmWrpSrvFD42CtrlRtn(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_CMNMFGSRVIF_APPL_VAR) ErrorCode) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
    VAR(uint8, AUTOMATIC) TmpData_Cnt_T_u08[1];
    
    /* Pass data to CmnMfgSrv main function */
    CmnMfgSrv_SrvFD42CtrlRtn(TmpData_Cnt_T_u08);
    return E_OK;
}




/*********************************************************************************************************************
 * Name:        CmnMfgSrvIfDcmWrpSrvFD42CtrlAdj
 * Description: 0xFD42: Vehicle Speed Override Short Term Adjust 
 * Inputs:      Short Term Adjust data
 * Outputs:     NONE
 * Usage Notes: NONE
 *********************************************************************************************************************/
FUNC(Std_ReturnType, DCM_CALLOUT_CODE) CmnMfgSrvIfDcmWrpSrvFD42CtrlAdj(P2CONST(uint8, AUTOMATIC, RTE_CMNMFGSRVIF_APPL_DATA) Data, 
Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_CMNMFGSRVIF_APPL_VAR) ErrorCode) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
    
   CmnMfgSrv_SrvFD42CtrlAdj((P2VAR(uint8, AUTOMATIC, RTE_CMNMFGSRV_APPL_VAR))Data);
   
    return E_OK;
}


/**********************************************************************************************************************
 * Name:        CmnMfgSrvIfDcmReadDataIdWrpr_Oper
 * Description: Dcm Wrapper function to perform DID read operations
 * Inputs:      NONE
 * Outputs:     NONE
 * Usage Notes: NONE
 *********************************************************************************************************************/
FUNC(Std_ReturnType, DCM_CALLOUT_CODE) CmnMfgSrvIfDcmReadDataIdWrpr_Oper(uint16 DID, P2VAR(uint8, AUTOMATIC, DCM_VAR_NOINIT) Data, Dcm_OpStatusType OpStatus, P2VAR(uint16, AUTOMATIC, DCM_VAR_NOINIT) DataLength, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR_NOINIT) ErrorCode)
{
    VAR(uint16, AUTOMATIC) DataLen_Cnt_T_u16;
    VAR(uint16, AUTOMATIC) RespDataLen_Cnt_T_u16 = 0u;
    
    /* Assign values that were passed in */
    DataLen_Cnt_T_u16 = *DataLength;
    
    /* Pass data to CmnMfgSrv Main function */
    CmnMfgSrvCmnMfgSrvMaiFct_Oper(0x22U, 0xFFU, DID, Data, DataLen_Cnt_T_u16, &RespDataLen_Cnt_T_u16, ErrorCode);
    *DataLength = RespDataLen_Cnt_T_u16;
	if (*ErrorCode != 0) 
		return E_NOT_OK;
    return E_OK;
}

Std_ReturnType Prog_UDS_DcmDspData_ProgrammingCounter_ReadData(uint8* Data) 
{
	*Data = 0u;
	 return (E_OK);
	
}

FUNC(Std_ReturnType, DCM_CALLOUT_CODE) CmnMfgSrvIf_Srv0xFE88Strt_Stubbed(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR_NOINIT) ErrorCode)
{
	
	return (DCM_E_OK);
	
}

FUNC(Std_ReturnType, DCM_CALLOUT_CODE) CmnMfgSrvIf_Srv0xFE8ARd_Stubbed(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, DCM_VAR_NOINIT) Data)
{
		return (DCM_E_OK);
}
FUNC(Std_ReturnType, DCM_CALLOUT_CODE) CmnMfgSrvIf_Srv0xFE8AWr_Stubbed(P2CONST(uint8, AUTOMATIC, DCM_VAR_NOINIT) Data, Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR_NOINIT)ErrorCode)
{
		return (DCM_E_OK);	
}


FUNC(Std_ReturnType, DCM_CALLOUT_CODE) CmnMfgSrvIf_Srv0xFE89Strt_Stubbed(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR_NOINIT) ErrorCode)
{
	return (DCM_E_OK);
}

FUNC(Std_ReturnType, DCM_CALLOUT_CODE) DcmDsdSidTabFnc_RequestDownload(Dcm_OpStatusType opStatus, Dcm_MsgContextPtrType pMsgContext, Dcm_NegativeResponseCodePtrType ErrorCode)
{
	
}
FUNC(Std_ReturnType, DCM_CALLOUT_CODE) DcmDsdSidTabFnc_TransferData(Dcm_OpStatusType opStatus, Dcm_MsgContextPtrType pMsgContext, Dcm_NegativeResponseCodePtrType ErrorCode)
{
	
}
FUNC(Std_ReturnType, DCM_CALLOUT_CODE) DcmDsdSidTabFnc_RequestTransferExit(Dcm_OpStatusType opStatus, Dcm_MsgContextPtrType pMsgContext, Dcm_NegativeResponseCodePtrType ErrorCode)
{}

/**********************************************************************************************************************
  PART 1 - STATIC PART
   These Callouts are announced within Dcm_Core.h.
   The existence is configuration specific
**********************************************************************************************************************/
FUNC(void, DCM_CALLOUT_CODE) Dcm_Confirmation(Dcm_IdContextType idContext
                                             ,PduIdType dcmRxPduId
                                             ,Dcm_ConfirmationStatusType status)
{
}



# if (DCM_DIAG_JUMPTOFBL_ENABLED   == STD_ON) || \
     (DCM_DIAG_JUMPFROMFBL_ENABLED == STD_ON)
FUNC(Std_ReturnType, DCM_CALLOUT_CODE) Dcm_SetProgConditions(Dcm_ProgConditionsPtrType progConditions)
{
  /* This Callout is called during first call of Dcm_Mainfunction().
     If it returns DCM_E_NOT_OK, a Det-Error would be hit (0x35,0x00,0xf0,0x06) */
  Dlog_BootModeRequestBootloader(DLOG_BMUSER_PROG,TRUE);
	 
  return DCM_E_OK;
}
# endif

# if (DCM_DIAG_JUMPFROMFBL_ENABLED == STD_ON)
FUNC(Dcm_EcuStartModeType, DCM_CALLOUT_CODE) Dcm_GetProgConditions(Dcm_ProgConditionsPtrType progConditions)
{
  return DCM_COLD_START;
}
# endif


/**********************************************************************************************************************
  PART 2 - DYNAMIC PART
   These Callouts are announced within Dcm_Lcfg.h.
   The existence is configuration specific
**********************************************************************************************************************/

FUNC(Std_ReturnType, DCM_CALLOUT_CODE) Dcm_DiagnosticService_0x11_0x42(Dcm_OpStatusType opStatus, Dcm_MsgContextPtrType pMsgContext)
{
  return E_NOT_OK;
}
/**********************************************************************************************************************
  END of User implementation area
**********************************************************************************************************************/
# define DCM_STOP_SEC_CALLOUT_CODE
# include "MemMap.h"
