/**
*  \file
*
*  \brief       BMW SWC StdDiag
*
*  This file contains the implementation of the module StdDiag
*  for usage in the BMW AUTOSAR Core.
*
*  \project     BMW Platform Software
*
*  \copyright   BMW AG 2015 - 2017
*
*  \version     5.3.0
*
*  \remarks     The StdDiag module is responsible for BMW specific session
*               handling and handles a number of BMW specific diagnostic requests.
*
*/

/*------------------------------------------------------------------------------
                      MISRA-Deviations
------------------------------------------------------------------------------*/
/*
   MISRA-C:2004 Rule 19.1: including StdDiag_MemMap.h is necessary throughout
   the file according to memory abstraction. See PRQA 5087.
*/


/*------------------------------------------------------------------------------
                      Include Section
-------------------------------------------------------------------------------*/

#include "BUtil/PlatformTypes.h"
#include "StdDiag_Version.h"
#include "StdDiag.h"
#include "StdDiag_Internal.h"
#include "StdDiag_Cfg.h"
#include "StdDiag_AssertAdapter.h"
#include "StdDiag_OmcAdapter.h"
#include "StdDiag_StmAdapter.h"
#include "StdDiag_UDSAdapter.h"
#include "StdDiag_ErrMemAdapter.h"
#include "StdDiag_AppAdapter.h"
#include "StdDiag_MgmtAdapter.h"
#include "StdDiag_ProgPreparation.h"


/*------------------------------------------------------------------------------
                      Macros
------------------------------------------------------------------------------*/

/* check version of the module */
#if (!StdDiag_CHECK_VERSION(5,3,0))
#error "Version of StdDiag_ProgPreparation.c does not match the version of the module!"
#endif

/*
   definitions for incoming service requests
*/

/**\{*/
/**
 * \name Service identifiers of incoming service requests
 */
#define SID_SESSIONCONTROL                       0x10u /**< Diagnostic Session Control */
#define SID_ECURESET                             0x11u /**< Ecu Reset */
#define SID_READDATABYIDENTIFIER                 0x22u /**< Read Data By Identifier */
#define SID_COMMUNICATIONCONTROL                 0x28u /**< Communication Control */
#define SID_ROUTINECONTROL                       0x31u /**< Routine Control */
#define SID_TESTERPRESENT                        0x3Eu /**< Tester Present */
#define SID_CONTROLDTCSETTING                    0x85u /**< Control DTC Setting */
/**\}*/

/**\{*/
/**
 * \name Subfunction IDs of incoming service requests
 */
#define APPL_DEFAULT_SESSION          0x01u /**< SID switch to Application Default Session */
#define PROGRAMMING_SESSION           0x02u /**< SID switch to Programming Session */
#define APPL_EXTENDED_DIAG_SESSION    0x03u /**< SID switch to Application Extended Session */

#define ROUTINECONTROL_START          0x01u /**< SID Routine Control Start */

#define ENABLE_RX_DISABLE_TX          0x01u /**< SID enable Rx and disable Tx Communication */
#define DISABLE_RX_AND_TX             0x03u /**< SID disable Rx and Tx Communication */

#define DTC_OFF                       0x02u /**< SID stop updating DTC status */

#define NORMAL_COMM_MSG_FLAG          0x01u /**< Communication Type for Communication Control */

#define HARD_RESET                    0x01u /**< SID for Ecu Hard Reset */
/**\}*/

/**\{*/
/**
 * \name Routine identifiers of incoming service requests
 */
#define RID_SET_ENERGY_MODE                  0x0F0Cu /**< RID for service Set Energy Mode */
#define RID_SET_EXTENDED_MODE                0x1003u /**< RID for service Set Extended Mode */
#define RID_ACTIVATE_PARALLEL_FLASHMODE      0x100Eu /**< RID for service Activate Parallel Flash Mode */
/**\}*/

/**\{*/
/**
 * \name Routine control options of incoming service requests
 */
#define RCO_ENERGY_MODE_FLASH                0x03u /**< Option for setting the Energy Mode to Flash */
#define RCO_EXTENDED_MODE_1                  0x01u /**< Option for setting the Extended Mode to 1 */
/**\}*/

/**\{*/
/**
 * \name Subsession values of DEFAULT_SESSION
 */
#define DEFAULT_APPL_FLASH_MODE_DEACTIVATED  0x81u /**< Subsession value for state Flash Mode Deactivated */
#define DEFAULT_APPL_FLASH_MODE_ACTIVATED    0x82u /**< Subsession value for state Flash Mode Activated */

/**\{*/
/**
 * \name Subsession values of EXTENDED_DIAGNOSTIC_SESSION
 */
#define EXTENDED_APPL_FLASH_MODE_ACTIVATED   0x84u /**< Subsession value for state Flash Mode Activated */
#define EXTENDED_APPL_FLASH_EXIT             0x85u /**< Subsession value for state Flash Exit */
#define EXTENDED_APPL_FLASH_MODE_DEACTIVATED 0x86u /**< Subsession value for state Started */
/**\}*/

/**
 * \brief Default Subsession value for Sessions without substate
 */
#define SUBSESSION_VALUE_DEFAULT                 0x00u

/**
 * \brief Bitmask for suppressPosRspMsgIndicationBit
 */
#define BITMASK_SUPPRESSPOSRESP                  0x80u

/**
 * \brief Total number of supported requests
 */
#define STDDIAG_NUMBER_OF_REQUESTS               REQ_LAST_ID

/**
 * \brief Total number of real states
 */
#define STDDIAG_NUMBER_OF_STATES                 STATE_LAST_REAL_STATE

/**
 * \brief Initial values for request permissions before initialization of the module
 */
#define STDDIAG_INITIAL_REQUEST_PERMISSIONS  \
{ \
   /* REQ_10_01            */ REQ_NOT_ALLOWED_CNC, \
   /* REQ_10_02            */ REQ_NOT_ALLOWED_CNC, \
   /* REQ_10_03            */ REQ_NOT_ALLOWED_CNC, \
   /* REQ_10_OTHER         */ REQ_NOT_ALLOWED_CNC, \
   /* REQ_28_DIS_TX_NORMAL */ REQ_NOT_ALLOWED_CNC, \
   /* REQ_31_01_0F_0C_xx   */ REQ_NOT_ALLOWED_CNC, \
   /* REQ_31_01_0F_0C_03   */ REQ_NOT_ALLOWED_CNC, \
   /* REQ_31_01_10_03_01   */ REQ_NOT_ALLOWED_CNC, \
   /* REQ_85_02            */ REQ_NOT_ALLOWED_CNC, \
   /* REQ_22               */ REQ_ALLOWED,         \
   /* REQ_3E               */ REQ_ALLOWED,         \
   /* REQ_11_HARD          */ REQ_NOT_ALLOWED_CNC, \
   /* REQ_31_01_10_0E      */ REQ_NOT_ALLOWED_CNC, \
   /* REQ_OTHER            */ REQ_ALLOWED          \
}

/*------------------------------------------------------------------------------
                      Data Types
-------------------------------------------------------------------------------*/

/**
 * \brief type definition for the subsession
 */
typedef uint8 StdDiag_SubSessionType;

/**
 * \brief type definition for the state machine states
 */

typedef enum {
  STATE_APPL_DEFAULT_APPLICATION_ACTIVATED,  /**< State Application Activated in Application Default Session */
  STATE_APPL_DEFAULT_FLASH_MODE_ACTIVATED,   /**< State Flash Mode Activated in Application Default Session */
  STATE_APPL_EXTENDED_STARTED,               /**< State Started in Application Extended Diagnostic Session */
  STATE_APPL_EXTENDED_DTC_OFF,               /**< State DTC Off in Application Extended Diagnostic Session, without Energy Mode Flash */
  STATE_APPL_EXTENDED_NDC_DISABLED,          /**< State NDC Disabled in Application Extended Diagnostic Session, without Energy Mode Flash */
  STATE_APPL_EXTENDED_ENERGY_MODE_FLASH,     /**< State Energy Mode Flash in Application Extended Diagnostic Session */
  STATE_APPL_EXTENDED_DTC_OFF_EMF,           /**< State DTC Off in Application Extended Diagnostic Session, with Energy Mode Flash */
  STATE_APPL_EXTENDED_NDC_DISABLED_EMF,      /**< State NDC Disabled in Application Extended Diagnostic Session, with Energy Mode Flash */
  STATE_APPL_EXTENDED_FLASH_MODE_ACTIVATED,  /**< State Flash Mode Activated in Application Extended Diagnostic Session */
  STATE_APPL_EXTENDED_FLASH_EXIT,            /**< State Flash Exit in Application Extended Diagnostic Session */
  STATE_OTHER_DIAGNOSTIC_SESSION,            /**< Other diagnostic Session than Default or Extended Diagnostic session */
  STATE_LAST_REAL_STATE,                     /**< internal ID, indicating number of states */
  STATE_NO_CHANGE                            /**< internal ID, indicating no state change */
}StdDiag_StateType;

/**
 * \brief type definition for handled request id
 */

typedef enum {
  REQ_10_01,            /**< Diagnostic Request switch to default session */
  REQ_10_02,            /**< Diagnostic Request switch to programming session */
  REQ_10_03,            /**< Diagnostic Request switch to application extended session */
  REQ_10_OTHER,         /**< Diagnostic Request switch to other diagnostic session */
  REQ_28_DIS_TX_NORMAL, /**< Diagnostic Request disable Tx communication for normal messages */
  REQ_31_01_0F_0C_xx,   /**< Diagnostic Request set energy mode to other than flash */
  REQ_31_01_0F_0C_03,   /**< Diagnostic Request set energy mode to flash */
  REQ_31_01_10_03_01,   /**< Diagnostic Request set extended mode to 1 */
  REQ_85_02,            /**< Diagnostic Request lock error memory */
  REQ_22,               /**< Diagnostic Request read data by identifier allowed in all states */
  REQ_3E,               /**< Diagnostic Request tester present */
  REQ_11_HARD,          /**< Diagnostic Request hard or soft reset */
  REQ_31_01_10_0E,      /**< Diagnostic Request activate parallel flash mode */
  REQ_OTHER,            /**< any other Diagnostic Request */
  REQ_LAST_ID           /**< invalid Diagnostic Request ID */
} StdDiag_RequestType;


