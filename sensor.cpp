/*
  Authors: Tom Causer, Finn Hansch, Jacek Patora, Pavlos Vlazakis
  Date: 2022-10-15
  Version: 1.0
  Language: C

  Responsiblities:

  Sensor is responsible for sensor sampling and transmission.

*/

 // Include Arduino library
#include <Arduino.h>

 // Include the OS
#include <Arduino_FreeRTOS.h>

 // Include local headers
#include "modes.h"
#include "sensor.h"
#include "txSensor.h"
#include "samplerSensorP.h"
#include "txStatusSensor.h"

 // Define functions

void sensor_activate(){
	txSensor_init();
	samplerSensorP_activate();
	txStatusSensor_init();
}

void sensor_setTxStatus(bool status){
	mode_t mode = modes_get();
	if (mode == NORMAL, status==1){
		txStatusSensor_set(1);
	}
	if (mode == SAFE, status==0){
		txStatusSensor_set(0);
	}
	else {
	// TODO: Include error handling incase the bool status received is neither 0 or 1
	}
}
