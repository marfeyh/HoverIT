/**
@file jobtype.h
@author Dmitry Igoshin
@brief Job types
**/
#pragma once
#ifndef __jobtype_h_
#define __jobtype_h_

/**
@enum JOB_TYPE
@brief type of the job
**/
enum JOB_TYPE {
	MOVEMENT,  // @var movement-related jobs (servos, fans)
	SENSORS,   // @var sensor-related things 
	DEMO       // @var dummy category for demo purposes
};

#endif
