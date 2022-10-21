/*
 * txSensor.cpp
 *
 * Date: 2022-10-15
 * Version: 1.0
 * Language: C
 *
 * Title:
 *		TX 
 *
 * Method:
 *		This object sets up the Serial device and writes data to it using 
 *		Arduino library calls.
 *
 * Authors:
 * 		Tom Causer, Finn Hansch, Jacek Patora, Pavlos Vlazakis
 *
 * Reviewed:
 * 		Tom Causer, Finn Hansch, Jacek Patora, Pavlos Vlazakis, 20 October 2022
 *
 * 	Note:
 * 		The serial initialization is removed when the compile DEBUG flag is set 
 * 		as the Serial device is initialized in the init.ino file so that all 
 * 		objects can write messages.
 */
#include <Arduino.h>
#include "env_vars.h"
#include "txSensor.h"

void txSensor_init(void) {
#ifndef DEBUG
  Serial.begin(BAUD_RATE, SERIAL_SETUP); 
  while (!Serial) {
    ; /* wait for serial port to connect. */ 
  }
#endif
}

void txSensor_transmitAscii(uint16_t data) {
    Serial.println(data);
}
