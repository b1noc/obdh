/*
 * modesIndicator.cpp
 *
 * Date: 2022-10-15
 * Version: 1.0
 * Language: C
 *
 * Title:
 *		Modes Indicator
 *
 * Method:
 *		The LED is switched ON/OFF by using Arduino library calls.
 *
 * Authors:
 * 		Tom Causer, Finn Hansch, Jacek Patora, Pavlos Vlazakis
 *
 * Reviewed:
 * 		Tom Causer, Finn Hansch, Jacek Patora, Pavlos Vlazakis, 20 October 2022
 */

#include <Arduino.h>
#include "env_vars.h"
#include "modesIndicator.h"

void modesIndicator_init(void) {
	pinMode(LED_PIN, OUTPUT);    
}

void modesIndicator_set(bool status) {
	if (status == 1) {
#ifdef DEBUG
		Serial.println("Turn on LED");
#endif
		digitalWrite(LED_PIN, HIGH);
	}
	else if (status == 0) {
#ifdef DEBUG
		Serial.println("Turn off LED");
#endif
		digitalWrite(LED_PIN, LOW);
	}
}
