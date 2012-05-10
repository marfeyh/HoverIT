#
# Makefile to run check
#
# ! IMPORTANT NOTE !
# If there is at least one C file in the source, the main file must
# be a c file; it should then be placed either in the MAIN_SRC variable
# or first in the SRC_C variable
#
# SRC_DIR should be the path to the source files
# SRC_C & SRC_CXX should contain the .c & .cpp files for test
# MAIN_SRC should contain maximum one file, the one that holds the main
#	function for the tests
# SEARDUINO_PATH should as always be the path to the searduino installation
# 	usually /opt/searduino, unless you compiled it yourself
# USER_C_FLAGS & USER_CXX_FLAGS is if you need to give gcc & g++ any extra
#	commands. For example if you need add a include path
# USER_LD_FLABS should be used to add flags to the linker.
#	For example if you need to link with some cool library
#
# SRC_FILES can be set by a calling makefile to set the files of the src folder
#

SRC_DIR=../
SRC_C= 
SRC_CXX=
MAIN_SRC= test_suite_temp.c

SEARDUINO_PATH = /opt/searduino

USER_C_FLAGS =
USER_CXX_FLAGS =
USER_LD_FLAGS = 

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
	export LD_LIBRARY_PATH=$(SEARDUINO_PATH)/lib && ./$(PROG)

gcov: USER_C_FLAGS += -fprofile-arcs -ftest-coverage
gcov: USER_CXX_FLAGS += -fprofile-arcs -ftest-coverage
gcov: USER_LD_FLAGS += -lgcov
gcov: check


debug: USER_C_FLAGS += -g
debug: USER_CXX_FLAGS += -g
debug: check


gcovcheck: gcov
	rm -f objs/*.gcda objs/*.gcno
	gcov *.gcno

gcovbcheck: gcov
	rm -f objs/*.gcda objs/*.gcno
	gcov *.gcno

memcheck: debug
	valgrind --leak-check=full --xml-file=leakcheck.xml ./$(PROG)

clean-tests: clean
	rm -f objs/*.gcda objs/*.gcno *.gcda *.gcno $(PROG)

include $(SEARDUINO_PATH)/share/searduino/mk/searduino.mk

