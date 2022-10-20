/*
 * command.cpp
 *
 * Date: 2022-10-15
 * Version: 1.0
 * Language: C
 *
 * Title:
 *		Command
 *
 * Method:
 *		This object initializes all it's child objects. 
 *
 * Authors:
 * 		Tom Causer, Finn Hansch, Jacek Patora, Pavlos Vlazakis
 *
 * Reviewed:
 * 		Tom Causer, Finn Hansch, Jacek Patora, Pavlos Vlazakis, 20 October 2022
 */
#include "commandInterrupt.h"
#include "actionCommandS.h"
#include "interpreterCommand.h"
#include "command.h"

void command_activate(void) {
    commandInterrupt_activate();
    actionCommandS_activate();
    interpreterCommand_init();
}
