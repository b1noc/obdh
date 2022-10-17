/*
  Authors: Tom Causer, Finn Hansch, Jacek Patora, Pavlos Vlazakis
  Date: 2022-10-15
  Version: 1.0
  Language: C

  Responsiblities:

  command is responsible for reading commands, interpreting these
  commands and then taking action as described in [A1]

*/


#include <Arduino_FreeRTOS.h>
#include <Arduino.h>
#include "modes.h"
#include "env_vars.h"
#include "txStatusSensor.h"
#include "interpreterCommand.h"
#include "actionCommandS.h"

void activate(){
    commandInterrupt_activate();
    actionCommandS_activate();
    interpreterCommand_init();
}

void txStatusSensor_set(bool status){
    txStatusSensor_set(status);
}

void modes_set(mode_t mode){
    modes_set(mode);
}

mode_t modes_get(){
    return modes_get()
}
