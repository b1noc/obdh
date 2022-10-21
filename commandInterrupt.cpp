/*
 * commandInterrupt.cpp
 *
 * Date: 2022-10-15
 * Version: 1.0
 * Language: C
 *
 * Title:
 * 		Command Interrupt
 *
 * Method:
 *   	This object provides interrupt handling through the use of binary
 *   	semaphores. 
 *
 * Authors:
 * 		Tom Causer, Finn Hansch, Jacek Patora, Pavlos Vlazakis
 *
 * Reviewed:
 * 		Tom Causer, Finn Hansch, Jacek Patora, Pavlos Vlazakis, 19 October 2022
 *
*/
#include <Arduino.h>
#include <Arduino_FreeRTOS.h>
#include <semphr.h>
#include "env_vars.h"
#include "commandInterrupt.h"

static void interruptHandler(void);
static SemaphoreHandle_t interruptSemaphore; /* reference to the semaphore */

void commandInterrupt_activate(void) {
	pinMode(2, INPUT_PULLUP); 
	pinMode(COMMAND_PIN_LSB, INPUT_PULLUP);
	pinMode(COMMAND_PIN_MSB, INPUT_PULLUP);
	interruptSemaphore = xSemaphoreCreateBinary(); 
}

void commandInterrupt_start(void) {
	attachInterrupt(digitalPinToInterrupt(2), interruptHandler, RISING);
}

static void interruptHandler(void) {
	xSemaphoreGiveFromISR(interruptSemaphore, NULL); 
}

void commandInterrupt_wait(command_t *command) {
	xSemaphoreTake(interruptSemaphore, portMAX_DELAY);

#ifdef DEBUG
	Serial.println("Interrupt received");
	Serial.println("command = " + (String) digitalRead(COMMAND_PIN_MSB) \
			+ digitalRead(COMMAND_PIN_LSB));
#endif

	*command = digitalRead(COMMAND_PIN_LSB) | (digitalRead(COMMAND_PIN_MSB)<<1);
}