/**
 * \brief type definition for request permissions
 */
typedef enum
{
  REQ_ALLOWED = 0x00u,             /**< request is allowed */
  REQ_NOT_ALLOWED_CNC = 0x22u,     /**< request rejected, conditions not correct */
  REQ_NOT_ALLOWED_SFNSIAS = 0x7Eu, /**< request rejected, subfunction not supported in active session */
  REQ_NOT_ALLOWED_SNSIAS = 0x7Fu   /**< request rejected, service not supported in active session */
}StdDiag_RequestPermissionType;

/**
 * \brief type definition for the combination of request permission and next state
 *        for a handled request id
 */
typedef struct
{
  StdDiag_RequestPermissionType permission; /**< permission of the request */
  StdDiag_StateType nextState;              /**< next state */
  StdDiag_StateType nextStateNegResp;       /**< next state on negative response */
}StdDiag_RequestTransitionType;

/*------------------------------------------------------------------------------
                      Global Variables
------------------------------------------------------------------------------*/

/* PRQA S 5087 2 */
#define StdDiag_START_SEC_VAR_NO_INIT_8
#include "StdDiag_MemMap.h"

/**
 * \brief StdDiag_currentState holds the current state of the state machine
 */
static StdDiag_StateType StdDiag_currentState;

/**
 * \brief StdDiag_currentRequest holds the currently handled diagnostic request
 */
static StdDiag_RequestType StdDiag_currentRequest;


/* PRQA S 5087 2 */
#define StdDiag_STOP_SEC_VAR_NO_INIT_8
#include "StdDiag_MemMap.h"

/* PRQA S 5087 2 */
#define StdDiag_START_SEC_VAR_NO_INIT_BOOLEAN
#include "StdDiag_MemMap.h"

/**
 * \brief StdDiag_currentEnableConditionState holds the current setting of the enable condition
 */
static boolean StdDiag_currentEnableConditionState;

/* PRQA S 5087 2 */
#define StdDiag_STOP_SEC_VAR_NO_INIT_BOOLEAN
#include "StdDiag_MemMap.h"

/* PRQA S 5087 2 */
#define StdDiag_START_SEC_VAR_NO_INIT_16
#include "StdDiag_MemMap.h"

/**
 * \brief StdDiag_pendingSourceAddress holds the source address of the currently handled diagnostic request
 */
static uint16 StdDiag_pendingSourceAddress;

/* PRQA S 5087 2 */
#define StdDiag_STOP_SEC_VAR_NO_INIT_16
#include "StdDiag_MemMap.h"



/* PRQA S 5087 2 */
#define StdDiag_START_SEC_VAR_INIT_UNSPECIFIED
#include "StdDiag_MemMap.h"

/**
 * \brief StdDiag_RequestPermission holds the permission for all incoming diagnostic requests related to the current state of the state machine
 *        (initialization is necessary to provide defined value even before module initialization)
 */
static StdDiag_RequestPermissionType StdDiag_RequestPermission[STDDIAG_NUMBER_OF_REQUESTS] = STDDIAG_INITIAL_REQUEST_PERMISSIONS;

/* PRQA S 5087 2 */
#define StdDiag_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "StdDiag_MemMap.h"


/*------------------------------------------------------------------------------
                      Global Constants
-------------------------------------------------------------------------------*/
/* PRQA S 5087 2 */
#define StdDiag_START_SEC_CONST_UNSPECIFIED
#include "StdDiag_MemMap.h"

/*
   MISRA-C:2004 Rule 8.7: static constant StdDiag_SubSessionValue is located here even if it is
   only used in function StdDiag_ConditionCheckActiveSessionState, because static variables
   within block scope are not allowed due to AUTOSAR Memory Mapping.
*/
/* PRQA S 3218 4 */
/**
 * \brief StdDiag_SubSessionValue holds the numerical subsession values for all states of the state machine
 */
static const StdDiag_SubSessionType StdDiag_SubSessionValue[STATE_LAST_REAL_STATE] =
{
  DEFAULT_APPL_FLASH_MODE_DEACTIVATED,  /* STATE_APPL_DEFAULT_APPLICATION_ACTIVATED */
  DEFAULT_APPL_FLASH_MODE_ACTIVATED,    /* STATE_APPL_DEFAULT_FLASH_MODE_ACTIVATED  */
  EXTENDED_APPL_FLASH_MODE_DEACTIVATED, /* STATE_APPL_EXTENDED_STARTED              */
  EXTENDED_APPL_FLASH_MODE_DEACTIVATED, /* STATE_APPL_EXTENDED_DTC_OFF              */
  EXTENDED_APPL_FLASH_MODE_DEACTIVATED, /* STATE_APPL_EXTENDED_NDC_DISABLED         */
  EXTENDED_APPL_FLASH_MODE_DEACTIVATED, /* STATE_APPL_EXTENDED_ENERGY_MODE_FLASH    */
  EXTENDED_APPL_FLASH_MODE_DEACTIVATED, /* STATE_APPL_EXTENDED_DTC_OFF_EMF          */
  EXTENDED_APPL_FLASH_MODE_DEACTIVATED, /* STATE_APPL_EXTENDED_NDC_DISABLED_EMF     */
  EXTENDED_APPL_FLASH_MODE_ACTIVATED,   /* STATE_APPL_EXTENDED_FLASH_MODE_ACTIVATED */
  EXTENDED_APPL_FLASH_EXIT,             /* STATE_APPL_EXTENDED_FLASH_EXIT           */
  SUBSESSION_VALUE_DEFAULT              /* STATE_OTHER_DIAGNOSTIC_SESSION           */
};

/*
   MISRA-C:2004 Rule 8.7: static constant StdDiag_InitialRequestPermission is located here even if it is
   only used in function StdDiag_Stop, because static variables within block scope are not allowed
   due to AUTOSAR Memory Mapping.
*/
/* PRQA S 3218 4 */
/**
 * \brief StdDiag_InitialRequestPermission holds the request permission values valid before the module is initialized
 */
static const StdDiag_RequestPermissionType StdDiag_InitialRequestPermission[STDDIAG_NUMBER_OF_REQUESTS] = STDDIAG_INITIAL_REQUEST_PERMISSIONS;

/**
 * \brief StdDiag_RequestTransitionTables holds one table for each state of the state machine, which
 *       defines the permission of each diagnostic request for this state
 *
 * \lhref FL109, FL111, FL113, FL115, FL117, FL120, FL128, FL132, FL134, FL218, FL258, FL264, FL279, FL1307, FL1308, FL1309, FL1310, FL1311, FL1312,
 *        DK_T2_257, DK_T2_259, DK_T3_1171
 *
 *  \remarks accepted deviation for FL1307 to FL1311: RDBI is always allowed and does not change states
 */
