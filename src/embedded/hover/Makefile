TEST_DIR=tests/
SEARDUINO_PATH=/opt/searduino
PROG=hover

# Add your source files here
SRC_C=hovering_motor.c hovering_control.c main.c
SHLIB=hovering_motor.so
ARDUINO =stub
USER_C_FLAGS=-DSTUB_TEST
include $(SEARDUINO_PATH)/share/searduino/mk/searduino.mk

# Needs to be modified as well
check: SRC_C = hovering_motor.c hovering_control.c ../check_hovering.c
check: USER_LD_FLAGS = -lcheck
check: hovering_motor.o hovering_control.o $(TEST_DIR)check_hovering.o 
	$(MAKE) check -C tests

clean-tests:
	$(MAKE) clean -C tests

.PHONY: check
