/*
 * modes.cpp
 *
 * Date: 2022-10-15
 * Version: 1.0
 * Language: C
 *
 * Title:
 *		Modes
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
#include "env_vars.h"
#include "modesIndicator.h"
#include "modesPO.h"
#include "modes.h"

void modes_init(void) { 
  modesPO_init();
  modesIndicator_init();
}

void modes_set(mode_t mode) {
  modesPO_set(mode);
}

void modes_get(mode_t *mode) {
  modesPO_get(mode);
}
