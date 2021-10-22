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
## REGISTRY

LIBRARIES_TO_BUILD				+= Srv_src

Srv_src_FILES					:= $(Srv_CORE_PATH)/src/Srv_BootMode.c

#add this makefile to the makefile dependency list
MAKE_FILE_LIST					+= $(BAC_SSC_ROOT)/Srv/make/Srv_rules.mak

# add module specific makefile rules
MAKE_GENERATE_RULES				+= generate_Srv_config

# second list for generation targets which create swcds only
#MAKE_GENERATE_RULES_SWCD 	+=

#################################################################

# phony rules

.phony:                 generate_Srv_config verify_Srv_config

generate_Srv_config: $(Srv_OUTPUT_CFG_H_FILE) $(Srv_OUTPUT_VERSION_H_FILE) 


#################################################################

## RULES

verify_Srv_config: $(Srv_VERIFY_TOUCHFILE) $(Srv_TEMPL_AUTOVERIFY_H_FILE) 

$(Srv_VERIFY_TOUCHFILE): $(Srv_TEMPL_AUTOVERIFY_H_FILE) $(Srv_CONFIG_FILE)
	$(SEPARATOR)
	$(START_BLOCK)
	$(SEPARATOR) Checking configuration consistency of 
	$(SEPARATOR) $(Srv_CONFIG_FILE)
	$(SEPARATOR)
	$(Srv_GENERATOR) -t=$(call C2W,$(Srv_TEMPL_AUTOVERIFY_H_FILE)) -u=$(ARTT_AUTOSAR_VERSION) -o=$(call C2W,$(Srv_OUTPUT_PATH)/verify) \
		             -I=$(call C2W,$(Srv_GENERATOR_INCLUDE_PATH)) $(call C2W,$(Srv_CONFIG_FILE))
	touch $(Srv_VERIFY_TOUCHFILE)



$(Srv_OUTPUT_CFG_H_FILE): $(Srv_TEMPL_CFG_H_FILE) $(Srv_CONFIG_FILE) $(Srv_VERIFY_TOUCHFILE)
	$(SEPARATOR)
	$(START_BLOCK)
	$(SEPARATOR) GENERATING $(Srv_OUTPUT_CFG_H_FILE)
	$(SEPARATOR)
	$(Srv_GENERATOR) -t=$(call C2W,$(Srv_TEMPL_CFG_H_FILE)) -u=$(ARTT_AUTOSAR_VERSION) -o=$(call C2W,$(Srv_OUTPUT_PATH)/include) \
		-I=$(call C2W,$(Srv_GENERATOR_INCLUDE_PATH)) $(call C2W,$(Srv_CONFIG_FILE))

$(Srv_OUTPUT_VERSION_H_FILE): $(Srv_TEMPL_VERSION_H_FILE) $(Srv_CONFIG_FILE) $(Srv_VERIFY_TOUCHFILE)
	$(SEPARATOR)
	$(START_BLOCK)
	$(SEPARATOR) GENERATING $(Srv_OUTPUT_VERSION_H_FILE)
	$(SEPARATOR)
	$(Srv_GENERATOR) -t=$(call C2W,$(Srv_TEMPL_VERSION_H_FILE)) -u=$(ARTT_AUTOSAR_VERSION) -o=$(call C2W,$(Srv_OUTPUT_PATH)/include) \
		-I=$(call C2W,$(Srv_GENERATOR_INCLUDE_PATH)) $(call C2W,$(Srv_CONFIG_FILE))


