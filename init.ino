/*
  Authors: Tom Causer, Finn Hansch, Jacek Patora, Pavlos Vlazakis
  Date: 2022-10-15
  Version: 1.0
  Language: C

  Responsiblities: 

  Init is responsible for initiating all objects. It is the main file.

 */

#include "env_vars.h"
#include "sensor.h"
#include "command.h"
#include "modes.h"

void setup() {

#ifdef DEBUG
	Serial.begin(9600);
	while (!Serial) {}
	Serial.print("BOOT \n");
#endif
	modes_init();
	sensor_activate();
	command_activate();
#ifdef DEBUG
	Serial.print("setup completed \n");
#endif
}

void loop() {}
