/*
 * samplerSensorP.cpp
 *
 * Date: 2022-10-15
 * Version: 1.0
 * Language: C
 *
 * Title:
 *		Sampler
 *
 * Method:
 * 		The periodic task will run at an interval of SAMP_TIME. The wake time is
 * 		set as an absolute time which will be incremented by SAMP_TIME on every
 * 		run.
 * 		The periodic task will check the mode and if the mode is SAFE it will set
 * 		the transmission status OFF.
 *
 * Constraints: 
 * 		Deadline: 15ms [untested]
 *
 * Authors:
 * 		Tom Causer, Finn Hansch, Jacek Patora, Pavlos Vlazakis
 *
 * Reviewed:
 * 		Tom Causer, Finn Hansch, Jacek Patora, Pavlos Vlazakis, 20 October 2022
 *
 * Note:
 * 		In case the transmission status is set to OFF the sensor value will not
 * 		be read because the voltage is neither transmitted nor logged. This has
 * 		been discussed with the customer.
 */

#include <Arduino.h>
#include <Arduino_FreeRTOS.h>
#include "env_vars.h"
#include "modes.h"
#include "txSensor.h"
#include "txStatusSensor.h"
#include "samplerSensorP.h"

static void sampleLoop(void);

void samplerSensorP_activate(void) {
  xTaskCreate(
    sampleLoop
    ,  "sampleLoop" 
    ,  128  
    ,  NULL
    ,  TPRIO_SAMPLE_LOOP
    ,  NULL );
}

static void sampleLoop(void) {
	uint16_t sensorValue; /* sensor value read from ADC */
	mode_t mode; /* current mode */
	bool status; /* current status */
	TickType_t xLastWakeTime; /* last tic function was run */

#ifdef DEBUG
	Serial.println("starting sampleLoop");
	Serial.println("tickLenght [ms] = " + (String) portTICK_PERIOD_MS );
#endif
	 xLastWakeTime = xTaskGetTickCount();

	for (;;){
#ifdef DEBUG
		Serial.println("lastRun = " + (String) (xLastWakeTime * portTICK_PERIOD_MS) );
#endif
		modes_get(&mode);
		if (mode == SAFE) {
			txStatusSensor_set(0);
		}
		txStatusSensor_get(&status);
		if (status == 1) {
			sensorValue = analogRead(ADC_PIN); 
			txSensor_transmitAscii(sensorValue);
		}
		/* The SAMP_TIME is divided by the portTICK_PERIOD_MS because SAMP_TIME
		 * is specified in ms. */
		vTaskDelayUntil(&xLastWakeTime, SAMP_TIME / portTICK_PERIOD_MS ); 
	}
}
