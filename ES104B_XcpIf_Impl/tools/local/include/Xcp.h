/* Stub for Xcp.h, includes only the items that are required */
#if !defined (XCP_H)
# define XCP_H

/* The following enable/disable the various functions in XcpIf. They are based 
   on the XCP configuration */
#define XCP_DAQ_TIMESTAMP_SIZE  2
#define XCP_CALIBRATION         STD_ON
#define XCP_READ_PROTECTION     STD_ON
#define XCP_CHECKSUM            STD_OFF /* Not supported in this ES104B version */
#define XCP_CUSTOM_CRC          STD_OFF /* Not supported in this ES104B version */
#define XCP_OPEN_COMMAND_IF     STD_ON
#define XCP_SEED_KEY            STD_OFF /* Not supported in this ES104B version */
#define XCP_CALIBRATION_PAGE    STD_ON
#define XCP_COPY_CAL_PAGE       STD_ON
#define XCP_USER_COMMAND        STD_ON

/* Xcp_Cfg.h */
#define XCP_MAX_SEGMENT                      (1u)
#define XCP_MAX_CTO_MAX                      (28U)
#define XCP_NUMBER_OF_CHANNELS               ((1U))

#if( XCP_NUMBER_OF_CHANNELS > 1 )
# define XCP_CHANNEL_IDX (XcpChannel)
#else
# define XCP_CHANNEL_IDX (0u)
#endif

/* From Xcp_Types.h */
typedef uint32 Xcp_AddressPtrType; /*<! An pointer as integer */
typedef uint8 Xcp_ChannelType; /*<! XCP channel index type */

#define XCP_DAQ_TIMESTAMP_OFF                 (0<<0)
#define XCP_DAQ_TIMESTAMP_BYTE                (1<<0)
#define XCP_DAQ_TIMESTAMP_WORD                (2<<0)
#define XCP_DAQ_TIMESTAMP_DWORD               (4<<0)
# if ( XCP_DAQ_TIMESTAMP_SIZE == XCP_DAQ_TIMESTAMP_OFF )
typedef uint8 Xcp_TimestampType; /*<! Timestamp used during DAQ measurement */
# elif ( XCP_DAQ_TIMESTAMP_SIZE == XCP_DAQ_TIMESTAMP_BYTE )
typedef uint8 Xcp_TimestampType; /*<! Timestamp used during DAQ measurement */
# elif ( XCP_DAQ_TIMESTAMP_SIZE == XCP_DAQ_TIMESTAMP_WORD )
typedef uint16 Xcp_TimestampType; /*<! Timestamp used during DAQ measurement */
# elif ( XCP_DAQ_TIMESTAMP_SIZE == XCP_DAQ_TIMESTAMP_DWORD )
typedef uint32 Xcp_TimestampType; /*<! Timestamp used during DAQ measurement */
# else
#  error "Please define a valid timestamp size. Valid sizes are 0, 1, 2 and 4 Bytes"
# endif


typedef union
{ /* PRQA S 0750 */ /* MD_MSR_18.4 */
  uint8     b[XCP_MAX_CTO_MAX];
  uint16    w[XCP_MAX_CTO_MAX/2];
  uint32    l[XCP_MAX_CTO_MAX/4];
} Xcp_AlignedCTOFrameType;

typedef struct
{
#if( XCP_CHECKSUM == STD_ON )
  tXcpChecksumType CheckSum; /*<! The checksum intermediate result */
#endif
#if ( XCP_DAQ == STD_ON )
  Xcp_DaqListType DaqList; /*<! the complete DAQ list information */
  uint16 SessionConfigId; /*<! The session configuration id */
#endif
  /* The following 3 variable are moved here, because they are relevant in Resume Mode */
  uint16 MaxDto; /*<! The currently active MaxDto, dependent on active TL */
  uint8  MaxCto; /*<! The currently active MaxCto, dependent on active TL */
  uint8  ActiveTl; /*<! The currently active TL */
  /* --- The following variables are not relevant for Resume Mode --- */
  Xcp_AlignedCTOFrameType ResponseFrame; /*<! The response frame buffer */
  Xcp_AddressPtrType MTA; /*<! The MTA (memory transfer address) */
#if( XCP_CHECKSUM == STD_ON )
  uint16 CheckSumSize; /*<! The size of the checksum block */
#endif
  uint16 SessionStatus;
  uint8  MTAExtension; /*<! The address extension of the MTA */
  uint8  ResponseFrameLength; /*<! The length of the response frame string */
  uint8  ResponsePending; /*<! true in case a response is pending and triggered asynchronously */
  uint8  ConnectState; /*<! The current connection state */
#if ( XCP_SEED_KEY == STD_ON )
  uint8  ProtectionStatus; /*!< Resource Protection Status */
  uint8  ProtectionStatusInit; /*<! Initial Resource Protection Status */
#endif
#if( (XCP_BLOCK_UPLOAD == STD_ON) || (XCP_BLOCK_DOWNLOAD == STD_ON) )
  uint8  NextDataBlockSize; /*<! The intermediate block size used during block transfer */
#endif
#if( (XCP_SEND_EVENT == STD_ON) || (XCP_SERV_TEXT == STD_ON) )
  Xcp_AlignedCTOFrameType EventFrame;       /*<! EV,SERV Message buffer */
  uint8                   EventFrameLength; /*<! EV,SERV Message length */
#endif
  uint8  SendStatus; /*<! Status variable of transmission, must be last element. */
} Xcp_ChannelStruct;

