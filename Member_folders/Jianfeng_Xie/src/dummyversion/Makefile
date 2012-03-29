thread: bit_gen.h bit_gen.c thread_handler.c
	gcc -o thread bit_gen.c thread_handler.c -lpthread $(EXTRAGCCFLAGS)

testobjs: bit_gen.c thread_handler.c 
	gcc -o thread.o -c bit_gen.c thread_handler.c $(EXTRAGCCFLAGS)

clean:
	rm -f thread thread.exe thread.o *.gcov *.gcda *.gcno
