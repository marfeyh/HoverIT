TEST_DIR=tests/
SEARDUINO_PATH = /opt/searduino
PROG = brake_pro

# Add your source files here
SRC_C= propulsion.c propulsion_api.c brake_propulsion.c hover_speed.c
SRC_CXX= 
MAIN_SRC = main.c
ARDUINO = stub
#ARDUINO = mega2560
SHLIB = brake_pro.so

LIB = libpropulsion.a
LIB_H = propulsion.h pin.h propulsion_api.h brake_propulsion.h hover_speed.c
USER_LIB_INSTALL_PATH = ../../../bin

export SRC_FILES= $(SRC_C) $(SRC_CXX)

include $(SEARDUINO_PATH)/share/searduino/mk/searduino.mk
