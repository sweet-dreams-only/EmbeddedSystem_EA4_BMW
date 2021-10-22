#################################################################
##
## BMW Srv
##
## This makefile defines rules for the module Srv
##
## project      BMW AUTOSAR Core
##
## Copyright (C) BMW AG 2014 - 2015
##
#################################################################

#################################################################
## DEFINITIONS

# default name of parameter configuration
Srv_PARAMCONF_NAME              ?= Srv_paramconf.arxml

# Core path
Srv_CORE_PATH                   := $(BAC_SSC_ROOT)/Srv

# output path
Srv_OUTPUT_PATH                 := $(GENERAL_GEN_PATH)

# config paths
Srv_CONFIG_PATH                 := $(GENERAL_CONFIG_PATH)/config
Srv_CONFIG_FILE                 := $(Srv_CONFIG_PATH)/$(Srv_PARAMCONF_NAME)

# touchfile for verify
Srv_VERIFY_TOUCHFILE            := $(GENERAL_GEN_PATH)/touch/Srv_config_verified

# config files from other modules

# generators
Srv_GENERATOR                   := $(BAC_GENERATOR_ROOT)/artt/artt.exe
Srv_GENERATOR_INCLUDE_PATH      := $(BAC_GENERATOR_ROOT)/artt/include

# add to global include path
CC_INCLUDE_PATH                 +=  $(Srv_CORE_PATH)/include \
                                $(Srv_OUTPUT_PATH)/include

# add this makefile to the makefile dependency list
MAKE_FILE_LIST                  += $(BAC_SSC_ROOT)/Srv/make/Srv_defs.mak

#################################################################
## TEMPLATES

# swcd template files

# header template files
Srv_TEMPL_CFG_H_FILE            := $(BAC_SSC_ROOT)/Srv/generate/include/Srv_Cfg.h.tt
Srv_TEMPL_VERSION_H_FILE        := $(BAC_SSC_ROOT)/Srv/generate/include/Srv_Version.h.tt

# c template files

# verify template files
Srv_TEMPL_AUTOVERIFY_H_FILE     := $(BAC_SSC_ROOT)/Srv/generate/verify/Srv.autoverify.tt

#################################################################
## OUTPUT

# header output files
Srv_OUTPUT_CFG_H_FILE           := $(Srv_OUTPUT_PATH)/include/Srv_Cfg.h
Srv_OUTPUT_VERSION_H_FILE       := $(Srv_OUTPUT_PATH)/include/Srv_Version.h

# c output files

