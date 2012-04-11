#All the code should be structured as following
# / src
# 	| Makefile   <--- You are here
#	/computer
#		| Makefile 
#		/feature
#       		| Makefile 
# 			| example.c
#			| example1.c
# 			/tests
#	 			| check_main.c

computer:
	cd computer && $(MAKE) 

embedded:
	cd embedded && $(MAKE) 

computer-check: 
	cd computer && $(MAKE) check

embedded-check:
	cd embedded && $(MAKE) check

.PHONY: computer embedded computer-check embedded-check

pressure_loop.o: pressure_loop.c pressure_loop.h
	gcc -c pressure_loop.c -I. 
clean:
	rm -f *.o pressure pressure.exe

all: list.h list.c job.h jobpriority.h jobtype.h demotasks.h main.c
	gcc -o main main.c -L. list.c $(EXTRAGCCFLAGS)

testobjs: calc.h calc.c 
	gcc -o calc.o -c calc.c $(EXTRAGCCFLAGS)

gdb: EXTRAGCCFLAGS+= -g
gdb: calc

clean:
	rm -f main
