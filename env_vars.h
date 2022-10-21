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
#define RECEIVE_MESSAGE_TASK_PRIO 1 /* TBD */
#define SAMP_TIME 500 /* TBD */ 

typedef enum
{
	NORMAL,
	SAFE
} mode_t;

typedef enum 
{ 
    TRANS_ON, 
    TRANS_OFF, 
    NORMAL_MODE,
    SAFE_MODE 
} command_t;

#endif