static const StdDiag_RequestTransitionType StdDiag_RequestTransitionTables[STDDIAG_NUMBER_OF_STATES][STDDIAG_NUMBER_OF_REQUESTS] =
{
  /* allowed transitions and next states for different sessions.
     REQ_ALLOWED: request is always allowed in this state
     REQ_NOT_ALLOWED_xxx: request is never allowed in this state, xxx indicates error code */

  /* STATE_NO_CHANGE means: State is not changed due to diagnostic request, but may be changed later due to
   * other notification */

  /*   request id           | req. permission          | next state on pos. resp. | next state on neg. response */

  /* STATE_APPL_DEFAULT_APPLICATION_ACTIVATED */
  {
      /* REQ_10_01            */ {REQ_ALLOWED,             STATE_NO_CHANGE,                STATE_NO_CHANGE}, /* FL132 */
      /* REQ_10_02            */ {REQ_NOT_ALLOWED_SFNSIAS, STATE_NO_CHANGE,                STATE_NO_CHANGE},
      /* REQ_10_03            */ {REQ_ALLOWED,             STATE_APPL_EXTENDED_STARTED,    STATE_NO_CHANGE}, /* FL109 */
      /* REQ_10_OTHER         */ {REQ_ALLOWED,             STATE_OTHER_DIAGNOSTIC_SESSION, STATE_NO_CHANGE},
      /* REQ_28_DIS_TX_NORMAL */ {REQ_NOT_ALLOWED_SNSIAS,  STATE_NO_CHANGE,                STATE_NO_CHANGE}, /* DK_T2_257, FL264 */
      /* REQ_31_01_0F_0C_xx   */ {REQ_ALLOWED,             STATE_NO_CHANGE,                STATE_NO_CHANGE}, /* DK_T3_1171, FL279 */
      /* REQ_31_01_0F_0C_03   */ {REQ_NOT_ALLOWED_CNC,     STATE_NO_CHANGE,                STATE_NO_CHANGE}, /* FL218 */
      /* REQ_31_01_10_03_01   */ {REQ_ALLOWED,             STATE_NO_CHANGE,                STATE_NO_CHANGE},
      /* REQ_85_02            */ {REQ_NOT_ALLOWED_SNSIAS,  STATE_NO_CHANGE,                STATE_NO_CHANGE}, /* DK_T2_259, FL258 */
      /* REQ_22               */ {REQ_ALLOWED,             STATE_NO_CHANGE,                STATE_NO_CHANGE},
      /* REQ_3E               */ {REQ_ALLOWED,             STATE_NO_CHANGE,                STATE_NO_CHANGE},
      /* REQ_11_HARD          */ {REQ_ALLOWED,             STATE_NO_CHANGE,                STATE_NO_CHANGE},
      /* REQ_31_01_10_0E      */ {REQ_ALLOWED,             STATE_NO_CHANGE,                STATE_NO_CHANGE},
      /* REQ_OTHER            */ {REQ_ALLOWED,             STATE_NO_CHANGE,                STATE_NO_CHANGE}
  },

  /* STATE_APPL_DEFAULT_FLASH_MODE_ACTIVATED */
  {
      /* REQ_10_01            */ {REQ_ALLOWED,             STATE_NO_CHANGE,                          STATE_NO_CHANGE}, /* FL132 */
      /* REQ_10_02            */ {REQ_NOT_ALLOWED_SFNSIAS, STATE_NO_CHANGE,                          STATE_NO_CHANGE},
      /* REQ_10_03            */ {REQ_ALLOWED,             STATE_APPL_EXTENDED_FLASH_MODE_ACTIVATED, STATE_NO_CHANGE}, /* FL113 */
      /* REQ_10_OTHER         */ {REQ_ALLOWED,             STATE_OTHER_DIAGNOSTIC_SESSION,           STATE_NO_CHANGE},
      /* REQ_28_DIS_TX_NORMAL */ {REQ_NOT_ALLOWED_SNSIAS,  STATE_NO_CHANGE,                          STATE_NO_CHANGE}, /* DK_T2_257, FL264 */
      /* REQ_31_01_0F_0C_xx   */ {REQ_ALLOWED,             STATE_APPL_DEFAULT_APPLICATION_ACTIVATED, STATE_NO_CHANGE}, /* DK_T3_1171, FL279 */
      /* REQ_31_01_0F_0C_03   */ {REQ_NOT_ALLOWED_CNC,     STATE_NO_CHANGE,                          STATE_NO_CHANGE}, /* FL218 */
      /* REQ_31_01_10_03_01   */ {REQ_ALLOWED,             STATE_NO_CHANGE,                          STATE_NO_CHANGE},
      /* REQ_85_02            */ {REQ_NOT_ALLOWED_SNSIAS,  STATE_NO_CHANGE,                          STATE_NO_CHANGE}, /* DK_T2_259, FL258 */
      /* REQ_22               */ {REQ_ALLOWED,             STATE_NO_CHANGE,                          STATE_NO_CHANGE},
      /* REQ_3E               */ {REQ_ALLOWED,             STATE_NO_CHANGE,                          STATE_NO_CHANGE},
      /* REQ_11_HARD          */ {REQ_ALLOWED,             STATE_NO_CHANGE,                          STATE_NO_CHANGE},
      /* REQ_31_01_10_0E      */ {REQ_ALLOWED,             STATE_NO_CHANGE,                          STATE_NO_CHANGE},
      /* REQ_OTHER            */ {REQ_ALLOWED,             STATE_NO_CHANGE,                          STATE_NO_CHANGE}
  },

  /* STATE_APPL_EXTENDED_STARTED */  /* FL1307 */
  {
      /* REQ_10_01            */ {REQ_ALLOWED,         STATE_APPL_DEFAULT_APPLICATION_ACTIVATED, STATE_NO_CHANGE}, /* FL134, FL117 */
      /* REQ_10_02            */ {REQ_NOT_ALLOWED_CNC, STATE_APPL_EXTENDED_FLASH_EXIT,           STATE_APPL_EXTENDED_FLASH_EXIT}, /* FL128 */
      /* REQ_10_03            */ {REQ_ALLOWED,         STATE_NO_CHANGE,                          STATE_NO_CHANGE},
      /* REQ_10_OTHER         */ {REQ_ALLOWED,         STATE_OTHER_DIAGNOSTIC_SESSION,           STATE_APPL_EXTENDED_FLASH_EXIT},
      /* REQ_28_DIS_TX_NORMAL */ {REQ_ALLOWED,         STATE_APPL_EXTENDED_FLASH_EXIT,           STATE_APPL_EXTENDED_FLASH_EXIT},
      /* REQ_31_01_0F_0C_xx   */ {REQ_ALLOWED,         STATE_APPL_EXTENDED_FLASH_EXIT,           STATE_APPL_EXTENDED_FLASH_EXIT}, /* FL279 */
      /* REQ_31_01_0F_0C_03   */ {REQ_ALLOWED,         STATE_APPL_EXTENDED_ENERGY_MODE_FLASH,    STATE_NO_CHANGE}, /* FL218 */
      /* REQ_31_01_10_03_01   */ {REQ_ALLOWED,         STATE_APPL_EXTENDED_FLASH_EXIT,           STATE_APPL_EXTENDED_FLASH_EXIT},
      /* REQ_85_02            */ {REQ_ALLOWED,         STATE_APPL_EXTENDED_DTC_OFF,              STATE_NO_CHANGE},
      /* REQ_22               */ {REQ_ALLOWED,         STATE_NO_CHANGE,                          STATE_NO_CHANGE},
      /* REQ_3E               */ {REQ_ALLOWED,         STATE_NO_CHANGE,                          STATE_NO_CHANGE},
      /* REQ_11_HARD          */ {REQ_ALLOWED,         STATE_APPL_DEFAULT_APPLICATION_ACTIVATED, STATE_NO_CHANGE},
      /* REQ_31_01_10_0E      */ {REQ_ALLOWED,         STATE_APPL_EXTENDED_FLASH_EXIT,           STATE_APPL_EXTENDED_FLASH_EXIT},
      /* REQ_OTHER            */ {REQ_ALLOWED,         STATE_APPL_EXTENDED_FLASH_EXIT,           STATE_APPL_EXTENDED_FLASH_EXIT}
  },

  /* STATE_APPL_EXTENDED_DTC_OFF */ /* FL1307 */
  {
      /* REQ_10_01            */ {REQ_ALLOWED,         STATE_APPL_DEFAULT_APPLICATION_ACTIVATED, STATE_NO_CHANGE}, /* FL134, FL117 */
      /* REQ_10_02            */ {REQ_NOT_ALLOWED_CNC, STATE_APPL_EXTENDED_FLASH_EXIT,           STATE_APPL_EXTENDED_FLASH_EXIT}, /* FL128 */
      /* REQ_10_03            */ {REQ_ALLOWED,         STATE_NO_CHANGE,                          STATE_NO_CHANGE},
      /* REQ_10_OTHER         */ {REQ_ALLOWED,         STATE_OTHER_DIAGNOSTIC_SESSION,           STATE_APPL_EXTENDED_FLASH_EXIT},
      /* REQ_28_DIS_TX_NORMAL */ {REQ_ALLOWED,         STATE_APPL_EXTENDED_NDC_DISABLED,         STATE_NO_CHANGE},
      /* REQ_31_01_0F_0C_xx   */ {REQ_ALLOWED,         STATE_APPL_EXTENDED_FLASH_EXIT,           STATE_APPL_EXTENDED_FLASH_EXIT}, /* FL279 */
      /* REQ_31_01_0F_0C_03   */ {REQ_NOT_ALLOWED_CNC, STATE_APPL_EXTENDED_FLASH_EXIT,           STATE_APPL_EXTENDED_FLASH_EXIT},
      /* REQ_31_01_10_03_01   */ {REQ_ALLOWED,         STATE_APPL_EXTENDED_FLASH_EXIT,           STATE_APPL_EXTENDED_FLASH_EXIT},
      /* REQ_85_02            */ {REQ_ALLOWED,         STATE_APPL_EXTENDED_FLASH_EXIT,           STATE_APPL_EXTENDED_FLASH_EXIT},
      /* REQ_22               */ {REQ_ALLOWED,         STATE_NO_CHANGE,                          STATE_NO_CHANGE},
      /* REQ_3E               */ {REQ_ALLOWED,         STATE_NO_CHANGE,                          STATE_NO_CHANGE},
      /* REQ_11_HARD          */ {REQ_ALLOWED,         STATE_APPL_DEFAULT_APPLICATION_ACTIVATED, STATE_NO_CHANGE},
      /* REQ_31_01_10_0E      */ {REQ_NOT_ALLOWED_CNC, STATE_APPL_EXTENDED_FLASH_EXIT,           STATE_APPL_EXTENDED_FLASH_EXIT},
      /* REQ_OTHER            */ {REQ_ALLOWED,         STATE_APPL_EXTENDED_FLASH_EXIT,           STATE_APPL_EXTENDED_FLASH_EXIT}
  },

  /* STATE_APPL_EXTENDED_NDC_DISABLED */ /* FL1307 */
  {
      /* REQ_10_01            */ {REQ_ALLOWED,         STATE_APPL_DEFAULT_APPLICATION_ACTIVATED, STATE_NO_CHANGE}, /* FL134, FL117 */
      /* REQ_10_02            */ {REQ_ALLOWED,         STATE_OTHER_DIAGNOSTIC_SESSION,           STATE_NO_CHANGE},
      /* REQ_10_03            */ {REQ_ALLOWED,         STATE_NO_CHANGE,                          STATE_NO_CHANGE},
      /* REQ_10_OTHER         */ {REQ_ALLOWED,         STATE_OTHER_DIAGNOSTIC_SESSION,           STATE_APPL_EXTENDED_FLASH_EXIT},
      /* REQ_28_DIS_TX_NORMAL */ {REQ_ALLOWED,         STATE_APPL_EXTENDED_FLASH_EXIT,           STATE_APPL_EXTENDED_FLASH_EXIT},
      /* REQ_31_01_0F_0C_xx   */ {REQ_ALLOWED,         STATE_APPL_EXTENDED_FLASH_EXIT,           STATE_APPL_EXTENDED_FLASH_EXIT}, /* FL279 */
      /* REQ_31_01_0F_0C_03   */ {REQ_NOT_ALLOWED_CNC, STATE_APPL_EXTENDED_FLASH_EXIT,           STATE_APPL_EXTENDED_FLASH_EXIT},
      /* REQ_31_01_10_03_01   */ {REQ_ALLOWED,         STATE_APPL_EXTENDED_FLASH_EXIT,           STATE_APPL_EXTENDED_FLASH_EXIT},
      /* REQ_85_02            */ {REQ_ALLOWED,         STATE_APPL_EXTENDED_FLASH_EXIT,           STATE_APPL_EXTENDED_FLASH_EXIT},
      /* REQ_22               */ {REQ_ALLOWED,         STATE_NO_CHANGE,                          STATE_NO_CHANGE},
      /* REQ_3E               */ {REQ_ALLOWED,         STATE_NO_CHANGE,                          STATE_NO_CHANGE},
      /* REQ_11_HARD          */ {REQ_ALLOWED,         STATE_APPL_DEFAULT_APPLICATION_ACTIVATED, STATE_NO_CHANGE},
      /* REQ_31_01_10_0E      */ {REQ_NOT_ALLOWED_CNC, STATE_APPL_EXTENDED_FLASH_EXIT,           STATE_APPL_EXTENDED_FLASH_EXIT},
      /* REQ_OTHER            */ {REQ_ALLOWED,         STATE_APPL_EXTENDED_FLASH_EXIT,           STATE_APPL_EXTENDED_FLASH_EXIT}
  },

  /* STATE_APPL_EXTENDED_ENERGY_MODE_FLASH */ /* FL1308 */
  {
      /* REQ_10_01            */ {REQ_ALLOWED,         STATE_APPL_DEFAULT_APPLICATION_ACTIVATED, STATE_NO_CHANGE}, /* FL134, FL117 */
      /* REQ_10_02            */ {REQ_NOT_ALLOWED_CNC, STATE_APPL_EXTENDED_FLASH_EXIT,           STATE_APPL_EXTENDED_FLASH_EXIT}, /* FL128 */
      /* REQ_10_03            */ {REQ_ALLOWED,         STATE_NO_CHANGE,                          STATE_NO_CHANGE},
      /* REQ_10_OTHER         */ {REQ_ALLOWED,         STATE_OTHER_DIAGNOSTIC_SESSION,           STATE_APPL_EXTENDED_FLASH_EXIT},
      /* REQ_28_DIS_TX_NORMAL */ {REQ_ALLOWED,         STATE_APPL_EXTENDED_FLASH_EXIT,           STATE_APPL_EXTENDED_FLASH_EXIT},
      /* REQ_31_01_0F_0C_xx   */ {REQ_ALLOWED,         STATE_APPL_EXTENDED_FLASH_EXIT,           STATE_APPL_EXTENDED_FLASH_EXIT}, /* FL279 */
      /* REQ_31_01_0F_0C_03   */ {REQ_ALLOWED,         STATE_APPL_EXTENDED_FLASH_EXIT,           STATE_APPL_EXTENDED_FLASH_EXIT}, /* REQ_OTHER */
      /* REQ_31_01_10_03_01   */ {REQ_ALLOWED,         STATE_APPL_EXTENDED_FLASH_EXIT,           STATE_APPL_EXTENDED_FLASH_EXIT},
      /* REQ_85_02            */ {REQ_ALLOWED,         STATE_APPL_EXTENDED_DTC_OFF_EMF,          STATE_NO_CHANGE},
      /* REQ_22               */ {REQ_ALLOWED,         STATE_NO_CHANGE,                          STATE_NO_CHANGE},
      /* REQ_3E               */ {REQ_ALLOWED,         STATE_NO_CHANGE,                          STATE_NO_CHANGE},
      /* REQ_11_HARD          */ {REQ_ALLOWED,         STATE_APPL_DEFAULT_APPLICATION_ACTIVATED, STATE_NO_CHANGE},
      /* REQ_31_01_10_0E      */ {REQ_NOT_ALLOWED_CNC, STATE_APPL_EXTENDED_FLASH_EXIT,           STATE_APPL_EXTENDED_FLASH_EXIT},
      /* REQ_OTHER            */ {REQ_ALLOWED,         STATE_APPL_EXTENDED_FLASH_EXIT,           STATE_APPL_EXTENDED_FLASH_EXIT}
  },

  /* STATE_APPL_EXTENDED_DTC_OFF_EMF */ /* FL1309 */
  {
      /* REQ_10_01            */ {REQ_ALLOWED,         STATE_APPL_DEFAULT_APPLICATION_ACTIVATED, STATE_NO_CHANGE}, /* FL134, FL117 */
      /* REQ_10_02            */ {REQ_NOT_ALLOWED_CNC, STATE_APPL_EXTENDED_FLASH_EXIT,           STATE_APPL_EXTENDED_FLASH_EXIT}, /* FL128 */
      /* REQ_10_03            */ {REQ_ALLOWED,         STATE_NO_CHANGE,                          STATE_NO_CHANGE},
      /* REQ_10_OTHER         */ {REQ_ALLOWED,         STATE_OTHER_DIAGNOSTIC_SESSION,           STATE_APPL_EXTENDED_FLASH_EXIT},
      /* REQ_28_DIS_TX_NORMAL */ {REQ_ALLOWED,         STATE_APPL_EXTENDED_NDC_DISABLED_EMF,     STATE_NO_CHANGE},
      /* REQ_31_01_0F_0C_xx   */ {REQ_ALLOWED,         STATE_APPL_EXTENDED_FLASH_EXIT,           STATE_APPL_EXTENDED_FLASH_EXIT}, /* FL279 */
      /* REQ_31_01_0F_0C_03   */ {REQ_ALLOWED,         STATE_APPL_EXTENDED_FLASH_EXIT,           STATE_APPL_EXTENDED_FLASH_EXIT}, /* REQ_OTHER */
      /* REQ_31_01_10_03_01   */ {REQ_ALLOWED,         STATE_APPL_EXTENDED_FLASH_EXIT,           STATE_APPL_EXTENDED_FLASH_EXIT},
      /* REQ_85_02            */ {REQ_ALLOWED,         STATE_APPL_EXTENDED_FLASH_EXIT,           STATE_APPL_EXTENDED_FLASH_EXIT},
      /* REQ_22               */ {REQ_ALLOWED,         STATE_NO_CHANGE,                          STATE_NO_CHANGE},
      /* REQ_3E               */ {REQ_ALLOWED,         STATE_NO_CHANGE,                          STATE_NO_CHANGE},
      /* REQ_11_HARD          */ {REQ_ALLOWED,         STATE_APPL_DEFAULT_APPLICATION_ACTIVATED, STATE_NO_CHANGE},
      /* REQ_31_01_10_0E      */ {REQ_NOT_ALLOWED_CNC, STATE_APPL_EXTENDED_FLASH_EXIT,           STATE_APPL_EXTENDED_FLASH_EXIT},
      /* REQ_OTHER            */ {REQ_ALLOWED,         STATE_APPL_EXTENDED_FLASH_EXIT,           STATE_APPL_EXTENDED_FLASH_EXIT}
  },

  /* STATE_APPL_EXTENDED_NDC_DISABLED_EMF */ /* FL1310 */
  {
      /* REQ_10_01            */ {REQ_ALLOWED,         STATE_APPL_DEFAULT_APPLICATION_ACTIVATED, STATE_NO_CHANGE}, /* FL134, FL117 */
      /* REQ_10_02            */ {REQ_ALLOWED,         STATE_OTHER_DIAGNOSTIC_SESSION,           STATE_NO_CHANGE},
      /* REQ_10_03            */ {REQ_ALLOWED,         STATE_NO_CHANGE,                          STATE_NO_CHANGE},
      /* REQ_10_OTHER         */ {REQ_ALLOWED,         STATE_OTHER_DIAGNOSTIC_SESSION,           STATE_APPL_EXTENDED_FLASH_EXIT},
      /* REQ_28_DIS_TX_NORMAL */ {REQ_ALLOWED,         STATE_APPL_EXTENDED_FLASH_EXIT,           STATE_APPL_EXTENDED_FLASH_EXIT},
      /* REQ_31_01_0F_0C_xx   */ {REQ_ALLOWED,         STATE_APPL_EXTENDED_FLASH_EXIT,           STATE_APPL_EXTENDED_FLASH_EXIT}, /* FL279 */
      /* REQ_31_01_0F_0C_03   */ {REQ_ALLOWED,         STATE_APPL_EXTENDED_FLASH_EXIT,           STATE_APPL_EXTENDED_FLASH_EXIT}, /* REQ_OTHER */
      /* REQ_31_01_10_03_01   */ {REQ_ALLOWED,         STATE_APPL_EXTENDED_FLASH_MODE_ACTIVATED, STATE_NO_CHANGE},
      /* REQ_85_02            */ {REQ_ALLOWED,         STATE_APPL_EXTENDED_FLASH_EXIT,           STATE_APPL_EXTENDED_FLASH_EXIT},
      /* REQ_22               */ {REQ_ALLOWED,         STATE_NO_CHANGE,                          STATE_NO_CHANGE},
      /* REQ_3E               */ {REQ_ALLOWED,         STATE_NO_CHANGE,                          STATE_NO_CHANGE},
      /* REQ_11_HARD          */ {REQ_ALLOWED,         STATE_APPL_DEFAULT_APPLICATION_ACTIVATED, STATE_NO_CHANGE},
      /* REQ_31_01_10_0E      */ {REQ_NOT_ALLOWED_CNC, STATE_APPL_EXTENDED_FLASH_EXIT,           STATE_APPL_EXTENDED_FLASH_EXIT},
      /* REQ_OTHER            */ {REQ_ALLOWED,         STATE_APPL_EXTENDED_FLASH_EXIT,           STATE_APPL_EXTENDED_FLASH_EXIT}
  },

  /* STATE_APPL_EXTENDED_FLASH_MODE_ACTIVATED */ /* FL1311 */
  {
      /* REQ_10_01            */ {REQ_ALLOWED,         STATE_APPL_DEFAULT_FLASH_MODE_ACTIVATED, STATE_NO_CHANGE}, /* FL134, FL115 */
      /* REQ_10_02            */ {REQ_ALLOWED,         STATE_OTHER_DIAGNOSTIC_SESSION,          STATE_NO_CHANGE},
      /* REQ_10_03            */ {REQ_ALLOWED,         STATE_NO_CHANGE,                         STATE_NO_CHANGE}, /* FL120 */
      /* REQ_10_OTHER         */ {REQ_NOT_ALLOWED_CNC, STATE_NO_CHANGE,                         STATE_NO_CHANGE},
      /* REQ_28_DIS_TX_NORMAL */ {REQ_NOT_ALLOWED_CNC, STATE_NO_CHANGE,                         STATE_NO_CHANGE},
      /* REQ_31_01_0F_0C_xx   */ {REQ_ALLOWED,         STATE_APPL_EXTENDED_FLASH_EXIT,          STATE_NO_CHANGE}, /* FL279 */
      /* REQ_31_01_0F_0C_03   */ {REQ_NOT_ALLOWED_CNC, STATE_NO_CHANGE,                         STATE_NO_CHANGE}, /* handled as REQ_OTHER */
      /* REQ_31_01_10_03_01   */ {REQ_NOT_ALLOWED_CNC, STATE_NO_CHANGE,                         STATE_NO_CHANGE}, /* handled as REQ_OTHER */
      /* REQ_85_02            */ {REQ_NOT_ALLOWED_CNC, STATE_NO_CHANGE,                         STATE_NO_CHANGE},
      /* REQ_22               */ {REQ_ALLOWED,         STATE_NO_CHANGE,                         STATE_NO_CHANGE},
      /* REQ_3E               */ {REQ_ALLOWED,         STATE_NO_CHANGE,                         STATE_NO_CHANGE},
      /* REQ_11_HARD          */ {REQ_ALLOWED,         STATE_APPL_DEFAULT_FLASH_MODE_ACTIVATED, STATE_NO_CHANGE},
      /* REQ_31_01_10_0E      */ {REQ_ALLOWED,         STATE_NO_CHANGE,                         STATE_NO_CHANGE},
      /* REQ_OTHER            */ {REQ_NOT_ALLOWED_CNC, STATE_NO_CHANGE,                         STATE_NO_CHANGE}
  },

  /* STATE_APPL_EXTENDED_FLASH_EXIT */ /* FL1312 */
  {
      /* REQ_10_01            */ {REQ_ALLOWED,         STATE_APPL_DEFAULT_APPLICATION_ACTIVATED, STATE_NO_CHANGE}, /* FL134, FL117 */
      /* REQ_10_02            */ {REQ_NOT_ALLOWED_CNC, STATE_NO_CHANGE,                          STATE_NO_CHANGE}, /* FL128 */
      /* REQ_10_03            */ {REQ_ALLOWED,         STATE_NO_CHANGE,                          STATE_NO_CHANGE},
      /* REQ_10_OTHER         */ {REQ_ALLOWED,         STATE_OTHER_DIAGNOSTIC_SESSION,           STATE_NO_CHANGE},
      /* REQ_28_DIS_TX_NORMAL */ {REQ_ALLOWED,         STATE_NO_CHANGE,                          STATE_NO_CHANGE},
      /* REQ_31_01_0F_0C_xx   */ {REQ_ALLOWED,         STATE_NO_CHANGE,                          STATE_NO_CHANGE}, /* FL279 */
      /* REQ_31_01_0F_0C_03   */ {REQ_NOT_ALLOWED_CNC, STATE_NO_CHANGE,                          STATE_NO_CHANGE},
      /* REQ_31_01_10_03_01   */ {REQ_ALLOWED,         STATE_NO_CHANGE,                          STATE_NO_CHANGE},
      /* REQ_85_02            */ {REQ_ALLOWED,         STATE_NO_CHANGE,                          STATE_NO_CHANGE},
      /* REQ_22               */ {REQ_ALLOWED,         STATE_NO_CHANGE,                          STATE_NO_CHANGE},
      /* REQ_3E               */ {REQ_ALLOWED,         STATE_NO_CHANGE,                          STATE_NO_CHANGE},
      /* REQ_11_HARD          */ {REQ_ALLOWED,         STATE_APPL_DEFAULT_APPLICATION_ACTIVATED, STATE_NO_CHANGE},
      /* REQ_31_01_10_0E      */ {REQ_NOT_ALLOWED_CNC, STATE_NO_CHANGE,                          STATE_NO_CHANGE},
      /* REQ_OTHER            */ {REQ_ALLOWED,         STATE_NO_CHANGE,                          STATE_NO_CHANGE}
  },

  /* STATE_OTHER_DIAGNOSTIC_SESSION */
  {
      /* REQ_10_01            */ {REQ_ALLOWED,             STATE_APPL_DEFAULT_APPLICATION_ACTIVATED, STATE_NO_CHANGE},
      /* REQ_10_02            */ {REQ_NOT_ALLOWED_SFNSIAS, STATE_NO_CHANGE,                          STATE_NO_CHANGE},
      /* REQ_10_03            */ {REQ_ALLOWED,             STATE_APPL_EXTENDED_STARTED,              STATE_NO_CHANGE},
      /* REQ_10_OTHER         */ {REQ_ALLOWED,             STATE_NO_CHANGE,                          STATE_NO_CHANGE},
      /* REQ_28_DIS_TX_NORMAL */ {REQ_ALLOWED,             STATE_NO_CHANGE,                          STATE_NO_CHANGE},
      /* REQ_31_01_0F_0C_xx   */ {REQ_ALLOWED,             STATE_NO_CHANGE,                          STATE_NO_CHANGE}, /* FL279 */
      /* REQ_31_01_0F_0C_03   */ {REQ_ALLOWED,             STATE_NO_CHANGE,                          STATE_NO_CHANGE},
      /* REQ_31_01_10_03_01   */ {REQ_ALLOWED,             STATE_NO_CHANGE,                          STATE_NO_CHANGE},
      /* REQ_85_02            */ {REQ_NOT_ALLOWED_SNSIAS,  STATE_NO_CHANGE,                          STATE_NO_CHANGE}, /* FL258 */
      /* REQ_22               */ {REQ_ALLOWED,             STATE_NO_CHANGE,                          STATE_NO_CHANGE},
      /* REQ_3E               */ {REQ_ALLOWED,             STATE_NO_CHANGE,                          STATE_NO_CHANGE},
      /* REQ_11_HARD          */ {REQ_ALLOWED,             STATE_APPL_DEFAULT_APPLICATION_ACTIVATED, STATE_NO_CHANGE},
      /* REQ_31_01_10_0E      */ {REQ_ALLOWED,             STATE_NO_CHANGE,                          STATE_NO_CHANGE},
      /* REQ_OTHER            */ {REQ_ALLOWED,             STATE_NO_CHANGE,                          STATE_NO_CHANGE}
  }
};

