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
#################################################################

#################################################################
## REGISTRY

LIBRARIES_TO_BUILD                  += Vin_src

Vin_src_FILES                  += $(Vin_CORE_PATH)/src/Vin.c \
                                  $(Vin_CORE_PATH)/src/Vin_Com.c \
                                  $(Vin_CORE_PATH)/src/Vin_Dlog.c \
                                  $(Vin_CORE_PATH)/src/Vin_Ssv.c \
                                  $(Vin_OUTPUT_PBCFG_C_FILE)

#add this makefile to the makefile dependency list
MAKE_FILE_LIST                      += $(Vin_CORE_PATH)/make/Vin_rules.mak

# add module specific makefile rules
MAKE_GENERATE_RULES                 += generate_Vin_config

# second list for generation targets which create swcds only
MAKE_GENERATE_RULES_SWCD += generate_Vin_swcds

#################################################################
# phony rules

.phony:                 generate_Vin_config verify_Vin_config

generate_Vin_config: $(Vin_OUTPUT_CFG_H_FILE) $(Vin_OUTPUT_VER_H_FILE) \
					$(Vin_OUTPUT_PBCFG_C_FILE) $(Vin_OUTPUT_PBCFG_H_FILE)



#################################################################
## RULES

verify_Vin_config: $(Vin_VERIFY_TOUCHFILE) $(Vin_TEMPL_AUTOVERIFY_FILE) $(Vin_TEMPL_VERIFY_FILE)

$(Vin_VERIFY_TOUCHFILE): $(Vin_TEMPL_VERIFY_FILE) $(Vin_TEMPL_AUTOVERIFY_FILE) $(Vin_CONFIG_FILE)
	$(SEPARATOR)
	$(START_BLOCK)
	$(SEPARATOR) Checking configuration consistency of
	$(SEPARATOR) $(Vin_CONFIG_FILE)
	$(SEPARATOR)
	$(SEPARATOR)
	$(Vin_GENERATOR) -t=$(call C2W,$(Vin_TEMPL_AUTOVERIFY_FILE)) -u=$(ARTT_AUTOSAR_VERSION) -o=$(call C2W,$(Vin_OUTPUT_PATH)/verify ) \
		-I=$(call C2W,$(Vin_GENERATOR_INCLUDE_PATH)) $(call C2W,$(Vin_CONFIG_FILE))
	$(Vin_GENERATOR) -t=$(call C2W,$(Vin_TEMPL_VERIFY_FILE)) -u=$(ARTT_AUTOSAR_VERSION) -o=$(call C2W,$(Vin_OUTPUT_PATH)/verify ) \
		-I=$(call C2W,$(Vin_GENERATOR_INCLUDE_PATH)) $(call C2W,$(Vin_CONFIG_FILE))
	touch $(Vin_VERIFY_TOUCHFILE)

generate_Vin_swcds: $(Vin_CONFIG_FILE) $(Vin_VERIFY_TOUCHFILE)
	$(SEPARATOR)
	$(START_BLOCK)
	$(SEPARATOR) GENERATING Vin software component description file
	$(SEPARATOR)
	$(Vin_GENERATOR) -t=$(call C2W,$(Vin_TEMPL_SWCD_INTERNAL_FILE) ) -u=$(ARTT_AUTOSAR_VERSION) -o=$(call C2W,$(Vin_OUTPUT_PATH)/swcd ) \
		-I=$(call C2W,$(Vin_GENERATOR_INCLUDE_PATH)) $(call C2W,$(Vin_CONFIG_FILE))

$(Vin_OUTPUT_CFG_H_FILE): $(Vin_TEMPL_CFG_H_FILE) $(Vin_CONFIG_FILE) $(Vin_VERIFY_TOUCHFILE)
	$(SEPARATOR)
	$(START_BLOCK)
	$(SEPARATOR) GENERATING $(Vin_OUTPUT_CFG_H_FILE)
	$(SEPARATOR)
	$(Vin_GENERATOR) -t=$(call C2W,$(Vin_TEMPL_CFG_H_FILE) ) -u=$(ARTT_AUTOSAR_VERSION) -o=$(call C2W,$(Vin_OUTPUT_PATH)/include ) \
		-I=$(call C2W,$(Vin_GENERATOR_INCLUDE_PATH)) $(call C2W,$(Vin_CONFIG_FILE))

$(Vin_OUTPUT_VER_H_FILE): $(Vin_TEMPL_VER_H_FILE) $(Vin_CONFIG_FILE) $(Vin_VERIFY_TOUCHFILE)
	$(SEPARATOR)
	$(START_BLOCK)
	$(SEPARATOR) GENERATING $(Vin_OUTPUT_VER_H_FILE)
	$(SEPARATOR)
	$(Vin_GENERATOR) -t=$(call C2W,$(Vin_TEMPL_VER_H_FILE) ) -u=$(ARTT_AUTOSAR_VERSION) -o=$(call C2W,$(Vin_OUTPUT_PATH)/include ) \
		-I=$(call C2W,$(Vin_GENERATOR_INCLUDE_PATH)) $(call C2W,$(Vin_CONFIG_FILE))

$(Vin_OUTPUT_PBCFG_H_FILE): $(Vin_TEMPL_PBCFG_H_FILE) $(Vin_CONFIG_FILE) $(Vin_VERIFY_TOUCHFILE)
	$(SEPARATOR)
	$(START_BLOCK)
	$(SEPARATOR) GENERATING $(Vin_OUTPUT_PBCFG_H_FILE)
	$(SEPARATOR)
	$(Vin_GENERATOR) -t=$(call C2W,$(Vin_TEMPL_PBCFG_H_FILE) ) -u=$(ARTT_AUTOSAR_VERSION) -o=$(call C2W,$(Vin_OUTPUT_PATH)/include ) \
		-I=$(call C2W,$(Vin_GENERATOR_INCLUDE_PATH)) $(call C2W,$(Vin_CONFIG_FILE))

$(Vin_OUTPUT_PBCFG_C_FILE): $(Vin_TEMPL_PBCFG_C_FILE) $(Vin_CONFIG_FILE) $(Vin_VERIFY_TOUCHFILE)
	$(SEPARATOR)
	$(START_BLOCK)
	$(SEPARATOR) GENERATING $(Vin_OUTPUT_PBCFG_C_FILE)
	$(SEPARATOR)
	$(Vin_GENERATOR) -t=$(call C2W,$(Vin_TEMPL_PBCFG_C_FILE) ) -u=$(ARTT_AUTOSAR_VERSION) -o=$(call C2W,$(Vin_OUTPUT_PATH)/src ) \
		-I=$(call C2W,$(Vin_GENERATOR_INCLUDE_PATH)) $(call C2W,$(Vin_CONFIG_FILE))

$(Vin_OUTPUT_CFG_MAK_FILE): $(Vin_TEMPL_CFG_MAK_FILE) $(Vin_CONFIG_FILE)
	$(SEPARATOR)
	$(START_BLOCK)
	$(SEPARATOR) GENERATING $(Vin_OUTPUT_CFG_MAK_FILE)
	$(SEPARATOR)
	$(Vin_GENERATOR) -t=$(call C2W,$(Vin_TEMPL_CFG_MAK_FILE)) -u=$(ARTT_AUTOSAR_VERSION) -o=$(call C2W,$(Vin_OUTPUT_PATH)/make) \
		-I=$(Vin_GENERATOR_INCLUDE_PATH) $(call C2W,$(Vin_CONFIG_FILE))
