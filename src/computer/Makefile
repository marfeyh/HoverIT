#All the code should be structured as following
# | Makefile
# | src
# 	| example.c
#	| example1.c
# | tests
# 	| check_example.c



all: *.c *.h
	gcc -o computer *.c -lbluetooth

clean:
	rm -f computer computer.exe *.o
	

# change checkmain.c on both lines to whatever your file is called in "tests" folder
testsuite.o: tests/checkmain.c
	gcc -c tests/checkmain.c -o tests/testsuite.o

# change main.o and test.o on both lines to whatever your .c files are called in the "src" folder
testsuite: src/main.o src/test.o testsuite.o
	gcc src/main.o src/test.o tests/testsuite.o -o tests/testsuite -lcheck

check:	testsuite
	@echo Running tests...
	tests/./testsuite