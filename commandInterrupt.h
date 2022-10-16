/*
  Authors: Tom Causer, Finn Hansch, Jacek Patora, Pavlos Vlazakis
  Date: 2022-10-15
  Version: 1.0
  Language: C

  Responsiblities:

  commandInterrupt is responsible for handling an INT0 external interrupt.

*/

#include "env_vars.h"

void commandInterrupt_activate();
void commandInterrupt_start();
command_t commandInterrupt_wait();
