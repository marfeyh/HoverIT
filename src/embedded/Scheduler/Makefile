TEST_DIR=test/
SEARDUINO_PATH = /opt/searduino
PROG = Scheduler

# Put your c or cpp main files here
ifndef GLOBAL_MAIN
SRC_C = main.c
SRC_CXX = 
endif

SRC_C += controller.c list.c
SRC_CXX += 
ARDUINO = mega2560
SHLIB = Scheduler.so

LIB = libscheduler.a
LIB_H = Theta-API.h job.h list.h
USER_LIB_INSTALL_PATH = ../../../bin
USER_C_FLAGS = -I../../../bin/include

include $(SEARDUINO_PATH)/share/searduino/mk/searduino.mk

