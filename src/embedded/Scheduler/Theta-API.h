/** 
 *  \file			Theta-API.h	
 *	\details		This module could be included wherever either of the functions 
 *					"control" or "putJobInQueue" are invoked.
 *	\date			09-04-2012 
 *	\version		0.1
 *	\author 		Mozhan Soltani
 */
#if !defined Theta-API_h
 #define Theta-API_h
	void control();
	void putJobInQueue(struct Job job);
#endif
