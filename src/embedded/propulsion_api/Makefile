pro: propulsion_api.c propulsion.c propulsion.h main.c
	gcc -o pro propulsion.c propulsion_api.c main.c -I.$(EXTRAGCCFLAGS)

test: propulsion.o propulsion_api.o

propulsion.o: propulsion.c propulsion.h
	gcc -o pro.o -c propulsion.c -I. $(EXTRAGCCFLAGS)
	
propulsion_api.o: propulsion_api.c propulsion_api.h
	gcc -o propulsion_api.o -c propulsion_api.c -I. $(EXTRAGCCFLAGS) 
	
clean:
	rm -f *.o pro pro.exe