/* From Xcp.h */
extern VAR(uint8, XCP_VAR_INIT) Xcp_ControlState;

# define kXcp_Control_Disable                 (0x00u)
# define kXcp_Control_Enable                  (0x01u)

/*-------------------------------------------------------------------------*/
/* Command Error Codes */
#define XCP_ERR_CMD_SYNCH                     (0x00u)

#define XCP_ERR_CMD_BUSY                      (0x10u)
#define XCP_ERR_DAQ_ACTIVE                    (0x11u)
#define XCP_ERR_PRM_ACTIVE                    (0x12u)

#define XCP_ERR_CMD_UNKNOWN                   (0x20u)
#define XCP_ERR_CMD_SYNTAX                    (0x21u)
#define XCP_ERR_OUT_OF_RANGE                  (0x22u)
#define XCP_ERR_WRITE_PROTECTED               (0x23u)
#define XCP_ERR_ACCESS_DENIED                 (0x24u)
#define XCP_ERR_ACCESS_LOCKED                 (0x25u)
#define XCP_ERR_PAGE_NOT_VALID                (0x26u)
#define XCP_ERR_PAGE_MODE_NOT_VALID           (0x27u)
#define XCP_ERR_SEGMENT_NOT_VALID             (0x28u)
#define XCP_ERR_SEQUENCE                      (0x29u)
#define XCP_ERR_DAQ_CONFIG                    (0x2Au)

#define XCP_ERR_MEMORY_OVERFLOW               (0x30u)
#define XCP_ERR_GENERIC                       (0x31u)
#define XCP_ERR_VERIFY                        (0x32u)
#define XCP_ERR_RESOURCE_TEMP_NOT_ACCESSIBLE  (0x33u)

/*-------------------------------------------------------------------------*/
/* Command Return Codes */
#define XCP_CRC_CMD_SYNCH                     (0x00u)

#define XCP_CRC_CMD_BUSY                      (0x10u)
#define XCP_CRC_DAQ_ACTIVE                    (0x11u)
#define XCP_CRC_PRM_ACTIVE                    (0x12u)

#define XCP_CRC_CMD_UNKNOWN                   (0x20u)
#define XCP_CRC_CMD_SYNTAX                    (0x21u)
#define XCP_CRC_OUT_OF_RANGE                  (0x22u)
#define XCP_CRC_WRITE_PROTECTED               (0x23u)
#define XCP_CRC_ACCESS_DENIED                 (0x24u)
#define XCP_CRC_ACCESS_LOCKED                 (0x25u)
#define XCP_CRC_PAGE_NOT_VALID                (0x26u)
#define XCP_CRC_PAGE_MODE_NOT_VALID           (0x27u)
#define XCP_CRC_SEGMENT_NOT_VALID             (0x28u)
#define XCP_CRC_SEQUENCE                      (0x29u)
#define XCP_CRC_DAQ_CONFIG                    (0x2Au)

#define XCP_CRC_MEMORY_OVERFLOW               (0x30u)
#define XCP_CRC_GENERIC                       (0x31u)
#define XCP_CRC_VERIFY                        (0x32u)
#define XCP_CRC_RESOURCE_TEMP_NOT_ACCESSIBLE  (0x33u)

/*-------------------------------------------------------------------------*/
/* Return values */
#define XCP_CMD_OK                            (0x00u)
#define XCP_CMD_PENDING                       (0x01u)

#define XCP_CMD_BUSY                          (0x10u)
#define XCP_CMD_UNKNOWN                       (0x20u)
#define XCP_CMD_SYNTAX                        (0x21u)
#define XCP_CMD_OUT_OF_RANGE                  (0x22u)
#define XCP_CMD_PROTECTED                     (0x23u)
#define XCP_CMD_DENIED                        (0x24u)
#define XCP_CMD_ERROR                         (0xFFu)

#define XCP_ACTIVATE() { Xcp_ControlState = kXcp_Control_Enable; } /* PRQA S 3458 */ /* MD_MSR_19.4 */
#define XCP_DEACTIVATE() { Xcp_ControlState = kXcp_Control_Disable; } /* PRQA S 3458 */ /* MD_MSR_19.4 */

extern FUNC(uint8, XCP_CODE) Xcp_Event( uint16 EventChannel );
extern VAR(Xcp_ChannelStruct, XCP_VAR_NOINIT) Xcp_ChannelInfo[XCP_NUMBER_OF_CHANNELS];

/* From Xcp_Lcfg.h */
#define XcpConf_XcpEventChannel_XcpEveCh2MilliSec (0UL)

#endif
