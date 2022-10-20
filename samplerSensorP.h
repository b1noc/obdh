/*
 * samplerSensorP.h
 *
 * Date: 2022-10-15
 * Version: 1.0
 * Language: C
 *
 * Title:
 *		Sampler
 *
 * Responsibility:
 *		This object is responsible to create a periodic task that is reading the 
 *		voltage from AD-channel at a rate defined by SAMP_TIME, and	transmitting
 *		the voltage.
 *
 * Public functions:
 * 		activate():
 * 			Creates and runs the periodic Task.
 *
 * Authors:
 * 		Tom Causer, Finn Hansch, Jacek Patora, Pavlos Vlazakis
 *
 * Reviewed:
 * 		Tom Causer, Finn Hansch, Jacek Patora, Pavlos Vlazakis, 20 October 2022
 */
#ifndef SAMPLERSENSORP.H
#define SAMPLERSENSORP.H

void samplerSensorP_activate(void);

#endif
