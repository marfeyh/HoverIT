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
	$(MAKE) lib-install -C Rudder_control
	$(MAKE) lib-install -C determine-speed
	$(MAKE) prog -C Hovercraft

check:
	$(MAKE) check -C Propulsion
	$(MAKE) check -C Communication

gcovcheck:
	$(MAKE) gcovcheck -C Propulsion
	$(MAKE) gcovcheck -C Communication
	gcovr -x --xml > coverage.xml

memcheck:
	$(MAKE) memcheck -C Propulsion

clean-tests:
	$(MAKE) clean-tests -C Propulsion
	$(MAKE) clean-tests -C Communication

clean: clean-tests
	$(MAKE) clean -C Scheduler
	$(MAKE) clean -C Communication
	$(MAKE) clean -C Propulsion
	$(MAKE) clean -C Hover
	$(MAKE) clean -C Rudder_control
	$(MAKE) clean -C Hovercraft