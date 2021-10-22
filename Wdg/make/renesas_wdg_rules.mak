###############################################################################
# REGISTRY
#

LIBRARIES_TO_BUILD += renesas_wdglib

ifeq ($(WDG_DRIVER_INSTANCE), DRIVERA)
renesas_wdglib_FILES = \
    $(WDG_CORE_PATH)\src\Wdg_59_DriverA.c \
    $(WDG_CORE_PATH)\src\Wdg_59_DriverA_Ram.c \
    $(WDG_CORE_PATH)\src\Wdg_59_DriverA_Private.c \
    $(WDG_CORE_PATH)\src\Wdg_59_DriverA_Irq.c \
    $(WDG_CORE_PATH)\src\Wdg_59_DriverA_Version.c

CC_FILES_TO_BUILD += \
    $(WDG_CORE_PATH)\src\Wdg_59_DriverA.c \
    $(WDG_CORE_PATH)\src\Wdg_59_DriverA_Ram.c \
    $(WDG_CORE_PATH)\src\Wdg_59_DriverA_Private.c \
    $(WDG_CORE_PATH)\src\Wdg_59_DriverA_Irq.c \
    $(WDG_CORE_PATH)\src\Wdg_59_DriverA_Version.c

endif

ifeq ($(WDG_DRIVER_INSTANCE), DRIVERB)
renesas_wdglib_FILES = \
    $(WDG_CORE_PATH)\src\Wdg_59_DriverB.c \
    $(WDG_CORE_PATH)\src\Wdg_59_DriverB_Ram.c \
    $(WDG_CORE_PATH)\src\Wdg_59_DriverB_Private.c \
    $(WDG_CORE_PATH)\src\Wdg_59_DriverB_Irq.c \
    $(WDG_CORE_PATH)\src\Wdg_59_DriverB_Version.c

CC_FILES_TO_BUILD += \
    $(WDG_CORE_PATH)\src\Wdg_59_DriverB.c \
    $(WDG_CORE_PATH)\src\Wdg_59_DriverB_Ram.c \
    $(WDG_CORE_PATH)\src\Wdg_59_DriverB_Private.c \
    $(WDG_CORE_PATH)\src\Wdg_59_DriverB_Irq.c \
    $(WDG_CORE_PATH)\src\Wdg_59_DriverB_Version.c

endif
ifeq ($(WDG_DRIVER_INSTANCE), DRIVERC)
renesas_wdglib_FILES = \
    $(WDG_CORE_PATH)\src\Wdg_59_DriverC.c \
    $(WDG_CORE_PATH)\src\Wdg_59_DriverC_Ram.c \
    $(WDG_CORE_PATH)\src\Wdg_59_DriverC_Private.c \
    $(WDG_CORE_PATH)\src\Wdg_59_DriverC_Irq.c \
    $(WDG_CORE_PATH)\src\Wdg_59_DriverC_Version.c

CC_FILES_TO_BUILD += \
    $(WDG_CORE_PATH)\src\Wdg_59_DriverC.c \
    $(WDG_CORE_PATH)\src\Wdg_59_DriverC_Ram.c \
    $(WDG_CORE_PATH)\src\Wdg_59_DriverC_Private.c \
    $(WDG_CORE_PATH)\src\Wdg_59_DriverC_Irq.c \
    $(WDG_CORE_PATH)\src\Wdg_59_DriverC_Version.c

endif

ifeq ($(WDG_DRIVER_INSTANCE), DRIVERAB)
renesas_wdglib_FILES = \
    $(WDG_CORE_PATH)\src\Wdg_59_DriverA.c \
    $(WDG_CORE_PATH)\src\Wdg_59_DriverA_Ram.c \
    $(WDG_CORE_PATH)\src\Wdg_59_DriverA_Private.c \
    $(WDG_CORE_PATH)\src\Wdg_59_DriverA_Irq.c \
    $(WDG_CORE_PATH)\src\Wdg_59_DriverA_Version.c \
    $(WDG_CORE_PATH)\src\Wdg_59_DriverB.c \
    $(WDG_CORE_PATH)\src\Wdg_59_DriverB_Ram.c \
    $(WDG_CORE_PATH)\src\Wdg_59_DriverB_Private.c \
    $(WDG_CORE_PATH)\src\Wdg_59_DriverB_Irq.c \
    $(WDG_CORE_PATH)\src\Wdg_59_DriverB_Version.c

