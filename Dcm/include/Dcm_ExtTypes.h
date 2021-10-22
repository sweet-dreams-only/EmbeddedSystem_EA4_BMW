/**********************************************************************************************************************
 *  COPYRIGHT
 *  -------------------------------------------------------------------------------------------------------------------
 *  \verbatim
 *  Copyright (c) 2017 by Vctr Informatik GmbH.                                             All rights reserved.
 *
 *                This software is copyright protected and proprietary to Vctr Informatik GmbH.
 *                Vctr Informatik GmbH grants to you only those rights as set out in the license conditions.
 *                All other rights remain with Vctr Informatik GmbH.
 *  \endverbatim
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/**        \file  Dcm_ExtTypes.h
 *        \brief  Public data type definition interface of DCM
 *
 *      \details  MICROSAR DCM based on AR 4.0.3
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 *  REVISION HISTORY
 *  -------------------------------------------------------------------------------------------------------------------
 *  Refer to the module's header file.
 *
 *  FILE VERSION
 *  -------------------------------------------------------------------------------------------------------------------
 *  Refer to the VERSION CHECK below.
 *********************************************************************************************************************/
#if !defined(DCM_EXTTYPES_H)
# define DCM_EXTTYPES_H
/* ----------------------------------------------
 ~&&&   Versions
---------------------------------------------- */

/*! Implementation version */
# define DCM_EXTTYPES_MAJOR_VERSION                                  8u
# define DCM_EXTTYPES_MINOR_VERSION                                  6u
# define DCM_EXTTYPES_PATCH_VERSION                                  1u
# if (DCM_EXTENSION_ID != 0x0001016CUL)
#  error "Mismatching OEMs between static and generated code"
# endif
/* ----------------------------------------------
 ~&&&   Defines
---------------------------------------------- */
# if (DCM_SVC_86_SUPPORT_ENABLED == STD_ON)                                                                                                          /* COV_DCM_UNSUPPORTED XF */
/* Backward compatibility to older releases (needed in case Dcm_Svc86NvMDataType is only extended by Dcm_ExtSvc86NvMDataType!) */
#  define Dcm_Svc86NvMDataType                                       Dcm_ExtSvc86NvMDataType
#  define dcmSvc86DefaultNvMData                                     dcmExtSvc86DefaultNvMData
# endif /* (DCM_SVC_86_SUPPORT_ENABLED == STD_ON) */
/* ----------------------------------------------
 ~&&&   Typedefs
---------------------------------------------- */
# if (DCM_SVC_86_SUPPORT_ENABLED == STD_ON)                                                                                                          /* COV_DCM_UNSUPPORTED XF */
typedef uint8  Dcm_ExtSvc86RoeStateType;
struct DCM_EXTSVC86NVMDATATYPE_TAG
{
  Dcm_ExtSvc86RoeStateType    Activation;     /* Activation state of the active response mechanism */
  PduIdType                   RxPduId;        /* Id of connection currently requesting RoE */
  uint16                      ClientSrcAddr;  /* The testers source identifier */
};
typedef struct DCM_EXTSVC86NVMDATATYPE_TAG Dcm_ExtSvc86NvMDataType;
# endif /* (DCM_SVC_86_SUPPORT_ENABLED == STD_ON) */
#endif /* !defined(DCM_EXTTYPES_H) */
/* ********************************************************************************************************************
 * END OF FILE: Dcm_ExtTypes.h
 * ******************************************************************************************************************** */
