###############################################################################
# File Name  : Tp_Iso10681_defs.mak                                           #
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
# Copyright (c) 2008 by Vctr Informatik GmbH.  All rights reserved.         #
#                                                                             #
#-----------------------------------------------------------------------------#
#               A U T H O R   I D E N T I T Y                                 #
#-----------------------------------------------------------------------------#
# Initials     Name                      Company                              #
# --------     ---------------------     -------------------------------------#
# Aba          Andreas Barac             Vctr Informatik GmbH               #
# Her          Peter Herrmann            Vctr Informatik GmbH               #
# Wnk          Knut Winkelbach           Vctr Informatik GmbH               #
#-----------------------------------------------------------------------------#
#               R E V I S I O N   H I S T O R Y                               #
#-----------------------------------------------------------------------------#
# Date         Version  Sign Description                                      #
# ----------   -------  ---- -------------------------------------------------#
# 2007/06/13   1.00     Aba  Initial Version of Template (1.0)                #
# 2007/08/02   1.01     Her  Added support of AUTOSAR CANTP                   #
# 2008/02/08   1.02     Wnk  Adapted for AUTOSAR FrTp                         #
# 2008/02/19   1.03     wnk  Added FRTP_CORE_PATH                             #
# 2008/07/09   1.03     Wnk  Adapted for FrTp ISO 10681-2 (CD) 2008-03-17     #
# 2009/08/04   1.04     Wnk  ESCAN00036861 Makefiles do not properly support  #
#                            building a library with Tp_Iso10681              #
# 2009/08/04   1.05     Wnk  Adapted revision history                         #
#-----------------------------------------------------------------------------#
# TemplateVersion = 1.0                                                       #
# MAKEFILE        = 1.05                                                      #
###############################################################################

###############################################################
# INTERNAL REQUIRED CONFIGURATION (in Tp_Iso10681_cfg.mak)
#
# FR_MODULES 	    (required)  (not necessary for Vector)
# FR_DRIVER_MODE   (required)  (not necessary for Vector)
# FR_PROJECT_PATH  (optional) 
# FR_BUILD_LIBRARY (required)


###############################################################
# REQUIRED (defined in base_make)
# 
# PROJECT_ROOT
# SSC_ROOT
###############################################################


###############################################################
# SPECIFIC
# Specific variables which were defined here are only for local use in this Makefile
# if for example additional includes are necessary, these vars can be defined and used in the REGISTRY-Part.
# e.g.: $(FR_CORE_PATH) = $(SSC_ROOT)\Fr  could be used for CPP_INCLUDE_PATH    +=  $(FR_CORE_PATH)\CPP_FILES\...
TP_ISO10681_CORE_PATH    = Tp_Iso10681\
TP_ISO10681_OUTPUT_PATH  = $(GENDATA_DIR)

#TP_ISO10681_TOOL_PATH   = $(PROJECT_ROOT)\core\com\fr\gentool

# it is also possible to generate own configurations with some checks like the following example
#  ifneq ( $(FR_CONFIG_PATH),)
#      FR_PROJECT_PATH    = $(FR_CONFIG_PATH)
#  else
#     FR_PROJECT_PATH    = $(PROJECT_ROOT)\source\network\fr
#  endif 


###############################################################
# REGISTRY
# 
# $(SSC_PLUGINS) is a list of the components. Here fr is added (not necessary for Vector, whole component-list also exists in Global.makefile.target.make...)
# e.g.: SSC_PLUGINS        += fr
SSC_PLUGINS        += 
#e.g.: fr_DEPENDENT_PLUGINS = 
TP_ISO10681_DEPENDENT_PLUGINS = 

#-----------------------------------------------------------------------------------------
# MakeSupport usually includes all header-files which were in the same
# directory as the source-files automatically, but to ensure that the
# Asr-Makefiles will also work with other Basic-Make-Packages,
# it is necessary to define all include directories for this Module
# e.g.: CC_INCLUDE_PATH     += $(FR_CORE_PATH)
#------------------------------------------------------------------------------------------
CC_INCLUDE_PATH     += Tp_Iso10681
CPP_INCLUDE_PATH    +=
ASM_INCLUDE_PATH    +=

#PREPROCESSOR_DEFINES+= drivermode

#drivermode_KEY       = FR_MODE
#drivermode_VALUE    = $(FR_DRIVER_MODE)


###############################################################
# PROVIDE
#
# A Public Makefile does not provide resources for other basic
# software bundles or the base_make package.
###############################################################