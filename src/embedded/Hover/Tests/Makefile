
#***************************************************************************
#* Copyright (C) 2012  Eva-Lisa Kedborn                     
#* 		       Jing Liu
#*		       Seyed Ehsan Mohajerani
#*		       Navid Amiriarshad	
#*
#* This program is free software: you can redistribute it and/or
#* modify it under the terms of the GNU General Public License as published
#* by the Free Software Foundation, either version 3 of the License, or
#* (at your option) any later version.
#* 
#* This program is distributed in the hope that it will be useful,
#* but WITHOUT ANY WARRANTY; without even the implied warranty of
#* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
#* GNU General Public License for more details.
#* 

#* You should have received a copy of the GNU General Public License
#* along with this program.  If not, see <http://www.gnu.org/licenses/>.
#*
#****************************************************************************

#
# @file Test make file
# @brief Compiles the files for testing control hovering fan
# @author Eva-Lisa Kedborn 
# @author Jing Liu 
# @author Seyed Ehsan Mohajerani
# @author Navid Amiriarshad
# @date 9 April 2012
# @version 0.9
# @see Arduino.cc
# @see sandklef.com
# @see hoveritu.com
# @see dreamincode.net/forums/topic/34861-functions-stored-in-structure
# @see Turnigy_Plush_and_Sentry_ESC user manual
# @see reference for Coding standard ece.cmu.edu/~eno/coding/CCodingStandard
# .html
# @see reference for commenting stack.nl/~dimitri/doxygen/commands
# .html#cmdparam

SRC_DIR =../
SRC_C = hovering_check.c generate_random.c \
hovering_init_fix_check.c ../pressure_stub.c
MAIN_SRC = test_main.c

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
	gcov -b *.gcno 

memcheck: debug
	valgrind --leak-check=full --xml-file=leakcheck.xml Testsuite

clean-tests: clean
	rm -f objs/*.gcda objs/*.gcno *.gcda *.gcno *.gcov

include $(SEARDUINO_PATH)/share/searduino/mk/searduino.mk
