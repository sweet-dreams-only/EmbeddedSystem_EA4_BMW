###############################################################################
# REGISTRY
#

LIBRARIES_TO_BUILD += renesas_flslib


renesas_flslib_FILES = \
    $(FLS_CORE_PATH)\src\Fls.c \
    $(FLS_CORE_PATH)\src\Fls_Irq.c \
    $(FLS_CORE_PATH)\src\Fls_Internal.c \
    $(FLS_CORE_PATH)\src\Fls_Private_Fcu.c \
    $(FLS_CORE_PATH)\src\Fls_Ram.c \
   	$(FLS_CORE_PATH)\src\Fls_Version.c

CC_FILES_TO_BUILD += \
    $(FLS_CORE_PATH)\src\Fls.c \
    $(FLS_CORE_PATH)\src\Fls_Irq.c \
    $(FLS_CORE_PATH)\src\Fls_Internal.c \
    $(FLS_CORE_PATH)\src\Fls_Private_Fcu.c \
    $(FLS_CORE_PATH)\src\Fls_Ram.c \
   	$(FLS_CORE_PATH)\src\Fls_Version.c


OBJECTS_LINK_ONLY +=

ifeq ($(FLS_DBASE_REQ),yes)
GENERATED_SOURCE_FILES += \
     $(FLS_PROJECT_PATH)\src\Fls_PBcfg.c
endif

MAKE_CLEAN_RULES += fls_clean_generated_files
MAKE_GENERATE_RULES += generate_fls_config
MAKE_DEBUG_RULES += debug_fls_makefile
MAKE_CONFIG_RULES += generate_fls_config

fls_clean_generated_files:
	@del $(FLS_CONFIG_PATH)\src\*.c
	@del $(FLS_CONFIG_PATH)\include\*.h

###############################################################################
# Command to print debug information                                          #
###############################################################################
debug_fls_makefile:
	@echo FLS_PROJECT_PATH = $(FLS_PROJECT_PATH)
	@echo FLS_CORE_PATH = $(FLS_CORE_PATH)
	@echo FLS_TOOL_PATH = $(FLS_TOOL_PATH)
	@echo FLS_CONFIG_PATH = $(FLS_CONFIG_PATH)
	@echo FLS_CONFIG_FILE = $(FLS_CONFIG_FILE)
	@echo FLS_DBASE_REQ = $(FLS_DBASE_REQ)
	@echo FLS_MCU_CONFIG_FILE = $(FLS_MCU_CONFIG_FILE)
	@echo TRXML_CONFIG_FILE = $(TRXML_CONFIG_FILE)
	@echo FLS_DEM_CONFIG_FILE = $(FLS_DEM_CONFIG_FILE)
	@echo FLS_BSWMDT_CONFIG_FILE = $(FLS_BSWMDT_CONFIG_FILE)

###############################################################################
# Command to trigger the tool and generate configuration files                #
###############################################################################
generate_fls_config:
ifeq ($(AUTOSAR_VERSION),3.2.2)
	"$(RUCG_TOOL_PATH)\RUCG.exe" "$(FLS_TOOL_PATH)\Fls_X1x.dll" -o "$(FLS_CONFIG_PATH)" "$(FLS_CONFIG_FILE)" "$(FLS_MCU_CONFIG_FILE)" "$(TRXML_CONFIG_FILE)" "$(FLS_BSWMDT_CONFIG_FILE)"
endif

ifeq ($(AUTOSAR_VERSION),4.0.3)
	"$(RUCG_TOOL_PATH)\RUCG.exe" "$(FLS_TOOL_PATH)\Fls_X1x.dll" -o "$(FLS_CONFIG_PATH)" "$(FLS_CONFIG_FILE)" "$(FLS_MCU_CONFIG_FILE)" "$(TRXML_CONFIG_FILE)" "$(FLS_DEM_CONFIG_FILE)" "$(FLS_BSWMDT_CONFIG_FILE)" 
endif