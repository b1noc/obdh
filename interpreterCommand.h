/*
  Authors: Tom Causer, Finn Hansch, Jacek Patora, Pavlos Vlazakis
  Date: 2022-10-15
  Version: 1.0
  Language: C

  Responsiblities:

  interpreterCommand is responsible for interpreting and decoding commands.

*/


#include "env_vars.h"

void interpreterCommand_init();
void interpreterCommand_execute(command_t command);
