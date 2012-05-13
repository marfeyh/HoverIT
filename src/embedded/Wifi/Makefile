TEST_DIR=test/
SEARDUINO_PATH = /opt/searduino
PROG = Wifi

# Add your source files here
SRC_C=
SRC_CXX= wifi_wrapper.cpp
USER_C_FLAGS=-I/opt/searduino/3pp/include
USER_CXX_FLAGS=-I/opt/searduino/3pp/include
USER_LD_FLAGS=-L/opt/searduino/3pp/lib/$(BOARD) -lwifly
simulate:
	$(SEARDUINO_PATH)/bin/searduino-stream-sim --arduino-code ./$(SHLIB)
MAIN_SRC = main.c
ARDUINO = mega2560
SHLIB = bluetooth.so

LIB = libwifi.a
LIB_H = wifi_wrapper.h
USER_LIB_INSTALL_PATH = ../../../bin

export SRC_FILES= $(SRC_C) $(SRC_CXX)

include $(SEARDUINO_PATH)/share/searduino/mk/searduino.mk

# Needs to be modified as well
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
