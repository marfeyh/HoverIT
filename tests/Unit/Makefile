SRC_DIR = ../../src/embedded/Communication

check: maincheck.o Communication/info_test.o
	gcc maincheck.o $(SRC_DIR)/info.o Communication/info_test.o -l check -o $@

gcovcheck:

gcovbcheck:

memcheck:

maincheck.o: main_test.c main_test.h
	gcc -c $< -I . -o $@