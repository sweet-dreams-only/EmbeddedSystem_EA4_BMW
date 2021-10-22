###############################################################################
# File Name  : E2E_check.mak                                      #
# Description: Autosar makefile Template                                      #
#              This makefile is a template to implement the common            #
#              features of each project.                                      #
#              It is included by the Global.Makefile.target.make.$(Version)   #
#              and is supported from version 3.24 .                           #
#                                                                             #
# This Template is based on AUTOSAR_BSW_MakefileInterface.doc version 0.4     #
#                                                                             #
#-----------------------------------------------------------------------------#
#               C O P Y R I G H T                                             #
#-----------------------------------------------------------------------------#
# Copyright (c) 2007 by Vctr Informatik GmbH.  All rights reserved.         #
#                                                                             #
#-----------------------------------------------------------------------------#
#               A U T H O R   I D E N T I T Y                                 #
#-----------------------------------------------------------------------------#
# Initials     Name                      Company                              #
# --------     ---------------------     -------------------------------------#
# Jk          Joachim Kalmbach             Vctr Informatik GmbH             #
# Gmi         Michael Goss                 Vctr Informatik GmbH             #
#-----------------------------------------------------------------------------#
#               R E V I S I O N   H I S T O R Y                               #
#-----------------------------------------------------------------------------#
# Date         Version  Sign Description                                      #
# ----------   -------  ---- -------------------------------------------------#
# 2010-05-31   0.9      jk  initial creation                                  #
# 2015-07-03   1.00     gmi  Profile 5 and Profile 6 were added               #
# 2015-10-20   1.01.00  gmi  Profile JLR was added                            #
# 2016-11-25   1.02.00  gmi  Profile 7 was added                              #
#-----------------------------------------------------------------------------#
# TemplateVersion = 1.0                                                       #
# MAKEFILE        = 0.1                                                       #
###############################################################################

###############################################################
# Support PROFIL1
#
# Check if set
###############################################################
ifeq ($(E2E_USE_PROFIL1),)
  $(error Error: E2E_check.mak: Please set E2E_USE_PROFIL1 in E2E_cfg.mak)
endif

###############################################################
# Support PROFIL2
#
# Check if set
###############################################################
ifeq ($(E2E_USE_PROFIL2),)
  $(error Error: E2E_check.mak: Please set E2E_USE_PROFIL2 in E2E_cfg.mak)
endif

###############################################################
# Support PROFIL4
#
# Check if set
###############################################################
ifeq ($(E2E_USE_PROFIL4),)
  $(error Error: E2E_check.mak: Please set E2E_USE_PROFIL4 in E2E_cfg.mak)
endif

###############################################################
# Support PROFIL5
#
# Check if set
###############################################################
ifeq ($(E2E_USE_PROFIL5),)
  $(error Error: E2E_check.mak: Please set E2E_USE_PROFIL5 in E2E_cfg.mak)
endif

###############################################################
# Support PROFIL6
#
# Check if set
###############################################################
ifeq ($(E2E_USE_PROFIL6),)
  $(error Error: E2E_check.mak: Please set E2E_USE_PROFIL6 in E2E_cfg.mak)
endif

###############################################################
# Support PROFIL7
#
# Check if set
###############################################################
ifeq ($(E2E_USE_PROFIL7),)
  $(error Error: E2E_check.mak: Please set E2E_USE_PROFIL7 in E2E_cfg.mak)
endif

###############################################################
# Support PROFILJLR
#
# Check if set
###############################################################
ifeq ($(E2E_USE_PROFILJLR),)
  $(error Error: E2E_check.mak: Please set E2E_USE_PROFILJLR in E2E_cfg.mak)
endif


###############################################################
# REGISTRY
#

#e.g.: PREPARE_CONFIGURATION_INTERFACE     += E2E_MODULES
PREPARE_CONFIGURATION_INTERFACE     +=

CHECK_VARS_WHICH_ARE_REQUIRED       +=

CHECK_VARS_WHICH_ARE_OPTIONAL       +=

CHECK_VARS_WHICH_ARE_OBSOLETE       +=

CHECK_VARS_WITH_ONE_CC_FILE         +=
CHECK_VARS_WITH_MORE_CC_FILES       +=

CHECK_VARS_WITH_ONE_CPP_FILE        +=
CHECK_VARS_WITH_MORE_CPP_FILES      +=

CHECK_VARS_WITH_ONE_ASM_FILE        +=
CHECK_VARS_WITH_MORE_ASM_FILES      +=

CHECK_VARS_WITH_ONE_LIB_FILE        +=
CHECK_VARS_WITH_MORE_LIB_FILES      +=

CHECK_VARS_WITH_ONE_OBJ_FILE        +=
CHECK_VARS_WITH_MORE_OBJ_FILES      +=

#e.g: CHECK_VARS_WITH_ONE_DIRECTORY       +=     $(DIRECTORIES_TO_CREATE)
#       $(DIRECTORIES_TO_CREATE) = C:\demo\drv          (this var is defined in _rules.mak)
CHECK_VARS_WITH_ONE_DIRECTORY       +=
CHECK_VARS_WITH_MORE_DIRECTORIES    +=

CHECK_VARS_WITH_ONE_FILE            +=
CHECK_VARS_WITH_MORE_FILES          +=

CHECK_VARS_WITH_MAX_LENGTH_ONE      +=

###############################################################
# SPECIFIC
#
###############################################################


###############################################################
# REQUIRED
#
# No other resources are required for a Configuration Check
# Makefile
#
###############################################################


###############################################################
# PROVIDE
#
# A configuration Makefile does not provide resources for other
# basic software bundles or the base-make package.
#
###############################################################

