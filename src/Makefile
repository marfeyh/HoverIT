all: list.h list.c job.h jobpriority.h jobtype.h demotasks.h main.c
	gcc -o main main.c -L. list.c $(EXTRAGCCFLAGS)

testobjs: calc.h calc.c 
	gcc -o calc.o -c calc.c $(EXTRAGCCFLAGS)

gdb: EXTRAGCCFLAGS+= -g
gdb: calc

clean:
	rm -f main
