# #######################################################################
# Makefile for inclusion by other projects
#   heavily copied from original libarduino sources
#   (c) 2009, for all changes belong to Henrik Sandklef
#	which lead to the current version
#   (c) 2011, for all changes belong to Petre Mihail Anton
#######################################################################


# *** Change device port to corespond to your system ***
# 
# Example port names: 
# if you're using GNU/Linux (Ubuntu/Debian/Fedora.....):
   USB_PORT=/dev/ttyACM0
#
# if you're using Mac:
#    USB_PORT=/dev/tty.usbmodemfa141
#
# Hint:
#    Launch Arduino IDE  to see what your USB device 
#    is called (look under the port settings)
#    Alternatively, type in your terminal:
#        ls /dev/tty*                                                                                  
# USB_PORT=/dev/ttyACM0
# USB_PORT=/dev/tty.usbmodem411

# *** DO NOT EDIT TEXT BELOW! ***
# *** IF YOU NEED TO ADD YOUR OWN RULES, GO TO THE END OF THE FILE! ***
#########################################################################
#########################################################################
#########################################################################

# the speed that corresponds to your arduino (normally 16MHz)
F_CPU=16000000
#F_CPU=8000000

PROG=test
SRC=src/*.c
OBJ=bin/*.o

mega: MMCU=atmega2560
mega: STK=stk500v2
mega: BAUD=115200
mega: LIB=coremega

uno: MMCU=atmega328p
uno: STK=stk500v1
uno: BAUD=115200
uno: LIB=coreuno

#	echo '#include "WProgram.h"' > $(TARGET).c
#	cat $(PROG).c >> $(TARGET).c

$(OBJ): $(SRC)
	cd bin && \
	avr-gcc -c -g -Os -ffunction-sections -fdata-sections -mmcu=$(MMCU) -DARDUINO=22 -DF_CPU=$(F_CPU) -Wall -Wstrict-prototypes \
		-Wa,-ahlms=$(PROG).lst -fno-exceptions -I../include ../$(SRC)

#-DENABLE_PWM

$(PROG): MMCU=atmega328p
$(PROG): LIB=coreuno
$(PROG): $(OBJ)
	avr-gcc $(OBJ) lib/lib$(LIB).a -Wl,-Map=$(PROG).map,--cref -mmcu=$(MMCU) -DARDUINO=22 -Iinclude -lm -Llib \
		-fno-exceptions  -ffunction-sections -fdata-sections -l$(LIB) -o bin/$(PROG).x
	@ echo "Test passed"

install: $(OBJ)
	avr-gcc $(OBJ) lib/lib$(LIB).a -Wl,-Map=$(PROG).map,--cref -mmcu=$(MMCU) -Iinclude -lm -Llib \
		-fno-exceptions  -ffunction-sections -fdata-sections -l$(LIB) -o bin/$(PROG).elf
	cd bin && avr-objcopy -O srec $(PROG).elf $(PROG).rom
#	checksize $(PROG).elf
	avrdude -p $(MMCU) -P $(USB_PORT) -c $(STK) -b $(BAUD) -F -u -U flash:w:bin/$(PROG).rom


mega: clean install

uno: clean install

pc: clean
	gcc -DPC $(SRC) -o bin/$(PROG).x

clean:
	@ cd bin && rm -f *.o *.rom *.elf *.map *~ *.lst *.x
	@ echo "Project cleaned"

help:
	@ echo "Check your code includes 'WProgram.h' \nCheck you call 'init()'"

# reprogram the fuses for the right clock source
#fuse:
#	avrdude -p atmega168 -c stk200 -U lfuse:w:0x62:m

.PHONY : clean uno due mega install help
