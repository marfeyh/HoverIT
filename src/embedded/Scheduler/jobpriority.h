/** 
 *  \file			jobpriority.h	
 *	\version		0.1
 *	\author 		Dmitry Igoshin
 *	\attention 		Sections added/modified are as follow: 
 *                  - The initial enum PRIORITY was provided.
 *  \n
 *	\date			13-04-2012  
 *	\version		0.2
 *	\author 		Mozhan Soltani
 *	\attention 		Sections added/modified are as follow: 
 *                  - The prefix "PRIO_" was added to all fields of the enum due to a reported conflict with arduino library.
 *					- Comment was modified.
 *					- Guards were modified to foloow the provided standard.
 */
#pragma once
#if !defined jobpriority_h
#define jobpriority_h

/**
@enum priority
@brief job priority (the more - the higher)
**/
enum PRIORITY {PRIO_LOW=10,PRIO_MEDIUM=20,PRIO_HIGH=30,PRIO_RIGHT_NOW=40};

#endif
