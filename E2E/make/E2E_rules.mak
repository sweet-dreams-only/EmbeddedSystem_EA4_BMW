###############################################################################
# File Name  : E2E_rules.mak                                                  #
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
# 2010-05-31   1.00     jk   initial creation                                 #
# 2010-06-14   1.00     Nh   correct file path                                #
# 2015-07-03   1.00     gmi  Profile 5 and Profile 6 were added               #
# 2015-10-20   1.01.00  gmi  Profile JLR was added                            #
# 2016-11-25   1.02.00  gmi  Profile 7 was added                              #
#-----------------------------------------------------------------------------#
# TemplateVersion = 1.0                                                       #
# MAKEFILE        = 0.1                                                       #
###############################################################################


###############################################################
# REGISTRY
#

LIBRARIES_TO_BUILD      += E2E

E2E_FILES				+= E2E\E2E_SM.c E2E\E2E.c

ifeq ($(E2E_USE_PROFIL1),1)
E2E_FILES               += E2E\E2E_P01.c
endif
ifeq ($(E2E_USE_PROFIL2),1)
E2E_FILES               += E2E\E2E_P02.c
endif
ifeq ($(E2E_USE_PROFIL4),1)
E2E_FILES               += E2E\E2E_P04.c
endif
ifeq ($(E2E_USE_PROFIL5),1)
E2E_FILES               += E2E\E2E_P05.c
endif
ifeq ($(E2E_USE_PROFIL6),1)
E2E_FILES               += E2E\E2E_P06.c
endif
ifeq ($(E2E_USE_PROFIL7),1)
E2E_FILES               += E2E\E2E_P07.c
endif
ifeq ($(E2E_USE_PROFILJLR),1)
E2E_FILES               += E2E\E2E_PJLR.c
endif


CC_FILES_TO_BUILD               += E2E\E2E_SM.c E2E\E2E.c

ifeq ($(E2E_USE_PROFIL1),1)
CC_FILES_TO_BUILD               += E2E\E2E_P01.c
endif
ifeq ($(E2E_USE_PROFIL2),1)
CC_FILES_TO_BUILD               += E2E\E2E_P02.c
endif
ifeq ($(E2E_USE_PROFIL4),1)
CC_FILES_TO_BUILD               += E2E\E2E_P04.c
endif
ifeq ($(E2E_USE_PROFIL5),1)
CC_FILES_TO_BUILD               += E2E\E2E_P05.c
endif
ifeq ($(E2E_USE_PROFIL6),1)
CC_FILES_TO_BUILD               += E2E\E2E_P06.c
endif
ifeq ($(E2E_USE_PROFIL7),1)
CC_FILES_TO_BUILD               += E2E\E2E_P07.c
endif
ifeq ($(E2E_USE_PROFILJLR),1)
CC_FILES_TO_BUILD               += E2E\E2E_PJLR.c
endif

CPP_FILES_TO_BUILD      +=
ASM_FILES_TO_BUILD      +=

#LIBRARIES_LINK_ONLY     += (not yet supported)
#OBJECTS_LINK_ONLY       += (not yet supported)

#-------------------------------------------------------------------------------------------------
#only define new dirs, OBJ, LIB, LOG were created automaticly
#-------------------------------------------------------------------------------------------------
DIRECTORIES_TO_CREATE   +=

#DEPEND_GCC_OPTS         += (not yet supported)

GENERATED_SOURCE_FILES  +=

COMMON_SOURCE_FILES     +=

#-------------------------------------------------------------------------------------------------
# <project>.dep & <projekt>.lnk & <project>.bin and.....
# all in err\ & obj\ & lst\ & lib\ & log\ will be deleted by clean-rule automaticly
# so in this clean-rule it is only necessary to define additional files which
# were not delete automaticly.
# e.g.: $(<PATH>)\can_test.c
#-------------------------------------------------------------------------------------------------
MAKE_CLEAN_RULES        +=
#MAKE_GENERATE_RULES     +=
#MAKE_COMPILER_RULES     +=
#MAKE_DEBUG_RULES        +=
#MAKE_CONFIG_RULES       +=
#MAKE_ADD_RULES          +=


###############################################################
# REQUIRED   (defined in BaseMake (global.Makefile.target.make...))
#
# SSC_ROOT		(required)
# PROJECT_ROOT	(required)
#
# LIB_OUTPUT_PATH	(optional)
# OBJ_OUTPUT_PATH	(optional)
#
# OBJ_FILE_SUFFIX
# LIB_FILE_SUFFIX
#
###############################################################


###############################################################
# PROVIDE   this Section can be used to define own additional rules
#
###############################################################


###############################################################
# SPECIFIC
#
# There are no rules defined for the Specific part of the
# Rules-Makefile. Each author is free to create temporary
# variables or to use other resources of GNU-MAKE
#
###############################################################


