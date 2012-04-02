#All the code should be structured as following
# / src
# 	| Makefile   
#	/computer
#		| Makefile <-- You are here
#		/feature
#       		| Makefile 
# 			| example.c
#			| example1.c
# 			/tests
#	 			| check_main.c


all: bluetooth

check: bluetooth-check

clean: 
	cd bluetooth && $(MAKE) clean

bluetooth:
	cd bluetooth && $(MAKE) 

bluetooth-check:
	cd bluetooth && $(MAKE) check

.PHONY: all check clean bluetooth bluetooth-check