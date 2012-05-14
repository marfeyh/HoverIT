#
#This program is free software: you can redistribute it and/or modify
#it under the terms of the GNU General Public License as
#published by the Free Software Foundation, either version 3 of the
# License, or (at your option) any later version.

# This program is distodributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
# GNU General Public License for more details.

# You should have received a copy of the GNU General Public
# License along with this program. If not, see
# <http://www.gnu.org/licenses/gpl-3.0.html>.
# 

# 
# @file Makefile
# @details Makefile for building the embedded part of the project. When a workpackage is ready for integration 
# a new line should be added to this makefile, also the makefile of the Hovercraft workpackage should be modified 
# to include the static library.
# @authors Peter Myllykoski
# @version 0.1 (optional)
# 
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
