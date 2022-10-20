/*
 * commandInterrupt.h
 *
 * Date: 2022-10-15
 * Version: 1.0
 * Language: C
 *
 * Title:
 *		Command Interrupt
 *
 * Responsibility:
 *		This object is responsible for handling the hardware interrupt and is
 *		initialized to run upon a rising voltage on the external INTERRUPT_PIN
 *		of the Arduino.
 *		On interrupt the wait() function will return the command read on the 
 *		command input pins COMMAND_PIN_MSB and COMMAND_PIN_LSB defined in 
 *		env_vars.h.
 *
 * Public functions:
 * 		activate():
 * 			Initializes the Command Interrupt Object.
 *
 * 		start(): 
 * 			Enables the watching for the interrupt on INTERRUPT_PIN.
 *
 * 		wait():
 * 			Provides a service to other objects to wait until the interrupt is
 * 			triggered. It then returns the command read from COMMAND_PIN_MSB 
 * 			and COMMAND_PIN_LSB of type command_t. 
 *
 * Authors:
 * 		Tom Causer, Finn Hansch, Jacek Patora, Pavlos Vlazakis
 *
 * Reviewed:
 * 		Tom Causer, Finn Hansch, Jacek Patora, Pavlos Vlazakis, 19 October 2022
 *
 * 	Note:
 * 		The return type of commandInterrupt_wait was changed after discussion 
 * 		with the customer to avoid working with pointers.
 */
#ifndef COMMANDINTERRUPT.H
#define COMMANDINTERRUPT.H

void commandInterrupt_activate(void);
void commandInterrupt_start(void);
command_t commandInterrupt_wait(void); 

#endif
