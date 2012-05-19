
TEST_DIR=tests/
SEARDUINO_PATH = /opt/searduino
PROG = gsm

# Add your source files here
SRC_C= blink.c
SRC_CXX= sms_com.cpp eeprom_api.cpp call_processor.cpp gsm_setup.cpp
MAIN_SRC = gsm_main.c
ARDUINO = mega2560
SHLIB = gsm.so

LIB = libgsm.a
LIB_H = blink.h call_processor.h eeprom_api.h gsm_setup.h pin.h sms_com.h
USER_LIB_INSTALL_PATH = ../../../bin

export SRC_FILES= $(SRC_C) $(SRC_CXX)

include $(SEARDUINO_PATH)/share/searduino/mk/searduino.mk

check:
	$(MAKE) check -C $(TEST_DIR)

gcovcheck:
	$(MAKE) gcovcheck -C $(TEST_DIR)

gcovbcheck:
	$(MAKE) gcovbcheck -C $(TEST_DIR)

memcheck:
	$(MAKE) memcheck -C $(TEST_DIR)

clean-tests:
	$(MAKE) clean-tests -C $(TEST_DIR)

.PHONY: check
