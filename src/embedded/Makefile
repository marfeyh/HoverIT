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
#	$(MAKE) lib-install -C determine-speed
	$(MAKE) lib-install -C Pressure
	$(MAKE) lib-install -C 3pp
	$(MAKE) prog -C Hovercraft

check:
	$(MAKE) check -C Scheduler
	$(MAKE) check -C Communication
	$(MAKE) check -C Propulsion
	$(MAKE) check -C Hover
	$(MAKE) check -C Rudder_control
#	$(MAKE) check -C determine-speed
#	$(MAKE) check -C Pressure

gcovcheck:
	$(MAKE) gcovcheck -C Scheduler
	$(MAKE) gcovcheck -C Communication
	$(MAKE) gcovcheck -C Propulsion
	$(MAKE) gcovcheck -C Hover
	$(MAKE) gcovcheck -C Rudder_control
#	$(MAKE) gcovcheck -C determine-speed
#	$(MAKE) gcovcheck -C Pressure
	gcovr -x --xml > coverage.xml

memcheck:
	$(MAKE) memcheck -C Scheduler
	$(MAKE) memcheck -C Communication
	$(MAKE) memcheck -C Propulsion
	$(MAKE) memcheck -C Hover
	$(MAKE) memcheck -C Rudder_control
#	$(MAKE) memcheck -C determine-speed
#	$(MAKE) memcheck -C Pressure

clean-tests:
	$(MAKE) clean-tests -C Scheduler
	$(MAKE) clean-tests -C Communication
	$(MAKE) clean-tests -C Propulsion
	$(MAKE) clean-tests -C Hover
	$(MAKE) clean-tests -C Rudder_control
#	$(MAKE) clean-tests -C determine-speed
	$(MAKE) clean-tests -C Pressure

clean: clean-tests
	$(MAKE) clean -C Scheduler
	$(MAKE) clean -C Communication
	$(MAKE) clean -C Propulsion
	$(MAKE) clean -C Hover
	$(MAKE) clean -C Rudder_control
	$(MAKE) clean -C Hovercraft
#	$(MAKE) clean -C determine-speed
	$(MAKE) clean -C Pressure
	$(MAKE) clean -C 3pp
