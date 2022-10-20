/*
 * txStatusSensor.cpp
 *
 * Date: 2022-10-15
 * Version: 1.0
 * Language: C
 *
 * Title:
 *		Tx Status 
 *
 * Method:
 * 		This object uses Mutex Semaphores to protect the reading and writing of
 * 		the txStatus.
 *
 * Authors:
 * 		Tom Causer, Finn Hansch, Jacek Patora, Pavlos Vlazakis
 *
 * Reviewed:
 * 		Tom Causer, Finn Hansch, Jacek Patora, Pavlos Vlazakis, 20 October 2022
 */

#include <Arduino_FreeRTOS.h>
#include <semphr.h>
#include <env_vars.h>
#include "txStatusSensor.h"

static bool txStatus; /* TX status deciding if transmission is ON/OFF. */
static SemaphoreHandle_t xSemaphore; /* Mutex semaphore reference */

void txStatusSensor_init(void) {
	txStatus = 0;
	xSemaphore = xSemaphoreCreateMutex();
}

void txStatusSensor_set(bool status) {
#ifdef DEBUG
	Serial.println("sensor_setTxStatus: status = "+ (String)status);
#endif
	xSemaphoreTake(xSemaphore, 0);
	txStatus = status;
	xSemaphoreGive(xSemaphore);
}

bool txStatusSensor_get(void) {
	bool status; /* temporary status to be returned after give Semaphore */

	xSemaphoreTake(xSemaphore, 0);
	status = txStatus;
	xSemaphoreGive(xSemaphore);
	return state;
}
