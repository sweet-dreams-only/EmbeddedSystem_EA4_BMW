/**********************************************************************************************************************
* Copyright 2017 Nxtr 
* Nxtr Confidential
*
* Module File Name:   fbl_TmplMonr.h
* Module Description: Driver for handling temporal Monitor Interface
* Project           : BMW
* Author            : Kevin Smith
***********************************************************************************************************************
* Version Control:
* %version:          1 %
* %derived_by:       cz7lt6 %
*----------------------------------------------------------------------------------------------------------------------
* Date      Rev      Author         Change Description                                                           SCR #
* -------   -------  --------  ---------------------------------------------------------------------------     --------
* 09/06/17   1       KJS       Initial Version                                                                 EA4#14822                                                                            
**********************************************************************************************************************/

/**********************************************************************************************************************
    --- IMPORTANT ---
    Date: Sep-6-2017, K. Smith
    
    This file is only part of the project until the bootloader is available. Once the bootloader is available
    this file shall be removed from the project. 
**********************************************************************************************************************/

/***********************************************************************************************************************
 *  INCLUDES
 **********************************************************************************************************************/
// #include "fbl_inc.h"
#include "port_regs.h"
#include "csig_regs.h"
#include "csih_regs.h"


/***********************************************************************************************************************
 *  DEFINES
 **********************************************************************************************************************/

/***********************************************************************************************************************
 *  TYPEDEFS
 **********************************************************************************************************************/

/***********************************************************************************************************************
 *  PROTOTYPES
 **********************************************************************************************************************/
void FBL_TmplMonr_Init(void);
void FBL_TmplMonr_RestartMode(void);
void FBL_TmplMonr_FlashMode(void);
void FBL_SPIInit(void);
/***********************************************************************************************************************
 *  GLOBAL DATA
 **********************************************************************************************************************/

/***********************************************************************************************************************
 *  END OF FILE: KBFBL_APDIFRAMEOEM.H
 **********************************************************************************************************************/

