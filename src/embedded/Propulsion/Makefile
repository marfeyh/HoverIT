TEST_DIR=tests/
SEARDUINO_PATH = /opt/searduino
PROG = propulsion

# Add your source files here
SRC_C= propulsion.c propulsion_api.c brake_propulsion.c hover_speed_stub.c
SRC_CXX= 
MAIN_SRC = main.c
#ARDUINO = stub
ARDUINO = mega2560
SHLIB = propulsion.so

LIB = libpropulsion.a
LIB_H = propulsion.h pin.h propulsion_api.h brake_propulsion.h hover_speed_stub.h
USER_LIB_INSTALL_PATH = ../../../bin

export SRC_FILES= $(SRC_C) $(SRC_CXX)

include $(SEARDUINO_PATH)/share/searduino/mk/searduino.mk

# Needs to be modified as well
check:
	$(MAKE) check -C $(TEST_DIR)

gcovcheck:
	$(MAKE) gcovcheck -C $(TEST_DIR)
#	gcov -o $(TEST_DIR) $(SRC_FILES)

gcovbcheck:
	$(MAKE) gcovbcheck -C $(TEST_DIR)

memcheck:
	$(MAKE) memcheck -C $(TEST_DIR)

clean-tests:
	$(MAKE) clean-tests -C $(TEST_DIR)

.PHONY: check
