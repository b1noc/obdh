/*
 * modes.h
 *
 * Date: 2022-10-15
 * Version: 1.0
 * Language: C
 *
 * Title:
 *		Modes
 *
 * Responsibility:
 * 		This object is responsible for holding and indicating the current status 
 * 		on the indicator LED.
 *
 * Public functions:
 * 		init():
 * 			Initializes the object and all it's children.
 *
 * 		set(mode_t mode):
 * 			Set the mode.
 *
 * 		get():
 * 			Return the mode.
 *
 * Authors:
 * 		Tom Causer, Finn Hansch, Jacek Patora, Pavlos Vlazakis
 *
 * Reviewed:
 * 		Tom Causer, Finn Hansch, Jacek Patora, Pavlos Vlazakis, 20 October 2022
 */
#ifndef MODES.H
#define MODES.H

void modes_init(void);
void modes_set(mode_t mode);
void modes_get(mode_t *mode);

#endif
