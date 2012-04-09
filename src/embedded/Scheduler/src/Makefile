

default: 
	@echo To get object files type in terminal \"make jqObj\" \(short for Job_queue object\)
	@echo To clean \(i.e del all *.o and *.gcov files\) type in terminal \"make clean\"

jqObj:
	gcc -c -Wall -fprofile-arcs -ftest-coverage job_queue.c

gcov:
	gcc -c -Wall -fprofile-arcs -ftest-coverage job_queue.c -lgcov
clean: 
	rm -rf *.o *.gc* 