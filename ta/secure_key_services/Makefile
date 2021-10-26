# The UUID for the Trusted Application
BINARY=7f10a757-4139-4eae-90c9-f2b2eb118139

ifdef TA_CROSS_COMPILE
CROSS_COMPILE ?= $(TA_CROSS_COMPILE)
endif
export CROSS_COMPILE

-include $(TA_DEV_KIT_DIR)/mk/ta_dev_kit.mk
-include $(TA_DEV_KIT_DIR)/host_include/conf.mk

ifeq ($(wildcard $(TA_DEV_KIT_DIR)/mk/ta_dev_kit.mk), )
clean:
	@echo 'Note: $$(TA_DEV_KIT_DIR)/mk/ta_dev_kit.mk not found, cannot clean TA'
	@echo 'Note: TA_DEV_KIT_DIR=$(TA_DEV_KIT_DIR)'
endif
