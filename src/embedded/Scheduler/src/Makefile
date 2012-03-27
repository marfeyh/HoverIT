## Makefile to compile and link the basic scheduler and its demo
## Author: Kirill Blazhko
##
all: list.h list.c job.h jobpriority.h jobtype.h demotasks.h main.c
	gcc -o ../bin/main main.c -L. list.c $(EXTRAGCCFLAGS)

gdb: EXTRAGCCFLAGS+= -g
gdb: main

clean:
	rm -rf ../bin/main