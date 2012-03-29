pro: pro_api.c propelsion.c propelsion.h main.c
	gcc -o pro propelsion.c pro_api.c main.c -I.$(EXTRAGCCFLAGS)

test: propelsion.o pro_api.o

propelsion.o: propelsion.c propelsion.h
	gcc -o pro.o -c propelsion.c -I. $(EXTRAGCCFLAGS)
	
pro_api.o: pro_api.c pro_api.h
	gcc -o pro_api.o -c pro_api.c -I. $(EXTRAGCCFLAGS) 
	
clean:
	rm -f *.o pro pro.exe
