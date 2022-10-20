/*
 * txSensor.h
 *
 * Date: 2022-10-15
 * Version: 1.0
 * Language: C
 *
 * Title:
 *		TX 
 *
 * Responsibility:
 *		This object is responsible for transmitting Ascii data to the USART in 
 *		the format stated in Appendix 3.
 *
 * Public functions:
 * 		init():
 * 			Initializes the serial device.
 *
 * 		transmitAscii(unit16_t data):
 * 			Transmit the Ascii data via the serial device.
 *
 * Authors:
 * 		Tom Causer, Finn Hansch, Jacek Patora, Pavlos Vlazakis
 *
 * Reviewed:
 * 		Tom Causer, Finn Hansch, Jacek Patora, Pavlos Vlazakis, 20 October 2022
 */
#ifndef TXSENSOR.H
#define TXSENSOR.H

void txSensor_init(void);
void txSensor_transmitAscii(uint16_t data);

#endif
