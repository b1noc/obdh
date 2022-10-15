#include <Arduino_FreeRTOS.h>
#include <semphr.h>
#include "env_vars.h"
#include "modesIndicator.h"
#include "modesPO.h"

static mode_t mode_mem;
static SemaphoreHandle_t xSemaphore;

void modePO_init() {
	mode_mem = NORMAL;
	xSemaphore = xSemaphoreCreateMutex();
	if ( xSemaphore == NULL ) 
	{
		//this would throw an error.
	}
}

void modePO_set(mode_t mode) {
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

mode_t modePO_get() {
	xSemaphoreTake(xSemaphore, 0);
  return mode_mem;
	xSemaphoreGive( xSemaphore );
}