CC_FILES_TO_BUILD += \
    $(WDG_CORE_PATH)\src\Wdg_59_DriverA.c \
    $(WDG_CORE_PATH)\src\Wdg_59_DriverA_Ram.c \
    $(WDG_CORE_PATH)\src\Wdg_59_DriverA_Private.c \
    $(WDG_CORE_PATH)\src\Wdg_59_DriverA_Irq.c \
    $(WDG_CORE_PATH)\src\Wdg_59_DriverA_Version.c \
    $(WDG_CORE_PATH)\src\Wdg_59_DriverB.c \
    $(WDG_CORE_PATH)\src\Wdg_59_DriverB_Ram.c \
    $(WDG_CORE_PATH)\src\Wdg_59_DriverB_Private.c \
    $(WDG_CORE_PATH)\src\Wdg_59_DriverB_Irq.c \
    $(WDG_CORE_PATH)\src\Wdg_59_DriverB_Version.c

endif

ifeq ($(WDG_DRIVER_INSTANCE), DRIVERABC)
renesas_wdglib_FILES = \
    $(WDG_CORE_PATH)\src\Wdg_59_DriverA.c \
    $(WDG_CORE_PATH)\src\Wdg_59_DriverA_Ram.c \
    $(WDG_CORE_PATH)\src\Wdg_59_DriverA_Private.c \
    $(WDG_CORE_PATH)\src\Wdg_59_DriverA_Irq.c \
    $(WDG_CORE_PATH)\src\Wdg_59_DriverA_Version.c \
    $(WDG_CORE_PATH)\src\Wdg_59_DriverB.c \
    $(WDG_CORE_PATH)\src\Wdg_59_DriverB_Ram.c \
    $(WDG_CORE_PATH)\src\Wdg_59_DriverB_Private.c \
    $(WDG_CORE_PATH)\src\Wdg_59_DriverB_Irq.c \
    $(WDG_CORE_PATH)\src\Wdg_59_DriverB_Version.c\
    $(WDG_CORE_PATH)\src\Wdg_59_DriverC.c \
    $(WDG_CORE_PATH)\src\Wdg_59_DriverC_Ram.c \
    $(WDG_CORE_PATH)\src\Wdg_59_DriverC_Private.c \
    $(WDG_CORE_PATH)\src\Wdg_59_DriverC_Irq.c \
    $(WDG_CORE_PATH)\src\Wdg_59_DriverC_Version.c

CC_FILES_TO_BUILD += \
    $(WDG_CORE_PATH)\src\Wdg_59_DriverA.c \
    $(WDG_CORE_PATH)\src\Wdg_59_DriverA_Ram.c \
    $(WDG_CORE_PATH)\src\Wdg_59_DriverA_Private.c \
    $(WDG_CORE_PATH)\src\Wdg_59_DriverA_Irq.c \
    $(WDG_CORE_PATH)\src\Wdg_59_DriverA_Version.c \
    $(WDG_CORE_PATH)\src\Wdg_59_DriverB.c \
    $(WDG_CORE_PATH)\src\Wdg_59_DriverB_Ram.c \
    $(WDG_CORE_PATH)\src\Wdg_59_DriverB_Private.c \
    $(WDG_CORE_PATH)\src\Wdg_59_DriverB_Irq.c \
    $(WDG_CORE_PATH)\src\Wdg_59_DriverB_Version.c\
    $(WDG_CORE_PATH)\src\Wdg_59_DriverC.c \
    $(WDG_CORE_PATH)\src\Wdg_59_DriverC_Ram.c \
    $(WDG_CORE_PATH)\src\Wdg_59_DriverC_Private.c \
    $(WDG_CORE_PATH)\src\Wdg_59_DriverC_Irq.c \
    $(WDG_CORE_PATH)\src\Wdg_59_DriverC_Version.c

endif

OBJECTS_LINK_ONLY +=

ifeq ($(WDG_DBASE_REQ),yes)
ifeq ($(WDG_DRIVER_INSTANCE), DRIVERA)
GENERATED_SOURCE_FILES += \
     $(WDG_PROJECT_PATH)\src\Wdg_59_DriverA_PBcfg.c
endif
ifeq ($(WDG_DRIVER_INSTANCE), DRIVERB)
GENERATED_SOURCE_FILES += \
     $(WDG_PROJECT_PATH)\src\Wdg_59_DriverB_PBcfg.c
