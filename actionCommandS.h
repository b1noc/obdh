/*
 * actionCommandS.h
 *
 * Date: 2022-10-15
 * Version: 1.0
 * Language: C
 *
 * Title:
 *		Action Command Object
 *
 * Responsibility:
 * 		This object is responsible to create a sporadic process that executes
 * 		commands upon a hardware interrupt. 
 *
 * Public functions:
 * 		activate():
 * 			Creates and starts the sporadic task.
 *
 * Authors:
 * 		Tom Causer, Finn Hansch, Jacek Patora, Pavlos Vlazakis
 *
 * Reviewed:
 * 		Tom Causer, Finn Hansch, Jacek Patora, Pavlos Vlazakis, 20 October 2022
 */
#ifndef ACTIONCOMMANDS.H
#define ACTIONCOMMANDS.H

void actionCommandS_activate(void);

#endif
