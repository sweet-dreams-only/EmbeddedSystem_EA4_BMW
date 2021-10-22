/**********************************************************************************************************************
* Copyright 2017 Nxtr
* Nxtr Confidential
*
* Module File Name:   E2EPW_Init.c
* Module Description: E2EPW Init functions wrapper
* Project           : BMW 5441
* Author            : Akilan Rathakrishnan
***********************************************************************************************************************
* Version Control:
* %version:          3 %
* %derived_by:       tzyksv %
*----------------------------------------------------------------------------------------------------------------------
* Date      Rev      Author         Change Description                                                           SCR #
* -------   -------  --------  ---------------------------------------------------------------------------     --------
* 11/23/17  1        AR           Initial Version 																EA4#17066
* 04/27/18  2        AR           Updates I-190 MM components integration    									EA4#22843
* 05/04/18  3        AR           Updates I-190 MM components integration - MM107A and MM521A					EA4#22843
**********************************************************************************************************************/

/************************************************ Include Statements *************************************************/
#include "E2EPW_Init.h"
#include "E2EPW_BmwMsgSlot51Bas0Repn2BusFrChA_sigGroup_AVL_PO_EPS_sigGroup_AVL_PO_EPS_tx.h"
#include "E2EPW_BmwMsgSlot55Bas3Repn4BusFrChA_sigGroup_V_VEH_sigGroup_V_VEH_rx.h"
#include "E2EPW_BmwMsgSlot107Bas0Repn1BusFrChA_sigGroup_OFFS_QUAD_EPS_sigGroup_OFFS_QUAD_EPS_rx.h"
#include "E2EPW_BmwMsgSlot121Bas1Repn2BusFrChA_sigGroup_CON_VEH_sigGroup_CON_VEH_rx.h"
#include "E2EPW_BmwMsgSlot274Bas2Repn4BusFrChA_sigGroup_DISP_CC_EPS_sigGroup_DISP_CC_EPS_tx.h"
#include "E2EPW_BmwMsgSlot55Bas0Repn2BusFrChA_sigGroup_ACLNY_MASSCNTR_sigGroup_ACLNY_MASSCNTR_rx.h"
#include "E2EPW_BmwMsgSlot56Bas0Repn2BusFrChA_sigGroup_VYAW_VEH_sigGroup_VYAW_VEH_rx.h"
#include "E2EPW_BmwMsgSlot68Bas0Repn2BusFrChA_sigGroup_TAR_QTA_STRMOM_DV_sigGroup_TAR_QTA_STRMOM_DV_rx.h"
#include "E2EPW_BmwMsgSlot68Bas0Repn2BusFrChA_sigGroup_TAR_STMOM_DV_ACT_sigGroup_TAR_STMOM_DV_ACT_rx.h"
#include "E2EPW_BmwMsgSlot234Bas1Repn2BusFrChA_sigGroup_ST_EST_sigGroup_ST_EST_tx.h"
#include "E2EPW_BmwMsgSlot274Bas0Repn8BusFrChA_sigGroup_SU_EPS_sigGroup_SU_EPS_tx.h"
#include "E2EPW_BmwMsgSlot68Bas1Repn2BusFrChA_sigGroup_ENERG_DGR_DRDY_sigGroup_ENERG_DGR_DRDY_rx.h"
#include "E2EPW_BmwMsgSlot49Bas1Repn2BusFrChA_sigGroup_DT_EST_sigGroup_DT_EST_tx.h"
#include "E2EPW_BmwMsgSlot49Bas0Repn2BusFrChA_sigGroup_AVL_FORC_GRD_sigGroup_AVL_FORC_GRD_tx.h"
#include "E2EPW_BmwMsgSlot49Bas0Repn2BusFrChA_sigGroup_AVL_STMOM_DV_ACT_sigGroup_AVL_STMOM_DV_ACT_tx.h"

/******************************************** File Level Rule Deviations *********************************************/

/********************************************* Embedded Local Constants **********************************************/
/******************************************** Module Specific Variables **********************************************/

/******************************************** Local Function Prototypes **********************************************/

/*********************************************** Function Definitions ************************************************/

/**********************************************************************************************************************
 * Name:        E2EProtectionWrapperInit
 * Description: Init1 Function
 * Inputs:      NONE
 * Outputs:     NONE
 * Usage Notes: This function shall be called before COM initializaion
 *********************************************************************************************************************/
void E2EProtectionWrapperInit(void)
{
	E2EPW_ReadInit_sigGroup_V_VEH_sigGroup_V_VEH();
	E2EPW_ReadInit_sigGroup_CON_VEH_sigGroup_CON_VEH();
	E2EPW_ReadInit_sigGroup_OFFS_QUAD_EPS_sigGroup_OFFS_QUAD_EPS();
	E2EPW_ReadInit_sigGroup_ACLNY_MASSCNTR_sigGroup_ACLNY_MASSCNTR();
	E2EPW_ReadInit_sigGroup_VYAW_VEH_sigGroup_VYAW_VEH();
	E2EPW_ReadInit_sigGroup_TAR_QTA_STRMOM_DV_sigGroup_TAR_QTA_STRMOM_DV();
	E2EPW_ReadInit_sigGroup_TAR_STMOM_DV_ACT_sigGroup_TAR_STMOM_DV_ACT();
	E2EPW_ReadInit_sigGroup_ENERG_DGR_DRDY_sigGroup_ENERG_DGR_DRDY();	
	E2EPW_WriteInit_sigGroup_ST_EST_sigGroup_ST_EST();
	E2EPW_WriteInit_sigGroup_SU_EPS_sigGroup_SU_EPS();
	E2EPW_WriteInit_sigGroup_DISP_CC_EPS_sigGroup_DISP_CC_EPS();
	E2EPW_WriteInit_sigGroup_AVL_PO_EPS_sigGroup_AVL_PO_EPS();
	E2EPW_WriteInit_sigGroup_DT_EST_sigGroup_DT_EST();
	E2EPW_WriteInit_sigGroup_AVL_FORC_GRD_sigGroup_AVL_FORC_GRD();
	E2EPW_WriteInit_sigGroup_AVL_STMOM_DV_ACT_sigGroup_AVL_STMOM_DV_ACT();
}