#ifndef ENV_VARS.H
#define ENV_VARS.H

#define DEBUG

#define LEDPIN LED_BUILTIN
#define ADCPIN 14 // ADC PIN A0
#define INTERRUPTPIN 2
#define COMMANDPINLSB 8
#define COMMANDPINMSB 9
#define SAMP_TIME 500 //  TODO: In the current Assy4 document, this is TBD. Set to 500 ms.

#ifdef DEBUG
#include <Arduino.h>
#endif

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
