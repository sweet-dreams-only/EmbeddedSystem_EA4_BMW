/**********************************************************************************************************************
 * Copyright 2018 Nxtr
 * Nxtr Confidential
 *
 * Module File Name  : Spi.h
 * Module Description: SPI stub
 * Project           : CBD
 * Author            : Krzysztof Byrski
 **********************************************************************************************************************
 * Version Control:
 * %version:          1 %
 * %derived_by:       nz2999 %
 *---------------------------------------------------------------------------------------------------------------------
 * Date      Rev      Author    Change Description                                                             SCR #
 * --------  -------  --------  ----------------------------------------------------------------------------  ---------
 * 02/20/18  1        KByrski   Initial version                                                               EA4#2868
 *********************************************************************************************************************/

#ifndef SPI_H
#define SPI_H

#include "Spi_Cfg.h"
#include "Std_Types.h"

typedef uint8 Spi_SequenceType;
typedef uint16 Spi_DataType;
typedef uint8 Spi_ChannelType;

typedef enum ETagSpi_SeqResultType
{
  SPI_SEQ_OK = 0,
  SPI_SEQ_PENDING,
  SPI_SEQ_FAILED,
  SPI_SEQ_CANCELLED
} Spi_SeqResultType;

extern FUNC(Std_ReturnType, SPI_PUBLIC_CODE) Spi_WriteIB
               (Spi_ChannelType Channel, P2CONST(Spi_DataType, AUTOMATIC,
                                             SPI_APPL_CONST) DataBufferPtr);

extern FUNC(Std_ReturnType, SPI_PUBLIC_CODE) Spi_ReadIB
               (Spi_ChannelType Channel, P2VAR(Spi_DataType, AUTOMATIC,
                                             SPI_APPL_DATA) DataBufferPointer);

extern FUNC(Spi_SeqResultType, SPI_PUBLIC_CODE)
                       Spi_GetSequenceResult(Spi_SequenceType Sequence);

#endif /* SPI_H */
