TEST_DIR=tests/
SEARDUINO_PATH = /opt/searduino
PROG = propelsion

# Add your source files here
SRC_C = propelsion.c main.c
ARDUINO = stub
SHLIB = propelsion.so
include $(SEARDUINO_PATH)/share/searduino/mk/searduino.mk

# Needs to be modified as well
check: SRC_C = propelsion.c ../check_propelsion.c
check: USER_LD_FLAGS = -lcheck
check: propelsion.o $(TEST_DIR)check_propelsion.o 
	$(MAKE) check -C tests

clean-tests:
	$(MAKE) clean -C tests

.PHONY: check