#All the code should be structured as following
# | Makefile
# | src
#	|computer
# 		| example.c
#		| example1.c
# | tests
# 	| check_example.c

# All the header files
HEA=$(wildcard *.h)
# All the source code files
SRC=$(wildcard *.c)

all: $(SRC) $(HEA)
	gcc *.c -o ../../../bin/bluetooth -lbluetooth

clean:
	rm -f bluetooth bluetooth.exe *.o tests/testsuite tests/testsuite.o


# change checkmain.c on both lines to whatever your file is called in "tests" folder
tests/testsuite.o: tests/check_hc_remote.c
	gcc -c tests/check_hc_remote.c -o ../../../bin/testsuite.o 

# change main.o and test.o o both lines to whatever your .c files are called in the "src" folder
tests/testsuite: bluetooth tests/testsuite.o
	gcc bluetooth tests/testsuite.o -o tests/testsuite -lcheck

check:	tests/testsuite
	@echo Running tests...
	cd tests && ./testsuite
