#
#* @ Module name:  Test make file
#* @ Description:  Compiles the files for testing control hovering fan
#*
#* @ Author names : Eva-Lisa Kedborn, Jing Liu
#* 		    Seyed Ehsan Mohajerani, Navid Amiriarshad
#* @ Release      : 9 April 2012
#* @ Version      : 1
#* @ Refrences    : Arduino.cc, sandklef.com, Check manual
#

# Source path #
SRCPATH = ../

# C FLAGS #
CFLAGS= -I $(SRCPATH) -I/opt/searduino/include/searduino/arduino-sources/core -I/opt/searduino/include/searduino/  -I/opt/searduino/include/searduino/arduino  -I/opt/searduino/include/searduino/arduino-extras -lcheck -L/opt/searduino/lib -lsearduinostub

# Test objects #
TESTOBJS= test_main.o hovering_check.o ../ ../hover_api.o ../hovering_motor.o ../hovering_control.o ../hovering_init_fix.o ../pressure_check.o ../pressure_sensor.o

# Check program #
CHECK_PROGRAM=testsuite

# When use make check #
check: $(TESTOBJS)
	echo "CHECKING..."
	gcc $(TESTOBJS) $(CFLAGS) -o $(CHECK_PROGRAM)
	export LD_LIBRARY_PATH=/opt/searduino/lib && ./$(CHECK_PROGRAM)

# When use make clean #
clean:
	-rm $(TESTOBJS)
	-rm $(CHECK_PROGRAM)
