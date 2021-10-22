###############################################################################
# REGISTRY
#
PREPARE_CONFIGURATION_INTERFACE += MCU_DBASE_REQ

CHECK_VARS_WHICH_ARE_REQUIRED += MCU_DBASE_REQ


###############################################################################
# SPECIFIC
#
ifneq ($(MCU_DBASE_REQ),yes)
ifneq ($(MCU_DBASE_REQ),no)
$(error The value of the variable MCU_DBASE_REQ is not valid. \
  Please specify whether database is required or not )
endif
endif
