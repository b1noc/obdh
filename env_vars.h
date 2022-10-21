/*
 * env_vars.h
 *
 * Date: 2022-10-15
 * Version: 1.0
 * Language: C
 *
 * Title:
 *		Global environment variables.
 *
 * Responsibility:
 *		This file includes all the global constants and type definitions that
 *		are used in the software.
 *
 * Authors:
 * 		Tom Causer, Finn Hansch, Jacek Patora, Pavlos Vlazakis
 *
 * Reviewed:
 * 		Tom Causer, Finn Hansch, Jacek Patora, Pavlos Vlazakis, 20 October 2022
 */
#ifndef ENV_VARS.H
#define ENV_VARS.H

//#define DEBUG

#ifdef DEBUG
#include <Arduino.h> /* enabling all objects to write to the serial device */
#endif

#define LED_PIN LED_BUILTIN
#define ADC_PIN 14 /* ADC PIN A0 */
#define INTERRUPT_PIN 2
#define COMMAND_PIN_LSB 8
#define COMMAND_PIN_MSB 9

#define BAUD_RATE 9600
#define SERIAL_SETUP SERIAL_8N1 /* 8 data bits, no parity, 1 stop bit. */

#define TPRIO_RECEIVE_MESSAGE 1 /* TBD */
#define TPRIO_SAMPLE_LOOP 1 /* TBD */

/*
 * The SAMP_TIME shall be a multiple of TickTime (16ms) to avoid rounding
 * errors when converting it to a ticktime.
 */
#define SAMP_TIME 400 /* TBD */ 

/*
 * Type:
 * 		mode_t
 *
 * 	Function:
 * 		Used to define the software mode.
 *
 * 	Modes:
 * 		SAFE:
 * 			Stops all features but command reception.	
 *
 * 		NORMAL:
 * 			Enables all features to run.
 */
typedef enum
{
	NORMAL,
	SAFE
} mode_t;

/*
 * Type:
 * 		command_t
 *
 * 	Function:
 * 		Used to define commands interpreted by the software.
 *
 * 	Modes:
 * 		TRANS_ON: 
 * 			Switch transmission of data via the serial device on.
 * 		TRANS_OFF: 
 * 			Switch transmission of data via the serial device off.
 * 		NORMAL_MODE:
 * 			Switch software mode to NORMAL.
 * 		SAFE_MODE:
 * 			Switch software mode to SAFE.
 */
typedef enum 
{ 
    TRANS_ON, 
    TRANS_OFF, 
    NORMAL_MODE,
    SAFE_MODE 
} command_t;

#endif
