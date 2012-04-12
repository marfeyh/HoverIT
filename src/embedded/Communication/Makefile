TEST_DIR=test/
SEARDUINO_PATH = /opt/searduino
PROG = Bluetooth

# Put your c or cpp main files here
ifndef GLOBAL_MAIN
SRC_C = main.c
SRC_CXX = 
endif

SRC_C += messageHandler.c bluetooth_command.c bluetooth_controler.c
SRC_CXX += serial_interface.cpp
ARDUINO = mega2560
SHLIB = Bluetooth.so

LIB = libcommunication.a
LIB_H = API_bluetooth_controler.h bluetooth_controler.h conventions.h messageHandler.h serial_interface.h
USER_LIB_INSTALL_PATH = ../../../bin

include $(SEARDUINO_PATH)/share/searduino/mk/searduino.mk

