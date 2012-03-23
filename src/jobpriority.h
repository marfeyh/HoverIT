/**
Author: Dmitry Igoshin
Job priorities
**/
#pragma once
#include "jobpriority.h"
#include "jobtype.h"

#ifndef __jobpriority_h_
#define __jobpriority_h_

enum PRIORITY
{
	RIGHT_NOW = 40,
	LOW = 10,
	MEDIUM = 20,
	HIGH= 30
};

#endif
