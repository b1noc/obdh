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
#ifdef DEBUG
	Serial.println("sensor_setTxStatus: mode = "+ (String)mode);
	Serial.println("sensor_setTxStatus: status = "+ (String)status);
#endif
	if (mode == NORMAL) {
		txStatusSensor_set(status);
	}
	else {
		txStatusSensor_set(0);
	}
}
