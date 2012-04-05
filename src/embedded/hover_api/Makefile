pressure: pressure_check.c pressure_check.h pressure_sensor.c pressure_sensor.h main.c 
	gcc -o pressure pressure_check.c main.c pressure_sensor.c -g -I. 

test: pressure_check.c pressure_check.h pressure_sensor.c pressure_sensor.h
	gcc -o pressure_check.o -c pressure_check.c -I.$(EXTRAGCCFLAGS)
	gcc -o pressure_sensor.o -c pressure_sensor.c -I.$(EXTRAGCCFLAGS)

clean:
	rm -f *.o pressure pressure.exe


