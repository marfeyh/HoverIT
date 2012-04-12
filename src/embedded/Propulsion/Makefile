TEST_DIR=tests/
SEARDUINO_PATH = /opt/searduino
PROG = propulsion

# Add your source files here
SRC_C = propulsion.c propulsion_api.c
ifndef GLOBAL_MAIN
SRC_C += main.c
endif
ARDUINO = stub
SHLIB = propulsion.so
include $(SEARDUINO_PATH)/share/searduino/mk/searduino.mk

# Needs to be modified as well
check: SRC_C = propulsion.c propulsion_api.c ../check_propulsion.c
check: USER_LD_FLAGS = -lcheck
check: propulsion.o $(TEST_DIR)check_propulsion.o
	$(MAKE) check -C tests

clean-tests:
	$(MAKE) clean -C tests

.PHONY: check