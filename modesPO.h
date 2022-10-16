/*
  Authors: Tom Causer, Finn Hansch, Jacek Patora, Pavlos Vlazakis
  Date: 2022-10-15
  Version: 1.0
  Language: C

  Responsiblities:

  modesPO is responsible for holding the current state.

*/


#ifndef MODESPO.H
#define MODESPO.H

#include "env_vars.h"

void modesPO_init();
void modesPO_set(mode_t mode);
mode_t modesPO_get();

#endif
