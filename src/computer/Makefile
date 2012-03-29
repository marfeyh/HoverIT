#All the code should be structured as following
# | Makefile
# | src
#	|computer
# 		| example.c
#		| example1.c
# | tests
# 	| check_example.c



all: *.c *.h
	gcc -o computer *.c -lbluetooth

clean:
	rm -f computer computer.exe *.o


# change checkmain.c on both lines to whatever your file is called in "tests" folder
testsuite.o: ../../tests/check_hc_remote.c
	gcc -c ../../tests/check_hc_remote.c -o ../../tests/testsuite.o

# change main.o and test.o o both lines to whatever your .c files are called in the "src" folder
testsuite: UI_PC/main.o UI_PC/test.o testsuite.o
	gcc UI_PC/bt_client.o UI_PC/hcraft_remote_api.o ../../tests/testsuite.o -o ../../tests/testsuite -lcheck

check:	testsuite
	@echo Running tests...
	tests/./testsuite