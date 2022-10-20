/*
 * modesIndicator.h
 *
 * Date: 2022-10-15
 * Version: 1.0
 * Language: C
 *
 * Title:
 *		Modes Indicator
 *
 * Responsibility:
 * 		This object is responsible for turning ON/OFF the MODE LED. 
 *
 * Public functions:
 * 		init():
 * 			Initialize the LED PIN
 *
 * 		set(bool status)
 * 			Turn the LED ON/OFF depending on the input argument status.
 *
 * Authors:
 * 		Tom Causer, Finn Hansch, Jacek Patora, Pavlos Vlazakis
 *
 * Reviewed:
 * 		Tom Causer, Finn Hansch, Jacek Patora, Pavlos Vlazakis, 20 October 2022
 */
#ifndef MODESINDICATOR.H
#define MODESINDICATOR.H

void modesIndicator_init(void);
void modesIndicator_set(bool status);

#endif
