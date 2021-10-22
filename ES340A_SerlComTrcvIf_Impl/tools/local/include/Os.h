/**********************************************************************************************************************
 * Copyright 2018 Nxtr
 * Nxtr Confidential
 *
 * Module File Name  : Os.h
 * Module Description: OS stub
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

#ifndef OS_H
#define OS_H

#include "Spi.h"

extern Std_ReturnType Call_Spi_AsyncTransmit(Spi_SequenceType os_arg_Sequence);

#endif /* OS_H */
