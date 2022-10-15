/*
  Authors: Tom Causer, Finn Hansch, Jacek Patora, Pavlos Vlazakis
  Date: 2022-10-15
  Version: 1.0
  Language: C

  Responsiblities:

  txSensor is responsible for transmitting sensor measurements to the USART in the format stated in Appendix 3.

*/

void txSensor_init();
void txSensor_transmitAscii(uint16_t data);
