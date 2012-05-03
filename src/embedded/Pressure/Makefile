TEST_DIR=tests/
SEARDUINO_PATH = /opt/searduino
PROG = Pressure

# Add your source files here
SRC_C= pressure.c
SRC_CXX= 
MAIN_SRC =
ARDUINO = mega2560
SHLIB = example.so

LIB = libpressure.a
LIB_H = pressure.h
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
