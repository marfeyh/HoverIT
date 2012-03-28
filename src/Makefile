pressure: main.o pressure_sensor.o pressure_loop.o
	gcc -o pressure main.o pressure_sensor.o pressure_loop.o -I.

main.o: main.c 
	gcc -c main.c -I. 

pressure_sensor.o: pressure_sensor.c pressure_sensor.h
	gcc -c pressure_sensor.c -I.

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
