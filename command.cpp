include <Arduino_FreeRTOS.h>
include <Arduino.h>
include "modes.h"
include "env_vars.h"
include "txStatusSensor.h"

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