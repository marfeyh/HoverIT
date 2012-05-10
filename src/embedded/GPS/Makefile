TEST_DIR=tests/
SEARDUINO_PATH = /opt/searduino
PROG = GPS

# Add your source files here
SRC_C=  api_gps.c core_gps.c GPS_Stub/Serial_read.c
SRC_CXX= 
MAIN_SRC = 
#ARDUINO = uno
ARDUINO = stub
SHLIB = GPS.so

LIB = libGPS.a
LIB_H = gps.h
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
