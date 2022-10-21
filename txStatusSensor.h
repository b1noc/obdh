/*
 * txStatusSensor.h
 *
 * Date: 2022-10-15
 * Version: 1.0
 * Language: C
 *
 * Title:
 *		Tx Status
 *
 * Responsibility:
 *		This object is a protected object responsible for holding the current 
 *		transmission status (ON or OFF). Protection of this object is 
 *		accomplished by mutual exclusion.
 *
 * Public functions:
 * 		init():
 * 			Initializing the object and setting the txStatus to 0 (OFF).
 *
 * 		set(bool status):
 * 			Setting the status to the value given as status input argument.
 *
 * 		get():
 * 			Returning the currently set txStatus.
 *
 * Authors:
 * 		Tom Causer, Finn Hansch, Jacek Patora, Pavlos Vlazakis
 *
 * Reviewed:
 * 		Tom Causer, Finn Hansch, Jacek Patora, Pavlos Vlazakis, 20 October 2022
 */

#ifndef TXSTATUSSENSOR.H
#define TXSTATUSSENSOR.H

void txStatusSensor_init(void);
void txStatusSensor_set(bool status);
void txStatusSensor_get(bool *status);

#endif
