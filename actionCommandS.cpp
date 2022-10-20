/*
 * actionCommandS.cpp
 *
 * Date: 2022-10-15
 * Version: 1.0
 * Language: C
 *
 * Title:
 *		Action Command
 *
 * Method:
 *		This object creates a sporadic task that will start the Command 
 *		Interrupt Object. The loop will then be blocked by the 
 *		commandInerrupt_wait() until an interrupt is triggerd. 
 *		It then passes the returned command to the interpreter Command Object.
 *
 * Constriants: 
 * 		Deadline: 15ms [untested]
 *
 * Authors:
 * 		Tom Causer, Finn Hansch, Jacek Patora, Pavlos Vlazakis
 *
 * Reviewed:
 * 		Tom Causer, Finn Hansch, Jacek Patora, Pavlos Vlazakis, 20 October 2022
 */
#include <Arduino_FreeRTOS.h>
#include "env_vars.h"
#include "commandInterrupt.h"
#include "interpreterCommand.h"
#include "actionCommandS.h"

static void recieveMessage(void); 

void actionCommandS_activate(void){
  xTaskCreate(
    recieveMessage
    ,  "recieveMessage" 
    ,  128  
    ,  NULL
    ,  1   /* Priority TBD */
    ,  NULL );
}

static void recieveMessage(void) {
	command_t command; /* to be executed command */

	commandInterrupt_start();

  	for (;;){
		command = commandInterrupt_wait();
		interpreterCommand_execute(command);
	 }
}
