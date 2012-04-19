#
#* @ Module name:  Test make file
#* @ Description:  Compiles the files for testing control hovering fan
#*
#* @ Author names : Eva-Lisa Kedborn, Jing Liu
#* 		    Seyed Ehsan Mohajerani, Navid Amiriarshad#* @ Release      : 9 April 2012
#* @ Version      : 1
#* @ Refrences    : Arduino.cc, sandklef.com, Check manual
#

SRC_DIR =../
SRC_C = hovering_check.c
MAIN_SRC = test_main.c

SEARDUINO_PATH = /opt/searduino

#USER_C_FLAGS = 
#USER_CXX_FLAGS = 
#USER_LD_FLAGS =

#
# DO NOT CHANGE THINGS BELOW THIS LINE (UNLESS YOU ARE AWESOME)
#

ARDUINO=stub
PROG=Testsuite
USER_C_FLAGS += -I$(SRC_DIR)
USER_CXX_FLAGS += -I$(SRC_DIR)
USER_LD_FLAGS += -lcheck
USER_OBJ_PATH = ./objs/

SRC_C += $(addprefix $(SRC_DIR), $(filter %.c, $(SRC_FILES)))
SRC_CXX += $(addprefix $(SRC_DIR), $(filter %.cpp, $(SRC_FILES)))

.PHONY: check clean-tests

check: $(PROG)
	@echo $(OBJ_C) $(OBJ_CXX)
	export LD_LIBRARY_PATH=$(SEARDUINO_PATH)/lib && ./$(PROG)

gcovcheck: $(PPROG)
	export LD_LIBRARY_PATH=$(SEARDUINO_PATH)/lib && ./$(PROG)

gcovbcheck:
	export LD_LIBRARY_PATH=$(SEARDUINO_PATH)/lib && ./$(PROG)

memcheck: $(PROG)
	export LD_LIBRARY_PATH=$(SEARDUINO_PATH)/lib && ./$(PROG)

%.check.c: $(SRC_DIR)/%.c
	cp -f $< $@

%.check.cpp: $(SRC_DIR)%.cpp
	cp -f $< $@


clean-tests: clean

include $(SEARDUINO_PATH)/share/searduino/mk/searduino.mk



