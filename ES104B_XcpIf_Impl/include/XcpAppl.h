/**********************************************************************************************************************
* Copyright 2018 Nxtr
* Nxtr Confidential
*
* Module File Name:   XcpAppl.h
* Module Description: Header file for XCP Application interface. This is required by Xcp.h which should be included
*                     in the XcpIf header configuration.
* Project           : CBD
* Author            : Kevin Smith
***********************************************************************************************************************
* Version Control:
* %version:          2 %
* %derived_by:       cz7lt6 %
*----------------------------------------------------------------------------------------------------------------------
* Date      Rev      Author         Change Description                                                           SCR #
* -------   -------  --------  ---------------------------------------------------------------------------     --------
* 01/19/18  1        KJS       Initial Version                                                                EA4#17610
* 05/18/18  2        KJS       Updated protection headers                                                     EA4#24014
**********************************************************************************************************************/

/******************************************* Multiple Include Protection *********************************************/
#ifndef XCPAPPL_H
#define XCPAPPL_H

#include "Std_Types.h"

/************************************************ Embedded Constants *************************************************/

/******************************************** File Level Rule Deviations *********************************************/

/****************************************************** Macros *******************************************************/

/*********************************************** Exported Declarations ***********************************************/

#if ( XCP_DAQ_TIMESTAMP_SIZE > 0U )
extern FUNC(Xcp_TimestampType, XCP_CODE) XcpAppl_GetTimestamp(void);
#endif

#if !defined ( XcpAppl_MemCpy )
extern FUNC(void, XCP_CODE) XcpAppl_MemCpy( P2VAR(uint8, AUTOMATIC, AUTOMATIC) Dst,
                                            P2CONST(uint8, AUTOMATIC, AUTOMATIC) Src,
                                            VAR(uint16, AUTOMATIC) Size );
#endif

extern FUNC(uint8, XCP_CODE) XcpAppl_MeasurementRead( P2VAR(uint8, AUTOMATIC, XCP_APPL_VAR) Dst,
                                                      VAR(Xcp_AddressPtrType, AUTOMATIC) Src,
                                                      VAR(uint8, AUTOMATIC) Size );

#if( XCP_CALIBRATION == STD_ON )
extern FUNC(uint8, XCP_CODE) XcpAppl_CalibrationWrite( VAR(Xcp_AddressPtrType, AUTOMATIC) Dst,
                                                       P2CONST(uint8, AUTOMATIC, XCP_APPL_VAR) Src,
                                                       VAR(uint8, AUTOMATIC) Size );
#endif

#if !defined ( XcpAppl_GetPointer )
extern FUNC(Xcp_AddressPtrType, XCP_CODE) XcpAppl_GetPointer( VAR(Xcp_ChannelType, AUTOMATIC) XcpChannel,
                                                              VAR(uint8, AUTOMATIC) AddrExt,
                                                              CONST(Xcp_AddressPtrType, AUTOMATIC) Addr );
#endif

#if( XCP_READ_PROTECTION == STD_ON )
extern FUNC(uint8, XCP_CODE) XcpAppl_CheckReadAccess( VAR(Xcp_ChannelType, AUTOMATIC) XcpChannel, 
                                                      VAR(Xcp_AddressPtrType, AUTOMATIC) Address,
                                                      VAR(uint32, AUTOMATIC) Size );
#endif

#if( XCP_CHECKSUM == STD_ON ) && ( XCP_CUSTOM_CRC == STD_ON )
extern FUNC(uint8, XCP_CODE) XcpAppl_CalculateChecksum( P2CONST(uint8, AUTOMATIC, XCP_APPL_VAR) MemArea, 
                                                        P2VAR(uint8, AUTOMATIC, XCP_VAR_NOINIT) Result, 
                                                        VAR(uint32, AUTOMATIC) Length );
#endif

#if( XCP_OPEN_COMMAND_IF == STD_ON )
extern FUNC(uint8, XCP_CODE) XcpAppl_OpenCmdIf( VAR(Xcp_ChannelType, AUTOMATIC) XcpChannel,
                                                P2CONST(uint8, AUTOMATIC, XCP_APPL_VAR) Cmd,
                                                P2VAR(uint8, AUTOMATIC, XCP_VAR_NOINIT) Response,
                                                P2VAR(uint8, AUTOMATIC, XCP_VAR_NOINIT) Length );
#endif

#if( XCP_SEED_KEY == STD_ON )
extern FUNC(uint8, XCP_CODE) XcpAppl_GetSeed( CONST(uint8, AUTOMATIC) Resource,
                                              P2VAR(uint8, AUTOMATIC, XCP_APPL_DATA) Seed );

extern FUNC(uint8, XCP_CODE) XcpAppl_Unlock( P2CONST(uint8, AUTOMATIC, XCP_APPL_DATA) Key,
                                             CONST(uint8, AUTOMATIC) Length );
#endif

#if( XCP_CALIBRATION_PAGE == STD_ON )
extern FUNC(uint8, XCP_CODE) XcpAppl_SetCalPage( VAR(uint8, AUTOMATIC) Segment, 
                                                 VAR(uint8, AUTOMATIC) Page, 
                                                 VAR(uint8, AUTOMATIC) Mode );

extern FUNC(uint8, XCP_CODE) XcpAppl_GetCalPage( VAR(uint8, AUTOMATIC) Segment, 
                                                 VAR(uint8, AUTOMATIC) Mode );
#endif

#if( XCP_COPY_CAL_PAGE == STD_ON )
extern FUNC(uint8, XCP_CODE) XcpAppl_CopyCalPage( VAR(uint8, AUTOMATIC) SrcSeg, VAR(uint8, AUTOMATIC) SrcPage, 
                                                  VAR(uint8, AUTOMATIC) DestSeg, VAR(uint8, AUTOMATIC) DestPage );
#endif

#if( XCP_USER_COMMAND == STD_ON )
extern FUNC(uint8, XCP_CODE) XcpAppl_UserService( P2CONST(uint8, AUTOMATIC, XCP_APPL_VAR) Cmd );
#endif

extern FUNC(void, XCP_CODE) XcpAppl_ConStateNotification( Xcp_ChannelType XcpChannel, uint8 ConnectionState );

/**************************************** End Of Multiple Include Protection *****************************************/
#endif /* XCPAPPL_H */
