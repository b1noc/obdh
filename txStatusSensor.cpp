/*
  Authors: Tom Causer, Finn Hansch, Jacek Patora, Pavlos Vlazakis
  Date: 2022-10-15
  Version: 1.0
  Language: C

  Responsiblities:

  txStatusSensor is responsible for holding the current transmission status (ON or OFF)

*/

 // Include the OS
#include <Arduino_FreeRTOS.h>
#include <semphr.h>

 // Include local header files
#include "txStatusSensor.h"

 // Declare two static variables that will be used in this object
static bool currentState; // TODO: Is declaring this static a problem if it is returned in txStatusSensor_get()?
static SemaphoreHandle_t xSemaphore;

 // Functions

void txStatusSensor_init(){
	// Upon initialisation, transmission is set to OFF.
	currentState = 0;
	// Initialise the Mutex Semaphore as this is a protected object.
	xSemaphore = xSemaphoreCreateMutex();
	if ( xSemaphore == NULL ) 
	{
		// TODO: This would throw an error.
	}
}

void txStatusSensor_set(bool status){
	/*
	This function is responsible for taking the status
	applied to it, and setting the currentState to it
	*/
	xSemaphoreTake( xSemaphore, 0);
	currentState = status;
	xSemaphoreGive( xSemaphore );
}

bool txStatusSensor_get(){
	xSemaphoreTake( xSemaphore, 0);
	bool state = currentState;
	xSemaphoreGive( xSemaphore );
	return state;
}
