#

SRC_DIR = ../
SRC_C   = check_coordinate_distance.c
SRC_CXX =
MAIN_SRC= checkmain.c

SEARDUINO_PATH = /opt/searduino

USER_C_FLAGS = 
USER_CXX_FLAGS = 
USER_LD_FLAGS =-lm

#
# DO NOT CHANGE THINGS BELOW THIS LINE (UNLESS YOU ARE AWESOME)
#

ARDUINO=stub
PROG=Testsuite
USER_C_FLAGS += -I$(SRC_DIR)
USER_CXX_FLAGS += -I$(SRC_DIR)
USER_LD_FLAGS += -lcheck
USER_OBJ_PATH = ./objs/


SRC_C+= $(addprefix $(SRC_DIR), $(filter %.c, $(SRC_FILES)))
SRC_CXX+= $(addprefix $(SRC_DIR), $(filter %.cpp, $(SRC_FILES)))

.PHONY: check clean-tests

check: $(PROG)
	export LD_LIBRARY_PATH=$(SEARDUINO_PATH)/lib && ./$(PROG)

# gcovcheck: $(PPROG)
# 	export LD_LIBRARY_PATH=$(SEARDUINO_PATH)/lib && ./$(PROG)

# gcovbcheck:
# 	export LD_LIBRARY_PATH=$(SEARDUINO_PATH)/lib && ./$(PROG)

# memcheck: $(PROG)
# 	export LD_LIBRARY_PATH=$(SEARDUINO_PATH)/lib && ./$(PROG)


# clean-tests: clean

# include $(SEARDUINO_PATH)/share/searduino/mk/searduino.mk

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


