/*
  Authors: Tom Causer, Finn Hansch, Jacek Patora, Pavlos Vlazakis
  Date: 2022-10-15
  Version: 1.0
  Language: C

  Responsiblities: 

  Init is responsible for initiating all objects. It is the main file.

 */

#include "sensor.h"
#include "command.h"
#include "modes.h"

void setup() {
	sensor_init();
	command_init();
	mode_init();
}

void loop() {}