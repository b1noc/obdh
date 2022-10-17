/*
  Authors: Tom Causer, Finn Hansch, Jacek Patora, Pavlos Vlazakis
  Date: 2022-10-15
  Version: 1.0
  Language: C

  Responsiblities:

  actionCommandS is responsible for reading commands, interpreting these
  commands and then taking action as described in [A1]

*/

#include "actionCommandS.h"
#include "commandInterrupt.h"
#include "interpreterCommand.h"
// TODO: include global vars and add command_t type there.

static void interpretFunction();

void actionCommandS_activate(){
  xTaskCreate(
    interpretFunction
    ,  "interpretFunction" // Name for identification
    ,  128  // The stack size
    ,  NULL
    ,  1  // Priority. 3 is highest, 0 is lowest.
    ,  NULL );

}

static void interpretFunction(void *pvParameters) {
  	(void) pvParameters;

	commandInterrupt_start();
	command_t command;

  	for (;;){
		command = commandInterrupt_wait();
		interpreterCommand_execute(command);
	 }
}
