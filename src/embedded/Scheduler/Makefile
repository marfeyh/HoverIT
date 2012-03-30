SRCPATH = ../dit168/src
TESTPATH = ../dit168/tests
SRCOBJS = $(wildcard $(SRCPATH)/*.o)
TESTSRCS = $(wildcard *.c)

default:
	@echo make clean - deletes all the files generated from this make file

cjob:
	cd $(SRCPATH) 
	gcc -c job_queue.c

testprog:
	cd $(TESTPATH) && gcc -c set_main.c && gcc set_main.o ../src/job_queue.o -o $@ && ./$@

clean:
	cd $(SRCABPATH) 
	rm -f job_queue.o *.gcov *.gcda *gcno 
	 cd $(TESTPATH) 
	 rm -f set_main.o testprog