#All the code should be structured as following
# | Makefile
# / src
#	/computer
#	| Makefile
#		/feature
#       	| Makefile <--- You are here
# 		| example.c
#		| example1.c
# 		/tests
#	 		| check_example.c

OBJ = $(TESTSRCS:.c=.o)
TESTSRCS = $(filter-out main.c, $(wildcard *.c))
HEADERS= $(wildcard *.h)

all: *.c *.h
	gcc -o bluetooth *.c -lbluetooth

clean:
	rm -f bluetooth *.o
	rm -f tests/testsuite tests/*.o 

%.o: %.c
	gcc -c $*.c 	

# change checkmain.c on both lines to whatever your file is called in "tests" folder
testsuite.o: tests/checkmain.c
	gcc -c tests/checkmain.c -o tests/testsuite.o -lbluetooth

# change main.o and test.o on both lines to whatever your .c files are called in the "src" folder
testsuite: $(OBJ) testsuite.o 
	gcc $(OBJ) tests/testsuite.o -o tests/testsuite -lcheck -lbluetooth

check:	testsuite
	@echo Running tests...
	tests/./testsuite

.PHONY: all clean testsuite.o testsuite check %.o