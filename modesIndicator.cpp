/*
  Authors: Tom Causer, Finn Hansch, Jacek Patora, Pavlos Vlazakis
  Date: 2022-10-15
  Version: 1.0
  Language: C

  Responsiblities:

  modesIndicator is responsible for indicating the current state on BUILTIN_LED.

*/


#include <Arduino.h>
#include "modesIndicator.h"
#include "env_vars.h"


void modesIndicator_init() {
	pinMode(LEDPIN, OUTPUT);    
	//TODO: status?
}

void modesIndicator_set(bool mode) {
	if (mode == 1) {
		digitalWrite(LEDPIN, HIGH);
	}
	else if (mode == 0) {
		digitalWrite(LEDPIN, LOW);
	}
}
