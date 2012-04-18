SRCPATH = ../../
SRCOBJS = $(wildcard $(SRCPATH)/*.o)
TESTSRCS = $(wildcard *.c)

check: testsuite
	@echo Running tests...
	./checkmain

# gcovcheck: EXTRAGCCFLAGS+= -fprofile-arcs -ftest-coverage -lgcov
# gcovcheck: check
# 	gcov testsuite
# 	cd $(SRCPATH) && gcov main.c

# gcovcheckb: EXTRAGCCFLAGS+= -fprofile-arcs -ftest-coverage -lgcov
# gcovcheckb: check
# 	gcov -b -c testsuite
# 	cd $(SRCPATH) && gcov -b -c main.c

memcheck: EXTRAGCCFLAGS+= -g
memcheck: testsuite
	@echo Running tests under valgrind...
	valgrind --leak-check=full ./checkmain

testsuite.o:
	gcc -c checkmain.c -fprofile-arcs -ftest-coverage -lgcov -lcheck

testsuite: testsuite.o
	gcc $(SRCOBJS) checkmain.o -o checkmain -fprofile-arcs -ftest-coverage -lcheck

clean:
	rm -f checkmain checkmain.o *.gcov *.gcda *.gcno