TEST_DIR=tests/
SEARDUINO_PATH = /opt/searduino
PROG = rudder

# Add your source files here
SRC_C= steering.c
SRC_CXX= RuddarControll.cpp
MAIN_SRC = main.c
ARDUINO = mega2560
#ARDUINO = uno
SHLIB = rudder.so

LIB = librudder.a
LIB_H = steering.h RuddarControll.h pin.h
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
