/*
  Authors: Tom Causer, Finn Hansch, Jacek Patora, Pavlos Vlazakis
  Date: 2022-10-15
  Version: 1.0
  Language: C

  Responsiblities:

  modes is responsible for holding and indicating the current status on BUILTIN_LED.

*/

#include "modesIndicator.h"
#include "modesPO.h"
#include "modes.h"

/*
This function initializes its childeren.
*/
void modes_init(){ 
  void modesIndicator_init();
  void modesPO_init();
}

void modes_set(mode_t mode) {
  modesPO_set(mode);
}

mode_t mode_get(){
  return modesPO_get();
}
