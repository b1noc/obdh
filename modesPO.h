/*
 * modesPO.h
 *
 * Date: 2022-10-15
 * Version: 1.0
 * Language: C
 *
 * Title:
 *		Modes Protected 
 *
 * Responsibility:
 *		This object is responsible for holding the current mode.
 *
 * Public functions:
 * 		init():
 * 			Initializing the object and setting the mode to SAFE. 
 *
 * 		set(mode_t mode):
 * 			Setting the mode to the value given as mode input argument.
 *
 * 		get():
 * 			Returning the currently set mode.
 *
 * Authors:
 * 		Tom Causer, Finn Hansch, Jacek Patora, Pavlos Vlazakis
 *
 * Reviewed:
 * 		Tom Causer, Finn Hansch, Jacek Patora, Pavlos Vlazakis, 20 October 2022
 */
#ifndef MODESPO.H
#define MODESPO.H

void modesPO_init(void);
void modesPO_set(mode_t mode);
void modesPO_get(mode_t *mode);

#endif
