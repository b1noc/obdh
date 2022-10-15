#ifndef ENV_VARS.H
#define ENV_VARS.H

#define LEDPIN 13

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
