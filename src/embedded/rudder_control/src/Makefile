TEST_DIR=tests/
SEARDUINO_PATH = /opt/searduino
PROG = RuddarControll

# Add your source files here
SRC_C = main.c
SRC_CXX= RuddarControll.cpp
ARDUINO = stub
SHLIB = ruddar.so
include $(SEARDUINO_PATH)/share/searduino/mk/searduino.mk

# Needs to be modified as well
check: SRC_CXX = RuddarControll.cpp tests/checkmain.cpp
check: USER_LD_FLAGS = -lcheck
check: USER_CXX_FLAGS = -I/usr/include
check: RuddarControll.o $(TEST_DIR)checkmain.o
	$(MAKE) check -C tests

clean-tests:
	$(MAKE) clean -C tests

.PHONY: check
