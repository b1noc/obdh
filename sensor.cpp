/*
 * sensor.cpp
 *
 * Date: 2022-10-15
 * Version: 1.0
 * Language: C
 *
 * Title:
 *		Sensor
 *
 * Method:
 *		This object initializes all it's child objects and delegates function
 *		calls.	
 *
 * Authors:
 * 		Tom Causer, Finn Hansch, Jacek Patora, Pavlos Vlazakis
 *
 * Reviewed:
 * 		Tom Causer, Finn Hansch, Jacek Patora, Pavlos Vlazakis, 20 October 2022
 */
#include <Arduino.h>
#include <Arduino_FreeRTOS.h>
#include "modes.h"
#include "sensor.h"
#include "txSensor.h"
#include "samplerSensorP.h"
#include "txStatusSensor.h"

void sensor_activate(void) {
	txSensor_init();
	samplerSensorP_activate();
	txStatusSensor_init();
}

void sensor_setTxStatus(bool status) {
	txStatusSensor_set(status);
}
