/*
 * command.h
 *
 * Date: 2022-10-15
 * Version: 1.0
 * Language: C
 *
 * Title:
 *		Command 
 *
 * Responsibility:
 *    This object is responsible for reading and interpreting commands 
 *    and then taking action as described in [A1]. 
 *    The commands are read in by the Arduino via two pins and the
 *    command read is triggered on a RISING voltage on a hardware interrupt pin.
 *		
 * Public functions:
 * 		activate():
 * 			Initializes the object and all it's children.
 *
 * Authors:
 * 		Tom Causer, Finn Hansch, Jacek Patora, Pavlos Vlazakis
 *
 * Reviewed:
 * 		Tom Causer, Finn Hansch, Jacek Patora, Pavlos Vlazakis, 20 October 2022
 */
#ifndef COMMAND.H
#define COMMAND.H

void command_activate(void);

#endif
