TEST_DIR = Tests/
SEARDUINO_PATH = /opt/searduino
PROG = hovering

# Add your source files here
SRC_C = hovering_motor.c hovering_control.c hovering_init_fix.c \
	hover_api.c pressure_check.c pressure.c
MAIN_SRC = main.c
ARDUINO = uno
SHLIB = hovering.so

# When using stub audible_test should be commented and when
# using uno or mega, print_test should be commented.
SRC_C += audible_test.c
#SRC_C += print_test.c

#LIB =
LIB_H = hovering_motor.h hovering_control.h hovering_init_fix.h \
	hover_api.h pressure_check.h pressure.h pin.h print_audible_test.h
USER_LIB_INSTALL_PATH = ../../../bin

export SRC_FILES = $(SRC_C)

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

