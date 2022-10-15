/*
  Authors: Tom Causer, Finn Hansch, Jacek Patora, Pavlos Vlazakis
  Date: 2022-10-15
  Version: 1.0
  Language: C

  Responsiblities:

  txStatusSensor is responsible for holding the current transmission status (ON or OFF)

*/

void txStatusSensor_init();
void txStatusSensor_set(bool status);
bool txStatusSensor_get();
