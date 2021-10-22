/**
 * \file
 *
 * \brief       Maps the RTE interface to std c interface.
 *
 * \project     BMW Platform Software
 *
 * \copyright   BMW AG 2015 - 2017
 *
 * \version     5.3.1
 *
 * \remarks     This is included only if RTE support is not enabled.
 *
 */

#ifndef DLOG_RTE2C_H_
#define DLOG_RTE2C_H_

/*------------------------------------------------------------------------------
                      Include Section
-------------------------------------------------------------------------------*/

#include "DlogClassic_Version.h"


/*------------------------------------------------------------------------------
                      Macros
-------------------------------------------------------------------------------*/

/* check version of the module */
#if (!DlogClassic_CHECK_VERSION(5,3,1))
   #error "Version of Dlog_Rte2C.h does not match the version of the module!"
#endif


#define Rte_Call_DlogUser_SvkCurrent_NumberOfSvk                   Dlog_UserNumberOfSvkCurrent
#define Rte_Call_DlogUser_SvkCurrent_ReadSvk                       Dlog_UserReadSvkCurrent
#define Rte_Call_DlogUser_SvkCurrent_GetProgDepState               Dlog_UserGetProgDepState
#define Rte_Call_DlogUser_SvkHistory_NumberOfSvkHistory            Dlog_UserNumberOfSvkHistory
#define Rte_Call_DlogUser_SvkHistory_ReadSvkHistory                Dlog_UserReadSvkHistory
#define Rte_Call_DlogUser_DevelopmentInfo_ReadDevelopmentInfoField Dlog_UserReadDevelopmentInfoField
#define Rte_Call_DlogUser_SweProgrammingStatus_ReadSweProgrammingStatus Dlog_UserReadSweProgrammingStatus

#define RTE_E_OK E_OK

#define RTE_E_DlogUser_Svk_E_PENDING                  DCM_E_PENDING
#define RTE_E_DlogUser_SvkHistory_E_PENDING           DCM_E_PENDING
#define RTE_E_DlogUser_SweProgrammingStatus_E_PENDING DCM_E_PENDING
#define RTE_E_DataServices_Svk_DCM_E_PENDING          DCM_E_PENDING
#define RTE_E_DataServices_Vin_DCM_E_PENDING          DCM_E_PENDING
#define RTE_E_RandomSeed_E_NOT_OK                     E_NOT_OK
#define RTE_E_RandomSeed_E_PENDING                    DCM_E_PENDING
#define RTE_E_RoutineService_SweProgStatus_DCM_E_PENDING DCM_E_PENDING
#define RTE_E_RoutineService_DevInfo_DCM_E_PENDING    DCM_E_PENDING
#define RTE_E_SweInfo_E_NOT_OK                        E_NOT_OK

#define DLOG_HISTORY_SYSTEMSUPPLIER 0U
#define DLOG_HISTORY_PLANT          1U
#define DLOG_HISTORY_BACKUP_01      2U
#define DLOG_HISTORY_BACKUP_02      3U
#define DLOG_HISTORY_BACKUP_03      4U
#define DLOG_HISTORY_BACKUP_04      5U
#define DLOG_HISTORY_BACKUP_05      6U
#define DLOG_HISTORY_BACKUP_06      7U
#define DLOG_HISTORY_BACKUP_07      8U
#define DLOG_HISTORY_BACKUP_08      9U
#define DLOG_HISTORY_BACKUP_09     10U
#define DLOG_HISTORY_BACKUP_10     11U
#define DLOG_HISTORY_BACKUP_11     12U
#define DLOG_HISTORY_BACKUP_12     13U

#define DLOG_USER_PROG_DEP_UNCHECKED_APPL 0U
#define DLOG_USER_PROG_DEP_CONSISTENT_APPL 1U
#define DLOG_USER_PROG_DEP_INVALID 2U
#define DLOG_USER_PROG_DEP_WRONG_APPL 3U
#define DLOG_USER_PROG_DEP_INCONSISTENT_APPL 4U
#define DLOG_USER_PROG_DEP_VALID_BLU 6U


/*------------------------------------------------------------------------------
                      Data Types
-------------------------------------------------------------------------------*/

typedef uint8 Dlog_HistoryType;
typedef uint8 Dlog_UserSweProgDepStateType;


#endif /* DLOG_USERRTE_H_ */
