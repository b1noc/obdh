/*
 * modesPO.cpp
 *
 * Date: 2022-10-15
 * Version: 1.0
 * Language: C
 *
 * Title:
 *		Modes Protected 
 *
 * Method:
 * 		This object uses Mutex Semaphores to protect the reading and writing of
 * 		the mode.
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
#include "modesIndicator.h"
#include "modesPO.h"

static mode_t swMode; /* current mode of Software */
static SemaphoreHandle_t xSemaphore; /* Mutex semaphore reference */

void modesPO_init(void) {
	xSemaphore = xSemaphoreCreateMutex();
	/* 
	 * Question @Anita: Does it make sense to call the modesPO_set() function
	 * instead of initializing the mode directly?
	 */
	modesPO_set(SAFE);
}

void modesPO_set(mode_t mode) {
#ifdef DEBUG
	Serial.println("setMode to: " + (String) mode);
#endif
	xSemaphoreTake(xSemaphore, 0);
	swMode = mode;
	xSemaphoreGive(xSemaphore);
	if(mode==NORMAL){
		modesIndicator_set(0);
	}
	else if(mode==SAFE){
		modesIndicator_set(1);
	}
}

void modesPO_get(mode_t *mode) {
	xSemaphoreTake(xSemaphore, 0);
	*mode = swMode;
	xSemaphoreGive(xSemaphore);
}

