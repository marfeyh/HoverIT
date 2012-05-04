<<<<<<< HEAD
#All the code should be structured as following
# / src
# 	| Makefile   <--- You are here
#	/computer
#		| Makefile 
#		/feature
#       		| Makefile 
# 			| example.c
#			| example1.c
# 			/tests
#	 			| check_main.c

computer:
	$(MAKE) all -C computer

embedded:
	$(MAKE) all -C embedded

computer-check: 
	cd computer && $(MAKE) check

embedded-check:
	cd embedded && $(MAKE) check

.PHONY: computer embedded computer-check embedded-check
