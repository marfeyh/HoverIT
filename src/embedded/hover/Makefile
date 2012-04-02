#All the code should be structured as following
# | Makefile
# / src
#	/computer
#	| Makefile
#		/feature
#       	| Makefile <--- This Makefile should be here
# 		| example.c
#		| example1.c
# 		/tests
#	 		| check_example.c

OBJ = $(TESTSRCS:.c=.o)
TESTSRCS = $(filter-out main.c, $(wildcard *.c))
HEADERS= $(wildcard *.h)

# Replace 'feature' with your feature name
all: *.c *.h
	gcc -o pressure *.c 

# Replace 'feature' with your feature name
clean:
	rm -f pressure *.o
	rm -f tests/testsuite tests/*.o

%.o: %.c
	gcc -c $*.c 	

# Replace 'check_main.c' with your main check file
testsuite.o: tests/test_main.c
	gcc -c tests/test_main.c -o tests/testsuite.o 

testsuite: $(OBJ) testsuite.o 
	gcc $(OBJ) tests/testsuite.o -o tests/testsuite -lcheck 

check:	testsuite
	@echo Running tests...
	tests/./testsuite

.PHONY: all clean testsuite.o testsuite check %.o


