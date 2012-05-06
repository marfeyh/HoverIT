TEST_DIR=../tests/
SEARDUINO_PATH = /opt/searduino
PROG = percentage
# Add your source files here
SRC_C= percentage.c
SRC_CXX=
MAIN_SRC = main.c
ARDUINO = uno
SHLIB = percentage.so

LIB = libpercentage.a
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
