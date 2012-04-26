speed: calculateSpeed.h calculateSpeed.c main.c
	gcc -o speed calculateSpeed.c main.c $(EXTRAGCCFLAGS)

testobjs: calculateSpeed.h calculateSpeed.c 
	gcc -o calculateSpeed.o -c calculateSpeed.c $(EXTRAGCCFLAGS)

testobjscov: EXTRAGCCFLAGS+= -fprofile-arcs -ftest-coverage
testobjscov: testobjs

testobjsgdb: EXTRAGCCFLAGS+= -g
testobjsgdb: testobjs

gdb: EXTRAGCCFLAGS+= -g
gdb: calc

gcovcalc: EXTRAGCCFLAGS+= -fprofile-arcs -ftest-coverage
gcovcalc: calc

clean:
	rm -f money money.exe money.o *.gcov *.gcda *.gcno