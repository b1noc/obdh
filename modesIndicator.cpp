#include <Arduino.h>
#include "modesIndicator.h"
#include "env_vars.h"


void modesIndicator_init() {
	  pinMode(LEDPIN, OUTPUT);    
}

void modesIndicator_set(bool mode) {
	if (mode == SAFE) {
		digitalWrite(LEDPIN, HIGH);
	}
	else if (mode == NORMAL) {
		digitalWrite(LEDPIN, LOW);
	}
}
