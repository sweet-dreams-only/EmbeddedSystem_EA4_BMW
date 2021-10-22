/**********************************************************************************************************************
* Copyright 2018 Nxtr 
* Nxtr Confidential
*
* Module File Name:   CDD_XcpIf_private.h
* Module Description: Private header file for XCP Interface ES 104A
* Project           : CBD 
* Author            : Kevin Smith
***********************************************************************************************************************
* Version Control:
* %version:          1 %
* %derived_by:       cz7lt6 %
*----------------------------------------------------------------------------------------------------------------------
* Date      Rev      Author         Change Description                                                           SCR #
* -------   -------  --------  ---------------------------------------------------------------------------     --------
* 01/19/18  1        KJS       Initial Version                                                                EA4#17610
**********************************************************************************************************************/

/******************************************* Multiple Include Protection *********************************************/
#ifndef CDD_XCPIF_PRIVATE_H
#define CDD_XCPIF_PRIVATE_H

#include "Std_Types.h"

/************************************************ Embedded Constants *************************************************/
typedef struct
{
    uint8 Seg_u08;
} NtCopyCalPageTyp;

typedef struct
{
    uint8 Seg_u08;
    uint8 Mod_u08;
    uint8 Page_u08;
} NtSetCalPageTyp;

typedef struct
{
    uint16 XcpEve_u16;
} NtXcpEveTyp;

/******************************************** File Level Rule Deviations *********************************************/

/****************************************************** Macros *******************************************************/

/*********************************************** Exported Declarations ***********************************************/

/**************************************** End Of Multiple Include Protection *****************************************/
#endif /* CDD_XCPIF_PRIVATE_H */
