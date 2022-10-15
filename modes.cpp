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
