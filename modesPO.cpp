/*
  Authors: Tom Causer, Finn Hansch, Jacek Patora, Pavlos Vlazakis
  Date: 2022-10-15
  Version: 1.0
  Language: C

  Responsiblities:

  modesPO is responsible for holding the current state.

*/

#include <Arduino_FreeRTOS.h>
#include <semphr.h>
#include "env_vars.h"
#include "modesIndicator.h"
#include "modesPO.h"

static mode_t mode_mem;
static SemaphoreHandle_t xSemaphore;

void modesPO_init() {
	mode_mem = SAFE;
	xSemaphore = xSemaphoreCreateMutex();
	if ( xSemaphore == NULL ) 
	{
		//this would throw an error.
	}
}

void modesPO_set(mode_t mode) {
	xSemaphoreTake(xSemaphore, 0);
  mode_mem = mode;
  if(mode==NORMAL){
    modesIndicator_set(1);
  }
  else if(mode==SAFE){
    modesIndicator_set(0);
  }
	xSemaphoreGive( xSemaphore );
}

mode_t modesPO_get() {
	xSemaphoreTake(xSemaphore, 0);
  return mode_mem;
	xSemaphoreGive( xSemaphore );
}

