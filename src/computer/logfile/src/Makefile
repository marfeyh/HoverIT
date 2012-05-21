pclog: pc_log.h pc_log.c main.c 
	gcc -o pclog pc_log.c main.c $(EXTRAGCCFLAGS)

testobjs: pc_log.h pc_log.c 
	gcc -o pclog.o -c pc_log.c $(EXTRAGCCFLAGS)

testobjscov: EXTRAGCCFLAGS+= -fprofile-arcs -ftest-coverage
testobjscov: testobjs

testobjsgdb: EXTRAGCCFLAGS+= -g
testobjsgdb: testobjs

gdb: EXTRAGCCFLAGS+= -g
gdb: pclog

gcovpclog: EXTRAGCCFLAGS+= -fprofile-arcs -ftest-coverage
gcovpclog: pclog

clean:
	rm -f pclog pclog.exe pclog.o *.gcov *.gcda *.gcno
