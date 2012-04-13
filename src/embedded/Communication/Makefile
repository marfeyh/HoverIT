TEST_DIR=test/
SEARDUINO_PATH = /opt/searduino
PROG = Communication

# Add your source files here
SRC_C=bluetooth_command.c bluetooth_controler.c messageHandler.c 
SRC_CXX= serial_interface.cpp
MAIN_SRC = main.c
ARDUINO = uno
SHLIB = communication.so

LIB = libcommunication.a
LIB_H = API_bluetooth_controler.h bluetooth_controler.h conventions.h messageHandler.h serial_interface.h
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