/* PRQA S 5087 2 */
#define StdDiag_STOP_SEC_CONST_UNSPECIFIED
#include "StdDiag_MemMap.h"

/*------------------------------------------------------------------------------
                      Local Function Prototypes
------------------------------------------------------------------------------*/
/* PRQA S 5087 2 */
#define StdDiag_START_SEC_CODE
#include "StdDiag_MemMap.h"

static void StdDiag_LockErrorMemory( void );

static void StdDiag_UnlockErrorMemory( void );

static boolean StdDiag_IsFlashModeActive( void );

static void StdDiag_EnterApplicationActivatedState( void );

static void StdDiag_EnterFlashModeActivatedState( void );

static void StdDiag_TriggerStateTransition(
    StdDiag_RequestType request,
    UDS_ConfirmationType confirmation );

static StdDiag_RequestType StdDiag_EvaluateRequest_SID_SESSIONCONTROL(
    const uint8* RequestData,
    uint16 DataSize );

static StdDiag_RequestType StdDiag_EvaluateRequest_SID_COMMUNICATIONCONTROL(
    const uint8* RequestData,
    uint16 DataSize );

static StdDiag_RequestType StdDiag_EvaluateRequest_SET_ENERGY_MODE(
    const uint8* RequestData,
    uint16 DataSize );