endif
ifeq ($(WDG_DRIVER_INSTANCE), DRIVERC)
GENERATED_SOURCE_FILES += \
     $(WDG_PROJECT_PATH)\src\Wdg_59_DriverC_PBcfg.c
endif

ifeq ($(WDG_DRIVER_INSTANCE), DRIVERAB)
GENERATED_SOURCE_FILES += \
     $(WDG_PROJECT_PATH)\src\Wdg_59_DriverA_PBcfg.c \
     $(WDG_PROJECT_PATH)\src\Wdg_59_DriverB_PBcfg.c
endif

ifeq ($(WDG_DRIVER_INSTANCE), DRIVERABC)
GENERATED_SOURCE_FILES += \
     $(WDG_PROJECT_PATH)\src\Wdg_59_DriverA_PBcfg.c \
     $(WDG_PROJECT_PATH)\src\Wdg_59_DriverB_PBcfg.c \
     $(WDG_PROJECT_PATH)\src\Wdg_59_DriverC_PBcfg.c
endif
endif

MAKE_CLEAN_RULES += wdg_clean_generated_files
MAKE_GENERATE_RULES += generate_wdg_config
MAKE_DEBUG_RULES += debug_wdg_makefile
MAKE_CONFIG_RULES += generate_wdg_config

wdg_clean_generated_files:
	@del $(WDG_CONFIG_PATH)\src\*.c
	@del $(WDG_CONFIG_PATH)\include\*.h

###############################################################################
# Command to print debug information                                          #
###############################################################################
debug_wdg_makefile:
	@echo WDG_PROJECT_PATH = $(WDG_PROJECT_PATH)
	@echo WDG_CORE_PATH = $(WDG_CORE_PATH)
	@echo WDG_TOOL_PATH = $(WDG_TOOL_PATH)
	@echo WDG_CONFIG_PATH = $(WDG_CONFIG_PATH)
	@echo WDG_CONFIG_FILE = $(WDG_CONFIG_FILE)
	@echo WDG_DBASE_REQ = $(WDG_DBASE_REQ)
	@echo TRXML_CONFIG_FILE = $(TRXML_CONFIG_FILE)
	@echo TRXML_CONFIG_FILE = $(TRXML_CONFIG_FILE)
	@echo WDG_DEM_CONFIG_FILE = $(WDG_DEM_CONFIG_FILE)
	@echo WDG_MCU_CONFIG_FILE = $(WDG_MCU_CONFIG_FILE)
	@echo WDG_DRIVERA_BSWMDT_CONFIG_FILE = $(WDG_DRIVERA_BSWMDT_CONFIG_FILE)
	@echo WDG_DRIVERB_BSWMDT_CONFIG_FILE = $(WDG_DRIVERB_BSWMDT_CONFIG_FILE)
	@echo WDG_DRIVERC_BSWMDT_CONFIG_FILE = $(WDG_DRIVERC_BSWMDT_CONFIG_FILE)
	@echo WDG_BSWMDT_CONFIG_FILE = $(WDG_BSWMDT_CONFIG_FILE)

###############################################################################
# Command to trigger the tool and generate configuration files                #
###############################################################################
generate_wdg_config:
ifeq ($(AUTOSAR_VERSION),3.2.2)
	$(WDG_TOOL_PATH)\Wdg_$(MICRO_FAMILY).exe -o $(WDG_CONFIG_PATH) $(WDG_CONFIG_FILE)\
  $(TRXML_CONFIG_FILE) $(WDG_DRIVERA_BSWMDT_CONFIG_FILE) $(WDG_DRIVERB_BSWMDT_CONFIG_FILE) \
  $(WDG_DRIVERC_BSWMDT_CONFIG_FILE)
endif

ifeq ($(AUTOSAR_VERSION),4.0.3)
	"$(RUCG_TOOL_PATH)\RUCG.exe" "$(WDG_TOOL_PATH)\Wdg_$(MICRO_FAMILY).dll" -o $(WDG_CONFIG_PATH) $(WDG_CONFIG_FILE) \
  $(TRXML_CONFIG_FILE) $(WDG_MCU_CONFIG_FILE) $(WDG_DEM_CONFIG_FILE) \
  $(WDG_BSWMDT_CONFIG_FILE)
endif