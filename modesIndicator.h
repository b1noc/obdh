/*
  Authors: Tom Causer, Finn Hansch, Jacek Patora, Pavlos Vlazakis
  Date: 2022-10-15
  Version: 1.0
  Language: C

  Responsiblities:

  modesIndicator is responsible for indicating the current state on BUILTIN_LED.

*/

#ifndef MODESINDICATOR.H
#define MODESINDICATOR.H

void modesIndicator_init();
void modesIndicator_set(bool);

#endif