static StdDiag_RequestType StdDiag_EvaluateRequest_SET_EXTENDED_MODE(
    const uint8* RequestData,
    uint16 DataSize );

static StdDiag_RequestType StdDiag_EvaluateRequest_SID_ROUTINECONTROL(
    const uint8* RequestData,
    uint16 DataSize );

static StdDiag_RequestType StdDiag_EvaluateRequest_SID_CONTROLDTCSETTING(
    const uint8* RequestData,
    uint16 DataSize );

static StdDiag_RequestType StdDiag_EvaluateRequest_SID_ECURESET(
    const uint8* RequestData,
    uint16 DataSize );

static StdDiag_RequestType StdDiag_EvaluateRequest(
    uint8 SID,
    const uint8* RequestData,
    uint16 DataSize );

static StdDiag_StateType StdDiag_EvaluateNextState(
    StdDiag_RequestType request,
    UDS_ConfirmationType confirmation );

static void StdDiag_AdjustOnSessionChange(
    StdDiag_RequestType request,
    StdDiag_StateType* nextState);

/*------------------------------------------------------------------------------
                      Local Functions
------------------------------------------------------------------------------*/

/**
 * \brief disable writing of DTCs
 *
 * This function disables writing of DTCs by setting the enable condition
 * to FALSE.
 *
 * \global_w StdDiag_currentEnableConditionState
 *
 */
