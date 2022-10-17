/*
  Authors: Tom Causer, Finn Hansch, Jacek Patora, Pavlos Vlazakis
  Date: 2022-10-15
  Version: 1.0
  Language: C

  Responsiblities:

  samplerSensorP is responsible for reading the voltage from AD-channel at a rate given by SAMP_TIME, and then forwarding this on for transmission.

*/

 // Include Arduino library
#include <Arduino.h>

 // Include the OS
#include <Arduino_FreeRTOS.h>

 // Include local files
#include "modes.h"
#include "samplerSensorP.h"
#include "txSensor.h"
#include "txStatusSensor.h"


static uint16_t SAMP_TIME = 500; // [ms] TODO: In the current Assy4 document, this is TBD. Set to 500 ms.
								 // TODO: move to global defaults
static void sampleLoop(void *pvParameters); // Declaration for task
static uint16_t sensorVoltage;
static bool status;


void samplerSensorP_activate(){
  xTaskCreate(
    sampleLoop
    ,  "sampleLoop" // Name for identification
    ,  128  // The stack size
    ,  NULL
    ,  1  // Priority. 3 is highest, 0 is lowest.
    ,  NULL );
}

static void sampleLoop(void *pvParameters){
  	(void) pvParameters;

	uint16_t sensorValue; 
	bool currentStatus;
	mode_t currentMode; 

  	for (;;){
		/*
		This for-loop cycles infinitely. It does two mode checks. The first check is for SAFE mode,
		which does nothing except continue to check the mode. The second check is for NORMAL mode,
		which then does another check to see if we actually want to be transmitting. Provided that
		we want to be transmitting, it will then finally use txSensor to transmit the value.
		*/
		currentMode = modes_get();
		if (currentMode==SAFE){}
		if (currentMode==NORMAL){
			/*
			Provided that the mode is NORMAL, another check needs to be done to see if we are reading
			the channel or not. If txStatusSensor returns a value of 0, then we do not call the
			transmit function from txSensor.
			*/
			sensorValue = analogRead(ADCPIN); 
			currentStatus = txStatusSensor_get();
				if (currentStatus==1){
					txSensor_transmitAscii(sensorValue);
				}
		}
		vTaskDelay( SAMP_TIME / portTICK_PERIOD_MS ); // TODO: This is the wrong tick type I think. Need to change to Tick_Type_t(?)
  	}
}
