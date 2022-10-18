/*
  Authors: Tom Causer, Finn Hansch, Jacek Patora, Pavlos Vlazakis
  Date: 2022-10-15
  Version: 1.0
  Language: C

  Responsiblities:

  commandInterrupt is responsible for handling an INT0 external interrupt.

*/


#include <Arduino.h>
#include <Arduino_FreeRTOS.h>
#include <semphr.h>
#include "commandInterrupt.h"
#include "env_vars.h"

static void interruptHandler();
static SemaphoreHandle_t interruptSemaphore;

void commandInterrupt_activate(){
    pinMode(2, INPUT_PULLUP); //going from low to high voltage
    interruptSemaphore = xSemaphoreCreateBinary(); //creates the semaphore
    pinMode(COMMANDPINLSB, INPUT);
    pinMode(COMMANDPINMSB, INPUT);
}

void commandInterrupt_start(){
    if (interruptSemaphore != NULL) {
    // Attach interrupt for Arduino digital pin
    attachInterrupt(digitalPinToInterrupt(2), interruptHandler, RISING);
  }
}

static void interruptHandler(){
#ifdef DEBUG
	Serial.println("Interrupt received");
#endif
  
  xSemaphoreGiveFromISR(interruptSemaphore, NULL); //TODO: Check what NULL means here
}

command_t commandInterrupt_wait() {

    if (xSemaphoreTake(interruptSemaphore, portMAX_DELAY) == pdPASS) {
		return digitalRead(COMMANDPINLSB) | (1<<digitalRead(COMMANDPINMSB));
    }

}
