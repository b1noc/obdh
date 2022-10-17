/*
  Authors: Tom Causer, Finn Hansch, Jacek Patora, Pavlos Vlazakis
  Date: 2022-10-15
  Version: 1.0
  Language: C

  Responsiblities:

  interpreterCommand is responsible for interpreting and decoding commands.

*/

#include <Arduino.h>
#include <Arduino_FreeRTOS.h>
#include "modes.h"
#include "interpreterCommand.h"
#include "sensor.h"

static mode_t mode;

void interpreterCommand_init(){
	/*
	interpreterCommand initially sets the transmission status to OFF
	and sets the mode to SAFE
	*/
	//TODO: check if they should really be removed
	//sensor_setTxStatus(0);
	//modes_set(SAFE);
}

void interpreterCommand_execute(command_t command){
	/*
	interpreterCommand_execute checks what the command is and then
	executes it. If asked to turn transmission on while in SAFE mode,
	the command will be ignored.
	*/
	if (command == TRANS_ON){
		mode = modes_get();
		if (mode!=SAFE){
			sensor_setTxStatus(1);
		}
	}
        if (command == TRANS_OFF){
		sensor_setTxStatus(0);
	}
        if (command == NORMAL_MODE){
                modes_set(NORMAL);
        }
        if (command == SAFE_MODE){
                modes_set(SAFE);
        }
}
