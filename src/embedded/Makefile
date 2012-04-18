<<<<<<< HEAD
#All the code should be structured as following
# / src
# 	| Makefile   
#	/computer
#		| Makefile <-- You are here
#		/feature
#       		| Makefile 
# 			| example.c
#			| example1.c
# 			/tests
#	 			| check_main.c


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
=======
## Makefile to run all other make files
## Reference: Taken from Henrik's example
##


default:
	@echo "--- Normal compilation ----------------------------------"
	@echo "make all     produces binary in bin/"
	@echo " "
	
all:
	cd src && $(MAKE) all


>>>>>>> 723411e1aab2aca803cd8445a1ac8d1f933f63a1
