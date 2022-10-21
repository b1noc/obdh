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
#include "env_vars.h"
#include "txStatusSensor.h"

static bool txStatus; /* TX status deciding if transmission is ON/OFF. */
static SemaphoreHandle_t xSemaphore; /* Mutex semaphore reference */

void txStatusSensor_init(void) {
	xSemaphore = xSemaphoreCreateMutex();
	/* 
	 * Question @Anita: Does it make sense to call the txStatusSensor_set() 
	 * function instead of initializing the state directly?
	 */
	txStatusSensor_set(0);
}

void txStatusSensor_set(bool status) {
#ifdef DEBUG
	Serial.println("sensor_setTxStatus: status = "+ (String)status);
#endif
	xSemaphoreTake(xSemaphore, 0);
	txStatus = status;
	xSemaphoreGive(xSemaphore);
}

void txStatusSensor_get(bool *status) {
	xSemaphoreTake(xSemaphore, 0);
	*status = txStatus;
	xSemaphoreGive(xSemaphore);
}