static void StdDiag_LockErrorMemory( void )
{
  /* lock error memory */
  StdDiag_currentEnableConditionState = FALSE;
  StdDiag_ErrMem_LockErrorMemory();

  return;
}

/**
 * \brief enable writing of DTCs
 *
 * This function enables writing of DTCs by setting the enable condition
 * to TRUE.
 *
 * \global_w StdDiag_currentEnableConditionState
 *
 */
static void StdDiag_UnlockErrorMemory( void )
{
  /* unlock error memory */
  StdDiag_currentEnableConditionState = TRUE;
  StdDiag_ErrMem_UnlockErrorMemory();

  return;
}

/**
 * \brief evaluates the internal id of an incoming request 0x10
 *
 * This function evaluates the internal id of an incoming diagnostic session
 * control request (SID 0x10)
 *
 * \param[in] RequestData pointer to incoming data stream
 * \param[in] DataSize size of the incoming data
 *
 * \retval StdDiag_RequestType internal id of the incoming request
 *
 * \pre to be called by function StdDiag_EvaluateRequest
 *
 */
static StdDiag_RequestType StdDiag_EvaluateRequest_SID_SESSIONCONTROL(
    const uint8* RequestData,
    uint16 DataSize )
{
  StdDiag_RequestType request;

  if( DataSize == 1 )
  {
    /* check subfunction value */
    switch( (*RequestData) & (~BITMASK_SUPPRESSPOSRESP) )
    {
      case APPL_DEFAULT_SESSION:
        request = REQ_10_01;
        break;

      case PROGRAMMING_SESSION:
        request = REQ_10_02;
        break;

      case APPL_EXTENDED_DIAG_SESSION:
        request = REQ_10_03;
        break;

      default:
        request = REQ_10_OTHER;
        break;
    }
  }
  else
  {
    request = REQ_OTHER;
  }

  return request;
}

/**
 * \brief evaluates the internal id of an incoming request 0x28
 *
 * This function evaluates the internal id of an incoming communication
 * control request (SID 0x28)
 *
 * \param[in] RequestData pointer to incoming data stream
 * \param[in] DataSize size of the incoming data
 *
 * \retval StdDiag_RequestType internal id of the incoming request
 *
 * \pre to be called by function StdDiag_EvaluateRequest
 *
 */
static StdDiag_RequestType StdDiag_EvaluateRequest_SID_COMMUNICATIONCONTROL(
    const uint8* RequestData,
    uint16 DataSize )
{
  StdDiag_RequestType request = REQ_OTHER;

  if( DataSize == 2 )
  {
    /*
       MISRA-C:2004 Rule 17.4: array subscription is necessary to read more
       than one byte from the given buffer
    */
    /* PRQA S 0492 1 */
    if( (RequestData[1] & NORMAL_COMM_MSG_FLAG) != 0u )
    {
      /* check subfunction value */
      switch( (*RequestData) & (~BITMASK_SUPPRESSPOSRESP) )
      {
        case ENABLE_RX_DISABLE_TX:
          /* no break */
        case DISABLE_RX_AND_TX:
          request = REQ_28_DIS_TX_NORMAL;
          break;

        default:
          break;
      }
    }
  }

  return request;
}

/**
 * \brief evaluates the internal id of an incoming request 0x31 01 0F 0C
 *
 * This function evaluates the internal id of an incoming routine control
 * request for setting the energy mode (0x31 01 0F 0C)
 *
 * \param[in] RequestData pointer to incoming data stream
 * \param[in] DataSize size of the incoming data
 *
 * \retval StdDiag_RequestType internal id of the incoming request
 *
 * \pre to be called by function StdDiag_EvaluateRequest_SID_ROUTINECONTROL
 *
 */
static StdDiag_RequestType StdDiag_EvaluateRequest_SET_ENERGY_MODE(
    const uint8* RequestData,
    uint16 DataSize )
{
  StdDiag_RequestType request;

  if( DataSize == 4u )
  {
    /*
       MISRA-C:2004 Rule 17.4: array subscription is necessary to read more
       than one byte from the given buffer
    */
    /* PRQA S 0492 1 */
    if (RCO_ENERGY_MODE_FLASH == RequestData[3]) {
      request = REQ_31_01_0F_0C_03;
    } else {
      request = REQ_31_01_0F_0C_xx;
    }
  }

  return request;
}

/**
 * \brief evaluates the internal id of an incoming request 0x31 01 10 03
 *
 * This function evaluates the internal id of an incoming routine control
 * request for setting the extended energy mode (0x31 01 10 03)
 *
 * \param[in] RequestData pointer to incoming data stream
 * \param[in] DataSize size of the incoming data
 *
 * \retval StdDiag_RequestType internal id of the incoming request
 *
 * \pre to be called by function StdDiag_EvaluateRequest_SID_ROUTINECONTROL
 *
 */
static StdDiag_RequestType StdDiag_EvaluateRequest_SET_EXTENDED_MODE(
    const uint8* RequestData,
    uint16 DataSize )
{
  StdDiag_RequestType request = REQ_OTHER;

  if( DataSize == 4u )
  {
    /*
       MISRA-C:2004 Rule 17.4: array subscription is necessary to read more
       than one byte from the given buffer
    */
    /* PRQA S 0492 1 */
    if(RequestData[3] == RCO_EXTENDED_MODE_1 )
    {
      request = REQ_31_01_10_03_01;
    }
  }

  return request;
}

/**
 * \brief evaluates the internal id of an incoming request 0x31
 *
 * This function evaluates the internal id of an incoming routine control
 * request (SID 0x31)
 *
 * \param[in] RequestData pointer to incoming data stream
 * \param[in] DataSize size of the incoming data
 *
 * \retval StdDiag_RequestType internal id of the incoming request
 *
 * \pre to be called by function StdDiag_EvaluateRequest
 *
 */
static StdDiag_RequestType StdDiag_EvaluateRequest_SID_ROUTINECONTROL(
    const uint8* RequestData,
    uint16 DataSize )
{
  StdDiag_RequestType request = REQ_OTHER;

  /* check if we have a routine control with subfunction 'start' */
  if( (DataSize >= 3u) && (((*RequestData) & (~BITMASK_SUPPRESSPOSRESP)) == ROUTINECONTROL_START) )
  {
    /*
       MISRA-C:2004 Rule 17.4 (2x): array subscription is necessary to read more
       than one byte from the given buffer
    */
    /* PRQA S 0492 1 */
    uint16 routineId = ((uint16)(RequestData[1]) << 8) + RequestData[2];

    switch( routineId )
    {
      case RID_SET_ENERGY_MODE:
        request = StdDiag_EvaluateRequest_SET_ENERGY_MODE(RequestData, DataSize);
        break;

      case RID_SET_EXTENDED_MODE:
        request = StdDiag_EvaluateRequest_SET_EXTENDED_MODE(RequestData, DataSize);
        break;

      case RID_ACTIVATE_PARALLEL_FLASHMODE:
        if( DataSize == 3u )
        {
          request = REQ_31_01_10_0E;
        }
        break;

      default:
        break;
    }
  }

  return request;
}

/**
 * \brief evaluates the internal id of an incoming request 0x85
 *
 * This function evaluates the internal id of an incoming control DTCSetting
 * request (SID 0x85)
 *
 * \param[in] RequestData pointer to incoming data stream
 * \param[in] DataSize size of the incoming data
 *
 * \retval StdDiag_RequestType internal id of the incoming request
 *
 * \pre to be called by function StdDiag_EvaluateRequest
 *
 */
static StdDiag_RequestType StdDiag_EvaluateRequest_SID_CONTROLDTCSETTING(
    const uint8* RequestData,
    uint16 DataSize )
{
  StdDiag_RequestType request;

  if( (DataSize == 1) && (((*RequestData) & (~BITMASK_SUPPRESSPOSRESP)) == DTC_OFF) )
  {
    request = REQ_85_02;
  }
  else
  {
    request = REQ_OTHER;
  }

  return request;
}

/**
 * \brief evaluates the internal id of an incoming request 0x11
 *
 * This function evaluates the internal id of an incoming ECU reset
 * request (SID 0x11)
 *
 * \param[in] RequestData pointer to incoming data stream
 * \param[in] DataSize size of the incoming data
 *
 * \retval StdDiag_RequestType internal id of the incoming request
 *
 * \pre to be called by function StdDiag_EvaluateRequest
 *
 */
static StdDiag_RequestType StdDiag_EvaluateRequest_SID_ECURESET(
    const uint8* RequestData,
    uint16 DataSize )
{
  StdDiag_RequestType request;

  if( (DataSize == 1) && (((*RequestData) & (~BITMASK_SUPPRESSPOSRESP)) == HARD_RESET) )
  {
    request = REQ_11_HARD;
  }
  else
  {
    request = REQ_OTHER;
  }

  return request;
}

/**
 * \brief evaluates the internal id of an incoming request
 *
 * This function evaluates the internal id of an incoming diagnostic
 * request.
 *
 * \param[in] SID incoming service identifier
 * \param[in] RequestData pointer to incoming data stream
 * \param[in] DataSize size of the incoming data
 *
 * \retval StdDiag_RequestType internal id of the incoming request
 *
 * \pre to be called by function StdDiag_DiagRequest_Indication
 *
 */
