/*
 * interpreterCommand.cpp
 *
 * Date: 2022-10-15
 * Version: 1.0
 * Language: C
 *
 * Title:
 *		Interpreter Command 
 *
 * Method:
 *		This object includes the logic given in [A1] for execution of commands.
 *		It will set the mode and transmission status depending on the command 
 *		received.
 *		If the TRANS_ON signal is received it will check if the mode is SAFE 
 *		before executing the command. If the mode is SAFE the command will be 
 *		ignored.
 *
 * Authors:
 * 		Tom Causer, Finn Hansch, Jacek Patora, Pavlos Vlazakis
 *
 * Reviewed:
 * 		Tom Causer, Finn Hansch, Jacek Patora, Pavlos Vlazakis, 20 October 2022
 */
#include <Arduino.h>
#include <Arduino_FreeRTOS.h>
#include <env_vars.h>
#include "modes.h"
#include "sensor.h"
#include "interpreterCommand.h"

void interpreterCommand_init(void) {
	/* empty */
}

void interpreterCommand_execute(command_t command) {

#ifdef DEBUG
	Serial.println("Command execute = " + (String) command);
#endif

	if (command == SAFE_MODE) {
		modes_set(SAFE);
	}
	else if (command == NORMAL_MODE) {
		modes_set(NORMAL);
	}
	else if (command == TRANS_ON) {
		if (modes_get() != SAFE){
			sensor_setTxStatus(1);
		}
	}
	else if (command == TRANS_OFF) {
		sensor_setTxStatus(0);
	}
}
