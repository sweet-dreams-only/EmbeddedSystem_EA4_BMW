###############################################################################
# File Name  : Tp_Iso10681_cfg.mak                                            #
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
# 2007/08/02   1.01     Her  Added CanTp support                              #
# 2008/02/08   1.02     Wnk  Adapted for AUTOSAR FrTp                         #
# 2008/07/09   1.03     Wnk  Adapted for FrTp ISO 10681-2 (CD) 2008-03-17     #
# 2009/08/04   1.04     Wnk  ESCAN00036861 Makefiles do not properly support  #
#                            building a library with Tp_Iso10681              #
# 2009/08/04   1.05     Wnk  Adapted revision history                         #
#-----------------------------------------------------------------------------#
# TemplateVersion = 1.0                                                       #
# MAKEFILE        = 1.05                                                      #
###############################################################################

##############################################################
# FR_CONFIG_PATH: (not used for Vector)
# The Variable FR_CONFIG_PATH is optional. It allows the 
# configuration of the directory, where you can also find the 
# generated source files. Generally they should be in the 
# directory $(PROJECT_ROOT)\source\networks.
# But if the application should run on several hardware 
# targets, then different FR configurations of different
# directories will be necessary. Therefor the variable 
# FR_CONFIG_PATH should be used.
# 
# For example:
# FR_CONFIG_PATH = $(PROJECT_ROOT)\source\network\v850
# FR_CONFIG_PATH = $(PROJECT_ROOT)\source\network\st10
# FR_CONFIG_PATH = $(PROJECT_ROOT)\source\network\v850
#
#TP_ISO10681_CONFIG_PATH =


##############################################################
# FR_DRIVER_MODE:  (not used for Vector)
# This Variable contains the name of the FlexRay driver module. At 
# the moment the Standard Software Core Supports the two driver
# fr_drv.c (single FR) and fr_drvm.c (multi FR). Other 
# values are not allowed.
# 
# For example:
# FR_DRIVER_MODE = singlechannel/multichannel
#

###############################################################
# REQUIRED
#
# No Other resources are required to write a Configuration 
# Makefile.
#
###############################################################


###############################################################
# PROVIDE
#
# A Configuration Makefile does not provide resources for other
# basic software bundles or the base_make package
#
###############################################################


###############################################################
# REGISTRY
# 
# Like the Provide-Section this block is empty.
#
###############################################################


###############################################################
# SPECIFIC
#
# All variables in the _cfg makefile are "Specific" variables,
# because they should only be used in the *_check.mak,
# *_defs.mak and *_rules.mak Makefiles of the same basic 
# software bundle.
###############################################################
