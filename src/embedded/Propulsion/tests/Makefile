
SRC_DIR=../

CFLAGS = -I $(SRC_DIR) -I/opt/searduino/include/searduino/arduino-sources/core -I/opt/searduino/include/searduino/  -I/opt/searduino/include/searduino/arduino  -I/opt/searduino/include/searduino/arduino-extras -lcheck -L/opt/searduino/lib -lsearduinostub 
TESTOBJS=check_main.o check_propulsion.o ../propulsion.o ../propulsion_api.o 
CHECK_PROGRAM=check1


check: $(TESTOBJS)
	echo "Will soon check"
	gcc $(TESTOBJS) $(CFLAGS) -o $(CHECK_PROGRAM) 
	export LD_LIBRARY_PATH=/opt/searduino/lib && ./$(CHECK_PROGRAM) 

clean:
	-rm $(TESTOBJS)
	-rm $(CHECK_PROGRAM)

