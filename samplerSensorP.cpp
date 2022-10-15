/*
  Authors: Tom Causer, Finn Hansch, Jacek Patora, Pavlos Vlazakis
  Date: 2022-10-15
  Version: 1.0
  Language: C

  Responsiblities:

  samplerSensorP is responsible for reading the voltage from AD-channel at a rate given by SAMP_TIME, and then forwarding this on for transmission.

*/

 // Include Arduino library
#include <Arduino.h>

 // Include the OS
#include <Arduino_FreeRTOS.h>

 // Include local files
#include "samplerSensorP.h"
#include "txSensor.h"
#include "txStatusSensor.h"

void samplerSensorP_activate(){

}
