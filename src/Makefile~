#All the code should be structured as following
# | Makefile   <--- You are here
# / src
#	/computer
#	| Makefile
#		/feature
#       	| Makefile 
# 		| example.c
#		| example1.c
# 		/tests
#	 		| check_main.c

computer:
	cd computer && $(MAKE) 

embedded:
	cd embedded && $(MAKE) 

computer-check: 
	cd computer && $(MAKE) check

embedded-check:
	cd embedded && $(MAKE) check

.PHONY: computer embedded computer-check embedded-check