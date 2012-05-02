TEST_DIR=test/
SEARDUINO_PATH = /opt/searduino
PROG = Alarm

# Add your source files here
SRC_C= alarm.c
SRC_CXX= toneWrapper.cpp
MAIN_SRC = main.c
ARDUINO = due
SHLIB = 

LIB = 
LIB_H = 
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