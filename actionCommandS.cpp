/*
  Authors: Tom Causer, Finn Hansch, Jacek Patora, Pavlos Vlazakis
  Date: 2022-10-15
  Version: 1.0
  Language: C

  Responsiblities:

  actionCommandS is responsible for reading commands, interpreting these
  commands and then taking action as described in [A1]

*/

#include <Arduino_FreeRTOS.h>
#include "actionCommandS.h"
#include "commandInterrupt.h"
#include "env_vars.h"
#include "interpreterCommand.h"

static void recieveMessage(void *pvParameters); 

void actionCommandS_activate(){
  xTaskCreate(
    recieveMessage
    ,  "recieveMessage" // Name for identification
    ,  128  // The stack size
    ,  NULL
    ,  1  // Priority. 3 is highest, 0 is lowest.
    ,  NULL );
}

static void recieveMessage(void *pvParameters) {
  	(void) pvParameters;

	commandInterrupt_start();
	command_t command;

  	for (;;){
		command = commandInterrupt_wait();
		interpreterCommand_execute(command);
	 }
}
