/*
  Authors: Tom Causer, Finn Hansch, Jacek Patora, Pavlos Vlazakis
  Date: 2022-10-15
  Version: 1.0
  Language: C

  Responsiblities:

  txSensor is responsible for transmitting sensor measurements to the USART in the format stated in Appendix 3.

*/

 // Include Arduino library
#include <Arduino.h>

 // Include local header files
#include "txSensor.h"

void txSensor_init(){
  /*
  This function initialises the USB with a bit rate of 9600 bits per second, and
  specifies a format of 8N1, meaning 8 data bits, no parity and 1 stop bit.  
  */
  Serial.begin(9600, SERIAL_8N1); //

  while (!Serial) {
    ; // wait for serial port to connect. Needed for the USB port.
  }
}

void txSensor_transmitAscii(uint16_t data){
    Serial.println(data);
}
