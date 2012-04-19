#All the code should be structured as following
# / src
# 	| Makefile   
#	/embedded
#		| Makefile <-- You are here
#		/feature
#       		| Makefile 
# 			| example.c
#			| example1.c
# 			/tests
#	 			| check_main.c


all: 
	$(MAKE) lib-install -C Scheduler
	$(MAKE) lib-install -C Communication
	$(MAKE) lib-install -C Propulsion
	$(MAKE) lib-install -C Hover
	$(MAKE) prog -C Hovercraft

clean:
	$(MAKE) clean -C Scheduler
	$(MAKE) clean -C Communication
	$(MAKE) clean -C Propulsion
	$(MAKE) clean -C Hover
	$(MAKE) clean -C Hovercraft