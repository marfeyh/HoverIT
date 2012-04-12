
#       Searduino
#
#  Copyright (C) 2011, 2012 Henrik Sandklef      
#                                                                   
# This program is free software; you can redistribute it and/or     
# modify it under the terms of the GNU General Public License       
# as published by the Free Software Foundation; either version 3    
# of the License, or any later version.                             
#                                                                   
#                                                                   
# This program is distributed in the hope that it will be useful,   
# but WITHOUT ANY WARRANTY; without even the implied warranty of    
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the     
# GNU General Public License for more details.                      
#                                                                   
# You should have received a copy of the GNU General Public License 
# along with this program; if not, write to the Free Software       
# Foundation, Inc., 51 Franklin Street, Boston,            
# MA  02110-1301, USA.                                              
#
#


SRC_C=gps.c
SRC_CXX=
# use this for uno
MAIN_SRC=test.c
MAIN_SRC=
ARDUINO=stub
#ARDUINO = uno

# define PROG to make a stad alone program
# PROG=henrik

# defnie SHLIB to create a lib for simulator
SHLIB=gpstest.so

SEARDUINO_PATH=/opt/searduino

check: $(SHLIB)

include $(SEARDUINO_PATH)/share/searduino/mk/searduino.mk
#include $(SEARDUINO_PATH)/mk/searduino_lib.mk

check-upload:
	BOARD=due
	make upload

install:
	echo nothing to do in install

distdir:
	echo nothing to do in dist

all:
	echo nothing to do for all