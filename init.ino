/*
 * init.ino
 *
 * Date: 2022-10-15
 * Version: 1.0
 * Language: C
 *
 * Title:
 *		Init
 *
 * Method:
 *		This object is responsible for initializing all first level objects.
 *
 * Authors:
 * 		Tom Causer, Finn Hansch, Jacek Patora, Pavlos Vlazakis
 *
 * Reviewed:
 * 		Tom Causer, Finn Hansch, Jacek Patora, Pavlos Vlazakis, 20 October 2022
 *
 * Note:
 *		This object has no header file as it is the initial file for the
 *		Arduino compiler. 
 */
#include <Arduino_FreeRTOS.h> // only required according to Appendix C
#include "env_vars.h"
#include "sensor.h"
#include "modes.h"
#include "command.h"

void setup() {

#ifdef DEBUG
	Serial.begin(9600);
	while (!Serial) {}
	Serial.println("BOOT");
#endif

	modes_init();
	sensor_activate();
	command_activate();

#ifdef DEBUG
	Serial.println("Setup completed");
#endif
}

void loop() {
	/* empty */
}
