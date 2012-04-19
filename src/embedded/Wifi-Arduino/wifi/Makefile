
ARDUINO=uno
PROG=wifi-code
SHLIB_LIBS=-lpthread 
SRC_C=
SRC_CXX=wifi.cpp 


USER_C_FLAGS=-I/opt/searduino/3pp/include
USER_CXX_FLAGS=-I/opt/searduino/3pp/include
USER_LD_FLAGS=-L/opt/searduino/3pp/lib/$(BOARD) -lwifly

SEARDUINO_PATH=/opt/searduino

all: $(PROG)

simulate:
	$(SEARDUINO_PATH)/bin/searduino-stream-sim --arduino-code ./$(SHLIB)

include $(SEARDUINO_PATH)/share/searduino//mk/searduino.mk

