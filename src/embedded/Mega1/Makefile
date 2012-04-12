TEST_DIR=test/
SEARDUINO_PATH = /opt/searduino
PROG = Mega1

# Put your c or cpp main files here
ifdef GLOBAL_MAIN
SRC_C = main.c
SRC_CXX = 
endif

USER_C_FLAGS = -I../../../bin/include

ARDUINO = mega2560
USER_LD_FLAGS = -L../../../bin/lib/$(BOARD) -lcommunication -lscheduler

include $(SEARDUINO_PATH)/share/searduino/mk/searduino.mk

