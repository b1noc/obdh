#include "modeIndicator.h"
#include "Arduino.h"
#include "Arduino_FreeRTOS.h"

mode_t mode_mem;

void modePO_set(mode_t mode);{
  mode_mem = mode;
  if(mode==NORMAL){
    modesIndicator(True)
  }
  else if(mode==SAFE){
    modesIndicator(False)
  }
}

mode_t modePO_get(){
  return mode_mem;
}