static StdDiag_RequestType StdDiag_EvaluateRequest(
    uint8 SID,
    const uint8* RequestData,
    uint16 DataSize )
{
  StdDiag_RequestType request;

  switch( SID )
  {
    /* session control (0x10 plus 1 byte mandatory) */
    case SID_SESSIONCONTROL:
      request = StdDiag_EvaluateRequest_SID_SESSIONCONTROL(RequestData, DataSize);
      break;

      /* communication control (0x28 plus 2 byte mandatory) */
    case SID_COMMUNICATIONCONTROL:
      request = StdDiag_EvaluateRequest_SID_COMMUNICATIONCONTROL(RequestData, DataSize);
      break;

      /* routine control (0x31 plus 3 byte mandatory) */
    case SID_ROUTINECONTROL:
      request = StdDiag_EvaluateRequest_SID_ROUTINECONTROL(RequestData, DataSize);
      break;

      /* control DTC setting (0x85 plus 1 byte mandatory) */
    case SID_CONTROLDTCSETTING:
      request = StdDiag_EvaluateRequest_SID_CONTROLDTCSETTING(RequestData, DataSize);
      break;

    case SID_READDATABYIDENTIFIER:
      request = REQ_22;
      break;

    case SID_TESTERPRESENT:
      request = REQ_3E;
      break;

    case SID_ECURESET:
      request = StdDiag_EvaluateRequest_SID_ECURESET(RequestData, DataSize);
      break;

    default:
      request = REQ_OTHER;
      break;
  }

  return request;
}

/**
 * \brief evaluates next state of the state machine
 *
 * This function evaluates the next state of the state machine, depending
 * on the current request and the current state.
 *
 * \global_r StdDiag_currentState
 *
 * \param[in] request Id of the current request
 * \param[in] externalTrigger TRUE  if state triggering is caused by an external notification
 *                                  as a result of a positive response.
 *                            FALSE if state triggering is caused internally because job
 *                                  will result in negative response.
 *
 * \retval StdDiag_StateType next state of the state machine
 *
 * \pre to be called by function StdDiag_TriggerStateTransition
 *
 * \lhref FL136
 *
 */
static StdDiag_StateType StdDiag_EvaluateNextState(
    StdDiag_RequestType request,
    UDS_ConfirmationType confirmation)
{
  StdDiag_StateType nextState;

  /* first get next state from transition table */
  if (UDS_DIAG_Confirm_PosResp_Suppressed >= confirmation) {
    nextState = StdDiag_RequestTransitionTables[StdDiag_currentState][request].nextState;
  }
  else
  {
    nextState = StdDiag_RequestTransitionTables[StdDiag_currentState][request].nextStateNegResp;
  }

  /* translate STATE_NO_CHANGE to real state */
  if (STATE_NO_CHANGE == nextState) {
    nextState = StdDiag_currentState;
  }

  if (UDS_DIAG_Confirm_PosResp_Suppressed >= confirmation)
  {
    /* adjust next state in case of session change */
    StdDiag_AdjustOnSessionChange(request, &nextState);
  }

  /* adjust settings on change to default session */
  if (StdDiag_currentState != nextState) {
	  

    switch (nextState) {
      case STATE_APPL_DEFAULT_APPLICATION_ACTIVATED:
        StdDiag_EnterApplicationActivatedState();
        break;

      case STATE_APPL_DEFAULT_FLASH_MODE_ACTIVATED:
        StdDiag_EnterFlashModeActivatedState();
        break;

      default:
        break;
    }
  }

  return nextState;
}

/**
 * \brief adjusts next state of the state machine
 *
 * This function adjusts the next state of the state machine if triggered by
 * external notification.
 *
 * \global_r StdDiag_currentState
 *
 * \param[in] request Id of the current request
 * \param[out] nextState pointer to variable that holds the adjusted next state.
 *
 * \lhref FL106, FL107, FL1318
 *
 * \pre called by function StdDiag_EvaluateNextState
 *
 */
static void StdDiag_AdjustOnSessionChange(
    StdDiag_RequestType request,
    StdDiag_StateType* nextState)
{
  switch (request) {
    case REQ_10_01:
      if( TRUE == StdDiag_IsFlashModeActive() ) {
        *nextState = STATE_APPL_DEFAULT_FLASH_MODE_ACTIVATED;
      } else {
        *nextState = STATE_APPL_DEFAULT_APPLICATION_ACTIVATED;
      }
      break;

    case REQ_10_03:
      /* adjust next state on transition from other session to extended session (FL1318) */
      if (STATE_OTHER_DIAGNOSTIC_SESSION == StdDiag_currentState)
      {
        if ( TRUE == StdDiag_IsFlashModeActive() ) {
          *nextState = STATE_APPL_EXTENDED_FLASH_MODE_ACTIVATED;
        } else if (STDDIAG_OMC_MODE_BMW_FLASH == StdDiag_Omc_GetCurrentOperatingMode()) {
          *nextState = STATE_APPL_EXTENDED_ENERGY_MODE_FLASH;
        } else {
          *nextState = STATE_APPL_EXTENDED_STARTED;
        }
      }
      /* adjust next state on transition from default session to extended session */
      if (STATE_APPL_DEFAULT_APPLICATION_ACTIVATED == StdDiag_currentState)
      {
        if (STDDIAG_OMC_MODE_BMW_FLASH == StdDiag_Omc_GetCurrentOperatingMode()) {
          *nextState = STATE_APPL_EXTENDED_ENERGY_MODE_FLASH;
        } else {
          *nextState = STATE_APPL_EXTENDED_STARTED;
        }
      }
      break;

    default:
      break;
  }
}

/**
 * \brief internal state machine of the StdDiag module
 *
 * This function does the internal state machine handling, and is called on
 * every diagnostic request and on a session change to the default session due
 * to a timeout. It triggers the necessary actions of the current state,
 * evaluates the next state, and sets the permissions for the next diagnostic
 * request.
 *
 * \global_w StdDiag_currentState, StdDiag_RequestPermission
 *
 * \param[in] request Id of the current request
 * \param[in] externalTrigger TRUE  if state triggering is caused by an external notification
 *                                  as a result of a positive response.
 *                            FALSE if state triggering is caused internally because job
 *                                  will result in negative response.
 *
 * \lhref FL1306
 *
 */
static void StdDiag_TriggerStateTransition(
    StdDiag_RequestType request,
    UDS_ConfirmationType confirmation )
{
  StdDiag_StateType nextState;
  uint16 index;

  /* evaluate next state of the state machine */
  nextState = StdDiag_EvaluateNextState(request, confirmation);


  /* set request permissions to predefined values of next state */
  for (index=0; index< STDDIAG_NUMBER_OF_REQUESTS; index++)
  {
    StdDiag_RequestPermission[index] = StdDiag_RequestTransitionTables[nextState][index].permission;
  }

  /* set new current state */
  StdDiag_currentState = nextState;
}

/**
 * \brief checks if the FlashMode is active
 *
 * This function checks if the FlashMode is active by retrieving information
 * from the Omc module.
 *
 * \retval TRUE flash mode is active
 * \retval FALSE flash mode is not active
 *
 * \lhref FL136
 *
 */
static boolean StdDiag_IsFlashModeActive(
    void )
{
  StdDiag_Omc_OperatingModeType currentOpMode;
  StdDiag_Omc_ExtendedOperatingModeType currentExtOpMode;

  currentOpMode = StdDiag_Omc_GetCurrentOperatingMode();
  currentExtOpMode = StdDiag_Omc_GetCurrentExtendedOperatingMode();

  if ((currentOpMode == STDDIAG_OMC_MODE_BMW_FLASH) &&
      (currentExtOpMode == STDDIAG_OMC_MODE_EXTENSION_1)) {
    return TRUE;
  } else {
    return FALSE;
  }
}

/**
 * \brief enters application activated state
 *
 * This function handles a session change to the application default subsession
 * ApplicationActive, i.e. unlocking the error memory, enabling diagnostic
 * communication and canceling RoE suspension.
 *
 * \lhref FL118, FL134
 *
 */
static void StdDiag_EnterApplicationActivatedState(
    void )
{
  /* ControlDTCSetting(On) */
  StdDiag_UnlockErrorMemory();

  /* enable diagnostic communication */
  StdDiag_Mgmt_EnableNonDiagnosticCommunication();
}

/**
 * \brief enters flash mode activated state
 *
 * This function handles a session change to the application default subsession
 * FlashModeActive, i.e. locking the error memory, disabling diagnostic
 * communication and suspending RoE.
 *
 * \lhref FL257, FL263, FL274
 *
 */
static void StdDiag_EnterFlashModeActivatedState(
    void )
{
  /* ControlDTCSetting(Off) */
  StdDiag_LockErrorMemory();

  /* disable diagnostic communication */
  StdDiag_Mgmt_DisableNonDiagnosticCommunication();
}


/*------------------------------------------------------------------------------
                      Global Functions
-------------------------------------------------------------------------------*/

/**
 * \brief raw incoming diagnostic request handler
 *
 * This function handles incoming diagnostic requests
 *
 * \global_r  StdDiag_RequestPermission
 *
 * \param[in]  serviceId Value of service identifier
 * \param[in]  requestData request data (diagnostic buffer), except SID
 * \param[in]  dataSize number of valid bytes in RequestData
 * \param[in]  sourceAddress unique identifier of the requester
 * \param[out] errorCode Error code according to Dcm specification. Only set in
 *                       case of return value E_NOT_OK.
 *
 * \retval E_OK request may be executed
 * \retval E_NOT_OK request may not be executed
 *
 * \remarks This function is called when a diagnostic request has been received.
 *
 */
UDS_ReturnType StdDiag_DiagRequest_Indication(
    uint8 serviceId,
    const uint8* requestData,
    uint16 dataSize,
    uint16 sourceAddress,
    UDS_ErrorCodeType* errorCode )
{
  UDS_ReturnType retVal;
  StdDiag_RequestPermissionType requestPermission;

  StdDiag_pendingSourceAddress = sourceAddress;

  /* evaluate service */
  StdDiag_currentRequest = StdDiag_EvaluateRequest(serviceId, requestData, dataSize);

  /* get permission */
  requestPermission = StdDiag_RequestPermission[StdDiag_currentRequest];
  if( requestPermission == REQ_ALLOWED )
  {
    retVal = UDS_DIAG_JOB_FINISHED_OK;
  }
  else
  {
    *errorCode = (UDS_ErrorCodeType) requestPermission;
    retVal = UDS_DIAG_JOB_FINISHED_E_NOT_OK;
  }

  return retVal;
  /* PRQA S 5204 1 */ /* number of API parameters is defined by AUTOSAR */
}

