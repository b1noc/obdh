/*
  Authors: Tom Causer, Finn Hansch, Jacek Patora, Pavlos Vlazakis
  Date: 2022-10-15
  Version: 1.0
  Language: C

  Responsiblities:

  modes is responsible for holding and indicating the current status on BUILTIN_LED.

*/

#ifndef MODES.H
#define MODES.H

#include "env_vars.h"

void modes_init();
void modes_set(mode_t mode);
mode_t modes_get();

#endif
