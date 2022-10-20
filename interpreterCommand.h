/*
 * interpreterCommand.h
 *
 * Date: 2022-10-15
 * Version: 1.0
 * Language: C
 *
 * Title:
 *		Interpreter Command 
 *
 * Responsibility:
 *		This object is responsible for interpreting the received command and
 *		taking appropriate action according to [A1].
 *		It can perform mode changes and change the transmission status.
 *
 * Public functions:
 * 		init():
 * 			Initialize the object.
 *
 * 		execute(command_t command):
 * 			Executes the command from the input parameter command.
 *
 * Authors:
 * 		Tom Causer, Finn Hansch, Jacek Patora, Pavlos Vlazakis
 *
 * Reviewed:
 * 		Tom Causer, Finn Hansch, Jacek Patora, Pavlos Vlazakis, 20 October 2022
 */
#ifndef INTERPRETERCOMMAND.H
#define INTERPRETERCOMMAND.H

void interpreterCommand_init(void);
void interpreterCommand_execute(command_t command);

#endif
