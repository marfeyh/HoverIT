/*!
  This file is part of Hoveritu.
  
  Hoveritu is free software: you can redistribute it and/or modify
  it under the terms of the GNU General Public License as published by
  the Free Software Foundation, either version 3 of the License, or
  (at your option) any later version.
  
  Hoveritu is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License for more details.
  
  You should have received a copy of the GNU General Public License
  along with Hoveritu.  If not, see <http://www.gnu.org/licenses/>.
*/
/**
@author: Dmitry Igoshin
brief job structure
**/
#pragma once
/**
@struct Job 
**/
struct Job {
	void (*task)();		/** @var pointer to the function to call **/
	enum PRIORITY prio;	/** @var priority **/
	enum JOB_TYPE type;	/** @var type **/
};
