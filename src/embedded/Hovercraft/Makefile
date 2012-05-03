TEST_DIR=test/
SEARDUINO_PATH = /opt/searduino
PROG = Hovercraft

# Add your source files here
SRC_C= 
SRC_CXX= 
MAIN_SRC = main.c
ARDUINO = mega2560
SHLIB = hovercraft.so

USER_C_FLAGS = -I ../../../bin/include
USER_LD_FLAGS = -L ../../../bin/lib/$(BOARD) -L . -lscheduler -lbluetooth -lpropulsion -lhovering -lrudder -lspeed

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