/**
 * \brief raw diagnostic request confirmation
 *
 * This function indicates completion of a diagnostic request to a generic function.
 *
 * \param[in] serviceId     UDS service identifier
 * \param[in] dataLength    size of requestData
 * \param[in] confirmation  indicates the final outcome of the UDS response
 */
void StdDiag_DiagRequest_Confirmation(
    uint8 serviceId,
    uint16 sourceAddress,
    UDS_ConfirmationType confirmation )
{
  (void) serviceId;

  if ((StdDiag_pendingSourceAddress == sourceAddress) &&
      (TRUE == StdDiag_IsInitialized()))
  {
    /* trigger state machine and pass current request and result */
    StdDiag_TriggerStateTransition(StdDiag_currentRequest, confirmation);

    /* reset current request */
    StdDiag_currentRequest = REQ_OTHER;
  }
}

/**
 * \brief Session change notification
 *
 * This function shall be called whenever the diagnostic session changes to default session
 *
 */
void StdDiag_NotifyDefaultSessionEnter(void)
{
  StdDiag_TriggerStateTransition(REQ_10_01, UDS_DIAG_Confirm_PosResp_OK);
}

/**
 * \brief Condition check for operating mode change
 *
 * This function shall be called whenever the operating mode or extended
 * operating mode shall be changed
 *
 * \param[in] currentOpMode current operating mode
 * \param[in] currentExtOpMode current extended operating mode
 * \param[in] newOpMode new operating mode
 * \param[in] newExtOpMode new extended operating mode
 *
 * \retval STDDIAG_APPL_OK operating mode switch is allowed
 * \retval STDDIAG_APPL_E_NOT_OK operating mode switch is not allowed
 * \retval STDDIAG_APPL_RUNNING evaluation by application is pending
 *
 * \lhref FL215, FL216, FL269, FL270, FL272, FL278
 *
 */
StdDiag_App_ReturnType StdDiag_AllowOpModeSwitch(
    uint8 currentOpMode,
    uint8 currentExtOpMode,
    uint8 newOpMode,
    uint8 newExtOpMode)
{
  StdDiag_App_ReturnType retVal = STDDIAG_APPL_OK;

  if (currentOpMode != STDDIAG_OMC_MODE_BMW_FLASH)
  {
    /* handle switch to flash mode, establish intrinsic safety */
    if (STDDIAG_OMC_MODE_BMW_FLASH == newOpMode)
    {
      /* check PWF state precondition */
      if( !StdDiag_IsPWFPreconditionValid() )
      {
        retVal = STDDIAG_APPL_E_NOT_OK;
      }
#if( STDDIAG_USER_ESTABLISH_INTRINSIC_SAFETY == STD_ON )
      else
      {
        /* call application */
        retVal = StdDiag_App_EstablishIntrinsicSafety();
      }
#endif /* STDDIAG_USER_ESTABLISH_INTRINSIC_SAFETY == STD_ON */
    }
  }
  else
  {
    /* check if Flash Mode activation is requested */
    if (STDDIAG_OMC_MODE_EXTENSION_1 == newExtOpMode) {
      /* flash mode activation only allowed in the following two states (FL269, FL270, FL272) */
      if ((STATE_APPL_EXTENDED_NDC_DISABLED_EMF != StdDiag_currentState) &&
          (STATE_OTHER_DIAGNOSTIC_SESSION != StdDiag_currentState))
      {
        retVal = STDDIAG_APPL_E_NOT_OK;
      }
    }

    /* check behavior in active flash mode */
    if (STDDIAG_OMC_MODE_EXTENSION_1 == currentExtOpMode) {
      /* avoid deactivating flash mode by resetting extended operating mode (FL278) */
      if ((STDDIAG_OMC_MODE_BMW_FLASH == newOpMode) &&
          (STDDIAG_OMC_MODE_EXTENSION_1 != newExtOpMode))
      {
        retVal = STDDIAG_APPL_E_NOT_OK;
      }
    }
  }
  


  return retVal;
}

/**
 * \brief Cancellation of operating mode change
 *
 * This function shall be called whenever the request to change the operating mode
 * or extended operating mode has been rejected
 *
 * \param[in] currentOpMode current operating mode
 * \param[in] currentExtOpMode current extended operating mode
 * \param[in] requestedOpMode requested operating mode
 * \param[in] requestedExtOpMode requested extended operating mode
 *
 * \retval STDDIAG_APPL_OK operating mode switch is allowed
 * \retval STDDIAG_APPL_RUNNING evaluation by application is pending
 *
 * \lhref FL217
 *
 */
extern StdDiag_App_ReturnType StdDiag_OpModeSwitchCancelled(
    uint8 currentOpMode,
    uint8 currentExtOpMode,
    uint8 requestedOpMode,
    uint8 requestedExtOpMode)
{
  StdDiag_App_ReturnType retVal = STDDIAG_APPL_OK;

  (void) currentExtOpMode;
  (void) requestedExtOpMode;

#if( STDDIAG_USER_ESTABLISH_INTRINSIC_SAFETY == STD_ON )
  /* revert intrinsic safety if switch to flash mode is cancelled */
  if ((STDDIAG_OMC_MODE_BMW_FLASH != currentOpMode) &&
      (STDDIAG_OMC_MODE_BMW_FLASH == requestedOpMode)){
    retVal = StdDiag_App_RevertIntrinsicSafety();
  }
#else
  (void) currentOpMode;
  (void) requestedOpMode;
#endif /* STDDIAG_USER_ESTABLISH_INTRINSIC_SAFETY == STD_ON */

  return retVal;
}
/**
 * \brief Get current subsession value
 *
 * Internal function to get the current subsession value
 *
 * \global_r  StdDiag_currentState
 *
 * \retval current subsession value
 *
 */
uint8 StdDiag_GetActiveSessionState(void)
{
  return StdDiag_SubSessionValue[StdDiag_currentState];
}

/**
 * \brief Check programming precondition PWF state
 *
 * Internal function to check the current PWF state
 *
 * \global_r  StdDiag_currentState
 *
 * \retval TRUE precondition fulfilled, PWF state is PAD
 * \retval FALSE precondition not fulfilled
 *
 * \lhref FL195, FL231
 *
 */
boolean StdDiag_IsPWFPreconditionValid()
{
  StdDiag_Stm_VehicleStateType currentVehicleState = StdDiag_Stm_GetVehicleState();

  /* skip check of PWF state if communication is disabled, FL195 */
  if( !StdDiag_IsNDCDisabled() )
  {
    /* check PWF state, FL231 */
    if( (STDDIAG_STM_MODE_PAD != currentVehicleState) &&
        (STDDIAG_STM_MODE_UNAVAILABLE != currentVehicleState) )
    {
      return FALSE;
    }
  }

  return TRUE;
}

/**
 * \brief Check non diagnostic communication state
 *
 * Internal function to check whether non diagnostic communication is disabled
 *
 * \global_r  StdDiag_currentState
 *
 * \retval TRUE non diagnostic communication is disabled
 * \retval FALSE non diagnostic communication is enabled
 *
 */
boolean StdDiag_IsNDCDisabled()
{
  /* check if communication is disabled */
  if( (StdDiag_currentState == STATE_APPL_EXTENDED_NDC_DISABLED) ||
      (StdDiag_currentState == STATE_APPL_EXTENDED_NDC_DISABLED_EMF) ||
      (StdDiag_currentState == STATE_APPL_EXTENDED_FLASH_MODE_ACTIVATED) ||
      (StdDiag_currentState == STATE_APPL_DEFAULT_FLASH_MODE_ACTIVATED))
  {
    return TRUE;
  }

  return FALSE;
}

/**
 * \brief Initialization function
 *
 * This function initializes the StdDiag state machine
 *
 * \lhref FL106, FL107
 *
 */
void StdDiag_StateMachineInit( void )
{
  uint16 index;

  /* evaluate initial state */
  if( StdDiag_IsFlashModeActive() == TRUE )
  {
    StdDiag_EnterFlashModeActivatedState();
    StdDiag_currentState = STATE_APPL_DEFAULT_FLASH_MODE_ACTIVATED;
  }
  else
  {
    StdDiag_EnterApplicationActivatedState();
    StdDiag_currentState = STATE_APPL_DEFAULT_APPLICATION_ACTIVATED;
  }

  /* set request permissions to predefined values of initial state */
  for( index=0; index< STDDIAG_NUMBER_OF_REQUESTS; index++ )
  {
    StdDiag_RequestPermission[index] = StdDiag_RequestTransitionTables[StdDiag_currentState][index].permission;
  }

  /* reset current request */
  StdDiag_currentRequest = REQ_OTHER;
}

/**
 * \brief Deactivation function
 *
 * This function deactivates the StdDiag state machine
 *
 */
void StdDiag_StateMachineStop( void )
{
  uint16 index;

  /* set request permissions to predefined values */
  for( index=0; index< STDDIAG_NUMBER_OF_REQUESTS; index++ )
  {
    StdDiag_RequestPermission[index] = StdDiag_InitialRequestPermission[index];
  }

  /* reset current request */
  StdDiag_currentRequest = REQ_OTHER;
}

/* PRQA S 5087 2 */
#define StdDiag_STOP_SEC_CODE
#include "StdDiag_MemMap.h"

