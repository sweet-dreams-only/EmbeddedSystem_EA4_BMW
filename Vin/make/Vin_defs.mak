################################################################################
##
## BMW Vin
##
## This makefile defines rules for the module Vin
##
## project      BMW AUTOSAR Core
##
## Copyright (C) BMW AG 2015 - 2016
##
################################################################################

#################################################################
## DEFINITIONS

# default name of parameter configuration
Vin_PARAMCONF_NAME         ?= Vin_paramconf.arxml

# Core path
Vin_CORE_PATH              := $(BAC_SSC_ROOT)/Vin

# output path
Vin_OUTPUT_PATH            := $(GENERAL_GEN_PATH)

# config paths
Vin_CONFIG_PATH            := $(GENERAL_CONFIG_PATH)/config
Vin_CONFIG_FILE            := $(Vin_CONFIG_PATH)/$(Vin_PARAMCONF_NAME)

# touchfile for verify
Vin_VERIFY_TOUCHFILE       := $(GENERAL_GEN_PATH)/touch/Vin_config_verified

# config files from other modules

# generators
Vin_GENERATOR               := $(BAC_GENERATOR_ROOT)/artt/artt.exe
Vin_GENERATOR_INCLUDE_PATH  := $(BAC_GENERATOR_ROOT)/artt/include
Vin_XML_CONVERTER           := $(BAC_UTIL)/xml/xml.exe

# add to global include path
CC_INCLUDE_PATH                  += $(Vin_CORE_PATH)/include \
                                    $(Vin_OUTPUT_PATH)/include


# add this makefile to the makefile dependency list
MAKE_FILE_LIST              += $(Vin_CORE_PATH)/make/Vin_defs.mak

# include generated makefile if exists
-include                        $(Vin_OUTPUT_PATH)/make/Vin_Cfg.mak

#################################################################
## TEMPLATES

# swcd template files
Vin_TEMPL_SWCD_INTERNAL_FILE := $(Vin_CORE_PATH)/generate/swcd/Vin_internal.arxml.tt

# header template files
Vin_TEMPL_CFG_H_FILE         := $(Vin_CORE_PATH)/generate/include/Vin_Cfg.h.tt
Vin_TEMPL_PBCFG_H_FILE       := $(Vin_CORE_PATH)/generate/include/Vin_PBCfg.h.tt
Vin_TEMPL_VER_H_FILE         := $(Vin_CORE_PATH)/generate/include/Vin_Version.h.tt

# c template files
Vin_TEMPL_PBCFG_C_FILE       := $(Vin_CORE_PATH)/generate/src/Vin_PBCfg.c.tt

# verify template files
Vin_TEMPL_VERIFY_FILE        := $(Vin_CORE_PATH)/generate/verify/Vin.verify.tt
Vin_TEMPL_AUTOVERIFY_FILE    := $(Vin_CORE_PATH)/generate/verify/Vin.autoverify.tt

# makefile template files
Vin_TEMPL_CFG_MAK_FILE       := $(Vin_CORE_PATH)/generate/make/Vin_Cfg.mak.tt

#################################################################
## OUTPUT

# header output files
Vin_OUTPUT_CFG_H_FILE         := $(Vin_OUTPUT_PATH)/include/Vin_Cfg.h
Vin_OUTPUT_PBCFG_H_FILE       := $(Vin_OUTPUT_PATH)/include/Vin_PBCfg.h
Vin_OUTPUT_VER_H_FILE         := $(Vin_OUTPUT_PATH)/include/Vin_Version.h

# c output files
Vin_OUTPUT_PBCFG_C_FILE       := $(Vin_OUTPUT_PATH)/src/Vin_PBCfg.c

# makefile output file
Vin_OUTPUT_CFG_MAK_FILE       := $(Vin_OUTPUT_PATH)/make/Vin_Cfg.mak
