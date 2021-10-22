/**********************************************************************************************************************
 * Copyright 2016-2018 Nxtr
 * Nxtr Confidential
 *
 * Module File Name  : CDD_MotAg0Meas_private.h
 * Module Description: Private header file for the CDD_MotAg0Meas component
 * Project           : CBD
 * Author            : Avinash James
 **********************************************************************************************************************
 * Version Control:
 * %version:          5 %
 * %derived_by:       zzr258 %
 *---------------------------------------------------------------------------------------------------------------------
 * Date      Rev      Author    Change Description                                                             SCR #
 * --------  -------  --------  ----------------------------------------------------------------------------  ---------
 * 06/07/16  1        AJM       Initial version                                                               EA4#5027
 * 01/19/18  2        AJM       Added constant SNSRERRMASK_CNT_U32                                            EA4#19623
 * 04/25/17  3        KByrski   Updated as per Design 5.0.0                                                   EA4#15121,EA4#18232,EA4#22026
 * 05/15/17  4        KByrski   Updated as per Design 6.1.0                                                   EA4#23813
 * 06/28/18  5        FCD       Temporarily changed MOTAG0TURNCNTRVLTGFLTPASSSTEP_CNT_U16 from 655 to 2620    EA4#25381
 *********************************************************************************************************************/

/******************************************* Multiple Include Protection *********************************************/
#ifndef CDD_MOTAG0MEAS_PRIVATE_H
#define CDD_MOTAG0MEAS_PRIVATE_H

/************************************************ Include Statements *************************************************/
#include "Std_Types.h"


/********************************************* Embedded Local Constants **********************************************/
#define COEFFTBLELMSIZE_CNT_U08                 (2U)
#define COEFFTBLSIZE_CNT_U08                    (13U)
#define CORRNTBLAGSTEPSIZE_MATRAD_F32           (0.04908738521F)
#define CORRNTBLSIDXOFFS_CNT_U16                (7U)
#define CORRNTBLSIZEMASK_CNT_U08                (127U)
#define CORRNTBLSIZE_CNT_U16                    (128U)
#define MCTL2BASE_CNT_U32                       (2147549189U)
#define MCTL2CMDTRANSPT_CNT_U32                 (2147614733U)
#define MCTL2RSTERR_CNT_U32                     (2147614726U)
#define MCTL2RSTTURNCNTR_CNT_U32                (2147680265U)
#define MOTAG0ERRTHD_MOTREV_U0P16               ((u0p16)2163U)
#define MOTAG0MECLQUARTERPIMASK_MOTREV_U0P16    ((u0p16)8191U)
#define MOTAG0PRTCLFLTFAILSTEP_CNT_U16          (3276U)
#define MOTAG0PRTCLFLTPASSSTEP_CNT_U16          (655U)
#define MOTAG0SLEEPWAIT_MICROSEC_U32            (100U)
#define MOTAG0TURNCNTRFLOATCNVN_CNT_F32         (1.525878906e-05F)
#define MOTAG0TURNCNTRPRTCLFLTFAILSTEP_CNT_U16  (3277U)
#define MOTAG0TURNCNTRPRTCLFLTPASSSTEP_CNT_U16  (655U)
#define MOTAG0TURNCNTRVLTGFLTFAILSTEP_CNT_U16   (3277U)
#define MOTAG0TURNCNTRVLTGFLTPASSSTEP_CNT_U16   (2620U)
#define MOTAGDELTAPERCORRNPT_CNT_U16            (512U)
#define MOTAGIDXMASK_CNT_U16                    (65024U)
#define MOTAGLIMMASK_CNT_S32                    ((sint32)65535)
#define MOTAGOFFSENAMASK_CNT_U08                ((uint8)5U)
#define MOTAGOFFS_CNT_S32                       ((sint32)32768)
#define ODDPARCALCNMASK_CNT_U32                 (4369U)
#define RAWAGREGIDX_CNT_U08                     (2U)
#define RAWERRREGIDX_CNT_U08                    (3U)
#define RAWERRSTSIDX_CNT_U08                    (0U)
#define RAWERRWARNIDX_CNT_U08                   (4U)
#define RAWTURNCNTRREGIDX_CNT_U08               (1U)
#define SNSRAGMASK_CNT_U32                      (4095U)
#define SNSRERRMASK_CNT_U16                     (128U)
#define SNSRERRMASK_CNT_U32                     (65535U)
#define SNSRERRNTCMASK_CNT_U16                  (64U)
#define SNSRERRPWRRSTMASK_CNT_U16               (1U)
#define SNSRERRQEPFAILDMASK_CNT_U16             (256U)
#define SNSRERRTURNCTROVFNTCMASK_CNT_U16        (1U)
#define SNSRERRTURNCTRVLTGMASK_CNT_U16          (4U)
#define SNSRERRTURNCTRWARNNTCMASK_CNT_U16       (8U)
#define SNSRMAGERRNTCMASK_CNT_U16               (2U)
#define SNSRTURNCNTRMASK_CNT_U32                (4095U)
#define SNSRTURNCNTRSIGNMASK_CNT_S16            ((sint16)2048)
#define SNSRVLTGFLTMASK_CNT_U32                 (8192U)
#define TRFREGBASE_CNT_U32                      (2147811334U)
#define TURNCNTRCFGCMDTRANSPTOFFS_CNT_U08       (4U)
#define TURNCNTRCFGRSTERROFFS_CNT_U08           (1U)
#define TURNCNTRCFGRSTTURNCNTROFFS_CNT_U08      (2U)
#define TURNCNTRDESCNT_CNT_U08                  (2U)


/*************************************************** Local Macros ****************************************************/
#define PimMotAg0CoeffTbl                       (*(Ary1D_f32_26 *)     (Rte_Pim_MotAg0CoeffTbl()))
#define PimMotAg0CorrnTbl                       (*(Ary1D_sm5p12_128 *) (Rte_Pim_MotAg0CorrnTbl()))


/**************************************** End Of Multiple Include Protection *****************************************/
#endif


