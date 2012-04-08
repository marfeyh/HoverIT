SRCPATH = ../../src
SRCOBJS = $(wildcard $(SRCPATH)/*.o)
TESTSRCS = $(wildcard *.c)

unit: testsuite
	@echo Running tests...
	./testsuite

testsuite.o: $(TESTSRCS)
	gcc -c unitmain.c -o testsuite.o $(ECTRAGCCFLAGS)

testsuite: $(SRCOBJS) testsuite.o
	gcc $(SRCOBJS) testsuite.o -o testsuite $(EXTRAGCCFLAGS) -lcunit 


clean:
	rm -f testsuite testsuite.exe testsuite.o

