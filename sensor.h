/*
 * sensor.h
 *
 * Date: 2022-10-15
 * Version: 1.0
 * Language: C
 *
 * Title:
 *		Sensor
 *
 * Responsibility:
 *		This object is responsible for sensor sampling and transmission.
 *
 * Public functions:
 * 		activate():
 * 			Initializes the object and all it's children.
 *
 * 		setTxStatus(bool status):
 * 			Changes the status to turn ON/OFF data transmission.
 *
 * Authors:
 * 		Tom Causer, Finn Hansch, Jacek Patora, Pavlos Vlazakis
 *
 * Reviewed:
 * 		Tom Causer, Finn Hansch, Jacek Patora, Pavlos Vlazakis, 20 October 2022
 */
#ifndef SENSOR.H
#define SENSOR.H

void sensor_activate(void);
void sensor_setTxStatus(bool status);

#endif
