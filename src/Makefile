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
