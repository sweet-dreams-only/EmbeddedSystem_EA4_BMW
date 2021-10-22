###############################################################################
# File Name  : Tp_Iso10681_rules.mak                                          #
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
# 2008/07/09   1.03     Wnk  Adapted for FrTp ISO 10681-2 (CD) 2008-03-17     #
# 2009/08/04   1.04     Wnk  ESCAN00036861 Makefiles do not properly support  #
#                            building a library with Tp_Iso10681              #
# 2009/08/04   1.05     Wnk  Adapted revision history                         #
# 2015/04/24   2.00     Wnk  Submodules due to Safety-Coaches rulez
#-----------------------------------------------------------------------------#
# TemplateVersion = 1.0                                                       #
# MAKEFILE        = 1.05                                                      #
###############################################################################


###############################################################
# REGISTRY
#

#e.g.: LIBRARIES_TO_BUILD      +=    $(LIB_OUPUT_PATH)\vendorx_frlib1.$(LIB_FILE_SUFFIX)
LIBRARIES_TO_BUILD      += Tp_Iso10681
Tp_Iso10681_FILES        = Tp_Iso10681\FrTp.c Tp_Iso10681\FrTp_FrIf.c Tp_Iso10681\FrTp_Rsrc.c Tp_Iso10681\FrTp_RxSm.c Tp_Iso10681\FrTp_TxSm.c Tp_Iso10681\FrTp_Util.c

# e.g.: CC_FILES_TO_BUILD       += drv\fr_drv.c
CC_FILES_TO_BUILD       += Tp_Iso10681\FrTp.c Tp_Iso10681\FrTp_FrIf.c Tp_Iso10681\FrTp_Rsrc.c Tp_Iso10681\FrTp_RxSm.c Tp_Iso10681\FrTp_TxSm.c Tp_Iso10681\FrTp_Util.c
CPP_FILES_TO_BUILD      +=
ASM_FILES_TO_BUILD      +=

#LIBRARIES_LINK_ONLY     += (not yet supported)
#OBJECTS_LINK_ONLY       += (not yet supported)

#-------------------------------------------------------------------------------------------------
#only define new dirs, OBJ, LIB, LOG were created automaticly 
#-------------------------------------------------------------------------------------------------
DIRECTORIES_TO_CREATE   +=

#DEPEND_GCC_OPTS         += (not yet supported)

# e.g.:  GENERATED_SOURCE_FILES += $(GENDATA_DIR)\drv_par.c
GENERATED_SOURCE_FILES  += $(GENDATA_DIR)\FrTp_PBcfg.c $(GENDATA_DIR)\FrTp_Lcfg.c

#e.g.: COMMON_SOURCE_FILES     += $(GENDATA_DIR)\v_par.c
COMMON_SOURCE_FILES     += 

#-------------------------------------------------------------------------------------------------
# <project>.dep & <projekt>.lnk & <project>.bin and.....
# all in err\ & obj\ & lst\ & lib\ & log\ will be deleted by clean-rule automaticly
# so in this clean-rule it is only necessary to define additional files which
# were not delete automaticly.
# e.g.: $(<PATH>)\fr_test.c
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
# In vendorx_fr_cfg.mak:
# Please configure the project file:
#FR_CONFIG_FILE = $(PROJECT_ROOT)\source\network\fr\my_fr_config.cfg

#In vendorx_fr_config :
#generate_fr_config:
#$(SSC_ROOT)\core\com\fr\tools\frconfiggen.exe -o $(FR_CONFIG_FILE)


###############################################################
# SPECIFIC
#
# There are no rules defined for the Specific part of the 
# Rules-Makefile. Each author is free to create temporary 
# variables or to use other resources of GNU-MAKE
#
###############################################################


