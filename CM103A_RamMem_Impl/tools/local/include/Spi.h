/**********************************************************************************************************************
* Module File Name  : Spi.h
* Module Description: Stub header file for Spi.h from Renesas in the Synergy Release AR001A_Spi_Renesas/Ar4.0.3
***********************************************************************************************************************
* Version Control:
* %version:          2 %
* %derived_by:       nz3893 %
*----------------------------------------------------------------------------------------------------------------------
* Date      Rev      Author    Change Description                                                             SCR #
* -------   -------  --------  ---------------------------------------------------------------------------    ---------
* 07/27/17  1        AJM       Initial version                                                                EA4#13350
* 07/11/18  2        BLS       Updated to match latest header from Renesas Spi.h                              EA4#25009
**********************************************************************************************************************/
#ifndef SPI_H
#define SPI_H

/* Struct defined in Spi_Types.h file #included by Spi.h
   for SPI Handler/Driver initialization */
typedef struct STag_Spi_ConfigType
{
    uint32 DummyVari;
} Spi_ConfigType;

/* Dummy variable for SpiDriver #defined below */
Spi_ConfigType Config;

/* Defined in integration-level Spi_Cfg.h file #included by Spi.h
   to store the address to the SPI Handler/Driver */
#define SpiDriver  (&Config)

/* Relevant function headers from Spi.h */
extern void Spi_Init(Spi_ConfigType* ConfigPtr);
extern Std_ReturnType Spi_DeInit(void);

#endif /* SPI_H */
