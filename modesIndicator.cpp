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
	pinMode(LED_PIN, OUTPUT);    
}

void modesIndicator_set(bool status) {
	if (status == 1) {
#ifdef DEBUG
		Serial.println("Turn on LED status = " + (String) status);
#endif
		digitalWrite(LED_PIN, HIGH);
	}
	else if (status == 0) {
#ifdef DEBUG
		Serial.println("Turn off LED status = " + (String) status);
#endif
		digitalWrite(LED_PIN, LOW);
	}
}
